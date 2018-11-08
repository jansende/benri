#pragma once
#include <benri/si/system.h>
#include <benri/units/dimensions.h>
#include <benri/units/macros.h>
#include <benri/units/prefix.h>

namespace benri
{
namespace si
{
namespace astronomic
{
#pragma region astronomical unit(length)
implement_subunit(si, si, astronomic, astronomical_unit, dim::length_t, prefix::astronomical_unit_t);
#pragma endregion
#pragma region light speed based units(length)
implement_subunit(si, si, astronomic, lightsecond, dim::length_t, fix(impl::multiply_lists_t<prefix::speed_of_light_t, prefix::second_t>));
implement_subunit(si, si, astronomic, lightminute, dim::length_t, fix(impl::multiply_lists_t<prefix::speed_of_light_t, prefix::minute_t>));
implement_subunit(si, si, astronomic, lighthour, dim::length_t, fix(impl::multiply_lists_t<prefix::speed_of_light_t, prefix::hour_t>));
implement_subunit(si, si, astronomic, lightday, dim::length_t, fix(impl::multiply_lists_t<prefix::speed_of_light_t, prefix::day_t>));
implement_subunit(si, si, astronomic, lightyear, dim::length_t, fix(impl::multiply_lists_t<prefix::speed_of_light_t, prefix::year_t>));
#pragma endregion
#pragma region parsec(length)
implement_subunit(si, si, astronomic, parsec, dim::length_t, fix(impl::multiply_lists_t<prefix::one, prefix::parsec_t>));
implement_subunit(si, si, astronomic, kiloparsec, dim::length_t, fix(impl::multiply_lists_t<prefix::kilo, prefix::parsec_t>));
implement_subunit(si, si, astronomic, megaparsec, dim::length_t, fix(impl::multiply_lists_t<prefix::mega, prefix::parsec_t>));
implement_subunit(si, si, astronomic, gigaparsec, dim::length_t, fix(impl::multiply_lists_t<prefix::giga, prefix::parsec_t>));
#pragma endregion
#pragma region solar mass, ...(mass)
implement_subunit(si, si, astronomic, solar_mass, dim::mass_t, prefix::solar_mass_t);
implement_subunit(si, si, astronomic, jupiter_mass, dim::mass_t, prefix::jupiter_mass_t);
implement_subunit(si, si, astronomic, earth_mass, dim::mass_t, prefix::earth_mass_t);
#pragma endregion
#pragma region solar mass per year, ...(massloss)
implement_subunit(si, si, astronomic, solar_mass_per_year, dim::massloss_t, fix(impl::divide_lists_t<prefix::solar_mass_t, prefix::year_t>));
implement_subunit(si, si, astronomic, jupiter_mass_per_year, dim::massloss_t, fix(impl::divide_lists_t<prefix::jupiter_mass_t, prefix::year_t>));
implement_subunit(si, si, astronomic, earth_mass_per_year, dim::massloss_t, fix(impl::divide_lists_t<prefix::earth_mass_t, prefix::year_t>));
#pragma endregion
#pragma region solar luminosity (luminosity)
implement_subunit(si, si, astronomic, solar_luminosity, dim::luminosity_t, prefix::solar_luminosity_t);
#pragma endregion
} // namespace astronomic
#pragma region constants
namespace constant
{
using namespace benri::si::base;
#pragma region astronomical constants
create_constant(solar_luminosity, prefix::solar_luminosity_v, typename decltype(watt / steradian)::unit_type);
create_constant(solar_mass, prefix::solar_mass_v, kilogram_t);
create_constant(jupiter_mass, prefix::jupiter_mass_v, kilogram_t);
create_constant(earth_mass, prefix::earth_mass_v, kilogram_t);
#pragma endregion
} // namespace constant
#pragma endregion
#pragma region symbols
namespace symbol
{
#pragma region astronomical constants
create_symbol(si, solar_luminosity, dim::luminosity_t, prefix::solar_luminosity_t);
create_symbol(si, solar_mass, dim::mass_t, prefix::solar_mass_t);
create_symbol(si, jupiter_mass, dim::mass_t, prefix::jupiter_mass_t);
create_symbol(si, earth_mass, dim::mass_t, prefix::earth_mass_t);
#pragma endregion
} // namespace symbol
#pragma endregion
} // namespace si
} // namespace benri