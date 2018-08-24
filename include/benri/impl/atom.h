#pragma once
#include <ratio>
#include <benri/impl/meta_math.h>

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
    static constexpr auto test(typename U::type *) { return true; };
    template <class U>
    static constexpr auto test(...) { return false; };

    static constexpr auto value = test<T>(0);
};
template <class T>
constexpr auto has_type_v = has_type<T>::value;
//The has_type function checks if a type has the ::power attribute
//using SFINAE.
template <class T>
struct has_power
{
    template <class U>
    static constexpr auto test(typename U::power *) { return true; };
    template <class U>
    static constexpr auto test(...) { return false; };

    static constexpr auto value = test<T>(0);
};
template <class T>
constexpr auto has_power_v = has_power<T>::value;
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
constexpr auto power_is_ratio_v = power_is_ratio<Check, T>::value;
//The has_valid_power function checks if a given type has a ::power
//attribute which is a ratio.
template <class T>
struct has_valid_power : std::integral_constant<bool, power_is_ratio_v<has_power_v<T>, T>>
{
};
template <class T>
constexpr auto has_valid_power_v = has_valid_power<T>::value;
//The is_atom function checks if a type has a ::type and a ::power
//attribute. This does not mean, we have an atom type, but we do not
//care, as we can do the necessary calculations.
template <class T>
struct is_atom : std::integral_constant<bool, has_type_v<T> && has_valid_power_v<T>>
{
};
template <class T>
constexpr auto is_atom_v = is_atom<T>::value;
//TODO: - Put this into a unit test folder.
auto test_is_atom()
{
    static_assert(!is_atom_v<int>, "");
    static_assert(is_atom_v<atom<double>>, "");
}
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
constexpr auto is_root_v = is_root<T>::value;
//TODO: - Put this into a unit test folder.
auto test_is_root()
{
    static_assert(!is_root_v<atom<std::ratio<2>, std::ratio<2>>>, "");
    static_assert(!is_root_v<atom<std::ratio<2>, std::ratio<-2>>>, "");
    static_assert(is_root_v<atom<std::ratio<2>, std::ratio<3, 5>>>, "");
    static_assert(!is_root_v<atom<std::ratio<2>, std::ratio_multiply<std::ratio<2>, std::ratio<1, 2>>>>, "");
    static_assert(!is_root_v<atom<std::ratio<2>, std::ratio_multiply<std::ratio<16>, std::ratio<1, 2>>>>, "");
    static_assert(is_root_v<atom<std::ratio<2>, std::ratio_multiply<std::ratio<16>, std::ratio<1, 3>>>>, "");
}
//The expand_atom function takes an atom with a std::ratio type
//and calculates its value to the power given in the atom.
template <class T, class Atom>
struct expand_atom
{
    static_assert(is_atom_v<Atom>, "expand_atom takes a value type and an atom, but your Atom is not an atom.");
    static_assert(!is_root_v<Atom>, "expand_atom cannot handle roots in the atoms at the moment. Sorry!");
    static constexpr auto value = power_v<T, typename Atom::type, typename Atom::power>;
};
template <class T, class Atom>
constexpr auto expand_atom_v = expand_atom<T, Atom>::value;
//TODO: - Put this into a unit test folder.
auto test_expand_atom()
{
    static_assert(expand_atom_v<intmax_t, atom<std::ratio<2>, std::ratio<2>>> == 4, "");
    static_assert(expand_atom_v<double, atom<std::ratio<2>, std::ratio<-2>>> == 1. / 4., "");
}
//The runtime_expand_atom function takes an atom with a std::ratio type
//and calculates its value to the power given in the atom. However, this
//is done at runtime rather than compile time. The reason being, that
//std::pow is not constexpr. Still, the whole function is marked constexpr
//to be forward compatible with a constexpr std::pow implementation.
template <class T, class Atom>
constexpr auto runtime_expand_atom()
{
    static_assert(is_atom_v<Atom>, "runtime_expand_atom takes a value type and an atom, but your Atom is not an atom.");
    return std::pow(T(Atom::type::num) / T(Atom::type::den), T(Atom::power::num) / T(Atom::power::den));
};
#pragma endregion
} // namespace impl
//Pull the atom type into the benri namespace, because we need
//it for constructing units.
using impl::atom;
} // namespace benri