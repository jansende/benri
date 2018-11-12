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
implement_subunit(si, imperial, nautical_mile, dim::length_t, prefix::nautical_mile_t);
implement_subunit(si, imperial, international_mile, dim::length_t, prefix::international_mile_t);
implement_subunit(si, imperial, yard, dim::length_t, prefix::yard_t);
implement_subunit(si, imperial, international_foot, dim::length_t, prefix::international_foot_t);
implement_subunit(si, imperial, inch, dim::length_t, prefix::inch_t);
#pragma endregion
#pragma region area
implement_subunit(si, imperial, barn, dim::area_t, make_power_list<-28>);
#pragma endregion
#pragma region mass
implement_subunit(si, imperial, carat, dim::mass_t, fix(multiply_lists<make_fraction_list<2>, make_power_list<-4>>));
implement_subunit(si, imperial, pound, dim::mass_t, prefix::pound_t);
implement_subunit(si, imperial, ounce, dim::mass_t, prefix::ounce_t);
#pragma endregion
#pragma region velocity
implement_subunit(si, imperial, knot, dim::velocity_t, fix(divide_lists<prefix::nautical_mile_t, prefix::hour_t>));
#pragma endregion
#pragma region pressure
implement_subunit(si, imperial, torr, dim::pressure_t, fix(make_fraction_list<101325, 760>));
implement_subunit(si, imperial, millimeter_of_mercury, dim::pressure_t, fix(make_fraction_list<133322, 1000>));
implement_subunit(si, imperial, atmosphere, dim::pressure_t, make_fraction_list<101325>);
#pragma endregion
} // namespace imperial
} // namespace si
} // namespace benri