#pragma once
#include <benri/impl/meta/math.h>
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



//The is_root function checks if a given atom has a root power.
template <class T>
using is_root = typename std::enable_if<type::detect_if<T, type::is_prefix> && (T::power::den != 1)>::type;
//TODO: - Put this into a unit test folder.
//Basic tests
static_assert(!type::detect_if<pre<std::ratio<2>, std::ratio<2>>, is_root>, "");
static_assert(!type::detect_if<pre<std::ratio<2>, std::ratio<-2>>, is_root>, "");
static_assert(type::detect_if<pre<std::ratio<2>, std::ratio<3, 5>>, is_root>, "");
static_assert(!type::detect_if<pre<std::ratio<2>, std::ratio_multiply<std::ratio<2>, std::ratio<1, 2>>>, is_root>, "");
static_assert(!type::detect_if<pre<std::ratio<2>, std::ratio_multiply<std::ratio<16>, std::ratio<1, 2>>>, is_root>, "");
static_assert(type::detect_if<pre<std::ratio<2>, std::ratio_multiply<std::ratio<16>, std::ratio<1, 3>>>, is_root>, "");
//The expand_prefix function takes an prefix with a std::ratio type
//and calculates its value to the power given in the prefix.
template <class T, class Prefix>
constexpr T expand_prefix = meta::pow<T, typename Prefix::type, typename Prefix::power>;
//TODO: - Put this into a unit test folder.
//Basic tests
static_assert(expand_prefix<intmax_t, pre<std::ratio<2>, std::ratio<2>>> == 4, "");
static_assert(expand_prefix<double, pre<std::ratio<2>, std::ratio<-2>>> == 1. / 4., "");
//The runtime_expand_prefix_impl function implements the actual power calcu-
//lation for the runtime_expand_prefix function. It handles two cases: the
//case of std::ratio as the prefix::type, and a constexpr value for it.
template <class T, class Prefix>
constexpr auto runtime_expand_prefix_impl() -> std::enable_if_t<!type::detect_if<typename Prefix::type, type::is_std_ratio>, T>
{
    //handle constants
    return std::pow(T(Prefix::type::value), T(Prefix::power::num) / T(Prefix::power::den));
};
template <class T, class Prefix>
constexpr auto runtime_expand_prefix_impl() -> std::enable_if_t<type::detect_if<typename Prefix::type, type::is_std_ratio>, T>
{
    //handle ratios
    return std::pow(T(Prefix::type::num) / T(Prefix::type::den), T(Prefix::power::num) / T(Prefix::power::den));
};
//The runtime_expand_prefix function takes an prefix with a std::ratio type
//and calculates its value to the power given in the prefix. However, this
//is done at runtime rather than compile time. The reason being, that
//std::pow is not constexpr. Still, the whole function is marked constexpr
//to be forward compatible with a constexpr std::pow implementation.
template <class T, class Prefix>
constexpr auto runtime_expand_prefix()
{
    static_assert(type::detect_if<Prefix, type::is_prefix>, "runtime_expand_prefix takes a value type and an prefix, but your Prefix is not an prefix.");
    return runtime_expand_prefix_impl<T, Prefix>();
};
#pragma endregion
} // namespace benri