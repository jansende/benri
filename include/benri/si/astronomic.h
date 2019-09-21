#pragma once
#include <benri/quantity.h>
#include <benri/si/base.h>
#include <benri/si/dimensions.h>
#include <benri/si/macros.h>
#include <benri/si/prefixes.h>

namespace benri
{
namespace si
{
namespace astronomic
{
#pragma region length
implement_unit(astronomical_unit, dimension::length_t, prefix::astronomical_unit_t);
implement_unit(lightsecond, dimension::length_t,
               fix(type::multiply_lists<prefix::speed_of_light_t, prefix::second_t>));
implement_unit(lightminute, dimension::length_t,
               fix(type::multiply_lists<prefix::speed_of_light_t, prefix::minute_t>));
implement_unit(lighthour, dimension::length_t,
               fix(type::multiply_lists<prefix::speed_of_light_t, prefix::hour_t>));
implement_unit(lightday, dimension::length_t,
               fix(type::multiply_lists<prefix::speed_of_light_t, prefix::day_t>));
implement_unit(lightyear, dimension::length_t,
               fix(type::multiply_lists<prefix::speed_of_light_t, prefix::year_t>));
implement_unit(parsec, dimension::length_t, prefix::parsec_t);
#pragma endregion
#pragma region mass
implement_unit(solar_mass, dimension::mass_t, prefix::solar_mass_t);
implement_unit(jupiter_mass, dimension::mass_t, prefix::jupiter_mass_t);
implement_unit(earth_mass, dimension::mass_t, prefix::earth_mass_t);
#pragma endregion
#pragma region plane angle
implement_unit(arcminute, dimension::plane_angle_t,
               fix(type::multiply_lists<prefix::pi_t, type::make_prefix<1, 10800>>));
implement_unit(arcsecond, dimension::plane_angle_t,
               fix(type::multiply_lists<prefix::pi_t, type::make_prefix<1, 648000>>));
#pragma endregion
#pragma region luminosity
implement_unit(solar_luminosity, dimension::luminosity_t, prefix::solar_luminosity_t);
#pragma endregion
#pragma region spectral heat flux density
// TODO: Check
implement_unit(jansky, dimension::surface_tension_t,
               fix(type::multiply_lists<prefix::yocto_t, prefix::centi_t>));
#pragma endregion
} // namespace astronomic
#pragma region constants
namespace constant
{
#pragma region astronomical constants
create_constant(solar_luminosity, prefix::solar_luminosity_t,
                typename decltype(kilogram * square(metre) * steradian
                                  / cubic(second))::unit_type);
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
create_symbol(solar_luminosity, dimension::luminosity_t, prefix::solar_luminosity_t);
create_symbol(solar_mass, dimension::mass_t, prefix::solar_mass_t);
create_symbol(jupiter_mass, dimension::mass_t, prefix::jupiter_mass_t);
create_symbol(earth_mass, dimension::mass_t, prefix::earth_mass_t);
#pragma endregion
} // namespace symbol
#pragma endregion
} // namespace si
} // namespace benri