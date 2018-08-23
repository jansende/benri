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
} // namespace impl
} // namespace benri