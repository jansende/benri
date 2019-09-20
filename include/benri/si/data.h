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
implement_unit(px, dimension::screen_position_t, prefix::one_t);
link_unit_point(px_position, px);
#pragma endregion
#pragma region screen area
implement_unit(pixel, dimension::screen_area_t, prefix::one_t);
#pragma endregion
#pragma region amount of data
implement_unit(byte, dimension::amount_of_data_t, prefix::one_t);
implement_unit(bit, dimension::amount_of_data_t, fix(make_prefix<1, 8>));
#pragma endregion
#pragma region prefixes
implement_unit(kibi, dimension::dimensionless_t, prefix::kibi_t);
implement_unit(mebi, dimension::dimensionless_t, prefix::mebi_t);
implement_unit(gibi, dimension::dimensionless_t, prefix::gibi_t);
implement_unit(tebi, dimension::dimensionless_t, prefix::tebi_t);
implement_unit(pebi, dimension::dimensionless_t, prefix::pebi_t);
implement_unit(exbi, dimension::dimensionless_t, prefix::exbi_t);
implement_unit(zebi, dimension::dimensionless_t, prefix::zebi_t);
implement_unit(yobi, dimension::dimensionless_t, prefix::yobi_t);
#pragma endregion
} // namespace data
} // namespace si
} // namespace benri