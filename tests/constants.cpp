#include <gtest/gtest.h>
#include "helpers.h"

#include <benri/si/base.h>
#include <benri/si/astronomic.h>
using namespace benri::si;

TEST(constants, symbol_consistency)
{
#pragma region mathematical constants
    EXPECT_BENRI_EQ(decltype(constant::quarter_pi), constant::quarter_pi, benri::simple_cast<decltype(constant::quarter_pi)>(symbol::quarter_pi));
    EXPECT_BENRI_EQ(decltype(constant::half_pi), constant::half_pi, benri::simple_cast<decltype(constant::half_pi)>(symbol::half_pi));
    EXPECT_BENRI_EQ(decltype(constant::pi), constant::pi, benri::simple_cast<decltype(constant::pi)>(symbol::pi));
    EXPECT_BENRI_EQ(decltype(constant::two_pi), constant::two_pi, benri::simple_cast<decltype(constant::two_pi)>(symbol::two_pi));
    EXPECT_BENRI_EQ(decltype(constant::e), constant::e, benri::simple_cast<decltype(constant::e)>(symbol::e));
    EXPECT_BENRI_EQ(decltype(constant::phi), constant::phi, benri::simple_cast<decltype(constant::phi)>(symbol::phi));
    EXPECT_BENRI_EQ(decltype(constant::gamma), constant::gamma, benri::simple_cast<decltype(constant::gamma)>(symbol::gamma));
    EXPECT_BENRI_EQ(decltype(constant::root_two), constant::root_two, benri::unit_cast<decltype(constant::root_two)>(symbol::root_two));
#pragma endregion
#pragma region physical constants
    EXPECT_BENRI_EQ(decltype(constant::speed_of_light), constant::speed_of_light, benri::simple_cast<decltype(constant::speed_of_light)>(symbol::speed_of_light));
    EXPECT_BENRI_EQ(decltype(constant::magnetic_constant), constant::magnetic_constant, benri::simple_cast<decltype(constant::magnetic_constant)>(symbol::magnetic_constant));
    EXPECT_BENRI_EQ(decltype(constant::electric_constant), constant::electric_constant, benri::simple_cast<decltype(constant::electric_constant)>(symbol::electric_constant));
    EXPECT_BENRI_EQ(decltype(constant::gravitational_constant), constant::gravitational_constant, benri::simple_cast<decltype(constant::gravitational_constant)>(symbol::gravitational_constant));
    EXPECT_BENRI_EQ(decltype(constant::planck_constant), constant::planck_constant, benri::simple_cast<decltype(constant::planck_constant)>(symbol::planck_constant));
    EXPECT_BENRI_EQ(decltype(constant::reduced_planck_constant), constant::reduced_planck_constant, benri::simple_cast<decltype(constant::reduced_planck_constant)>(symbol::reduced_planck_constant));
    EXPECT_BENRI_EQ(decltype(constant::elementary_charge), constant::elementary_charge, benri::simple_cast<decltype(constant::elementary_charge)>(symbol::elementary_charge));
    EXPECT_BENRI_EQ(decltype(constant::fine_structure_constant), constant::fine_structure_constant, benri::simple_cast<decltype(constant::fine_structure_constant)>(symbol::fine_structure_constant));
    EXPECT_BENRI_EQ(decltype(constant::inverse_fine_structure_constant), constant::inverse_fine_structure_constant, benri::simple_cast<decltype(constant::inverse_fine_structure_constant)>(symbol::inverse_fine_structure_constant));
    EXPECT_BENRI_EQ(decltype(constant::electron_mass), constant::electron_mass, benri::simple_cast<decltype(constant::electron_mass)>(symbol::electron_mass));
    EXPECT_BENRI_EQ(decltype(constant::proton_mass), constant::proton_mass, benri::simple_cast<decltype(constant::proton_mass)>(symbol::proton_mass));
    EXPECT_BENRI_EQ(decltype(constant::muon_mass), constant::muon_mass, benri::simple_cast<decltype(constant::muon_mass)>(symbol::muon_mass));
    EXPECT_BENRI_EQ(decltype(constant::tau_mass), constant::tau_mass, benri::simple_cast<decltype(constant::tau_mass)>(symbol::tau_mass));
    EXPECT_BENRI_EQ(decltype(constant::neutron_mass), constant::neutron_mass, benri::simple_cast<decltype(constant::neutron_mass)>(symbol::neutron_mass));
    EXPECT_BENRI_EQ(decltype(constant::deuteron_mass), constant::deuteron_mass, benri::simple_cast<decltype(constant::deuteron_mass)>(symbol::deuteron_mass));
    EXPECT_BENRI_EQ(decltype(constant::triton_mass), constant::triton_mass, benri::simple_cast<decltype(constant::triton_mass)>(symbol::triton_mass));
    EXPECT_BENRI_EQ(decltype(constant::helion_mass), constant::helion_mass, benri::simple_cast<decltype(constant::helion_mass)>(symbol::helion_mass));
    EXPECT_BENRI_EQ(decltype(constant::alpha_particle_mass), constant::alpha_particle_mass, benri::simple_cast<decltype(constant::alpha_particle_mass)>(symbol::alpha_particle_mass));
    EXPECT_BENRI_EQ(decltype(constant::rydberg_constant), constant::rydberg_constant, benri::simple_cast<decltype(constant::rydberg_constant)>(symbol::rydberg_constant));
    EXPECT_BENRI_EQ(decltype(constant::bohr_radius), constant::bohr_radius, benri::simple_cast<decltype(constant::bohr_radius)>(symbol::bohr_radius));
    EXPECT_BENRI_EQ(decltype(constant::bohr_magneton), constant::bohr_magneton, benri::simple_cast<decltype(constant::bohr_magneton)>(symbol::bohr_magneton));
    EXPECT_BENRI_EQ(decltype(constant::avogadro_constant), constant::avogadro_constant, benri::simple_cast<decltype(constant::avogadro_constant)>(symbol::avogadro_constant));
    EXPECT_BENRI_EQ(decltype(constant::faraday_constant), constant::faraday_constant, benri::simple_cast<decltype(constant::faraday_constant)>(symbol::faraday_constant));
    EXPECT_BENRI_EQ(decltype(constant::molar_gas_constant), constant::molar_gas_constant, benri::simple_cast<decltype(constant::molar_gas_constant)>(symbol::molar_gas_constant));
    EXPECT_BENRI_EQ(decltype(constant::boltzmann_constant), constant::boltzmann_constant, benri::simple_cast<decltype(constant::boltzmann_constant)>(symbol::boltzmann_constant));
    EXPECT_BENRI_EQ(decltype(constant::stefan_boltzmann_constant), constant::stefan_boltzmann_constant, benri::simple_cast<decltype(constant::stefan_boltzmann_constant)>(symbol::stefan_boltzmann_constant));
    EXPECT_BENRI_EQ(decltype(constant::magnetic_flux_quantum), constant::magnetic_flux_quantum, benri::simple_cast<decltype(constant::magnetic_flux_quantum)>(symbol::magnetic_flux_quantum));
    EXPECT_BENRI_EQ(decltype(constant::josephson_constant), constant::josephson_constant, benri::simple_cast<decltype(constant::josephson_constant)>(symbol::josephson_constant));
    EXPECT_BENRI_EQ(decltype(constant::von_klitzing_constant), constant::von_klitzing_constant, benri::simple_cast<decltype(constant::von_klitzing_constant)>(symbol::von_klitzing_constant));
    EXPECT_BENRI_EQ(decltype(constant::atomic_mass_unit), constant::atomic_mass_unit, benri::simple_cast<decltype(constant::atomic_mass_unit)>(symbol::atomic_mass_unit));
    EXPECT_BENRI_EQ(decltype(constant::hartree_energy), constant::hartree_energy, benri::simple_cast<decltype(constant::hartree_energy)>(symbol::hartree_energy));
    EXPECT_BENRI_EQ(decltype(constant::conductance_quantum), constant::conductance_quantum, benri::simple_cast<decltype(constant::conductance_quantum)>(symbol::conductance_quantum));
    EXPECT_BENRI_EQ(decltype(constant::inverse_conductance_quantum), constant::inverse_conductance_quantum, benri::simple_cast<decltype(constant::inverse_conductance_quantum)>(symbol::inverse_conductance_quantum));
    EXPECT_BENRI_EQ(decltype(constant::vacuum_impedance), constant::vacuum_impedance, benri::simple_cast<decltype(constant::vacuum_impedance)>(symbol::vacuum_impedance));
    EXPECT_BENRI_EQ(decltype(constant::nuclear_magneton), constant::nuclear_magneton, benri::simple_cast<decltype(constant::nuclear_magneton)>(symbol::nuclear_magneton));
#pragma endregion
#pragma region astronomical constants
    EXPECT_BENRI_EQ(decltype(constant::solar_luminosity), constant::solar_luminosity, benri::simple_cast<decltype(constant::solar_luminosity)>(symbol::solar_luminosity));
    EXPECT_BENRI_EQ(decltype(constant::solar_mass), constant::solar_mass, benri::simple_cast<decltype(constant::solar_mass)>(symbol::solar_mass));
    EXPECT_BENRI_EQ(decltype(constant::jupiter_mass), constant::jupiter_mass, benri::simple_cast<decltype(constant::jupiter_mass)>(symbol::jupiter_mass));
    EXPECT_BENRI_EQ(decltype(constant::earth_mass), constant::earth_mass, benri::simple_cast<decltype(constant::earth_mass)>(symbol::earth_mass));
#pragma endregion
}
