#pragma once
#include <benri/impl/dimension.h>
#include <benri/impl/type/list.h>
#include <benri/impl/type/sort.h>

namespace benri
{
template <class... Dims>
using make_dimension = type::sort<type::list<Dims...>>;
template <class Dimension, class Prefix = type::list<>>
using make_unit = unit<type::sort<Dimension>, type::sort<Prefix>>;
template <class Unit, class ValueType = Precision, class T = Precision>
constexpr auto make_quantity(const T& value) -> quantity<Unit, ValueType>
{
    return quantity<Unit, ValueType>{static_cast<ValueType>(value)};
}
template <class Unit, class ValueType = Precision, class T = Precision>
constexpr auto make_quantity_point(const T& value) -> quantity_point<Unit, ValueType>
{
    return quantity_point<Unit, ValueType>{static_cast<ValueType>(value)};
}
template <class Unit, class Value = type::sorted_list<>, class ValueType = Precision>
constexpr quantity<Unit, ValueType>
    make_constant = make_quantity<Unit, ValueType>(expand_prefix_list<ValueType, Value>);
template <class Dimension, class Prefix = type::list<>, class Value = type::sorted_list<>,
          class ValueType = Precision>
constexpr quantity<make_unit<Dimension, Prefix>, ValueType> make_symbol =
    make_constant<make_unit<Dimension, Prefix>, Value, ValueType>;
template <class Unit, class Value = type::sorted_list<>, class ValueType = Precision>
constexpr quantity_point<Unit, ValueType> make_constant_point =
    make_quantity_point<Unit, ValueType>(expand_prefix_list<ValueType, Value>);
template <class Dimension, class Prefix = type::list<>, class Value = type::sorted_list<>,
          class ValueType = Precision>
constexpr quantity_point<make_unit<Dimension, Prefix>, ValueType> make_symbol_point =
    make_constant_point<make_unit<Dimension, Prefix>, Value, ValueType>;
} // namespace benri