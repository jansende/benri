#pragma once
#include <benri/impl/config.h>
#include <benri/impl/type/list.h>
#include <math.h>

namespace benri
{
namespace prefix
{
struct zero
{
    static constexpr Precision value = 0.0;
};
using zero_t = type::sorted_list<pre<zero>>;
// List of prefixes and constant values used to define units.
#pragma region si prefixes
using yocto_t = type::make_prefix_pow10<-24>;
using zepto_t = type::make_prefix_pow10<-21>;
using atto_t  = type::make_prefix_pow10<-18>;
using femto_t = type::make_prefix_pow10<-15>;
using pico_t  = type::make_prefix_pow10<-12>;
using nano_t  = type::make_prefix_pow10<-9>;
using micro_t = type::make_prefix_pow10<-6>;
using milli_t = type::make_prefix_pow10<-3>;
using centi_t = type::make_prefix_pow10<-2>;
using deci_t  = type::make_prefix_pow10<-1>;
using one_t   = type::make_prefix_pow10<0>;
using deca_t  = type::make_prefix_pow10<1>;
using hecto_t = type::make_prefix_pow10<2>;
using kilo_t  = type::make_prefix_pow10<3>;
using mega_t  = type::make_prefix_pow10<6>;
using giga_t  = type::make_prefix_pow10<9>;
using tera_t  = type::make_prefix_pow10<12>;
using peta_t  = type::make_prefix_pow10<15>;
using exa_t   = type::make_prefix_pow10<18>;
using zetta_t = type::make_prefix_pow10<21>;
using yotta_t = type::make_prefix_pow10<24>;
#pragma endregion
#pragma region data prefixes
using kibi_t = type::make_prefix<1024>;
using mebi_t = type::make_prefix<1048576>;
using gibi_t = type::make_prefix<1073741824>;
using tebi_t = type::make_prefix<1099511627776>;
using pebi_t = type::make_prefix<1125899906842624>;
using exbi_t = type::multiply_lists<pebi_t, kibi_t>;
using zebi_t = type::multiply_lists<pebi_t, mebi_t>;
using yobi_t = type::multiply_lists<pebi_t, gibi_t>;
#pragma endregion
#pragma region math constants
// Archimedes constant.
struct pi
{
    // See: https://oeis.org/A000796
    static constexpr Precision value =
        3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214;
};
using pi_t         = type::sorted_list<pre<pi>>;
using quarter_pi_t = type::multiply_lists<type::make_prefix<1, 4>, pi_t>;
using half_pi_t    = type::multiply_lists<type::make_prefix<1, 2>, pi_t>;
using two_pi_t     = type::multiply_lists<type::make_prefix<2>, pi_t>;
// Euler constant.
struct e
{
    // See: https://oeis.org/A001113
    static constexpr Precision value =
        2.71828182845904523536028747135266249775724709369995957496696762772407663035354759457138217852516642742746;
};
// Golden ratio.
using e_t = type::sorted_list<pre<e>>;
struct phi
{
    // See: https://oeis.org/A001622
    static constexpr Precision value =
        1.61803398874989484820458683436563811772030917980576286213544862270526046281890244970720720418939113748475;
};
using phi_t = type::sorted_list<pre<phi>>;
// Euler mascheroni constant.
struct gamma
{
    // See: https://oeis.org/A001620
    static constexpr Precision value =
        0.577215664901532860606512090082402431042159335939923598805767234884867726777664670936947063291746749;
};
// Square root of two.
using gamma_t = type::sorted_list<pre<gamma>>;
struct root_two // TODO: rethink!
{
    // See: https://oeis.org/A002193
    static constexpr Precision value =
        1.41421356237309504880168872420969807856967187537694807317667973799073247846210703885038753432764157;
};
using root_two_symbol_t = type::sorted_list<pre<std::ratio<2>, std::ratio<1, 2>>>;
using root_two_t        = type::sorted_list<pre<root_two>>;
#pragma endregion
#pragma region physics constants
// Speed of light in metre per second (exact, by definition).
struct speed_of_light
{
    static constexpr Precision value = 299792458.;
};
using speed_of_light_t = type::sorted_list<pre<speed_of_light>>;
// Magnetic constant in Henry per metre (exact, by definition).
using magnetic_constant_t =
    type::multiply_lists<type::make_prefix<2>, two_pi_t, type::make_prefix<1, 10000000>>;
// Electric constant in Farad per metre (exact, by definition).
using electric_constant_t = type::divide_lists<
    type::make_prefix<1>,
    type::multiply_lists<magnetic_constant_t,
                         type::pow_list<speed_of_light_t, std::ratio<2>>>>;
// Gravitational constant in Newton square metre per kilogram
struct gravitational_constant // TODO: check value
{
    static constexpr Precision value = 6.6740831e-11;
};
using gravitational_constant_t = type::sorted_list<pre<gravitational_constant>>;
// Planck constant in Joule seconds.
struct planck_constant
{
    static constexpr Precision value = 6.62607004081e-34;
};
using planck_constant_t = type::sorted_list<pre<planck_constant>>;
// Reduced planck constant in Joule seconds.
using reduced_planck_constant_t = type::divide_lists<planck_constant_t, two_pi_t>;
// Elementary charge in Coulomb.
struct elementary_charge
{
    static constexpr Precision value = 1.602176620898e-19;
};
using elementary_charge_t = type::sorted_list<pre<elementary_charge>>;
// Fine structure constant.
using fine_structure_constant_symbol_t = type::divide_lists<
    type::multiply_lists<type::multiply_lists<elementary_charge_t, elementary_charge_t>,
                         type::multiply_lists<magnetic_constant_t, speed_of_light_t>>,
    type::multiply_lists<type::make_prefix<2>, planck_constant_t>>;
struct fine_structure_constant
{
    static constexpr Precision value =
        expand_prefix_list<Precision, fine_structure_constant_symbol_t>;
};
using fine_structure_constant_t = type::sorted_list<pre<fine_structure_constant>>;
// Inverse fine structure constant.
using inverse_fine_structure_constant_t =
    type::divide_lists<type::make_prefix<1>, fine_structure_constant_t>;
// Electron mass in kilogram.
struct electron_mass
{
    static constexpr Precision value = 9.1093835611e-31;
};
using electron_mass_t = type::sorted_list<pre<electron_mass>>;
// Proton mass in kilogram.
struct proton_mass
{
    static constexpr Precision value = 1.67262189821e-27;
};
using proton_mass_t = type::sorted_list<pre<proton_mass>>;
// Muon mass in kilogram.
struct muon_mass
{
    static constexpr Precision value = 1.88353159448e-28;
};
using muon_mass_t = type::sorted_list<pre<muon_mass>>;
// Tau mass in kilogram.
struct tau_mass
{
    static constexpr Precision value = 3.1674729e-27;
};
using tau_mass_t = type::sorted_list<pre<tau_mass>>;
// Neutron mass in kilogram.
struct neutron_mass
{
    static constexpr Precision value = 1.67492747121 - 27;
};
using neutron_mass_t = type::sorted_list<pre<neutron_mass>>;
// Deuteron mass in kilogram.
struct deuteron_mass
{
    static constexpr Precision value = 3.34358371941e-27;
};
using deuteron_mass_t = type::sorted_list<pre<deuteron_mass>>;
// Triton mass in kilogram.
struct triton_mass
{
    static constexpr Precision value = 5.00735666562e-27;
};
using triton_mass_t = type::sorted_list<pre<triton_mass>>;
// Helion mass in kilogram.
struct helion_mass
{
    static constexpr Precision value = 5.00641270062e-27;
};
using helion_mass_t = type::sorted_list<pre<helion_mass>>;
// Alpha particle mass in kilogram.
struct alpha_particle_mass
{
    static constexpr Precision value = 6.64465723082e-27;
};
using alpha_particle_mass_t = type::sorted_list<pre<alpha_particle_mass>>;
// Rydberg constant in one per metre.
using rydberg_constant_t = type::divide_lists<
    type::multiply_lists<type::pow_list<fine_structure_constant_t, std::ratio<2>>,
                         electron_mass_t, speed_of_light_t>,
    type::multiply_lists<type::make_prefix<2>, planck_constant_t>>;
// Bohr radius in metre.
using bohr_radius_t = type::divide_lists<
    fine_structure_constant_t,
    type::multiply_lists<type::make_prefix<4>, pi_t, rydberg_constant_t>>;
// Bohr magneton in Joule per Tesla.
using bohr_magneton_t = type::divide_lists<
    type::multiply_lists<elementary_charge_t, reduced_planck_constant_t>,
    type::multiply_lists<type::make_prefix<2>, electron_mass_t>>;
// Avogadro constant in one per mol.
struct avogadro_constant
{
    static constexpr Precision value = 6.02214085774e23;
};
using avogadro_constant_t = type::sorted_list<pre<avogadro_constant>>;
// Faraday constant in Coulomb per mol.
using faraday_constant_t = type::multiply_lists<avogadro_constant_t, elementary_charge_t>;
// Molar gas constant in Joule per mole Kelvin.
struct molar_gas_constant
{
    static constexpr Precision value = 8.314459848;
};
using molar_gas_constant_t = type::sorted_list<pre<molar_gas_constant>>;
// Boltzmann constant in Joule per Kelvin.
using boltzmann_constant_t =
    type::divide_lists<molar_gas_constant_t, avogadro_constant_t>;
// Stefan-Boltzmann constant in Watt per square metre quartic Kelvin steradian
using stefan_boltzmann_constant_symbol_t = type::divide_lists<
    type::multiply_lists<type::pow_list<pi_t, std::ratio<2>>,
                         type::pow_list<boltzmann_constant_t, std::ratio<4>>>,
    type::multiply_lists<type::make_prefix<60>,
                         type::pow_list<reduced_planck_constant_t, std::ratio<3>>,
                         type::pow_list<speed_of_light_t, std::ratio<2>>>>;
struct stefan_boltzmann_constant_helper
{
    static constexpr Precision value = expand_prefix_list<
        Precision, type::divide_lists<boltzmann_constant_t, reduced_planck_constant_t>>;
};
struct stefan_boltzmann_constant
{
    static constexpr Precision value =
        expand_prefix_list<
            Precision,
            type::divide_lists<
                type::pow_list<pi_t, std::ratio<2>>,
                type::make_prefix<
                    60>>> * expand_prefix_list<Precision, type::pow_list<type::sorted_list<pre<stefan_boltzmann_constant_helper>>, std::ratio<3>>> * expand_prefix_list<Precision, boltzmann_constant_t> * expand_prefix_list<Precision, speed_of_light_t>;
};
using stefan_boltzmann_constant_t = type::sorted_list<pre<stefan_boltzmann_constant>>;
// Magnetic flux quantum in Weber.
using magnetic_flux_quantum_t =
    type::divide_lists<planck_constant_t,
                       type::multiply_lists<type::make_prefix<2>, elementary_charge_t>>;
// Josephson constant in Hertz per Volt.
using josephson_constant_t =
    type::divide_lists<type::multiply_lists<type::make_prefix<2>, elementary_charge_t>,
                       planck_constant_t>;
// von Klitzing constant in Ohm.
using von_klitzing_constant_t =
    type::divide_lists<planck_constant_t,
                       type::pow_list<elementary_charge_t, std::ratio<2>>>;
// Atomic mass unit in kilogram.
struct atomic_mass_unit
{
    static constexpr Precision value = 1.6605388628e-27;
};
using atomic_mass_unit_t = type::sorted_list<pre<atomic_mass_unit>>;
// Hartree energy in Joule.
using hartree_energy_t = type::divide_lists<
    type::pow_list<elementary_charge_t, std::ratio<2>>,
    type::multiply_lists<type::make_prefix<4>, pi_t, electric_constant_t, bohr_radius_t>>;
// Conductance quantum in Siemens.
using conductance_quantum_t = type::divide_lists<
    type::multiply_lists<type::make_prefix<2>,
                         type::pow_list<elementary_charge_t, std::ratio<2>>>,
    planck_constant_t>;
// Inverse conductance quantum in Ohm.
using inverse_conductance_quantum_t =
    type::divide_lists<type::make_prefix<1>, conductance_quantum_t>;
// Vacuum impedance in Ohm.
using vacuum_impedance_t = type::multiply_lists<magnetic_constant_t, speed_of_light_t>;
// Nuclear magneton in Joule per Tesla.
using nuclear_magneton_t = type::divide_lists<
    type::multiply_lists<elementary_charge_t, reduced_planck_constant_t>,
    type::multiply_lists<type::make_prefix<2>, proton_mass_t>>;
#pragma endregion
#pragma region time
using second_t          = type::make_prefix<>;
using minute_t          = type::multiply_lists<second_t, type::make_prefix<60>>;
using hour_t            = type::multiply_lists<minute_t, type::make_prefix<60>>;
using day_t             = type::multiply_lists<hour_t, type::make_prefix<24>>;
using week_t            = type::multiply_lists<day_t, type::make_prefix<7>>;
using gregorian_month_t = type::make_prefix<2629746>;
using gregorian_year_t  = type::make_prefix<31556952>;
using calendar_month_t  = type::multiply_lists<day_t, type::make_prefix<30>>;
using calendar_year_t   = type::multiply_lists<day_t, type::make_prefix<36525, 100>>;
using month_t           = gregorian_month_t;
using year_t            = gregorian_year_t;
// Sidereal year in seconds.
struct sidereal_year
{
    static constexpr Precision value = 3.155815e7;
};
using sidereal_year_t = type::sorted_list<pre<sidereal_year>>;
// Tropical year in seconds.
struct tropical_year
{
    static constexpr Precision value = 3.155693e7;
};
using tropical_year_t = type::sorted_list<pre<tropical_year>>;
#pragma endregion
#pragma region temperature
// Kelvin in Rankine.
struct rankine
{
    static constexpr Precision value = 1.8;
};
using rankine_t = type::sorted_list<pre<rankine>>;
// Absolute zero in degree Fahrenheit.
struct fahrenheit_zero
{
    static constexpr Precision value = -459.67;
};
using fahrenheit_zero_t = type::sorted_list<pre<fahrenheit_zero>>;
// Absolute zero in degree Celsius.
struct absolute_zero
{
    static constexpr Precision value = -273.15;
};
using absolute_zero_t = type::sorted_list<pre<absolute_zero>>;
// Absolute zero in degree Fahrenheit.
struct freezing_point
{
    static constexpr Precision value = 32.0;
};
using freezing_point_t = type::sorted_list<pre<freezing_point>>;
#pragma endregion
#pragma region astronomic
// Astronomical unit in metre.
struct astronomical_unit
{
    static constexpr Precision value = 149597870700.;
};
using astronomical_unit_t = type::sorted_list<pre<astronomical_unit>>;
// Parsec in metre.
using parsec_t = type::multiply_lists<type::divide_lists<type::make_prefix<648000>, pi_t>,
                                      astronomical_unit_t>;
// Solar mass in kilogram.
struct solar_mass
{
    static constexpr Precision value = 1.988474491e30;
};
using solar_mass_t = type::sorted_list<pre<solar_mass>>;
// Solar luminosity in Watt per steradian.
struct solar_luminosity
{
    static constexpr Precision value = 3.828e26;
};
using solar_luminosity_t = type::sorted_list<pre<solar_luminosity>>;
// Jupiter mass in kilogram.
struct jupiter_mass
{
    static constexpr Precision value = 1.898579334e27;
};
using jupiter_mass_t = type::sorted_list<pre<jupiter_mass>>;
// Earth mass in kilogram.
struct earth_mass
{
    static constexpr Precision value = 6.157296241e24;
};
using earth_mass_t = type::sorted_list<pre<earth_mass>>;
#pragma endregion
#pragma region non - si
//Ångström in metre.
using angstroem_t = type::make_prefix_pow10<-10>;
// Bohr in metre.
struct bohr
{
    static constexpr Precision value = 0.529177210818e-10;
};
using bohr_t = type::sorted_list<pre<bohr>>;
// Nautical mile in metre.
struct nautical_mile
{
    static constexpr Precision value = 1852;
};
using nautical_mile_t = type::sorted_list<pre<nautical_mile>>;
// International mile in metre.
struct international_mile
{
    static constexpr Precision value = 1609.344;
};
using international_mile_t = type::sorted_list<pre<international_mile>>;
// Yard in metre.
struct yard
{
    static constexpr Precision value = 0.9144;
};
using yard_t = type::sorted_list<pre<yard>>;
// International foot in metre.
struct international_foot
{
    static constexpr Precision value = 0.3048;
};
using international_foot_t = type::sorted_list<pre<international_foot>>;
// Inch in metre.
struct inch
{
    static constexpr Precision value = (1. / 39.37);
};
using inch_t = type::sorted_list<pre<inch>>;
// Pound in kilogram.
struct pound
{
    static constexpr Precision value = 4.5359237e-1;
};
using pound_t = type::sorted_list<pre<pound>>;
// Ounce in kilogram.
struct ounce
{
    static constexpr Precision value = 2.834952e-2;
};
using ounce_t = type::sorted_list<pre<ounce>>;
// Smoot in metre.
struct smoot
{
    static constexpr Precision value = 1.708;
};
using smoot_t = type::sorted_list<pre<smoot>>;
// Speed of cherry blossoms falling in centimetre per second.
struct sakura
{
    // See: 秒速5センチメートル
    static constexpr Precision value = 5.;
};
using sakura_t = type::sorted_list<pre<sakura>>;
#pragma endregion
} // namespace prefix
} // namespace benri