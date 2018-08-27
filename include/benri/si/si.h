#pragma once
#include <benri/units/macros.h>
#include <benri/units/dimensions.h>
#include <benri/units/prefix.h>
#include <benri/units/systems.h>
#include <benri/quantity.h>

namespace benri
{
namespace si
{
implement_unit(si, si, metre, _m, dim::length_t, prefix::one);

implement_unit(si, si, kilometre, _km, dim::length_t, prefix::kilo);
// implement_unit(si, si, millisecond_m, dim::length_t, prefix::one);
implement_unit(si, si, square_metre, _sq_m, dim::area_t, prefix::one);
implement_unit(si, si, second, _s, dim::time_t, prefix::one);

implement_unit(si, si, metre_second, _ms, dim::absement_t, prefix::one);

#pragma region si constants
create_constant(si, yocto, dim::dimensionless_t, prefix::yocto);
create_constant(si, zepto, dim::dimensionless_t, prefix::zepto);
create_constant(si, atto, dim::dimensionless_t, prefix::atto);
create_constant(si, femto, dim::dimensionless_t, prefix::femto);
create_constant(si, pico, dim::dimensionless_t, prefix::pico);
create_constant(si, nano, dim::dimensionless_t, prefix::nano);
create_constant(si, micro, dim::dimensionless_t, prefix::micro);
create_constant(si, milli, dim::dimensionless_t, prefix::milli);
create_constant(si, centi, dim::dimensionless_t, prefix::centi);
create_constant(si, deci, dim::dimensionless_t, prefix::deci);
create_constant(si, deca, dim::dimensionless_t, prefix::deca);
create_constant(si, hecto, dim::dimensionless_t, prefix::hecto);
create_constant(si, kilo, dim::dimensionless_t, prefix::kilo);
create_constant(si, mega, dim::dimensionless_t, prefix::mega);
create_constant(si, giga, dim::dimensionless_t, prefix::giga);
create_constant(si, tera, dim::dimensionless_t, prefix::tera);
create_constant(si, peta, dim::dimensionless_t, prefix::peta);
create_constant(si, exa, dim::dimensionless_t, prefix::exa);
create_constant(si, zetta, dim::dimensionless_t, prefix::zetta);
create_constant(si, yotta, dim::dimensionless_t, prefix::yotta);
#pragma endregion

create_constant(si, c, dim::velocity_t, prefix::c);
} // namespace si
} // namespace benri