#pragma once
#include <benri/impl/config.h>
#include <benri/impl/list.h>
#include <benri/impl/unit.h>
#pragma GCC diagnostic push                          //fix clang warning for this line
#pragma GCC diagnostic ignored "-Wreserved-id-macro" //we actually want to define this constant to include M_PI, ...
#define _USE_MATH_DEFINES
#pragma GCC diagnostic pop
#include <math.h>

namespace benri
{
namespace prefix
{
#pragma region si prefixes
using yocto_t = make_power_list<-24>;
using zepto_t = make_power_list<-21>;
using atto_t = make_power_list<-18>;
using femto_t = make_power_list<-15>;
using pico_t = make_power_list<-12>;
using nano_t = make_power_list<-9>;
using micro_t = make_power_list<-6>;
using milli_t = make_power_list<-3>;
using centi_t = make_power_list<-2>;
using deci_t = make_power_list<-1>;
using one_t = make_power_list<0>;
using deca_t = make_power_list<1>;
using hecto_t = make_power_list<2>;
using kilo_t = make_power_list<3>;
using mega_t = make_power_list<6>;
using giga_t = make_power_list<9>;
using tera_t = make_power_list<12>;
using peta_t = make_power_list<15>;
using exa_t = make_power_list<18>;
using zetta_t = make_power_list<21>;
using yotta_t = make_power_list<24>;
#pragma endregion
#pragma region data prefixes
using kibi_t = make_fraction_list<1024>;
using mebi_t = make_fraction_list<1048576>;
using gibi_t = make_fraction_list<1073741824>;
using tebi_t = make_fraction_list<1099511627776>;
using pebi_t = make_fraction_list<1125899906842624>;
using exbi_t = multiply_lists<pebi_t, kibi_t>;
using zebi_t = multiply_lists<pebi_t, mebi_t>;
using yobi_t = multiply_lists<pebi_t, gibi_t>;
#pragma endregion
#pragma region time prefixes
using second_t = make_fraction_list<>;
using minute_t = multiply_lists<second_t, make_fraction_list<60>>;
using hour_t = multiply_lists<minute_t, make_fraction_list<60>>;
using day_t = multiply_lists<hour_t, make_fraction_list<24>>;
using week_t = multiply_lists<day_t, make_fraction_list<7>>;
using month_t = multiply_lists<day_t, make_fraction_list<30>>;
using year_t = multiply_lists<day_t, make_fraction_list<36525, 100>>;
//sidereal year in s
struct sidereal_year
{
    static constexpr Precision value = 3.155815e7;
};
using sidereal_year_t = list<atom<sidereal_year>>;
//tropical year in s
struct tropical_year
{
    static constexpr Precision value = 3.155693e7;
};
using tropical_year_t = list<atom<tropical_year>>;
#pragma endregion
#pragma region mathematical constants
struct pi
{
    //archimedes constant
    //See: https://oeis.org/A000796
    static constexpr Precision value = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214;
};
using pi_t = list<atom<pi>>;
//quarter pi
using quarter_pi_t = multiply_lists<make_fraction_list<1, 4>, pi_t>;
//half pi
using half_pi_t = multiply_lists<make_fraction_list<1, 2>, pi_t>;
//two pi
using two_pi_t = multiply_lists<make_fraction_list<2>, pi_t>;
struct e
{
    //euler constant
    //See: https://oeis.org/A001113
    static constexpr Precision value = 2.71828182845904523536028747135266249775724709369995957496696762772407663035354759457138217852516642742746;
};
using e_t = list<atom<e>>;
struct phi
{
    //golden ratio
    //See: https://oeis.org/A001622
    static constexpr Precision value = 1.61803398874989484820458683436563811772030917980576286213544862270526046281890244970720720418939113748475;
};
using phi_t = list<atom<phi>>;
struct gamma
{
    //euler mascheroni constant
    //See: https://oeis.org/A001620
    static constexpr Precision value = 0.577215664901532860606512090082402431042159335939923598805767234884867726777664670936947063291746749;
};
using gamma_t = list<atom<gamma>>;
struct root_two //TODO: rethink!
{
    //square root of two
    //See: https://oeis.org/A002193
    static constexpr Precision value = 1.41421356237309504880168872420969807856967187537694807317667973799073247846210703885038753432764157;
};
using root_two_symbol_t = list<atom<std::ratio<2>, std::ratio<1, 2>>>;
using root_two_t = list<atom<root_two>>;
#pragma endregion
#pragma region physical constants
//speed of light in m/s (exact, by definition)
struct speed_of_light
{
    static constexpr Precision value = 299792458.;
};
using speed_of_light_t = list<atom<speed_of_light>>;
//magnetic constant in H/m (exact, by definition)
using magnetic_constant_t = multiply_lists<make_fraction_list<2>, two_pi_t, make_fraction_list<1, 10000000>>;
//electric constant in F/m (exact, by definition)
using electric_constant_t = divide_lists<make_fraction_list<1>, multiply_lists<magnetic_constant_t, pow_list<speed_of_light_t, std::ratio<2>>>>;
//gravitational constant in N m²/kg
struct gravitational_constant //TODO: check value
{
    static constexpr Precision value = 6.6740831e-11;
};
using gravitational_constant_t = list<atom<gravitational_constant>>;
//planck constant in J s
struct planck_constant
{
    static constexpr Precision value = 6.62607004081e-34;
};
using planck_constant_t = list<atom<planck_constant>>;
//reduced planck constant in J s
using reduced_planck_constant_t = divide_lists<planck_constant_t, two_pi_t>;
//elementary charge in C
struct elementary_charge
{
    static constexpr Precision value = 1.602176620898e-19;
};
using elementary_charge_t = list<atom<elementary_charge>>;
//fine structure constant in 1
using fine_structure_constant_t = divide_lists<multiply_lists<multiply_lists<elementary_charge_t, elementary_charge_t>, multiply_lists<magnetic_constant_t, speed_of_light_t>>, multiply_lists<make_fraction_list<2>, planck_constant_t>>;
//inverse fine structure constant in 1
using inverse_fine_structure_constant_t = divide_lists<make_fraction_list<1>, fine_structure_constant_t>;
//electron mass in kg
struct electron_mass
{
    static constexpr Precision value = 9.1093835611e-31;
};
using electron_mass_t = list<atom<electron_mass>>;
//proton mass in kg
struct proton_mass
{
    static constexpr Precision value = 1.67262189821e-27;
};
using proton_mass_t = list<atom<proton_mass>>;
//muon mass in kg
struct muon_mass
{
    static constexpr Precision value = 1.88353159448e-28;
};
using muon_mass_t = list<atom<muon_mass>>;
//tau mass in kg
struct tau_mass
{
    static constexpr Precision value = 3.1674729e-27;
};
using tau_mass_t = list<atom<tau_mass>>;
//neutron mass in kg
struct neutron_mass
{
    static constexpr Precision value = 1.67492747121 - 27;
};
using neutron_mass_t = list<atom<neutron_mass>>;
//deuteron mass in kg
struct deuteron_mass
{
    static constexpr Precision value = 3.34358371941e-27;
};
using deuteron_mass_t = list<atom<deuteron_mass>>;
//triton mass in kg
struct triton_mass
{
    static constexpr Precision value = 5.00735666562e-27;
};
using triton_mass_t = list<atom<triton_mass>>;
//helion mass in kg
struct helion_mass
{
    static constexpr Precision value = 5.00641270062e-27;
};
using helion_mass_t = list<atom<helion_mass>>;
//alpha particle mass in kg
struct alpha_particle_mass
{
    static constexpr Precision value = 6.64465723082e-27;
};
using alpha_particle_mass_t = list<atom<alpha_particle_mass>>;
//rydberg constant in m⁻¹
using rydberg_constant_t = divide_lists<multiply_lists<pow_list<fine_structure_constant_t, std::ratio<2>>, electron_mass_t, speed_of_light_t>, multiply_lists<make_fraction_list<2>, planck_constant_t>>;
//bohr radius in m
using bohr_radius_t = divide_lists<fine_structure_constant_t, multiply_lists<make_fraction_list<4>, pi_t, rydberg_constant_t>>;
//bohr magneton in J/T
using bohr_magneton_t = divide_lists<multiply_lists<elementary_charge_t, reduced_planck_constant_t>, multiply_lists<make_fraction_list<2>, electron_mass_t>>;
//avogadro constant in mol⁻¹
struct avogadro_constant
{
    static constexpr Precision value = 6.02214085774e23;
};
using avogadro_constant_t = list<atom<avogadro_constant>>;
//faraday constant in C/mol
using faraday_constant_t = multiply_lists<avogadro_constant_t, elementary_charge_t>;
//molar gas constant in J/(mol K)
struct molar_gas_constant
{
    static constexpr Precision value = 8.314459848;
};
using molar_gas_constant_t = list<atom<molar_gas_constant>>;
//boltzmann constant in J/K
using boltzmann_constant_t = divide_lists<molar_gas_constant_t, avogadro_constant_t>;
//stefan-boltzmann constant in W m⁻² K⁻⁴ sr⁻¹
using stefan_boltzmann_constant_t = divide_lists<multiply_lists<pow_list<pi_t, std::ratio<2>>,pow_list<boltzmann_constant_t, std::ratio<4>>>, multiply_lists<make_fraction_list<60>, pow_list<reduced_planck_constant_t, std::ratio<3>>, pow_list<speed_of_light_t, std::ratio<2>>>>;
//magnetic flux quantum in Wb
using magnetic_flux_quantum_t = divide_lists<planck_constant_t, multiply_lists<make_fraction_list<2>, elementary_charge_t>>;
//josephson constant in Hz/V
using josephson_constant_t = divide_lists<multiply_lists<make_fraction_list<2>, elementary_charge_t>, planck_constant_t>;
//von klitzing constant in Ω
using von_klitzing_constant_t = divide_lists<planck_constant_t, pow_list<elementary_charge_t, std::ratio<2>>>;
//atomic mass unit in kg
struct atomic_mass_unit
{
    static constexpr Precision value = 1.6605388628e-27;
};
using atomic_mass_unit_t = list<atom<atomic_mass_unit>>;
//hartree energy in J
using hartree_energy_t = divide_lists<pow_list<elementary_charge_t, std::ratio<2>>, multiply_lists<make_fraction_list<4>, pi_t, electric_constant_t, bohr_radius_t>>;
//conductance quantum in S
using conductance_quantum_t = divide_lists<multiply_lists<make_fraction_list<2>, pow_list<elementary_charge_t, std::ratio<2>>>, planck_constant_t>;
//inverse conductance quantum in Ω
using inverse_conductance_quantum_t = divide_lists<make_fraction_list<1>, conductance_quantum_t>;
//vacuum impedance in Ω
using vacuum_impedance_t = multiply_lists<magnetic_constant_t, speed_of_light_t>;
//nuclear magneton in J/T
using nuclear_magneton_t = divide_lists<multiply_lists<elementary_charge_t, reduced_planck_constant_t>, multiply_lists<make_fraction_list<2>, proton_mass_t>>;
#pragma endregion
#pragma region conversion values
//astronomical unit in m
struct astronomical_unit
{
    static constexpr Precision value = 149597870700.;
};
using astronomical_unit_t = list<atom<astronomical_unit>>;
//parsec in m
using parsec_t = multiply_lists<divide_lists<make_fraction_list<648000>, pi_t>, astronomical_unit_t>;
//solar mass in kg
struct solar_mass
{
    static constexpr Precision value = 1.988474491e30;
};
using solar_mass_t = list<atom<solar_mass>>;
//solar luminosity in W/sr
struct solar_luminosity
{
    static constexpr Precision value = 3.828e26;
};
using solar_luminosity_t = list<atom<solar_luminosity>>;
//jupiter mass in kg
struct jupiter_mass
{
    static constexpr Precision value = 1.898579334e27;
};
using jupiter_mass_t = list<atom<jupiter_mass>>;
//earth mass in kg
struct earth_mass
{
    static constexpr Precision value = 6.157296241e24;
};
using earth_mass_t = list<atom<earth_mass>>;
//angstroem in m
using angstroem_t = make_power_list<-10>;
//bohr in m
struct bohr
{
    static constexpr Precision value = 0.529177210818e-10;
};
using bohr_t = list<atom<bohr>>;
//nautical mile in m
struct nautical_mile
{
    static constexpr Precision value = 1852;
};
using nautical_mile_t = list<atom<nautical_mile>>;
//international mile in m
struct international_mile
{
    static constexpr Precision value = 1609.344;
};
using international_mile_t = list<atom<international_mile>>;
//yard in m
struct yard
{
    static constexpr Precision value = 0.9144;
};
using yard_t = list<atom<yard>>;
//international foot in m
struct international_foot
{
    static constexpr Precision value = 0.3048;
};
using international_foot_t = list<atom<international_foot>>;
//inch in m
struct inch
{
    static constexpr Precision value = (1. / 39.37);
};
using inch_t = list<atom<inch>>;
//pound in kg
struct pound
{
    static constexpr Precision value = 4.5359237e-1;
};
using pound_t = list<atom<pound>>;
//ounce in kg
struct ounce
{
    static constexpr Precision value = 2.834952e-2;
};
using ounce_t = list<atom<ounce>>;
//kelvin in rankine
struct rankine
{
    static constexpr Precision value = 1.8;
};
using rankine_t = list<atom<rankine>>;
//absolute zero in fahrenheit
struct fahrenheit_zero
{
    static constexpr Precision value = -459.67;
};
using fahrenheit_zero_t = list<atom<fahrenheit_zero>>;
//absolute zero in celsius
struct absolute_zero
{
    static constexpr Precision value = -273.15;
};
using absolute_zero_t = list<atom<absolute_zero>>;
#pragma endregion
} // namespace prefix
} // namespace benri
#pragma GCC diagnostic push                          //fix clang warning for this line
#pragma GCC diagnostic ignored "-Wreserved-id-macro"
#undef _USE_MATH_DEFINES
#pragma GCC diagnostic pop