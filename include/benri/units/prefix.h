#pragma once
#include <benri/config.h>
#include <benri/quantity.h>
#include <benri/unit.h>
#include <benri/impl/list.h>
#define _USE_MATH_DEFINES
#include <math.h>

namespace benri
{
namespace prefix
{
#pragma region si prefixes
using yocto = make_power_list_t<-24>;
using zepto = make_power_list_t<-21>;
using atto = make_power_list_t<-18>;
using femto = make_power_list_t<-15>;
using pico = make_power_list_t<-12>;
using nano = make_power_list_t<-9>;
using micro = make_power_list_t<-6>;
using milli = make_power_list_t<-3>;
using centi = make_power_list_t<-2>;
using deci = make_power_list_t<-1>;
using one = make_power_list_t<0>;
using deca = make_power_list_t<1>;
using hecto = make_power_list_t<2>;
using kilo = make_power_list_t<3>;
using mega = make_power_list_t<6>;
using giga = make_power_list_t<9>;
using tera = make_power_list_t<12>;
using peta = make_power_list_t<15>;
using exa = make_power_list_t<18>;
using zetta = make_power_list_t<21>;
using yotta = make_power_list_t<24>;
#pragma endregion
#pragma region data prefixes
using kibi = make_fraction_list_t<1024>;
using mebi = make_fraction_list_t<1048576>;
using gibi = make_fraction_list_t<1073741824>;
using tebi = make_fraction_list_t<1099511627776>;
using pebi = make_fraction_list_t<1125899906842624>;
using exbi = impl::multiply_lists_t<pebi, kibi>;
using zebi = impl::multiply_lists_t<pebi, mebi>;
using yobi = impl::multiply_lists_t<pebi, gibi>;
#pragma endregion
#pragma region time prefixes
using second = make_fraction_list_t<>;
using minute = impl::multiply_lists_t<second, make_fraction_list_t<60>>;
using hour = impl::multiply_lists_t<minute, make_fraction_list_t<60>>;
using day = impl::multiply_lists_t<hour, make_fraction_list_t<24>>;
using week = impl::multiply_lists_t<day, make_fraction_list_t<7>>;
using month = impl::multiply_lists_t<day, make_fraction_list_t<30>>;
using year = impl::multiply_lists_t<day, make_fraction_list_t<36525, 100>>;
//sidereal year in s
struct sidereal_year
{
    static constexpr Precision value = 3.155815e7;
};
using sidereal_year_t = list<atom<sidereal_year>>;
using sidereal_year_v = list<atom<sidereal_year>>;
//tropical year in s
struct tropical_year
{
    static constexpr Precision value = 3.155693e7;
};
using tropical_year_t = list<atom<tropical_year>>;
using tropical_year_v = list<atom<tropical_year>>;
#pragma endregion
#pragma region mathematical constants
struct pi
{
    //archimedes constant
    //See: https://oeis.org/A000796
    static constexpr Precision value = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214;
};
using pi_t = list<atom<pi>>;
using pi_v = list<atom<pi>>;
//two pi
using two_pi_t = impl::multiply_lists_t<make_fraction_list_t<2>, pi_t>;
using two_pi_v = impl::multiply_lists_t<make_fraction_list_t<2>, pi_v>;
struct e
{
    //euler constant
    //See: https://oeis.org/A001113
    static constexpr Precision value = 2.71828182845904523536028747135266249775724709369995957496696762772407663035354759457138217852516642742746;
};
using e_t = list<atom<e>>;
using e_v = list<atom<e>>;
struct phi
{
    //golden ratio
    //See: https://oeis.org/A001622
    static constexpr Precision value = 1.61803398874989484820458683436563811772030917980576286213544862270526046281890244970720720418939113748475;
};
using phi_t = list<atom<phi>>;
using phi_v = list<atom<phi>>;
struct gamma
{
    //euler mascheroni constant
    //See: https://oeis.org/A001620
    static constexpr Precision value = 0.577215664901532860606512090082402431042159335939923598805767234884867726777664670936947063291746749;
};
using gamma_t = list<atom<gamma>>;
using gamma_v = list<atom<gamma>>;
struct root_two //TODO: rethink!
{
    //square root of two
    //See: https://oeis.org/A002193
    static constexpr Precision value = 1.41421356237309504880168872420969807856967187537694807317667973799073247846210703885038753432764157;
};
using root_two_t = list<atom<std::ratio<2>, std::ratio<1, 2>>>;
using root_two_v = list<atom<root_two>>;
#pragma endregion
#pragma region physical constants
//speed of light in m/s (exact, by definition)
struct speed_of_light
{
    static constexpr Precision value = 299792458.;
};
using speed_of_light_t = list<atom<speed_of_light>>;
using speed_of_light_v = list<atom<speed_of_light>>;
//magnetic constant in H/m (exact, by definition)
using magnetic_constant_t = impl::multiply_lists_t<make_fraction_list_t<2>, impl::multiply_lists_t<two_pi_t, make_fraction_list_t<1, 10000000>>>;
using magnetic_constant_v = impl::multiply_lists_t<make_fraction_list_t<2>, impl::multiply_lists_t<two_pi_v, make_fraction_list_t<1, 10000000>>>;
//electric constant in F/m (exact, by definition)
using electric_constant_t = impl::divide_lists_t<make_fraction_list_t<1>, impl::multiply_lists_t<magnetic_constant_t, impl::multiply_lists_t<speed_of_light_t, speed_of_light_t>>>;
using electric_constant_v = impl::divide_lists_t<make_fraction_list_t<1>, impl::multiply_lists_t<magnetic_constant_v, impl::multiply_lists_t<speed_of_light_v, speed_of_light_v>>>;
//gravitational constant in N m²/kg
struct gravitational_constant //TODO: check value
{
    static constexpr Precision value = 6.6740831e-11;
};
using gravitational_constant_t = list<atom<gravitational_constant>>;
using gravitational_constant_v = list<atom<gravitational_constant>>;
//planck constant in J s
struct planck_constant
{
    static constexpr Precision value = 6.62607004081e-34;
};
using planck_constant_t = list<atom<planck_constant>>;
using planck_constant_v = list<atom<planck_constant>>;
//reduced planck constant in J s
using reduced_planck_constant_t = impl::divide_lists_t<planck_constant_t, two_pi_t>;
using reduced_planck_constant_v = impl::divide_lists_t<planck_constant_v, two_pi_v>;
//elementary charge in C
struct elementary_charge
{
    static constexpr Precision value = 1.602176620898e-19;
};
using elementary_charge_t = list<atom<elementary_charge>>;
using elementary_charge_v = list<atom<elementary_charge>>;
//fine structure constant in 1
using fine_structure_constant_t = impl::divide_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<elementary_charge_t, elementary_charge_t>, impl::multiply_lists_t<magnetic_constant_t, speed_of_light_t>>, impl::multiply_lists_t<make_fraction_list_t<2>, planck_constant_t>>;
using fine_structure_constant_v = impl::divide_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<elementary_charge_v, elementary_charge_v>, impl::multiply_lists_t<magnetic_constant_v, speed_of_light_v>>, impl::multiply_lists_t<make_fraction_list_t<2>, planck_constant_v>>;
//inverse fine structure constant in 1
using inverse_fine_structure_constant_t = impl::divide_lists_t<make_fraction_list_t<1>, fine_structure_constant_t>;
using inverse_fine_structure_constant_v = impl::divide_lists_t<make_fraction_list_t<1>, fine_structure_constant_v>;
//electron mass in kg
struct electron_mass
{
    static constexpr Precision value = 9.1093835611e-31;
};
using electron_mass_t = list<atom<electron_mass>>;
using electron_mass_v = list<atom<electron_mass>>;
//proton mass in kg
struct proton_mass
{
    static constexpr Precision value = 1.67262189821e-27;
};
using proton_mass_t = list<atom<proton_mass>>;
using proton_mass_v = list<atom<proton_mass>>;
//muon mass in kg
struct muon_mass
{
    static constexpr Precision value = 1.88353159448e-28;
};
using muon_mass_t = list<atom<muon_mass>>;
using muon_mass_v = list<atom<muon_mass>>;
//tau mass in kg
struct tau_mass
{
    static constexpr Precision value = 3.1674729e-27;
};
using tau_mass_t = list<atom<tau_mass>>;
using tau_mass_v = list<atom<tau_mass>>;
//neutron mass in kg
struct neutron_mass
{
    static constexpr Precision value = 1.67492747121-27;
};
using neutron_mass_t = list<atom<neutron_mass>>;
using neutron_mass_v = list<atom<neutron_mass>>;
//deuteron mass in kg
struct deuteron_mass
{
    static constexpr Precision value = 3.34358371941e-27;
};
using deuteron_mass_t = list<atom<deuteron_mass>>;
using deuteron_mass_v = list<atom<deuteron_mass>>;
//triton mass in kg
struct triton_mass
{
    static constexpr Precision value = 5.00735666562e-27;
};
using triton_mass_t = list<atom<triton_mass>>;
using triton_mass_v = list<atom<triton_mass>>;
//helion mass in kg
struct helion_mass
{
    static constexpr Precision value = 5.00641270062e-27;
};
using helion_mass_t = list<atom<helion_mass>>;
using helion_mass_v = list<atom<helion_mass>>;
//alpha particle mass in kg
struct alpha_particle_mass
{
    static constexpr Precision value = 6.64465723082e-27;
};
using alpha_particle_mass_t = list<atom<alpha_particle_mass>>;
using alpha_particle_mass_v = list<atom<alpha_particle_mass>>;
//rydberg constant in m⁻¹
using rydberg_constant_t = impl::divide_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<fine_structure_constant_t, fine_structure_constant_t>, impl::multiply_lists_t<electron_mass_t, speed_of_light_t>>, impl::multiply_lists_t<make_fraction_list_t<2>, planck_constant_t>>;
using rydberg_constant_v = impl::divide_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<fine_structure_constant_v, fine_structure_constant_v>, impl::multiply_lists_t<electron_mass_v, speed_of_light_v>>, impl::multiply_lists_t<make_fraction_list_t<2>, planck_constant_v>>;
//bohr radius in m
using bohr_radius_t = impl::divide_lists_t<fine_structure_constant_t, impl::multiply_lists_t<impl::multiply_lists_t<make_fraction_list_t<4>, pi_t>, rydberg_constant_t>>;
using bohr_radius_v = impl::divide_lists_t<fine_structure_constant_v, impl::multiply_lists_t<impl::multiply_lists_t<make_fraction_list_t<4>, pi_v>, rydberg_constant_v>>;
//bohr magneton in J/T
using bohr_magneton_t = impl::divide_lists_t<impl::multiply_lists_t<elementary_charge_t, reduced_planck_constant_t>, impl::multiply_lists_t<make_fraction_list_t<2>, electron_mass_t>>;
using bohr_magneton_v = impl::divide_lists_t<impl::multiply_lists_t<elementary_charge_v, reduced_planck_constant_v>, impl::multiply_lists_t<make_fraction_list_t<2>, electron_mass_v>>;
//avogadro constant in mol⁻¹
struct avogadro_constant
{
    static constexpr Precision value = 6.02214085774e23;
};
using avogadro_constant_t = list<atom<avogadro_constant>>;
using avogadro_constant_v = list<atom<avogadro_constant>>;
//faraday constant in C/mol
using faraday_constant_t = impl::multiply_lists_t<avogadro_constant_t, elementary_charge_t>;
using faraday_constant_v = impl::multiply_lists_t<avogadro_constant_v, elementary_charge_v>;
//molar gas constant in J/(mol K)
struct molar_gas_constant
{
    static constexpr Precision value = 8.314459848;
};
using molar_gas_constant_t = list<atom<molar_gas_constant>>;
using molar_gas_constant_v = list<atom<molar_gas_constant>>;
//boltzmann constant in J/K
using boltzmann_constant_t = impl::divide_lists_t<molar_gas_constant_t, avogadro_constant_t>;
using boltzmann_constant_v = impl::divide_lists_t<molar_gas_constant_v, avogadro_constant_v>;
//stefan-boltzmann constant in W m⁻² K⁻⁴ sr⁻¹
using stefan_boltzmann_constant_t = impl::divide_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<pi_t, pi_t>, impl::multiply_lists_t<impl::multiply_lists_t<boltzmann_constant_t, boltzmann_constant_t>, impl::multiply_lists_t<boltzmann_constant_t, boltzmann_constant_t>>>, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<make_fraction_list_t<60>, reduced_planck_constant_t>, impl::multiply_lists_t<reduced_planck_constant_t, reduced_planck_constant_t>>, impl::multiply_lists_t<speed_of_light_t, speed_of_light_t>>>;
using stefan_boltzmann_constant_v = impl::divide_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<pi_v, pi_v>, impl::multiply_lists_t<impl::multiply_lists_t<boltzmann_constant_v, boltzmann_constant_v>, impl::multiply_lists_t<boltzmann_constant_v, boltzmann_constant_v>>>, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<make_fraction_list_t<60>, reduced_planck_constant_v>, impl::multiply_lists_t<reduced_planck_constant_v, reduced_planck_constant_v>>, impl::multiply_lists_t<speed_of_light_v, speed_of_light_v>>>;
//magnetic flux quantum in Wb
using magnetic_flux_quantum_t = impl::divide_lists_t<planck_constant_t, impl::multiply_lists_t<make_fraction_list_t<2>, elementary_charge_t>>;
using magnetic_flux_quantum_v = impl::divide_lists_t<planck_constant_v, impl::multiply_lists_t<make_fraction_list_t<2>, elementary_charge_v>>;
//josephson constant in Hz/V
using josephson_constant_t = impl::divide_lists_t<impl::multiply_lists_t<make_fraction_list_t<2>, elementary_charge_t>, planck_constant_t>;
using josephson_constant_v = impl::divide_lists_t<impl::multiply_lists_t<make_fraction_list_t<2>, elementary_charge_v>, planck_constant_v>;
//von klitzing constant in Ω
using von_klitzing_constant_t = impl::divide_lists_t<planck_constant_t, impl::multiply_lists_t<elementary_charge_t, elementary_charge_t>>;
using von_klitzing_constant_v = impl::divide_lists_t<planck_constant_v, impl::multiply_lists_t<elementary_charge_v, elementary_charge_v>>;
//atomic mass unit in kg
struct atomic_mass_unit
{
    static constexpr Precision value = 1.6605388628e-27;
};
using atomic_mass_unit_t = list<atom<atomic_mass_unit>>;
using atomic_mass_unit_v = list<atom<atomic_mass_unit>>;
//hartree energy in J
using hartree_energy_t = impl::divide_lists_t<impl::multiply_lists_t<elementary_charge_t, elementary_charge_t>, impl::multiply_lists_t<impl::multiply_lists_t<make_fraction_list_t<4>, pi_t>, impl::multiply_lists_t<electric_constant_t, bohr_radius_t>>>;
using hartree_energy_v = impl::divide_lists_t<impl::multiply_lists_t<elementary_charge_v, elementary_charge_v>, impl::multiply_lists_t<impl::multiply_lists_t<make_fraction_list_t<4>, pi_v>, impl::multiply_lists_t<electric_constant_v, bohr_radius_v>>>;
//conductance quantum in S
using conductance_quantum_t = impl::divide_lists_t<impl::multiply_lists_t<make_fraction_list_t<2>,impl::multiply_lists_t<elementary_charge_t, elementary_charge_t>>, planck_constant_t>;
using conductance_quantum_v = impl::divide_lists_t<impl::multiply_lists_t<make_fraction_list_t<2>,impl::multiply_lists_t<elementary_charge_v, elementary_charge_v>>, planck_constant_v>;
//inverse conductance quantum in Ω
using inverse_conductance_quantum_t = impl::divide_lists_t<make_fraction_list_t<1>,conductance_quantum_t>;
using inverse_conductance_quantum_v = impl::divide_lists_t<make_fraction_list_t<1>,conductance_quantum_v>;
//vacuum impedance in Ω
using vacuum_impedance_t = impl::multiply_lists_t<magnetic_constant_t,speed_of_light_t>;
using vacuum_impedance_v = impl::multiply_lists_t<magnetic_constant_v,speed_of_light_v>;
//nuclear magneton in J/T
using nuclear_magneton_t = impl::divide_lists_t<impl::multiply_lists_t<elementary_charge_t, reduced_planck_constant_t>, impl::multiply_lists_t<make_fraction_list_t<2>, proton_mass_t>>;
using nuclear_magneton_v = impl::divide_lists_t<impl::multiply_lists_t<elementary_charge_v, reduced_planck_constant_v>, impl::multiply_lists_t<make_fraction_list_t<2>, proton_mass_v>>;
#pragma endregion
#pragma region conversion values
//astronomical unit in m
struct astronomical_unit
{
    static constexpr Precision value = 149597870700.;
};
using astronomical_unit_t = list<atom<astronomical_unit>>;
using astronomical_unit_v = list<atom<astronomical_unit>>;
//parsec in m
using parsec_t = impl::multiply_lists_t<impl::divide_lists_t<make_fraction_list_t<648000>, pi_t>, astronomical_unit_t>;
using parsec_v = impl::multiply_lists_t<impl::divide_lists_t<make_fraction_list_t<648000>, pi_v>, astronomical_unit_v>;
//solar mass in kg
struct solar_mass
{
    static constexpr Precision value = 1.988474491e30;
};
using solar_mass_t = list<atom<solar_mass>>;
using solar_mass_v = list<atom<solar_mass>>;
//jupiter mass in kg
struct jupiter_mass
{
    static constexpr Precision value = 1.898579334e27;
};
using jupiter_mass_t = list<atom<jupiter_mass>>;
using jupiter_mass_v = list<atom<jupiter_mass>>;
//earth mass in kg
struct earth_mass
{
    static constexpr Precision value = 6.157296241e24;
};
using earth_mass_t = list<atom<earth_mass>>;
using earth_mass_v = list<atom<earth_mass>>;
//angstroem in m
using angstroem_t = impl::multiply_lists_t<nano,deci>;
using angstroem_v = impl::multiply_lists_t<nano,deci>;
//bohr in m
struct bohr
{
    static constexpr Precision value = 0.529177210818e-10;
};
using bohr_t = list<atom<bohr>>;
using bohr_v = list<atom<bohr>>;
//nautical mile in m
struct nautical_mile
{
    static constexpr Precision value = 1852;
};
using nautical_mile_t = list<atom<nautical_mile>>;
using nautical_mile_v = list<atom<nautical_mile>>;
//international mile in m
struct international_mile
{
    static constexpr Precision value = 1609.344;
};
using international_mile_t = list<atom<international_mile>>;
using international_mile_v = list<atom<international_mile>>;
//yard in m
struct yard
{
    static constexpr Precision value = 0.9144;
};
using yard_t = list<atom<yard>>;
using yard_v = list<atom<yard>>;
//international foot in m
struct international_foot
{
    static constexpr Precision value = 0.3048;
};
using international_foot_t = list<atom<international_foot>>;
using international_foot_v = list<atom<international_foot>>;
//inch in m
struct inch
{
    static constexpr Precision value = (1./39.37);
};
using inch_t = list<atom<inch>>;
using inch_v = list<atom<inch>>;
//pound in kg
struct pound
{
    static constexpr Precision value = 4.5359237e-1;
};
using pound_t = list<atom<pound>>;
using pound_v = list<atom<pound>>;
//ounce in kg
struct ounce
{
    static constexpr Precision value = 2.834952e-2;
};
using ounce_t = list<atom<ounce>>;
using ounce_v = list<atom<ounce>>;
#pragma endregion
} // namespace prefix
} // namespace benri
#undef _USE_MATH_DEFINES