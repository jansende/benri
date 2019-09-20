#pragma once
#include <benri/impl/type/list.h>
#include <benri/impl/type/sort.h>
#include <benri/impl/math.h>
#include <benri/impl/type/traits.h>

namespace benri
{
#pragma region unit type
//Container type for saving units.
template <class Dimensions, class Prefix>
struct unit
{
    static_assert(type::detect_if<Dimensions, type::is_sorted_list>, "Dimensions has to be a sorted_list.");
    static_assert(type::detect_if<Prefix, type::is_sorted_list>, "Prefix has to be a sorted_list.");
    using dimensions = Dimensions;
    using prefix = Prefix;
};
//Shortcut for the unit without prefix and dimension.
using one = unit<type::sorted_list<>, type::sorted_list<>>;
#pragma endregion
#pragma region type functions
//Function for multiplying two or more units.
template <class... Units>
using multiply_units = unit<
    type::multiply_lists<typename Units::dimensions...>,
    type::multiply_lists<typename Units::prefix...>>;
//Function for raising units by a given Power.
template <class Unit, class Power>
using pow_unit = unit<
    type::pow_list<typename Unit::dimensions, Power>,
    type::pow_list<typename Unit::prefix, Power>>;
//Function for dividing two units.
template <class lhsUnit, class rhsUnit>
using divide_units = multiply_units<lhsUnit, pow_unit<rhsUnit, std::ratio<-1>>>;
//Helper for handling units as equivalent even if the types are not.
template <class LDimensions, class LPrefix, class RDimensions, class RPrefix>
struct is_compatible : std::false_type
{
};
template <class LDimensions, class LPrefix, class RDimensions, class RPrefix>
constexpr bool is_compatible_v = is_compatible<LDimensions, LPrefix,
                                               RDimensions, RPrefix>::value;

template <class L, class R>
using is_compatible_with = typename std::enable_if_t<
    is_compatible_v<typename L::dimensions, typename L::prefix,
                    typename R::dimensions, typename R::prefix> ||
    is_compatible_v<typename R::dimensions, typename R::prefix,
                    typename L::dimensions, typename L::prefix>>;
//Helper for removing a units prefix.
template <class Unit>
using drop_unit_prefix = unit<typename Unit::dimensions, type::sorted_list<>>;
#pragma endregion
} // namespace benri