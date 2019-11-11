#pragma once
#include <benri/si/astronomic.h>
#include <benri/si/cgs.h>
#include <benri/si/si.h>
#include <iostream>
#include <ratio>
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
using one_per_gram_t         = divide_units<one_t, gram_t>;
using one_per_jupiter_mass_t = divide_units<one_t, jupiter_mass_t>;
using one_per_solar_mass_t   = divide_units<one_t, solar_mass_t>;
//---length
using micrometre_t = multiply_units<micro_t, metre_t>;
using centimetre_t = multiply_units<centi_t, metre_t>;
using kilometre_t  = multiply_units<kilo_t, metre_t>;
//---inverse length
using one_per_micrometre_t        = divide_units<one_t, micrometre_t>;
using one_per_centimetre_t        = divide_units<one_t, centimetre_t>;
using one_per_kilometre_t         = divide_units<one_t, kilometre_t>;
using one_per_astronomical_unit_t = divide_units<one_t, astronomical_unit_t>;
//---area
using square_centimetre_t        = pow_unit<centimetre_t, std::ratio<2>>;
using square_astronomical_unit_t = pow_unit<astronomical_unit_t, std::ratio<2>>;
//---inverse area
using one_per_square_centimetre_t = divide_units<one_t, square_centimetre_t>;
using one_per_square_astronomical_unit_t =
    divide_units<one_t, square_astronomical_unit_t>;
//---volume
using cubic_centimetre_t        = pow_unit<centimetre_t, std::ratio<3>>;
using cubic_astronomical_unit_t = pow_unit<astronomical_unit_t, std::ratio<3>>;
//---inverse volume
using one_per_cubic_centimetre_t        = divide_units<one_t, cubic_centimetre_t>;
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
using one_per_year_t      = divide_units<one_t, year_t>;
using one_per_kilo_year_t = divide_units<one_t, kilo_year_t>;
using one_per_mega_year_t = divide_units<one_t, mega_year_t>;
using one_per_giga_year_t = divide_units<one_t, giga_year_t>;
//---velocity
using metre_per_second_t           = divide_units<metre_t, second_t>;
using kilometre_per_second_t       = divide_units<kilometre_t, second_t>;
using astronomical_unit_per_year_t = divide_units<astronomical_unit_t, year_t>;
//---angular velocity
using radian_per_year_t = divide_units<radian_t, year_t>;
using degree_per_year_t = divide_units<degree_t, year_t>;
//---mass rate
using gram_per_year_t       = divide_units<gram_t, year_t>;
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
using lemmy_t =
    divide_units<one_t, multiply_units<gram_t, one_t, astronomical_unit_t, radian_t>>;
using lemmy_gram_t              = multiply_units<gram_t, lemmy_t>;
using lemmy_one_t               = multiply_units<one_t, lemmy_t>;
using lemmy_astronomical_unit_t = multiply_units<astronomical_unit_t, lemmy_t>;
using lemmy_degree_t            = multiply_units<degree_t, lemmy_t>;
using lemmy_radian_t            = multiply_units<radian_t, lemmy_t>;
using lemmy_gram_radian_t       = multiply_units<lemmy_gram_t, radian_t>;

using lemmy_per_year_t      = divide_units<lemmy_t, year_t>;
using lemmy_gram_per_year_t = divide_units<lemmy_gram_t, year_t>;
using lemmy_one_per_year_t  = divide_units<lemmy_one_t, year_t>;
using lemmy_astronomical_unit_per_year_t =
    divide_units<lemmy_astronomical_unit_t, year_t>;
using lemmy_degree_per_year_t = divide_units<lemmy_degree_t, year_t>;
using lemmy_radian_per_year_t = divide_units<lemmy_radian_t, year_t>;
//---various
using one_per_astronomical_unit_radian_t =
    divide_units<one_t, multiply_units<astronomical_unit_t, radian_t>>;
using square_gram_t = pow_unit<gram_t, std::ratio<2>>;
using cubic_astronomical_unit_per_square_year_solar_mass_t =
    divide_units<pow_unit<astronomical_unit_t, std::ratio<3>>,
                 multiply_units<pow_unit<year_t, std::ratio<2>>, solar_mass_t>>;
using square_astronomical_unit_per_year_t =
    divide_units<pow_unit<astronomical_unit_t, std::ratio<2>>, year_t>;
using square_astronomical_unit_per_square_year_t =
    divide_units<pow_unit<astronomical_unit_t, std::ratio<2>>,
                 pow_unit<year_t, std::ratio<2>>>;
using gram_square_astronomical_unit_per_year_t =
    multiply_units<gram_t, square_astronomical_unit_per_year_t>;
using gram_square_astronomical_unit_per_square_year_t =
    multiply_units<gram_t, pow_unit<astronomical_unit_per_year_t, std::ratio<2>>>;
using square_astronomical_unit_centimetre_per_square_year_gram_t = divide_units<
    multiply_units<centimetre_t, pow_unit<astronomical_unit_t, std::ratio<2>>>,
    multiply_units<pow_unit<year_t, std::ratio<2>>, gram_t>>;
using astronomical_unit_square_centimetre_per_square_year_solar_mass_t = divide_units<
    multiply_units<astronomical_unit_t, pow_unit<centimetre_t, std::ratio<2>>>,
    multiply_units<pow_unit<year_t, std::ratio<2>>, solar_mass_t>>;
using astronomical_unit_square_centimetre_per_square_year_t = divide_units<
    multiply_units<astronomical_unit_t, pow_unit<centimetre_t, std::ratio<2>>>,
    pow_unit<year_t, std::ratio<2>>>;
using gram_square_astronomical_unit_steradian_per_cubic_year_t = divide_units<
    multiply_units<gram_t, pow_unit<astronomical_unit_t, std::ratio<2>>, steradian_t>,
    pow_unit<year_t, std::ratio<3>>>;
using square_astronomical_unit_square_centimetre_per_cubic_year_t =
    divide_units<multiply_units<pow_unit<astronomical_unit_t, std::ratio<2>>,
                                pow_unit<centimetre_t, std::ratio<2>>>,
                 pow_unit<year_t, std::ratio<3>>>;
using gram_square_astronomical_unit_per_cubic_year_centimetre_t =
    divide_units<multiply_units<gram_t, pow_unit<astronomical_unit_t, std::ratio<2>>>,
                 multiply_units<pow_unit<year_t, std::ratio<3>>, centimetre_t>>;
using gram_square_astronomical_unit_per_cubic_year_t =
    divide_units<multiply_units<gram_t, pow_unit<astronomical_unit_t, std::ratio<2>>>,
                 pow_unit<year_t, std::ratio<3>>>;
using gram_astronomical_unit_per_square_year_centimetre_t =
    divide_units<multiply_units<gram_t, astronomical_unit_t>,
                 multiply_units<pow_unit<year_t, std::ratio<2>>, centimetre_t>>;
using solar_mass_astronomical_unit_per_square_year_t =
    divide_units<multiply_units<solar_mass_t, astronomical_unit_t>,
                 pow_unit<year_t, std::ratio<2>>>;
using astronomical_unit_square_centimetre_per_square_year_gram_t = divide_units<
    multiply_units<astronomical_unit_t, pow_unit<centimetre_t, std::ratio<2>>>,
    multiply_units<pow_unit<year_t, std::ratio<2>>, gram_t>>;
using solar_mass_astronomical_unit_square_centimetre_per_square_year_gram_t =
    divide_units<multiply_units<solar_mass_t, astronomical_unit_t,
                                pow_unit<centimetre_t, std::ratio<2>>>,
                 multiply_units<pow_unit<year_t, std::ratio<2>>, gram_t>>;
using solar_mass_astronomical_unit_per_square_year_centimetre_t =
    divide_units<multiply_units<solar_mass_t, astronomical_unit_t>,
                 multiply_units<pow_unit<year_t, std::ratio<2>>, centimetre_t>>;
using solar_mass_square_astronomical_unit_square_centimetre_per_cubic_year_gram_t =
    divide_units<
        multiply_units<solar_mass_t, pow_unit<astronomical_unit_t, std::ratio<2>>>,
        multiply_units<pow_unit<year_t, std::ratio<3>>, gram_t>>;
} // namespace si
template <class Unit>
struct symbol_impl
{
    static constexpr auto name = meta::static_string{"???"};
};
template <class Unit>
constexpr meta::static_string symbol = symbol_impl<Unit>::name;

template <class Unit, class T>
auto operator<<(std::ostream& os, const quantity<Unit, T>& obj) -> std::ostream&
{
    os << obj.value() << symbol<Unit>;
    return os;
}
template <class Unit, class T>
auto operator<<(std::ostream& os, const std::vector<quantity<Unit, T>>& obj)
    -> std::ostream&
{
    os << "[";
    for (auto index = size_t{0}; index + 1 < obj.size(); ++index)
        os << obj[index].value() << ", ";
    if (obj.size() >= size_t{1})
        os << obj[obj.size() - 1].value();
    os << "]" << symbol<Unit>;
    return os;
}

//---dimensionless units
template <>
struct symbol_impl<si::one_t>
{
    static constexpr auto name = meta::static_string{""};
};
//---mass
template <>
struct symbol_impl<si::gram_t>
{
    static constexpr auto name = meta::static_string{"g"};
};
template <>
struct symbol_impl<si::jupiter_mass_t>
{
    static constexpr auto name = meta::static_string{"MJup"};
};
template <>
struct symbol_impl<si::solar_mass_t>
{
    static constexpr auto name = meta::static_string{"MSol"};
};
//---inverse mass
template <>
struct symbol_impl<si::one_per_gram_t>
{
    static constexpr auto name = meta::static_string{"g^-1"};
};
template <>
struct symbol_impl<si::one_per_jupiter_mass_t>
{
    static constexpr auto name = meta::static_string{"MJup^-1"};
};
template <>
struct symbol_impl<si::one_per_solar_mass_t>
{
    static constexpr auto name = meta::static_string{"MSol^-1"};
};
//---length
template <>
struct symbol_impl<si::micrometre_t>
{
    static constexpr auto name = meta::static_string{"µm"};
};
template <>
struct symbol_impl<si::centimetre_t>
{
    static constexpr auto name = meta::static_string{"cm"};
};
template <>
struct symbol_impl<si::kilometre_t>
{
    static constexpr auto name = meta::static_string{"km"};
};
template <>
struct symbol_impl<si::astronomical_unit_t>
{
    static constexpr auto name = meta::static_string{"au"};
};
//---inverse length
template <>
struct symbol_impl<si::one_per_micrometre_t>
{
    static constexpr auto name = meta::static_string{"µm^-1"};
};
template <>
struct symbol_impl<si::one_per_centimetre_t>
{
    static constexpr auto name = meta::static_string{"cm^-1"};
};
template <>
struct symbol_impl<si::one_per_kilometre_t>
{
    static constexpr auto name = meta::static_string{"km^-1"};
};
template <>
struct symbol_impl<si::one_per_astronomical_unit_t>
{
    static constexpr auto name = meta::static_string{"au^-1"};
};
//---area
template <>
struct symbol_impl<si::square_centimetre_t>
{
    static constexpr auto name = meta::static_string{"cm^2"};
};
template <>
struct symbol_impl<si::square_astronomical_unit_t>
{
    static constexpr auto name = meta::static_string{"au^2"};
};
//---inverse area
template <>
struct symbol_impl<si::one_per_square_centimetre_t>
{
    static constexpr auto name = meta::static_string{"cm^-2"};
};
template <>
struct symbol_impl<si::one_per_square_astronomical_unit_t>
{
    static constexpr auto name = meta::static_string{"au^-2"};
};
//---volume
template <>
struct symbol_impl<si::cubic_centimetre_t>
{
    static constexpr auto name = meta::static_string{"cm^3"};
};
template <>
struct symbol_impl<si::cubic_astronomical_unit_t>
{
    static constexpr auto name = meta::static_string{"au^3"};
};
//---inverse volume
template <>
struct symbol_impl<si::one_per_cubic_centimetre_t>
{
    static constexpr auto name = meta::static_string{"cm^-3"};
};
template <>
struct symbol_impl<si::one_per_cubic_astronomical_unit_t>
{
    static constexpr auto name = meta::static_string{"au^-3"};
};
//---angles
template <>
struct symbol_impl<si::radian_t>
{
    static constexpr auto name = meta::static_string{"rad"};
};
template <>
struct symbol_impl<si::degree_t>
{
    static constexpr auto name = meta::static_string{"deg"};
};
//---inverse angles
template <>
struct symbol_impl<si::one_per_radian_t>
{
    static constexpr auto name = meta::static_string{"rad^-1"};
};
template <>
struct symbol_impl<si::one_per_degree_t>
{
    static constexpr auto name = meta::static_string{"deg^-1"};
};
//---time
template <>
struct symbol_impl<si::second_t>
{
    static constexpr auto name = meta::static_string{"s"};
};
template <>
struct symbol_impl<si::year_t>
{
    static constexpr auto name = meta::static_string{"yr"};
};
template <>
struct symbol_impl<si::kilo_year_t>
{
    static constexpr auto name = meta::static_string{"kyr"};
};
template <>
struct symbol_impl<si::mega_year_t>
{
    static constexpr auto name = meta::static_string{"Myr"};
};
template <>
struct symbol_impl<si::giga_year_t>
{
    static constexpr auto name = meta::static_string{"Gyr"};
};
//---frequency
template <>
struct symbol_impl<si::hertz_t>
{
    static constexpr auto name = meta::static_string{"Hz"};
};
template <>
struct symbol_impl<si::one_per_year_t>
{
    static constexpr auto name = meta::static_string{"yr^-1"};
};
template <>
struct symbol_impl<si::one_per_kilo_year_t>
{
    static constexpr auto name = meta::static_string{"kyr^-1"};
};
template <>
struct symbol_impl<si::one_per_mega_year_t>
{
    static constexpr auto name = meta::static_string{"Myr^-1"};
};
template <>
struct symbol_impl<si::one_per_giga_year_t>
{
    static constexpr auto name = meta::static_string{"Gyr^-1"};
};
//---velocity
template <>
struct symbol_impl<si::metre_per_second_t>
{
    static constexpr auto name = meta::static_string{"m s^-1"};
};
template <>
struct symbol_impl<si::kilometre_per_second_t>
{
    static constexpr auto name = meta::static_string{"km s^-1"};
};
template <>
struct symbol_impl<si::astronomical_unit_per_year_t>
{
    static constexpr auto name = meta::static_string{"au yr^-1"};
};
//---angular velocity
template <>
struct symbol_impl<si::radian_per_year_t>
{
    static constexpr auto name = meta::static_string{"rad yr^-1"};
};
template <>
struct symbol_impl<si::degree_per_year_t>
{
    static constexpr auto name = meta::static_string{"deg yr^-1"};
};
//---mass rate
template <>
struct symbol_impl<si::gram_per_year_t>
{
    static constexpr auto name = meta::static_string{"g yr^-1"};
};
template <>
struct symbol_impl<si::solar_mass_per_year_t>
{
    static constexpr auto name = meta::static_string{"MSol yr^-1"};
};
//---density
template <>
struct symbol_impl<si::gram_per_cubic_centimetre_t>
{
    static constexpr auto name = meta::static_string{"g cm^-3"};
};
//---inverse density
template <>
struct symbol_impl<si::cubic_centimetre_per_gram_t>
{
    static constexpr auto name = meta::static_string{"g^-1 cm^3"};
};
//---energy density
template <>
struct symbol_impl<si::erg_per_gram_t>
{
    static constexpr auto name = meta::static_string{"erg g^-1"};
};
//---inverse energy density
template <>
struct symbol_impl<si::gram_per_erg_t>
{
    static constexpr auto name = meta::static_string{"erg^-1 g"};
};

//---phase space
template <>
struct symbol_impl<si::lemmy_t>
{
    static constexpr auto name = meta::static_string{"rad^-1 g^-1 au^-1"};
};
template <>
struct symbol_impl<si::lemmy_gram_t>
{
    static constexpr auto name = meta::static_string{"rad^-1 au^-1"};
};
// template <> struct symbol_impl<si::lemmy_one_t> {  static constexpr auto name =
// meta::static_string{"rad^-1 g^-1 au^-1"};  };
template <>
struct symbol_impl<si::lemmy_astronomical_unit_t>
{
    static constexpr auto name = meta::static_string{"rad^-1 g^-1"};
};
template <>
struct symbol_impl<si::lemmy_degree_t>
{
    static constexpr auto name = meta::static_string{"deg rad^-1 g^-1 au^-1"};
};
template <>
struct symbol_impl<si::lemmy_radian_t>
{
    static constexpr auto name = meta::static_string{"g^-1 au^-1"};
};

template <>
struct symbol_impl<si::lemmy_per_year_t>
{
    static constexpr auto name = meta::static_string{"rad^-1 g^-1 au^-1 yr^-1"};
};
template <>
struct symbol_impl<si::lemmy_gram_per_year_t>
{
    static constexpr auto name = meta::static_string{"rad^-1 au^-1 yr^-1"};
};
// template <> struct symbol_impl<si::lemmy_one_per_year_t> {  static constexpr auto name
// = meta::static_string{"rad^-1 g^-1 au^-1 yr^-1"};  };
template <>
struct symbol_impl<si::lemmy_astronomical_unit_per_year_t>
{
    static constexpr auto name = meta::static_string{"rad^-1 g^-1 yr^-1"};
};
template <>
struct symbol_impl<si::lemmy_degree_per_year_t>
{
    static constexpr auto name = meta::static_string{"deg rad^-1 g^-1 au^-1 yr^-1"};
};
template <>
struct symbol_impl<si::lemmy_radian_per_year_t>
{
    static constexpr auto name = meta::static_string{"g^-1 au^-1 yr^-1"};
};
//---various
template <>
struct symbol_impl<si::square_gram_t>
{
    static constexpr auto name = meta::static_string{"g^2"};
};
template <>
struct symbol_impl<si::cubic_astronomical_unit_per_square_year_solar_mass_t>
{
    static constexpr auto name = meta::static_string{"MSol^-2 au^3"};
};
template <>
struct symbol_impl<si::square_astronomical_unit_per_year_t>
{
    static constexpr auto name = meta::static_string{"au^2 yr^-1"};
};
template <>
struct symbol_impl<si::square_astronomical_unit_per_square_year_t>
{
    static constexpr auto name = meta::static_string{"au^2 yr^-2"};
};
template <>
struct symbol_impl<si::gram_square_astronomical_unit_per_year_t>
{
    static constexpr auto name = meta::static_string{"g au^2 yr^-1"};
};
template <>
struct symbol_impl<si::gram_square_astronomical_unit_per_square_year_t>
{
    static constexpr auto name = meta::static_string{"g au^2 yr^-2"};
};
template <>
struct symbol_impl<si::solar_luminosity_t>
{
    static constexpr auto name = meta::static_string{"LSol"};
};
template <>
struct symbol_impl<si::steradian_t>
{
    static constexpr auto name = meta::static_string{"rad^2"};
};
template <>
struct symbol_impl<si::gram_square_astronomical_unit_steradian_per_cubic_year_t>
{
    static constexpr auto name = meta::static_string{"g au^2 rad^2 yr^-3"};
};
// template <> struct symbol_impl<si::one_per_astronomical_unit_radian_t> {  static
// constexpr auto name = meta::static_string{"au^-1 rad^-1"};  };
// //same as lemmy_gram_t
template <>
struct symbol_impl<si::square_astronomical_unit_centimetre_per_square_year_gram_t>
{
    static constexpr auto name = meta::static_string{"au^2 cm yr^-2 g^-1"};
};
template <>
struct symbol_impl<si::astronomical_unit_square_centimetre_per_square_year_solar_mass_t>
{
    static constexpr auto name = meta::static_string{"au cm^2 yr^-2 MSol^-1"};
};
template <>
struct symbol_impl<si::astronomical_unit_square_centimetre_per_square_year_t>
{
    static constexpr auto name = meta::static_string{"au cm^2 yr^-2"};
};
template <>
struct symbol_impl<si::square_astronomical_unit_square_centimetre_per_cubic_year_t>
{
    static constexpr auto name = meta::static_string{"au^2 cm^2 yr^-3"};
};
template <>
struct symbol_impl<si::gram_square_astronomical_unit_per_cubic_year_centimetre_t>
{
    static constexpr auto name = meta::static_string{"g au^2 yr-3 cm^-1"};
};
template <>
struct symbol_impl<si::gram_square_astronomical_unit_per_cubic_year_t>
{
    static constexpr auto name = meta::static_string{"g au^2 yr^-3"};
};
template <>
struct symbol_impl<si::gram_astronomical_unit_per_square_year_centimetre_t>
{
    static constexpr auto name = meta::static_string{"g au yr^-2 cm^-1"};
};
template <>
struct symbol_impl<si::solar_mass_astronomical_unit_per_square_year_t>
{
    static constexpr auto name = meta::static_string{"MSol au yr^-2"};
};
template <>
struct symbol_impl<si::astronomical_unit_square_centimetre_per_square_year_gram_t>
{
    static constexpr auto name = meta::static_string{"au cm^2 yr^-2 g^-1"};
};
template <>
struct symbol_impl<
    si::solar_mass_astronomical_unit_square_centimetre_per_square_year_gram_t>
{
    static constexpr auto name = meta::static_string{"MSol au cm^2 yr^-2 g^-1"};
};
template <>
struct symbol_impl<si::solar_mass_astronomical_unit_per_square_year_centimetre_t>
{
    static constexpr auto name = meta::static_string{"MSol au yr^-2 cm^-1"};
};
template <>
struct symbol_impl<
    si::solar_mass_square_astronomical_unit_square_centimetre_per_cubic_year_gram_t>
{
    static constexpr auto name = meta::static_string{"MSol au^2 cm^2 yr^-3 g^-1"};
};
} // namespace benri