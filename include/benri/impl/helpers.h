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
} // namespace benri