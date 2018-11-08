#pragma once
#include <benri/si/system.h>
#include <benri/units/dimensions.h>
#include <benri/units/macros.h>
#include <benri/units/prefix.h>

namespace benri
{
namespace si
{
namespace cgs
{
#pragma region gal(acceleration)
implement_subunit(si, si, cgs, gal, dim::acceleration_t, prefix::deci);
#pragma endregion
#pragma region poise(dynamic viscosity)
implement_subunit(si, si, cgs, poise, dim::dynamic_viscosity_t, prefix::deci);
#pragma endregion
#pragma region maxwell(magnetic flux)
implement_subunit(si, si, cgs, maxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::one>));
#pragma endregion
#pragma region gauss(magentic flux density)
implement_subunit(si, si, cgs, gauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::one>));
#pragma endregion
#pragma region erg(energy)
implement_subunit(si, si, cgs, erg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::one>));
#pragma endregion
#pragma region erg/g(specific energy)
#pragma endregion
#pragma region dyne(force)
implement_subunit(si, si, cgs, dyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::one>));
#pragma endregion
#pragma region oersted(magnetic field strength)
implement_subunit(si, si, cgs, oersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list<4>,prefix::pi_t>>,prefix::one>));
#pragma endregion
#pragma region stilb(luminance)
implement_subunit(si, si, cgs, stilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list<-4>,prefix::one>));
#pragma endregion
} // namespace cgs
} // namespace si
} // namespace benri