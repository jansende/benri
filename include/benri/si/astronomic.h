#pragma once
#include <benri/quantity.h>
#include <benri/impl/dimensions.h>
#include <benri/impl/macros.h>
#include <benri/impl/prefix.h>
#include <benri/si/base.h>

namespace benri
{
namespace si
{
namespace astronomic
{
#pragma region length
implement_unit(astronomical_unit, dim::length_t, prefix::astronomical_unit_t);
implement_unit(lightsecond, dim::length_t, fix(multiply_lists<prefix::speed_of_light_t, prefix::second_t>));
implement_unit(lightminute, dim::length_t, fix(multiply_lists<prefix::speed_of_light_t, prefix::minute_t>));
implement_unit(lighthour, dim::length_t, fix(multiply_lists<prefix::speed_of_light_t, prefix::hour_t>));
implement_unit(lightday, dim::length_t, fix(multiply_lists<prefix::speed_of_light_t, prefix::day_t>));
implement_unit(lightyear, dim::length_t, fix(multiply_lists<prefix::speed_of_light_t, prefix::year_t>));
implement_unit(parsec, dim::length_t, prefix::parsec_t);
#pragma endregion
#pragma region mass
implement_unit(solar_mass, dim::mass_t, prefix::solar_mass_t);
implement_unit(jupiter_mass, dim::mass_t, prefix::jupiter_mass_t);
implement_unit(earth_mass, dim::mass_t, prefix::earth_mass_t);
#pragma endregion
#pragma region plane angle
implement_unit(arcminute, dim::plane_angle_t, fix(multiply_lists<prefix::pi_t, make_fraction_list<1, 10800>>));
implement_unit(arcsecond, dim::plane_angle_t, fix(multiply_lists<prefix::pi_t, make_fraction_list<1, 648000>>));
#pragma endregion
#pragma region luminosity
implement_unit(solar_luminosity, dim::luminosity_t, prefix::solar_luminosity_t);
#pragma endregion
#pragma region spectral heat flux density
//TODO: Check
implement_unit(jansky, dim::surface_tension_t, fix(multiply_lists<prefix::yocto_t, prefix::centi_t>));
#pragma endregion
} // namespace astronomic
#pragma region constants
namespace constant
{
#pragma region astronomical constants
create_constant(solar_luminosity, prefix::solar_luminosity_t, typename decltype(kilogram * square(metre) * steradian / cubic(second))::unit_type);
create_constant(solar_mass, prefix::solar_mass_t, kilogram_t);
create_constant(jupiter_mass, prefix::jupiter_mass_t, kilogram_t);
create_constant(earth_mass, prefix::earth_mass_t, kilogram_t);
#pragma endregion
} // namespace constant
#pragma endregion
#pragma region symbols
namespace symbol
{
#pragma region astronomical constants
create_symbol(solar_luminosity, dim::luminosity_t, prefix::solar_luminosity_t);
create_symbol(solar_mass, dim::mass_t, prefix::solar_mass_t);
create_symbol(jupiter_mass, dim::mass_t, prefix::jupiter_mass_t);
create_symbol(earth_mass, dim::mass_t, prefix::earth_mass_t);
#pragma endregion
} // namespace symbol
#pragma endregion
} // namespace si
} // namespace benri