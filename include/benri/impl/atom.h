#pragma once
#include <benri/impl/meta/math.h>
#include <benri/impl/type/traits.h>
#include <ratio>
#include <cmath>

namespace benri
{
namespace impl
{
#pragma region atom type
//Container type for saving dimensions with their associated power.
template <class T, class Power = std::ratio<1>>
struct dim
{
    static_assert(type::detect_if<Power, type::is_std_ratio>, "Power has to be a std::ratio.");
    using type = T;
    using power = Power;
};
//Container type for saving prefixes with their associated power.
template <class T, class Power = std::ratio<1>>
struct pre
{
    static_assert(type::detect_if<T, type::has_value> || type::detect_if<T, type::is_std_ratio>, "T has to either be std::ratio or a struct with a ::value attribute.");
    static_assert(type::detect_if<Power, type::is_std_ratio>, "Power has to be a std::ratio.");
    using type = T;
    using power = Power;
};
//The has_valid_type function checks if a given type has a ::type
//attribute which is a ratio or has a ::value argument.
template <class T>
using has_valid_type = typename std::enable_if<type::detect_if<typename T::type, type::is_std_ratio> || type::detect_if<typename T::type, type::has_value>>::type;
//The is_atom function checks if a type has a ::type and a ::power
//attribute. This does not mean, we have an atom type, but we do not
//care, if we can do the necessary calculations.
template <class T>
using is_atom = typename std::enable_if<type::detect_if<T, type::has_type>>::type;
template <class T>
using is_prefix = is_atom<T>;
//TODO: - Put this into a unit test folder.
//Basic tests
static_assert(!type::detect_if<int, is_atom>, "");
static_assert(type::detect_if<dim<double>, is_atom>, "");
static_assert(type::detect_if<dim<std::ratio<3, 7>>, is_atom>, "");
static_assert(type::detect_if<dim<std::ratio<3>>, is_atom>, "");
#pragma endregion
#pragma region expansion
//The is_root function checks if a given atom has a root power.
template <class T>
using is_root = typename std::enable_if<type::detect_if<T, is_atom> && (T::power::den != 1)>::type;
//TODO: - Put this into a unit test folder.
//Basic tests
static_assert(!type::detect_if<dim<std::ratio<2>, std::ratio<2>>, is_root>, "");
static_assert(!type::detect_if<dim<std::ratio<2>, std::ratio<-2>>, is_root>, "");
static_assert(type::detect_if<dim<std::ratio<2>, std::ratio<3, 5>>, is_root>, "");
static_assert(!type::detect_if<dim<std::ratio<2>, std::ratio_multiply<std::ratio<2>, std::ratio<1, 2>>>, is_root>, "");
static_assert(!type::detect_if<dim<std::ratio<2>, std::ratio_multiply<std::ratio<16>, std::ratio<1, 2>>>, is_root>, "");
static_assert(type::detect_if<dim<std::ratio<2>, std::ratio_multiply<std::ratio<16>, std::ratio<1, 3>>>, is_root>, "");
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
    static_assert(type::detect_if<Prefix, is_prefix>, "runtime_expand_prefix takes a value type and an prefix, but your Prefix is not an prefix.");
    static_assert(type::detect_if<Prefix, has_valid_type>, "runtime_expand_prefix requires the ::type of your Prefix to be std::ratio or have a constexpr ::value.");
    return runtime_expand_prefix_impl<T, Prefix>();
};
#pragma endregion
} // namespace impl
} // namespace benri