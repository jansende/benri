#pragma once
#include <benri/impl/meta_math.h>
#include <benri/impl/detector.h>
#include <ratio>
#include <cmath>

namespace benri
{
namespace impl
{
#pragma region atom type
//The atom type save arbitrary types and their associated power.
//It is used to represent multiple occurences of T in a product.
//For example 2^3 would be saved as atom<ratio<2>,ratio<3>>, and
//int^1/2 would be saved as atom<int,ratio<1,2>>.
template <class T, class Power = std::ratio<1>>
struct atom
{
    // static_assert(!std::is_same<Power, std::ratio<0>>::value, "Atoms with a Power of 0 are not allowed.");
    using type = T;
    using power = Power;
};
//The has_type function checks if a type has the ::type attribute
//using SFINAE.
template <class T>
using has_type = typename T::type;
//The has_valid_type function checks if a given type has a ::type
//attribute which is a ratio or has a ::value argument.
template <class T>
using has_valid_type = typename std::enable_if<detect_if<typename T::type, is_std_ratio> || detect_if<typename T::type, has_static_constexpr_value>>::type;
//The has_valid_power function checks if a given type has a ::power
//attribute which is a ratio.
template <class T>
using has_valid_power = typename std::enable_if<detect_if<typename T::power, is_std_ratio>>::type;
//The is_atom function checks if a type has a ::type and a ::power
//attribute. This does not mean, we have an atom type, but we do not
//care, if we can do the necessary calculations.
template <class T>
using is_atom = typename std::enable_if<detect_if<T, has_type> && detect_if<T, has_valid_power>>::type;
//TODO: - Put this into a unit test folder.
//basic tests
static_assert(!detect_if<int, is_atom>, "");
static_assert(detect_if<atom<double>, is_atom>, "");
static_assert(detect_if<atom<std::ratio<3, 7>>, is_atom>, "");
static_assert(detect_if<atom<std::ratio<3>>, is_atom>, "");
#pragma endregion
#pragma region expansion
//The is_root function checks if a given atom has a root power.
template <class T>
using is_root = typename std::enable_if<detect_if<T, is_atom> && (T::power::den != 1)>::type;
//TODO: - Put this into a unit test folder.
//basic tests
static_assert(!detect_if<atom<std::ratio<2>, std::ratio<2>>, is_root>, "");
static_assert(!detect_if<atom<std::ratio<2>, std::ratio<-2>>, is_root>, "");
static_assert(detect_if<atom<std::ratio<2>, std::ratio<3, 5>>, is_root>, "");
static_assert(!detect_if<atom<std::ratio<2>, std::ratio_multiply<std::ratio<2>, std::ratio<1, 2>>>, is_root>, "");
static_assert(!detect_if<atom<std::ratio<2>, std::ratio_multiply<std::ratio<16>, std::ratio<1, 2>>>, is_root>, "");
static_assert(detect_if<atom<std::ratio<2>, std::ratio_multiply<std::ratio<16>, std::ratio<1, 3>>>, is_root>, "");
//The expand_atom function takes an atom with a std::ratio type
//and calculates its value to the power given in the atom.
template <class T, class Atom>
constexpr T expand_atom = power<T, typename Atom::type, typename Atom::power>;
//TODO: - Put this into a unit test folder.
//basic tests
static_assert(expand_atom<intmax_t, atom<std::ratio<2>, std::ratio<2>>> == 4, "");
static_assert(expand_atom<double, atom<std::ratio<2>, std::ratio<-2>>> == 1. / 4., "");
//The runtime_expand_atom_impl function implements the actual power calcu-
//lation for the runtime_expand_atom function. It handles two cases: the
//case of std::ratio as the atom::type, and a constexpr value for it.
template <class T, class Atom>
constexpr auto runtime_expand_atom_impl() -> std::enable_if_t<!detect_if<typename Atom::type, is_std_ratio>, T>
{
    //handle constants
    return std::pow(T(Atom::type::value), T(Atom::power::num) / T(Atom::power::den));
};
template <class T, class Atom>
constexpr auto runtime_expand_atom_impl() -> std::enable_if_t<detect_if<typename Atom::type, is_std_ratio>, T>
{
    //handle ratios
    return std::pow(T(Atom::type::num) / T(Atom::type::den), T(Atom::power::num) / T(Atom::power::den));
};
//The runtime_expand_atom function takes an atom with a std::ratio type
//and calculates its value to the power given in the atom. However, this
//is done at runtime rather than compile time. The reason being, that
//std::pow is not constexpr. Still, the whole function is marked constexpr
//to be forward compatible with a constexpr std::pow implementation.
template <class T, class Atom>
constexpr auto runtime_expand_atom()
{
    static_assert(detect_if<Atom, is_atom>, "runtime_expand_atom takes a value type and an atom, but your Atom is not an atom.");
    static_assert(detect_if<Atom, has_valid_type>, "runtime_expand_atom requires the ::type of your Atom to be std::ratio or have a constexpr ::value.");
    return runtime_expand_atom_impl<T, Atom>();
};
#pragma endregion
} // namespace impl
//Pull the atom type into the benri namespace, because we need
//it for constructing units.
using impl::atom;
} // namespace benri