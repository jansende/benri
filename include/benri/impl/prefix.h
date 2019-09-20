#pragma once
#include <benri/impl/meta/math.h>
#include <benri/impl/type/list.h>
#include <benri/impl/type/traits.h>
#include <ratio>
#include <cmath>

namespace benri
{
#pragma region prefix type
//Container type for saving prefixes with their associated power.
template <class T, class Power = std::ratio<1>>
struct pre
{
    static_assert(type::detect_if<T, type::has_value> || type::detect_if<T, type::is_std_ratio>, "T has to either be std::ratio or a struct with a ::value attribute.");
    static_assert(type::detect_if<Power, type::is_std_ratio>, "Power has to be a std::ratio.");
    using type = T;
    using power = Power;
};
#pragma endregion
#pragma region prefix expansion functions
//Function for expanding prefixes. It takes the value from T and raises it to the value
//stored in Power. (Can only handle integer values for Power.)
template <class T, class Prefix>
constexpr T expand_prefix = meta::pow<T, typename Prefix::type, typename Prefix::power>;
//Basic tests
static_assert(expand_prefix<intmax_t, pre<std::ratio<2>, std::ratio<2>>> == 4, "expand_prefix<pre<2,2>> is 4.");
static_assert(expand_prefix<double, pre<std::ratio<2>, std::ratio<-2>>> == 1. / 4., "expand_prefix<pre<2,-2>> is 1/4.");
//Function for expanding prefixes. It takes the value from T and raises it to the value
//stored in Power. (Can take any value for Power, but has to do the calculation at runtime.)
template <class T, class Prefix>
constexpr auto runtime_expand_prefix_impl()
    -> std::enable_if_t<!type::detect_if<typename Prefix::type, type::is_std_ratio>, T>
{
    //Value store in ::value attribute.
    return std::pow(T(Prefix::type::value),
                    T(Prefix::power::num) / T(Prefix::power::den));
};
template <class T, class Prefix>
constexpr auto runtime_expand_prefix_impl()
    -> std::enable_if_t<type::detect_if<typename Prefix::type, type::is_std_ratio>, T>
{
    //Value stored in std::ratio.
    return std::pow(T(Prefix::type::num) / T(Prefix::type::den),
                    T(Prefix::power::num) / T(Prefix::power::den));
};
template <class T, class Prefix>
constexpr auto runtime_expand_prefix()
{
    static_assert(type::detect_if<Prefix, type::is_prefix>, "runtime_expand_prefix takes a value type and an prefix, but your Prefix is not an prefix.");
    return runtime_expand_prefix_impl<T, Prefix>();
};
//Function for expanding a list of prefixes.
template <class ValueType, class... Elements>
constexpr auto expand_prefix_list_impl(type::sorted_list<Elements...>)
{
    static_assert(type::all_true<type::detect_if<Elements, type::is_prefix>...>, "All Elements have to be pre.");
    static_assert(type::all_true<type::detect_if<typename Elements::power, type::is_integer_ratio>...>, "expand_prefix_list cannot handle roots in the atoms at the moment. Use runtime_expand_prefix_list instead.");

    return meta::accumulate(
        meta::array<ValueType, sizeof...(Elements)>{
            expand_prefix<ValueType, Elements>...},
        ValueType{1}, std::multiplies<ValueType>());
}
template <class ValueType, class List>
constexpr ValueType expand_prefix_list = expand_prefix_list_impl<ValueType>(List{});
//Basic tests
static_assert(expand_prefix_list<intmax_t, type::sorted_list<pre<std::ratio<2>, std::ratio<3>>>> == 8, "expand_prefix_list<pre<2,3>> is 8.");
static_assert(expand_prefix_list<float, type::sorted_list<pre<std::ratio<2>, std::ratio<-3>>>> == 1. / 8., "expand_prefix_list<pre<2,-3>> is 1/8.");
static_assert(expand_prefix_list<intmax_t, type::sorted_list<pre<std::ratio<2>, std::ratio<2>>, pre<std::ratio<7>>>> == 28, "expand_prefix_list<pre<2,2>,pre<7>> is 28.");
static_assert(expand_prefix_list<float, type::sorted_list<pre<std::ratio<2>, std::ratio<-2>>, pre<std::ratio<7>>>> == 1.75f, "expand_prefix_list<pre<2,-2>,pre<7>> is 1.75.");
//Function for expanding a list of prefixes at runtime.
template <class ValueType, class... Elements>
constexpr auto runtime_expand_prefix_list(type::sorted_list<Elements...>)
{
    static_assert(type::all_true<type::detect_if<Elements, type::is_prefix>...>, "All Elements have to be pre.");
    return meta::accumulate(
        meta::array<ValueType, sizeof...(Elements)>{
            runtime_expand_prefix<ValueType, Elements>()...},
        ValueType{1}, std::multiplies<ValueType>());
};
#pragma endregion
} // namespace benri