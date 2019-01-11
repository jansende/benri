#pragma once
#include <benri/si/si.h>
#include <benri/si/astronomic.h>
#include <benri/si/cgs.h>
#include <ratio>
#include <iostream>

namespace benri
{
namespace si
{
using namespace astronomic;
using namespace cgs;
using centimetre_t = benri::multiply_units<benri::si::centi_t, benri::si::metre_t>;
using kilometre_t = benri::multiply_units<benri::si::kilo_t, benri::si::metre_t>;
using kilometre_per_second_t = benri::divide_units<kilometre_t, second_t>;

using astronomical_unit_per_year_t = benri::divide_units<astronomical_unit_t, year_t>;

using gram_per_cubic_centimetre_t = benri::divide_units<gram_t, benri::pow_unit<centimetre_t, std::ratio<3>>>;
using erg_per_gram_t = benri::divide_units<erg_t, gram_t>;
using solar_mass_per_year_t = benri::divide_units<solar_mass_t, year_t>;
using gram_per_year_t = benri::divide_units<gram_t, year_t>;
using one_per_year_t = benri::divide_units<one_t, year_t>;
using astronomical_unit_per_year_t = benri::divide_units<astronomical_unit_t, year_t>;
using degree_per_year_t = benri::divide_units<degree_t, year_t>;
using radian_per_year_t = benri::divide_units<radian_t, year_t>;

using square_gram_t = benri::pow_unit<gram_t, std::ratio<2>>;
using one_per_gram_t = benri::divide_units<one_t, gram_t>;
using one_per_degree_t = benri::divide_units<one_t, degree_t>;
using one_per_radian_t = benri::divide_units<one_t, radian_t>;
using one_per_astronomical_unit_t = benri::divide_units<one_t, astronomical_unit_t>;

using lemmy_t = benri::divide_units<one_t, benri::multiply_units<gram_t, one_t, astronomical_unit_t, degree_t>>;
using lemmy_gram_t = benri::multiply_units<gram_t, lemmy_t>;
using lemmy_one_t = benri::multiply_units<one_t, lemmy_t>;
using lemmy_astronomical_unit_t = benri::multiply_units<astronomical_unit_t, lemmy_t>;
using lemmy_degree_t = benri::multiply_units<degree_t, lemmy_t>;
using lemmy_radian_t = benri::multiply_units<radian_t, lemmy_t>;

using lemmy_per_year_t = benri::divide_units<lemmy_t, year_t>;
using one_per_cubic_astronomical_unit_t = benri::divide_units<one_t, benri::pow_unit<astronomical_unit_t, std::ratio<3>>>;

using square_centimetre_t = benri::pow_unit<centimetre_t, std::ratio<2>>;
using cubic_astronomical_unit_per_square_year_solar_mass_t = benri::divide_units<benri::pow_unit<astronomical_unit_t, std::ratio<3>>, benri::multiply_units<benri::pow_unit<year_t, std::ratio<2>>, solar_mass_t>>;
using square_astronomical_unit_per_year_t = benri::divide_units<benri::pow_unit<astronomical_unit_t, std::ratio<2>>, year_t>;
using square_astronomical_unit_per_square_year_t = benri::divide_units<benri::pow_unit<astronomical_unit_t, std::ratio<2>>, benri::pow_unit<year_t, std::ratio<2>>>;
using gram_square_astronomical_unit_per_year_t = benri::multiply_units<gram_t, square_astronomical_unit_per_year_t>;

using gram_square_astronomical_unit_per_square_year_t = benri::multiply_units<gram_t, benri::pow_unit<astronomical_unit_per_year_t, std::ratio<2>>>;

template <class T>
constexpr auto gravitational_constant = benri::value_type_cast<T>(benri::simple_cast<cubic_astronomical_unit_per_square_year_solar_mass_t>(benri::si::constant::gravitational_constant));
template <class T>
constexpr auto speed_of_light = benri::value_type_cast<T>(benri::simple_cast<astronomical_unit_per_year_t>(benri::si::constant::speed_of_light));
template <class T>
constexpr auto pi_constant = benri::value_type_cast<T>(benri::si::constant::pi);

} // namespace si

template <class T>
std::ostream &operator<<(std::ostream &os, const quantity<si::astronomical_unit_t, T> &obj)
{
    os << obj.value() << "au";
    return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const quantity<si::gram_t, T> &obj)
{
    os << obj.value() << "g";
    return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const quantity<si::degree_t, T> &obj)
{
    os << obj.value() << "deg";
    return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const quantity<si::radian_t, T> &obj)
{
    os << obj.value() << "rad";
    return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const quantity<si::one_t, T> &obj)
{
    os << obj.value();
    return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const quantity<si::astronomical_unit_per_year_t, T> &obj)
{
    os << obj.value() << "au/yr";
    return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const quantity<si::gram_per_year_t, T> &obj)
{
    os << obj.value() << "g/yr";
    return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const quantity<si::degree_per_year_t, T> &obj)
{
    os << obj.value() << "deg/yr";
    return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const quantity<si::radian_per_year_t, T> &obj)
{
    os << obj.value() << "rad/yr";
    return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const quantity<si::one_per_year_t, T> &obj)
{
    os << obj.value() << "/yr";
    return os;
}

} // namespace benri