#pragma once
#include <benri/si/base.h>
#include <benri/si/extra.h>
#include <benri/si/chemical.h>

namespace benri
{
namespace si
{
template <class T>
constexpr auto square(T val) {
    return val * val;
}
template <class T>
constexpr auto cubic(T val) {
    return val * val * val;
}
using namespace benri::si::base;
#pragma region units
implement_unit(si, si, natural_unit_of_speed, dim::velocity_t, prefix::speed_of_light_t);
implement_unit(si, si, knot, dim::velocity_t, fix(impl::divide_lists_t<prefix::nautical_mile_t,prefix::hour_t>));
#pragma region angstroem, ...(length)
implement_unit(si, si, angstroem, dim::length_t, prefix::angstroem_t);
implement_unit(si, si, bohr, dim::length_t, prefix::bohr_t);
implement_unit(si, si, nautical_mile, dim::length_t, prefix::nautical_mile_t);
implement_unit(si, si, international_mile, dim::length_t, prefix::international_mile_t);
implement_unit(si, si, yard, dim::length_t, prefix::yard_t);
implement_unit(si, si, international_foot, dim::length_t, prefix::international_foot_t);
implement_unit(si, si, inch, dim::length_t, prefix::inch_t);
#pragma endregion
#pragma region dalton, ...(mass)
implement_unit(si, si, dalton, dim::mass_t, prefix::atomic_mass_unit_t);
link_unit(atomic_mass_unit, dalton);
implement_unit(si, si, natural_unit_of_mass, dim::mass_t, prefix::electron_mass_t);
implement_unit(si, si, carat, dim::mass_t, fix(impl::multiply_lists_t<make_fraction_list<2>,make_power_list<-4>>));
implement_unit(si, si, pound, dim::mass_t, prefix::pound_t);
implement_unit(si, si, ounce, dim::mass_t, prefix::ounce_t);
#pragma endregion
#pragma region minute, hour, ...(time)
implement_unit(si, si, minute, dim::time_t, prefix::minute_t);
implement_unit(si, si, hour, dim::time_t, prefix::hour_t);
implement_unit(si, si, day, dim::time_t, prefix::day_t);
implement_unit(si, si, week, dim::time_t, prefix::week_t);
implement_unit(si, si, month, dim::time_t, prefix::month_t);
implement_unit(si, si, year, dim::time_t, prefix::year_t);
implement_unit(si, si, sidereal_year, dim::time_t, prefix::sidereal_year_t);
implement_unit(si, si, tropical_year, dim::time_t, prefix::tropical_year_t);
implement_unit(si, si, natural_unit_of_time, dim::time_t, fix(impl::divide_lists_t<prefix::reduced_planck_constant_t,impl::multiply_lists_t<prefix::electron_mass_t,impl::pow_list<prefix::speed_of_light_t,std::ratio<2>>>>));
implement_unit(si, si, atomic_unit_of_time, dim::time_t, fix(impl::divide_lists_t<prefix::reduced_planck_constant_t,prefix::hartree_energy_t>));
#pragma endregion
#pragma region square metre(area)
implement_unit(si, si, barn, dim::area_t, make_power_list<-28>);
implement_unit(si, si, hectare, dim::area_t, make_fraction_list<10000>);
#pragma endregion
#pragma region cubic metre(volume)
implement_unit(si, si, litre, dim::volume_t, prefix::milli);
#pragma endregion
#pragma region metre per second(velocity)
#pragma endregion
#pragma region metre per minute(velocity)
#pragma endregion
#pragma region metre per hour(velocity)
#pragma endregion
#pragma region metre per square second(acceleration)
#pragma endregion
#pragma region metre per square minute(acceleration)
#pragma endregion
#pragma region metre per square hour(acceleration)
#pragma endregion
#pragma region one per metre(wavenumber)
#pragma endregion
#pragma region kilogram per cubic metre(density)
#pragma endregion
#pragma region kilogram per cubic decimetre(density)
#pragma endregion
#pragma region kilogram per litre(density)
#pragma endregion
#pragma region kilogram per cubic centimetre(density)
#pragma endregion
#pragma region kilogram per millilitre(density)
#pragma endregion
#pragma region kilogram per square metre(area density)
#pragma endregion
#pragma region cubic metre per kilogram(specific volume)
#pragma endregion
#pragma region ampere per square metre(current density)
#pragma endregion
#pragma region ampere per metre(magnetic field strength)
#pragma endregion
#pragma region mole per cubic metre(concentration)
#pragma endregion
#pragma region candela per square metre(luminance)
#pragma endregion
#pragma region plane angle
implement_unit(si, si, gon, dim::plane_angle_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list<1, 200>>));
implement_unit(si, si, revolution, dim::plane_angle_t, prefix::two_pi_t);
#pragma endregion
#pragma region solid angle
implement_unit(si, si, steradian, dim::solid_angle_t, prefix::one);
#pragma endregion
#pragma region hertz(frequency)
implement_unit(si, si, hertz, dim::frequency_t, prefix::one);
#pragma endregion
#pragma region newton(force)
implement_unit(si, si, newton, dim::force_t, prefix::one);
#pragma endregion
#pragma region pascal(pressure)
implement_unit(si, si, pascal, dim::pressure_t, prefix::one);
#pragma endregion
#pragma region bar, mmHg, ...(pressure)
implement_unit(si, si, bar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::one, make_power_list<5>>));

implement_unit(si, si, millimeter_of_mercury, dim::pressure_t, fix(make_fraction_list<133322,1000>));
implement_unit(si, si, atmosphere, dim::pressure_t, make_fraction_list<101325>);
implement_unit(si, si, torr, dim::pressure_t, fix(make_fraction_list<101325,760>));
#pragma endregion
#pragma region joule(energy)
implement_unit(si, si, joule, dim::energy_t, prefix::one);
#pragma endregion
#pragma region electron volt, hartree(energy)
implement_unit(si, si, electron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::one,prefix::elementary_charge_t>));

implement_unit(si, si, hartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::one,prefix::hartree_energy_t>));
#pragma endregion
#pragma region watt minute(energy)
#pragma endregion
#pragma region watt hour(energy)
#pragma endregion
#pragma region watt(power)
implement_unit(si, si, watt, dim::power_t, prefix::one);
#pragma endregion
#pragma region coulomb(electric charge)
implement_unit(si, si, coulomb, dim::electric_charge_t, prefix::one);
#pragma endregion
#pragma region ampere minute(electric charge)
#pragma endregion
#pragma region ampere hour(electric charge)
#pragma endregion
#pragma region electron/elementary charge(electric charge)
implement_unit(si, si, electron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::one,prefix::elementary_charge_t>));
#pragma endregion
#pragma region volt(electric potential)
implement_unit(si, si, volt, dim::electric_potential_t, prefix::one);
#pragma endregion
#pragma region farad(capacitance)
implement_unit(si, si, farad, dim::capacitance_t, prefix::one);
#pragma endregion
#pragma region ohm(electric resistance)
implement_unit(si, si, ohm, dim::electric_resistance_t, prefix::one);
#pragma endregion
#pragma region siemens(electric conductance)
implement_unit(si, si, siemens, dim::electric_conductance_t, prefix::one);
#pragma endregion
#pragma region weber(magnetic flux)
implement_unit(si, si, weber, dim::magnetic_flux_t, prefix::one);
#pragma endregion
#pragma region tesla(magnetic flux density)
implement_unit(si, si, tesla, dim::magnetic_flux_density_t, prefix::one);
#pragma endregion
#pragma region henry(inductance)
implement_unit(si, si, henry, dim::inductance_t, prefix::one);
#pragma endregion
#pragma region lumen(luminous flux)
implement_unit(si, si, lumen, dim::luminous_flux_t, prefix::one);
#pragma endregion
#pragma region lux(illuminance)
implement_unit(si, si, lux, dim::illuminance_t, prefix::one);
#pragma endregion
#pragma region watt per steradian(luminosity)
#pragma endregion
#pragma region becquerel(activity referred to a radionuclide)
implement_unit(si, si, becquerel, dim::activity_of_radionuclide_t, prefix::one);
#pragma endregion
#pragma region gray(specific energy)
implement_unit(si, si, gray, dim::absorbed_dose_t, prefix::one);
#pragma endregion
#pragma region sievert(dose equivalent)
implement_unit(si, si, sievert, dim::dose_equivalent_t, prefix::one);
#pragma endregion
#pragma region katal(catalytic activity)
implement_unit(si, si, katal, dim::catalytic_activity_t, prefix::one);
#pragma endregion
#pragma region pascal second(dynamic viscosity)
#pragma endregion
#pragma region pascal minute(dynamic viscosity)
#pragma endregion
#pragma region pascal hour(dynamic viscosity)
#pragma endregion
#pragma region joule per radian(torque)
#pragma endregion
#pragma region joule per degree, ...(torque)
#pragma endregion
#pragma region radian per second(angular velocity)
#pragma endregion
#pragma region radian per minute(angular velocity)
#pragma endregion
#pragma region radian per hour(angular velocity)
#pragma endregion
#pragma region radian per square second(angular acceleration)
#pragma endregion
#pragma region radian per square minute(angular acceleration)
#pragma endregion
#pragma region radian per hour(angular acceleration)
#pragma endregion
#pragma region watt per square metre(heat flux density)
#pragma endregion
#pragma region watt per square metre hertz(spectral heat flux density)
#pragma endregion
#pragma region jansky(spectral heat flux density)
//TODO: Check
implement_unit(si, si, jansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::one>));
#pragma endregion
#pragma region joule per kelvin(heat capacity)
#pragma endregion
#pragma region joule per kilogram kelvin(specific heat capacity)
#pragma endregion
#pragma region joule per kilogram(specific energy)
#pragma endregion
#pragma region watt per metre kelvin(thermal conductivity)
#pragma endregion
#pragma region joule per cubic metre(energy density)
#pragma endregion
#pragma region volt per metre(electric field strength)
#pragma endregion
#pragma region coulomb per cubic metre(electric charge density)
#pragma endregion
#pragma region coulomb per square metre(electric charge density)
#pragma endregion
#pragma region farad per metre(permittivity)
#pragma endregion
#pragma region henry per metre(permeability)
#pragma endregion
#pragma region joule per mole(molar energy)
#pragma endregion
#pragma region joule per mole kelvin(molar heat capacity)
#pragma endregion
#pragma region coulomb per kilogram(exposure)
#pragma endregion
#pragma region gray per second(absorbed dose rate)
#pragma endregion
#pragma region gray per minute(absorbed dose rate)
#pragma endregion
#pragma region gray per hour(absorbed dose rate)
#pragma endregion
#pragma region watt per square metre steradian(radiance)
#pragma endregion
#pragma region katal per cubic metre(catalytic activity concentration)
#pragma endregion
#pragma region joule second(action)
#pragma endregion
#pragma region joule minute(action)
#pragma endregion
#pragma region joule hour(action)
#pragma endregion
#pragma region square metre per second(kinematic viscosity)
#pragma endregion
#pragma region kilogram per metre(line density)
#pragma endregion
#pragma region metre second(absement)
#pragma endregion
#pragma region metre minute(absement)
#pragma endregion
#pragma region metre hour(absement)
#pragma endregion
#pragma region siemens per metre(electric conductivity)
#pragma endregion
#pragma region ohm metre(electric resitivity)
#pragma endregion
#pragma region newton second(momentum)
#pragma endregion
#pragma region newton minute(momentum)
#pragma endregion
#pragma region newton hour(momentum)
#pragma endregion
#pragma region newton metre second per radian(angular momentum)
#pragma endregion
#pragma region newton metre minute per radian(angular momentum)
#pragma endregion
#pragma region newton metre hour per radian(angular momentum)
#pragma endregion
#pragma region square metre kilogram per steradian(moment of inertia)
#pragma endregion
#pragma endregion
#pragma region special units for the constants
#pragma region joule per tesla(bohr magneton)
#pragma endregion
#pragma region one per mole(avogadro constant)
#pragma endregion
#pragma region coulomb per mole(faraday constant)
#pragma endregion
#pragma region hertz per volt(josephson constant)
#pragma endregion
#pragma region newton per square metre kilogram(gravitational constant)
#pragma endregion
#pragma region watt per square metre quartic kelvin steradian(stefan - boltzmann constant)
#pragma endregion
#pragma endregion
#pragma region constants
namespace constant
{
using namespace benri::si::base;
#pragma region physical constants
create_constant(speed_of_light, prefix::speed_of_light_v, typename decltype(metre / second)::unit_type);
create_constant(magnetic_constant, prefix::magnetic_constant_v, typename decltype(henry / metre)::unit_type);
create_constant(electric_constant, prefix::electric_constant_v, typename decltype(farad / metre)::unit_type);
create_constant(gravitational_constant, prefix::gravitational_constant_v, typename decltype(newton * metre * metre / (kilogram * kilogram))::unit_type);
create_constant(planck_constant, prefix::planck_constant_v, typename decltype(joule * second)::unit_type);
create_constant(reduced_planck_constant, prefix::reduced_planck_constant_v, typename decltype(joule * second)::unit_type);
create_constant(elementary_charge, prefix::elementary_charge_v, coulomb_t);
create_constant(fine_structure_constant, prefix::fine_structure_constant_v, one_t);
create_constant(inverse_fine_structure_constant, prefix::inverse_fine_structure_constant_v, one_t);
create_constant(electron_mass, prefix::electron_mass_v, kilogram_t);
create_constant(proton_mass, prefix::proton_mass_v, kilogram_t);
create_constant(muon_mass, prefix::muon_mass_v, kilogram_t);
create_constant(tau_mass, prefix::tau_mass_v, kilogram_t);
create_constant(neutron_mass, prefix::neutron_mass_v, kilogram_t);
create_constant(deuteron_mass, prefix::deuteron_mass_v, kilogram_t);
create_constant(triton_mass, prefix::triton_mass_v, kilogram_t);
create_constant(helion_mass, prefix::helion_mass_v, kilogram_t);
create_constant(alpha_particle_mass, prefix::alpha_particle_mass_v, kilogram_t);
create_constant(rydberg_constant, prefix::rydberg_constant_v, typename decltype(one / metre)::unit_type);
create_constant(bohr_radius, prefix::bohr_radius_v, metre_t);
create_constant(bohr_magneton, prefix::bohr_magneton_v, typename decltype(joule / tesla)::unit_type);
create_constant(avogadro_constant, prefix::avogadro_constant_v, typename decltype(one / mole)::unit_type);
create_constant(faraday_constant, prefix::faraday_constant_v, typename decltype(coulomb / mole)::unit_type);
create_constant(molar_gas_constant, prefix::molar_gas_constant_v, typename decltype(joule / (mole * kelvin))::unit_type);
create_constant(boltzmann_constant, prefix::boltzmann_constant_v, typename decltype(joule / kelvin)::unit_type);
create_constant(stefan_boltzmann_constant, prefix::stefan_boltzmann_constant_v, typename decltype(watt / (metre*metre*kelvin*kelvin*kelvin*kelvin*steradian))::unit_type);
create_constant(magnetic_flux_quantum, prefix::magnetic_flux_quantum_v, weber_t);
create_constant(josephson_constant, prefix::josephson_constant_v, typename decltype(hertz / volt)::unit_type);
create_constant(von_klitzing_constant, prefix::von_klitzing_constant_v, ohm_t);
create_constant(atomic_mass_unit, prefix::atomic_mass_unit_v, kilogram_t);
create_constant(hartree_energy, prefix::hartree_energy_v, joule_t);
create_constant(conductance_quantum, prefix::conductance_quantum_v, siemens_t);
create_constant(inverse_conductance_quantum, prefix::inverse_conductance_quantum_v, ohm_t);
create_constant(vacuum_impedance, prefix::vacuum_impedance_v, ohm_t);
create_constant(nuclear_magneton, prefix::nuclear_magneton_v, typename decltype(joule / tesla)::unit_type);
#pragma endregion
} // namespace constant
#pragma endregion
#pragma region symbols
namespace symbol
{
#pragma region physical constants
create_symbol(si, speed_of_light, dim::velocity_t, prefix::speed_of_light_t);
create_symbol(si, magnetic_constant, dim::permeability_t, prefix::magnetic_constant_t);
create_symbol(si, electric_constant, dim::permittivity_t, prefix::electric_constant_t);
create_symbol(si, gravitational_constant, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::gravitational_constant_t);
create_symbol(si, planck_constant, dim::action_t, prefix::planck_constant_t);
create_symbol(si, reduced_planck_constant, dim::action_t, prefix::reduced_planck_constant_t);
create_symbol(si, elementary_charge, dim::electric_charge_t, prefix::elementary_charge_t);
create_symbol(si, fine_structure_constant, dim::dimensionless_t, prefix::fine_structure_constant_t);
create_symbol(si, inverse_fine_structure_constant, dim::dimensionless_t, prefix::inverse_fine_structure_constant_t);
create_symbol(si, electron_mass, dim::mass_t, prefix::electron_mass_t);
create_symbol(si, proton_mass, dim::mass_t, prefix::proton_mass_t);
create_symbol(si, muon_mass, dim::mass_t, prefix::muon_mass_t);
create_symbol(si, tau_mass, dim::mass_t, prefix::tau_mass_t);
create_symbol(si, neutron_mass, dim::mass_t, prefix::neutron_mass_t);
create_symbol(si, deuteron_mass, dim::mass_t, prefix::deuteron_mass_t);
create_symbol(si, triton_mass, dim::mass_t, prefix::triton_mass_t);
create_symbol(si, helion_mass, dim::mass_t, prefix::helion_mass_t);
create_symbol(si, alpha_particle_mass, dim::mass_t, prefix::alpha_particle_mass_t);
create_symbol(si, rydberg_constant, dim::wavenumber_t, prefix::rydberg_constant_t);
create_symbol(si, bohr_radius, dim::length_t, prefix::bohr_radius_t);
create_symbol(si, bohr_magneton, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::bohr_magneton_t);
create_symbol(si, avogadro_constant, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), prefix::avogadro_constant_t);
create_symbol(si, faraday_constant, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::faraday_constant_t);
create_symbol(si, molar_gas_constant, dim::molar_heat_capacity_t, prefix::molar_gas_constant_t);
create_symbol(si, boltzmann_constant, dim::heat_capacity_t, prefix::boltzmann_constant_t);
create_symbol(si, stefan_boltzmann_constant, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::stefan_boltzmann_constant_t);
create_symbol(si, magnetic_flux_quantum, dim::magnetic_flux_t, prefix::magnetic_flux_quantum_t);
create_symbol(si, josephson_constant, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::josephson_constant_t);
create_symbol(si, von_klitzing_constant, dim::electric_resistance_t, prefix::von_klitzing_constant_t);
create_symbol(si, atomic_mass_unit, dim::mass_t, prefix::atomic_mass_unit_t);
create_symbol(si, hartree_energy, dim::energy_t, prefix::hartree_energy_t);
create_symbol(si, conductance_quantum, dim::electric_conductance_t, prefix::conductance_quantum_t);
create_symbol(si, inverse_conductance_quantum, dim::electric_resistance_t, prefix::inverse_conductance_quantum_t);
create_symbol(si, vacuum_impedance, dim::electric_resistance_t, prefix::vacuum_impedance_t);
create_symbol(si, nuclear_magneton, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::nuclear_magneton_t);
#pragma endregion
} // namespace symbol
#pragma endregion
} // namespace si
} // namespace benri