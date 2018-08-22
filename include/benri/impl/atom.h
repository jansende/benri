#pragma once
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
    static constexpr auto test(typename U::type *) { return true; };
    template <class U>
    static constexpr auto test(...) { return false; };

    static constexpr auto value = test<T>(0);
};
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
//The is_atom function checks if a type has a ::type and a ::power
//attribute. This does not mean, we have an atom type, but we do not
//care, as we can do the necessary calculations.
template <class T>
struct is_atom : std::integral_constant<bool, has_type<T>::value && has_power<T>::value>
{
};
//TODO: - Put this into a unit test folder.
auto test_is_atom()
{
    static_assert(!is_atom<int>::value, "");
    static_assert(is_atom<atom<double>>::value, "");
}
#pragma endregion
} // namespace impl
} // namespace benri