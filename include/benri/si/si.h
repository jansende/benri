#pragma once
#include <benri/si/base.h>
#include <benri/si/extra.h>
#include <benri/si/chemical.h>

namespace benri
{
namespace si
{
using namespace benri::si::base;
#pragma region units
implement_unit(si, si, natural_unit_of_speed, _natural_unit_of_speed, dim::velocity_t, prefix::speed_of_light_t);
implement_unit(si, si, knot, _knot, dim::velocity_t, fix(impl::divide_lists_t<prefix::nautical_mile_t,prefix::hour>));
#pragma region angstroem, ...(length)
implement_unit(si, si, angstroem, _angstroem, dim::length_t, prefix::angstroem_t);
implement_unit(si, si, bohr, _bohr, dim::length_t, prefix::bohr_t);
implement_unit(si, si, nautical_mile, _nautical_mile, dim::length_t, prefix::nautical_mile_t);
implement_unit(si, si, international_mile, _international_mile, dim::length_t, prefix::international_mile_t);
implement_unit(si, si, yard, _yard, dim::length_t, prefix::yard_t);
implement_unit(si, si, international_foot, _international_foot, dim::length_t, prefix::international_foot_t);
implement_unit(si, si, inch, _inch, dim::length_t, prefix::inch_t);
#pragma endregion
#pragma region dalton, ...(mass)
implement_unit(si, si, dalton, _dalton, dim::mass_t, prefix::atomic_mass_unit_t);
link_unit(atomic_mass_unit,_atomic_mass_unit,dalton);
implement_unit(si, si, natural_unit_of_mass, _natural_unit_of_mass, dim::mass_t, prefix::electron_mass_t);
implement_unit(si, si, carat, _carat, dim::mass_t, fix(impl::multiply_lists_t<make_fraction_list_t<2>,make_power_list_t<-4>>));
implement_unit(si, si, pound, _pound, dim::mass_t, prefix::pound_t);
implement_unit(si, si, ounce, _ounce, dim::mass_t, prefix::ounce_t);
#pragma endregion
#pragma region minute, hour, ...(time)
implement_unit(si, si, minute, _minute, dim::time_t, prefix::minute);
implement_unit(si, si, hour, _hour, dim::time_t, prefix::hour);
implement_unit(si, si, day, _day, dim::time_t, prefix::day);
implement_unit(si, si, week, _week, dim::time_t, prefix::week);
implement_unit(si, si, month, _month, dim::time_t, prefix::month);
implement_unit(si, si, year, _year, dim::time_t, prefix::year);
implement_unit(si, si, kiloyear, _kiloyear, dim::time_t, fix(impl::multiply_lists_t<prefix::kilo, prefix::year>));
implement_unit(si, si, megayear, _megayear, dim::time_t, fix(impl::multiply_lists_t<prefix::mega, prefix::year>));
implement_unit(si, si, gigayear, _gigayear, dim::time_t, fix(impl::multiply_lists_t<prefix::giga, prefix::year>));
implement_unit(si, si, sidereal_year, _sidereal_year, dim::time_t, prefix::sidereal_year);
implement_unit(si, si, tropical_year, _tropical_year, dim::time_t, prefix::tropical_year);
implement_unit(si, si, natural_unit_of_time, _natural_unit_of_time, dim::time_t, fix(impl::divide_lists_t<prefix::reduced_planck_constant_t,impl::multiply_lists_t<prefix::electron_mass_t,impl::pow_list_t<prefix::speed_of_light_t,std::ratio<2>>>>));
implement_unit(si, si, atomic_unit_of_time, _atomic_unit_of_time, dim::time_t, fix(impl::divide_lists_t<prefix::reduced_planck_constant_t,prefix::hartree_energy_t>));
#pragma endregion
#pragma region square metre(area)
implement_unit(si, si, barn, _barn, dim::area_t, make_power_list_t<-28>);
implement_unit(si, si, square_picometre, _square_picometre, dim::area_t, prefix::yocto);
implement_unit(si, si, square_nanometre, _square_nanometre, dim::area_t, prefix::atto);
implement_unit(si, si, square_micrometre, _square_micrometre, dim::area_t, prefix::pico);
implement_unit(si, si, square_millimetre, _square_millimetre, dim::area_t, prefix::micro);
implement_unit(si, si, square_centimetre, _square_centimetre, dim::area_t, fix(make_fraction_list_t<1, 10000>));
implement_unit(si, si, square_decimetre, _square_decimetre, dim::area_t, prefix::centi);
implement_unit(si, si, square_metre, _square_metre, dim::area_t, prefix::one);
implement_unit(si, si, hectare, _hectare, dim::area_t, make_fraction_list_t<10000>);
implement_unit(si, si, square_kilometre, _square_kilometre, dim::area_t, prefix::mega);
#pragma endregion
#pragma region cubic metre(volume)
implement_unit(si, si, cubic_micrometre, _cubic_micrometre, dim::volume_t, prefix::atto);
implement_unit(si, si, cubic_millimetre, _cubic_millimetre, dim::volume_t, prefix::nano);
implement_unit(si, si, cubic_centimetre, _cubic_centimetre, dim::volume_t, prefix::micro);
link_unit(millilitre, _millilitre, cubic_centimetre);
implement_unit(si, si, cubic_decimetre, _cubic_decimetre, dim::volume_t, prefix::milli);
link_unit(litre, _litre, cubic_decimetre);
implement_unit(si, si, cubic_metre, _cubic_metre, dim::volume_t, prefix::one);
implement_unit(si, si, cubic_kilometre, _cubic_kilometre, dim::volume_t, prefix::giga);
#pragma endregion
#pragma region metre per second(velocity)
implement_unit(si, si, yoctometre_per_second, _yoctometre_per_second, dim::velocity_t, prefix::yocto);
implement_unit(si, si, zeptometre_per_second, _zeptometre_per_second, dim::velocity_t, prefix::zepto);
implement_unit(si, si, attometre_per_second, _attometre_per_second, dim::velocity_t, prefix::atto);
implement_unit(si, si, femtometre_per_second, _femtometre_per_second, dim::velocity_t, prefix::femto);
implement_unit(si, si, picometre_per_second, _picometre_per_second, dim::velocity_t, prefix::pico);
implement_unit(si, si, nanometre_per_second, _nanometre_per_second, dim::velocity_t, prefix::nano);
implement_unit(si, si, micrometre_per_second, _micrometre_per_second, dim::velocity_t, prefix::micro);
implement_unit(si, si, millimetre_per_second, _millimetre_per_second, dim::velocity_t, prefix::milli);
implement_unit(si, si, centimetre_per_second, _centimetre_per_second, dim::velocity_t, prefix::centi);
implement_unit(si, si, decimetre_per_second, _decimetre_per_second, dim::velocity_t, prefix::deci);
implement_unit(si, si, metre_per_second, _metre_per_second, dim::velocity_t, prefix::one);
implement_unit(si, si, decametre_per_second, _decametre_per_second, dim::velocity_t, prefix::deca);
implement_unit(si, si, hectometre_per_second, _hectometre_per_second, dim::velocity_t, prefix::hecto);
implement_unit(si, si, kilometre_per_second, _kilometre_per_second, dim::velocity_t, prefix::kilo);
implement_unit(si, si, megametre_per_second, _megametre_per_second, dim::velocity_t, prefix::mega);
implement_unit(si, si, gigametre_per_second, _gigametre_per_second, dim::velocity_t, prefix::giga);
implement_unit(si, si, terametre_per_second, _terametre_per_second, dim::velocity_t, prefix::tera);
implement_unit(si, si, petametre_per_second, _petametre_per_second, dim::velocity_t, prefix::peta);
implement_unit(si, si, exametre_per_second, _exametre_per_second, dim::velocity_t, prefix::exa);
implement_unit(si, si, zettametre_per_second, _zettametre_per_second, dim::velocity_t, prefix::zetta);
implement_unit(si, si, yottametre_per_second, _yottametre_per_second, dim::velocity_t, prefix::yotta);
#pragma endregion
#pragma region metre per minute(velocity)
implement_unit(si, si, yoctometre_per_minute, _yoctometre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::yocto, prefix::minute>));
implement_unit(si, si, zeptometre_per_minute, _zeptometre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::zepto, prefix::minute>));
implement_unit(si, si, attometre_per_minute, _attometre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::atto, prefix::minute>));
implement_unit(si, si, femtometre_per_minute, _femtometre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::femto, prefix::minute>));
implement_unit(si, si, picometre_per_minute, _picometre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::pico, prefix::minute>));
implement_unit(si, si, nanometre_per_minute, _nanometre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::nano, prefix::minute>));
implement_unit(si, si, micrometre_per_minute, _micrometre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::micro, prefix::minute>));
implement_unit(si, si, millimetre_per_minute, _millimetre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::milli, prefix::minute>));
implement_unit(si, si, centimetre_per_minute, _centimetre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::centi, prefix::minute>));
implement_unit(si, si, decimetre_per_minute, _decimetre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::deci, prefix::minute>));
implement_unit(si, si, metre_per_minute, _metre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::one, prefix::minute>));
implement_unit(si, si, decametre_per_minute, _decametre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::deca, prefix::minute>));
implement_unit(si, si, hectometre_per_minute, _hectometre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::hecto, prefix::minute>));
implement_unit(si, si, kilometre_per_minute, _kilometre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::kilo, prefix::minute>));
implement_unit(si, si, megametre_per_minute, _megametre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::mega, prefix::minute>));
implement_unit(si, si, gigametre_per_minute, _gigametre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::giga, prefix::minute>));
implement_unit(si, si, terametre_per_minute, _terametre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::tera, prefix::minute>));
implement_unit(si, si, petametre_per_minute, _petametre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::peta, prefix::minute>));
implement_unit(si, si, exametre_per_minute, _exametre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::exa, prefix::minute>));
implement_unit(si, si, zettametre_per_minute, _zettametre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::zetta, prefix::minute>));
implement_unit(si, si, yottametre_per_minute, _yottametre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::yotta, prefix::minute>));
#pragma endregion
#pragma region metre per hour(velocity)
implement_unit(si, si, yoctometre_per_hour, _yoctometre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::yocto, prefix::hour>));
implement_unit(si, si, zeptometre_per_hour, _zeptometre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::zepto, prefix::hour>));
implement_unit(si, si, attometre_per_hour, _attometre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::atto, prefix::hour>));
implement_unit(si, si, femtometre_per_hour, _femtometre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::femto, prefix::hour>));
implement_unit(si, si, picometre_per_hour, _picometre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::pico, prefix::hour>));
implement_unit(si, si, nanometre_per_hour, _nanometre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::nano, prefix::hour>));
implement_unit(si, si, micrometre_per_hour, _micrometre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::micro, prefix::hour>));
implement_unit(si, si, millimetre_per_hour, _millimetre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::milli, prefix::hour>));
implement_unit(si, si, centimetre_per_hour, _centimetre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::centi, prefix::hour>));
implement_unit(si, si, decimetre_per_hour, _decimetre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::deci, prefix::hour>));
implement_unit(si, si, metre_per_hour, _metre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::one, prefix::hour>));
implement_unit(si, si, decametre_per_hour, _decametre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::deca, prefix::hour>));
implement_unit(si, si, hectometre_per_hour, _hectometre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::hecto, prefix::hour>));
implement_unit(si, si, kilometre_per_hour, _kilometre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::kilo, prefix::hour>));
implement_unit(si, si, megametre_per_hour, _megametre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::mega, prefix::hour>));
implement_unit(si, si, gigametre_per_hour, _gigametre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::giga, prefix::hour>));
implement_unit(si, si, terametre_per_hour, _terametre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::tera, prefix::hour>));
implement_unit(si, si, petametre_per_hour, _petametre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::peta, prefix::hour>));
implement_unit(si, si, exametre_per_hour, _exametre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::exa, prefix::hour>));
implement_unit(si, si, zettametre_per_hour, _zettametre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::zetta, prefix::hour>));
implement_unit(si, si, yottametre_per_hour, _yottametre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::yotta, prefix::hour>));
#pragma endregion
#pragma region metre per square second(acceleration)
implement_unit(si, si, yoctometre_per_square_second, _yoctometre_per_square_second, dim::acceleration_t, prefix::yocto);
implement_unit(si, si, zeptometre_per_square_second, _zeptometre_per_square_second, dim::acceleration_t, prefix::zepto);
implement_unit(si, si, attometre_per_square_second, _attometre_per_square_second, dim::acceleration_t, prefix::atto);
implement_unit(si, si, femtometre_per_square_second, _femtometre_per_square_second, dim::acceleration_t, prefix::femto);
implement_unit(si, si, picometre_per_square_second, _picometre_per_square_second, dim::acceleration_t, prefix::pico);
implement_unit(si, si, nanometre_per_square_second, _nanometre_per_square_second, dim::acceleration_t, prefix::nano);
implement_unit(si, si, micrometre_per_square_second, _micrometre_per_square_second, dim::acceleration_t, prefix::micro);
implement_unit(si, si, millimetre_per_square_second, _millimetre_per_square_second, dim::acceleration_t, prefix::milli);
implement_unit(si, si, centimetre_per_square_second, _centimetre_per_square_second, dim::acceleration_t, prefix::centi);
implement_unit(si, si, decimetre_per_square_second, _decimetre_per_square_second, dim::acceleration_t, prefix::deci);
implement_unit(si, si, metre_per_square_second, _metre_per_square_second, dim::acceleration_t, prefix::one);
implement_unit(si, si, decametre_per_square_second, _decametre_per_square_second, dim::acceleration_t, prefix::deca);
implement_unit(si, si, hectometre_per_square_second, _hectometre_per_square_second, dim::acceleration_t, prefix::hecto);
implement_unit(si, si, kilometre_per_square_second, _kilometre_per_square_second, dim::acceleration_t, prefix::kilo);
implement_unit(si, si, megametre_per_square_second, _megametre_per_square_second, dim::acceleration_t, prefix::mega);
implement_unit(si, si, gigametre_per_square_second, _gigametre_per_square_second, dim::acceleration_t, prefix::giga);
implement_unit(si, si, terametre_per_square_second, _terametre_per_square_second, dim::acceleration_t, prefix::tera);
implement_unit(si, si, petametre_per_square_second, _petametre_per_square_second, dim::acceleration_t, prefix::peta);
implement_unit(si, si, exametre_per_square_second, _exametre_per_square_second, dim::acceleration_t, prefix::exa);
implement_unit(si, si, zettametre_per_square_second, _zettametre_per_square_second, dim::acceleration_t, prefix::zetta);
implement_unit(si, si, yottametre_per_square_second, _yottametre_per_square_second, dim::acceleration_t, prefix::yotta);
#pragma endregion
#pragma region metre per square minute(acceleration)
implement_unit(si, si, yoctometre_per_square_minute, _yoctometre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::yocto, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, zeptometre_per_square_minute, _zeptometre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::zepto, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, attometre_per_square_minute, _attometre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::atto, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, femtometre_per_square_minute, _femtometre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::femto, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, picometre_per_square_minute, _picometre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::pico, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, nanometre_per_square_minute, _nanometre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::nano, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, micrometre_per_square_minute, _micrometre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::micro, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, millimetre_per_square_minute, _millimetre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::milli, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, centimetre_per_square_minute, _centimetre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::centi, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, decimetre_per_square_minute, _decimetre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::deci, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, metre_per_square_minute, _metre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::one, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, decametre_per_square_minute, _decametre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::deca, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, hectometre_per_square_minute, _hectometre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::hecto, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, kilometre_per_square_minute, _kilometre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::kilo, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, megametre_per_square_minute, _megametre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::mega, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, gigametre_per_square_minute, _gigametre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::giga, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, terametre_per_square_minute, _terametre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::tera, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, petametre_per_square_minute, _petametre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::peta, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, exametre_per_square_minute, _exametre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::exa, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, zettametre_per_square_minute, _zettametre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::zetta, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, yottametre_per_square_minute, _yottametre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::yotta, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
#pragma endregion
#pragma region metre per square hour(acceleration)
implement_unit(si, si, yoctometre_per_square_hour, _yoctometre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::yocto, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, zeptometre_per_square_hour, _zeptometre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::zepto, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, attometre_per_square_hour, _attometre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::atto, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, femtometre_per_square_hour, _femtometre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::femto, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, picometre_per_square_hour, _picometre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::pico, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, nanometre_per_square_hour, _nanometre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::nano, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, micrometre_per_square_hour, _micrometre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::micro, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, millimetre_per_square_hour, _millimetre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::milli, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, centimetre_per_square_hour, _centimetre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::centi, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, decimetre_per_square_hour, _decimetre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::deci, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, metre_per_square_hour, _metre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::one, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, decametre_per_square_hour, _decametre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::deca, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, hectometre_per_square_hour, _hectometre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::hecto, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, kilometre_per_square_hour, _kilometre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::kilo, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, megametre_per_square_hour, _megametre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::mega, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, gigametre_per_square_hour, _gigametre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::giga, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, terametre_per_square_hour, _terametre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::tera, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, petametre_per_square_hour, _petametre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::peta, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, exametre_per_square_hour, _exametre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::exa, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, zettametre_per_square_hour, _zettametre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::zetta, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, yottametre_per_square_hour, _yottametre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::yotta, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
#pragma endregion
#pragma region one per metre(wavenumber)
implement_unit(si, si, one_per_yoctometre, _one_per_yoctometre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::yocto>));
implement_unit(si, si, one_per_zeptometre, _one_per_zeptometre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::zepto>));
implement_unit(si, si, one_per_attometre, _one_per_attometre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::atto>));
implement_unit(si, si, one_per_femtometre, _one_per_femtometre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::femto>));
implement_unit(si, si, one_per_picometre, _one_per_picometre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::pico>));
implement_unit(si, si, one_per_nanometre, _one_per_nanometre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::nano>));
implement_unit(si, si, one_per_micrometre, _one_per_micrometre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::micro>));
implement_unit(si, si, one_per_millimetre, _one_per_millimetre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::milli>));
implement_unit(si, si, one_per_centimetre, _one_per_centimetre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::centi>));
implement_unit(si, si, one_per_decimetre, _one_per_decimetre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::deci>));
implement_unit(si, si, one_per_metre, _one_per_metre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::one>));
implement_unit(si, si, one_per_decametre, _one_per_decametre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::deca>));
implement_unit(si, si, one_per_hectometre, _one_per_hectometre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::hecto>));
implement_unit(si, si, one_per_kilometre, _one_per_kilometre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::kilo>));
implement_unit(si, si, one_per_megametre, _one_per_megametre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::mega>));
implement_unit(si, si, one_per_gigametre, _one_per_gigametre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::giga>));
implement_unit(si, si, one_per_terametre, _one_per_terametre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::tera>));
implement_unit(si, si, one_per_petametre, _one_per_petametre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::peta>));
implement_unit(si, si, one_per_exametre, _one_per_exametre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::exa>));
implement_unit(si, si, one_per_zettametre, _one_per_zettametre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::zetta>));
implement_unit(si, si, one_per_yottametre, _one_per_yottametre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::yotta>));
#pragma endregion
#pragma region kilogram per cubic metre(density)
implement_unit(si, si, yoctogram_per_cubic_metre, _yoctogram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::yocto, prefix::milli>));
implement_unit(si, si, zeptogram_per_cubic_metre, _zeptogram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::zepto, prefix::milli>));
implement_unit(si, si, attogram_per_cubic_metre, _attogram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::atto, prefix::milli>));
implement_unit(si, si, femtogram_per_cubic_metre, _femtogram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::femto, prefix::milli>));
implement_unit(si, si, picogram_per_cubic_metre, _picogram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::pico, prefix::milli>));
implement_unit(si, si, nanogram_per_cubic_metre, _nanogram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::nano, prefix::milli>));
implement_unit(si, si, microgram_per_cubic_metre, _microgram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::micro, prefix::milli>));
implement_unit(si, si, milligram_per_cubic_metre, _milligram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::milli, prefix::milli>));
implement_unit(si, si, centigram_per_cubic_metre, _centigram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::centi, prefix::milli>));
implement_unit(si, si, decigram_per_cubic_metre, _decigram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::deci, prefix::milli>));
implement_unit(si, si, gram_per_cubic_metre, _gram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::one, prefix::milli>));
implement_unit(si, si, decagram_per_cubic_metre, _decagram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::deca, prefix::milli>));
implement_unit(si, si, hectogram_per_cubic_metre, _hectogram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::hecto, prefix::milli>));
implement_unit(si, si, kilogram_per_cubic_metre, _kilogram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::kilo, prefix::milli>));
implement_unit(si, si, megagram_per_cubic_metre, _megagram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::mega, prefix::milli>));
link_unit(tonne_per_cubic_metre, _tonne_per_cubic_metre, megagram_per_cubic_metre);
implement_unit(si, si, gigagram_per_cubic_metre, _gigagram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::giga, prefix::milli>));
link_unit(kilotonne_per_cubic_metre, _kilotonne_per_cubic_metre, gigagram_per_cubic_metre);
implement_unit(si, si, teragram_per_cubic_metre, _teragram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::tera, prefix::milli>));
link_unit(megatonne_per_cubic_metre, _megatonne_per_cubic_metre, teragram_per_cubic_metre);
implement_unit(si, si, petagram_per_cubic_metre, _petagram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::peta, prefix::milli>));
link_unit(gigatonne_per_cubic_metre, _gigatonne_per_cubic_metre, petagram_per_cubic_metre);
implement_unit(si, si, exagram_per_cubic_metre, _exagram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::exa, prefix::milli>));
implement_unit(si, si, zettagram_per_cubic_metre, _zettagram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::zetta, prefix::milli>));
implement_unit(si, si, yottagram_per_cubic_metre, _yottagram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::yotta, prefix::milli>));
#pragma endregion
#pragma region kilogram per cubic decimetre(density)
link_unit(yoctogram_per_cubic_decimetre, _yoctogram_per_cubic_decimetre, zeptogram_per_cubic_metre);
link_unit(zeptogram_per_cubic_decimetre, _zeptogram_per_cubic_decimetre, attogram_per_cubic_metre);
link_unit(attogram_per_cubic_decimetre, _attogram_per_cubic_decimetre, femtogram_per_cubic_metre);
link_unit(femtogram_per_cubic_decimetre, _femtogram_per_cubic_decimetre, picogram_per_cubic_metre);
link_unit(picogram_per_cubic_decimetre, _picogram_per_cubic_decimetre, nanogram_per_cubic_metre);
link_unit(nanogram_per_cubic_decimetre, _nanogram_per_cubic_decimetre, microgram_per_cubic_metre);
link_unit(microgram_per_cubic_decimetre, _microgram_per_cubic_decimetre, milligram_per_cubic_metre);
link_unit(milligram_per_cubic_decimetre, _milligram_per_cubic_decimetre, gram_per_cubic_metre);
link_unit(centigram_per_cubic_decimetre, _centigram_per_cubic_decimetre, decagram_per_cubic_metre);
link_unit(decigram_per_cubic_decimetre, _decigram_per_cubic_decimetre, hectogram_per_cubic_metre);
link_unit(gram_per_cubic_decimetre, _gram_per_cubic_decimetre, kilogram_per_cubic_metre);
implement_unit(si, si, decagram_per_cubic_decimetre, _decagram_per_cubic_decimetre, dim::density_t, fix(impl::multiply_lists_t<prefix::kilo, impl::multiply_lists_t<prefix::deca, prefix::milli>>));
implement_unit(si, si, hectogram_per_cubic_decimetre, _hectogram_per_cubic_decimetre, dim::density_t, fix(impl::multiply_lists_t<prefix::kilo, impl::multiply_lists_t<prefix::hecto, prefix::milli>>));
link_unit(kilogram_per_cubic_decimetre, _kilogram_per_cubic_decimetre, megagram_per_cubic_metre);
link_unit(megagram_per_cubic_decimetre, _megagram_per_cubic_decimetre, gigagram_per_cubic_metre);
link_unit(tonne_per_cubic_decimetre, _tonne_per_cubic_decimetre, megagram_per_cubic_decimetre);
link_unit(gigagram_per_cubic_decimetre, _gigagram_per_cubic_decimetre, teragram_per_cubic_metre);
link_unit(kilotonne_per_cubic_decimetre, _kilotonne_per_cubic_decimetre, gigagram_per_cubic_decimetre);
link_unit(teragram_per_cubic_decimetre, _teragram_per_cubic_decimetre, petagram_per_cubic_metre);
link_unit(megatonne_per_cubic_decimetre, _megatonne_per_cubic_decimetre, teragram_per_cubic_decimetre);
link_unit(petagram_per_cubic_decimetre, _petagram_per_cubic_decimetre, exagram_per_cubic_metre);
link_unit(gigatonne_per_cubic_decimetre, _gigatonne_per_cubic_decimetre, petagram_per_cubic_decimetre);
link_unit(exagram_per_cubic_decimetre, _exagram_per_cubic_decimetre, zettagram_per_cubic_metre);
link_unit(zettagram_per_cubic_decimetre, _zettagram_per_cubic_decimetre, yottagram_per_cubic_metre);
implement_unit(si, si, yottagram_per_cubic_decimetre, _yottagram_per_cubic_decimetre, dim::density_t, fix(impl::multiply_lists_t<prefix::kilo, impl::multiply_lists_t<prefix::yotta, prefix::milli>>));
#pragma endregion
#pragma region kilogram per litre(density)
link_unit(yoctogram_per_litre, _yoctogram_per_litre, yoctogram_per_cubic_decimetre);
link_unit(zeptogram_per_litre, _zeptogram_per_litre, zeptogram_per_cubic_decimetre);
link_unit(attogram_per_litre, _attogram_per_litre, attogram_per_cubic_decimetre);
link_unit(femtogram_per_litre, _femtogram_per_litre, femtogram_per_cubic_decimetre);
link_unit(picogram_per_litre, _picogram_per_litre, picogram_per_cubic_decimetre);
link_unit(nanogram_per_litre, _nanogram_per_litre, nanogram_per_cubic_decimetre);
link_unit(microgram_per_litre, _microgram_per_litre, microgram_per_cubic_decimetre);
link_unit(milligram_per_litre, _milligram_per_litre, milligram_per_cubic_decimetre);
link_unit(centigram_per_litre, _centigram_per_litre, centigram_per_cubic_decimetre);
link_unit(decigram_per_litre, _decigram_per_litre, decigram_per_cubic_decimetre);
link_unit(gram_per_litre, _gram_per_litre, gram_per_cubic_decimetre);
link_unit(decagram_per_litre, _decagram_per_litre, decagram_per_cubic_decimetre);
link_unit(hectogram_per_litre, _hectogram_per_litre, hectogram_per_cubic_decimetre);
link_unit(kilogram_per_litre, _kilogram_per_litre, kilogram_per_cubic_decimetre);
link_unit(megagram_per_litre, _megagram_per_litre, megagram_per_cubic_decimetre);
link_unit(tonne_per_litre, _tonne_per_litre, tonne_per_cubic_decimetre);
link_unit(gigagram_per_litre, _gigagram_per_litre, gigagram_per_cubic_decimetre);
link_unit(kilotonne_per_litre, _kilotonne_per_litre, kilotonne_per_cubic_decimetre);
link_unit(teragram_per_litre, _teragram_per_litre, teragram_per_cubic_decimetre);
link_unit(megatonne_per_litre, _megatonne_per_litre, megatonne_per_cubic_decimetre);
link_unit(petagram_per_litre, _petagram_per_litre, petagram_per_cubic_decimetre);
link_unit(gigatonne_per_litre, _gigatonne_per_litre, gigatonne_per_cubic_decimetre);
link_unit(exagram_per_litre, _exagram_per_litre, exagram_per_cubic_decimetre);
link_unit(zettagram_per_litre, _zettagram_per_litre, zettagram_per_cubic_decimetre);
link_unit(yottagram_per_litre, _yottagram_per_litre, yottagram_per_cubic_decimetre);
#pragma endregion
#pragma region kilogram per cubic centimetre(density)
link_unit(yoctogram_per_cubic_centimetre, _yoctogram_per_cubic_centimetre, attogram_per_cubic_metre);
link_unit(zeptogram_per_cubic_centimetre, _zeptogram_per_cubic_centimetre, femtogram_per_cubic_metre);
link_unit(attogram_per_cubic_centimetre, _attogram_per_cubic_centimetre, picogram_per_cubic_metre);
link_unit(femtogram_per_cubic_centimetre, _femtogram_per_cubic_centimetre, nanogram_per_cubic_metre);
link_unit(picogram_per_cubic_centimetre, _picogram_per_cubic_centimetre, microgram_per_cubic_metre);
link_unit(nanogram_per_cubic_centimetre, _nanogram_per_cubic_centimetre, milligram_per_cubic_metre);
link_unit(microgram_per_cubic_centimetre, _microgram_per_cubic_centimetre, gram_per_cubic_metre);
link_unit(milligram_per_cubic_centimetre, _milligram_per_cubic_centimetre, kilogram_per_cubic_metre);
link_unit(centigram_per_cubic_centimetre, _centigram_per_cubic_centimetre, decagram_per_cubic_decimetre);
link_unit(decigram_per_cubic_centimetre, _decigram_per_cubic_centimetre, hectogram_per_cubic_decimetre);
link_unit(gram_per_cubic_centimetre, _gram_per_cubic_centimetre, megagram_per_cubic_metre);
implement_unit(si, si, decagram_per_cubic_centimetre, _decagram_per_cubic_centimetre, dim::density_t, fix(impl::multiply_lists_t<prefix::mega, impl::multiply_lists_t<prefix::deca, prefix::milli>>));
implement_unit(si, si, hectogram_per_cubic_centimetre, _hectogram_per_cubic_centimetre, dim::density_t, fix(impl::multiply_lists_t<prefix::mega, impl::multiply_lists_t<prefix::hecto, prefix::milli>>));
link_unit(kilogram_per_cubic_centimetre, _kilogram_per_cubic_centimetre, gigagram_per_cubic_metre);
link_unit(megagram_per_cubic_centimetre, _megagram_per_cubic_centimetre, teragram_per_cubic_metre);
link_unit(tonne_per_cubic_centimetre, _tonne_per_cubic_centimetre, megagram_per_cubic_centimetre);
link_unit(gigagram_per_cubic_centimetre, _gigagram_per_cubic_centimetre, petagram_per_cubic_metre);
link_unit(kilotonne_per_cubic_centimetre, _kilotonne_per_cubic_centimetre, gigagram_per_cubic_centimetre);
link_unit(teragram_per_cubic_centimetre, _teragram_per_cubic_centimetre, exagram_per_cubic_metre);
link_unit(megatonne_per_cubic_centimetre, _megatonne_per_cubic_centimetre, teragram_per_cubic_centimetre);
link_unit(petagram_per_cubic_centimetre, _petagram_per_cubic_centimetre, zettagram_per_cubic_metre);
link_unit(gigatonne_per_cubic_centimetre, _gigatonne_per_cubic_centimetre, petagram_per_cubic_centimetre);
link_unit(exagram_per_cubic_centimetre, _exagram_per_cubic_centimetre, yottagram_per_cubic_metre);
link_unit(zettagram_per_cubic_centimetre, _zettagram_per_cubic_centimetre, yottagram_per_cubic_decimetre);
implement_unit(si, si, yottagram_per_cubic_centimetre, _yottagram_per_cubic_centimetre, dim::density_t, fix(impl::multiply_lists_t<prefix::mega, impl::multiply_lists_t<prefix::yotta, prefix::milli>>));
#pragma endregion
#pragma region kilogram per millilitre(density)
link_unit(yoctogram_per_millilitre, _yoctogram_per_millilitre, yoctogram_per_cubic_centimetre);
link_unit(zeptogram_per_millilitre, _zeptogram_per_millilitre, zeptogram_per_cubic_centimetre);
link_unit(attogram_per_millilitre, _attogram_per_millilitre, attogram_per_cubic_centimetre);
link_unit(femtogram_per_millilitre, _femtogram_per_millilitre, femtogram_per_cubic_centimetre);
link_unit(picogram_per_millilitre, _picogram_per_millilitre, picogram_per_cubic_centimetre);
link_unit(nanogram_per_millilitre, _nanogram_per_millilitre, nanogram_per_cubic_centimetre);
link_unit(microgram_per_millilitre, _microgram_per_millilitre, microgram_per_cubic_centimetre);
link_unit(milligram_per_millilitre, _milligram_per_millilitre, milligram_per_cubic_centimetre);
link_unit(centigram_per_millilitre, _centigram_per_millilitre, centigram_per_cubic_centimetre);
link_unit(decigram_per_millilitre, _decigram_per_millilitre, decigram_per_cubic_centimetre);
link_unit(gram_per_millilitre, _gram_per_millilitre, gram_per_cubic_centimetre);
link_unit(decagram_per_millilitre, _decagram_per_millilitre, decagram_per_cubic_centimetre);
link_unit(hectogram_per_millilitre, _hectogram_per_millilitre, hectogram_per_cubic_centimetre);
link_unit(kilogram_per_millilitre, _kilogram_per_millilitre, kilogram_per_cubic_centimetre);
link_unit(megagram_per_millilitre, _megagram_per_millilitre, megagram_per_cubic_centimetre);
link_unit(tonne_per_millilitre, _tonne_per_millilitre, tonne_per_cubic_centimetre);
link_unit(gigagram_per_millilitre, _gigagram_per_millilitre, gigagram_per_cubic_centimetre);
link_unit(kilotonne_per_millilitre, _kilotonne_per_millilitre, kilotonne_per_cubic_centimetre);
link_unit(teragram_per_millilitre, _teragram_per_millilitre, teragram_per_cubic_centimetre);
link_unit(megatonne_per_millilitre, _megatonne_per_millilitre, megatonne_per_cubic_centimetre);
link_unit(petagram_per_millilitre, _petagram_per_millilitre, petagram_per_cubic_centimetre);
link_unit(gigatonne_per_millilitre, _gigatonne_per_millilitre, gigatonne_per_cubic_centimetre);
link_unit(exagram_per_millilitre, _exagram_per_millilitre, exagram_per_cubic_centimetre);
link_unit(zettagram_per_millilitre, _zettagram_per_millilitre, zettagram_per_cubic_centimetre);
link_unit(yottagram_per_millilitre, _yottagram_per_millilitre, yottagram_per_cubic_centimetre);
#pragma endregion
#pragma region kilogram per square metre(area density)
implement_unit(si, si, yoctogram_per_square_metre, _yoctogram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::yocto, prefix::milli>));
implement_unit(si, si, zeptogram_per_square_metre, _zeptogram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::zepto, prefix::milli>));
implement_unit(si, si, attogram_per_square_metre, _attogram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::atto, prefix::milli>));
implement_unit(si, si, femtogram_per_square_metre, _femtogram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::femto, prefix::milli>));
implement_unit(si, si, picogram_per_square_metre, _picogram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::pico, prefix::milli>));
implement_unit(si, si, nanogram_per_square_metre, _nanogram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::nano, prefix::milli>));
implement_unit(si, si, microgram_per_square_metre, _microgram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::micro, prefix::milli>));
implement_unit(si, si, milligram_per_square_metre, _milligram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::milli, prefix::milli>));
implement_unit(si, si, centigram_per_square_metre, _centigram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::centi, prefix::milli>));
implement_unit(si, si, decigram_per_square_metre, _decigram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::deci, prefix::milli>));
implement_unit(si, si, gram_per_square_metre, _gram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::one, prefix::milli>));
implement_unit(si, si, decagram_per_square_metre, _decagram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::deca, prefix::milli>));
implement_unit(si, si, hectogram_per_square_metre, _hectogram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::hecto, prefix::milli>));
implement_unit(si, si, kilogram_per_square_metre, _kilogram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::kilo, prefix::milli>));
implement_unit(si, si, megagram_per_square_metre, _megagram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::mega, prefix::milli>));
link_unit(tonne_per_square_metre, _tonne_per_square_metre, megagram_per_square_metre);
implement_unit(si, si, gigagram_per_square_metre, _gigagram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::giga, prefix::milli>));
link_unit(kilotonne_per_square_metre, _kilotonne_per_square_metre, gigagram_per_square_metre);
implement_unit(si, si, teragram_per_square_metre, _teragram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::tera, prefix::milli>));
link_unit(megatonne_per_square_metre, _megatonne_per_square_metre, teragram_per_square_metre);
implement_unit(si, si, petagram_per_square_metre, _petagram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::peta, prefix::milli>));
link_unit(gigatonne_per_square_metre, _gigatonne_per_square_metre, petagram_per_square_metre);
implement_unit(si, si, exagram_per_square_metre, _exagram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::exa, prefix::milli>));
implement_unit(si, si, zettagram_per_square_metre, _zettagram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::zetta, prefix::milli>));
implement_unit(si, si, yottagram_per_square_metre, _yottagram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::yotta, prefix::milli>));
#pragma endregion
#pragma region cubic metre per kilogram(specific volume)
implement_unit(si, si, cubic_micrometre_per_kilogram, _cubic_micrometre_per_kilogram, dim::specific_volume_t, prefix::atto);
implement_unit(si, si, cubic_millimetre_per_kilogram, _cubic_millimetre_per_kilogram, dim::specific_volume_t, prefix::nano);
implement_unit(si, si, cubic_centimetre_per_kilogram, _cubic_centimetre_per_kilogram, dim::specific_volume_t, prefix::micro);
link_unit(millilitre_per_kilogram, _millilitre_per_kilogram, cubic_centimetre_per_kilogram);
implement_unit(si, si, cubic_decimetre_per_kilogram, _cubic_decimetre_per_kilogram, dim::specific_volume_t, prefix::milli);
link_unit(litre_per_kilogram, _litre_per_kilogram, cubic_decimetre_per_kilogram);
implement_unit(si, si, cubic_metre_per_kilogram, _cubic_metre_per_kilogram, dim::specific_volume_t, prefix::one);
implement_unit(si, si, cubic_kilometre_per_kilogram, _cubic_kilometre_per_kilogram, dim::specific_volume_t, prefix::giga);
#pragma endregion
#pragma region ampere per square metre(current density)
implement_unit(si, si, yoctoampere_per_square_metre, _yoctoampere_per_square_metre, dim::current_density_t, prefix::yocto);
implement_unit(si, si, zeptoampere_per_square_metre, _zeptoampere_per_square_metre, dim::current_density_t, prefix::zepto);
implement_unit(si, si, attoampere_per_square_metre, _attoampere_per_square_metre, dim::current_density_t, prefix::atto);
implement_unit(si, si, femtoampere_per_square_metre, _femtoampere_per_square_metre, dim::current_density_t, prefix::femto);
implement_unit(si, si, picoampere_per_square_metre, _picoampere_per_square_metre, dim::current_density_t, prefix::pico);
implement_unit(si, si, nanoampere_per_square_metre, _nanoampere_per_square_metre, dim::current_density_t, prefix::nano);
implement_unit(si, si, microampere_per_square_metre, _microampere_per_square_metre, dim::current_density_t, prefix::micro);
implement_unit(si, si, milliampere_per_square_metre, _milliampere_per_square_metre, dim::current_density_t, prefix::milli);
implement_unit(si, si, centiampere_per_square_metre, _centiampere_per_square_metre, dim::current_density_t, prefix::centi);
implement_unit(si, si, deciampere_per_square_metre, _deciampere_per_square_metre, dim::current_density_t, prefix::deci);
implement_unit(si, si, ampere_per_square_metre, _ampere_per_square_metre, dim::current_density_t, prefix::one);
implement_unit(si, si, decaampere_per_square_metre, _decaampere_per_square_metre, dim::current_density_t, prefix::deca);
implement_unit(si, si, hectoampere_per_square_metre, _hectoampere_per_square_metre, dim::current_density_t, prefix::hecto);
implement_unit(si, si, kiloampere_per_square_metre, _kiloampere_per_square_metre, dim::current_density_t, prefix::kilo);
implement_unit(si, si, megaampere_per_square_metre, _megaampere_per_square_metre, dim::current_density_t, prefix::mega);
implement_unit(si, si, gigaampere_per_square_metre, _gigaampere_per_square_metre, dim::current_density_t, prefix::giga);
implement_unit(si, si, teraampere_per_square_metre, _teraampere_per_square_metre, dim::current_density_t, prefix::tera);
implement_unit(si, si, petaampere_per_square_metre, _petaampere_per_square_metre, dim::current_density_t, prefix::peta);
implement_unit(si, si, exaampere_per_square_metre, _exaampere_per_square_metre, dim::current_density_t, prefix::exa);
implement_unit(si, si, zettaampere_per_square_metre, _zettaampere_per_square_metre, dim::current_density_t, prefix::zetta);
implement_unit(si, si, yottaampere_per_square_metre, _yottaampere_per_square_metre, dim::current_density_t, prefix::yotta);
#pragma endregion
#pragma region ampere per metre(magnetic field strength)
implement_unit(si, si, yoctoampere_per_metre, _yoctoampere_per_metre, dim::magnetic_field_strength_t, prefix::yocto);
implement_unit(si, si, zeptoampere_per_metre, _zeptoampere_per_metre, dim::magnetic_field_strength_t, prefix::zepto);
implement_unit(si, si, attoampere_per_metre, _attoampere_per_metre, dim::magnetic_field_strength_t, prefix::atto);
implement_unit(si, si, femtoampere_per_metre, _femtoampere_per_metre, dim::magnetic_field_strength_t, prefix::femto);
implement_unit(si, si, picoampere_per_metre, _picoampere_per_metre, dim::magnetic_field_strength_t, prefix::pico);
implement_unit(si, si, nanoampere_per_metre, _nanoampere_per_metre, dim::magnetic_field_strength_t, prefix::nano);
implement_unit(si, si, microampere_per_metre, _microampere_per_metre, dim::magnetic_field_strength_t, prefix::micro);
implement_unit(si, si, milliampere_per_metre, _milliampere_per_metre, dim::magnetic_field_strength_t, prefix::milli);
implement_unit(si, si, centiampere_per_metre, _centiampere_per_metre, dim::magnetic_field_strength_t, prefix::centi);
implement_unit(si, si, deciampere_per_metre, _deciampere_per_metre, dim::magnetic_field_strength_t, prefix::deci);
implement_unit(si, si, ampere_per_metre, _ampere_per_metre, dim::magnetic_field_strength_t, prefix::one);
implement_unit(si, si, decaampere_per_metre, _decaampere_per_metre, dim::magnetic_field_strength_t, prefix::deca);
implement_unit(si, si, hectoampere_per_metre, _hectoampere_per_metre, dim::magnetic_field_strength_t, prefix::hecto);
implement_unit(si, si, kiloampere_per_metre, _kiloampere_per_metre, dim::magnetic_field_strength_t, prefix::kilo);
implement_unit(si, si, megaampere_per_metre, _megaampere_per_metre, dim::magnetic_field_strength_t, prefix::mega);
implement_unit(si, si, gigaampere_per_metre, _gigaampere_per_metre, dim::magnetic_field_strength_t, prefix::giga);
implement_unit(si, si, teraampere_per_metre, _teraampere_per_metre, dim::magnetic_field_strength_t, prefix::tera);
implement_unit(si, si, petaampere_per_metre, _petaampere_per_metre, dim::magnetic_field_strength_t, prefix::peta);
implement_unit(si, si, exaampere_per_metre, _exaampere_per_metre, dim::magnetic_field_strength_t, prefix::exa);
implement_unit(si, si, zettaampere_per_metre, _zettaampere_per_metre, dim::magnetic_field_strength_t, prefix::zetta);
implement_unit(si, si, yottaampere_per_metre, _yottaampere_per_metre, dim::magnetic_field_strength_t, prefix::yotta);
#pragma endregion
#pragma region mole per cubic metre(concentration)
implement_unit(si, si, mole_per_cubic_micrometre, _mole_per_cubic_micrometre, dim::concentration_t, fix(impl::divide_lists_t<prefix::one, prefix::atto>));
implement_unit(si, si, mole_per_cubic_millimetre, _mole_per_cubic_millimetre, dim::concentration_t, fix(impl::divide_lists_t<prefix::one, prefix::nano>));
implement_unit(si, si, mole_per_cubic_centimetre, _mole_per_cubic_centimetre, dim::concentration_t, fix(impl::divide_lists_t<prefix::one, prefix::micro>));
link_unit(mole_per_millilitre, _mole_per_millilitre, mole_per_cubic_centimetre);
implement_unit(si, si, mole_per_cubic_decimetre, _mole_per_cubic_decimetre, dim::concentration_t, fix(impl::divide_lists_t<prefix::one, prefix::milli>));
link_unit(mole_per_litre, _mole_per_litre, mole_per_cubic_decimetre);
implement_unit(si, si, mole_per_cubic_metre, _mole_per_cubic_metre, dim::concentration_t, fix(impl::divide_lists_t<prefix::one, prefix::one>));
implement_unit(si, si, mole_per_cubic_kilometre, _mole_per_cubic_kilometre, dim::concentration_t, fix(impl::divide_lists_t<prefix::one, prefix::giga>));
#pragma endregion
#pragma region candela per square metre(luminance)
implement_unit(si, si, yoctocandela_per_square_metre, _yoctocandela_per_square_metre, dim::luminance_t, prefix::yocto);
implement_unit(si, si, zeptocandela_per_square_metre, _zeptocandela_per_square_metre, dim::luminance_t, prefix::zepto);
implement_unit(si, si, attocandela_per_square_metre, _attocandela_per_square_metre, dim::luminance_t, prefix::atto);
implement_unit(si, si, femtocandela_per_square_metre, _femtocandela_per_square_metre, dim::luminance_t, prefix::femto);
implement_unit(si, si, picocandela_per_square_metre, _picocandela_per_square_metre, dim::luminance_t, prefix::pico);
implement_unit(si, si, nanocandela_per_square_metre, _nanocandela_per_square_metre, dim::luminance_t, prefix::nano);
implement_unit(si, si, microcandela_per_square_metre, _microcandela_per_square_metre, dim::luminance_t, prefix::micro);
implement_unit(si, si, millicandela_per_square_metre, _millicandela_per_square_metre, dim::luminance_t, prefix::milli);
implement_unit(si, si, centicandela_per_square_metre, _centicandela_per_square_metre, dim::luminance_t, prefix::centi);
implement_unit(si, si, decicandela_per_square_metre, _decicandela_per_square_metre, dim::luminance_t, prefix::deci);
implement_unit(si, si, candela_per_square_metre, _candela_per_square_metre, dim::luminance_t, prefix::one);
implement_unit(si, si, decacandela_per_square_metre, _decacandela_per_square_metre, dim::luminance_t, prefix::deca);
implement_unit(si, si, hectocandela_per_square_metre, _hectocandela_per_square_metre, dim::luminance_t, prefix::hecto);
implement_unit(si, si, kilocandela_per_square_metre, _kilocandela_per_square_metre, dim::luminance_t, prefix::kilo);
implement_unit(si, si, megacandela_per_square_metre, _megacandela_per_square_metre, dim::luminance_t, prefix::mega);
implement_unit(si, si, gigacandela_per_square_metre, _gigacandela_per_square_metre, dim::luminance_t, prefix::giga);
implement_unit(si, si, teracandela_per_square_metre, _teracandela_per_square_metre, dim::luminance_t, prefix::tera);
implement_unit(si, si, petacandela_per_square_metre, _petacandela_per_square_metre, dim::luminance_t, prefix::peta);
implement_unit(si, si, exacandela_per_square_metre, _exacandela_per_square_metre, dim::luminance_t, prefix::exa);
implement_unit(si, si, zettacandela_per_square_metre, _zettacandela_per_square_metre, dim::luminance_t, prefix::zetta);
implement_unit(si, si, yottacandela_per_square_metre, _yottacandela_per_square_metre, dim::luminance_t, prefix::yotta);
#pragma endregion
#pragma region plane angle
implement_unit(si, si, gon, _gon, dim::plane_angle_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 200>>));
implement_unit(si, si, revolution, _revolution, dim::plane_angle_t, prefix::two_pi_t);
#pragma endregion
#pragma region solid angle
implement_unit(si, si, steradian, _steradian, dim::solid_angle_t, prefix::one);
#pragma endregion
#pragma region hertz(frequency)
implement_unit(si, si, yoctohertz, _yoctohertz, dim::frequency_t, prefix::yocto);
implement_unit(si, si, zeptohertz, _zeptohertz, dim::frequency_t, prefix::zepto);
implement_unit(si, si, attohertz, _attohertz, dim::frequency_t, prefix::atto);
implement_unit(si, si, femtohertz, _femtohertz, dim::frequency_t, prefix::femto);
implement_unit(si, si, picohertz, _picohertz, dim::frequency_t, prefix::pico);
implement_unit(si, si, nanohertz, _nanohertz, dim::frequency_t, prefix::nano);
implement_unit(si, si, microhertz, _microhertz, dim::frequency_t, prefix::micro);
implement_unit(si, si, millihertz, _millihertz, dim::frequency_t, prefix::milli);
implement_unit(si, si, centihertz, _centihertz, dim::frequency_t, prefix::centi);
implement_unit(si, si, decihertz, _decihertz, dim::frequency_t, prefix::deci);
implement_unit(si, si, hertz, _hertz, dim::frequency_t, prefix::one);
implement_unit(si, si, decahertz, _decahertz, dim::frequency_t, prefix::deca);
implement_unit(si, si, hectohertz, _hectohertz, dim::frequency_t, prefix::hecto);
implement_unit(si, si, kilohertz, _kilohertz, dim::frequency_t, prefix::kilo);
implement_unit(si, si, megahertz, _megahertz, dim::frequency_t, prefix::mega);
implement_unit(si, si, gigahertz, _gigahertz, dim::frequency_t, prefix::giga);
implement_unit(si, si, terahertz, _terahertz, dim::frequency_t, prefix::tera);
implement_unit(si, si, petahertz, _petahertz, dim::frequency_t, prefix::peta);
implement_unit(si, si, exahertz, _exahertz, dim::frequency_t, prefix::exa);
implement_unit(si, si, zettahertz, _zettahertz, dim::frequency_t, prefix::zetta);
implement_unit(si, si, yottahertz, _yottahertz, dim::frequency_t, prefix::yotta);
#pragma endregion
#pragma region newton(force)
implement_unit(si, si, yoctonewton, _yoctonewton, dim::force_t, prefix::yocto);
implement_unit(si, si, zeptonewton, _zeptonewton, dim::force_t, prefix::zepto);
implement_unit(si, si, attonewton, _attonewton, dim::force_t, prefix::atto);
implement_unit(si, si, femtonewton, _femtonewton, dim::force_t, prefix::femto);
implement_unit(si, si, piconewton, _piconewton, dim::force_t, prefix::pico);
implement_unit(si, si, nanonewton, _nanonewton, dim::force_t, prefix::nano);
implement_unit(si, si, micronewton, _micronewton, dim::force_t, prefix::micro);
implement_unit(si, si, millinewton, _millinewton, dim::force_t, prefix::milli);
implement_unit(si, si, centinewton, _centinewton, dim::force_t, prefix::centi);
implement_unit(si, si, decinewton, _decinewton, dim::force_t, prefix::deci);
implement_unit(si, si, newton, _newton, dim::force_t, prefix::one);
implement_unit(si, si, decanewton, _decanewton, dim::force_t, prefix::deca);
implement_unit(si, si, hectonewton, _hectonewton, dim::force_t, prefix::hecto);
implement_unit(si, si, kilonewton, _kilonewton, dim::force_t, prefix::kilo);
implement_unit(si, si, meganewton, _meganewton, dim::force_t, prefix::mega);
implement_unit(si, si, giganewton, _giganewton, dim::force_t, prefix::giga);
implement_unit(si, si, teranewton, _teranewton, dim::force_t, prefix::tera);
implement_unit(si, si, petanewton, _petanewton, dim::force_t, prefix::peta);
implement_unit(si, si, exanewton, _exanewton, dim::force_t, prefix::exa);
implement_unit(si, si, zettanewton, _zettanewton, dim::force_t, prefix::zetta);
implement_unit(si, si, yottanewton, _yottanewton, dim::force_t, prefix::yotta);
#pragma endregion
#pragma region pascal(pressure)
implement_unit(si, si, yoctopascal, _yoctopascal, dim::pressure_t, prefix::yocto);
implement_unit(si, si, zeptopascal, _zeptopascal, dim::pressure_t, prefix::zepto);
implement_unit(si, si, attopascal, _attopascal, dim::pressure_t, prefix::atto);
implement_unit(si, si, femtopascal, _femtopascal, dim::pressure_t, prefix::femto);
implement_unit(si, si, picopascal, _picopascal, dim::pressure_t, prefix::pico);
implement_unit(si, si, nanopascal, _nanopascal, dim::pressure_t, prefix::nano);
implement_unit(si, si, micropascal, _micropascal, dim::pressure_t, prefix::micro);
implement_unit(si, si, millipascal, _millipascal, dim::pressure_t, prefix::milli);
implement_unit(si, si, centipascal, _centipascal, dim::pressure_t, prefix::centi);
implement_unit(si, si, decipascal, _decipascal, dim::pressure_t, prefix::deci);
implement_unit(si, si, pascal, _pascal, dim::pressure_t, prefix::one);
implement_unit(si, si, decapascal, _decapascal, dim::pressure_t, prefix::deca);
implement_unit(si, si, hectopascal, _hectopascal, dim::pressure_t, prefix::hecto);
implement_unit(si, si, kilopascal, _kilopascal, dim::pressure_t, prefix::kilo);
implement_unit(si, si, megapascal, _megapascal, dim::pressure_t, prefix::mega);
implement_unit(si, si, gigapascal, _gigapascal, dim::pressure_t, prefix::giga);
implement_unit(si, si, terapascal, _terapascal, dim::pressure_t, prefix::tera);
implement_unit(si, si, petapascal, _petapascal, dim::pressure_t, prefix::peta);
implement_unit(si, si, exapascal, _exapascal, dim::pressure_t, prefix::exa);
implement_unit(si, si, zettapascal, _zettapascal, dim::pressure_t, prefix::zetta);
implement_unit(si, si, yottapascal, _yottapascal, dim::pressure_t, prefix::yotta);
#pragma endregion
#pragma region bar, mmHg, ...(pressure)
implement_unit(si, si, yoctobar, _yoctobar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::yocto, make_power_list_t<5>>));
implement_unit(si, si, zeptobar, _zeptobar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::zepto, make_power_list_t<5>>));
implement_unit(si, si, attobar, _attobar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::atto, make_power_list_t<5>>));
implement_unit(si, si, femtobar, _femtobar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::femto, make_power_list_t<5>>));
implement_unit(si, si, picobar, _picobar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::pico, make_power_list_t<5>>));
implement_unit(si, si, nanobar, _nanobar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::nano, make_power_list_t<5>>));
link_unit(microbar,_microbar,decipascal);
link_unit(millibar,_millibar,hectopascal);
link_unit(centibar,_centibar,kilopascal);
implement_unit(si, si, decibar, _decibar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::deci, make_power_list_t<5>>));
implement_unit(si, si, bar, _bar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::one, make_power_list_t<5>>));
link_unit(decabar,_decabar,megapascal);
implement_unit(si, si, hectobar, _hectobar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::hecto, make_power_list_t<5>>));
implement_unit(si, si, kilobar, _kilobar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::kilo, make_power_list_t<5>>));
implement_unit(si, si, megabar, _megabar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::mega, make_power_list_t<5>>));
implement_unit(si, si, gigabar, _gigabar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::giga, make_power_list_t<5>>));
implement_unit(si, si, terabar, _terabar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::tera, make_power_list_t<5>>));
implement_unit(si, si, petabar, _petabar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::peta, make_power_list_t<5>>));
implement_unit(si, si, exabar, _exabar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::exa, make_power_list_t<5>>));
implement_unit(si, si, zettabar, _zettabar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::zetta, make_power_list_t<5>>));
implement_unit(si, si, yottabar, _yottabar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::yotta, make_power_list_t<5>>));

implement_unit(si, si, millimeter_of_mercury, _millimeter_of_mercury, dim::pressure_t, fix(make_fraction_list_t<133322,1000>));
implement_unit(si, si, atmosphere, _atmosphere, dim::pressure_t, make_fraction_list_t<101325>);
implement_unit(si, si, torr, _torr, dim::pressure_t, fix(make_fraction_list_t<101325,760>));
#pragma endregion
#pragma region joule(energy)
implement_unit(si, si, yoctojoule, _yoctojoule, dim::energy_t, prefix::yocto);
implement_unit(si, si, zeptojoule, _zeptojoule, dim::energy_t, prefix::zepto);
implement_unit(si, si, attojoule, _attojoule, dim::energy_t, prefix::atto);
implement_unit(si, si, femtojoule, _femtojoule, dim::energy_t, prefix::femto);
implement_unit(si, si, picojoule, _picojoule, dim::energy_t, prefix::pico);
implement_unit(si, si, nanojoule, _nanojoule, dim::energy_t, prefix::nano);
implement_unit(si, si, microjoule, _microjoule, dim::energy_t, prefix::micro);
implement_unit(si, si, millijoule, _millijoule, dim::energy_t, prefix::milli);
implement_unit(si, si, centijoule, _centijoule, dim::energy_t, prefix::centi);
implement_unit(si, si, decijoule, _decijoule, dim::energy_t, prefix::deci);
implement_unit(si, si, joule, _joule, dim::energy_t, prefix::one);
implement_unit(si, si, decajoule, _decajoule, dim::energy_t, prefix::deca);
implement_unit(si, si, hectojoule, _hectojoule, dim::energy_t, prefix::hecto);
implement_unit(si, si, kilojoule, _kilojoule, dim::energy_t, prefix::kilo);
implement_unit(si, si, megajoule, _megajoule, dim::energy_t, prefix::mega);
implement_unit(si, si, gigajoule, _gigajoule, dim::energy_t, prefix::giga);
implement_unit(si, si, terajoule, _terajoule, dim::energy_t, prefix::tera);
implement_unit(si, si, petajoule, _petajoule, dim::energy_t, prefix::peta);
implement_unit(si, si, exajoule, _exajoule, dim::energy_t, prefix::exa);
implement_unit(si, si, zettajoule, _zettajoule, dim::energy_t, prefix::zetta);
implement_unit(si, si, yottajoule, _yottajoule, dim::energy_t, prefix::yotta);
#pragma endregion
#pragma region electron volt, hartree(energy)
implement_unit(si, si, yoctoelectron_volt, _yoctoelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::yocto,prefix::elementary_charge_t>));
implement_unit(si, si, zeptoelectron_volt, _zeptoelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::zepto,prefix::elementary_charge_t>));
implement_unit(si, si, attoelectron_volt, _attoelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::atto,prefix::elementary_charge_t>));
implement_unit(si, si, femtoelectron_volt, _femtoelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::femto,prefix::elementary_charge_t>));
implement_unit(si, si, picoelectron_volt, _picoelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::pico,prefix::elementary_charge_t>));
implement_unit(si, si, nanoelectron_volt, _nanoelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::nano,prefix::elementary_charge_t>));
implement_unit(si, si, microelectron_volt, _microelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::micro,prefix::elementary_charge_t>));
implement_unit(si, si, millielectron_volt, _millielectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::milli,prefix::elementary_charge_t>));
implement_unit(si, si, centielectron_volt, _centielectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::centi,prefix::elementary_charge_t>));
implement_unit(si, si, decielectron_volt, _decielectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::deci,prefix::elementary_charge_t>));
implement_unit(si, si, electron_volt, _electron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::one,prefix::elementary_charge_t>));
implement_unit(si, si, decaelectron_volt, _decaelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::deca,prefix::elementary_charge_t>));
implement_unit(si, si, hectoelectron_volt, _hectoelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::hecto,prefix::elementary_charge_t>));
implement_unit(si, si, kiloelectron_volt, _kiloelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::kilo,prefix::elementary_charge_t>));
implement_unit(si, si, megaelectron_volt, _megaelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::mega,prefix::elementary_charge_t>));
implement_unit(si, si, gigaelectron_volt, _gigaelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::giga,prefix::elementary_charge_t>));
implement_unit(si, si, teraelectron_volt, _teraelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::tera,prefix::elementary_charge_t>));
implement_unit(si, si, petaelectron_volt, _petaelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::peta,prefix::elementary_charge_t>));
implement_unit(si, si, exaelectron_volt, _exaelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::exa,prefix::elementary_charge_t>));
implement_unit(si, si, zettaelectron_volt, _zettaelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::zetta,prefix::elementary_charge_t>));
implement_unit(si, si, yottaelectron_volt, _yottaelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::yotta,prefix::elementary_charge_t>));

implement_unit(si, si, yoctohartree, _yoctohartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::yocto,prefix::hartree_energy_t>));
implement_unit(si, si, zeptohartree, _zeptohartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::zepto,prefix::hartree_energy_t>));
implement_unit(si, si, attohartree, _attohartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::atto,prefix::hartree_energy_t>));
implement_unit(si, si, femtohartree, _femtohartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::femto,prefix::hartree_energy_t>));
implement_unit(si, si, picohartree, _picohartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::pico,prefix::hartree_energy_t>));
implement_unit(si, si, nanohartree, _nanohartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::nano,prefix::hartree_energy_t>));
implement_unit(si, si, microhartree, _microhartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::micro,prefix::hartree_energy_t>));
implement_unit(si, si, millihartree, _millihartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::milli,prefix::hartree_energy_t>));
implement_unit(si, si, centihartree, _centihartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::centi,prefix::hartree_energy_t>));
implement_unit(si, si, decihartree, _decihartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::deci,prefix::hartree_energy_t>));
implement_unit(si, si, hartree, _hartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::one,prefix::hartree_energy_t>));
implement_unit(si, si, decahartree, _decahartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::deca,prefix::hartree_energy_t>));
implement_unit(si, si, hectohartree, _hectohartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::hecto,prefix::hartree_energy_t>));
implement_unit(si, si, kilohartree, _kilohartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::kilo,prefix::hartree_energy_t>));
implement_unit(si, si, megahartree, _megahartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::mega,prefix::hartree_energy_t>));
implement_unit(si, si, gigahartree, _gigahartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::giga,prefix::hartree_energy_t>));
implement_unit(si, si, terahartree, _terahartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::tera,prefix::hartree_energy_t>));
implement_unit(si, si, petahartree, _petahartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::peta,prefix::hartree_energy_t>));
implement_unit(si, si, exahartree, _exahartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::exa,prefix::hartree_energy_t>));
implement_unit(si, si, zettahartree, _zettahartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::zetta,prefix::hartree_energy_t>));
implement_unit(si, si, yottahartree, _yottahartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::yotta,prefix::hartree_energy_t>));
#pragma endregion
#pragma region watt minute(energy)
implement_unit(si, si, yoctowatt_minute, _yoctowatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yocto>));
implement_unit(si, si, zeptowatt_minute, _zeptowatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zepto>));
implement_unit(si, si, attowatt_minute, _attowatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::atto>));
implement_unit(si, si, femtowatt_minute, _femtowatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::femto>));
implement_unit(si, si, picowatt_minute, _picowatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::pico>));
implement_unit(si, si, nanowatt_minute, _nanowatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::nano>));
implement_unit(si, si, microwatt_minute, _microwatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::micro>));
implement_unit(si, si, milliwatt_minute, _milliwatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::milli>));
implement_unit(si, si, centiwatt_minute, _centiwatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::centi>));
implement_unit(si, si, deciwatt_minute, _deciwatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deci>));
implement_unit(si, si, watt_minute, _watt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::one>));
implement_unit(si, si, decawatt_minute, _decawatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deca>));
implement_unit(si, si, hectowatt_minute, _hectowatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::hecto>));
implement_unit(si, si, kilowatt_minute, _kilowatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::kilo>));
implement_unit(si, si, megawatt_minute, _megawatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::mega>));
implement_unit(si, si, gigawatt_minute, _gigawatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::giga>));
implement_unit(si, si, terawatt_minute, _terawatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::tera>));
implement_unit(si, si, petawatt_minute, _petawatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::peta>));
implement_unit(si, si, exawatt_minute, _exawatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::exa>));
implement_unit(si, si, zettawatt_minute, _zettawatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zetta>));
implement_unit(si, si, yottawatt_minute, _yottawatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yotta>));
#pragma endregion
#pragma region watt hour(energy)
implement_unit(si, si, yoctowatt_hour, _yoctowatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yocto>));
implement_unit(si, si, zeptowatt_hour, _zeptowatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zepto>));
implement_unit(si, si, attowatt_hour, _attowatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::atto>));
implement_unit(si, si, femtowatt_hour, _femtowatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::femto>));
implement_unit(si, si, picowatt_hour, _picowatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::pico>));
implement_unit(si, si, nanowatt_hour, _nanowatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::nano>));
implement_unit(si, si, microwatt_hour, _microwatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::micro>));
implement_unit(si, si, milliwatt_hour, _milliwatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::milli>));
implement_unit(si, si, centiwatt_hour, _centiwatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::centi>));
implement_unit(si, si, deciwatt_hour, _deciwatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deci>));
implement_unit(si, si, watt_hour, _watt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::one>));
implement_unit(si, si, decawatt_hour, _decawatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deca>));
implement_unit(si, si, hectowatt_hour, _hectowatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::hecto>));
implement_unit(si, si, kilowatt_hour, _kilowatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::kilo>));
implement_unit(si, si, megawatt_hour, _megawatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::mega>));
implement_unit(si, si, gigawatt_hour, _gigawatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::giga>));
implement_unit(si, si, terawatt_hour, _terawatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::tera>));
implement_unit(si, si, petawatt_hour, _petawatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::peta>));
implement_unit(si, si, exawatt_hour, _exawatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::exa>));
implement_unit(si, si, zettawatt_hour, _zettawatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zetta>));
implement_unit(si, si, yottawatt_hour, _yottawatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yotta>));
#pragma endregion
#pragma region watt(power)
implement_unit(si, si, yoctowatt, _yoctowatt, dim::power_t, prefix::yocto);
implement_unit(si, si, zeptowatt, _zeptowatt, dim::power_t, prefix::zepto);
implement_unit(si, si, attowatt, _attowatt, dim::power_t, prefix::atto);
implement_unit(si, si, femtowatt, _femtowatt, dim::power_t, prefix::femto);
implement_unit(si, si, picowatt, _picowatt, dim::power_t, prefix::pico);
implement_unit(si, si, nanowatt, _nanowatt, dim::power_t, prefix::nano);
implement_unit(si, si, microwatt, _microwatt, dim::power_t, prefix::micro);
implement_unit(si, si, milliwatt, _milliwatt, dim::power_t, prefix::milli);
implement_unit(si, si, centiwatt, _centiwatt, dim::power_t, prefix::centi);
implement_unit(si, si, deciwatt, _deciwatt, dim::power_t, prefix::deci);
implement_unit(si, si, watt, _watt, dim::power_t, prefix::one);
implement_unit(si, si, decawatt, _decawatt, dim::power_t, prefix::deca);
implement_unit(si, si, hectowatt, _hectowatt, dim::power_t, prefix::hecto);
implement_unit(si, si, kilowatt, _kilowatt, dim::power_t, prefix::kilo);
implement_unit(si, si, megawatt, _megawatt, dim::power_t, prefix::mega);
implement_unit(si, si, gigawatt, _gigawatt, dim::power_t, prefix::giga);
implement_unit(si, si, terawatt, _terawatt, dim::power_t, prefix::tera);
implement_unit(si, si, petawatt, _petawatt, dim::power_t, prefix::peta);
implement_unit(si, si, exawatt, _exawatt, dim::power_t, prefix::exa);
implement_unit(si, si, zettawatt, _zettawatt, dim::power_t, prefix::zetta);
implement_unit(si, si, yottawatt, _yottawatt, dim::power_t, prefix::yotta);
#pragma endregion
#pragma region coulomb(electric charge)
implement_unit(si, si, yoctocoulomb, _yoctocoulomb, dim::electric_charge_t, prefix::yocto);
implement_unit(si, si, zeptocoulomb, _zeptocoulomb, dim::electric_charge_t, prefix::zepto);
implement_unit(si, si, attocoulomb, _attocoulomb, dim::electric_charge_t, prefix::atto);
implement_unit(si, si, femtocoulomb, _femtocoulomb, dim::electric_charge_t, prefix::femto);
implement_unit(si, si, picocoulomb, _picocoulomb, dim::electric_charge_t, prefix::pico);
implement_unit(si, si, nanocoulomb, _nanocoulomb, dim::electric_charge_t, prefix::nano);
implement_unit(si, si, microcoulomb, _microcoulomb, dim::electric_charge_t, prefix::micro);
implement_unit(si, si, millicoulomb, _millicoulomb, dim::electric_charge_t, prefix::milli);
implement_unit(si, si, centicoulomb, _centicoulomb, dim::electric_charge_t, prefix::centi);
implement_unit(si, si, decicoulomb, _decicoulomb, dim::electric_charge_t, prefix::deci);
implement_unit(si, si, coulomb, _coulomb, dim::electric_charge_t, prefix::one);
implement_unit(si, si, decacoulomb, _decacoulomb, dim::electric_charge_t, prefix::deca);
implement_unit(si, si, hectocoulomb, _hectocoulomb, dim::electric_charge_t, prefix::hecto);
implement_unit(si, si, kilocoulomb, _kilocoulomb, dim::electric_charge_t, prefix::kilo);
implement_unit(si, si, megacoulomb, _megacoulomb, dim::electric_charge_t, prefix::mega);
implement_unit(si, si, gigacoulomb, _gigacoulomb, dim::electric_charge_t, prefix::giga);
implement_unit(si, si, teracoulomb, _teracoulomb, dim::electric_charge_t, prefix::tera);
implement_unit(si, si, petacoulomb, _petacoulomb, dim::electric_charge_t, prefix::peta);
implement_unit(si, si, exacoulomb, _exacoulomb, dim::electric_charge_t, prefix::exa);
implement_unit(si, si, zettacoulomb, _zettacoulomb, dim::electric_charge_t, prefix::zetta);
implement_unit(si, si, yottacoulomb, _yottacoulomb, dim::electric_charge_t, prefix::yotta);
#pragma endregion
#pragma region ampere minute(electric charge)
implement_unit(si, si, yoctoampere_minute, _yoctoampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yocto>));
implement_unit(si, si, zeptoampere_minute, _zeptoampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zepto>));
implement_unit(si, si, attoampere_minute, _attoampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::atto>));
implement_unit(si, si, femtoampere_minute, _femtoampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::femto>));
implement_unit(si, si, picoampere_minute, _picoampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::pico>));
implement_unit(si, si, nanoampere_minute, _nanoampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::nano>));
implement_unit(si, si, microampere_minute, _microampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::micro>));
implement_unit(si, si, milliampere_minute, _milliampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::milli>));
implement_unit(si, si, centiampere_minute, _centiampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::centi>));
implement_unit(si, si, deciampere_minute, _deciampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deci>));
implement_unit(si, si, ampere_minute, _ampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::one>));
implement_unit(si, si, decaampere_minute, _decaampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deca>));
implement_unit(si, si, hectoampere_minute, _hectoampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::hecto>));
implement_unit(si, si, kiloampere_minute, _kiloampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::kilo>));
implement_unit(si, si, megaampere_minute, _megaampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::mega>));
implement_unit(si, si, gigaampere_minute, _gigaampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::giga>));
implement_unit(si, si, teraampere_minute, _teraampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::tera>));
implement_unit(si, si, petaampere_minute, _petaampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::peta>));
implement_unit(si, si, exaampere_minute, _exaampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::exa>));
implement_unit(si, si, zettaampere_minute, _zettaampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zetta>));
implement_unit(si, si, yottaampere_minute, _yottaampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yotta>));
#pragma endregion
#pragma region ampere hour(electric charge)
implement_unit(si, si, yoctoampere_hour, _yoctoampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yocto>));
implement_unit(si, si, zeptoampere_hour, _zeptoampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zepto>));
implement_unit(si, si, attoampere_hour, _attoampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::atto>));
implement_unit(si, si, femtoampere_hour, _femtoampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::femto>));
implement_unit(si, si, picoampere_hour, _picoampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::pico>));
implement_unit(si, si, nanoampere_hour, _nanoampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::nano>));
implement_unit(si, si, microampere_hour, _microampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::micro>));
implement_unit(si, si, milliampere_hour, _milliampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::milli>));
implement_unit(si, si, centiampere_hour, _centiampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::centi>));
implement_unit(si, si, deciampere_hour, _deciampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deci>));
implement_unit(si, si, ampere_hour, _ampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::one>));
implement_unit(si, si, decaampere_hour, _decaampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deca>));
implement_unit(si, si, hectoampere_hour, _hectoampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::hecto>));
implement_unit(si, si, kiloampere_hour, _kiloampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::kilo>));
implement_unit(si, si, megaampere_hour, _megaampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::mega>));
implement_unit(si, si, gigaampere_hour, _gigaampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::giga>));
implement_unit(si, si, teraampere_hour, _teraampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::tera>));
implement_unit(si, si, petaampere_hour, _petaampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::peta>));
implement_unit(si, si, exaampere_hour, _exaampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::exa>));
implement_unit(si, si, zettaampere_hour, _zettaampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zetta>));
implement_unit(si, si, yottaampere_hour, _yottaampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yotta>));
#pragma endregion
#pragma region electron/elementary charge(electric charge)
implement_unit(si, si, yoctoelectron, _yoctoelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::yocto,prefix::elementary_charge_t>));
implement_unit(si, si, zeptoelectron, _zeptoelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::zepto,prefix::elementary_charge_t>));
implement_unit(si, si, attoelectron, _attoelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::atto,prefix::elementary_charge_t>));
implement_unit(si, si, femtoelectron, _femtoelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::femto,prefix::elementary_charge_t>));
implement_unit(si, si, picoelectron, _picoelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::pico,prefix::elementary_charge_t>));
implement_unit(si, si, nanoelectron, _nanoelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::nano,prefix::elementary_charge_t>));
implement_unit(si, si, microelectron, _microelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::micro,prefix::elementary_charge_t>));
implement_unit(si, si, millielectron, _millielectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::milli,prefix::elementary_charge_t>));
implement_unit(si, si, centielectron, _centielectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::centi,prefix::elementary_charge_t>));
implement_unit(si, si, decielectron, _decielectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::deci,prefix::elementary_charge_t>));
implement_unit(si, si, electron, _electron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::one,prefix::elementary_charge_t>));
implement_unit(si, si, decaelectron, _decaelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::deca,prefix::elementary_charge_t>));
implement_unit(si, si, hectoelectron, _hectoelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hecto,prefix::elementary_charge_t>));
implement_unit(si, si, kiloelectron, _kiloelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::kilo,prefix::elementary_charge_t>));
implement_unit(si, si, megaelectron, _megaelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::mega,prefix::elementary_charge_t>));
implement_unit(si, si, gigaelectron, _gigaelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::giga,prefix::elementary_charge_t>));
implement_unit(si, si, teraelectron, _teraelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::tera,prefix::elementary_charge_t>));
implement_unit(si, si, petaelectron, _petaelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::peta,prefix::elementary_charge_t>));
implement_unit(si, si, exaelectron, _exaelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::exa,prefix::elementary_charge_t>));
implement_unit(si, si, zettaelectron, _zettaelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::zetta,prefix::elementary_charge_t>));
implement_unit(si, si, yottaelectron, _yottaelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::yotta,prefix::elementary_charge_t>));
#pragma endregion
#pragma region volt(electric potential)
implement_unit(si, si, yoctovolt, _yoctovolt, dim::electric_potential_t, prefix::yocto);
implement_unit(si, si, zeptovolt, _zeptovolt, dim::electric_potential_t, prefix::zepto);
implement_unit(si, si, attovolt, _attovolt, dim::electric_potential_t, prefix::atto);
implement_unit(si, si, femtovolt, _femtovolt, dim::electric_potential_t, prefix::femto);
implement_unit(si, si, picovolt, _picovolt, dim::electric_potential_t, prefix::pico);
implement_unit(si, si, nanovolt, _nanovolt, dim::electric_potential_t, prefix::nano);
implement_unit(si, si, microvolt, _microvolt, dim::electric_potential_t, prefix::micro);
implement_unit(si, si, millivolt, _millivolt, dim::electric_potential_t, prefix::milli);
implement_unit(si, si, centivolt, _centivolt, dim::electric_potential_t, prefix::centi);
implement_unit(si, si, decivolt, _decivolt, dim::electric_potential_t, prefix::deci);
implement_unit(si, si, volt, _volt, dim::electric_potential_t, prefix::one);
implement_unit(si, si, decavolt, _decavolt, dim::electric_potential_t, prefix::deca);
implement_unit(si, si, hectovolt, _hectovolt, dim::electric_potential_t, prefix::hecto);
implement_unit(si, si, kilovolt, _kilovolt, dim::electric_potential_t, prefix::kilo);
implement_unit(si, si, megavolt, _megavolt, dim::electric_potential_t, prefix::mega);
implement_unit(si, si, gigavolt, _gigavolt, dim::electric_potential_t, prefix::giga);
implement_unit(si, si, teravolt, _teravolt, dim::electric_potential_t, prefix::tera);
implement_unit(si, si, petavolt, _petavolt, dim::electric_potential_t, prefix::peta);
implement_unit(si, si, exavolt, _exavolt, dim::electric_potential_t, prefix::exa);
implement_unit(si, si, zettavolt, _zettavolt, dim::electric_potential_t, prefix::zetta);
implement_unit(si, si, yottavolt, _yottavolt, dim::electric_potential_t, prefix::yotta);
#pragma endregion
#pragma region farad(capacitance)
implement_unit(si, si, yoctofarad, _yoctofarad, dim::capacitance_t, prefix::yocto);
implement_unit(si, si, zeptofarad, _zeptofarad, dim::capacitance_t, prefix::zepto);
implement_unit(si, si, attofarad, _attofarad, dim::capacitance_t, prefix::atto);
implement_unit(si, si, femtofarad, _femtofarad, dim::capacitance_t, prefix::femto);
implement_unit(si, si, picofarad, _picofarad, dim::capacitance_t, prefix::pico);
implement_unit(si, si, nanofarad, _nanofarad, dim::capacitance_t, prefix::nano);
implement_unit(si, si, microfarad, _microfarad, dim::capacitance_t, prefix::micro);
implement_unit(si, si, millifarad, _millifarad, dim::capacitance_t, prefix::milli);
implement_unit(si, si, centifarad, _centifarad, dim::capacitance_t, prefix::centi);
implement_unit(si, si, decifarad, _decifarad, dim::capacitance_t, prefix::deci);
implement_unit(si, si, farad, _farad, dim::capacitance_t, prefix::one);
implement_unit(si, si, decafarad, _decafarad, dim::capacitance_t, prefix::deca);
implement_unit(si, si, hectofarad, _hectofarad, dim::capacitance_t, prefix::hecto);
implement_unit(si, si, kilofarad, _kilofarad, dim::capacitance_t, prefix::kilo);
implement_unit(si, si, megafarad, _megafarad, dim::capacitance_t, prefix::mega);
implement_unit(si, si, gigafarad, _gigafarad, dim::capacitance_t, prefix::giga);
implement_unit(si, si, terafarad, _terafarad, dim::capacitance_t, prefix::tera);
implement_unit(si, si, petafarad, _petafarad, dim::capacitance_t, prefix::peta);
implement_unit(si, si, exafarad, _exafarad, dim::capacitance_t, prefix::exa);
implement_unit(si, si, zettafarad, _zettafarad, dim::capacitance_t, prefix::zetta);
implement_unit(si, si, yottafarad, _yottafarad, dim::capacitance_t, prefix::yotta);
#pragma endregion
#pragma region ohm(electric resistance)
implement_unit(si, si, yoctoohm, _yoctoohm, dim::electric_resistance_t, prefix::yocto);
implement_unit(si, si, zeptoohm, _zeptoohm, dim::electric_resistance_t, prefix::zepto);
implement_unit(si, si, attoohm, _attoohm, dim::electric_resistance_t, prefix::atto);
implement_unit(si, si, femtoohm, _femtoohm, dim::electric_resistance_t, prefix::femto);
implement_unit(si, si, picoohm, _picoohm, dim::electric_resistance_t, prefix::pico);
implement_unit(si, si, nanoohm, _nanoohm, dim::electric_resistance_t, prefix::nano);
implement_unit(si, si, microohm, _microohm, dim::electric_resistance_t, prefix::micro);
implement_unit(si, si, milliohm, _milliohm, dim::electric_resistance_t, prefix::milli);
implement_unit(si, si, centiohm, _centiohm, dim::electric_resistance_t, prefix::centi);
implement_unit(si, si, deciohm, _deciohm, dim::electric_resistance_t, prefix::deci);
implement_unit(si, si, ohm, _ohm, dim::electric_resistance_t, prefix::one);
implement_unit(si, si, decaohm, _decaohm, dim::electric_resistance_t, prefix::deca);
implement_unit(si, si, hectoohm, _hectoohm, dim::electric_resistance_t, prefix::hecto);
implement_unit(si, si, kiloohm, _kiloohm, dim::electric_resistance_t, prefix::kilo);
implement_unit(si, si, megaohm, _megaohm, dim::electric_resistance_t, prefix::mega);
implement_unit(si, si, gigaohm, _gigaohm, dim::electric_resistance_t, prefix::giga);
implement_unit(si, si, teraohm, _teraohm, dim::electric_resistance_t, prefix::tera);
implement_unit(si, si, petaohm, _petaohm, dim::electric_resistance_t, prefix::peta);
implement_unit(si, si, exaohm, _exaohm, dim::electric_resistance_t, prefix::exa);
implement_unit(si, si, zettaohm, _zettaohm, dim::electric_resistance_t, prefix::zetta);
implement_unit(si, si, yottaohm, _yottaohm, dim::electric_resistance_t, prefix::yotta);
#pragma endregion
#pragma region siemens(electric conductance)
implement_unit(si, si, yoctosiemens, _yoctosiemens, dim::electric_conductance_t, prefix::yocto);
implement_unit(si, si, zeptosiemens, _zeptosiemens, dim::electric_conductance_t, prefix::zepto);
implement_unit(si, si, attosiemens, _attosiemens, dim::electric_conductance_t, prefix::atto);
implement_unit(si, si, femtosiemens, _femtosiemens, dim::electric_conductance_t, prefix::femto);
implement_unit(si, si, picosiemens, _picosiemens, dim::electric_conductance_t, prefix::pico);
implement_unit(si, si, nanosiemens, _nanosiemens, dim::electric_conductance_t, prefix::nano);
implement_unit(si, si, microsiemens, _microsiemens, dim::electric_conductance_t, prefix::micro);
implement_unit(si, si, millisiemens, _millisiemens, dim::electric_conductance_t, prefix::milli);
implement_unit(si, si, centisiemens, _centisiemens, dim::electric_conductance_t, prefix::centi);
implement_unit(si, si, decisiemens, _decisiemens, dim::electric_conductance_t, prefix::deci);
implement_unit(si, si, siemens, _siemens, dim::electric_conductance_t, prefix::one);
implement_unit(si, si, decasiemens, _decasiemens, dim::electric_conductance_t, prefix::deca);
implement_unit(si, si, hectosiemens, _hectosiemens, dim::electric_conductance_t, prefix::hecto);
implement_unit(si, si, kilosiemens, _kilosiemens, dim::electric_conductance_t, prefix::kilo);
implement_unit(si, si, megasiemens, _megasiemens, dim::electric_conductance_t, prefix::mega);
implement_unit(si, si, gigasiemens, _gigasiemens, dim::electric_conductance_t, prefix::giga);
implement_unit(si, si, terasiemens, _terasiemens, dim::electric_conductance_t, prefix::tera);
implement_unit(si, si, petasiemens, _petasiemens, dim::electric_conductance_t, prefix::peta);
implement_unit(si, si, exasiemens, _exasiemens, dim::electric_conductance_t, prefix::exa);
implement_unit(si, si, zettasiemens, _zettasiemens, dim::electric_conductance_t, prefix::zetta);
implement_unit(si, si, yottasiemens, _yottasiemens, dim::electric_conductance_t, prefix::yotta);
#pragma endregion
#pragma region weber(magnetic flux)
implement_unit(si, si, yoctoweber, _yoctoweber, dim::magnetic_flux_t, prefix::yocto);
implement_unit(si, si, zeptoweber, _zeptoweber, dim::magnetic_flux_t, prefix::zepto);
implement_unit(si, si, attoweber, _attoweber, dim::magnetic_flux_t, prefix::atto);
implement_unit(si, si, femtoweber, _femtoweber, dim::magnetic_flux_t, prefix::femto);
implement_unit(si, si, picoweber, _picoweber, dim::magnetic_flux_t, prefix::pico);
implement_unit(si, si, nanoweber, _nanoweber, dim::magnetic_flux_t, prefix::nano);
implement_unit(si, si, microweber, _microweber, dim::magnetic_flux_t, prefix::micro);
implement_unit(si, si, milliweber, _milliweber, dim::magnetic_flux_t, prefix::milli);
implement_unit(si, si, centiweber, _centiweber, dim::magnetic_flux_t, prefix::centi);
implement_unit(si, si, deciweber, _deciweber, dim::magnetic_flux_t, prefix::deci);
implement_unit(si, si, weber, _weber, dim::magnetic_flux_t, prefix::one);
implement_unit(si, si, decaweber, _decaweber, dim::magnetic_flux_t, prefix::deca);
implement_unit(si, si, hectoweber, _hectoweber, dim::magnetic_flux_t, prefix::hecto);
implement_unit(si, si, kiloweber, _kiloweber, dim::magnetic_flux_t, prefix::kilo);
implement_unit(si, si, megaweber, _megaweber, dim::magnetic_flux_t, prefix::mega);
implement_unit(si, si, gigaweber, _gigaweber, dim::magnetic_flux_t, prefix::giga);
implement_unit(si, si, teraweber, _teraweber, dim::magnetic_flux_t, prefix::tera);
implement_unit(si, si, petaweber, _petaweber, dim::magnetic_flux_t, prefix::peta);
implement_unit(si, si, exaweber, _exaweber, dim::magnetic_flux_t, prefix::exa);
implement_unit(si, si, zettaweber, _zettaweber, dim::magnetic_flux_t, prefix::zetta);
implement_unit(si, si, yottaweber, _yottaweber, dim::magnetic_flux_t, prefix::yotta);
#pragma endregion
#pragma region tesla(magnetic flux density)
implement_unit(si, si, yoctotesla, _yoctotesla, dim::magnetic_flux_density_t, prefix::yocto);
implement_unit(si, si, zeptotesla, _zeptotesla, dim::magnetic_flux_density_t, prefix::zepto);
implement_unit(si, si, attotesla, _attotesla, dim::magnetic_flux_density_t, prefix::atto);
implement_unit(si, si, femtotesla, _femtotesla, dim::magnetic_flux_density_t, prefix::femto);
implement_unit(si, si, picotesla, _picotesla, dim::magnetic_flux_density_t, prefix::pico);
implement_unit(si, si, nanotesla, _nanotesla, dim::magnetic_flux_density_t, prefix::nano);
implement_unit(si, si, microtesla, _microtesla, dim::magnetic_flux_density_t, prefix::micro);
implement_unit(si, si, millitesla, _millitesla, dim::magnetic_flux_density_t, prefix::milli);
implement_unit(si, si, centitesla, _centitesla, dim::magnetic_flux_density_t, prefix::centi);
implement_unit(si, si, decitesla, _decitesla, dim::magnetic_flux_density_t, prefix::deci);
implement_unit(si, si, tesla, _tesla, dim::magnetic_flux_density_t, prefix::one);
implement_unit(si, si, decatesla, _decatesla, dim::magnetic_flux_density_t, prefix::deca);
implement_unit(si, si, hectotesla, _hectotesla, dim::magnetic_flux_density_t, prefix::hecto);
implement_unit(si, si, kilotesla, _kilotesla, dim::magnetic_flux_density_t, prefix::kilo);
implement_unit(si, si, megatesla, _megatesla, dim::magnetic_flux_density_t, prefix::mega);
implement_unit(si, si, gigatesla, _gigatesla, dim::magnetic_flux_density_t, prefix::giga);
implement_unit(si, si, teratesla, _teratesla, dim::magnetic_flux_density_t, prefix::tera);
implement_unit(si, si, petatesla, _petatesla, dim::magnetic_flux_density_t, prefix::peta);
implement_unit(si, si, exatesla, _exatesla, dim::magnetic_flux_density_t, prefix::exa);
implement_unit(si, si, zettatesla, _zettatesla, dim::magnetic_flux_density_t, prefix::zetta);
implement_unit(si, si, yottatesla, _yottatesla, dim::magnetic_flux_density_t, prefix::yotta);
#pragma endregion
#pragma region henry(inductance)
implement_unit(si, si, yoctohenry, _yoctohenry, dim::inductance_t, prefix::yocto);
implement_unit(si, si, zeptohenry, _zeptohenry, dim::inductance_t, prefix::zepto);
implement_unit(si, si, attohenry, _attohenry, dim::inductance_t, prefix::atto);
implement_unit(si, si, femtohenry, _femtohenry, dim::inductance_t, prefix::femto);
implement_unit(si, si, picohenry, _picohenry, dim::inductance_t, prefix::pico);
implement_unit(si, si, nanohenry, _nanohenry, dim::inductance_t, prefix::nano);
implement_unit(si, si, microhenry, _microhenry, dim::inductance_t, prefix::micro);
implement_unit(si, si, millihenry, _millihenry, dim::inductance_t, prefix::milli);
implement_unit(si, si, centihenry, _centihenry, dim::inductance_t, prefix::centi);
implement_unit(si, si, decihenry, _decihenry, dim::inductance_t, prefix::deci);
implement_unit(si, si, henry, _henry, dim::inductance_t, prefix::one);
implement_unit(si, si, decahenry, _decahenry, dim::inductance_t, prefix::deca);
implement_unit(si, si, hectohenry, _hectohenry, dim::inductance_t, prefix::hecto);
implement_unit(si, si, kilohenry, _kilohenry, dim::inductance_t, prefix::kilo);
implement_unit(si, si, megahenry, _megahenry, dim::inductance_t, prefix::mega);
implement_unit(si, si, gigahenry, _gigahenry, dim::inductance_t, prefix::giga);
implement_unit(si, si, terahenry, _terahenry, dim::inductance_t, prefix::tera);
implement_unit(si, si, petahenry, _petahenry, dim::inductance_t, prefix::peta);
implement_unit(si, si, exahenry, _exahenry, dim::inductance_t, prefix::exa);
implement_unit(si, si, zettahenry, _zettahenry, dim::inductance_t, prefix::zetta);
implement_unit(si, si, yottahenry, _yottahenry, dim::inductance_t, prefix::yotta);
#pragma endregion
#pragma region lumen(luminous flux)
implement_unit(si, si, yoctolumen, _yoctolumen, dim::luminous_flux_t, prefix::yocto);
implement_unit(si, si, zeptolumen, _zeptolumen, dim::luminous_flux_t, prefix::zepto);
implement_unit(si, si, attolumen, _attolumen, dim::luminous_flux_t, prefix::atto);
implement_unit(si, si, femtolumen, _femtolumen, dim::luminous_flux_t, prefix::femto);
implement_unit(si, si, picolumen, _picolumen, dim::luminous_flux_t, prefix::pico);
implement_unit(si, si, nanolumen, _nanolumen, dim::luminous_flux_t, prefix::nano);
implement_unit(si, si, microlumen, _microlumen, dim::luminous_flux_t, prefix::micro);
implement_unit(si, si, millilumen, _millilumen, dim::luminous_flux_t, prefix::milli);
implement_unit(si, si, centilumen, _centilumen, dim::luminous_flux_t, prefix::centi);
implement_unit(si, si, decilumen, _decilumen, dim::luminous_flux_t, prefix::deci);
implement_unit(si, si, lumen, _lumen, dim::luminous_flux_t, prefix::one);
implement_unit(si, si, decalumen, _decalumen, dim::luminous_flux_t, prefix::deca);
implement_unit(si, si, hectolumen, _hectolumen, dim::luminous_flux_t, prefix::hecto);
implement_unit(si, si, kilolumen, _kilolumen, dim::luminous_flux_t, prefix::kilo);
implement_unit(si, si, megalumen, _megalumen, dim::luminous_flux_t, prefix::mega);
implement_unit(si, si, gigalumen, _gigalumen, dim::luminous_flux_t, prefix::giga);
implement_unit(si, si, teralumen, _teralumen, dim::luminous_flux_t, prefix::tera);
implement_unit(si, si, petalumen, _petalumen, dim::luminous_flux_t, prefix::peta);
implement_unit(si, si, exalumen, _exalumen, dim::luminous_flux_t, prefix::exa);
implement_unit(si, si, zettalumen, _zettalumen, dim::luminous_flux_t, prefix::zetta);
implement_unit(si, si, yottalumen, _yottalumen, dim::luminous_flux_t, prefix::yotta);
#pragma endregion
#pragma region lux(illuminance)
implement_unit(si, si, yoctolux, _yoctolux, dim::illuminance_t, prefix::yocto);
implement_unit(si, si, zeptolux, _zeptolux, dim::illuminance_t, prefix::zepto);
implement_unit(si, si, attolux, _attolux, dim::illuminance_t, prefix::atto);
implement_unit(si, si, femtolux, _femtolux, dim::illuminance_t, prefix::femto);
implement_unit(si, si, picolux, _picolux, dim::illuminance_t, prefix::pico);
implement_unit(si, si, nanolux, _nanolux, dim::illuminance_t, prefix::nano);
implement_unit(si, si, microlux, _microlux, dim::illuminance_t, prefix::micro);
implement_unit(si, si, millilux, _millilux, dim::illuminance_t, prefix::milli);
implement_unit(si, si, centilux, _centilux, dim::illuminance_t, prefix::centi);
implement_unit(si, si, decilux, _decilux, dim::illuminance_t, prefix::deci);
implement_unit(si, si, lux, _lux, dim::illuminance_t, prefix::one);
implement_unit(si, si, decalux, _decalux, dim::illuminance_t, prefix::deca);
implement_unit(si, si, hectolux, _hectolux, dim::illuminance_t, prefix::hecto);
implement_unit(si, si, kilolux, _kilolux, dim::illuminance_t, prefix::kilo);
implement_unit(si, si, megalux, _megalux, dim::illuminance_t, prefix::mega);
implement_unit(si, si, gigalux, _gigalux, dim::illuminance_t, prefix::giga);
implement_unit(si, si, teralux, _teralux, dim::illuminance_t, prefix::tera);
implement_unit(si, si, petalux, _petalux, dim::illuminance_t, prefix::peta);
implement_unit(si, si, exalux, _exalux, dim::illuminance_t, prefix::exa);
implement_unit(si, si, zettalux, _zettalux, dim::illuminance_t, prefix::zetta);
implement_unit(si, si, yottalux, _yottalux, dim::illuminance_t, prefix::yotta);
#pragma endregion
#pragma region watt per steradian(luminosity)
implement_unit(si, si, yoctowatt_per_steradian, _yoctowatt_per_steradian, dim::luminosity_t, prefix::yocto);
implement_unit(si, si, zeptowatt_per_steradian, _zeptowatt_per_steradian, dim::luminosity_t, prefix::zepto);
implement_unit(si, si, attowatt_per_steradian, _attowatt_per_steradian, dim::luminosity_t, prefix::atto);
implement_unit(si, si, femtowatt_per_steradian, _femtowatt_per_steradian, dim::luminosity_t, prefix::femto);
implement_unit(si, si, picowatt_per_steradian, _picowatt_per_steradian, dim::luminosity_t, prefix::pico);
implement_unit(si, si, nanowatt_per_steradian, _nanowatt_per_steradian, dim::luminosity_t, prefix::nano);
implement_unit(si, si, microwatt_per_steradian, _microwatt_per_steradian, dim::luminosity_t, prefix::micro);
implement_unit(si, si, milliwatt_per_steradian, _milliwatt_per_steradian, dim::luminosity_t, prefix::milli);
implement_unit(si, si, centiwatt_per_steradian, _centiwatt_per_steradian, dim::luminosity_t, prefix::centi);
implement_unit(si, si, deciwatt_per_steradian, _deciwatt_per_steradian, dim::luminosity_t, prefix::deci);
implement_unit(si, si, watt_per_steradian, _watt_per_steradian, dim::luminosity_t, prefix::one);
implement_unit(si, si, decawatt_per_steradian, _decawatt_per_steradian, dim::luminosity_t, prefix::deca);
implement_unit(si, si, hectowatt_per_steradian, _hectowatt_per_steradian, dim::luminosity_t, prefix::hecto);
implement_unit(si, si, kilowatt_per_steradian, _kilowatt_per_steradian, dim::luminosity_t, prefix::kilo);
implement_unit(si, si, megawatt_per_steradian, _megawatt_per_steradian, dim::luminosity_t, prefix::mega);
implement_unit(si, si, gigawatt_per_steradian, _gigawatt_per_steradian, dim::luminosity_t, prefix::giga);
implement_unit(si, si, terawatt_per_steradian, _terawatt_per_steradian, dim::luminosity_t, prefix::tera);
implement_unit(si, si, petawatt_per_steradian, _petawatt_per_steradian, dim::luminosity_t, prefix::peta);
implement_unit(si, si, exawatt_per_steradian, _exawatt_per_steradian, dim::luminosity_t, prefix::exa);
implement_unit(si, si, zettawatt_per_steradian, _zettawatt_per_steradian, dim::luminosity_t, prefix::zetta);
implement_unit(si, si, yottawatt_per_steradian, _yottawatt_per_steradian, dim::luminosity_t, prefix::yotta);
#pragma endregion
#pragma region becquerel(activity referred to a radionuclide)
implement_unit(si, si, yoctobecquerel, _yoctobecquerel, dim::activity_of_radionuclide_t, prefix::yocto);
implement_unit(si, si, zeptobecquerel, _zeptobecquerel, dim::activity_of_radionuclide_t, prefix::zepto);
implement_unit(si, si, attobecquerel, _attobecquerel, dim::activity_of_radionuclide_t, prefix::atto);
implement_unit(si, si, femtobecquerel, _femtobecquerel, dim::activity_of_radionuclide_t, prefix::femto);
implement_unit(si, si, picobecquerel, _picobecquerel, dim::activity_of_radionuclide_t, prefix::pico);
implement_unit(si, si, nanobecquerel, _nanobecquerel, dim::activity_of_radionuclide_t, prefix::nano);
implement_unit(si, si, microbecquerel, _microbecquerel, dim::activity_of_radionuclide_t, prefix::micro);
implement_unit(si, si, millibecquerel, _millibecquerel, dim::activity_of_radionuclide_t, prefix::milli);
implement_unit(si, si, centibecquerel, _centibecquerel, dim::activity_of_radionuclide_t, prefix::centi);
implement_unit(si, si, decibecquerel, _decibecquerel, dim::activity_of_radionuclide_t, prefix::deci);
implement_unit(si, si, becquerel, _becquerel, dim::activity_of_radionuclide_t, prefix::one);
implement_unit(si, si, decabecquerel, _decabecquerel, dim::activity_of_radionuclide_t, prefix::deca);
implement_unit(si, si, hectobecquerel, _hectobecquerel, dim::activity_of_radionuclide_t, prefix::hecto);
implement_unit(si, si, kilobecquerel, _kilobecquerel, dim::activity_of_radionuclide_t, prefix::kilo);
implement_unit(si, si, megabecquerel, _megabecquerel, dim::activity_of_radionuclide_t, prefix::mega);
implement_unit(si, si, gigabecquerel, _gigabecquerel, dim::activity_of_radionuclide_t, prefix::giga);
implement_unit(si, si, terabecquerel, _terabecquerel, dim::activity_of_radionuclide_t, prefix::tera);
implement_unit(si, si, petabecquerel, _petabecquerel, dim::activity_of_radionuclide_t, prefix::peta);
implement_unit(si, si, exabecquerel, _exabecquerel, dim::activity_of_radionuclide_t, prefix::exa);
implement_unit(si, si, zettabecquerel, _zettabecquerel, dim::activity_of_radionuclide_t, prefix::zetta);
implement_unit(si, si, yottabecquerel, _yottabecquerel, dim::activity_of_radionuclide_t, prefix::yotta);
#pragma endregion
#pragma region gray(specific energy)
implement_unit(si, si, yoctogray, _yoctogray, dim::absorbed_dose_t, prefix::yocto);
implement_unit(si, si, zeptogray, _zeptogray, dim::absorbed_dose_t, prefix::zepto);
implement_unit(si, si, attogray, _attogray, dim::absorbed_dose_t, prefix::atto);
implement_unit(si, si, femtogray, _femtogray, dim::absorbed_dose_t, prefix::femto);
implement_unit(si, si, picogray, _picogray, dim::absorbed_dose_t, prefix::pico);
implement_unit(si, si, nanogray, _nanogray, dim::absorbed_dose_t, prefix::nano);
implement_unit(si, si, microgray, _microgray, dim::absorbed_dose_t, prefix::micro);
implement_unit(si, si, milligray, _milligray, dim::absorbed_dose_t, prefix::milli);
implement_unit(si, si, centigray, _centigray, dim::absorbed_dose_t, prefix::centi);
implement_unit(si, si, decigray, _decigray, dim::absorbed_dose_t, prefix::deci);
implement_unit(si, si, gray, _gray, dim::absorbed_dose_t, prefix::one);
implement_unit(si, si, decagray, _decagray, dim::absorbed_dose_t, prefix::deca);
implement_unit(si, si, hectogray, _hectogray, dim::absorbed_dose_t, prefix::hecto);
implement_unit(si, si, kilogray, _kilogray, dim::absorbed_dose_t, prefix::kilo);
implement_unit(si, si, megagray, _megagray, dim::absorbed_dose_t, prefix::mega);
implement_unit(si, si, gigagray, _gigagray, dim::absorbed_dose_t, prefix::giga);
implement_unit(si, si, teragray, _teragray, dim::absorbed_dose_t, prefix::tera);
implement_unit(si, si, petagray, _petagray, dim::absorbed_dose_t, prefix::peta);
implement_unit(si, si, exagray, _exagray, dim::absorbed_dose_t, prefix::exa);
implement_unit(si, si, zettagray, _zettagray, dim::absorbed_dose_t, prefix::zetta);
implement_unit(si, si, yottagray, _yottagray, dim::absorbed_dose_t, prefix::yotta);
#pragma endregion
#pragma region sievert(dose equivalent)
implement_unit(si, si, yoctosievert, _yoctosievert, dim::dose_equivalent_t, prefix::yocto);
implement_unit(si, si, zeptosievert, _zeptosievert, dim::dose_equivalent_t, prefix::zepto);
implement_unit(si, si, attosievert, _attosievert, dim::dose_equivalent_t, prefix::atto);
implement_unit(si, si, femtosievert, _femtosievert, dim::dose_equivalent_t, prefix::femto);
implement_unit(si, si, picosievert, _picosievert, dim::dose_equivalent_t, prefix::pico);
implement_unit(si, si, nanosievert, _nanosievert, dim::dose_equivalent_t, prefix::nano);
implement_unit(si, si, microsievert, _microsievert, dim::dose_equivalent_t, prefix::micro);
implement_unit(si, si, millisievert, _millisievert, dim::dose_equivalent_t, prefix::milli);
implement_unit(si, si, centisievert, _centisievert, dim::dose_equivalent_t, prefix::centi);
implement_unit(si, si, decisievert, _decisievert, dim::dose_equivalent_t, prefix::deci);
implement_unit(si, si, sievert, _sievert, dim::dose_equivalent_t, prefix::one);
implement_unit(si, si, decasievert, _decasievert, dim::dose_equivalent_t, prefix::deca);
implement_unit(si, si, hectosievert, _hectosievert, dim::dose_equivalent_t, prefix::hecto);
implement_unit(si, si, kilosievert, _kilosievert, dim::dose_equivalent_t, prefix::kilo);
implement_unit(si, si, megasievert, _megasievert, dim::dose_equivalent_t, prefix::mega);
implement_unit(si, si, gigasievert, _gigasievert, dim::dose_equivalent_t, prefix::giga);
implement_unit(si, si, terasievert, _terasievert, dim::dose_equivalent_t, prefix::tera);
implement_unit(si, si, petasievert, _petasievert, dim::dose_equivalent_t, prefix::peta);
implement_unit(si, si, exasievert, _exasievert, dim::dose_equivalent_t, prefix::exa);
implement_unit(si, si, zettasievert, _zettasievert, dim::dose_equivalent_t, prefix::zetta);
implement_unit(si, si, yottasievert, _yottasievert, dim::dose_equivalent_t, prefix::yotta);
#pragma endregion
#pragma region katal(catalytic activity)
implement_unit(si, si, yoctokatal, _yoctokatal, dim::catalytic_activity_t, prefix::yocto);
implement_unit(si, si, zeptokatal, _zeptokatal, dim::catalytic_activity_t, prefix::zepto);
implement_unit(si, si, attokatal, _attokatal, dim::catalytic_activity_t, prefix::atto);
implement_unit(si, si, femtokatal, _femtokatal, dim::catalytic_activity_t, prefix::femto);
implement_unit(si, si, picokatal, _picokatal, dim::catalytic_activity_t, prefix::pico);
implement_unit(si, si, nanokatal, _nanokatal, dim::catalytic_activity_t, prefix::nano);
implement_unit(si, si, microkatal, _microkatal, dim::catalytic_activity_t, prefix::micro);
implement_unit(si, si, millikatal, _millikatal, dim::catalytic_activity_t, prefix::milli);
implement_unit(si, si, centikatal, _centikatal, dim::catalytic_activity_t, prefix::centi);
implement_unit(si, si, decikatal, _decikatal, dim::catalytic_activity_t, prefix::deci);
implement_unit(si, si, katal, _katal, dim::catalytic_activity_t, prefix::one);
implement_unit(si, si, decakatal, _decakatal, dim::catalytic_activity_t, prefix::deca);
implement_unit(si, si, hectokatal, _hectokatal, dim::catalytic_activity_t, prefix::hecto);
implement_unit(si, si, kilokatal, _kilokatal, dim::catalytic_activity_t, prefix::kilo);
implement_unit(si, si, megakatal, _megakatal, dim::catalytic_activity_t, prefix::mega);
implement_unit(si, si, gigakatal, _gigakatal, dim::catalytic_activity_t, prefix::giga);
implement_unit(si, si, terakatal, _terakatal, dim::catalytic_activity_t, prefix::tera);
implement_unit(si, si, petakatal, _petakatal, dim::catalytic_activity_t, prefix::peta);
implement_unit(si, si, exakatal, _exakatal, dim::catalytic_activity_t, prefix::exa);
implement_unit(si, si, zettakatal, _zettakatal, dim::catalytic_activity_t, prefix::zetta);
implement_unit(si, si, yottakatal, _yottakatal, dim::catalytic_activity_t, prefix::yotta);
#pragma endregion
#pragma region pascal second(dynamic viscosity)
implement_unit(si, si, yoctopascal_second, _yoctopascal_second, dim::dynamic_viscosity_t, prefix::yocto);
implement_unit(si, si, zeptopascal_second, _zeptopascal_second, dim::dynamic_viscosity_t, prefix::zepto);
implement_unit(si, si, attopascal_second, _attopascal_second, dim::dynamic_viscosity_t, prefix::atto);
implement_unit(si, si, femtopascal_second, _femtopascal_second, dim::dynamic_viscosity_t, prefix::femto);
implement_unit(si, si, picopascal_second, _picopascal_second, dim::dynamic_viscosity_t, prefix::pico);
implement_unit(si, si, nanopascal_second, _nanopascal_second, dim::dynamic_viscosity_t, prefix::nano);
implement_unit(si, si, micropascal_second, _micropascal_second, dim::dynamic_viscosity_t, prefix::micro);
implement_unit(si, si, millipascal_second, _millipascal_second, dim::dynamic_viscosity_t, prefix::milli);
implement_unit(si, si, centipascal_second, _centipascal_second, dim::dynamic_viscosity_t, prefix::centi);
implement_unit(si, si, decipascal_second, _decipascal_second, dim::dynamic_viscosity_t, prefix::deci);
implement_unit(si, si, pascal_second, _pascal_second, dim::dynamic_viscosity_t, prefix::one);
implement_unit(si, si, decapascal_second, _decapascal_second, dim::dynamic_viscosity_t, prefix::deca);
implement_unit(si, si, hectopascal_second, _hectopascal_second, dim::dynamic_viscosity_t, prefix::hecto);
implement_unit(si, si, kilopascal_second, _kilopascal_second, dim::dynamic_viscosity_t, prefix::kilo);
implement_unit(si, si, megapascal_second, _megapascal_second, dim::dynamic_viscosity_t, prefix::mega);
implement_unit(si, si, gigapascal_second, _gigapascal_second, dim::dynamic_viscosity_t, prefix::giga);
implement_unit(si, si, terapascal_second, _terapascal_second, dim::dynamic_viscosity_t, prefix::tera);
implement_unit(si, si, petapascal_second, _petapascal_second, dim::dynamic_viscosity_t, prefix::peta);
implement_unit(si, si, exapascal_second, _exapascal_second, dim::dynamic_viscosity_t, prefix::exa);
implement_unit(si, si, zettapascal_second, _zettapascal_second, dim::dynamic_viscosity_t, prefix::zetta);
implement_unit(si, si, yottapascal_second, _yottapascal_second, dim::dynamic_viscosity_t, prefix::yotta);
#pragma endregion
#pragma region pascal minute(dynamic viscosity)
implement_unit(si, si, yoctopascal_minute, _yoctopascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yocto>));
implement_unit(si, si, zeptopascal_minute, _zeptopascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zepto>));
implement_unit(si, si, attopascal_minute, _attopascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::atto>));
implement_unit(si, si, femtopascal_minute, _femtopascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::femto>));
implement_unit(si, si, picopascal_minute, _picopascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::pico>));
implement_unit(si, si, nanopascal_minute, _nanopascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::nano>));
implement_unit(si, si, micropascal_minute, _micropascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::micro>));
implement_unit(si, si, millipascal_minute, _millipascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::milli>));
implement_unit(si, si, centipascal_minute, _centipascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::centi>));
implement_unit(si, si, decipascal_minute, _decipascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deci>));
implement_unit(si, si, pascal_minute, _pascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::one>));
implement_unit(si, si, decapascal_minute, _decapascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deca>));
implement_unit(si, si, hectopascal_minute, _hectopascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::hecto>));
implement_unit(si, si, kilopascal_minute, _kilopascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::kilo>));
implement_unit(si, si, megapascal_minute, _megapascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::mega>));
implement_unit(si, si, gigapascal_minute, _gigapascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::giga>));
implement_unit(si, si, terapascal_minute, _terapascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::tera>));
implement_unit(si, si, petapascal_minute, _petapascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::peta>));
implement_unit(si, si, exapascal_minute, _exapascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::exa>));
implement_unit(si, si, zettapascal_minute, _zettapascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zetta>));
implement_unit(si, si, yottapascal_minute, _yottapascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yotta>));
#pragma endregion
#pragma region pascal hour(dynamic viscosity)
implement_unit(si, si, yoctopascal_hour, _yoctopascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yocto>));
implement_unit(si, si, zeptopascal_hour, _zeptopascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zepto>));
implement_unit(si, si, attopascal_hour, _attopascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::atto>));
implement_unit(si, si, femtopascal_hour, _femtopascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::femto>));
implement_unit(si, si, picopascal_hour, _picopascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::pico>));
implement_unit(si, si, nanopascal_hour, _nanopascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::nano>));
implement_unit(si, si, micropascal_hour, _micropascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::micro>));
implement_unit(si, si, millipascal_hour, _millipascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::milli>));
implement_unit(si, si, centipascal_hour, _centipascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::centi>));
implement_unit(si, si, decipascal_hour, _decipascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deci>));
implement_unit(si, si, pascal_hour, _pascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::one>));
implement_unit(si, si, decapascal_hour, _decapascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deca>));
implement_unit(si, si, hectopascal_hour, _hectopascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::hecto>));
implement_unit(si, si, kilopascal_hour, _kilopascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::kilo>));
implement_unit(si, si, megapascal_hour, _megapascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::mega>));
implement_unit(si, si, gigapascal_hour, _gigapascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::giga>));
implement_unit(si, si, terapascal_hour, _terapascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::tera>));
implement_unit(si, si, petapascal_hour, _petapascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::peta>));
implement_unit(si, si, exapascal_hour, _exapascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::exa>));
implement_unit(si, si, zettapascal_hour, _zettapascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zetta>));
implement_unit(si, si, yottapascal_hour, _yottapascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yotta>));
#pragma endregion
#pragma region joule per radian(torque)
implement_unit(si, si, yoctojoule_per_radian, _yoctojoule_per_radian, dim::torque_t, prefix::yocto);
implement_unit(si, si, zeptojoule_per_radian, _zeptojoule_per_radian, dim::torque_t, prefix::zepto);
implement_unit(si, si, attojoule_per_radian, _attojoule_per_radian, dim::torque_t, prefix::atto);
implement_unit(si, si, femtojoule_per_radian, _femtojoule_per_radian, dim::torque_t, prefix::femto);
implement_unit(si, si, picojoule_per_radian, _picojoule_per_radian, dim::torque_t, prefix::pico);
implement_unit(si, si, nanojoule_per_radian, _nanojoule_per_radian, dim::torque_t, prefix::nano);
implement_unit(si, si, microjoule_per_radian, _microjoule_per_radian, dim::torque_t, prefix::micro);
implement_unit(si, si, millijoule_per_radian, _millijoule_per_radian, dim::torque_t, prefix::milli);
implement_unit(si, si, centijoule_per_radian, _centijoule_per_radian, dim::torque_t, prefix::centi);
implement_unit(si, si, decijoule_per_radian, _decijoule_per_radian, dim::torque_t, prefix::deci);
implement_unit(si, si, joule_per_radian, _joule_per_radian, dim::torque_t, prefix::one);
implement_unit(si, si, decajoule_per_radian, _decajoule_per_radian, dim::torque_t, prefix::deca);
implement_unit(si, si, hectojoule_per_radian, _hectojoule_per_radian, dim::torque_t, prefix::hecto);
implement_unit(si, si, kilojoule_per_radian, _kilojoule_per_radian, dim::torque_t, prefix::kilo);
implement_unit(si, si, megajoule_per_radian, _megajoule_per_radian, dim::torque_t, prefix::mega);
implement_unit(si, si, gigajoule_per_radian, _gigajoule_per_radian, dim::torque_t, prefix::giga);
implement_unit(si, si, terajoule_per_radian, _terajoule_per_radian, dim::torque_t, prefix::tera);
implement_unit(si, si, petajoule_per_radian, _petajoule_per_radian, dim::torque_t, prefix::peta);
implement_unit(si, si, exajoule_per_radian, _exajoule_per_radian, dim::torque_t, prefix::exa);
implement_unit(si, si, zettajoule_per_radian, _zettajoule_per_radian, dim::torque_t, prefix::zetta);
implement_unit(si, si, yottajoule_per_radian, _yottajoule_per_radian, dim::torque_t, prefix::yotta);
#pragma endregion
#pragma region joule per degree, ...(torque)
implement_unit(si, si, joule_per_degree, _joule_per_degree, dim::torque_t, fix(impl::divide_lists_t<prefix::one, impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 180>>>));
implement_unit(si, si, joule_per_arcminute, _joule_per_arcminute, dim::torque_t, fix(impl::divide_lists_t<prefix::one, impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 10800>>>));
implement_unit(si, si, joule_per_arcsecond, _joule_per_arcsecond, dim::torque_t, fix(impl::divide_lists_t<prefix::one, impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 648000>>>));
#pragma endregion
#pragma region radian per second(angular velocity)
implement_unit(si, si, yoctoradian_per_second, _yoctoradian_per_second, dim::angular_velocity_t, prefix::yocto);
implement_unit(si, si, zeptoradian_per_second, _zeptoradian_per_second, dim::angular_velocity_t, prefix::zepto);
implement_unit(si, si, attoradian_per_second, _attoradian_per_second, dim::angular_velocity_t, prefix::atto);
implement_unit(si, si, femtoradian_per_second, _femtoradian_per_second, dim::angular_velocity_t, prefix::femto);
implement_unit(si, si, picoradian_per_second, _picoradian_per_second, dim::angular_velocity_t, prefix::pico);
implement_unit(si, si, nanoradian_per_second, _nanoradian_per_second, dim::angular_velocity_t, prefix::nano);
implement_unit(si, si, microradian_per_second, _microradian_per_second, dim::angular_velocity_t, prefix::micro);
implement_unit(si, si, milliradian_per_second, _milliradian_per_second, dim::angular_velocity_t, prefix::milli);
implement_unit(si, si, centiradian_per_second, _centiradian_per_second, dim::angular_velocity_t, prefix::centi);
implement_unit(si, si, deciradian_per_second, _deciradian_per_second, dim::angular_velocity_t, prefix::deci);
implement_unit(si, si, radian_per_second, _radian_per_second, dim::angular_velocity_t, prefix::one);
implement_unit(si, si, degree_per_second, _degree_per_second, dim::angular_velocity_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 180>>));
implement_unit(si, si, arcminute_per_second, _arcminute_per_second, dim::angular_velocity_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 10800>>));
implement_unit(si, si, arcsecond_per_second, _arcsecond_per_second, dim::angular_velocity_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 648000>>));
#pragma endregion
#pragma region radian per minute(angular velocity)
implement_unit(si, si, yoctoradian_per_minute, _yoctoradian_per_minute, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::yocto, prefix::minute>));
implement_unit(si, si, zeptoradian_per_minute, _zeptoradian_per_minute, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::zepto, prefix::minute>));
implement_unit(si, si, attoradian_per_minute, _attoradian_per_minute, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::atto, prefix::minute>));
implement_unit(si, si, femtoradian_per_minute, _femtoradian_per_minute, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::femto, prefix::minute>));
implement_unit(si, si, picoradian_per_minute, _picoradian_per_minute, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::pico, prefix::minute>));
implement_unit(si, si, nanoradian_per_minute, _nanoradian_per_minute, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::nano, prefix::minute>));
implement_unit(si, si, microradian_per_minute, _microradian_per_minute, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::micro, prefix::minute>));
implement_unit(si, si, milliradian_per_minute, _milliradian_per_minute, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::milli, prefix::minute>));
implement_unit(si, si, centiradian_per_minute, _centiradian_per_minute, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::centi, prefix::minute>));
implement_unit(si, si, deciradian_per_minute, _deciradian_per_minute, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::deci, prefix::minute>));
implement_unit(si, si, radian_per_minute, _radian_per_minute, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::one, prefix::minute>));
link_unit(degree_per_minute, _degree_per_minute, arcminute_per_second);
link_unit(arcminute_per_minute, _arcminute_per_minute, arcsecond_per_second);
implement_unit(si, si, arcsecond_per_minute, _arcsecond_per_minute, dim::angular_velocity_t, fix(impl::divide_lists_t<impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 648000>>, prefix::minute>));
#pragma endregion
#pragma region radian per hour(angular velocity)
implement_unit(si, si, yoctoradian_per_hour, _yoctoradian_per_hour, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::yocto, prefix::hour>));
implement_unit(si, si, zeptoradian_per_hour, _zeptoradian_per_hour, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::zepto, prefix::hour>));
implement_unit(si, si, attoradian_per_hour, _attoradian_per_hour, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::atto, prefix::hour>));
implement_unit(si, si, femtoradian_per_hour, _femtoradian_per_hour, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::femto, prefix::hour>));
implement_unit(si, si, picoradian_per_hour, _picoradian_per_hour, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::pico, prefix::hour>));
implement_unit(si, si, nanoradian_per_hour, _nanoradian_per_hour, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::nano, prefix::hour>));
implement_unit(si, si, microradian_per_hour, _microradian_per_hour, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::micro, prefix::hour>));
implement_unit(si, si, milliradian_per_hour, _milliradian_per_hour, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::milli, prefix::hour>));
implement_unit(si, si, centiradian_per_hour, _centiradian_per_hour, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::centi, prefix::hour>));
implement_unit(si, si, deciradian_per_hour, _deciradian_per_hour, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::deci, prefix::hour>));
implement_unit(si, si, radian_per_hour, _radian_per_hour, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::one, prefix::hour>));
link_unit(degree_per_hour, _degree_per_hour, arcsecond_per_second);
link_unit(arcminute_per_hour, _arcminute_per_hour, arcsecond_per_minute);
implement_unit(si, si, arcsecond_per_hour, _arcsecond_per_hour, dim::angular_velocity_t, fix(impl::divide_lists_t<impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 648000>>, prefix::hour>));
#pragma endregion
#pragma region radian per square second(angular acceleration)
implement_unit(si, si, yoctoradian_per_square_second, _yoctoradian_per_square_second, dim::angular_acceleration_t, prefix::yocto);
implement_unit(si, si, zeptoradian_per_square_second, _zeptoradian_per_square_second, dim::angular_acceleration_t, prefix::zepto);
implement_unit(si, si, attoradian_per_square_second, _attoradian_per_square_second, dim::angular_acceleration_t, prefix::atto);
implement_unit(si, si, femtoradian_per_square_second, _femtoradian_per_square_second, dim::angular_acceleration_t, prefix::femto);
implement_unit(si, si, picoradian_per_square_second, _picoradian_per_square_second, dim::angular_acceleration_t, prefix::pico);
implement_unit(si, si, nanoradian_per_square_second, _nanoradian_per_square_second, dim::angular_acceleration_t, prefix::nano);
implement_unit(si, si, microradian_per_square_second, _microradian_per_square_second, dim::angular_acceleration_t, prefix::micro);
implement_unit(si, si, milliradian_per_square_second, _milliradian_per_square_second, dim::angular_acceleration_t, prefix::milli);
implement_unit(si, si, centiradian_per_square_second, _centiradian_per_square_second, dim::angular_acceleration_t, prefix::centi);
implement_unit(si, si, deciradian_per_square_second, _deciradian_per_square_second, dim::angular_acceleration_t, prefix::deci);
implement_unit(si, si, radian_per_square_second, _radian_per_square_second, dim::angular_acceleration_t, prefix::one);
implement_unit(si, si, degree_per_square_second, _degree_per_square_second, dim::angular_acceleration_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 180>>));
implement_unit(si, si, arcminute_per_square_second, _arcminute_per_square_second, dim::angular_acceleration_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 10800>>));
implement_unit(si, si, arcsecond_per_square_second, _arcsecond_per_square_second, dim::angular_acceleration_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 648000>>));
#pragma endregion
#pragma region radian per square minute(angular acceleration)
implement_unit(si, si, yoctoradian_per_square_minute, _yoctoradian_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::yocto, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, zeptoradian_per_square_minute, _zeptoradian_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::zepto, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, attoradian_per_square_minute, _attoradian_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::atto, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, femtoradian_per_square_minute, _femtoradian_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::femto, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, picoradian_per_square_minute, _picoradian_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::pico, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, nanoradian_per_square_minute, _nanoradian_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::nano, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, microradian_per_square_minute, _microradian_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::micro, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, milliradian_per_square_minute, _milliradian_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::milli, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, centiradian_per_square_minute, _centiradian_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::centi, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, deciradian_per_square_minute, _deciradian_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::deci, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, radian_per_square_minute, _radian_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::one, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
link_unit(degree_per_square_minute, _degree_per_square_minute, arcsecond_per_square_second);
implement_unit(si, si, arcminute_per_square_minute, _arcminute_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 648000>>, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, arcsecond_per_square_minute, _arcsecond_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 10800>>, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
#pragma endregion
#pragma region radian per hour(angular acceleration)
implement_unit(si, si, yoctoradian_per_square_hour, _yoctoradian_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::yocto, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, zeptoradian_per_square_hour, _zeptoradian_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::zepto, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, attoradian_per_square_hour, _attoradian_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::atto, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, femtoradian_per_square_hour, _femtoradian_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::femto, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, picoradian_per_square_hour, _picoradian_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::pico, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, nanoradian_per_square_hour, _nanoradian_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::nano, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, microradian_per_square_hour, _microradian_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::micro, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, milliradian_per_square_hour, _milliradian_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::milli, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, centiradian_per_square_hour, _centiradian_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::centi, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, deciradian_per_square_hour, _deciradian_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::deci, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, radian_per_square_hour, _radian_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::one, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
link_unit(degree_per_square_hour, _degree_per_square_hour, arcminute_per_square_minute);
implement_unit(si, si, arcminute_per_square_hour, _arcminute_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 648000>>, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, arcsecond_per_square_hour, _arcsecond_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 10800>>, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
#pragma endregion
#pragma region watt per square metre(heat flux density)
implement_unit(si, si, yoctowatt_per_square_metre, _yoctowatt_per_square_metre, dim::heat_flux_density_t, prefix::yocto);
implement_unit(si, si, zeptowatt_per_square_metre, _zeptowatt_per_square_metre, dim::heat_flux_density_t, prefix::zepto);
implement_unit(si, si, attowatt_per_square_metre, _attowatt_per_square_metre, dim::heat_flux_density_t, prefix::atto);
implement_unit(si, si, femtowatt_per_square_metre, _femtowatt_per_square_metre, dim::heat_flux_density_t, prefix::femto);
implement_unit(si, si, picowatt_per_square_metre, _picowatt_per_square_metre, dim::heat_flux_density_t, prefix::pico);
implement_unit(si, si, nanowatt_per_square_metre, _nanowatt_per_square_metre, dim::heat_flux_density_t, prefix::nano);
implement_unit(si, si, microwatt_per_square_metre, _microwatt_per_square_metre, dim::heat_flux_density_t, prefix::micro);
implement_unit(si, si, milliwatt_per_square_metre, _milliwatt_per_square_metre, dim::heat_flux_density_t, prefix::milli);
implement_unit(si, si, centiwatt_per_square_metre, _centiwatt_per_square_metre, dim::heat_flux_density_t, prefix::centi);
implement_unit(si, si, deciwatt_per_square_metre, _deciwatt_per_square_metre, dim::heat_flux_density_t, prefix::deci);
implement_unit(si, si, watt_per_square_metre, _watt_per_square_metre, dim::heat_flux_density_t, prefix::one);
implement_unit(si, si, decawatt_per_square_metre, _decawatt_per_square_metre, dim::heat_flux_density_t, prefix::deca);
implement_unit(si, si, hectowatt_per_square_metre, _hectowatt_per_square_metre, dim::heat_flux_density_t, prefix::hecto);
implement_unit(si, si, kilowatt_per_square_metre, _kilowatt_per_square_metre, dim::heat_flux_density_t, prefix::kilo);
implement_unit(si, si, megawatt_per_square_metre, _megawatt_per_square_metre, dim::heat_flux_density_t, prefix::mega);
implement_unit(si, si, gigawatt_per_square_metre, _gigawatt_per_square_metre, dim::heat_flux_density_t, prefix::giga);
implement_unit(si, si, terawatt_per_square_metre, _terawatt_per_square_metre, dim::heat_flux_density_t, prefix::tera);
implement_unit(si, si, petawatt_per_square_metre, _petawatt_per_square_metre, dim::heat_flux_density_t, prefix::peta);
implement_unit(si, si, exawatt_per_square_metre, _exawatt_per_square_metre, dim::heat_flux_density_t, prefix::exa);
implement_unit(si, si, zettawatt_per_square_metre, _zettawatt_per_square_metre, dim::heat_flux_density_t, prefix::zetta);
implement_unit(si, si, yottawatt_per_square_metre, _yottawatt_per_square_metre, dim::heat_flux_density_t, prefix::yotta);
#pragma endregion
#pragma region watt per square metre hertz(spectral heat flux density)
implement_unit(si, si, yoctowatt_per_square_metre_hertz, _yoctowatt_per_square_metre_hertz, dim::surface_tension_t, prefix::yocto);
implement_unit(si, si, zeptowatt_per_square_metre_hertz, _zeptowatt_per_square_metre_hertz, dim::surface_tension_t, prefix::zepto);
implement_unit(si, si, attowatt_per_square_metre_hertz, _attowatt_per_square_metre_hertz, dim::surface_tension_t, prefix::atto);
implement_unit(si, si, femtowatt_per_square_metre_hertz, _femtowatt_per_square_metre_hertz, dim::surface_tension_t, prefix::femto);
implement_unit(si, si, picowatt_per_square_metre_hertz, _picowatt_per_square_metre_hertz, dim::surface_tension_t, prefix::pico);
implement_unit(si, si, nanowatt_per_square_metre_hertz, _nanowatt_per_square_metre_hertz, dim::surface_tension_t, prefix::nano);
implement_unit(si, si, microwatt_per_square_metre_hertz, _microwatt_per_square_metre_hertz, dim::surface_tension_t, prefix::micro);
implement_unit(si, si, milliwatt_per_square_metre_hertz, _milliwatt_per_square_metre_hertz, dim::surface_tension_t, prefix::milli);
implement_unit(si, si, centiwatt_per_square_metre_hertz, _centiwatt_per_square_metre_hertz, dim::surface_tension_t, prefix::centi);
implement_unit(si, si, deciwatt_per_square_metre_hertz, _deciwatt_per_square_metre_hertz, dim::surface_tension_t, prefix::deci);
implement_unit(si, si, watt_per_square_metre_hertz, _watt_per_square_metre_hertz, dim::surface_tension_t, prefix::one);
implement_unit(si, si, decawatt_per_square_metre_hertz, _decawatt_per_square_metre_hertz, dim::surface_tension_t, prefix::deca);
implement_unit(si, si, hectowatt_per_square_metre_hertz, _hectowatt_per_square_metre_hertz, dim::surface_tension_t, prefix::hecto);
implement_unit(si, si, kilowatt_per_square_metre_hertz, _kilowatt_per_square_metre_hertz, dim::surface_tension_t, prefix::kilo);
implement_unit(si, si, megawatt_per_square_metre_hertz, _megawatt_per_square_metre_hertz, dim::surface_tension_t, prefix::mega);
implement_unit(si, si, gigawatt_per_square_metre_hertz, _gigawatt_per_square_metre_hertz, dim::surface_tension_t, prefix::giga);
implement_unit(si, si, terawatt_per_square_metre_hertz, _terawatt_per_square_metre_hertz, dim::surface_tension_t, prefix::tera);
implement_unit(si, si, petawatt_per_square_metre_hertz, _petawatt_per_square_metre_hertz, dim::surface_tension_t, prefix::peta);
implement_unit(si, si, exawatt_per_square_metre_hertz, _exawatt_per_square_metre_hertz, dim::surface_tension_t, prefix::exa);
implement_unit(si, si, zettawatt_per_square_metre_hertz, _zettawatt_per_square_metre_hertz, dim::surface_tension_t, prefix::zetta);
implement_unit(si, si, yottawatt_per_square_metre_hertz, _yottawatt_per_square_metre_hertz, dim::surface_tension_t, prefix::yotta);
#pragma endregion
#pragma region jansky(spectral heat flux density)
implement_unit(si, si, yoctojansky, _yoctojansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::yocto>));
implement_unit(si, si, zeptojansky, _zeptojansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::zepto>));
implement_unit(si, si, attojansky, _attojansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::atto>));
implement_unit(si, si, femtojansky, _femtojansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::femto>));
implement_unit(si, si, picojansky, _picojansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::pico>));
implement_unit(si, si, nanojansky, _nanojansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::nano>));
implement_unit(si, si, microjansky, _microjansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::micro>));
implement_unit(si, si, millijansky, _millijansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::milli>));
implement_unit(si, si, centijansky, _centijansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::centi>));
implement_unit(si, si, decijansky, _decijansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::deci>));
implement_unit(si, si, jansky, _jansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::one>));
implement_unit(si, si, decajansky, _decajansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::deca>));
link_unit(hectojansky, _hectojansky, yoctowatt_per_square_metre_hertz);
implement_unit(si, si, kilojansky, _kilojansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::kilo>));
implement_unit(si, si, megajansky, _megajansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::mega>));
implement_unit(si, si, gigajansky, _gigajansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::giga>));
implement_unit(si, si, terajansky, _terajansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::tera>));
implement_unit(si, si, petajansky, _petajansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::peta>));
implement_unit(si, si, exajansky, _exajansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::exa>));
implement_unit(si, si, zettajansky, _zettajansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::zetta>));
link_unit(yottajansky, _yottajansky, centiwatt_per_square_metre_hertz);
#pragma endregion
#pragma region joule per kelvin(heat capacity)
implement_unit(si, si, yoctojoule_per_kelvin, _yoctojoule_per_kelvin, dim::heat_capacity_t, prefix::yocto);
implement_unit(si, si, zeptojoule_per_kelvin, _zeptojoule_per_kelvin, dim::heat_capacity_t, prefix::zepto);
implement_unit(si, si, attojoule_per_kelvin, _attojoule_per_kelvin, dim::heat_capacity_t, prefix::atto);
implement_unit(si, si, femtojoule_per_kelvin, _femtojoule_per_kelvin, dim::heat_capacity_t, prefix::femto);
implement_unit(si, si, picojoule_per_kelvin, _picojoule_per_kelvin, dim::heat_capacity_t, prefix::pico);
implement_unit(si, si, nanojoule_per_kelvin, _nanojoule_per_kelvin, dim::heat_capacity_t, prefix::nano);
implement_unit(si, si, microjoule_per_kelvin, _microjoule_per_kelvin, dim::heat_capacity_t, prefix::micro);
implement_unit(si, si, millijoule_per_kelvin, _millijoule_per_kelvin, dim::heat_capacity_t, prefix::milli);
implement_unit(si, si, centijoule_per_kelvin, _centijoule_per_kelvin, dim::heat_capacity_t, prefix::centi);
implement_unit(si, si, decijoule_per_kelvin, _decijoule_per_kelvin, dim::heat_capacity_t, prefix::deci);
implement_unit(si, si, joule_per_kelvin, _joule_per_kelvin, dim::heat_capacity_t, prefix::one);
implement_unit(si, si, decajoule_per_kelvin, _decajoule_per_kelvin, dim::heat_capacity_t, prefix::deca);
implement_unit(si, si, hectojoule_per_kelvin, _hectojoule_per_kelvin, dim::heat_capacity_t, prefix::hecto);
implement_unit(si, si, kilojoule_per_kelvin, _kilojoule_per_kelvin, dim::heat_capacity_t, prefix::kilo);
implement_unit(si, si, megajoule_per_kelvin, _megajoule_per_kelvin, dim::heat_capacity_t, prefix::mega);
implement_unit(si, si, gigajoule_per_kelvin, _gigajoule_per_kelvin, dim::heat_capacity_t, prefix::giga);
implement_unit(si, si, terajoule_per_kelvin, _terajoule_per_kelvin, dim::heat_capacity_t, prefix::tera);
implement_unit(si, si, petajoule_per_kelvin, _petajoule_per_kelvin, dim::heat_capacity_t, prefix::peta);
implement_unit(si, si, exajoule_per_kelvin, _exajoule_per_kelvin, dim::heat_capacity_t, prefix::exa);
implement_unit(si, si, zettajoule_per_kelvin, _zettajoule_per_kelvin, dim::heat_capacity_t, prefix::zetta);
implement_unit(si, si, yottajoule_per_kelvin, _yottajoule_per_kelvin, dim::heat_capacity_t, prefix::yotta);
#pragma endregion
#pragma region joule per kilogram kelvin(specific heat capacity)
implement_unit(si, si, yoctojoule_per_kilogram_kelvin, _yoctojoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::yocto);
implement_unit(si, si, zeptojoule_per_kilogram_kelvin, _zeptojoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::zepto);
implement_unit(si, si, attojoule_per_kilogram_kelvin, _attojoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::atto);
implement_unit(si, si, femtojoule_per_kilogram_kelvin, _femtojoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::femto);
implement_unit(si, si, picojoule_per_kilogram_kelvin, _picojoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::pico);
implement_unit(si, si, nanojoule_per_kilogram_kelvin, _nanojoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::nano);
implement_unit(si, si, microjoule_per_kilogram_kelvin, _microjoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::micro);
implement_unit(si, si, millijoule_per_kilogram_kelvin, _millijoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::milli);
implement_unit(si, si, centijoule_per_kilogram_kelvin, _centijoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::centi);
implement_unit(si, si, decijoule_per_kilogram_kelvin, _decijoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::deci);
implement_unit(si, si, joule_per_kilogram_kelvin, _joule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::one);
implement_unit(si, si, decajoule_per_kilogram_kelvin, _decajoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::deca);
implement_unit(si, si, hectojoule_per_kilogram_kelvin, _hectojoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::hecto);
implement_unit(si, si, kilojoule_per_kilogram_kelvin, _kilojoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::kilo);
implement_unit(si, si, megajoule_per_kilogram_kelvin, _megajoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::mega);
implement_unit(si, si, gigajoule_per_kilogram_kelvin, _gigajoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::giga);
implement_unit(si, si, terajoule_per_kilogram_kelvin, _terajoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::tera);
implement_unit(si, si, petajoule_per_kilogram_kelvin, _petajoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::peta);
implement_unit(si, si, exajoule_per_kilogram_kelvin, _exajoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::exa);
implement_unit(si, si, zettajoule_per_kilogram_kelvin, _zettajoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::zetta);
implement_unit(si, si, yottajoule_per_kilogram_kelvin, _yottajoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::yotta);
#pragma endregion
#pragma region joule per kilogram(specific energy)
link_unit(yoctojoule_per_kilogram, _yoctojoule_per_kilogram, yoctogray);
link_unit(zeptojoule_per_kilogram, _zeptojoule_per_kilogram, zeptogray);
link_unit(attojoule_per_kilogram, _attojoule_per_kilogram, attogray);
link_unit(femtojoule_per_kilogram, _femtojoule_per_kilogram, femtogray);
link_unit(picojoule_per_kilogram, _picojoule_per_kilogram, picogray);
link_unit(nanojoule_per_kilogram, _nanojoule_per_kilogram, nanogray);
link_unit(microjoule_per_kilogram, _microjoule_per_kilogram, microgray);
link_unit(millijoule_per_kilogram, _millijoule_per_kilogram, milligray);
link_unit(centijoule_per_kilogram, _centijoule_per_kilogram, centigray);
link_unit(decijoule_per_kilogram, _decijoule_per_kilogram, decigray);
link_unit(joule_per_kilogram, _joule_per_kilogram, gray);
link_unit(decajoule_per_kilogram, _decajoule_per_kilogram, decagray);
link_unit(hectojoule_per_kilogram, _hectojoule_per_kilogram, hectogray);
link_unit(kilojoule_per_kilogram, _kilojoule_per_kilogram, kilogray);
link_unit(megajoule_per_kilogram, _megajoule_per_kilogram, megagray);
link_unit(gigajoule_per_kilogram, _gigajoule_per_kilogram, gigagray);
link_unit(terajoule_per_kilogram, _terajoule_per_kilogram, teragray);
link_unit(petajoule_per_kilogram, _petajoule_per_kilogram, petagray);
link_unit(exajoule_per_kilogram, _exajoule_per_kilogram, exagray);
link_unit(zettajoule_per_kilogram, _zettajoule_per_kilogram, zettagray);
link_unit(yottajoule_per_kilogram, _yottajoule_per_kilogram, yottagray);
#pragma endregion
#pragma region watt per metre kelvin(thermal conductivity)
implement_unit(si, si, yoctowatt_per_metre_kelvin, _yoctowatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::yocto);
implement_unit(si, si, zeptowatt_per_metre_kelvin, _zeptowatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::zepto);
implement_unit(si, si, attowatt_per_metre_kelvin, _attowatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::atto);
implement_unit(si, si, femtowatt_per_metre_kelvin, _femtowatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::femto);
implement_unit(si, si, picowatt_per_metre_kelvin, _picowatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::pico);
implement_unit(si, si, nanowatt_per_metre_kelvin, _nanowatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::nano);
implement_unit(si, si, microwatt_per_metre_kelvin, _microwatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::micro);
implement_unit(si, si, milliwatt_per_metre_kelvin, _milliwatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::milli);
implement_unit(si, si, centiwatt_per_metre_kelvin, _centiwatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::centi);
implement_unit(si, si, deciwatt_per_metre_kelvin, _deciwatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::deci);
implement_unit(si, si, watt_per_metre_kelvin, _watt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::one);
implement_unit(si, si, decawatt_per_metre_kelvin, _decawatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::deca);
implement_unit(si, si, hectowatt_per_metre_kelvin, _hectowatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::hecto);
implement_unit(si, si, kilowatt_per_metre_kelvin, _kilowatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::kilo);
implement_unit(si, si, megawatt_per_metre_kelvin, _megawatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::mega);
implement_unit(si, si, gigawatt_per_metre_kelvin, _gigawatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::giga);
implement_unit(si, si, terawatt_per_metre_kelvin, _terawatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::tera);
implement_unit(si, si, petawatt_per_metre_kelvin, _petawatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::peta);
implement_unit(si, si, exawatt_per_metre_kelvin, _exawatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::exa);
implement_unit(si, si, zettawatt_per_metre_kelvin, _zettawatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::zetta);
implement_unit(si, si, yottawatt_per_metre_kelvin, _yottawatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::yotta);
#pragma endregion
#pragma region joule per cubic metre(energy density)
link_unit(yoctojoule_per_cubic_metre, _yoctojoule_per_cubic_metre, yoctopascal);
link_unit(zeptojoule_per_cubic_metre, _zeptojoule_per_cubic_metre, zeptopascal);
link_unit(attojoule_per_cubic_metre, _attojoule_per_cubic_metre, attopascal);
link_unit(femtojoule_per_cubic_metre, _femtojoule_per_cubic_metre, femtopascal);
link_unit(picojoule_per_cubic_metre, _picojoule_per_cubic_metre, picopascal);
link_unit(nanojoule_per_cubic_metre, _nanojoule_per_cubic_metre, nanopascal);
link_unit(microjoule_per_cubic_metre, _microjoule_per_cubic_metre, micropascal);
link_unit(millijoule_per_cubic_metre, _millijoule_per_cubic_metre, millipascal);
link_unit(centijoule_per_cubic_metre, _centijoule_per_cubic_metre, centipascal);
link_unit(decijoule_per_cubic_metre, _decijoule_per_cubic_metre, decipascal);
link_unit(joule_per_cubic_metre, _joule_per_cubic_metre, pascal);
link_unit(decajoule_per_cubic_metre, _decajoule_per_cubic_metre, decapascal);
link_unit(hectojoule_per_cubic_metre, _hectojoule_per_cubic_metre, hectopascal);
link_unit(kilojoule_per_cubic_metre, _kilojoule_per_cubic_metre, kilopascal);
link_unit(megajoule_per_cubic_metre, _megajoule_per_cubic_metre, megapascal);
link_unit(gigajoule_per_cubic_metre, _gigajoule_per_cubic_metre, gigapascal);
link_unit(terajoule_per_cubic_metre, _terajoule_per_cubic_metre, terapascal);
link_unit(petajoule_per_cubic_metre, _petajoule_per_cubic_metre, petapascal);
link_unit(exajoule_per_cubic_metre, _exajoule_per_cubic_metre, exapascal);
link_unit(zettajoule_per_cubic_metre, _zettajoule_per_cubic_metre, zettapascal);
link_unit(yottajoule_per_cubic_metre, _yottajoule_per_cubic_metre, yottapascal);
#pragma endregion
#pragma region volt per metre(electric field strength)
implement_unit(si, si, yoctovolt_per_metre, _yoctovolt_per_metre, dim::electric_field_strength_t, prefix::yocto);
implement_unit(si, si, zeptovolt_per_metre, _zeptovolt_per_metre, dim::electric_field_strength_t, prefix::zepto);
implement_unit(si, si, attovolt_per_metre, _attovolt_per_metre, dim::electric_field_strength_t, prefix::atto);
implement_unit(si, si, femtovolt_per_metre, _femtovolt_per_metre, dim::electric_field_strength_t, prefix::femto);
implement_unit(si, si, picovolt_per_metre, _picovolt_per_metre, dim::electric_field_strength_t, prefix::pico);
implement_unit(si, si, nanovolt_per_metre, _nanovolt_per_metre, dim::electric_field_strength_t, prefix::nano);
implement_unit(si, si, microvolt_per_metre, _microvolt_per_metre, dim::electric_field_strength_t, prefix::micro);
implement_unit(si, si, millivolt_per_metre, _millivolt_per_metre, dim::electric_field_strength_t, prefix::milli);
implement_unit(si, si, centivolt_per_metre, _centivolt_per_metre, dim::electric_field_strength_t, prefix::centi);
implement_unit(si, si, decivolt_per_metre, _decivolt_per_metre, dim::electric_field_strength_t, prefix::deci);
implement_unit(si, si, volt_per_metre, _volt_per_metre, dim::electric_field_strength_t, prefix::one);
implement_unit(si, si, decavolt_per_metre, _decavolt_per_metre, dim::electric_field_strength_t, prefix::deca);
implement_unit(si, si, hectovolt_per_metre, _hectovolt_per_metre, dim::electric_field_strength_t, prefix::hecto);
implement_unit(si, si, kilovolt_per_metre, _kilovolt_per_metre, dim::electric_field_strength_t, prefix::kilo);
implement_unit(si, si, megavolt_per_metre, _megavolt_per_metre, dim::electric_field_strength_t, prefix::mega);
implement_unit(si, si, gigavolt_per_metre, _gigavolt_per_metre, dim::electric_field_strength_t, prefix::giga);
implement_unit(si, si, teravolt_per_metre, _teravolt_per_metre, dim::electric_field_strength_t, prefix::tera);
implement_unit(si, si, petavolt_per_metre, _petavolt_per_metre, dim::electric_field_strength_t, prefix::peta);
implement_unit(si, si, exavolt_per_metre, _exavolt_per_metre, dim::electric_field_strength_t, prefix::exa);
implement_unit(si, si, zettavolt_per_metre, _zettavolt_per_metre, dim::electric_field_strength_t, prefix::zetta);
implement_unit(si, si, yottavolt_per_metre, _yottavolt_per_metre, dim::electric_field_strength_t, prefix::yotta);
#pragma endregion
#pragma region coulomb per cubic metre(electric charge density)
implement_unit(si, si, yoctocoulomb_per_cubic_metre, _yoctocoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::yocto);
implement_unit(si, si, zeptocoulomb_per_cubic_metre, _zeptocoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::zepto);
implement_unit(si, si, attocoulomb_per_cubic_metre, _attocoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::atto);
implement_unit(si, si, femtocoulomb_per_cubic_metre, _femtocoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::femto);
implement_unit(si, si, picocoulomb_per_cubic_metre, _picocoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::pico);
implement_unit(si, si, nanocoulomb_per_cubic_metre, _nanocoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::nano);
implement_unit(si, si, microcoulomb_per_cubic_metre, _microcoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::micro);
implement_unit(si, si, millicoulomb_per_cubic_metre, _millicoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::milli);
implement_unit(si, si, centicoulomb_per_cubic_metre, _centicoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::centi);
implement_unit(si, si, decicoulomb_per_cubic_metre, _decicoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::deci);
implement_unit(si, si, coulomb_per_cubic_metre, _coulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::one);
implement_unit(si, si, decacoulomb_per_cubic_metre, _decacoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::deca);
implement_unit(si, si, hectocoulomb_per_cubic_metre, _hectocoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::hecto);
implement_unit(si, si, kilocoulomb_per_cubic_metre, _kilocoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::kilo);
implement_unit(si, si, megacoulomb_per_cubic_metre, _megacoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::mega);
implement_unit(si, si, gigacoulomb_per_cubic_metre, _gigacoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::giga);
implement_unit(si, si, teracoulomb_per_cubic_metre, _teracoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::tera);
implement_unit(si, si, petacoulomb_per_cubic_metre, _petacoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::peta);
implement_unit(si, si, exacoulomb_per_cubic_metre, _exacoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::exa);
implement_unit(si, si, zettacoulomb_per_cubic_metre, _zettacoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::zetta);
implement_unit(si, si, yottacoulomb_per_cubic_metre, _yottacoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::yotta);
#pragma endregion
#pragma region coulomb per square metre(electric charge density)
implement_unit(si, si, yoctocoulomb_per_square_metre, _yoctocoulomb_per_square_metre, dim::electric_flux_density_t, prefix::yocto);
implement_unit(si, si, zeptocoulomb_per_square_metre, _zeptocoulomb_per_square_metre, dim::electric_flux_density_t, prefix::zepto);
implement_unit(si, si, attocoulomb_per_square_metre, _attocoulomb_per_square_metre, dim::electric_flux_density_t, prefix::atto);
implement_unit(si, si, femtocoulomb_per_square_metre, _femtocoulomb_per_square_metre, dim::electric_flux_density_t, prefix::femto);
implement_unit(si, si, picocoulomb_per_square_metre, _picocoulomb_per_square_metre, dim::electric_flux_density_t, prefix::pico);
implement_unit(si, si, nanocoulomb_per_square_metre, _nanocoulomb_per_square_metre, dim::electric_flux_density_t, prefix::nano);
implement_unit(si, si, microcoulomb_per_square_metre, _microcoulomb_per_square_metre, dim::electric_flux_density_t, prefix::micro);
implement_unit(si, si, millicoulomb_per_square_metre, _millicoulomb_per_square_metre, dim::electric_flux_density_t, prefix::milli);
implement_unit(si, si, centicoulomb_per_square_metre, _centicoulomb_per_square_metre, dim::electric_flux_density_t, prefix::centi);
implement_unit(si, si, decicoulomb_per_square_metre, _decicoulomb_per_square_metre, dim::electric_flux_density_t, prefix::deci);
implement_unit(si, si, coulomb_per_square_metre, _coulomb_per_square_metre, dim::electric_flux_density_t, prefix::one);
implement_unit(si, si, decacoulomb_per_square_metre, _decacoulomb_per_square_metre, dim::electric_flux_density_t, prefix::deca);
implement_unit(si, si, hectocoulomb_per_square_metre, _hectocoulomb_per_square_metre, dim::electric_flux_density_t, prefix::hecto);
implement_unit(si, si, kilocoulomb_per_square_metre, _kilocoulomb_per_square_metre, dim::electric_flux_density_t, prefix::kilo);
implement_unit(si, si, megacoulomb_per_square_metre, _megacoulomb_per_square_metre, dim::electric_flux_density_t, prefix::mega);
implement_unit(si, si, gigacoulomb_per_square_metre, _gigacoulomb_per_square_metre, dim::electric_flux_density_t, prefix::giga);
implement_unit(si, si, teracoulomb_per_square_metre, _teracoulomb_per_square_metre, dim::electric_flux_density_t, prefix::tera);
implement_unit(si, si, petacoulomb_per_square_metre, _petacoulomb_per_square_metre, dim::electric_flux_density_t, prefix::peta);
implement_unit(si, si, exacoulomb_per_square_metre, _exacoulomb_per_square_metre, dim::electric_flux_density_t, prefix::exa);
implement_unit(si, si, zettacoulomb_per_square_metre, _zettacoulomb_per_square_metre, dim::electric_flux_density_t, prefix::zetta);
implement_unit(si, si, yottacoulomb_per_square_metre, _yottacoulomb_per_square_metre, dim::electric_flux_density_t, prefix::yotta);
#pragma endregion
#pragma region farad per metre(permittivity)
implement_unit(si, si, yoctofarad_per_metre, _yoctofarad_per_metre, dim::permittivity_t, prefix::yocto);
implement_unit(si, si, zeptofarad_per_metre, _zeptofarad_per_metre, dim::permittivity_t, prefix::zepto);
implement_unit(si, si, attofarad_per_metre, _attofarad_per_metre, dim::permittivity_t, prefix::atto);
implement_unit(si, si, femtofarad_per_metre, _femtofarad_per_metre, dim::permittivity_t, prefix::femto);
implement_unit(si, si, picofarad_per_metre, _picofarad_per_metre, dim::permittivity_t, prefix::pico);
implement_unit(si, si, nanofarad_per_metre, _nanofarad_per_metre, dim::permittivity_t, prefix::nano);
implement_unit(si, si, microfarad_per_metre, _microfarad_per_metre, dim::permittivity_t, prefix::micro);
implement_unit(si, si, millifarad_per_metre, _millifarad_per_metre, dim::permittivity_t, prefix::milli);
implement_unit(si, si, centifarad_per_metre, _centifarad_per_metre, dim::permittivity_t, prefix::centi);
implement_unit(si, si, decifarad_per_metre, _decifarad_per_metre, dim::permittivity_t, prefix::deci);
implement_unit(si, si, farad_per_metre, _farad_per_metre, dim::permittivity_t, prefix::one);
implement_unit(si, si, decafarad_per_metre, _decafarad_per_metre, dim::permittivity_t, prefix::deca);
implement_unit(si, si, hectofarad_per_metre, _hectofarad_per_metre, dim::permittivity_t, prefix::hecto);
implement_unit(si, si, kilofarad_per_metre, _kilofarad_per_metre, dim::permittivity_t, prefix::kilo);
implement_unit(si, si, megafarad_per_metre, _megafarad_per_metre, dim::permittivity_t, prefix::mega);
implement_unit(si, si, gigafarad_per_metre, _gigafarad_per_metre, dim::permittivity_t, prefix::giga);
implement_unit(si, si, terafarad_per_metre, _terafarad_per_metre, dim::permittivity_t, prefix::tera);
implement_unit(si, si, petafarad_per_metre, _petafarad_per_metre, dim::permittivity_t, prefix::peta);
implement_unit(si, si, exafarad_per_metre, _exafarad_per_metre, dim::permittivity_t, prefix::exa);
implement_unit(si, si, zettafarad_per_metre, _zettafarad_per_metre, dim::permittivity_t, prefix::zetta);
implement_unit(si, si, yottafarad_per_metre, _yottafarad_per_metre, dim::permittivity_t, prefix::yotta);
#pragma endregion
#pragma region henry per metre(permeability)
implement_unit(si, si, yoctohenry_per_metre, _yoctohenry_per_metre, dim::permeability_t, prefix::yocto);
implement_unit(si, si, zeptohenry_per_metre, _zeptohenry_per_metre, dim::permeability_t, prefix::zepto);
implement_unit(si, si, attohenry_per_metre, _attohenry_per_metre, dim::permeability_t, prefix::atto);
implement_unit(si, si, femtohenry_per_metre, _femtohenry_per_metre, dim::permeability_t, prefix::femto);
implement_unit(si, si, picohenry_per_metre, _picohenry_per_metre, dim::permeability_t, prefix::pico);
implement_unit(si, si, nanohenry_per_metre, _nanohenry_per_metre, dim::permeability_t, prefix::nano);
implement_unit(si, si, microhenry_per_metre, _microhenry_per_metre, dim::permeability_t, prefix::micro);
implement_unit(si, si, millihenry_per_metre, _millihenry_per_metre, dim::permeability_t, prefix::milli);
implement_unit(si, si, centihenry_per_metre, _centihenry_per_metre, dim::permeability_t, prefix::centi);
implement_unit(si, si, decihenry_per_metre, _decihenry_per_metre, dim::permeability_t, prefix::deci);
implement_unit(si, si, henry_per_metre, _henry_per_metre, dim::permeability_t, prefix::one);
implement_unit(si, si, decahenry_per_metre, _decahenry_per_metre, dim::permeability_t, prefix::deca);
implement_unit(si, si, hectohenry_per_metre, _hectohenry_per_metre, dim::permeability_t, prefix::hecto);
implement_unit(si, si, kilohenry_per_metre, _kilohenry_per_metre, dim::permeability_t, prefix::kilo);
implement_unit(si, si, megahenry_per_metre, _megahenry_per_metre, dim::permeability_t, prefix::mega);
implement_unit(si, si, gigahenry_per_metre, _gigahenry_per_metre, dim::permeability_t, prefix::giga);
implement_unit(si, si, terahenry_per_metre, _terahenry_per_metre, dim::permeability_t, prefix::tera);
implement_unit(si, si, petahenry_per_metre, _petahenry_per_metre, dim::permeability_t, prefix::peta);
implement_unit(si, si, exahenry_per_metre, _exahenry_per_metre, dim::permeability_t, prefix::exa);
implement_unit(si, si, zettahenry_per_metre, _zettahenry_per_metre, dim::permeability_t, prefix::zetta);
implement_unit(si, si, yottahenry_per_metre, _yottahenry_per_metre, dim::permeability_t, prefix::yotta);
#pragma endregion
#pragma region joule per mole(molar energy)
implement_unit(si, si, yoctojoule_per_mole, _yoctojoule_per_mole, dim::molar_energy_t, prefix::yocto);
implement_unit(si, si, zeptojoule_per_mole, _zeptojoule_per_mole, dim::molar_energy_t, prefix::zepto);
implement_unit(si, si, attojoule_per_mole, _attojoule_per_mole, dim::molar_energy_t, prefix::atto);
implement_unit(si, si, femtojoule_per_mole, _femtojoule_per_mole, dim::molar_energy_t, prefix::femto);
implement_unit(si, si, picojoule_per_mole, _picojoule_per_mole, dim::molar_energy_t, prefix::pico);
implement_unit(si, si, nanojoule_per_mole, _nanojoule_per_mole, dim::molar_energy_t, prefix::nano);
implement_unit(si, si, microjoule_per_mole, _microjoule_per_mole, dim::molar_energy_t, prefix::micro);
implement_unit(si, si, millijoule_per_mole, _millijoule_per_mole, dim::molar_energy_t, prefix::milli);
implement_unit(si, si, centijoule_per_mole, _centijoule_per_mole, dim::molar_energy_t, prefix::centi);
implement_unit(si, si, decijoule_per_mole, _decijoule_per_mole, dim::molar_energy_t, prefix::deci);
implement_unit(si, si, joule_per_mole, _joule_per_mole, dim::molar_energy_t, prefix::one);
implement_unit(si, si, decajoule_per_mole, _decajoule_per_mole, dim::molar_energy_t, prefix::deca);
implement_unit(si, si, hectojoule_per_mole, _hectojoule_per_mole, dim::molar_energy_t, prefix::hecto);
implement_unit(si, si, kilojoule_per_mole, _kilojoule_per_mole, dim::molar_energy_t, prefix::kilo);
implement_unit(si, si, megajoule_per_mole, _megajoule_per_mole, dim::molar_energy_t, prefix::mega);
implement_unit(si, si, gigajoule_per_mole, _gigajoule_per_mole, dim::molar_energy_t, prefix::giga);
implement_unit(si, si, terajoule_per_mole, _terajoule_per_mole, dim::molar_energy_t, prefix::tera);
implement_unit(si, si, petajoule_per_mole, _petajoule_per_mole, dim::molar_energy_t, prefix::peta);
implement_unit(si, si, exajoule_per_mole, _exajoule_per_mole, dim::molar_energy_t, prefix::exa);
implement_unit(si, si, zettajoule_per_mole, _zettajoule_per_mole, dim::molar_energy_t, prefix::zetta);
implement_unit(si, si, yottajoule_per_mole, _yottajoule_per_mole, dim::molar_energy_t, prefix::yotta);
#pragma endregion
#pragma region joule per mole kelvin(molar heat capacity)
implement_unit(si, si, yoctojoule_per_mole_kelvin, _yoctojoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::yocto);
implement_unit(si, si, zeptojoule_per_mole_kelvin, _zeptojoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::zepto);
implement_unit(si, si, attojoule_per_mole_kelvin, _attojoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::atto);
implement_unit(si, si, femtojoule_per_mole_kelvin, _femtojoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::femto);
implement_unit(si, si, picojoule_per_mole_kelvin, _picojoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::pico);
implement_unit(si, si, nanojoule_per_mole_kelvin, _nanojoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::nano);
implement_unit(si, si, microjoule_per_mole_kelvin, _microjoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::micro);
implement_unit(si, si, millijoule_per_mole_kelvin, _millijoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::milli);
implement_unit(si, si, centijoule_per_mole_kelvin, _centijoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::centi);
implement_unit(si, si, decijoule_per_mole_kelvin, _decijoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::deci);
implement_unit(si, si, joule_per_mole_kelvin, _joule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::one);
implement_unit(si, si, decajoule_per_mole_kelvin, _decajoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::deca);
implement_unit(si, si, hectojoule_per_mole_kelvin, _hectojoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::hecto);
implement_unit(si, si, kilojoule_per_mole_kelvin, _kilojoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::kilo);
implement_unit(si, si, megajoule_per_mole_kelvin, _megajoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::mega);
implement_unit(si, si, gigajoule_per_mole_kelvin, _gigajoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::giga);
implement_unit(si, si, terajoule_per_mole_kelvin, _terajoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::tera);
implement_unit(si, si, petajoule_per_mole_kelvin, _petajoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::peta);
implement_unit(si, si, exajoule_per_mole_kelvin, _exajoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::exa);
implement_unit(si, si, zettajoule_per_mole_kelvin, _zettajoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::zetta);
implement_unit(si, si, yottajoule_per_mole_kelvin, _yottajoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::yotta);
#pragma endregion
#pragma region coulomb per kilogram(exposure)
implement_unit(si, si, yoctocoulomb_per_kilogram, _yoctocoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::yocto);
implement_unit(si, si, zeptocoulomb_per_kilogram, _zeptocoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::zepto);
implement_unit(si, si, attocoulomb_per_kilogram, _attocoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::atto);
implement_unit(si, si, femtocoulomb_per_kilogram, _femtocoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::femto);
implement_unit(si, si, picocoulomb_per_kilogram, _picocoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::pico);
implement_unit(si, si, nanocoulomb_per_kilogram, _nanocoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::nano);
implement_unit(si, si, microcoulomb_per_kilogram, _microcoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::micro);
implement_unit(si, si, millicoulomb_per_kilogram, _millicoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::milli);
implement_unit(si, si, centicoulomb_per_kilogram, _centicoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::centi);
implement_unit(si, si, decicoulomb_per_kilogram, _decicoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::deci);
implement_unit(si, si, coulomb_per_kilogram, _coulomb_per_kilogram, dim::radioactive_exposure_t, prefix::one);
implement_unit(si, si, decacoulomb_per_kilogram, _decacoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::deca);
implement_unit(si, si, hectocoulomb_per_kilogram, _hectocoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::hecto);
implement_unit(si, si, kilocoulomb_per_kilogram, _kilocoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::kilo);
implement_unit(si, si, megacoulomb_per_kilogram, _megacoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::mega);
implement_unit(si, si, gigacoulomb_per_kilogram, _gigacoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::giga);
implement_unit(si, si, teracoulomb_per_kilogram, _teracoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::tera);
implement_unit(si, si, petacoulomb_per_kilogram, _petacoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::peta);
implement_unit(si, si, exacoulomb_per_kilogram, _exacoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::exa);
implement_unit(si, si, zettacoulomb_per_kilogram, _zettacoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::zetta);
implement_unit(si, si, yottacoulomb_per_kilogram, _yottacoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::yotta);
#pragma endregion
#pragma region gray per second(absorbed dose rate)
implement_unit(si, si, yoctogray_per_second, _yoctogray_per_second, dim::absorbed_dose_rate_t, prefix::yocto);
implement_unit(si, si, zeptogray_per_second, _zeptogray_per_second, dim::absorbed_dose_rate_t, prefix::zepto);
implement_unit(si, si, attogray_per_second, _attogray_per_second, dim::absorbed_dose_rate_t, prefix::atto);
implement_unit(si, si, femtogray_per_second, _femtogray_per_second, dim::absorbed_dose_rate_t, prefix::femto);
implement_unit(si, si, picogray_per_second, _picogray_per_second, dim::absorbed_dose_rate_t, prefix::pico);
implement_unit(si, si, nanogray_per_second, _nanogray_per_second, dim::absorbed_dose_rate_t, prefix::nano);
implement_unit(si, si, microgray_per_second, _microgray_per_second, dim::absorbed_dose_rate_t, prefix::micro);
implement_unit(si, si, milligray_per_second, _milligray_per_second, dim::absorbed_dose_rate_t, prefix::milli);
implement_unit(si, si, centigray_per_second, _centigray_per_second, dim::absorbed_dose_rate_t, prefix::centi);
implement_unit(si, si, decigray_per_second, _decigray_per_second, dim::absorbed_dose_rate_t, prefix::deci);
implement_unit(si, si, gray_per_second, _gray_per_second, dim::absorbed_dose_rate_t, prefix::one);
implement_unit(si, si, decagray_per_second, _decagray_per_second, dim::absorbed_dose_rate_t, prefix::deca);
implement_unit(si, si, hectogray_per_second, _hectogray_per_second, dim::absorbed_dose_rate_t, prefix::hecto);
implement_unit(si, si, kilogray_per_second, _kilogray_per_second, dim::absorbed_dose_rate_t, prefix::kilo);
implement_unit(si, si, megagray_per_second, _megagray_per_second, dim::absorbed_dose_rate_t, prefix::mega);
implement_unit(si, si, gigagray_per_second, _gigagray_per_second, dim::absorbed_dose_rate_t, prefix::giga);
implement_unit(si, si, teragray_per_second, _teragray_per_second, dim::absorbed_dose_rate_t, prefix::tera);
implement_unit(si, si, petagray_per_second, _petagray_per_second, dim::absorbed_dose_rate_t, prefix::peta);
implement_unit(si, si, exagray_per_second, _exagray_per_second, dim::absorbed_dose_rate_t, prefix::exa);
implement_unit(si, si, zettagray_per_second, _zettagray_per_second, dim::absorbed_dose_rate_t, prefix::zetta);
implement_unit(si, si, yottagray_per_second, _yottagray_per_second, dim::absorbed_dose_rate_t, prefix::yotta);
#pragma endregion
#pragma region gray per minute(absorbed dose rate)
implement_unit(si, si, yoctogray_per_minute, _yoctogray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::yocto, prefix::minute>));
implement_unit(si, si, zeptogray_per_minute, _zeptogray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::zepto, prefix::minute>));
implement_unit(si, si, attogray_per_minute, _attogray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::atto, prefix::minute>));
implement_unit(si, si, femtogray_per_minute, _femtogray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::femto, prefix::minute>));
implement_unit(si, si, picogray_per_minute, _picogray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::pico, prefix::minute>));
implement_unit(si, si, nanogray_per_minute, _nanogray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::nano, prefix::minute>));
implement_unit(si, si, microgray_per_minute, _microgray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::micro, prefix::minute>));
implement_unit(si, si, milligray_per_minute, _milligray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::milli, prefix::minute>));
implement_unit(si, si, centigray_per_minute, _centigray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::centi, prefix::minute>));
implement_unit(si, si, decigray_per_minute, _decigray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::deci, prefix::minute>));
implement_unit(si, si, gray_per_minute, _gray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::one, prefix::minute>));
implement_unit(si, si, decagray_per_minute, _decagray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::deca, prefix::minute>));
implement_unit(si, si, hectogray_per_minute, _hectogray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::hecto, prefix::minute>));
implement_unit(si, si, kilogray_per_minute, _kilogray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::kilo, prefix::minute>));
implement_unit(si, si, megagray_per_minute, _megagray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::mega, prefix::minute>));
implement_unit(si, si, gigagray_per_minute, _gigagray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::giga, prefix::minute>));
implement_unit(si, si, teragray_per_minute, _teragray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::tera, prefix::minute>));
implement_unit(si, si, petagray_per_minute, _petagray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::peta, prefix::minute>));
implement_unit(si, si, exagray_per_minute, _exagray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::exa, prefix::minute>));
implement_unit(si, si, zettagray_per_minute, _zettagray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::zetta, prefix::minute>));
implement_unit(si, si, yottagray_per_minute, _yottagray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::yotta, prefix::minute>));
#pragma endregion
#pragma region gray per hour(absorbed dose rate)
implement_unit(si, si, yoctogray_per_hour, _yoctogray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::yocto, prefix::hour>));
implement_unit(si, si, zeptogray_per_hour, _zeptogray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::zepto, prefix::hour>));
implement_unit(si, si, attogray_per_hour, _attogray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::atto, prefix::hour>));
implement_unit(si, si, femtogray_per_hour, _femtogray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::femto, prefix::hour>));
implement_unit(si, si, picogray_per_hour, _picogray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::pico, prefix::hour>));
implement_unit(si, si, nanogray_per_hour, _nanogray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::nano, prefix::hour>));
implement_unit(si, si, microgray_per_hour, _microgray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::micro, prefix::hour>));
implement_unit(si, si, milligray_per_hour, _milligray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::milli, prefix::hour>));
implement_unit(si, si, centigray_per_hour, _centigray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::centi, prefix::hour>));
implement_unit(si, si, decigray_per_hour, _decigray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::deci, prefix::hour>));
implement_unit(si, si, gray_per_hour, _gray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::one, prefix::hour>));
implement_unit(si, si, decagray_per_hour, _decagray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::deca, prefix::hour>));
implement_unit(si, si, hectogray_per_hour, _hectogray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::hecto, prefix::hour>));
implement_unit(si, si, kilogray_per_hour, _kilogray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::kilo, prefix::hour>));
implement_unit(si, si, megagray_per_hour, _megagray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::mega, prefix::hour>));
implement_unit(si, si, gigagray_per_hour, _gigagray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::giga, prefix::hour>));
implement_unit(si, si, teragray_per_hour, _teragray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::tera, prefix::hour>));
implement_unit(si, si, petagray_per_hour, _petagray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::peta, prefix::hour>));
implement_unit(si, si, exagray_per_hour, _exagray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::exa, prefix::hour>));
implement_unit(si, si, zettagray_per_hour, _zettagray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::zetta, prefix::hour>));
implement_unit(si, si, yottagray_per_hour, _yottagray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::yotta, prefix::hour>));
#pragma endregion
#pragma region watt per square metre steradian(radiance)
implement_unit(si, si, yoctowatt_per_square_metre_steradian, _yoctowatt_per_square_metre_steradian, dim::radiance_t, prefix::yocto);
implement_unit(si, si, zeptowatt_per_square_metre_steradian, _zeptowatt_per_square_metre_steradian, dim::radiance_t, prefix::zepto);
implement_unit(si, si, attowatt_per_square_metre_steradian, _attowatt_per_square_metre_steradian, dim::radiance_t, prefix::atto);
implement_unit(si, si, femtowatt_per_square_metre_steradian, _femtowatt_per_square_metre_steradian, dim::radiance_t, prefix::femto);
implement_unit(si, si, picowatt_per_square_metre_steradian, _picowatt_per_square_metre_steradian, dim::radiance_t, prefix::pico);
implement_unit(si, si, nanowatt_per_square_metre_steradian, _nanowatt_per_square_metre_steradian, dim::radiance_t, prefix::nano);
implement_unit(si, si, microwatt_per_square_metre_steradian, _microwatt_per_square_metre_steradian, dim::radiance_t, prefix::micro);
implement_unit(si, si, milliwatt_per_square_metre_steradian, _milliwatt_per_square_metre_steradian, dim::radiance_t, prefix::milli);
implement_unit(si, si, centiwatt_per_square_metre_steradian, _centiwatt_per_square_metre_steradian, dim::radiance_t, prefix::centi);
implement_unit(si, si, deciwatt_per_square_metre_steradian, _deciwatt_per_square_metre_steradian, dim::radiance_t, prefix::deci);
implement_unit(si, si, watt_per_square_metre_steradian, _watt_per_square_metre_steradian, dim::radiance_t, prefix::one);
implement_unit(si, si, decawatt_per_square_metre_steradian, _decawatt_per_square_metre_steradian, dim::radiance_t, prefix::deca);
implement_unit(si, si, hectowatt_per_square_metre_steradian, _hectowatt_per_square_metre_steradian, dim::radiance_t, prefix::hecto);
implement_unit(si, si, kilowatt_per_square_metre_steradian, _kilowatt_per_square_metre_steradian, dim::radiance_t, prefix::kilo);
implement_unit(si, si, megawatt_per_square_metre_steradian, _megawatt_per_square_metre_steradian, dim::radiance_t, prefix::mega);
implement_unit(si, si, gigawatt_per_square_metre_steradian, _gigawatt_per_square_metre_steradian, dim::radiance_t, prefix::giga);
implement_unit(si, si, terawatt_per_square_metre_steradian, _terawatt_per_square_metre_steradian, dim::radiance_t, prefix::tera);
implement_unit(si, si, petawatt_per_square_metre_steradian, _petawatt_per_square_metre_steradian, dim::radiance_t, prefix::peta);
implement_unit(si, si, exawatt_per_square_metre_steradian, _exawatt_per_square_metre_steradian, dim::radiance_t, prefix::exa);
implement_unit(si, si, zettawatt_per_square_metre_steradian, _zettawatt_per_square_metre_steradian, dim::radiance_t, prefix::zetta);
implement_unit(si, si, yottawatt_per_square_metre_steradian, _yottawatt_per_square_metre_steradian, dim::radiance_t, prefix::yotta);
#pragma endregion
#pragma region katal per cubic metre(catalytic activity concentration)
implement_unit(si, si, yoctokatal_per_cubic_metre, _yoctokatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::yocto);
implement_unit(si, si, zeptokatal_per_cubic_metre, _zeptokatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::zepto);
implement_unit(si, si, attokatal_per_cubic_metre, _attokatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::atto);
implement_unit(si, si, femtokatal_per_cubic_metre, _femtokatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::femto);
implement_unit(si, si, picokatal_per_cubic_metre, _picokatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::pico);
implement_unit(si, si, nanokatal_per_cubic_metre, _nanokatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::nano);
implement_unit(si, si, microkatal_per_cubic_metre, _microkatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::micro);
implement_unit(si, si, millikatal_per_cubic_metre, _millikatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::milli);
implement_unit(si, si, centikatal_per_cubic_metre, _centikatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::centi);
implement_unit(si, si, decikatal_per_cubic_metre, _decikatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::deci);
implement_unit(si, si, katal_per_cubic_metre, _katal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::one);
implement_unit(si, si, decakatal_per_cubic_metre, _decakatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::deca);
implement_unit(si, si, hectokatal_per_cubic_metre, _hectokatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::hecto);
implement_unit(si, si, kilokatal_per_cubic_metre, _kilokatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::kilo);
implement_unit(si, si, megakatal_per_cubic_metre, _megakatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::mega);
implement_unit(si, si, gigakatal_per_cubic_metre, _gigakatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::giga);
implement_unit(si, si, terakatal_per_cubic_metre, _terakatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::tera);
implement_unit(si, si, petakatal_per_cubic_metre, _petakatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::peta);
implement_unit(si, si, exakatal_per_cubic_metre, _exakatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::exa);
implement_unit(si, si, zettakatal_per_cubic_metre, _zettakatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::zetta);
implement_unit(si, si, yottakatal_per_cubic_metre, _yottakatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::yotta);
#pragma endregion
#pragma region joule second(action)
implement_unit(si, si, yoctojoule_second, _yoctojoule_second, dim::action_t, prefix::yocto);
implement_unit(si, si, zeptojoule_second, _zeptojoule_second, dim::action_t, prefix::zepto);
implement_unit(si, si, attojoule_second, _attojoule_second, dim::action_t, prefix::atto);
implement_unit(si, si, femtojoule_second, _femtojoule_second, dim::action_t, prefix::femto);
implement_unit(si, si, picojoule_second, _picojoule_second, dim::action_t, prefix::pico);
implement_unit(si, si, nanojoule_second, _nanojoule_second, dim::action_t, prefix::nano);
implement_unit(si, si, microjoule_second, _microjoule_second, dim::action_t, prefix::micro);
implement_unit(si, si, millijoule_second, _millijoule_second, dim::action_t, prefix::milli);
implement_unit(si, si, centijoule_second, _centijoule_second, dim::action_t, prefix::centi);
implement_unit(si, si, decijoule_second, _decijoule_second, dim::action_t, prefix::deci);
implement_unit(si, si, joule_second, _joule_second, dim::action_t, prefix::one);
implement_unit(si, si, decajoule_second, _decajoule_second, dim::action_t, prefix::deca);
implement_unit(si, si, hectojoule_second, _hectojoule_second, dim::action_t, prefix::hecto);
implement_unit(si, si, kilojoule_second, _kilojoule_second, dim::action_t, prefix::kilo);
implement_unit(si, si, megajoule_second, _megajoule_second, dim::action_t, prefix::mega);
implement_unit(si, si, gigajoule_second, _gigajoule_second, dim::action_t, prefix::giga);
implement_unit(si, si, terajoule_second, _terajoule_second, dim::action_t, prefix::tera);
implement_unit(si, si, petajoule_second, _petajoule_second, dim::action_t, prefix::peta);
implement_unit(si, si, exajoule_second, _exajoule_second, dim::action_t, prefix::exa);
implement_unit(si, si, zettajoule_second, _zettajoule_second, dim::action_t, prefix::zetta);
implement_unit(si, si, yottajoule_second, _yottajoule_second, dim::action_t, prefix::yotta);
#pragma endregion
#pragma region joule minute(action)
implement_unit(si, si, yoctojoule_minute, _yoctojoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yocto>));
implement_unit(si, si, zeptojoule_minute, _zeptojoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zepto>));
implement_unit(si, si, attojoule_minute, _attojoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::atto>));
implement_unit(si, si, femtojoule_minute, _femtojoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::femto>));
implement_unit(si, si, picojoule_minute, _picojoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::pico>));
implement_unit(si, si, nanojoule_minute, _nanojoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::nano>));
implement_unit(si, si, microjoule_minute, _microjoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::micro>));
implement_unit(si, si, millijoule_minute, _millijoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::milli>));
implement_unit(si, si, centijoule_minute, _centijoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::centi>));
implement_unit(si, si, decijoule_minute, _decijoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deci>));
implement_unit(si, si, joule_minute, _joule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::one>));
implement_unit(si, si, decajoule_minute, _decajoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deca>));
implement_unit(si, si, hectojoule_minute, _hectojoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::hecto>));
implement_unit(si, si, kilojoule_minute, _kilojoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::kilo>));
implement_unit(si, si, megajoule_minute, _megajoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::mega>));
implement_unit(si, si, gigajoule_minute, _gigajoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::giga>));
implement_unit(si, si, terajoule_minute, _terajoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::tera>));
implement_unit(si, si, petajoule_minute, _petajoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::peta>));
implement_unit(si, si, exajoule_minute, _exajoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::exa>));
implement_unit(si, si, zettajoule_minute, _zettajoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zetta>));
implement_unit(si, si, yottajoule_minute, _yottajoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yotta>));
#pragma endregion
#pragma region joule hour(action)
implement_unit(si, si, yoctojoule_hour, _yoctojoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yocto>));
implement_unit(si, si, zeptojoule_hour, _zeptojoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zepto>));
implement_unit(si, si, attojoule_hour, _attojoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::atto>));
implement_unit(si, si, femtojoule_hour, _femtojoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::femto>));
implement_unit(si, si, picojoule_hour, _picojoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::pico>));
implement_unit(si, si, nanojoule_hour, _nanojoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::nano>));
implement_unit(si, si, microjoule_hour, _microjoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::micro>));
implement_unit(si, si, millijoule_hour, _millijoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::milli>));
implement_unit(si, si, centijoule_hour, _centijoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::centi>));
implement_unit(si, si, decijoule_hour, _decijoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deci>));
implement_unit(si, si, joule_hour, _joule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::one>));
implement_unit(si, si, decajoule_hour, _decajoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deca>));
implement_unit(si, si, hectojoule_hour, _hectojoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::hecto>));
implement_unit(si, si, kilojoule_hour, _kilojoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::kilo>));
implement_unit(si, si, megajoule_hour, _megajoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::mega>));
implement_unit(si, si, gigajoule_hour, _gigajoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::giga>));
implement_unit(si, si, terajoule_hour, _terajoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::tera>));
implement_unit(si, si, petajoule_hour, _petajoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::peta>));
implement_unit(si, si, exajoule_hour, _exajoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::exa>));
implement_unit(si, si, zettajoule_hour, _zettajoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zetta>));
implement_unit(si, si, yottajoule_hour, _yottajoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yotta>));
#pragma endregion
#pragma region square metre per second(kinematic viscosity)
implement_unit(si, si, square_metre_per_second, _square_metre_per_second, dim::kinematic_viscosity_t, prefix::one);
#pragma endregion
#pragma region kilogram per metre(line density)
implement_unit(si, si, yoctogram_per_metre, _yoctogram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::yocto, prefix::milli>));
implement_unit(si, si, zeptogram_per_metre, _zeptogram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::zepto, prefix::milli>));
implement_unit(si, si, attogram_per_metre, _attogram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::atto, prefix::milli>));
implement_unit(si, si, femtogram_per_metre, _femtogram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::femto, prefix::milli>));
implement_unit(si, si, picogram_per_metre, _picogram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::pico, prefix::milli>));
implement_unit(si, si, nanogram_per_metre, _nanogram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::nano, prefix::milli>));
implement_unit(si, si, microgram_per_metre, _microgram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::micro, prefix::milli>));
implement_unit(si, si, milligram_per_metre, _milligram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::milli, prefix::milli>));
implement_unit(si, si, centigram_per_metre, _centigram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::centi, prefix::milli>));
implement_unit(si, si, decigram_per_metre, _decigram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::deci, prefix::milli>));
implement_unit(si, si, gram_per_metre, _gram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::one, prefix::milli>));
implement_unit(si, si, decagram_per_metre, _decagram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::deca, prefix::milli>));
implement_unit(si, si, hectogram_per_metre, _hectogram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::hecto, prefix::milli>));
implement_unit(si, si, kilogram_per_metre, _kilogram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::kilo, prefix::milli>));
implement_unit(si, si, megagram_per_metre, _megagram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::mega, prefix::milli>));
link_unit(tonne_per_metre, _tonne_per_metre, megagram_per_metre);
implement_unit(si, si, gigagram_per_metre, _gigagram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::giga, prefix::milli>));
link_unit(kilotonne_per_metre, _kilotonne_per_metre, gigagram_per_metre);
implement_unit(si, si, teragram_per_metre, _teragram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::tera, prefix::milli>));
link_unit(megatonne_per_metre, _megatonne_per_metre, teragram_per_metre);
implement_unit(si, si, petagram_per_metre, _petagram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::peta, prefix::milli>));
link_unit(gigatonne_per_metre, _gigatonne_per_metre, petagram_per_metre);
implement_unit(si, si, exagram_per_metre, _exagram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::exa, prefix::milli>));
implement_unit(si, si, zettagram_per_metre, _zettagram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::zetta, prefix::milli>));
implement_unit(si, si, yottagram_per_metre, _yottagram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::yotta, prefix::milli>));
#pragma endregion
#pragma region metre second(absement)
implement_unit(si, si, yoctometre_second, _yoctometre_second, dim::absement_t, prefix::yocto);
implement_unit(si, si, zeptometre_second, _zeptometre_second, dim::absement_t, prefix::zepto);
implement_unit(si, si, attometre_second, _attometre_second, dim::absement_t, prefix::atto);
implement_unit(si, si, femtometre_second, _femtometre_second, dim::absement_t, prefix::femto);
implement_unit(si, si, picometre_second, _picometre_second, dim::absement_t, prefix::pico);
implement_unit(si, si, nanometre_second, _nanometre_second, dim::absement_t, prefix::nano);
implement_unit(si, si, micrometre_second, _micrometre_second, dim::absement_t, prefix::micro);
implement_unit(si, si, millimetre_second, _millimetre_second, dim::absement_t, prefix::milli);
implement_unit(si, si, centimetre_second, _centimetre_second, dim::absement_t, prefix::centi);
implement_unit(si, si, decimetre_second, _decimetre_second, dim::absement_t, prefix::deci);
implement_unit(si, si, metre_second, _metre_second, dim::absement_t, prefix::one);
implement_unit(si, si, decametre_second, _decametre_second, dim::absement_t, prefix::deca);
implement_unit(si, si, hectometre_second, _hectometre_second, dim::absement_t, prefix::hecto);
implement_unit(si, si, kilometre_second, _kilometre_second, dim::absement_t, prefix::kilo);
implement_unit(si, si, megametre_second, _megametre_second, dim::absement_t, prefix::mega);
implement_unit(si, si, gigametre_second, _gigametre_second, dim::absement_t, prefix::giga);
implement_unit(si, si, terametre_second, _terametre_second, dim::absement_t, prefix::tera);
implement_unit(si, si, petametre_second, _petametre_second, dim::absement_t, prefix::peta);
implement_unit(si, si, exametre_second, _exametre_second, dim::absement_t, prefix::exa);
implement_unit(si, si, zettametre_second, _zettametre_second, dim::absement_t, prefix::zetta);
implement_unit(si, si, yottametre_second, _yottametre_second, dim::absement_t, prefix::yotta);
#pragma endregion
#pragma region metre minute(absement)
implement_unit(si, si, yoctometre_minute, _yoctometre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yocto>));
implement_unit(si, si, zeptometre_minute, _zeptometre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zepto>));
implement_unit(si, si, attometre_minute, _attometre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::atto>));
implement_unit(si, si, femtometre_minute, _femtometre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::femto>));
implement_unit(si, si, picometre_minute, _picometre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::pico>));
implement_unit(si, si, nanometre_minute, _nanometre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::nano>));
implement_unit(si, si, micrometre_minute, _micrometre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::micro>));
implement_unit(si, si, millimetre_minute, _millimetre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::milli>));
implement_unit(si, si, centimetre_minute, _centimetre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::centi>));
implement_unit(si, si, decimetre_minute, _decimetre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deci>));
implement_unit(si, si, metre_minute, _metre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::one>));
implement_unit(si, si, decametre_minute, _decametre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deca>));
implement_unit(si, si, hectometre_minute, _hectometre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::hecto>));
implement_unit(si, si, kilometre_minute, _kilometre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::kilo>));
implement_unit(si, si, megametre_minute, _megametre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::mega>));
implement_unit(si, si, gigametre_minute, _gigametre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::giga>));
implement_unit(si, si, terametre_minute, _terametre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::tera>));
implement_unit(si, si, petametre_minute, _petametre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::peta>));
implement_unit(si, si, exametre_minute, _exametre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::exa>));
implement_unit(si, si, zettametre_minute, _zettametre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zetta>));
implement_unit(si, si, yottametre_minute, _yottametre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yotta>));
#pragma endregion
#pragma region metre hour(absement)
implement_unit(si, si, yoctometre_hour, _yoctometre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yocto>));
implement_unit(si, si, zeptometre_hour, _zeptometre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zepto>));
implement_unit(si, si, attometre_hour, _attometre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::atto>));
implement_unit(si, si, femtometre_hour, _femtometre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::femto>));
implement_unit(si, si, picometre_hour, _picometre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::pico>));
implement_unit(si, si, nanometre_hour, _nanometre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::nano>));
implement_unit(si, si, micrometre_hour, _micrometre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::micro>));
implement_unit(si, si, millimetre_hour, _millimetre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::milli>));
implement_unit(si, si, centimetre_hour, _centimetre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::centi>));
implement_unit(si, si, decimetre_hour, _decimetre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deci>));
implement_unit(si, si, metre_hour, _metre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::one>));
implement_unit(si, si, decametre_hour, _decametre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deca>));
implement_unit(si, si, hectometre_hour, _hectometre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::hecto>));
implement_unit(si, si, kilometre_hour, _kilometre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::kilo>));
implement_unit(si, si, megametre_hour, _megametre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::mega>));
implement_unit(si, si, gigametre_hour, _gigametre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::giga>));
implement_unit(si, si, terametre_hour, _terametre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::tera>));
implement_unit(si, si, petametre_hour, _petametre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::peta>));
implement_unit(si, si, exametre_hour, _exametre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::exa>));
implement_unit(si, si, zettametre_hour, _zettametre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zetta>));
implement_unit(si, si, yottametre_hour, _yottametre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yotta>));
#pragma endregion
#pragma region siemens per metre(electric conductivity)
implement_unit(si, si, yoctosiemens_per_metre, _yoctosiemens_per_metre, dim::electric_conductivity_t, prefix::yocto);
implement_unit(si, si, zeptosiemens_per_metre, _zeptosiemens_per_metre, dim::electric_conductivity_t, prefix::zepto);
implement_unit(si, si, attosiemens_per_metre, _attosiemens_per_metre, dim::electric_conductivity_t, prefix::atto);
implement_unit(si, si, femtosiemens_per_metre, _femtosiemens_per_metre, dim::electric_conductivity_t, prefix::femto);
implement_unit(si, si, picosiemens_per_metre, _picosiemens_per_metre, dim::electric_conductivity_t, prefix::pico);
implement_unit(si, si, nanosiemens_per_metre, _nanosiemens_per_metre, dim::electric_conductivity_t, prefix::nano);
implement_unit(si, si, microsiemens_per_metre, _microsiemens_per_metre, dim::electric_conductivity_t, prefix::micro);
implement_unit(si, si, millisiemens_per_metre, _millisiemens_per_metre, dim::electric_conductivity_t, prefix::milli);
implement_unit(si, si, centisiemens_per_metre, _centisiemens_per_metre, dim::electric_conductivity_t, prefix::centi);
implement_unit(si, si, decisiemens_per_metre, _decisiemens_per_metre, dim::electric_conductivity_t, prefix::deci);
implement_unit(si, si, siemens_per_metre, _siemens_per_metre, dim::electric_conductivity_t, prefix::one);
implement_unit(si, si, decasiemens_per_metre, _decasiemens_per_metre, dim::electric_conductivity_t, prefix::deca);
implement_unit(si, si, hectosiemens_per_metre, _hectosiemens_per_metre, dim::electric_conductivity_t, prefix::hecto);
implement_unit(si, si, kilosiemens_per_metre, _kilosiemens_per_metre, dim::electric_conductivity_t, prefix::kilo);
implement_unit(si, si, megasiemens_per_metre, _megasiemens_per_metre, dim::electric_conductivity_t, prefix::mega);
implement_unit(si, si, gigasiemens_per_metre, _gigasiemens_per_metre, dim::electric_conductivity_t, prefix::giga);
implement_unit(si, si, terasiemens_per_metre, _terasiemens_per_metre, dim::electric_conductivity_t, prefix::tera);
implement_unit(si, si, petasiemens_per_metre, _petasiemens_per_metre, dim::electric_conductivity_t, prefix::peta);
implement_unit(si, si, exasiemens_per_metre, _exasiemens_per_metre, dim::electric_conductivity_t, prefix::exa);
implement_unit(si, si, zettasiemens_per_metre, _zettasiemens_per_metre, dim::electric_conductivity_t, prefix::zetta);
implement_unit(si, si, yottasiemens_per_metre, _yottasiemens_per_metre, dim::electric_conductivity_t, prefix::yotta);
#pragma endregion
#pragma region ohm metre(electric resitivity)
implement_unit(si, si, yoctoohm_metre, _yoctoohm_metre, dim::electric_resistivity_t, prefix::yocto);
implement_unit(si, si, zeptoohm_metre, _zeptoohm_metre, dim::electric_resistivity_t, prefix::zepto);
implement_unit(si, si, attoohm_metre, _attoohm_metre, dim::electric_resistivity_t, prefix::atto);
implement_unit(si, si, femtoohm_metre, _femtoohm_metre, dim::electric_resistivity_t, prefix::femto);
implement_unit(si, si, picoohm_metre, _picoohm_metre, dim::electric_resistivity_t, prefix::pico);
implement_unit(si, si, nanoohm_metre, _nanoohm_metre, dim::electric_resistivity_t, prefix::nano);
implement_unit(si, si, microohm_metre, _microohm_metre, dim::electric_resistivity_t, prefix::micro);
implement_unit(si, si, milliohm_metre, _milliohm_metre, dim::electric_resistivity_t, prefix::milli);
implement_unit(si, si, centiohm_metre, _centiohm_metre, dim::electric_resistivity_t, prefix::centi);
implement_unit(si, si, deciohm_metre, _deciohm_metre, dim::electric_resistivity_t, prefix::deci);
implement_unit(si, si, ohm_metre, _ohm_metre, dim::electric_resistivity_t, prefix::one);
implement_unit(si, si, decaohm_metre, _decaohm_metre, dim::electric_resistivity_t, prefix::deca);
implement_unit(si, si, hectoohm_metre, _hectoohm_metre, dim::electric_resistivity_t, prefix::hecto);
implement_unit(si, si, kiloohm_metre, _kiloohm_metre, dim::electric_resistivity_t, prefix::kilo);
implement_unit(si, si, megaohm_metre, _megaohm_metre, dim::electric_resistivity_t, prefix::mega);
implement_unit(si, si, gigaohm_metre, _gigaohm_metre, dim::electric_resistivity_t, prefix::giga);
implement_unit(si, si, teraohm_metre, _teraohm_metre, dim::electric_resistivity_t, prefix::tera);
implement_unit(si, si, petaohm_metre, _petaohm_metre, dim::electric_resistivity_t, prefix::peta);
implement_unit(si, si, exaohm_metre, _exaohm_metre, dim::electric_resistivity_t, prefix::exa);
implement_unit(si, si, zettaohm_metre, _zettaohm_metre, dim::electric_resistivity_t, prefix::zetta);
implement_unit(si, si, yottaohm_metre, _yottaohm_metre, dim::electric_resistivity_t, prefix::yotta);
#pragma endregion
#pragma region newton second(momentum)
implement_unit(si, si, yoctonewton_second, _yoctonewton_second, dim::momentum_t, prefix::yocto);
implement_unit(si, si, zeptonewton_second, _zeptonewton_second, dim::momentum_t, prefix::zepto);
implement_unit(si, si, attonewton_second, _attonewton_second, dim::momentum_t, prefix::atto);
implement_unit(si, si, femtonewton_second, _femtonewton_second, dim::momentum_t, prefix::femto);
implement_unit(si, si, piconewton_second, _piconewton_second, dim::momentum_t, prefix::pico);
implement_unit(si, si, nanonewton_second, _nanonewton_second, dim::momentum_t, prefix::nano);
implement_unit(si, si, micronewton_second, _micronewton_second, dim::momentum_t, prefix::micro);
implement_unit(si, si, millinewton_second, _millinewton_second, dim::momentum_t, prefix::milli);
implement_unit(si, si, centinewton_second, _centinewton_second, dim::momentum_t, prefix::centi);
implement_unit(si, si, decinewton_second, _decinewton_second, dim::momentum_t, prefix::deci);
implement_unit(si, si, newton_second, _newton_second, dim::momentum_t, prefix::one);
implement_unit(si, si, decanewton_second, _decanewton_second, dim::momentum_t, prefix::deca);
implement_unit(si, si, hectonewton_second, _hectonewton_second, dim::momentum_t, prefix::hecto);
implement_unit(si, si, kilonewton_second, _kilonewton_second, dim::momentum_t, prefix::kilo);
implement_unit(si, si, meganewton_second, _meganewton_second, dim::momentum_t, prefix::mega);
implement_unit(si, si, giganewton_second, _giganewton_second, dim::momentum_t, prefix::giga);
implement_unit(si, si, teranewton_second, _teranewton_second, dim::momentum_t, prefix::tera);
implement_unit(si, si, petanewton_second, _petanewton_second, dim::momentum_t, prefix::peta);
implement_unit(si, si, exanewton_second, _exanewton_second, dim::momentum_t, prefix::exa);
implement_unit(si, si, zettanewton_second, _zettanewton_second, dim::momentum_t, prefix::zetta);
implement_unit(si, si, yottanewton_second, _yottanewton_second, dim::momentum_t, prefix::yotta);
#pragma endregion
#pragma region newton minute(momentum)
implement_unit(si, si, yoctonewton_minute, _yoctonewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yocto>));
implement_unit(si, si, zeptonewton_minute, _zeptonewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zepto>));
implement_unit(si, si, attonewton_minute, _attonewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::atto>));
implement_unit(si, si, femtonewton_minute, _femtonewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::femto>));
implement_unit(si, si, piconewton_minute, _piconewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::pico>));
implement_unit(si, si, nanonewton_minute, _nanonewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::nano>));
implement_unit(si, si, micronewton_minute, _micronewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::micro>));
implement_unit(si, si, millinewton_minute, _millinewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::milli>));
implement_unit(si, si, centinewton_minute, _centinewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::centi>));
implement_unit(si, si, decinewton_minute, _decinewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deci>));
implement_unit(si, si, newton_minute, _newton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::one>));
implement_unit(si, si, decanewton_minute, _decanewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deca>));
implement_unit(si, si, hectonewton_minute, _hectonewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::hecto>));
implement_unit(si, si, kilonewton_minute, _kilonewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::kilo>));
implement_unit(si, si, meganewton_minute, _meganewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::mega>));
implement_unit(si, si, giganewton_minute, _giganewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::giga>));
implement_unit(si, si, teranewton_minute, _teranewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::tera>));
implement_unit(si, si, petanewton_minute, _petanewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::peta>));
implement_unit(si, si, exanewton_minute, _exanewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::exa>));
implement_unit(si, si, zettanewton_minute, _zettanewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zetta>));
implement_unit(si, si, yottanewton_minute, _yottanewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yotta>));
#pragma endregion
#pragma region newton hour(momentum)
implement_unit(si, si, yoctonewton_hour, _yoctonewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yocto>));
implement_unit(si, si, zeptonewton_hour, _zeptonewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zepto>));
implement_unit(si, si, attonewton_hour, _attonewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::atto>));
implement_unit(si, si, femtonewton_hour, _femtonewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::femto>));
implement_unit(si, si, piconewton_hour, _piconewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::pico>));
implement_unit(si, si, nanonewton_hour, _nanonewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::nano>));
implement_unit(si, si, micronewton_hour, _micronewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::micro>));
implement_unit(si, si, millinewton_hour, _millinewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::milli>));
implement_unit(si, si, centinewton_hour, _centinewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::centi>));
implement_unit(si, si, decinewton_hour, _decinewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deci>));
implement_unit(si, si, newton_hour, _newton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::one>));
implement_unit(si, si, decanewton_hour, _decanewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deca>));
implement_unit(si, si, hectonewton_hour, _hectonewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::hecto>));
implement_unit(si, si, kilonewton_hour, _kilonewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::kilo>));
implement_unit(si, si, meganewton_hour, _meganewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::mega>));
implement_unit(si, si, giganewton_hour, _giganewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::giga>));
implement_unit(si, si, teranewton_hour, _teranewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::tera>));
implement_unit(si, si, petanewton_hour, _petanewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::peta>));
implement_unit(si, si, exanewton_hour, _exanewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::exa>));
implement_unit(si, si, zettanewton_hour, _zettanewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zetta>));
implement_unit(si, si, yottanewton_hour, _yottanewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yotta>));
#pragma endregion
#pragma region newton metre second per radian(angular momentum)
implement_unit(si, si, yoctonewton_metre_second_per_radian, _yoctonewton_metre_second_per_radian, dim::angular_momentum_t, prefix::yocto);
implement_unit(si, si, zeptonewton_metre_second_per_radian, _zeptonewton_metre_second_per_radian, dim::angular_momentum_t, prefix::zepto);
implement_unit(si, si, attonewton_metre_second_per_radian, _attonewton_metre_second_per_radian, dim::angular_momentum_t, prefix::atto);
implement_unit(si, si, femtonewton_metre_second_per_radian, _femtonewton_metre_second_per_radian, dim::angular_momentum_t, prefix::femto);
implement_unit(si, si, piconewton_metre_second_per_radian, _piconewton_metre_second_per_radian, dim::angular_momentum_t, prefix::pico);
implement_unit(si, si, nanonewton_metre_second_per_radian, _nanonewton_metre_second_per_radian, dim::angular_momentum_t, prefix::nano);
implement_unit(si, si, micronewton_metre_second_per_radian, _micronewton_metre_second_per_radian, dim::angular_momentum_t, prefix::micro);
implement_unit(si, si, millinewton_metre_second_per_radian, _millinewton_metre_second_per_radian, dim::angular_momentum_t, prefix::milli);
implement_unit(si, si, centinewton_metre_second_per_radian, _centinewton_metre_second_per_radian, dim::angular_momentum_t, prefix::centi);
implement_unit(si, si, decinewton_metre_second_per_radian, _decinewton_metre_second_per_radian, dim::angular_momentum_t, prefix::deci);
implement_unit(si, si, newton_metre_second_per_radian, _newton_metre_second_per_radian, dim::angular_momentum_t, prefix::one);
implement_unit(si, si, decanewton_metre_second_per_radian, _decanewton_metre_second_per_radian, dim::angular_momentum_t, prefix::deca);
implement_unit(si, si, hectonewton_metre_second_per_radian, _hectonewton_metre_second_per_radian, dim::angular_momentum_t, prefix::hecto);
implement_unit(si, si, kilonewton_metre_second_per_radian, _kilonewton_metre_second_per_radian, dim::angular_momentum_t, prefix::kilo);
implement_unit(si, si, meganewton_metre_second_per_radian, _meganewton_metre_second_per_radian, dim::angular_momentum_t, prefix::mega);
implement_unit(si, si, giganewton_metre_second_per_radian, _giganewton_metre_second_per_radian, dim::angular_momentum_t, prefix::giga);
implement_unit(si, si, teranewton_metre_second_per_radian, _teranewton_metre_second_per_radian, dim::angular_momentum_t, prefix::tera);
implement_unit(si, si, petanewton_metre_second_per_radian, _petanewton_metre_second_per_radian, dim::angular_momentum_t, prefix::peta);
implement_unit(si, si, exanewton_metre_second_per_radian, _exanewton_metre_second_per_radian, dim::angular_momentum_t, prefix::exa);
implement_unit(si, si, zettanewton_metre_second_per_radian, _zettanewton_metre_second_per_radian, dim::angular_momentum_t, prefix::zetta);
implement_unit(si, si, yottanewton_metre_second_per_radian, _yottanewton_metre_second_per_radian, dim::angular_momentum_t, prefix::yotta);
#pragma endregion
#pragma region newton metre minute per radian(angular momentum)
implement_unit(si, si, yoctonewton_metre_minute_per_radian, _yoctonewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yocto>));
implement_unit(si, si, zeptonewton_metre_minute_per_radian, _zeptonewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zepto>));
implement_unit(si, si, attonewton_metre_minute_per_radian, _attonewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::atto>));
implement_unit(si, si, femtonewton_metre_minute_per_radian, _femtonewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::femto>));
implement_unit(si, si, piconewton_metre_minute_per_radian, _piconewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::pico>));
implement_unit(si, si, nanonewton_metre_minute_per_radian, _nanonewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::nano>));
implement_unit(si, si, micronewton_metre_minute_per_radian, _micronewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::micro>));
implement_unit(si, si, millinewton_metre_minute_per_radian, _millinewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::milli>));
implement_unit(si, si, centinewton_metre_minute_per_radian, _centinewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::centi>));
implement_unit(si, si, decinewton_metre_minute_per_radian, _decinewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deci>));
implement_unit(si, si, newton_metre_minute_per_radian, _newton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::one>));
implement_unit(si, si, decanewton_metre_minute_per_radian, _decanewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deca>));
implement_unit(si, si, hectonewton_metre_minute_per_radian, _hectonewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::hecto>));
implement_unit(si, si, kilonewton_metre_minute_per_radian, _kilonewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::kilo>));
implement_unit(si, si, meganewton_metre_minute_per_radian, _meganewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::mega>));
implement_unit(si, si, giganewton_metre_minute_per_radian, _giganewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::giga>));
implement_unit(si, si, teranewton_metre_minute_per_radian, _teranewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::tera>));
implement_unit(si, si, petanewton_metre_minute_per_radian, _petanewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::peta>));
implement_unit(si, si, exanewton_metre_minute_per_radian, _exanewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::exa>));
implement_unit(si, si, zettanewton_metre_minute_per_radian, _zettanewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zetta>));
implement_unit(si, si, yottanewton_metre_minute_per_radian, _yottanewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yotta>));
#pragma endregion
#pragma region newton metre hour per radian(angular momentum)
implement_unit(si, si, yoctonewton_metre_hour_per_radian, _yoctonewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yocto>));
implement_unit(si, si, zeptonewton_metre_hour_per_radian, _zeptonewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zepto>));
implement_unit(si, si, attonewton_metre_hour_per_radian, _attonewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::atto>));
implement_unit(si, si, femtonewton_metre_hour_per_radian, _femtonewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::femto>));
implement_unit(si, si, piconewton_metre_hour_per_radian, _piconewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::pico>));
implement_unit(si, si, nanonewton_metre_hour_per_radian, _nanonewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::nano>));
implement_unit(si, si, micronewton_metre_hour_per_radian, _micronewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::micro>));
implement_unit(si, si, millinewton_metre_hour_per_radian, _millinewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::milli>));
implement_unit(si, si, centinewton_metre_hour_per_radian, _centinewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::centi>));
implement_unit(si, si, decinewton_metre_hour_per_radian, _decinewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deci>));
implement_unit(si, si, newton_metre_hour_per_radian, _newton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::one>));
implement_unit(si, si, decanewton_metre_hour_per_radian, _decanewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deca>));
implement_unit(si, si, hectonewton_metre_hour_per_radian, _hectonewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::hecto>));
implement_unit(si, si, kilonewton_metre_hour_per_radian, _kilonewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::kilo>));
implement_unit(si, si, meganewton_metre_hour_per_radian, _meganewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::mega>));
implement_unit(si, si, giganewton_metre_hour_per_radian, _giganewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::giga>));
implement_unit(si, si, teranewton_metre_hour_per_radian, _teranewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::tera>));
implement_unit(si, si, petanewton_metre_hour_per_radian, _petanewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::peta>));
implement_unit(si, si, exanewton_metre_hour_per_radian, _exanewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::exa>));
implement_unit(si, si, zettanewton_metre_hour_per_radian, _zettanewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zetta>));
implement_unit(si, si, yottanewton_metre_hour_per_radian, _yottanewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yotta>));
#pragma endregion
#pragma region square metre kilogram per steradian(moment of inertia)
implement_unit(si, si, square_metre_yoctogram_per_steradian, _square_metre_yoctogram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::yocto, prefix::milli>));
implement_unit(si, si, square_metre_zeptogram_per_steradian, _square_metre_zeptogram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::zepto, prefix::milli>));
implement_unit(si, si, square_metre_attogram_per_steradian, _square_metre_attogram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::atto, prefix::milli>));
implement_unit(si, si, square_metre_femtogram_per_steradian, _square_metre_femtogram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::femto, prefix::milli>));
implement_unit(si, si, square_metre_picogram_per_steradian, _square_metre_picogram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::pico, prefix::milli>));
implement_unit(si, si, square_metre_nanogram_per_steradian, _square_metre_nanogram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::nano, prefix::milli>));
implement_unit(si, si, square_metre_microgram_per_steradian, _square_metre_microgram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::micro, prefix::milli>));
implement_unit(si, si, square_metre_milligram_per_steradian, _square_metre_milligram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::milli, prefix::milli>));
implement_unit(si, si, square_metre_centigram_per_steradian, _square_metre_centigram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::centi, prefix::milli>));
implement_unit(si, si, square_metre_decigram_per_steradian, _square_metre_decigram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::deci, prefix::milli>));
implement_unit(si, si, square_metre_gram_per_steradian, _square_metre_gram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::one, prefix::milli>));
implement_unit(si, si, square_metre_decagram_per_steradian, _square_metre_decagram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::deca, prefix::milli>));
implement_unit(si, si, square_metre_hectogram_per_steradian, _square_metre_hectogram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::hecto, prefix::milli>));
implement_unit(si, si, square_metre_kilogram_per_steradian, _square_metre_kilogram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::kilo, prefix::milli>));
implement_unit(si, si, square_metre_megagram_per_steradian, _square_metre_megagram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::mega, prefix::milli>));
link_unit(square_metre_tonne_per_steradian, _square_metre_tonne_per_steradian, square_metre_megagram_per_steradian);
implement_unit(si, si, square_metre_gigagram_per_steradian, _square_metre_gigagram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::giga, prefix::milli>));
link_unit(square_metre_kilotonne_per_steradian, _square_metre_kilotonne_per_steradian, square_metre_gigagram_per_steradian);
implement_unit(si, si, square_metre_teragram_per_steradian, _square_metre_teragram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::tera, prefix::milli>));
link_unit(square_metre_megatonne_per_steradian, _square_metre_megatonne_per_steradian, square_metre_teragram_per_steradian);
implement_unit(si, si, square_metre_petagram_per_steradian, _square_metre_petagram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::peta, prefix::milli>));
link_unit(square_metre_gigatonne_per_steradian, _square_metre_gigatonne_per_steradian, square_metre_petagram_per_steradian);
implement_unit(si, si, square_metre_exagram_per_steradian, _square_metre_exagram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::exa, prefix::milli>));
implement_unit(si, si, square_metre_zettagram_per_steradian, _square_metre_zettagram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::zetta, prefix::milli>));
implement_unit(si, si, square_metre_yottagram_per_steradian, _square_metre_yottagram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::yotta, prefix::milli>));
#pragma endregion
#pragma endregion
#pragma region special units for the constants
#pragma region joule per tesla(bohr magneton)
implement_unit(si, si, yoctojoule_per_tesla, _yoctojoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::yocto);
implement_unit(si, si, zeptojoule_per_tesla, _zeptojoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::zepto);
implement_unit(si, si, attojoule_per_tesla, _attojoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::atto);
implement_unit(si, si, femtojoule_per_tesla, _femtojoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::femto);
implement_unit(si, si, picojoule_per_tesla, _picojoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::pico);
implement_unit(si, si, nanojoule_per_tesla, _nanojoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::nano);
implement_unit(si, si, microjoule_per_tesla, _microjoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::micro);
implement_unit(si, si, millijoule_per_tesla, _millijoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::milli);
implement_unit(si, si, centijoule_per_tesla, _centijoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::centi);
implement_unit(si, si, decijoule_per_tesla, _decijoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::deci);
implement_unit(si, si, joule_per_tesla, _joule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::one);
implement_unit(si, si, decajoule_per_tesla, _decajoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::deca);
implement_unit(si, si, hectojoule_per_tesla, _hectojoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::hecto);
implement_unit(si, si, kilojoule_per_tesla, _kilojoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::kilo);
implement_unit(si, si, megajoule_per_tesla, _megajoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::mega);
implement_unit(si, si, gigajoule_per_tesla, _gigajoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::giga);
implement_unit(si, si, terajoule_per_tesla, _terajoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::tera);
implement_unit(si, si, petajoule_per_tesla, _petajoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::peta);
implement_unit(si, si, exajoule_per_tesla, _exajoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::exa);
implement_unit(si, si, zettajoule_per_tesla, _zettajoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::zetta);
implement_unit(si, si, yottajoule_per_tesla, _yottajoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::yotta);
#pragma endregion
#pragma region one per mole(avogadro constant)
implement_unit(si, si, one_per_yoctomole, _one_per_yoctomole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::yocto>));
implement_unit(si, si, one_per_zeptomole, _one_per_zeptomole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::zepto>));
implement_unit(si, si, one_per_attomole, _one_per_attomole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::atto>));
implement_unit(si, si, one_per_femtomole, _one_per_femtomole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::femto>));
implement_unit(si, si, one_per_picomole, _one_per_picomole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::pico>));
implement_unit(si, si, one_per_nanomole, _one_per_nanomole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::nano>));
implement_unit(si, si, one_per_micromole, _one_per_micromole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::micro>));
implement_unit(si, si, one_per_millimole, _one_per_millimole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::milli>));
implement_unit(si, si, one_per_centimole, _one_per_centimole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::centi>));
implement_unit(si, si, one_per_decimole, _one_per_decimole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::deci>));
implement_unit(si, si, one_per_mole, _one_per_mole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::one>));
implement_unit(si, si, one_per_decamole, _one_per_decamole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::deca>));
implement_unit(si, si, one_per_hectomole, _one_per_hectomole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::hecto>));
implement_unit(si, si, one_per_kilomole, _one_per_kilomole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::kilo>));
implement_unit(si, si, one_per_megamole, _one_per_megamole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::mega>));
implement_unit(si, si, one_per_gigamole, _one_per_gigamole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::giga>));
implement_unit(si, si, one_per_teramole, _one_per_teramole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::tera>));
implement_unit(si, si, one_per_petamole, _one_per_petamole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::peta>));
implement_unit(si, si, one_per_examole, _one_per_examole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::exa>));
implement_unit(si, si, one_per_zettamole, _one_per_zettamole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::zetta>));
implement_unit(si, si, one_per_yottamole, _one_per_yottamole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::yotta>));
#pragma endregion
#pragma region coulomb per mole(faraday constant)
implement_unit(si, si, yoctocoulomb_per_mole, _yoctocoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::yocto);
implement_unit(si, si, zeptocoulomb_per_mole, _zeptocoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::zepto);
implement_unit(si, si, attocoulomb_per_mole, _attocoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::atto);
implement_unit(si, si, femtocoulomb_per_mole, _femtocoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::femto);
implement_unit(si, si, picocoulomb_per_mole, _picocoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::pico);
implement_unit(si, si, nanocoulomb_per_mole, _nanocoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::nano);
implement_unit(si, si, microcoulomb_per_mole, _microcoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::micro);
implement_unit(si, si, millicoulomb_per_mole, _millicoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::milli);
implement_unit(si, si, centicoulomb_per_mole, _centicoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::centi);
implement_unit(si, si, decicoulomb_per_mole, _decicoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::deci);
implement_unit(si, si, coulomb_per_mole, _coulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::one);
implement_unit(si, si, decacoulomb_per_mole, _decacoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::deca);
implement_unit(si, si, hectocoulomb_per_mole, _hectocoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::hecto);
implement_unit(si, si, kilocoulomb_per_mole, _kilocoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::kilo);
implement_unit(si, si, megacoulomb_per_mole, _megacoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::mega);
implement_unit(si, si, gigacoulomb_per_mole, _gigacoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::giga);
implement_unit(si, si, teracoulomb_per_mole, _teracoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::tera);
implement_unit(si, si, petacoulomb_per_mole, _petacoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::peta);
implement_unit(si, si, exacoulomb_per_mole, _exacoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::exa);
implement_unit(si, si, zettacoulomb_per_mole, _zettacoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::zetta);
implement_unit(si, si, yottacoulomb_per_mole, _yottacoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::yotta);
#pragma endregion
#pragma region hertz per volt(josephson constant)
implement_unit(si, si, yoctohertz_per_volt, _yoctohertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::yocto);
implement_unit(si, si, zeptohertz_per_volt, _zeptohertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::zepto);
implement_unit(si, si, attohertz_per_volt, _attohertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::atto);
implement_unit(si, si, femtohertz_per_volt, _femtohertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::femto);
implement_unit(si, si, picohertz_per_volt, _picohertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::pico);
implement_unit(si, si, nanohertz_per_volt, _nanohertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::nano);
implement_unit(si, si, microhertz_per_volt, _microhertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::micro);
implement_unit(si, si, millihertz_per_volt, _millihertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::milli);
implement_unit(si, si, centihertz_per_volt, _centihertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::centi);
implement_unit(si, si, decihertz_per_volt, _decihertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::deci);
implement_unit(si, si, hertz_per_volt, _hertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::one);
implement_unit(si, si, decahertz_per_volt, _decahertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::deca);
implement_unit(si, si, hectohertz_per_volt, _hectohertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::hecto);
implement_unit(si, si, kilohertz_per_volt, _kilohertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::kilo);
implement_unit(si, si, megahertz_per_volt, _megahertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::mega);
implement_unit(si, si, gigahertz_per_volt, _gigahertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::giga);
implement_unit(si, si, terahertz_per_volt, _terahertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::tera);
implement_unit(si, si, petahertz_per_volt, _petahertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::peta);
implement_unit(si, si, exahertz_per_volt, _exahertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::exa);
implement_unit(si, si, zettahertz_per_volt, _zettahertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::zetta);
implement_unit(si, si, yottahertz_per_volt, _yottahertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::yotta);
#pragma endregion
#pragma region newton per square metre kilogram(gravitational constant)
implement_unit(si, si, yoctonewton_square_metre_per_square_kilogram, _yoctonewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::yocto);
implement_unit(si, si, zeptonewton_square_metre_per_square_kilogram, _zeptonewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::zepto);
implement_unit(si, si, attonewton_square_metre_per_square_kilogram, _attonewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::atto);
implement_unit(si, si, femtonewton_square_metre_per_square_kilogram, _femtonewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::femto);
implement_unit(si, si, piconewton_square_metre_per_square_kilogram, _piconewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::pico);
implement_unit(si, si, nanonewton_square_metre_per_square_kilogram, _nanonewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::nano);
implement_unit(si, si, micronewton_square_metre_per_square_kilogram, _micronewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::micro);
implement_unit(si, si, millinewton_square_metre_per_square_kilogram, _millinewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::milli);
implement_unit(si, si, centinewton_square_metre_per_square_kilogram, _centinewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::centi);
implement_unit(si, si, decinewton_square_metre_per_square_kilogram, _decinewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::deci);
implement_unit(si, si, newton_square_metre_per_square_kilogram, _newton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::one);
implement_unit(si, si, decanewton_square_metre_per_square_kilogram, _decanewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::deca);
implement_unit(si, si, hectonewton_square_metre_per_square_kilogram, _hectonewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::hecto);
implement_unit(si, si, kilonewton_square_metre_per_square_kilogram, _kilonewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::kilo);
implement_unit(si, si, meganewton_square_metre_per_square_kilogram, _meganewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::mega);
implement_unit(si, si, giganewton_square_metre_per_square_kilogram, _giganewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::giga);
implement_unit(si, si, teranewton_square_metre_per_square_kilogram, _teranewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::tera);
implement_unit(si, si, petanewton_square_metre_per_square_kilogram, _petanewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::peta);
implement_unit(si, si, exanewton_square_metre_per_square_kilogram, _exanewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::exa);
implement_unit(si, si, zettanewton_square_metre_per_square_kilogram, _zettanewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::zetta);
implement_unit(si, si, yottanewton_square_metre_per_square_kilogram, _yottanewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::yotta);
#pragma endregion
#pragma region watt per square metre quartic kelvin steradian(stefan - boltzmann constant)
implement_unit(si, si, yoctowatt_per_square_metre_quartic_kelvin_steradian, _yoctowatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::yocto);
implement_unit(si, si, zeptowatt_per_square_metre_quartic_kelvin_steradian, _zeptowatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::zepto);
implement_unit(si, si, attowatt_per_square_metre_quartic_kelvin_steradian, _attowatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::atto);
implement_unit(si, si, femtowatt_per_square_metre_quartic_kelvin_steradian, _femtowatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::femto);
implement_unit(si, si, picowatt_per_square_metre_quartic_kelvin_steradian, _picowatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::pico);
implement_unit(si, si, nanowatt_per_square_metre_quartic_kelvin_steradian, _nanowatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::nano);
implement_unit(si, si, microwatt_per_square_metre_quartic_kelvin_steradian, _microwatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::micro);
implement_unit(si, si, milliwatt_per_square_metre_quartic_kelvin_steradian, _milliwatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::milli);
implement_unit(si, si, centiwatt_per_square_metre_quartic_kelvin_steradian, _centiwatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::centi);
implement_unit(si, si, deciwatt_per_square_metre_quartic_kelvin_steradian, _deciwatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::deci);
implement_unit(si, si, watt_per_square_metre_quartic_kelvin_steradian, _watt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::one);
implement_unit(si, si, decawatt_per_square_metre_quartic_kelvin_steradian, _decawatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::deca);
implement_unit(si, si, hectowatt_per_square_metre_quartic_kelvin_steradian, _hectowatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::hecto);
implement_unit(si, si, kilowatt_per_square_metre_quartic_kelvin_steradian, _kilowatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::kilo);
implement_unit(si, si, megawatt_per_square_metre_quartic_kelvin_steradian, _megawatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::mega);
implement_unit(si, si, gigawatt_per_square_metre_quartic_kelvin_steradian, _gigawatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::giga);
implement_unit(si, si, terawatt_per_square_metre_quartic_kelvin_steradian, _terawatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::tera);
implement_unit(si, si, petawatt_per_square_metre_quartic_kelvin_steradian, _petawatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::peta);
implement_unit(si, si, exawatt_per_square_metre_quartic_kelvin_steradian, _exawatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::exa);
implement_unit(si, si, zettawatt_per_square_metre_quartic_kelvin_steradian, _zettawatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::zetta);
implement_unit(si, si, yottawatt_per_square_metre_quartic_kelvin_steradian, _yottawatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::yotta);
#pragma endregion
#pragma endregion
#pragma region constants
namespace constant
{
using namespace benri::si::base;
#pragma region physical constants
create_constant(speed_of_light, prefix::speed_of_light_v, metre_per_second);
create_constant(magnetic_constant, prefix::magnetic_constant_v, henry_per_metre);
create_constant(electric_constant, prefix::electric_constant_v, farad_per_metre);
create_constant(gravitational_constant, prefix::gravitational_constant_v, newton_square_metre_per_square_kilogram);
create_constant(planck_constant, prefix::planck_constant_v, joule_second);
create_constant(reduced_planck_constant, prefix::reduced_planck_constant_v, joule_second);
create_constant(elementary_charge, prefix::elementary_charge_v, coulomb);
create_constant(fine_structure_constant, prefix::fine_structure_constant_v, one);
create_constant(inverse_fine_structure_constant, prefix::inverse_fine_structure_constant_v, one);
create_constant(electron_mass, prefix::electron_mass_v, kilogram);
create_constant(proton_mass, prefix::proton_mass_v, kilogram);
create_constant(muon_mass, prefix::muon_mass_v, kilogram);
create_constant(tau_mass, prefix::tau_mass_v, kilogram);
create_constant(neutron_mass, prefix::neutron_mass_v, kilogram);
create_constant(deuteron_mass, prefix::deuteron_mass_v, kilogram);
create_constant(triton_mass, prefix::triton_mass_v, kilogram);
create_constant(helion_mass, prefix::helion_mass_v, kilogram);
create_constant(alpha_particle_mass, prefix::alpha_particle_mass_v, kilogram);
create_constant(rydberg_constant, prefix::rydberg_constant_v, one_per_metre);
create_constant(bohr_radius, prefix::bohr_radius_v, metre);
create_constant(bohr_magneton, prefix::bohr_magneton_v, joule_per_tesla);
create_constant(avogadro_constant, prefix::avogadro_constant_v, one_per_mole);
create_constant(faraday_constant, prefix::faraday_constant_v, coulomb_per_mole);
create_constant(molar_gas_constant, prefix::molar_gas_constant_v, joule_per_mole_kelvin);
create_constant(boltzmann_constant, prefix::boltzmann_constant_v, joule_per_kelvin);
create_constant(stefan_boltzmann_constant, prefix::stefan_boltzmann_constant_v, watt_per_square_metre_quartic_kelvin_steradian);
create_constant(magnetic_flux_quantum, prefix::magnetic_flux_quantum_v, weber);
create_constant(josephson_constant, prefix::josephson_constant_v, hertz_per_volt);
create_constant(von_klitzing_constant, prefix::von_klitzing_constant_v, ohm);
create_constant(atomic_mass_unit, prefix::atomic_mass_unit_v, kilogram);
create_constant(hartree_energy, prefix::hartree_energy_v, joule);
create_constant(conductance_quantum, prefix::conductance_quantum_v, siemens);
create_constant(inverse_conductance_quantum, prefix::inverse_conductance_quantum_v, ohm);
create_constant(vacuum_impedance, prefix::vacuum_impedance_v, ohm);
create_constant(nuclear_magneton, prefix::nuclear_magneton_v, joule_per_tesla);
#pragma endregion
} // namespace constant
#pragma endregion
#pragma region symbols
namespace symbol
{
#pragma region physical constants
create_symbol(si, speed_of_light, dim::velocity_t, prefix::speed_of_light_t);
create_symbol(si, magnetic_constant, dim::permeability_t, prefix::magnetic_constant_t);
create_symbol(si, electric_constant, dim::permittivity_t, prefix::electric_constant_t);
create_symbol(si, gravitational_constant, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::gravitational_constant_t);
create_symbol(si, planck_constant, dim::action_t, prefix::planck_constant_t);
create_symbol(si, reduced_planck_constant, dim::action_t, prefix::reduced_planck_constant_t);
create_symbol(si, elementary_charge, dim::electric_charge_t, prefix::elementary_charge_t);
create_symbol(si, fine_structure_constant, dim::dimensionless_t, prefix::fine_structure_constant_t);
create_symbol(si, inverse_fine_structure_constant, dim::dimensionless_t, prefix::inverse_fine_structure_constant_t);
create_symbol(si, electron_mass, dim::mass_t, prefix::electron_mass_t);
create_symbol(si, proton_mass, dim::mass_t, prefix::proton_mass_t);
create_symbol(si, muon_mass, dim::mass_t, prefix::muon_mass_t);
create_symbol(si, tau_mass, dim::mass_t, prefix::tau_mass_t);
create_symbol(si, neutron_mass, dim::mass_t, prefix::neutron_mass_t);
create_symbol(si, deuteron_mass, dim::mass_t, prefix::deuteron_mass_t);
create_symbol(si, triton_mass, dim::mass_t, prefix::triton_mass_t);
create_symbol(si, helion_mass, dim::mass_t, prefix::helion_mass_t);
create_symbol(si, alpha_particle_mass, dim::mass_t, prefix::alpha_particle_mass_t);
create_symbol(si, rydberg_constant, dim::wavenumber_t, prefix::rydberg_constant_t);
create_symbol(si, bohr_radius, dim::length_t, prefix::bohr_radius_t);
create_symbol(si, bohr_magneton, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::bohr_magneton_t);
create_symbol(si, avogadro_constant, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), prefix::avogadro_constant_t);
create_symbol(si, faraday_constant, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::faraday_constant_t);
create_symbol(si, molar_gas_constant, dim::molar_heat_capacity_t, prefix::molar_gas_constant_t);
create_symbol(si, boltzmann_constant, dim::heat_capacity_t, prefix::boltzmann_constant_t);
create_symbol(si, stefan_boltzmann_constant, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::stefan_boltzmann_constant_t);
create_symbol(si, magnetic_flux_quantum, dim::magnetic_flux_t, prefix::magnetic_flux_quantum_t);
create_symbol(si, josephson_constant, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::josephson_constant_t);
create_symbol(si, von_klitzing_constant, dim::electric_resistance_t, prefix::von_klitzing_constant_t);
create_symbol(si, atomic_mass_unit, dim::mass_t, prefix::atomic_mass_unit_t);
create_symbol(si, hartree_energy, dim::energy_t, prefix::hartree_energy_t);
create_symbol(si, conductance_quantum, dim::electric_conductance_t, prefix::conductance_quantum_t);
create_symbol(si, inverse_conductance_quantum, dim::electric_resistance_t, prefix::inverse_conductance_quantum_t);
create_symbol(si, vacuum_impedance, dim::electric_resistance_t, prefix::vacuum_impedance_t);
create_symbol(si, nuclear_magneton, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::nuclear_magneton_t);
#pragma endregion
} // namespace symbol
#pragma endregion
} // namespace si
} // namespace benri