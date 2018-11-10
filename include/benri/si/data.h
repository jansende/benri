#pragma once
#include <benri/quantity.h>
#include <benri/quantity_point.h>
#include <benri/impl/dimensions.h>
#include <benri/impl/macros.h>
#include <benri/impl/prefix.h>

namespace benri
{
namespace si
{
namespace data
{
#pragma region screen position
implement_subunit(si, data, px, dim::screen_position_t, prefix::one);
link_unit_point(px_position, px);
#pragma endregion
#pragma region screen area
implement_subunit(si, data, pixel, dim::screen_area_t, prefix::one);
#pragma endregion
#pragma region amount of data
implement_subunit(si, data, byte, dim::amount_of_data_t, prefix::one);
implement_subunit(si, data, bit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list<1, 8>, prefix::one>));
#pragma endregion
#pragma region prefixes
implement_subunit(si, data, kibi, dim::dimensionless_t, prefix::kibi);
implement_subunit(si, data, mebi, dim::dimensionless_t, prefix::mebi);
implement_subunit(si, data, gibi, dim::dimensionless_t, prefix::gibi);
implement_subunit(si, data, tebi, dim::dimensionless_t, prefix::tebi);
implement_subunit(si, data, pebi, dim::dimensionless_t, prefix::pebi);
implement_subunit(si, data, exbi, dim::dimensionless_t, prefix::exbi);
implement_subunit(si, data, zebi, dim::dimensionless_t, prefix::zebi);
implement_subunit(si, data, yobi, dim::dimensionless_t, prefix::yobi);
#pragma endregion
} // namespace data
} // namespace si
} // namespace benri