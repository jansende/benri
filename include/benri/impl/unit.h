#pragma once
#include <benri/impl/type/list.h>
#include <benri/impl/type/sort.h>
#include <benri/impl/type/traits.h>

namespace benri
{
#pragma region unit type
//The unit type saves the dimensions and prefix of a physical unit.
template <class Dimensions, class Prefix>
struct unit
{
    static_assert(type::detect_if<Dimensions, type::is_sorted_list>, "Dimensions has to be a sorted_list.");
    static_assert(type::detect_if<Prefix, type::is_sorted_list>, "Prefix has to be a sorted_list.");
    using dimensions = Dimensions;
    using prefix = Prefix;
};
//The one unit is the unit where the dimension and the prefix are empty lists.
using one = unit<sorted_list<>, sorted_list<>>;
//The is_dimensionless function checks if a given unit is dimensionless.
//The is_one function checks if a given unit is one.
template <class T>
using is_one = typename std::enable_if<type::detect_if<T, type::is_unit> && std::is_same<typename T::dimensions, typename one::dimensions>::value && std::is_same<typename T::prefix, typename one::prefix>::value>::type;
//(The dimension is an empty list.)
template <class T>
using is_dimensionless = typename std::enable_if<type::detect_if<T, type::is_unit> && std::is_same<typename T::dimensions, sorted_list<>>::value>::type;
#pragma endregion
#pragma region unit functions
#pragma region multiplication
//The multiply_units function multiplies two units.
template <class Dimensions, class Prefixes, class... Units>
struct multiply_units_impl
{
};
template <class...Dimensions, class...Prefixes>
struct multiply_units_impl<list<Dimensions...>,list<Prefixes...>>
{
    using type = unit<multiply_lists<Dimensions...>,multiply_lists<Prefixes...>>;
};
template <class...Dimensions, class...Prefixes, class Unit, class... Rest>
struct multiply_units_impl<list<Dimensions...>,list<Prefixes...>,Unit, Rest...> : multiply_units_impl<list<Dimensions...,typename Unit::dimensions>,list<Prefixes...,typename Unit::prefix>,Rest...>
{
};
template <class... Lists>
using multiply_units = typename multiply_units_impl<list<>,list<>,Lists...>::type;
#pragma endregion
#pragma region power
//The pow_unit function applies a given power to a unit.
template <class Unit, class Power>
using pow_unit = unit<pow_list<typename Unit::dimensions, Power>, pow_list<typename Unit::prefix, Power>>;
#pragma endregion
#pragma region division
//The divide_units function divide two units.
template <class lhsUnit, class rhsUnit>
using divide_units = unit<divide_lists<typename lhsUnit::dimensions, typename rhsUnit::dimensions>, divide_lists<typename lhsUnit::prefix, typename rhsUnit::prefix>>;
#pragma endregion
#pragma endregion
#pragma region unit compatibility checker
//The is_compatible function checks if two units should be handled
//as if they are equivalent, even if they are not.
template <class LDimensions, class LPrefix, class RDimensions, class RPrefix>
struct is_compatible_with_impl : std::false_type
{
};
template <class L, class R>
using is_compatible_with = typename std::enable_if<is_compatible_with_impl<typename L::dimensions, typename L::prefix, typename R::dimensions, typename R::prefix>::value || is_compatible_with_impl<typename R::dimensions, typename R::prefix, typename L::dimensions, typename L::prefix>::value>::type;
#pragma endregion
#pragma region remove prefix
template <class Unit>
using remove_unit_prefix = unit<typename Unit::dimensions, sorted_list<>>;
#pragma endregion
} // namespace benri