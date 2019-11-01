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
} // namespace benri