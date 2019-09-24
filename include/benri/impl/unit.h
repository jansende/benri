#pragma once
#include <benri/impl/math.h>
#include <benri/impl/type/list.h>
#include <benri/impl/type/sort.h>
#include <benri/impl/type/traits.h>

namespace benri
{
#pragma region unit type
// Container type for saving units.
template <class Dimension, class Prefix>
struct unit
{
    static_assert(type::detect_if<Dimension, type::is_sorted_list>,
                  "Dimension has to be a sorted_list.");
    static_assert(type::detect_if<Prefix, type::is_sorted_list>,
                  "Prefix has to be a sorted_list.");
    using dimension = Dimension;
    using prefix    = Prefix;
};
// Shortcut for the unit without prefix and dimension.
using one = unit<type::sorted_list<>, type::sorted_list<>>;
#pragma endregion
#pragma region type functions
// Function for multiplying two or more units.
template <class... Units>
using multiply_units = unit<type::multiply_lists<typename Units::dimension...>,
                            type::multiply_lists<typename Units::prefix...>>;
// Function for raising units by a given Power.
template <class Unit, class Power>
using pow_unit = unit<type::pow_list<typename Unit::dimension, Power>,
                      type::pow_list<typename Unit::prefix, Power>>;
// Function for dividing two units.
template <class lhsUnit, class rhsUnit>
using divide_units = multiply_units<lhsUnit, pow_unit<rhsUnit, std::ratio<-1>>>;
// Helper for handling units as equivalent even if the types are not.
template <class From, class To>
struct convert
{
};
template <class From, class To>
using is_convertible_into = decltype(convert<From, To>{}(From{}));

// Helper for removing a units prefix.
template <class Unit>
using drop_unit_prefix = unit<typename Unit::dimension, type::sorted_list<>>;
#pragma endregion
} // namespace benri