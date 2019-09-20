#pragma once
#include <benri/quantity.h>
#include <benri/quantity_point.h>
#include <benri/impl/benri/dimensions.h>
#include <benri/impl/benri/macros.h>
#include <benri/impl/benri/prefixes.h>
#include <benri/si/base.h>

namespace benri
{
namespace si
{
#pragma region speed
implement_unit(natural_unit_of_speed, dim::velocity_t, prefix::speed_of_light_t);
#pragma endregion
#pragma region length
implement_unit(angstroem, dim::length_t, prefix::angstroem_t);
implement_unit(bohr, dim::length_t, prefix::bohr_t);
#pragma endregion
#pragma region mass
implement_unit(dalton, dim::mass_t, prefix::atomic_mass_unit_t);
link_unit(atomic_mass_unit, dalton);
implement_unit(natural_unit_of_mass, dim::mass_t, prefix::electron_mass_t);
#pragma endregion
#pragma region time
implement_unit(minute, dim::time_t, prefix::minute_t);
implement_unit(hour, dim::time_t, prefix::hour_t);
implement_unit(day, dim::time_t, prefix::day_t);
implement_unit(week, dim::time_t, prefix::week_t);
implement_unit(month, dim::time_t, prefix::month_t);
implement_unit(year, dim::time_t, prefix::year_t);
implement_unit(sidereal_year, dim::time_t, prefix::sidereal_year_t);
implement_unit(tropical_year, dim::time_t, prefix::tropical_year_t);
implement_unit(natural_unit_of_time, dim::time_t, fix(divide_lists<prefix::reduced_planck_constant_t, multiply_lists<prefix::electron_mass_t, pow_list<prefix::speed_of_light_t, std::ratio<2>>>>));
implement_unit(atomic_unit_of_time, dim::time_t, fix(divide_lists<prefix::reduced_planck_constant_t, prefix::hartree_energy_t>));
#pragma endregion
#pragma region area
implement_unit(hectare, dim::area_t, make_fraction_list<10000>);
#pragma endregion
#pragma region volume
implement_unit(litre, dim::volume_t, prefix::milli_t);
#pragma endregion
#pragma region plane angle
implement_unit(gon, dim::plane_angle_t, fix(multiply_lists<prefix::pi_t, make_fraction_list<1, 200>>));
implement_unit(revolution, dim::plane_angle_t, prefix::two_pi_t);
#pragma endregion
#pragma region frequency
implement_unit(hertz, dim::frequency_t, prefix::one_t);
#pragma endregion
#pragma region force
implement_unit(newton, dim::force_t, prefix::one_t);
#pragma endregion
#pragma region pressure
//Windows headers might define the pascal macro. This conflicts with
//our pascal unit. Therefore, we save the content in BENRI_PASCAL and
//remove the macro.
#ifdef pascal
#define BENRI_PASCAL pascal
#undef pascal
#endif
implement_unit(pascal, dim::pressure_t, prefix::one_t);
//Restore the value of the pascal macro, if necessary.
#ifdef BENRI_PASCAL
#define pascal BENRI_PASCAL
#undef BENRI_PASCAL
#endif
implement_unit(bar, dim::pressure_t, make_power_list<5>);
#pragma endregion
#pragma region energy
implement_unit(joule, dim::energy_t, prefix::one_t);
implement_unit(electron_volt, dim::energy_t, prefix::elementary_charge_t);
implement_unit(hartree, dim::energy_t, prefix::hartree_energy_t);
#pragma endregion
#pragma region power
implement_unit(watt, dim::power_t, prefix::one_t);
#pragma endregion
#pragma region electric charge
implement_unit(coulomb, dim::electric_charge_t, prefix::one_t);
implement_unit(electron, dim::electric_charge_t, prefix::elementary_charge_t);
#pragma endregion
#pragma region electric potential
implement_unit(volt, dim::electric_potential_t, prefix::one_t);
#pragma endregion
#pragma region capacitance
implement_unit(farad, dim::capacitance_t, prefix::one_t);
#pragma endregion
#pragma region electric resistance
implement_unit(ohm, dim::electric_resistance_t, prefix::one_t);
#pragma endregion
#pragma region electric conductance
implement_unit(siemens, dim::electric_conductance_t, prefix::one_t);
#pragma endregion
#pragma region magnetic flux
implement_unit(weber, dim::magnetic_flux_t, prefix::one_t);
#pragma endregion
#pragma region magnetic flux density
implement_unit(tesla, dim::magnetic_flux_density_t, prefix::one_t);
#pragma endregion
#pragma region inductance
implement_unit(henry, dim::inductance_t, prefix::one_t);
#pragma endregion
#pragma region luminous flux
implement_unit(lumen, dim::luminous_flux_t, prefix::one_t);
#pragma endregion
#pragma region illuminance
implement_unit(lux, dim::illuminance_t, prefix::one_t);
#pragma endregion
#pragma region activity referred to a radionuclide
implement_unit(becquerel, dim::activity_of_radionuclide_t, prefix::one_t);
#pragma endregion
#pragma region specific energy
implement_unit(gray, dim::absorbed_dose_t, prefix::one_t);
#pragma endregion
#pragma region dose equivalent
implement_unit(sievert, dim::dose_equivalent_t, prefix::one_t);
#pragma endregion
#pragma region catalytic activity
implement_unit(katal, dim::catalytic_activity_t, prefix::one_t);
#pragma endregion
} // namespace si
} // namespace benri