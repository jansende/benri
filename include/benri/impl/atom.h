#pragma once
#include <benri/impl/meta_math.h>
#include <ratio>

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
    using type = T;
    using power = Power;
};
//The has_type function checks if a type has the ::type attribute
//using SFINAE.
template <class T>
struct has_type
{
    template <class U>
    static constexpr auto test(typename U::type *) { return true; }
    template <class U>
    static constexpr auto test(...) { return false; }

    static constexpr auto value = test<T>(0);
};
template <class T>
constexpr bool has_type_v = has_type<T>::value;
//The value_is_arithmetic function checks if a given type has a ::value
//attribute which is arithmetic. The check is only done, when the given
//bool is true.
template <bool, class T>
struct value_is_arithmetic_impl;
template <class T>
struct value_is_arithmetic_impl<true, T>
{
    static constexpr auto value = std::is_arithmetic_v<decltype(T::value)>;
};
template <class T>
struct value_is_arithmetic_impl<false, T>
{
    static constexpr auto value = false;
};
template <bool Check, class T>
struct value_is_arithmetic : std::integral_constant<bool, value_is_arithmetic_impl<Check, T>::value>
{
};
template <bool Check, class T>
constexpr bool value_is_arithmetic_v = value_is_arithmetic<Check, T>::value;
//The has_valid_value function checks if a given type has a ::value
//attribute which is arithmetic.
template <class T>
struct has_valid_value : std::integral_constant<bool, value_is_arithmetic_v<has_static_constexpr_value_v<T>, T>>
{
};
template <class T>
constexpr bool has_valid_value_v = has_valid_value<T>::value;
//The type_is_valid function checks if a given type has a ::type
//attribute which is either a std::ratio, or which has a static
//constexpr arithmetic ::value. The check is only done, when the
//given bool is true.
template <bool, class T>
struct type_is_valid_impl;
template <class T>
struct type_is_valid_impl<true, T>
{
    static constexpr auto value = is_ratio_v<typename T::type> || has_valid_value_v<typename T::type>;
};
template <class T>
struct type_is_valid_impl<false, T>
{
    static constexpr auto value = false;
};
template <bool Check, class T>
struct type_is_valid : std::integral_constant<bool, type_is_valid_impl<Check, T>::value>
{
};
template <bool Check, class T>
constexpr bool type_is_valid_v = type_is_valid<Check, T>::value;
//The has_valid_type function checks if a given type has a ::type
//attribute which is a ratio or has a ::value argument which is an
//arithmetic type.
template <class T>
struct has_valid_type : std::integral_constant<bool, type_is_valid_v<has_type_v<T>, T>>
{
};
template <class T>
constexpr bool has_valid_type_v = has_valid_type<T>::value;
//The has_power function checks if a type has the ::power attribute
//using SFINAE.
template <class T>
struct has_power
{
    template <class U>
    static constexpr auto test(typename U::power *) { return true; }
    template <class U>
    static constexpr auto test(...) { return false; }

    static constexpr auto value = test<T>(0);
};
template <class T>
constexpr bool has_power_v = has_power<T>::value;
//The power_is_ratio function checks if a given type has a ::power
//attribute which is a ratio. The check is only done, when the given
//bool is true.
template <bool, class T>
struct power_is_ratio_impl;
template <class T>
struct power_is_ratio_impl<true, T>
{
    static constexpr auto value = is_ratio_v<typename T::power>;
};
template <class T>
struct power_is_ratio_impl<false, T>
{
    static constexpr auto value = false;
};
template <bool Check, class T>
struct power_is_ratio : std::integral_constant<bool, power_is_ratio_impl<Check, T>::value>
{
};
template <bool Check, class T>
constexpr bool power_is_ratio_v = power_is_ratio<Check, T>::value;
//The has_valid_power function checks if a given type has a ::power
//attribute which is a ratio.
template <class T>
struct has_valid_power : std::integral_constant<bool, power_is_ratio_v<has_power_v<T>, T>>
{
};
template <class T>
constexpr bool has_valid_power_v = has_valid_power<T>::value;
//The is_atom function checks if a type has a ::type and a ::power
//attribute. This does not mean, we have an atom type, but we do not
//care, as we can do the necessary calculations.
template <class T>
struct is_atom : std::integral_constant<bool, has_type_v<T> && has_valid_power_v<T>>
{
};
template <class T>
constexpr bool is_atom_v = is_atom<T>::value;
//TODO: - Put this into a unit test folder.
//basic tests
static_assert(!is_atom_v<int>, "");
static_assert(is_atom_v<atom<double>>, "");
static_assert(is_atom_v<atom<std::ratio<3>>>, "");
#pragma endregion
#pragma region expansion
//The is_root function checks if a given atom has a root power.
template <class T>
struct is_root : std::false_type
{
    static_assert(is_atom_v<T>, "is_root takes an atom, but your T is not an atom.");
};
template <template <class, class> class Atom, class T, intmax_t num, intmax_t den>
struct is_root<Atom<T, std::ratio<num, den>>> : std::integral_constant<bool, den != 1>
{
};
template <class T>
constexpr bool is_root_v = is_root<T>::value;
//TODO: - Put this into a unit test folder.
//basic tests
static_assert(!is_root_v<atom<std::ratio<2>, std::ratio<2>>>, "");
static_assert(!is_root_v<atom<std::ratio<2>, std::ratio<-2>>>, "");
static_assert(is_root_v<atom<std::ratio<2>, std::ratio<3, 5>>>, "");
static_assert(!is_root_v<atom<std::ratio<2>, std::ratio_multiply<std::ratio<2>, std::ratio<1, 2>>>>, "");
static_assert(!is_root_v<atom<std::ratio<2>, std::ratio_multiply<std::ratio<16>, std::ratio<1, 2>>>>, "");
static_assert(is_root_v<atom<std::ratio<2>, std::ratio_multiply<std::ratio<16>, std::ratio<1, 3>>>>, "");
//The expand_atom function takes an atom with a std::ratio type
//and calculates its value to the power given in the atom.
template <class T, class Atom>
struct expand_atom
{
    static_assert(is_atom_v<Atom>, "expand_atom takes a value type and an atom, but your Atom is not an atom.");
    static_assert(has_valid_type_v<Atom>, "expand_atom requires the ::type of your Atom to be std::ratio or have a static constexpr arithmetic ::value.");
    static_assert(!is_root_v<Atom>, "expand_atom cannot handle roots in the atoms at the moment. Sorry!");
    // static_assert(is_ratio_v<typename Atom::type>, "expand_atom cannot handle constexpr atom::types at the moment. Sorry!");
    static constexpr auto value = power_v<T, typename Atom::type, typename Atom::power>;
};
template <class T, class Atom>
constexpr T expand_atom_v = expand_atom<T, Atom>::value;
//TODO: - Put this into a unit test folder.
//basic tests
static_assert(expand_atom_v<intmax_t, atom<std::ratio<2>, std::ratio<2>>> == 4, "");
static_assert(expand_atom_v<double, atom<std::ratio<2>, std::ratio<-2>>> == 1. / 4., "");
//The runtime_expand_atom_impl function implements the actual power calcu-
//lation for the runtime_expand_atom function. It handles two cases: the
//case of std::ratio as the atom::type, and a constexpr value for it.
template <class T, class Atom>
constexpr auto runtime_expand_atom_impl() -> std::enable_if_t<!is_ratio_v<typename Atom::type>, T>
{
    //handle constants
    return std::pow(T(Atom::type::value), T(Atom::power::num) / T(Atom::power::den));
};
template <class T, class Atom>
constexpr auto runtime_expand_atom_impl() -> std::enable_if_t<is_ratio_v<typename Atom::type>, T>
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
    static_assert(is_atom_v<Atom>, "runtime_expand_atom takes a value type and an atom, but your Atom is not an atom.");
    static_assert(has_valid_type_v<Atom>, "runtime_expand_atom requires the ::type of your Atom to be std::ratio or have a constexpr arithmetic ::value.");
    return runtime_expand_atom_impl<T, Atom>();
};
#pragma endregion
} // namespace impl
//Pull the atom type into the benri namespace, because we need
//it for constructing units.
using impl::atom;
} // namespace benri