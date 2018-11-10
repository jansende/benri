#pragma once
#include <benri/quantity.h>
#include <benri/quantity_point.h>
#include <benri/impl/dimensions.h>
#include <benri/impl/macros.h>
#include <benri/impl/prefix.h>
#include <benri/si/base.h>

namespace benri
{
namespace si
{
#pragma region speed
implement_unit(si, natural_unit_of_speed, dim::velocity_t, prefix::speed_of_light_t);
#pragma endregion
#pragma region length
implement_unit(si, angstroem, dim::length_t, prefix::angstroem_t);
implement_unit(si, bohr, dim::length_t, prefix::bohr_t);
#pragma endregion
#pragma region mass
implement_unit(si, dalton, dim::mass_t, prefix::atomic_mass_unit_t);
link_unit(atomic_mass_unit, dalton);
implement_unit(si, natural_unit_of_mass, dim::mass_t, prefix::electron_mass_t);
#pragma endregion
#pragma region time
implement_unit(si, minute, dim::time_t, prefix::minute_t);
implement_unit(si, hour, dim::time_t, prefix::hour_t);
implement_unit(si, day, dim::time_t, prefix::day_t);
implement_unit(si, week, dim::time_t, prefix::week_t);
implement_unit(si, month, dim::time_t, prefix::month_t);
implement_unit(si, year, dim::time_t, prefix::year_t);
implement_unit(si, sidereal_year, dim::time_t, prefix::sidereal_year_t);
implement_unit(si, tropical_year, dim::time_t, prefix::tropical_year_t);
implement_unit(si, natural_unit_of_time, dim::time_t, fix(impl::divide_lists_t<prefix::reduced_planck_constant_t, impl::multiply_lists_t<prefix::electron_mass_t, impl::pow_list<prefix::speed_of_light_t, std::ratio<2>>>>));
implement_unit(si, atomic_unit_of_time, dim::time_t, fix(impl::divide_lists_t<prefix::reduced_planck_constant_t, prefix::hartree_energy_t>));
#pragma endregion
#pragma region area
implement_unit(si, hectare, dim::area_t, make_fraction_list<10000>);
#pragma endregion
#pragma region volume
implement_unit(si, litre, dim::volume_t, prefix::milli);
#pragma endregion
#pragma region plane angle
implement_unit(si, gon, dim::plane_angle_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list<1, 200>>));
implement_unit(si, revolution, dim::plane_angle_t, prefix::two_pi_t);
#pragma endregion
#pragma region frequency
implement_unit(si, hertz, dim::frequency_t, prefix::one);
#pragma endregion
#pragma region force
implement_unit(si, newton, dim::force_t, prefix::one);
#pragma endregion
#pragma region pressure
//Windows headers might define the pascal macro. This conflicts with
//our pascal unit. Therefore, we save the content in BENRI_PASCAL and
//remove the macro.
#ifdef pascal
#define BENRI_PASCAL pascal
#undef pascal
#endif
implement_unit(si, pascal, dim::pressure_t, prefix::one);
//Restore the value of the pascal macro, if necessary.
#ifdef BENRI_PASCAL
#define pascal BENRI_PASCAL
#undef BENRI_PASCAL
#endif
implement_unit(si, bar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::one, make_power_list<5>>));
#pragma endregion
#pragma region energy
implement_unit(si, joule, dim::energy_t, prefix::one);
implement_unit(si, electron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::one, prefix::elementary_charge_t>));
implement_unit(si, hartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::one, prefix::hartree_energy_t>));
#pragma endregion
#pragma region power
implement_unit(si, watt, dim::power_t, prefix::one);
#pragma endregion
#pragma region electric charge
implement_unit(si, coulomb, dim::electric_charge_t, prefix::one);
implement_unit(si, electron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::one, prefix::elementary_charge_t>));
#pragma endregion
#pragma region electric potential
implement_unit(si, volt, dim::electric_potential_t, prefix::one);
#pragma endregion
#pragma region capacitance
implement_unit(si, farad, dim::capacitance_t, prefix::one);
#pragma endregion
#pragma region electric resistance
implement_unit(si, ohm, dim::electric_resistance_t, prefix::one);
#pragma endregion
#pragma region electric conductance
implement_unit(si, siemens, dim::electric_conductance_t, prefix::one);
#pragma endregion
#pragma region magnetic flux
implement_unit(si, weber, dim::magnetic_flux_t, prefix::one);
#pragma endregion
#pragma region magnetic flux density
implement_unit(si, tesla, dim::magnetic_flux_density_t, prefix::one);
#pragma endregion
#pragma region inductance
implement_unit(si, henry, dim::inductance_t, prefix::one);
#pragma endregion
#pragma region luminous flux
implement_unit(si, lumen, dim::luminous_flux_t, prefix::one);
#pragma endregion
#pragma region illuminance
implement_unit(si, lux, dim::illuminance_t, prefix::one);
#pragma endregion
#pragma region activity referred to a radionuclide
implement_unit(si, becquerel, dim::activity_of_radionuclide_t, prefix::one);
#pragma endregion
#pragma region specific energy
implement_unit(si, gray, dim::absorbed_dose_t, prefix::one);
#pragma endregion
#pragma region dose equivalent
implement_unit(si, sievert, dim::dose_equivalent_t, prefix::one);
#pragma endregion
#pragma region catalytic activity
implement_unit(si, katal, dim::catalytic_activity_t, prefix::one);
#pragma endregion
} // namespace si
} // namespace benri