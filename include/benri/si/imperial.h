#pragma once
#include <benri/casts.h>
#include <benri/quantity.h>
#include <benri/si/dimensions.h>
#include <benri/si/macros.h>
#include <benri/si/prefixes.h>

namespace benri
{
namespace si
{
namespace imperial
{
#pragma region length
implement_unit(nautical_mile, dimension::length_t, prefix::nautical_mile_t);
implement_unit(international_mile, dimension::length_t, prefix::international_mile_t);
link_unit(mile, international_mile);
implement_unit(yard, dimension::length_t, prefix::yard_t);
implement_unit(international_foot, dimension::length_t, prefix::international_foot_t);
implement_unit(inch, dimension::length_t, prefix::inch_t);
implement_unit(smoot, dimension::length_t, prefix::smoot_t);
#pragma endregion
#pragma region area
implement_unit(barn, dimension::area_t, type::make_prefix_pow10<-28>);
#pragma endregion
#pragma region mass
implement_unit(
    carat, dimension::mass_t,
    fix(type::multiply_lists<type::make_prefix<2>, type::make_prefix_pow10<-4>>));
implement_unit(pound, dimension::mass_t, prefix::pound_t);
implement_unit(ounce, dimension::mass_t, prefix::ounce_t);
#pragma endregion
#pragma region velocity
implement_unit(knot, dimension::velocity_t,
               fix(type::divide_lists<prefix::nautical_mile_t, prefix::hour_t>));
#pragma endregion
#pragma region pressure
implement_unit(torr, dimension::pressure_t, fix(type::make_prefix<101325, 760>));
implement_unit(millimeter_of_mercury, dimension::pressure_t,
               fix(type::make_prefix<133322, 1000>));
implement_unit(atmosphere, dimension::pressure_t, type::make_prefix<101325>);
#pragma endregion
} // namespace imperial
} // namespace si
} // namespace benri