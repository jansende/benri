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
implement_unit(nautical_mile, dim::length_t, prefix::nautical_mile_t);
implement_unit(international_mile, dim::length_t, prefix::international_mile_t);
implement_unit(yard, dim::length_t, prefix::yard_t);
implement_unit(international_foot, dim::length_t, prefix::international_foot_t);
implement_unit(inch, dim::length_t, prefix::inch_t);
#pragma endregion
#pragma region area
implement_unit(barn, dim::area_t, make_power_list<-28>);
#pragma endregion
#pragma region mass
implement_unit(carat, dim::mass_t, fix(multiply_lists<make_fraction_list<2>, make_power_list<-4>>));
implement_unit(pound, dim::mass_t, prefix::pound_t);
implement_unit(ounce, dim::mass_t, prefix::ounce_t);
#pragma endregion
#pragma region velocity
implement_unit(knot, dim::velocity_t, fix(divide_lists<prefix::nautical_mile_t, prefix::hour_t>));
#pragma endregion
#pragma region pressure
implement_unit(torr, dim::pressure_t, fix(make_fraction_list<101325, 760>));
implement_unit(millimeter_of_mercury, dim::pressure_t, fix(make_fraction_list<133322, 1000>));
implement_unit(atmosphere, dim::pressure_t, make_fraction_list<101325>);
#pragma endregion
} // namespace imperial
} // namespace si
} // namespace benri