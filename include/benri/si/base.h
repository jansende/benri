#pragma once
#include <benri/casts.h>
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
constexpr auto              quarter_pi = make_constant<one_t, prefix::quarter_pi_t>;
constexpr auto              half_pi    = make_constant<one_t, prefix::half_pi_t>;
constexpr auto              pi         = make_constant<one_t, prefix::pi_t>;
constexpr auto              two_pi     = make_constant<one_t, prefix::two_pi_t>;
constexpr auto              e          = make_constant<one_t, prefix::e_t>;
constexpr auto              phi        = make_constant<one_t, prefix::phi_t>;
constexpr auto              gamma      = make_constant<one_t, prefix::gamma_t>;
constexpr auto              root_two   = make_constant<one_t, prefix::root_two_t>;
#pragma endregion
#pragma region physical constants
constexpr auto          speed_of_light =
    make_constant<typename decltype(metre / second)::unit_type, prefix::speed_of_light_t>;
constexpr auto magnetic_constant =
    make_constant<typename decltype(metre * kilogram / square(second)
                                    / square(ampere))::unit_type,
                  prefix::magnetic_constant_t>;
constexpr auto electric_constant =
    make_constant<typename decltype(one / cubic(metre) / kilogram * quartic(second)
                                    * square(ampere))::unit_type,
                  prefix::electric_constant_t>;
constexpr auto gravitational_constant =
    make_constant<typename decltype(cubic(metre) / kilogram / square(second))::unit_type,
                  prefix::gravitational_constant_t>;
constexpr auto planck_constant =
    make_constant<typename decltype(square(metre) * kilogram / second)::unit_type,
                  prefix::planck_constant_t>;
constexpr auto reduced_planck_constant =
    make_constant<typename decltype(square(metre) * kilogram / second)::unit_type,
                  prefix::reduced_planck_constant_t>;
constexpr auto elementary_charge =
    make_constant<typename decltype(second * ampere)::unit_type,
                  prefix::elementary_charge_t>;
constexpr auto fine_structure_constant =
    make_constant<one_t, prefix::fine_structure_constant_t>;
constexpr auto inverse_fine_structure_constant =
    make_constant<one_t, prefix::inverse_fine_structure_constant_t>;
constexpr auto electron_mass = make_constant<kilogram_t, prefix::electron_mass_t>;
constexpr auto proton_mass   = make_constant<kilogram_t, prefix::proton_mass_t>;
constexpr auto muon_mass     = make_constant<kilogram_t, prefix::muon_mass_t>;
constexpr auto tau_mass      = make_constant<kilogram_t, prefix::tau_mass_t>;
constexpr auto neutron_mass  = make_constant<kilogram_t, prefix::neutron_mass_t>;
constexpr auto deuteron_mass = make_constant<kilogram_t, prefix::deuteron_mass_t>;
constexpr auto triton_mass   = make_constant<kilogram_t, prefix::triton_mass_t>;
constexpr auto helion_mass   = make_constant<kilogram_t, prefix::helion_mass_t>;
constexpr auto alpha_particle_mass =
    make_constant<kilogram_t, prefix::alpha_particle_mass_t>;
constexpr auto rydberg_constant =
    make_constant<typename decltype(one / metre)::unit_type, prefix::rydberg_constant_t>;
constexpr auto bohr_radius = make_constant<metre_t, prefix::bohr_radius_t>;
constexpr auto bohr_magneton =
    make_constant<typename decltype(square(metre) * ampere)::unit_type,
                  prefix::bohr_magneton_t>;
constexpr auto avogadro_constant =
    make_constant<typename decltype(one / mole)::unit_type, prefix::avogadro_constant_t>;
constexpr auto faraday_constant =
    make_constant<typename decltype(second * ampere / mole)::unit_type,
                  prefix::faraday_constant_t>;
constexpr auto molar_gas_constant =
    make_constant<typename decltype(square(metre) * kilogram / square(second) / mole
                                    / kelvin)::unit_type,
                  prefix::molar_gas_constant_t>;
constexpr auto boltzmann_constant =
    make_constant<typename decltype(square(metre) * kilogram / square(second)
                                    / kelvin)::unit_type,
                  prefix::boltzmann_constant_t>;
constexpr auto stefan_boltzmann_constant =
    make_constant<typename decltype(kilogram / cubic(second) / quartic(kelvin)
                                    / steradian)::unit_type,
                  prefix::stefan_boltzmann_constant_t>;
constexpr auto magnetic_flux_quantum =
    make_constant<typename decltype(square(metre) * kilogram / square(second)
                                    / ampere)::unit_type,
                  prefix::magnetic_flux_quantum_t>;
constexpr auto josephson_constant =
    make_constant<typename decltype(one / square(metre) / kilogram * square(second)
                                    * ampere)::unit_type,
                  prefix::josephson_constant_t>;
constexpr auto von_klitzing_constant =
    make_constant<typename decltype(square(metre) * kilogram / cubic(second)
                                    / square(ampere))::unit_type,
                  prefix::von_klitzing_constant_t>;
constexpr auto atomic_mass_unit = make_constant<kilogram_t, prefix::atomic_mass_unit_t>;
constexpr auto hartree_energy =
    make_constant<typename decltype(square(metre) * kilogram / square(second))::unit_type,
                  prefix::hartree_energy_t>;
constexpr auto conductance_quantum =
    make_constant<typename decltype(one / square(metre) / kilogram * cubic(second)
                                    * square(ampere))::unit_type,
                  prefix::conductance_quantum_t>;
constexpr auto inverse_conductance_quantum =
    make_constant<typename decltype(square(metre) * kilogram / cubic(second)
                                    / square(ampere))::unit_type,
                  prefix::inverse_conductance_quantum_t>;
constexpr auto vacuum_impedance =
    make_constant<typename decltype(square(metre) * kilogram / cubic(second)
                                    / square(ampere))::unit_type,
                  prefix::vacuum_impedance_t>;
constexpr auto nuclear_magneton =
    make_constant<typename decltype(square(metre) * ampere)::unit_type,
                  prefix::nuclear_magneton_t>;
constexpr auto absolute_zero =
    make_constant_point<typename decltype(kelvin)::unit_type, prefix::zero_t>;
#pragma endregion
} // namespace constant
#pragma endregion
#pragma region symbols
namespace symbol
{
#pragma region mathematical constants
constexpr auto quarter_pi = make_symbol<dimension::dimensionless_t, prefix::quarter_pi_t>;
constexpr auto half_pi    = make_symbol<dimension::dimensionless_t, prefix::half_pi_t>;
constexpr auto pi         = make_symbol<dimension::dimensionless_t, prefix::pi_t>;
constexpr auto two_pi     = make_symbol<dimension::dimensionless_t, prefix::two_pi_t>;
constexpr auto e          = make_symbol<dimension::dimensionless_t, prefix::e_t>;
constexpr auto phi        = make_symbol<dimension::dimensionless_t, prefix::phi_t>;
constexpr auto gamma      = make_symbol<dimension::dimensionless_t, prefix::gamma_t>;
constexpr auto root_two =
    make_symbol<dimension::dimensionless_t, prefix::root_two_symbol_t>;
#pragma endregion
#pragma region physical constants
constexpr auto          speed_of_light =
    make_symbol<dimension::velocity_t, prefix::speed_of_light_t>;
constexpr auto magnetic_constant =
    make_symbol<dimension::permeability_t, prefix::magnetic_constant_t>;
constexpr auto electric_constant =
    make_symbol<dimension::permittivity_t, prefix::electric_constant_t>;
constexpr auto gravitational_constant =
    make_symbol<type::multiply_lists<
                    dimension::force_t,
                    type::divide_lists<dimension::area_t,
                                       type::pow_list<dimension::mass_t, std::ratio<2>>>>,
                prefix::gravitational_constant_t>;
constexpr auto planck_constant =
    make_symbol<dimension::action_t, prefix::planck_constant_t>;
constexpr auto reduced_planck_constant =
    make_symbol<dimension::action_t, prefix::reduced_planck_constant_t>;
constexpr auto elementary_charge =
    make_symbol<dimension::electric_charge_t, prefix::elementary_charge_t>;
constexpr auto fine_structure_constant =
    make_symbol<dimension::dimensionless_t, prefix::fine_structure_constant_symbol_t>;
constexpr auto inverse_fine_structure_constant =
    make_symbol<dimension::dimensionless_t, prefix::inverse_fine_structure_constant_t>;
constexpr auto electron_mass = make_symbol<dimension::mass_t, prefix::electron_mass_t>;
constexpr auto proton_mass   = make_symbol<dimension::mass_t, prefix::proton_mass_t>;
constexpr auto muon_mass     = make_symbol<dimension::mass_t, prefix::muon_mass_t>;
constexpr auto tau_mass      = make_symbol<dimension::mass_t, prefix::tau_mass_t>;
constexpr auto neutron_mass  = make_symbol<dimension::mass_t, prefix::neutron_mass_t>;
constexpr auto deuteron_mass = make_symbol<dimension::mass_t, prefix::deuteron_mass_t>;
constexpr auto triton_mass   = make_symbol<dimension::mass_t, prefix::triton_mass_t>;
constexpr auto helion_mass   = make_symbol<dimension::mass_t, prefix::helion_mass_t>;
constexpr auto alpha_particle_mass =
    make_symbol<dimension::mass_t, prefix::alpha_particle_mass_t>;
constexpr auto rydberg_constant =
    make_symbol<dimension::wavenumber_t, prefix::rydberg_constant_t>;
constexpr auto bohr_radius   = make_symbol<dimension::length_t, prefix::bohr_radius_t>;
constexpr auto bohr_magneton = make_symbol<
    type::divide_lists<dimension::energy_t, dimension::magnetic_flux_density_t>,
    prefix::bohr_magneton_t>;
constexpr auto avogadro_constant = make_symbol<
    type::divide_lists<dimension::dimensionless_t, dimension::amount_of_substance_t>,
    prefix::avogadro_constant_t>;
constexpr auto faraday_constant = make_symbol<
    type::divide_lists<dimension::electric_charge_t, dimension::amount_of_substance_t>,
    prefix::faraday_constant_t>;
constexpr auto molar_gas_constant =
    make_symbol<dimension::molar_heat_capacity_t, prefix::molar_gas_constant_t>;
constexpr auto boltzmann_constant =
    make_symbol<dimension::heat_capacity_t, prefix::boltzmann_constant_t>;
constexpr auto stefan_boltzmann_constant = make_symbol<
    type::divide_lists<
        dimension::power_t,
        type::multiply_lists<
            dimension::area_t,
            type::pow_list<dimension::thermodynamic_temperature_t, std::ratio<4>>,
            dimension::solid_angle_t>>,
    prefix::stefan_boltzmann_constant_t>;
constexpr auto magnetic_flux_quantum =
    make_symbol<dimension::magnetic_flux_t, prefix::magnetic_flux_quantum_t>;
constexpr auto josephson_constant = make_symbol<
    type::divide_lists<dimension::dimensionless_t, dimension::magnetic_flux_t>,
    prefix::josephson_constant_t>;
constexpr auto von_klitzing_constant =
    make_symbol<dimension::electric_resistance_t, prefix::von_klitzing_constant_t>;
constexpr auto atomic_mass_unit =
    make_symbol<dimension::mass_t, prefix::atomic_mass_unit_t>;
constexpr auto hartree_energy =
    make_symbol<dimension::energy_t, prefix::hartree_energy_t>;
constexpr auto conductance_quantum =
    make_symbol<dimension::electric_conductance_t, prefix::conductance_quantum_t>;
constexpr auto inverse_conductance_quantum =
    make_symbol<dimension::electric_resistance_t, prefix::inverse_conductance_quantum_t>;
constexpr auto vacuum_impedance =
    make_symbol<dimension::electric_resistance_t, prefix::vacuum_impedance_t>;
constexpr auto nuclear_magneton = make_symbol<
    type::divide_lists<dimension::energy_t, dimension::magnetic_flux_density_t>,
    prefix::nuclear_magneton_t>;
constexpr auto absolute_zero = make_symbol_point<dimension::thermodynamic_temperature_t,
                                                 prefix::one_t, prefix::zero_t>;
#pragma endregion
} // namespace symbol
#pragma endregion
} // namespace si
} // namespace benri