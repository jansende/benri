#pragma once
#include <benri/casts.h>
#include <benri/quantity.h>
#include <benri/quantity_point.h>
#include <benri/si/base.h>
#include <benri/si/dimensions.h>
#include <benri/si/macros.h>
#include <benri/si/prefixes.h>

namespace benri
{
namespace si
{
#pragma region speed
implement_unit(natural_unit_of_speed, dimension::velocity_t, prefix::speed_of_light_t);
#pragma endregion
#pragma region length
implement_unit(angstroem, dimension::length_t, prefix::angstroem_t);
implement_unit(bohr, dimension::length_t, prefix::bohr_t);
#pragma endregion
#pragma region mass
implement_unit(dalton, dimension::mass_t, prefix::atomic_mass_unit_t);
link_unit(atomic_mass_unit, dalton);
implement_unit(natural_unit_of_mass, dimension::mass_t, prefix::electron_mass_t);
#pragma endregion
#pragma region time
implement_unit(minute, dimension::time_t, prefix::minute_t);
implement_unit(hour, dimension::time_t, prefix::hour_t);
implement_unit(day, dimension::time_t, prefix::day_t);
implement_unit(week, dimension::time_t, prefix::week_t);
implement_unit(gregorian_month, dimension::time_t, prefix::month_t);
implement_unit(gregorian_year, dimension::time_t, prefix::year_t);
link_unit(month, gregorian_month);
link_unit(year, gregorian_year);
implement_unit(sidereal_year, dimension::time_t, prefix::sidereal_year_t);
implement_unit(tropical_year, dimension::time_t, prefix::tropical_year_t);
implement_unit(
    natural_unit_of_time, dimension::time_t,
    fix(type::divide_lists<
        prefix::reduced_planck_constant_t,
        type::multiply_lists<prefix::electron_mass_t,
                             type::pow_list<prefix::speed_of_light_t, std::ratio<2>>>>));
implement_unit(
    atomic_unit_of_time, dimension::time_t,
    fix(type::divide_lists<prefix::reduced_planck_constant_t, prefix::hartree_energy_t>));
#pragma endregion
#pragma region area
implement_unit(hectare, dimension::area_t, type::make_prefix<10000>);
#pragma endregion
#pragma region volume
implement_unit(litre, dimension::volume_t, prefix::milli_t);
#pragma endregion
#pragma region plane angle
implement_unit(gon, dimension::plane_angle_t,
               fix(type::multiply_lists<prefix::pi_t, type::make_prefix<1, 200>>));
implement_unit(revolution, dimension::plane_angle_t, prefix::two_pi_t);
#pragma endregion
#pragma region frequency
implement_unit(hertz, dimension::frequency_t, prefix::one_t);
#pragma endregion
#pragma region force
implement_unit(newton, dimension::force_t, prefix::one_t);
#pragma endregion
#pragma region pressure
// Windows headers might define the pascal macro. This conflicts with
// our pascal unit. Therefore, we save the content in BENRI_PASCAL and
// remove the macro.
#ifdef pascal
#define BENRI_PASCAL pascal
#undef pascal
#endif
implement_unit(pascal, dimension::pressure_t, prefix::one_t);
// Restore the value of the pascal macro, if necessary.
#ifdef BENRI_PASCAL
#define pascal BENRI_PASCAL
#undef BENRI_PASCAL
#endif
implement_unit(bar, dimension::pressure_t, type::make_prefix_pow10<5>);
#pragma endregion
#pragma region energy
implement_unit(joule, dimension::energy_t, prefix::one_t);
implement_unit(electron_volt, dimension::energy_t, prefix::elementary_charge_t);
implement_unit(hartree, dimension::energy_t, prefix::hartree_energy_t);
#pragma endregion
#pragma region power
implement_unit(watt, dimension::power_t, prefix::one_t);
#pragma endregion
#pragma region electric charge
implement_unit(coulomb, dimension::electric_charge_t, prefix::one_t);
implement_unit(electron, dimension::electric_charge_t, prefix::elementary_charge_t);
#pragma endregion
#pragma region electric potential
implement_unit(volt, dimension::electric_potential_t, prefix::one_t);
#pragma endregion
#pragma region capacitance
implement_unit(farad, dimension::capacitance_t, prefix::one_t);
#pragma endregion
#pragma region electric resistance
implement_unit(ohm, dimension::electric_resistance_t, prefix::one_t);
#pragma endregion
#pragma region electric conductance
implement_unit(siemens, dimension::electric_conductance_t, prefix::one_t);
#pragma endregion
#pragma region magnetic flux
implement_unit(weber, dimension::magnetic_flux_t, prefix::one_t);
#pragma endregion
#pragma region magnetic flux density
implement_unit(tesla, dimension::magnetic_flux_density_t, prefix::one_t);
#pragma endregion
#pragma region inductance
implement_unit(henry, dimension::inductance_t, prefix::one_t);
#pragma endregion
#pragma region luminous flux
implement_unit(lumen, dimension::luminous_flux_t, prefix::one_t);
#pragma endregion
#pragma region illuminance
implement_unit(lux, dimension::illuminance_t, prefix::one_t);
#pragma endregion
#pragma region activity referred to a radionuclide
implement_unit(becquerel, dimension::activity_of_radionuclide_t, prefix::one_t);
#pragma endregion
#pragma region specific energy
implement_unit(gray, dimension::absorbed_dose_t, prefix::one_t);
#pragma endregion
#pragma region dose equivalent
implement_unit(sievert, dimension::dose_equivalent_t, prefix::one_t);
#pragma endregion
#pragma region catalytic activity
implement_unit(katal, dimension::catalytic_activity_t, prefix::one_t);
#pragma endregion
} // namespace si
} // namespace benri