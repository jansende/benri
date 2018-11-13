#pragma once
#include <benri/quantity.h>
#include <benri/impl/dimensions.h>
#include <benri/impl/macros.h>
#include <benri/impl/prefix.h>

namespace benri
{
namespace si
{
namespace cgs
{
#pragma region acceleration
implement_unit(gal, dim::acceleration_t, prefix::deci_t);
#pragma endregion
#pragma region dynamic viscosity
implement_unit(poise, dim::dynamic_viscosity_t, prefix::deci_t);
#pragma endregion
#pragma region magnetic flux
implement_unit(maxwell, dim::magnetic_flux_t, fix(multiply_lists<prefix::nano_t, prefix::deca_t>));
#pragma endregion
#pragma region magentic flux density
implement_unit(gauss, dim::magnetic_flux_density_t, fix(multiply_lists<prefix::milli_t, prefix::deci_t>));
#pragma endregion
#pragma region energy
implement_unit(erg, dim::energy_t, fix(multiply_lists<prefix::nano_t, prefix::hecto_t>));
#pragma endregion
#pragma region force
implement_unit(dyne, dim::force_t, fix(multiply_lists<prefix::micro_t, prefix::deca_t>));
#pragma endregion
#pragma region magnetic field strength
implement_unit(oersted, dim::magnetic_field_strength_t, fix(divide_lists<prefix::kilo_t, multiply_lists<make_fraction_list<4>, prefix::pi_t>>));
#pragma endregion
#pragma region luminance
implement_unit(stilb, dim::luminance_t, make_power_list<-4>);
#pragma endregion
} // namespace cgs
} // namespace si
} // namespace benri