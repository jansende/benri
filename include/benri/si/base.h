#pragma once
#include <benri/quantity.h>
#include <benri/quantity_point.h>
#include <benri/impl/benri/dimensions.h>
#include <benri/impl/benri/macros.h>
#include <benri/si/prefixes.h>

namespace benri
{
namespace si
{
#pragma region length
implement_unit(metre, dim::length_t, prefix::one_t);
#pragma endregion
#pragma region mass
implement_unit(gram, dim::mass_t, prefix::milli_t);
implement_unit(kilogram, dim::mass_t, fix(multiply_lists<prefix::kilo_t, prefix::milli_t>));
implement_unit(tonne, dim::mass_t, fix(multiply_lists<prefix::mega_t, prefix::milli_t>));
#pragma endregion
#pragma region time
implement_unit(second, dim::time_t, prefix::one_t);
#pragma endregion
#pragma region electric current
implement_unit(ampere, dim::electric_current_t, prefix::one_t);
#pragma endregion
#pragma region thermodynamic temperature
implement_unit(kelvin, dim::thermodynamic_temperature_t, prefix::one_t);
link_unit_point(degree_kelvin, kelvin);
#pragma endregion
#pragma region amount of substance
implement_unit(mole, dim::amount_of_substance_t, prefix::one_t);
#pragma endregion
#pragma region luminous intensity
implement_unit(candela, dim::luminous_intensity_t, prefix::one_t);
#pragma endregion
#pragma region plane angle
implement_unit(radian, dim::plane_angle_t, prefix::one_t);
implement_unit(degree, dim::plane_angle_t, fix(multiply_lists<prefix::pi_t, make_fraction_list<1, 180>>));
#pragma endregion
#pragma region solid angle
implement_unit(steradian, dim::solid_angle_t, prefix::one_t);
#pragma endregion
#pragma region number of radioactive events
implement_unit(count, dim::number_of_radioactive_events_t, prefix::one_t);
#pragma endregion
#pragma region radiation weighting factor
implement_unit(sievert_per_gray, dim::radiation_weighting_factor_t, prefix::one_t);
#pragma endregion
#pragma region dimensionless data
implement_unit(percent, dim::dimensionless_t, prefix::centi_t);
implement_unit(permille, dim::dimensionless_t, prefix::milli_t);
implement_unit(parts_per_million, dim::dimensionless_t, prefix::micro_t);

implement_unit(yocto, dim::dimensionless_t, prefix::yocto_t);
implement_unit(zepto, dim::dimensionless_t, prefix::zepto_t);
implement_unit(atto, dim::dimensionless_t, prefix::atto_t);
implement_unit(femto, dim::dimensionless_t, prefix::femto_t);
implement_unit(pico, dim::dimensionless_t, prefix::pico_t);
implement_unit(nano, dim::dimensionless_t, prefix::nano_t);
implement_unit(micro, dim::dimensionless_t, prefix::micro_t);
implement_unit(milli, dim::dimensionless_t, prefix::milli_t);
implement_unit(centi, dim::dimensionless_t, prefix::centi_t);
implement_unit(deci, dim::dimensionless_t, prefix::deci_t);
implement_unit(one, dim::dimensionless_t, prefix::one_t);
implement_unit(deca, dim::dimensionless_t, prefix::deca_t);
implement_unit(hecto, dim::dimensionless_t, prefix::hecto_t);
implement_unit(kilo, dim::dimensionless_t, prefix::kilo_t);
implement_unit(mega, dim::dimensionless_t, prefix::mega_t);
implement_unit(giga, dim::dimensionless_t, prefix::giga_t);
implement_unit(tera, dim::dimensionless_t, prefix::tera_t);
implement_unit(peta, dim::dimensionless_t, prefix::peta_t);
implement_unit(exa, dim::dimensionless_t, prefix::exa_t);
implement_unit(zetta, dim::dimensionless_t, prefix::zetta_t);
implement_unit(yotta, dim::dimensionless_t, prefix::yotta_t);
#pragma endregion
#pragma region constants
namespace constant
{
#pragma region mathematical constants
create_constant(quarter_pi, prefix::quarter_pi_t, one_t);
create_constant(half_pi, prefix::half_pi_t, one_t);
create_constant(pi, prefix::pi_t, one_t);
create_constant(two_pi, prefix::two_pi_t, one_t);
create_constant(e, prefix::e_t, one_t);
create_constant(phi, prefix::phi_t, one_t);
create_constant(gamma, prefix::gamma_t, one_t);
create_constant(root_two, prefix::root_two_t, one_t);
#pragma endregion
#pragma region physical constants
create_constant(speed_of_light, prefix::speed_of_light_t, typename decltype(metre / second)::unit_type);
create_constant(magnetic_constant, prefix::magnetic_constant_t, typename decltype(metre * kilogram / square(second) / square(ampere))::unit_type);
create_constant(electric_constant, prefix::electric_constant_t, typename decltype(one / cubic(metre) / kilogram * quartic(second) * square(ampere))::unit_type);
create_constant(gravitational_constant, prefix::gravitational_constant_t, typename decltype(cubic(metre) / kilogram / square(second))::unit_type);
create_constant(planck_constant, prefix::planck_constant_t, typename decltype(square(metre) * kilogram / second)::unit_type);
create_constant(reduced_planck_constant, prefix::reduced_planck_constant_t, typename decltype(square(metre) * kilogram / second)::unit_type);
create_constant(elementary_charge, prefix::elementary_charge_t, typename decltype(second * ampere)::unit_type);
create_constant(fine_structure_constant, prefix::fine_structure_constant_t, one_t);
create_constant(inverse_fine_structure_constant, prefix::inverse_fine_structure_constant_t, one_t);
create_constant(electron_mass, prefix::electron_mass_t, kilogram_t);
create_constant(proton_mass, prefix::proton_mass_t, kilogram_t);
create_constant(muon_mass, prefix::muon_mass_t, kilogram_t);
create_constant(tau_mass, prefix::tau_mass_t, kilogram_t);
create_constant(neutron_mass, prefix::neutron_mass_t, kilogram_t);
create_constant(deuteron_mass, prefix::deuteron_mass_t, kilogram_t);
create_constant(triton_mass, prefix::triton_mass_t, kilogram_t);
create_constant(helion_mass, prefix::helion_mass_t, kilogram_t);
create_constant(alpha_particle_mass, prefix::alpha_particle_mass_t, kilogram_t);
create_constant(rydberg_constant, prefix::rydberg_constant_t, typename decltype(one / metre)::unit_type);
create_constant(bohr_radius, prefix::bohr_radius_t, metre_t);
create_constant(bohr_magneton, prefix::bohr_magneton_t, typename decltype(square(metre) * ampere)::unit_type);
create_constant(avogadro_constant, prefix::avogadro_constant_t, typename decltype(one / mole)::unit_type);
create_constant(faraday_constant, prefix::faraday_constant_t, typename decltype(second * ampere / mole)::unit_type);
create_constant(molar_gas_constant, prefix::molar_gas_constant_t, typename decltype(square(metre) * kilogram / square(second) / mole / kelvin)::unit_type);
create_constant(boltzmann_constant, prefix::boltzmann_constant_t, typename decltype(square(metre) * kilogram / square(second) / kelvin)::unit_type);
create_constant(stefan_boltzmann_constant, prefix::stefan_boltzmann_constant_t, typename decltype(kilogram / cubic(second) / quartic(kelvin) / steradian)::unit_type);
create_constant(magnetic_flux_quantum, prefix::magnetic_flux_quantum_t, typename decltype(square(metre) * kilogram / square(second) / ampere)::unit_type);
create_constant(josephson_constant, prefix::josephson_constant_t, typename decltype(one / square(metre) / kilogram * square(second) * ampere)::unit_type);
create_constant(von_klitzing_constant, prefix::von_klitzing_constant_t, typename decltype(square(metre) * kilogram / cubic(second) / square(ampere))::unit_type);
create_constant(atomic_mass_unit, prefix::atomic_mass_unit_t, kilogram_t);
create_constant(hartree_energy, prefix::hartree_energy_t, typename decltype(square(metre) * kilogram / square(second))::unit_type);
create_constant(conductance_quantum, prefix::conductance_quantum_t, typename decltype(one / square(metre) / kilogram * cubic(second) * square(ampere))::unit_type);
create_constant(inverse_conductance_quantum, prefix::inverse_conductance_quantum_t, typename decltype(square(metre) * kilogram / cubic(second) / square(ampere))::unit_type);
create_constant(vacuum_impedance, prefix::vacuum_impedance_t, typename decltype(square(metre) * kilogram / cubic(second) / square(ampere))::unit_type);
create_constant(nuclear_magneton, prefix::nuclear_magneton_t, typename decltype(square(metre) * ampere)::unit_type);
#pragma endregion
} // namespace constant
#pragma endregion
#pragma region symbols
namespace symbol
{
#pragma region mathematical constants
create_symbol(quarter_pi, dim::dimensionless_t, prefix::quarter_pi_t);
create_symbol(half_pi, dim::dimensionless_t, prefix::half_pi_t);
create_symbol(pi, dim::dimensionless_t, prefix::pi_t);
create_symbol(two_pi, dim::dimensionless_t, prefix::two_pi_t);
create_symbol(e, dim::dimensionless_t, prefix::e_t);
create_symbol(phi, dim::dimensionless_t, prefix::phi_t);
create_symbol(gamma, dim::dimensionless_t, prefix::gamma_t);
create_symbol(root_two, dim::dimensionless_t, prefix::root_two_symbol_t);
#pragma endregion
#pragma region physical constants
create_symbol(speed_of_light, dim::velocity_t, prefix::speed_of_light_t);
create_symbol(magnetic_constant, dim::permeability_t, prefix::magnetic_constant_t);
create_symbol(electric_constant, dim::permittivity_t, prefix::electric_constant_t);
create_symbol(gravitational_constant, fix(multiply_lists<dim::force_t, divide_lists<dim::area_t, pow_list<dim::mass_t, std::ratio<2>>>>), prefix::gravitational_constant_t);
create_symbol(planck_constant, dim::action_t, prefix::planck_constant_t);
create_symbol(reduced_planck_constant, dim::action_t, prefix::reduced_planck_constant_t);
create_symbol(elementary_charge, dim::electric_charge_t, prefix::elementary_charge_t);
create_symbol(fine_structure_constant, dim::dimensionless_t, prefix::fine_structure_constant_t);
create_symbol(inverse_fine_structure_constant, dim::dimensionless_t, prefix::inverse_fine_structure_constant_t);
create_symbol(electron_mass, dim::mass_t, prefix::electron_mass_t);
create_symbol(proton_mass, dim::mass_t, prefix::proton_mass_t);
create_symbol(muon_mass, dim::mass_t, prefix::muon_mass_t);
create_symbol(tau_mass, dim::mass_t, prefix::tau_mass_t);
create_symbol(neutron_mass, dim::mass_t, prefix::neutron_mass_t);
create_symbol(deuteron_mass, dim::mass_t, prefix::deuteron_mass_t);
create_symbol(triton_mass, dim::mass_t, prefix::triton_mass_t);
create_symbol(helion_mass, dim::mass_t, prefix::helion_mass_t);
create_symbol(alpha_particle_mass, dim::mass_t, prefix::alpha_particle_mass_t);
create_symbol(rydberg_constant, dim::wavenumber_t, prefix::rydberg_constant_t);
create_symbol(bohr_radius, dim::length_t, prefix::bohr_radius_t);
create_symbol(bohr_magneton, fix(divide_lists<dim::energy_t, dim::magnetic_flux_density_t>), prefix::bohr_magneton_t);
create_symbol(avogadro_constant, fix(divide_lists<dim::dimensionless_t, dim::amount_of_substance_t>), prefix::avogadro_constant_t);
create_symbol(faraday_constant, fix(divide_lists<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::faraday_constant_t);
create_symbol(molar_gas_constant, dim::molar_heat_capacity_t, prefix::molar_gas_constant_t);
create_symbol(boltzmann_constant, dim::heat_capacity_t, prefix::boltzmann_constant_t);
create_symbol(stefan_boltzmann_constant, fix(divide_lists<dim::power_t, multiply_lists<dim::area_t, pow_list<dim::thermodynamic_temperature_t, std::ratio<4>>, dim::solid_angle_t>>), prefix::stefan_boltzmann_constant_t);
create_symbol(magnetic_flux_quantum, dim::magnetic_flux_t, prefix::magnetic_flux_quantum_t);
create_symbol(josephson_constant, fix(divide_lists<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::josephson_constant_t);
create_symbol(von_klitzing_constant, dim::electric_resistance_t, prefix::von_klitzing_constant_t);
create_symbol(atomic_mass_unit, dim::mass_t, prefix::atomic_mass_unit_t);
create_symbol(hartree_energy, dim::energy_t, prefix::hartree_energy_t);
create_symbol(conductance_quantum, dim::electric_conductance_t, prefix::conductance_quantum_t);
create_symbol(inverse_conductance_quantum, dim::electric_resistance_t, prefix::inverse_conductance_quantum_t);
create_symbol(vacuum_impedance, dim::electric_resistance_t, prefix::vacuum_impedance_t);
create_symbol(nuclear_magneton, fix(divide_lists<dim::energy_t, dim::magnetic_flux_density_t>), prefix::nuclear_magneton_t);
#pragma endregion
} // namespace symbol
#pragma endregion
} // namespace si
} // namespace benri