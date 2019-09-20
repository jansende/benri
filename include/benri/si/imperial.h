#pragma once
#include <benri/quantity.h>
#include <benri/impl/dimensions.h>
#include <benri/impl/macros.h>
#include <benri/impl/prefix.h>

namespace benri
{
namespace si
{
namespace imperial
{
#pragma region length
implement_unit(nautical_mile, dimension::length_t, prefix::nautical_mile_t);
implement_unit(international_mile, dimension::length_t, prefix::international_mile_t);
implement_unit(yard, dimension::length_t, prefix::yard_t);
implement_unit(international_foot, dimension::length_t, prefix::international_foot_t);
implement_unit(inch, dimension::length_t, prefix::inch_t);
#pragma endregion
#pragma region area
implement_unit(barn, dimension::area_t, make_prefix_pow10<-28>);
#pragma endregion
#pragma region mass
implement_unit(carat, dimension::mass_t, fix(multiply_lists<make_prefix<2>, make_prefix_pow10<-4>>));
implement_unit(pound, dimension::mass_t, prefix::pound_t);
implement_unit(ounce, dimension::mass_t, prefix::ounce_t);
#pragma endregion
#pragma region velocity
implement_unit(knot, dimension::velocity_t, fix(divide_lists<prefix::nautical_mile_t, prefix::hour_t>));
#pragma endregion
#pragma region pressure
implement_unit(torr, dimension::pressure_t, fix(make_prefix<101325, 760>));
implement_unit(millimeter_of_mercury, dimension::pressure_t, fix(make_prefix<133322, 1000>));
implement_unit(atmosphere, dimension::pressure_t, make_prefix<101325>);
#pragma endregion
} // namespace imperial
} // namespace si
} // namespace benri