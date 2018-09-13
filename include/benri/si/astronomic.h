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
implement_subunit(si, si, astronomic, astronomical_unit, _astronomical_unit, dim::length_t, prefix::astronomical_unit_t);
#pragma endregion
#pragma region light speed based units(length)
implement_subunit(si, si, astronomic, lightsecond, _lightsecond, dim::length_t, fix(impl::multiply_lists_t<prefix::speed_of_light_t, prefix::second>));
implement_subunit(si, si, astronomic, lightminute, _lightminute, dim::length_t, fix(impl::multiply_lists_t<prefix::speed_of_light_t, prefix::minute>));
implement_subunit(si, si, astronomic, lighthour, _lighthour, dim::length_t, fix(impl::multiply_lists_t<prefix::speed_of_light_t, prefix::hour>));
implement_subunit(si, si, astronomic, lightday, _lightday, dim::length_t, fix(impl::multiply_lists_t<prefix::speed_of_light_t, prefix::day>));
implement_subunit(si, si, astronomic, lightyear, _lightyear, dim::length_t, fix(impl::multiply_lists_t<prefix::speed_of_light_t, prefix::year>));
implement_subunit(si, si, astronomic, kilolightyear, _kilolightyear, dim::length_t, fix(impl::multiply_lists_t<prefix::kilo, impl::multiply_lists_t<prefix::speed_of_light_t, prefix::year>>));
implement_subunit(si, si, astronomic, megalightyear, _megalightyear, dim::length_t, fix(impl::multiply_lists_t<prefix::mega, impl::multiply_lists_t<prefix::speed_of_light_t, prefix::year>>));
implement_subunit(si, si, astronomic, gigalightyear, _gigalightyear, dim::length_t, fix(impl::multiply_lists_t<prefix::giga, impl::multiply_lists_t<prefix::speed_of_light_t, prefix::year>>));
#pragma endregion
#pragma region parsec(length)
implement_subunit(si, si, astronomic, parsec, _parsec, dim::length_t, fix(impl::multiply_lists_t<prefix::one, prefix::parsec_t>));
implement_subunit(si, si, astronomic, kiloparsec, _kiloparsec, dim::length_t, fix(impl::multiply_lists_t<prefix::kilo, prefix::parsec_t>));
implement_subunit(si, si, astronomic, megaparsec, _megaparsec, dim::length_t, fix(impl::multiply_lists_t<prefix::mega, prefix::parsec_t>));
implement_subunit(si, si, astronomic, gigaparsec, _gigaparsec, dim::length_t, fix(impl::multiply_lists_t<prefix::giga, prefix::parsec_t>));
#pragma endregion
#pragma region solar mass, ...(mass)
implement_subunit(si, si, astronomic, solar_mass, _solar_mass, dim::mass_t, prefix::solar_mass_t);
implement_subunit(si, si, astronomic, jupiter_mass, _jupiter_mass, dim::mass_t, prefix::jupiter_mass_t);
implement_subunit(si, si, astronomic, earth_mass, _earth_mass, dim::mass_t, prefix::earth_mass_t);
#pragma endregion
} // namespace astronomic
#pragma region constants
namespace constant
{
using namespace benri::si::base;
#pragma region astronomical constants
create_constant(solar_mass, prefix::solar_mass_v, kilogram);
create_constant(jupiter_mass, prefix::jupiter_mass_v, kilogram);
create_constant(earth_mass, prefix::earth_mass_v, kilogram);
#pragma endregion
} // namespace constant
#pragma endregion
#pragma region symbols
namespace symbol
{
#pragma region astronomical constants
create_symbol(si, solar_mass, dim::mass_t, prefix::solar_mass_t);
create_symbol(si, jupiter_mass, dim::mass_t, prefix::jupiter_mass_t);
create_symbol(si, earth_mass, dim::mass_t, prefix::earth_mass_t);
#pragma endregion
} // namespace symbol
#pragma endregion
} // namespace si
} // namespace benri