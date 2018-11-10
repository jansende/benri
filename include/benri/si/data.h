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
implement_subunit(si, data, px, dim::screen_position_t, prefix::one_t);
link_unit_point(px_position, px);
#pragma endregion
#pragma region screen area
implement_subunit(si, data, pixel, dim::screen_area_t, prefix::one_t);
#pragma endregion
#pragma region amount of data
implement_subunit(si, data, byte, dim::amount_of_data_t, prefix::one_t);
implement_subunit(si, data, bit, dim::amount_of_data_t, fix(make_fraction_list<1, 8>));
#pragma endregion
#pragma region prefixes
implement_subunit(si, data, kibi, dim::dimensionless_t, prefix::kibi_t);
implement_subunit(si, data, mebi, dim::dimensionless_t, prefix::mebi_t);
implement_subunit(si, data, gibi, dim::dimensionless_t, prefix::gibi_t);
implement_subunit(si, data, tebi, dim::dimensionless_t, prefix::tebi_t);
implement_subunit(si, data, pebi, dim::dimensionless_t, prefix::pebi_t);
implement_subunit(si, data, exbi, dim::dimensionless_t, prefix::exbi_t);
implement_subunit(si, data, zebi, dim::dimensionless_t, prefix::zebi_t);
implement_subunit(si, data, yobi, dim::dimensionless_t, prefix::yobi_t);
#pragma endregion
} // namespace data
} // namespace si
} // namespace benri