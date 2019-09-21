#pragma once
#include <benri/quantity.h>
#include <benri/quantity_point.h>
#include <benri/si/dimensions.h>
#include <benri/si/macros.h>
#include <benri/si/prefixes.h>

namespace benri
{
namespace si
{
#pragma region length
implement_unit(metre, dimension::length_t, prefix::one_t);
#pragma endregion
#pragma region mass
implement_unit(gram, dimension::mass_t, prefix::milli_t);
implement_unit(kilogram, dimension::mass_t,
               fix(type::multiply_lists<prefix::kilo_t, prefix::milli_t>));
implement_unit(tonne, dimension::mass_t,
               fix(type::multiply_lists<prefix::mega_t, prefix::milli_t>));
#pragma endregion
#pragma region time
implement_unit(second, dimension::time_t, prefix::one_t);
#pragma endregion
#pragma region electric current
implement_unit(ampere, dimension::electric_current_t, prefix::one_t);
#pragma endregion
#pragma region thermodynamic temperature
implement_unit(kelvin, dimension::thermodynamic_temperature_t, prefix::one_t);
link_unit_point(degree_kelvin, kelvin);
#pragma endregion
#pragma region amount of substance
implement_unit(mole, dimension::amount_of_substance_t, prefix::one_t);
#pragma endregion
#pragma region luminous intensity
implement_unit(candela, dimension::luminous_intensity_t, prefix::one_t);
#pragma endregion
#pragma region plane angle
implement_unit(radian, dimension::plane_angle_t, prefix::one_t);
implement_unit(degree, dimension::plane_angle_t,
               fix(type::multiply_lists<prefix::pi_t, type::make_prefix<1, 180>>));
#pragma endregion
#pragma region solid angle
implement_unit(steradian, dimension::solid_angle_t, prefix::one_t);
#pragma endregion
#pragma region number of radioactive events
implement_unit(count, dimension::number_of_radioactive_events_t, prefix::one_t);
#pragma endregion
#pragma region radiation weighting factor
implement_unit(sievert_per_gray, dimension::radiation_weighting_factor_t, prefix::one_t);
#pragma endregion
#pragma region dimensionless data
implement_unit(percent, dimension::dimensionless_t, prefix::centi_t);
implement_unit(permille, dimension::dimensionless_t, prefix::milli_t);
implement_unit(parts_per_million, dimension::dimensionless_t, prefix::micro_t);

implement_unit(yocto, dimension::dimensionless_t, prefix::yocto_t);
implement_unit(zepto, dimension::dimensionless_t, prefix::zepto_t);
implement_unit(atto, dimension::dimensionless_t, prefix::atto_t);
implement_unit(femto, dimension::dimensionless_t, prefix::femto_t);
implement_unit(pico, dimension::dimensionless_t, prefix::pico_t);
implement_unit(nano, dimension::dimensionless_t, prefix::nano_t);
implement_unit(micro, dimension::dimensionless_t, prefix::micro_t);
implement_unit(milli, dimension::dimensionless_t, prefix::milli_t);
implement_unit(centi, dimension::dimensionless_t, prefix::centi_t);
implement_unit(deci, dimension::dimensionless_t, prefix::deci_t);
implement_unit(one, dimension::dimensionless_t, prefix::one_t);
implement_unit(deca, dimension::dimensionless_t, prefix::deca_t);
implement_unit(hecto, dimension::dimensionless_t, prefix::hecto_t);
implement_unit(kilo, dimension::dimensionless_t, prefix::kilo_t);
implement_unit(mega, dimension::dimensionless_t, prefix::mega_t);
implement_unit(giga, dimension::dimensionless_t, prefix::giga_t);
implement_unit(tera, dimension::dimensionless_t, prefix::tera_t);
implement_unit(peta, dimension::dimensionless_t, prefix::peta_t);
implement_unit(exa, dimension::dimensionless_t, prefix::exa_t);
implement_unit(zetta, dimension::dimensionless_t, prefix::zetta_t);
implement_unit(yotta, dimension::dimensionless_t, prefix::yotta_t);
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
create_constant(speed_of_light, prefix::speed_of_light_t,
                typename decltype(metre / second)::unit_type);
create_constant(magnetic_constant, prefix::magnetic_constant_t,
                typename decltype(metre * kilogram / square(second)
                                  / square(ampere))::unit_type);
create_constant(electric_constant, prefix::electric_constant_t,
                typename decltype(one / cubic(metre) / kilogram * quartic(second)
                                  * square(ampere))::unit_type);
create_constant(gravitational_constant, prefix::gravitational_constant_t,
                typename decltype(cubic(metre) / kilogram / square(second))::unit_type);
create_constant(planck_constant, prefix::planck_constant_t,
                typename decltype(square(metre) * kilogram / second)::unit_type);
create_constant(reduced_planck_constant, prefix::reduced_planck_constant_t,
                typename decltype(square(metre) * kilogram / second)::unit_type);
create_constant(elementary_charge, prefix::elementary_charge_t,
                typename decltype(second * ampere)::unit_type);
create_constant(fine_structure_constant, prefix::fine_structure_constant_t, one_t);
create_constant(inverse_fine_structure_constant,
                prefix::inverse_fine_structure_constant_t, one_t);
create_constant(electron_mass, prefix::electron_mass_t, kilogram_t);
create_constant(proton_mass, prefix::proton_mass_t, kilogram_t);
create_constant(muon_mass, prefix::muon_mass_t, kilogram_t);
create_constant(tau_mass, prefix::tau_mass_t, kilogram_t);
create_constant(neutron_mass, prefix::neutron_mass_t, kilogram_t);
create_constant(deuteron_mass, prefix::deuteron_mass_t, kilogram_t);
create_constant(triton_mass, prefix::triton_mass_t, kilogram_t);
create_constant(helion_mass, prefix::helion_mass_t, kilogram_t);
create_constant(alpha_particle_mass, prefix::alpha_particle_mass_t, kilogram_t);
create_constant(rydberg_constant, prefix::rydberg_constant_t,
                typename decltype(one / metre)::unit_type);
create_constant(bohr_radius, prefix::bohr_radius_t, metre_t);
create_constant(bohr_magneton, prefix::bohr_magneton_t,
                typename decltype(square(metre) * ampere)::unit_type);
create_constant(avogadro_constant, prefix::avogadro_constant_t,
                typename decltype(one / mole)::unit_type);
create_constant(faraday_constant, prefix::faraday_constant_t,
                typename decltype(second * ampere / mole)::unit_type);
create_constant(molar_gas_constant, prefix::molar_gas_constant_t,
                typename decltype(square(metre) * kilogram / square(second) / mole
                                  / kelvin)::unit_type);
create_constant(boltzmann_constant, prefix::boltzmann_constant_t,
                typename decltype(square(metre) * kilogram / square(second)
                                  / kelvin)::unit_type);
create_constant(stefan_boltzmann_constant, prefix::stefan_boltzmann_constant_t,
                typename decltype(kilogram / cubic(second) / quartic(kelvin)
                                  / steradian)::unit_type);
create_constant(magnetic_flux_quantum, prefix::magnetic_flux_quantum_t,
                typename decltype(square(metre) * kilogram / square(second)
                                  / ampere)::unit_type);
create_constant(josephson_constant, prefix::josephson_constant_t,
                typename decltype(one / square(metre) / kilogram * square(second)
                                  * ampere)::unit_type);
create_constant(von_klitzing_constant, prefix::von_klitzing_constant_t,
                typename decltype(square(metre) * kilogram / cubic(second)
                                  / square(ampere))::unit_type);
create_constant(atomic_mass_unit, prefix::atomic_mass_unit_t, kilogram_t);
create_constant(hartree_energy, prefix::hartree_energy_t,
                typename decltype(square(metre) * kilogram / square(second))::unit_type);
create_constant(conductance_quantum, prefix::conductance_quantum_t,
                typename decltype(one / square(metre) / kilogram * cubic(second)
                                  * square(ampere))::unit_type);
create_constant(inverse_conductance_quantum, prefix::inverse_conductance_quantum_t,
                typename decltype(square(metre) * kilogram / cubic(second)
                                  / square(ampere))::unit_type);
create_constant(vacuum_impedance, prefix::vacuum_impedance_t,
                typename decltype(square(metre) * kilogram / cubic(second)
                                  / square(ampere))::unit_type);
create_constant(nuclear_magneton, prefix::nuclear_magneton_t,
                typename decltype(square(metre) * ampere)::unit_type);
#pragma endregion
} // namespace constant
#pragma endregion
#pragma region symbols
namespace symbol
{
#pragma region mathematical constants
create_symbol(quarter_pi, dimension::dimensionless_t, prefix::quarter_pi_t);
create_symbol(half_pi, dimension::dimensionless_t, prefix::half_pi_t);
create_symbol(pi, dimension::dimensionless_t, prefix::pi_t);
create_symbol(two_pi, dimension::dimensionless_t, prefix::two_pi_t);
create_symbol(e, dimension::dimensionless_t, prefix::e_t);
create_symbol(phi, dimension::dimensionless_t, prefix::phi_t);
create_symbol(gamma, dimension::dimensionless_t, prefix::gamma_t);
create_symbol(root_two, dimension::dimensionless_t, prefix::root_two_symbol_t);
#pragma endregion
#pragma region physical constants
create_symbol(speed_of_light, dimension::velocity_t, prefix::speed_of_light_t);
create_symbol(magnetic_constant, dimension::permeability_t, prefix::magnetic_constant_t);
create_symbol(electric_constant, dimension::permittivity_t, prefix::electric_constant_t);
create_symbol(gravitational_constant,
              fix(type::multiply_lists<
                  dimension::force_t,
                  type::divide_lists<dimension::area_t,
                                     type::pow_list<dimension::mass_t, std::ratio<2>>>>),
              prefix::gravitational_constant_t);
create_symbol(planck_constant, dimension::action_t, prefix::planck_constant_t);
create_symbol(reduced_planck_constant, dimension::action_t,
              prefix::reduced_planck_constant_t);
create_symbol(elementary_charge, dimension::electric_charge_t,
              prefix::elementary_charge_t);
create_symbol(fine_structure_constant, dimension::dimensionless_t,
              prefix::fine_structure_constant_symbol_t);
create_symbol(inverse_fine_structure_constant, dimension::dimensionless_t,
              prefix::inverse_fine_structure_constant_t);
create_symbol(electron_mass, dimension::mass_t, prefix::electron_mass_t);
create_symbol(proton_mass, dimension::mass_t, prefix::proton_mass_t);
create_symbol(muon_mass, dimension::mass_t, prefix::muon_mass_t);
create_symbol(tau_mass, dimension::mass_t, prefix::tau_mass_t);
create_symbol(neutron_mass, dimension::mass_t, prefix::neutron_mass_t);
create_symbol(deuteron_mass, dimension::mass_t, prefix::deuteron_mass_t);
create_symbol(triton_mass, dimension::mass_t, prefix::triton_mass_t);
create_symbol(helion_mass, dimension::mass_t, prefix::helion_mass_t);
create_symbol(alpha_particle_mass, dimension::mass_t, prefix::alpha_particle_mass_t);
create_symbol(rydberg_constant, dimension::wavenumber_t, prefix::rydberg_constant_t);
create_symbol(bohr_radius, dimension::length_t, prefix::bohr_radius_t);
create_symbol(
    bohr_magneton,
    fix(type::divide_lists<dimension::energy_t, dimension::magnetic_flux_density_t>),
    prefix::bohr_magneton_t);
create_symbol(
    avogadro_constant,
    fix(type::divide_lists<dimension::dimensionless_t, dimension::amount_of_substance_t>),
    prefix::avogadro_constant_t);
create_symbol(faraday_constant,
              fix(type::divide_lists<dimension::electric_charge_t,
                                     dimension::amount_of_substance_t>),
              prefix::faraday_constant_t);
create_symbol(molar_gas_constant, dimension::molar_heat_capacity_t,
              prefix::molar_gas_constant_t);
create_symbol(boltzmann_constant, dimension::heat_capacity_t,
              prefix::boltzmann_constant_t);
create_symbol(
    stefan_boltzmann_constant,
    fix(type::divide_lists<
        dimension::power_t,
        type::multiply_lists<
            dimension::area_t,
            type::pow_list<dimension::thermodynamic_temperature_t, std::ratio<4>>,
            dimension::solid_angle_t>>),
    prefix::stefan_boltzmann_constant_t);
create_symbol(magnetic_flux_quantum, dimension::magnetic_flux_t,
              prefix::magnetic_flux_quantum_t);
create_symbol(
    josephson_constant,
    fix(type::divide_lists<dimension::dimensionless_t, dimension::magnetic_flux_t>),
    prefix::josephson_constant_t);
create_symbol(von_klitzing_constant, dimension::electric_resistance_t,
              prefix::von_klitzing_constant_t);
create_symbol(atomic_mass_unit, dimension::mass_t, prefix::atomic_mass_unit_t);
create_symbol(hartree_energy, dimension::energy_t, prefix::hartree_energy_t);
create_symbol(conductance_quantum, dimension::electric_conductance_t,
              prefix::conductance_quantum_t);
create_symbol(inverse_conductance_quantum, dimension::electric_resistance_t,
              prefix::inverse_conductance_quantum_t);
create_symbol(vacuum_impedance, dimension::electric_resistance_t,
              prefix::vacuum_impedance_t);
create_symbol(
    nuclear_magneton,
    fix(type::divide_lists<dimension::energy_t, dimension::magnetic_flux_density_t>),
    prefix::nuclear_magneton_t);
#pragma endregion
} // namespace symbol
#pragma endregion
} // namespace si
} // namespace benri