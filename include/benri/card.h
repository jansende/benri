#pragma once
#include <benri/si/si.h>
#include <benri/si/astronomic.h>
#include <benri/si/cgs.h>
#include <ratio>
#include <iostream>
#include <vector>

namespace benri
{
namespace si
{
using namespace astronomic;
using namespace cgs;

//---dimensionless units
//---mass
//---inverse mass
using one_per_gram_t = divide_units<one_t, gram_t>;
using one_per_jupiter_mass_t = divide_units<one_t, jupiter_mass_t>;
using one_per_solar_mass_t = divide_units<one_t, solar_mass_t>;
//---length
using micrometre_t = multiply_units<micro_t, metre_t>;
using centimetre_t = multiply_units<centi_t, metre_t>;
using kilometre_t = multiply_units<kilo_t, metre_t>;
//---inverse length
using one_per_micrometre_t = divide_units<one_t, micrometre_t>;
using one_per_centimetre_t = divide_units<one_t, centimetre_t>;
using one_per_kilometre_t = divide_units<one_t, kilometre_t>;
using one_per_astronomical_unit_t = divide_units<one_t, astronomical_unit_t>;
//---area
using square_centimetre_t = pow_unit<centimetre_t, std::ratio<2>>;
using square_astronomical_unit_t = pow_unit<astronomical_unit_t, std::ratio<2>>;
//---inverse area
using one_per_square_centimetre_t = divide_units<one_t, square_centimetre_t>;
using one_per_square_astronomical_unit_t = divide_units<one_t, square_astronomical_unit_t>;
//---volume
using cubic_centimetre_t = pow_unit<centimetre_t, std::ratio<3>>;
using cubic_astronomical_unit_t = pow_unit<astronomical_unit_t, std::ratio<3>>;
//---inverse volume
using one_per_cubic_centimetre_t = divide_units<one_t, cubic_centimetre_t>;
using one_per_cubic_astronomical_unit_t = divide_units<one_t, cubic_astronomical_unit_t>;
//---angles
//---inverse angles
using one_per_radian_t = divide_units<one_t, radian_t>;
using one_per_degree_t = divide_units<one_t, degree_t>;
//---time
using kilo_year_t = multiply_units<kilo_t, year_t>;
using mega_year_t = multiply_units<mega_t, year_t>;
using giga_year_t = multiply_units<giga_t, year_t>;
//---frequency
using one_per_year_t = divide_units<one_t, year_t>;
using one_per_kilo_year_t = divide_units<one_t, kilo_year_t>;
using one_per_mega_year_t = divide_units<one_t, mega_year_t>;
using one_per_giga_year_t = divide_units<one_t, giga_year_t>;
//---velocity
using kilometre_per_second_t = divide_units<kilometre_t, second_t>;
using astronomical_unit_per_year_t = divide_units<astronomical_unit_t, year_t>;
//---angular velocity
using radian_per_year_t = divide_units<radian_t, year_t>;
using degree_per_year_t = divide_units<degree_t, year_t>;
//---mass rate
using gram_per_year_t = divide_units<gram_t, year_t>;
using solar_mass_per_year_t = divide_units<solar_mass_t, year_t>;
//---density
using gram_per_cubic_centimetre_t = divide_units<gram_t, cubic_centimetre_t>;
//---inverse density
using cubic_centimetre_per_gram_t = divide_units<cubic_centimetre_t, gram_t>;
//---enery density
using erg_per_gram_t = divide_units<erg_t, gram_t>;
//---inverse enery density
using gram_per_erg_t = divide_units<gram_t, erg_t>;

//---phase space
using lemmy_t = divide_units<one_t, multiply_units<gram_t, one_t, astronomical_unit_t, degree_t>>;
using lemmy_gram_t = multiply_units<gram_t, lemmy_t>;
using lemmy_one_t = multiply_units<one_t, lemmy_t>;
using lemmy_astronomical_unit_t = multiply_units<astronomical_unit_t, lemmy_t>;
using lemmy_degree_t = multiply_units<degree_t, lemmy_t>;
using lemmy_radian_t = multiply_units<radian_t, lemmy_t>;
using lemmy_gram_degree_t = multiply_units<lemmy_gram_t, degree_t>;

using lemmy_per_year_t = divide_units<lemmy_t, year_t>;
//---various
using one_per_astronomical_unit_degree_t = divide_units<one_t, multiply_units<astronomical_unit_t, degree_t>>;
using square_gram_t = pow_unit<gram_t, std::ratio<2>>;
using cubic_astronomical_unit_per_square_year_solar_mass_t = divide_units<pow_unit<astronomical_unit_t, std::ratio<3>>, multiply_units<pow_unit<year_t, std::ratio<2>>, solar_mass_t>>;
using square_astronomical_unit_per_year_t = divide_units<pow_unit<astronomical_unit_t, std::ratio<2>>, year_t>;
using square_astronomical_unit_per_square_year_t = divide_units<pow_unit<astronomical_unit_t, std::ratio<2>>, pow_unit<year_t, std::ratio<2>>>;
using gram_square_astronomical_unit_per_year_t = multiply_units<gram_t, square_astronomical_unit_per_year_t>;
using gram_square_astronomical_unit_per_square_year_t = multiply_units<gram_t, pow_unit<astronomical_unit_per_year_t, std::ratio<2>>>;

//---constants
template <class T>
constexpr auto gravitational_constant = value_type_cast<T>(simple_cast<cubic_astronomical_unit_per_square_year_solar_mass_t>(constant::gravitational_constant));
template <class T>
constexpr auto speed_of_light = value_type_cast<T>(simple_cast<astronomical_unit_per_year_t>(constant::speed_of_light));
template <class T>
constexpr auto pi_constant = value_type_cast<T>(constant::pi);
} // namespace si

#define implement_stream_operator(NAME, SYMBOL)                                           \
    template <class T>                                                                    \
    std::ostream &operator<<(std::ostream &os, const quantity<NAME, T> &obj)              \
    {                                                                                     \
        os << obj.value() << SYMBOL;                                                      \
        return os;                                                                        \
    }                                                                                     \
    template <class T>                                                                    \
    std::ostream &operator<<(std::ostream &os, const std::vector<quantity<NAME, T>> &obj) \
    {                                                                                     \
        os << "[";                                                                        \
        for (auto index = size_t{0}; index < obj.size() - 1; ++index)                     \
            os << obj[index].value() << ", ";                                             \
        if (obj.size() > size_t{1})                                                       \
            os << obj[obj.size() - 1].value();                                            \
        os << "]" << SYMBOL;                                                              \
        return os;                                                                        \
    }
//---dimensionless units
implement_stream_operator(si::one_t, "");
//---mass
implement_stream_operator(si::gram_t, "g");
implement_stream_operator(si::jupiter_mass_t, "MJup");
implement_stream_operator(si::solar_mass_t, "MSol");
//---inverse mass
implement_stream_operator(si::one_per_gram_t, "g^-1");
implement_stream_operator(si::one_per_jupiter_mass_t, "MJup^-1");
implement_stream_operator(si::one_per_solar_mass_t, "MSol^-1");
//---length
implement_stream_operator(si::micrometre_t, "µm");
implement_stream_operator(si::centimetre_t, "cm");
implement_stream_operator(si::kilometre_t, "km");
implement_stream_operator(si::astronomical_unit_t, "au");
//---inverse length
implement_stream_operator(si::one_per_micrometre_t, "µm^-1");
implement_stream_operator(si::one_per_centimetre_t, "cm^-1");
implement_stream_operator(si::one_per_kilometre_t, "km^-1");
implement_stream_operator(si::one_per_astronomical_unit_t, "au^-1");
//---area
implement_stream_operator(si::square_centimetre_t, "cm^2");
implement_stream_operator(si::square_astronomical_unit_t, "au^2");
//---inverse area
implement_stream_operator(si::one_per_square_centimetre_t, "cm^-2");
implement_stream_operator(si::one_per_square_astronomical_unit_t, "au^-2");
//---volume
implement_stream_operator(si::cubic_centimetre_t, "cm^3");
implement_stream_operator(si::cubic_astronomical_unit_t, "au^3");
//---inverse volume
implement_stream_operator(si::one_per_cubic_centimetre_t, "cm^-3");
implement_stream_operator(si::one_per_cubic_astronomical_unit_t, "au^-3");
//---angles
implement_stream_operator(si::radian_t, "rad");
implement_stream_operator(si::degree_t, "deg");
//---inverse angles
implement_stream_operator(si::one_per_radian_t, "rad^-1");
implement_stream_operator(si::one_per_degree_t, "deg^-1");
//---time
implement_stream_operator(si::second_t, "s");
implement_stream_operator(si::year_t, "yr");
implement_stream_operator(si::kilo_year_t, "kyr");
implement_stream_operator(si::mega_year_t, "Myr");
implement_stream_operator(si::giga_year_t, "Gyr");
//---frequency
implement_stream_operator(si::hertz_t, "Hz");
implement_stream_operator(si::one_per_year_t, "yr^-1");
implement_stream_operator(si::one_per_kilo_year_t, "kyr^-1");
implement_stream_operator(si::one_per_mega_year_t, "Myr^-1");
implement_stream_operator(si::one_per_giga_year_t, "Gyr^-1");
//---velocity
implement_stream_operator(si::kilometre_per_second_t, "km s^-1");
implement_stream_operator(si::astronomical_unit_per_year_t, "au yr^-1");
//---angular velocity
implement_stream_operator(si::radian_per_year_t, "rad yr^-1");
implement_stream_operator(si::degree_per_year_t, "deg yr^-1");
//---mass rate
implement_stream_operator(si::gram_per_year_t, "g yr^-1");
implement_stream_operator(si::solar_mass_per_year_t, "MSol yr^-1");
//---density
implement_stream_operator(si::gram_per_cubic_centimetre_t, "g cm^-3");
//---inverse density
implement_stream_operator(si::cubic_centimetre_per_gram_t, "g^-1 cm^3");
//---energy density
implement_stream_operator(si::erg_per_gram_t, "erg g^-1");
//---inverse energy density
implement_stream_operator(si::gram_per_erg_t, "erg^-1 g");

//---phase space
implement_stream_operator(si::lemmy_t, "deg^-1 g^-1 au^-1");
implement_stream_operator(si::lemmy_gram_t, "deg^-1 au^-1");
// implement_stream_operator(si::lemmy_one_t, "deg^-1 g^-1 au^-1");
implement_stream_operator(si::lemmy_astronomical_unit_t, "deg^-1 g^-1");
implement_stream_operator(si::lemmy_degree_t, "g^-1 au^-1");
implement_stream_operator(si::lemmy_radian_t, "rad deg^-1 g^-1 au^-1");

implement_stream_operator(si::lemmy_per_year_t, "deg^-1 g^-1 au^-1 yr^-1");
//---various
implement_stream_operator(si::square_gram_t, "g^2");
implement_stream_operator(si::cubic_astronomical_unit_per_square_year_solar_mass_t, "MSol^-2 au^3");
implement_stream_operator(si::square_astronomical_unit_per_year_t, "au^2 yr^-1");
implement_stream_operator(si::square_astronomical_unit_per_square_year_t, "au^2 yr^-2");
implement_stream_operator(si::gram_square_astronomical_unit_per_year_t, "g au^2 yr^-1");
implement_stream_operator(si::gram_square_astronomical_unit_per_square_year_t, "g au^2 yr^-2");
} // namespace benri