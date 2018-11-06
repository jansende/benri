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
implement_unit(si, si, natural_unit_of_speed, dim::velocity_t, prefix::speed_of_light_t);
implement_unit(si, si, knot, dim::velocity_t, fix(impl::divide_lists_t<prefix::nautical_mile_t,prefix::hour>));
#pragma region angstroem, ...(length)
implement_unit(si, si, angstroem, dim::length_t, prefix::angstroem_t);
implement_unit(si, si, bohr, dim::length_t, prefix::bohr_t);
implement_unit(si, si, nautical_mile, dim::length_t, prefix::nautical_mile_t);
implement_unit(si, si, international_mile, dim::length_t, prefix::international_mile_t);
implement_unit(si, si, yard, dim::length_t, prefix::yard_t);
implement_unit(si, si, international_foot, dim::length_t, prefix::international_foot_t);
implement_unit(si, si, inch, dim::length_t, prefix::inch_t);
#pragma endregion
#pragma region dalton, ...(mass)
implement_unit(si, si, dalton, dim::mass_t, prefix::atomic_mass_unit_t);
link_unit(atomic_mass_unit, dalton);
implement_unit(si, si, natural_unit_of_mass, dim::mass_t, prefix::electron_mass_t);
implement_unit(si, si, carat, dim::mass_t, fix(impl::multiply_lists_t<make_fraction_list_t<2>,make_power_list_t<-4>>));
implement_unit(si, si, pound, dim::mass_t, prefix::pound_t);
implement_unit(si, si, ounce, dim::mass_t, prefix::ounce_t);
#pragma endregion
#pragma region minute, hour, ...(time)
implement_unit(si, si, minute, dim::time_t, prefix::minute);
implement_unit(si, si, hour, dim::time_t, prefix::hour);
implement_unit(si, si, day, dim::time_t, prefix::day);
implement_unit(si, si, week, dim::time_t, prefix::week);
implement_unit(si, si, month, dim::time_t, prefix::month);
implement_unit(si, si, year, dim::time_t, prefix::year);
implement_unit(si, si, kiloyear, dim::time_t, fix(impl::multiply_lists_t<prefix::kilo, prefix::year>));
implement_unit(si, si, megayear, dim::time_t, fix(impl::multiply_lists_t<prefix::mega, prefix::year>));
implement_unit(si, si, gigayear, dim::time_t, fix(impl::multiply_lists_t<prefix::giga, prefix::year>));
implement_unit(si, si, sidereal_year, dim::time_t, prefix::sidereal_year);
implement_unit(si, si, tropical_year, dim::time_t, prefix::tropical_year);
implement_unit(si, si, natural_unit_of_time, dim::time_t, fix(impl::divide_lists_t<prefix::reduced_planck_constant_t,impl::multiply_lists_t<prefix::electron_mass_t,impl::pow_list_t<prefix::speed_of_light_t,std::ratio<2>>>>));
implement_unit(si, si, atomic_unit_of_time, dim::time_t, fix(impl::divide_lists_t<prefix::reduced_planck_constant_t,prefix::hartree_energy_t>));
#pragma endregion
#pragma region square metre(area)
implement_unit(si, si, barn, dim::area_t, make_power_list_t<-28>);
implement_unit(si, si, square_picometre, dim::area_t, prefix::yocto);
implement_unit(si, si, square_nanometre, dim::area_t, prefix::atto);
implement_unit(si, si, square_micrometre, dim::area_t, prefix::pico);
implement_unit(si, si, square_millimetre, dim::area_t, prefix::micro);
implement_unit(si, si, square_centimetre, dim::area_t, fix(make_fraction_list_t<1, 10000>));
implement_unit(si, si, square_decimetre, dim::area_t, prefix::centi);
implement_unit(si, si, square_metre, dim::area_t, prefix::one);
implement_unit(si, si, hectare, dim::area_t, make_fraction_list_t<10000>);
implement_unit(si, si, square_kilometre, dim::area_t, prefix::mega);
#pragma endregion
#pragma region cubic metre(volume)
implement_unit(si, si, cubic_micrometre, dim::volume_t, prefix::atto);
implement_unit(si, si, cubic_millimetre, dim::volume_t, prefix::nano);
implement_unit(si, si, cubic_centimetre, dim::volume_t, prefix::micro);
link_unit(millilitre, cubic_centimetre);
implement_unit(si, si, cubic_decimetre, dim::volume_t, prefix::milli);
link_unit(litre, cubic_decimetre);
implement_unit(si, si, cubic_metre, dim::volume_t, prefix::one);
implement_unit(si, si, cubic_kilometre, dim::volume_t, prefix::giga);
#pragma endregion
#pragma region metre per second(velocity)
implement_unit(si, si, yoctometre_per_second, dim::velocity_t, prefix::yocto);
implement_unit(si, si, zeptometre_per_second, dim::velocity_t, prefix::zepto);
implement_unit(si, si, attometre_per_second, dim::velocity_t, prefix::atto);
implement_unit(si, si, femtometre_per_second, dim::velocity_t, prefix::femto);
implement_unit(si, si, picometre_per_second, dim::velocity_t, prefix::pico);
implement_unit(si, si, nanometre_per_second, dim::velocity_t, prefix::nano);
implement_unit(si, si, micrometre_per_second, dim::velocity_t, prefix::micro);
implement_unit(si, si, millimetre_per_second, dim::velocity_t, prefix::milli);
implement_unit(si, si, centimetre_per_second, dim::velocity_t, prefix::centi);
implement_unit(si, si, decimetre_per_second, dim::velocity_t, prefix::deci);
implement_unit(si, si, metre_per_second, dim::velocity_t, prefix::one);
implement_unit(si, si, decametre_per_second, dim::velocity_t, prefix::deca);
implement_unit(si, si, hectometre_per_second, dim::velocity_t, prefix::hecto);
implement_unit(si, si, kilometre_per_second, dim::velocity_t, prefix::kilo);
implement_unit(si, si, megametre_per_second, dim::velocity_t, prefix::mega);
implement_unit(si, si, gigametre_per_second, dim::velocity_t, prefix::giga);
implement_unit(si, si, terametre_per_second, dim::velocity_t, prefix::tera);
implement_unit(si, si, petametre_per_second, dim::velocity_t, prefix::peta);
implement_unit(si, si, exametre_per_second, dim::velocity_t, prefix::exa);
implement_unit(si, si, zettametre_per_second, dim::velocity_t, prefix::zetta);
implement_unit(si, si, yottametre_per_second, dim::velocity_t, prefix::yotta);
#pragma endregion
#pragma region metre per minute(velocity)
implement_unit(si, si, yoctometre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::yocto, prefix::minute>));
implement_unit(si, si, zeptometre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::zepto, prefix::minute>));
implement_unit(si, si, attometre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::atto, prefix::minute>));
implement_unit(si, si, femtometre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::femto, prefix::minute>));
implement_unit(si, si, picometre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::pico, prefix::minute>));
implement_unit(si, si, nanometre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::nano, prefix::minute>));
implement_unit(si, si, micrometre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::micro, prefix::minute>));
implement_unit(si, si, millimetre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::milli, prefix::minute>));
implement_unit(si, si, centimetre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::centi, prefix::minute>));
implement_unit(si, si, decimetre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::deci, prefix::minute>));
implement_unit(si, si, metre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::one, prefix::minute>));
implement_unit(si, si, decametre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::deca, prefix::minute>));
implement_unit(si, si, hectometre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::hecto, prefix::minute>));
implement_unit(si, si, kilometre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::kilo, prefix::minute>));
implement_unit(si, si, megametre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::mega, prefix::minute>));
implement_unit(si, si, gigametre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::giga, prefix::minute>));
implement_unit(si, si, terametre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::tera, prefix::minute>));
implement_unit(si, si, petametre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::peta, prefix::minute>));
implement_unit(si, si, exametre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::exa, prefix::minute>));
implement_unit(si, si, zettametre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::zetta, prefix::minute>));
implement_unit(si, si, yottametre_per_minute, dim::velocity_t, fix(impl::divide_lists_t<prefix::yotta, prefix::minute>));
#pragma endregion
#pragma region metre per hour(velocity)
implement_unit(si, si, yoctometre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::yocto, prefix::hour>));
implement_unit(si, si, zeptometre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::zepto, prefix::hour>));
implement_unit(si, si, attometre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::atto, prefix::hour>));
implement_unit(si, si, femtometre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::femto, prefix::hour>));
implement_unit(si, si, picometre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::pico, prefix::hour>));
implement_unit(si, si, nanometre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::nano, prefix::hour>));
implement_unit(si, si, micrometre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::micro, prefix::hour>));
implement_unit(si, si, millimetre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::milli, prefix::hour>));
implement_unit(si, si, centimetre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::centi, prefix::hour>));
implement_unit(si, si, decimetre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::deci, prefix::hour>));
implement_unit(si, si, metre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::one, prefix::hour>));
implement_unit(si, si, decametre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::deca, prefix::hour>));
implement_unit(si, si, hectometre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::hecto, prefix::hour>));
implement_unit(si, si, kilometre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::kilo, prefix::hour>));
implement_unit(si, si, megametre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::mega, prefix::hour>));
implement_unit(si, si, gigametre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::giga, prefix::hour>));
implement_unit(si, si, terametre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::tera, prefix::hour>));
implement_unit(si, si, petametre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::peta, prefix::hour>));
implement_unit(si, si, exametre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::exa, prefix::hour>));
implement_unit(si, si, zettametre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::zetta, prefix::hour>));
implement_unit(si, si, yottametre_per_hour, dim::velocity_t, fix(impl::divide_lists_t<prefix::yotta, prefix::hour>));
#pragma endregion
#pragma region metre per square second(acceleration)
implement_unit(si, si, yoctometre_per_square_second, dim::acceleration_t, prefix::yocto);
implement_unit(si, si, zeptometre_per_square_second, dim::acceleration_t, prefix::zepto);
implement_unit(si, si, attometre_per_square_second, dim::acceleration_t, prefix::atto);
implement_unit(si, si, femtometre_per_square_second, dim::acceleration_t, prefix::femto);
implement_unit(si, si, picometre_per_square_second, dim::acceleration_t, prefix::pico);
implement_unit(si, si, nanometre_per_square_second, dim::acceleration_t, prefix::nano);
implement_unit(si, si, micrometre_per_square_second, dim::acceleration_t, prefix::micro);
implement_unit(si, si, millimetre_per_square_second, dim::acceleration_t, prefix::milli);
implement_unit(si, si, centimetre_per_square_second, dim::acceleration_t, prefix::centi);
implement_unit(si, si, decimetre_per_square_second, dim::acceleration_t, prefix::deci);
implement_unit(si, si, metre_per_square_second, dim::acceleration_t, prefix::one);
implement_unit(si, si, decametre_per_square_second, dim::acceleration_t, prefix::deca);
implement_unit(si, si, hectometre_per_square_second, dim::acceleration_t, prefix::hecto);
implement_unit(si, si, kilometre_per_square_second, dim::acceleration_t, prefix::kilo);
implement_unit(si, si, megametre_per_square_second, dim::acceleration_t, prefix::mega);
implement_unit(si, si, gigametre_per_square_second, dim::acceleration_t, prefix::giga);
implement_unit(si, si, terametre_per_square_second, dim::acceleration_t, prefix::tera);
implement_unit(si, si, petametre_per_square_second, dim::acceleration_t, prefix::peta);
implement_unit(si, si, exametre_per_square_second, dim::acceleration_t, prefix::exa);
implement_unit(si, si, zettametre_per_square_second, dim::acceleration_t, prefix::zetta);
implement_unit(si, si, yottametre_per_square_second, dim::acceleration_t, prefix::yotta);
#pragma endregion
#pragma region metre per square minute(acceleration)
implement_unit(si, si, yoctometre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::yocto, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, zeptometre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::zepto, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, attometre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::atto, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, femtometre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::femto, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, picometre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::pico, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, nanometre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::nano, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, micrometre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::micro, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, millimetre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::milli, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, centimetre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::centi, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, decimetre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::deci, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, metre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::one, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, decametre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::deca, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, hectometre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::hecto, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, kilometre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::kilo, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, megametre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::mega, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, gigametre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::giga, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, terametre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::tera, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, petametre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::peta, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, exametre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::exa, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, zettametre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::zetta, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, yottametre_per_square_minute, dim::acceleration_t, fix(impl::divide_lists_t<prefix::yotta, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
#pragma endregion
#pragma region metre per square hour(acceleration)
implement_unit(si, si, yoctometre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::yocto, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, zeptometre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::zepto, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, attometre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::atto, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, femtometre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::femto, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, picometre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::pico, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, nanometre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::nano, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, micrometre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::micro, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, millimetre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::milli, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, centimetre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::centi, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, decimetre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::deci, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, metre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::one, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, decametre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::deca, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, hectometre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::hecto, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, kilometre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::kilo, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, megametre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::mega, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, gigametre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::giga, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, terametre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::tera, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, petametre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::peta, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, exametre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::exa, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, zettametre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::zetta, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, yottametre_per_square_hour, dim::acceleration_t, fix(impl::divide_lists_t<prefix::yotta, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
#pragma endregion
#pragma region one per metre(wavenumber)
implement_unit(si, si, one_per_yoctometre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::yocto>));
implement_unit(si, si, one_per_zeptometre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::zepto>));
implement_unit(si, si, one_per_attometre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::atto>));
implement_unit(si, si, one_per_femtometre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::femto>));
implement_unit(si, si, one_per_picometre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::pico>));
implement_unit(si, si, one_per_nanometre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::nano>));
implement_unit(si, si, one_per_micrometre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::micro>));
implement_unit(si, si, one_per_millimetre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::milli>));
implement_unit(si, si, one_per_centimetre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::centi>));
implement_unit(si, si, one_per_decimetre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::deci>));
implement_unit(si, si, one_per_metre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::one>));
implement_unit(si, si, one_per_decametre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::deca>));
implement_unit(si, si, one_per_hectometre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::hecto>));
implement_unit(si, si, one_per_kilometre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::kilo>));
implement_unit(si, si, one_per_megametre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::mega>));
implement_unit(si, si, one_per_gigametre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::giga>));
implement_unit(si, si, one_per_terametre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::tera>));
implement_unit(si, si, one_per_petametre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::peta>));
implement_unit(si, si, one_per_exametre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::exa>));
implement_unit(si, si, one_per_zettametre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::zetta>));
implement_unit(si, si, one_per_yottametre, dim::wavenumber_t, fix(impl::divide_lists_t<prefix::one, prefix::yotta>));
#pragma endregion
#pragma region kilogram per cubic metre(density)
implement_unit(si, si, yoctogram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::yocto, prefix::milli>));
implement_unit(si, si, zeptogram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::zepto, prefix::milli>));
implement_unit(si, si, attogram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::atto, prefix::milli>));
implement_unit(si, si, femtogram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::femto, prefix::milli>));
implement_unit(si, si, picogram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::pico, prefix::milli>));
implement_unit(si, si, nanogram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::nano, prefix::milli>));
implement_unit(si, si, microgram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::micro, prefix::milli>));
implement_unit(si, si, milligram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::milli, prefix::milli>));
implement_unit(si, si, centigram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::centi, prefix::milli>));
implement_unit(si, si, decigram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::deci, prefix::milli>));
implement_unit(si, si, gram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::one, prefix::milli>));
implement_unit(si, si, decagram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::deca, prefix::milli>));
implement_unit(si, si, hectogram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::hecto, prefix::milli>));
implement_unit(si, si, kilogram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::kilo, prefix::milli>));
implement_unit(si, si, megagram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::mega, prefix::milli>));
link_unit(tonne_per_cubic_metre, megagram_per_cubic_metre);
implement_unit(si, si, gigagram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::giga, prefix::milli>));
link_unit(kilotonne_per_cubic_metre, gigagram_per_cubic_metre);
implement_unit(si, si, teragram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::tera, prefix::milli>));
link_unit(megatonne_per_cubic_metre, teragram_per_cubic_metre);
implement_unit(si, si, petagram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::peta, prefix::milli>));
link_unit(gigatonne_per_cubic_metre, petagram_per_cubic_metre);
implement_unit(si, si, exagram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::exa, prefix::milli>));
implement_unit(si, si, zettagram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::zetta, prefix::milli>));
implement_unit(si, si, yottagram_per_cubic_metre, dim::density_t, fix(impl::multiply_lists_t<prefix::yotta, prefix::milli>));
#pragma endregion
#pragma region kilogram per cubic decimetre(density)
link_unit(yoctogram_per_cubic_decimetre, zeptogram_per_cubic_metre);
link_unit(zeptogram_per_cubic_decimetre, attogram_per_cubic_metre);
link_unit(attogram_per_cubic_decimetre, femtogram_per_cubic_metre);
link_unit(femtogram_per_cubic_decimetre, picogram_per_cubic_metre);
link_unit(picogram_per_cubic_decimetre, nanogram_per_cubic_metre);
link_unit(nanogram_per_cubic_decimetre, microgram_per_cubic_metre);
link_unit(microgram_per_cubic_decimetre, milligram_per_cubic_metre);
link_unit(milligram_per_cubic_decimetre, gram_per_cubic_metre);
link_unit(centigram_per_cubic_decimetre, decagram_per_cubic_metre);
link_unit(decigram_per_cubic_decimetre, hectogram_per_cubic_metre);
link_unit(gram_per_cubic_decimetre, kilogram_per_cubic_metre);
implement_unit(si, si, decagram_per_cubic_decimetre, dim::density_t, fix(impl::multiply_lists_t<prefix::kilo, impl::multiply_lists_t<prefix::deca, prefix::milli>>));
implement_unit(si, si, hectogram_per_cubic_decimetre, dim::density_t, fix(impl::multiply_lists_t<prefix::kilo, impl::multiply_lists_t<prefix::hecto, prefix::milli>>));
link_unit(kilogram_per_cubic_decimetre, megagram_per_cubic_metre);
link_unit(megagram_per_cubic_decimetre, gigagram_per_cubic_metre);
link_unit(tonne_per_cubic_decimetre, megagram_per_cubic_decimetre);
link_unit(gigagram_per_cubic_decimetre, teragram_per_cubic_metre);
link_unit(kilotonne_per_cubic_decimetre, gigagram_per_cubic_decimetre);
link_unit(teragram_per_cubic_decimetre, petagram_per_cubic_metre);
link_unit(megatonne_per_cubic_decimetre, teragram_per_cubic_decimetre);
link_unit(petagram_per_cubic_decimetre, exagram_per_cubic_metre);
link_unit(gigatonne_per_cubic_decimetre, petagram_per_cubic_decimetre);
link_unit(exagram_per_cubic_decimetre, zettagram_per_cubic_metre);
link_unit(zettagram_per_cubic_decimetre, yottagram_per_cubic_metre);
implement_unit(si, si, yottagram_per_cubic_decimetre, dim::density_t, fix(impl::multiply_lists_t<prefix::kilo, impl::multiply_lists_t<prefix::yotta, prefix::milli>>));
#pragma endregion
#pragma region kilogram per litre(density)
link_unit(yoctogram_per_litre, yoctogram_per_cubic_decimetre);
link_unit(zeptogram_per_litre, zeptogram_per_cubic_decimetre);
link_unit(attogram_per_litre, attogram_per_cubic_decimetre);
link_unit(femtogram_per_litre, femtogram_per_cubic_decimetre);
link_unit(picogram_per_litre, picogram_per_cubic_decimetre);
link_unit(nanogram_per_litre, nanogram_per_cubic_decimetre);
link_unit(microgram_per_litre, microgram_per_cubic_decimetre);
link_unit(milligram_per_litre, milligram_per_cubic_decimetre);
link_unit(centigram_per_litre, centigram_per_cubic_decimetre);
link_unit(decigram_per_litre, decigram_per_cubic_decimetre);
link_unit(gram_per_litre, gram_per_cubic_decimetre);
link_unit(decagram_per_litre, decagram_per_cubic_decimetre);
link_unit(hectogram_per_litre, hectogram_per_cubic_decimetre);
link_unit(kilogram_per_litre, kilogram_per_cubic_decimetre);
link_unit(megagram_per_litre, megagram_per_cubic_decimetre);
link_unit(tonne_per_litre, tonne_per_cubic_decimetre);
link_unit(gigagram_per_litre, gigagram_per_cubic_decimetre);
link_unit(kilotonne_per_litre, kilotonne_per_cubic_decimetre);
link_unit(teragram_per_litre, teragram_per_cubic_decimetre);
link_unit(megatonne_per_litre, megatonne_per_cubic_decimetre);
link_unit(petagram_per_litre, petagram_per_cubic_decimetre);
link_unit(gigatonne_per_litre, gigatonne_per_cubic_decimetre);
link_unit(exagram_per_litre, exagram_per_cubic_decimetre);
link_unit(zettagram_per_litre, zettagram_per_cubic_decimetre);
link_unit(yottagram_per_litre, yottagram_per_cubic_decimetre);
#pragma endregion
#pragma region kilogram per cubic centimetre(density)
link_unit(yoctogram_per_cubic_centimetre, attogram_per_cubic_metre);
link_unit(zeptogram_per_cubic_centimetre, femtogram_per_cubic_metre);
link_unit(attogram_per_cubic_centimetre, picogram_per_cubic_metre);
link_unit(femtogram_per_cubic_centimetre, nanogram_per_cubic_metre);
link_unit(picogram_per_cubic_centimetre, microgram_per_cubic_metre);
link_unit(nanogram_per_cubic_centimetre, milligram_per_cubic_metre);
link_unit(microgram_per_cubic_centimetre, gram_per_cubic_metre);
link_unit(milligram_per_cubic_centimetre, kilogram_per_cubic_metre);
link_unit(centigram_per_cubic_centimetre, decagram_per_cubic_decimetre);
link_unit(decigram_per_cubic_centimetre, hectogram_per_cubic_decimetre);
link_unit(gram_per_cubic_centimetre, megagram_per_cubic_metre);
implement_unit(si, si, decagram_per_cubic_centimetre, dim::density_t, fix(impl::multiply_lists_t<prefix::mega, impl::multiply_lists_t<prefix::deca, prefix::milli>>));
implement_unit(si, si, hectogram_per_cubic_centimetre, dim::density_t, fix(impl::multiply_lists_t<prefix::mega, impl::multiply_lists_t<prefix::hecto, prefix::milli>>));
link_unit(kilogram_per_cubic_centimetre, gigagram_per_cubic_metre);
link_unit(megagram_per_cubic_centimetre, teragram_per_cubic_metre);
link_unit(tonne_per_cubic_centimetre, megagram_per_cubic_centimetre);
link_unit(gigagram_per_cubic_centimetre, petagram_per_cubic_metre);
link_unit(kilotonne_per_cubic_centimetre, gigagram_per_cubic_centimetre);
link_unit(teragram_per_cubic_centimetre, exagram_per_cubic_metre);
link_unit(megatonne_per_cubic_centimetre, teragram_per_cubic_centimetre);
link_unit(petagram_per_cubic_centimetre, zettagram_per_cubic_metre);
link_unit(gigatonne_per_cubic_centimetre, petagram_per_cubic_centimetre);
link_unit(exagram_per_cubic_centimetre, yottagram_per_cubic_metre);
link_unit(zettagram_per_cubic_centimetre, yottagram_per_cubic_decimetre);
implement_unit(si, si, yottagram_per_cubic_centimetre, dim::density_t, fix(impl::multiply_lists_t<prefix::mega, impl::multiply_lists_t<prefix::yotta, prefix::milli>>));
#pragma endregion
#pragma region kilogram per millilitre(density)
link_unit(yoctogram_per_millilitre, yoctogram_per_cubic_centimetre);
link_unit(zeptogram_per_millilitre, zeptogram_per_cubic_centimetre);
link_unit(attogram_per_millilitre, attogram_per_cubic_centimetre);
link_unit(femtogram_per_millilitre, femtogram_per_cubic_centimetre);
link_unit(picogram_per_millilitre, picogram_per_cubic_centimetre);
link_unit(nanogram_per_millilitre, nanogram_per_cubic_centimetre);
link_unit(microgram_per_millilitre, microgram_per_cubic_centimetre);
link_unit(milligram_per_millilitre, milligram_per_cubic_centimetre);
link_unit(centigram_per_millilitre, centigram_per_cubic_centimetre);
link_unit(decigram_per_millilitre, decigram_per_cubic_centimetre);
link_unit(gram_per_millilitre, gram_per_cubic_centimetre);
link_unit(decagram_per_millilitre, decagram_per_cubic_centimetre);
link_unit(hectogram_per_millilitre, hectogram_per_cubic_centimetre);
link_unit(kilogram_per_millilitre, kilogram_per_cubic_centimetre);
link_unit(megagram_per_millilitre, megagram_per_cubic_centimetre);
link_unit(tonne_per_millilitre, tonne_per_cubic_centimetre);
link_unit(gigagram_per_millilitre, gigagram_per_cubic_centimetre);
link_unit(kilotonne_per_millilitre, kilotonne_per_cubic_centimetre);
link_unit(teragram_per_millilitre, teragram_per_cubic_centimetre);
link_unit(megatonne_per_millilitre, megatonne_per_cubic_centimetre);
link_unit(petagram_per_millilitre, petagram_per_cubic_centimetre);
link_unit(gigatonne_per_millilitre, gigatonne_per_cubic_centimetre);
link_unit(exagram_per_millilitre, exagram_per_cubic_centimetre);
link_unit(zettagram_per_millilitre, zettagram_per_cubic_centimetre);
link_unit(yottagram_per_millilitre, yottagram_per_cubic_centimetre);
#pragma endregion
#pragma region kilogram per square metre(area density)
implement_unit(si, si, yoctogram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::yocto, prefix::milli>));
implement_unit(si, si, zeptogram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::zepto, prefix::milli>));
implement_unit(si, si, attogram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::atto, prefix::milli>));
implement_unit(si, si, femtogram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::femto, prefix::milli>));
implement_unit(si, si, picogram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::pico, prefix::milli>));
implement_unit(si, si, nanogram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::nano, prefix::milli>));
implement_unit(si, si, microgram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::micro, prefix::milli>));
implement_unit(si, si, milligram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::milli, prefix::milli>));
implement_unit(si, si, centigram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::centi, prefix::milli>));
implement_unit(si, si, decigram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::deci, prefix::milli>));
implement_unit(si, si, gram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::one, prefix::milli>));
implement_unit(si, si, decagram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::deca, prefix::milli>));
implement_unit(si, si, hectogram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::hecto, prefix::milli>));
implement_unit(si, si, kilogram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::kilo, prefix::milli>));
implement_unit(si, si, megagram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::mega, prefix::milli>));
link_unit(tonne_per_square_metre, megagram_per_square_metre);
implement_unit(si, si, gigagram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::giga, prefix::milli>));
link_unit(kilotonne_per_square_metre, gigagram_per_square_metre);
implement_unit(si, si, teragram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::tera, prefix::milli>));
link_unit(megatonne_per_square_metre, teragram_per_square_metre);
implement_unit(si, si, petagram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::peta, prefix::milli>));
link_unit(gigatonne_per_square_metre, petagram_per_square_metre);
implement_unit(si, si, exagram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::exa, prefix::milli>));
implement_unit(si, si, zettagram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::zetta, prefix::milli>));
implement_unit(si, si, yottagram_per_square_metre, dim::area_density_t, fix(impl::multiply_lists_t<prefix::yotta, prefix::milli>));
#pragma endregion
#pragma region cubic metre per kilogram(specific volume)
implement_unit(si, si, cubic_micrometre_per_kilogram, dim::specific_volume_t, prefix::atto);
implement_unit(si, si, cubic_millimetre_per_kilogram, dim::specific_volume_t, prefix::nano);
implement_unit(si, si, cubic_centimetre_per_kilogram, dim::specific_volume_t, prefix::micro);
link_unit(millilitre_per_kilogram, cubic_centimetre_per_kilogram);
implement_unit(si, si, cubic_decimetre_per_kilogram, dim::specific_volume_t, prefix::milli);
link_unit(litre_per_kilogram, cubic_decimetre_per_kilogram);
implement_unit(si, si, cubic_metre_per_kilogram, dim::specific_volume_t, prefix::one);
implement_unit(si, si, cubic_kilometre_per_kilogram, dim::specific_volume_t, prefix::giga);
#pragma endregion
#pragma region ampere per square metre(current density)
implement_unit(si, si, yoctoampere_per_square_metre, dim::current_density_t, prefix::yocto);
implement_unit(si, si, zeptoampere_per_square_metre, dim::current_density_t, prefix::zepto);
implement_unit(si, si, attoampere_per_square_metre, dim::current_density_t, prefix::atto);
implement_unit(si, si, femtoampere_per_square_metre, dim::current_density_t, prefix::femto);
implement_unit(si, si, picoampere_per_square_metre, dim::current_density_t, prefix::pico);
implement_unit(si, si, nanoampere_per_square_metre, dim::current_density_t, prefix::nano);
implement_unit(si, si, microampere_per_square_metre, dim::current_density_t, prefix::micro);
implement_unit(si, si, milliampere_per_square_metre, dim::current_density_t, prefix::milli);
implement_unit(si, si, centiampere_per_square_metre, dim::current_density_t, prefix::centi);
implement_unit(si, si, deciampere_per_square_metre, dim::current_density_t, prefix::deci);
implement_unit(si, si, ampere_per_square_metre, dim::current_density_t, prefix::one);
implement_unit(si, si, decaampere_per_square_metre, dim::current_density_t, prefix::deca);
implement_unit(si, si, hectoampere_per_square_metre, dim::current_density_t, prefix::hecto);
implement_unit(si, si, kiloampere_per_square_metre, dim::current_density_t, prefix::kilo);
implement_unit(si, si, megaampere_per_square_metre, dim::current_density_t, prefix::mega);
implement_unit(si, si, gigaampere_per_square_metre, dim::current_density_t, prefix::giga);
implement_unit(si, si, teraampere_per_square_metre, dim::current_density_t, prefix::tera);
implement_unit(si, si, petaampere_per_square_metre, dim::current_density_t, prefix::peta);
implement_unit(si, si, exaampere_per_square_metre, dim::current_density_t, prefix::exa);
implement_unit(si, si, zettaampere_per_square_metre, dim::current_density_t, prefix::zetta);
implement_unit(si, si, yottaampere_per_square_metre, dim::current_density_t, prefix::yotta);
#pragma endregion
#pragma region ampere per metre(magnetic field strength)
implement_unit(si, si, yoctoampere_per_metre, dim::magnetic_field_strength_t, prefix::yocto);
implement_unit(si, si, zeptoampere_per_metre, dim::magnetic_field_strength_t, prefix::zepto);
implement_unit(si, si, attoampere_per_metre, dim::magnetic_field_strength_t, prefix::atto);
implement_unit(si, si, femtoampere_per_metre, dim::magnetic_field_strength_t, prefix::femto);
implement_unit(si, si, picoampere_per_metre, dim::magnetic_field_strength_t, prefix::pico);
implement_unit(si, si, nanoampere_per_metre, dim::magnetic_field_strength_t, prefix::nano);
implement_unit(si, si, microampere_per_metre, dim::magnetic_field_strength_t, prefix::micro);
implement_unit(si, si, milliampere_per_metre, dim::magnetic_field_strength_t, prefix::milli);
implement_unit(si, si, centiampere_per_metre, dim::magnetic_field_strength_t, prefix::centi);
implement_unit(si, si, deciampere_per_metre, dim::magnetic_field_strength_t, prefix::deci);
implement_unit(si, si, ampere_per_metre, dim::magnetic_field_strength_t, prefix::one);
implement_unit(si, si, decaampere_per_metre, dim::magnetic_field_strength_t, prefix::deca);
implement_unit(si, si, hectoampere_per_metre, dim::magnetic_field_strength_t, prefix::hecto);
implement_unit(si, si, kiloampere_per_metre, dim::magnetic_field_strength_t, prefix::kilo);
implement_unit(si, si, megaampere_per_metre, dim::magnetic_field_strength_t, prefix::mega);
implement_unit(si, si, gigaampere_per_metre, dim::magnetic_field_strength_t, prefix::giga);
implement_unit(si, si, teraampere_per_metre, dim::magnetic_field_strength_t, prefix::tera);
implement_unit(si, si, petaampere_per_metre, dim::magnetic_field_strength_t, prefix::peta);
implement_unit(si, si, exaampere_per_metre, dim::magnetic_field_strength_t, prefix::exa);
implement_unit(si, si, zettaampere_per_metre, dim::magnetic_field_strength_t, prefix::zetta);
implement_unit(si, si, yottaampere_per_metre, dim::magnetic_field_strength_t, prefix::yotta);
#pragma endregion
#pragma region mole per cubic metre(concentration)
implement_unit(si, si, mole_per_cubic_micrometre, dim::concentration_t, fix(impl::divide_lists_t<prefix::one, prefix::atto>));
implement_unit(si, si, mole_per_cubic_millimetre, dim::concentration_t, fix(impl::divide_lists_t<prefix::one, prefix::nano>));
implement_unit(si, si, mole_per_cubic_centimetre, dim::concentration_t, fix(impl::divide_lists_t<prefix::one, prefix::micro>));
link_unit(mole_per_millilitre, mole_per_cubic_centimetre);
implement_unit(si, si, mole_per_cubic_decimetre, dim::concentration_t, fix(impl::divide_lists_t<prefix::one, prefix::milli>));
link_unit(mole_per_litre, mole_per_cubic_decimetre);
implement_unit(si, si, mole_per_cubic_metre, dim::concentration_t, fix(impl::divide_lists_t<prefix::one, prefix::one>));
implement_unit(si, si, mole_per_cubic_kilometre, dim::concentration_t, fix(impl::divide_lists_t<prefix::one, prefix::giga>));
#pragma endregion
#pragma region candela per square metre(luminance)
implement_unit(si, si, yoctocandela_per_square_metre, dim::luminance_t, prefix::yocto);
implement_unit(si, si, zeptocandela_per_square_metre, dim::luminance_t, prefix::zepto);
implement_unit(si, si, attocandela_per_square_metre, dim::luminance_t, prefix::atto);
implement_unit(si, si, femtocandela_per_square_metre, dim::luminance_t, prefix::femto);
implement_unit(si, si, picocandela_per_square_metre, dim::luminance_t, prefix::pico);
implement_unit(si, si, nanocandela_per_square_metre, dim::luminance_t, prefix::nano);
implement_unit(si, si, microcandela_per_square_metre, dim::luminance_t, prefix::micro);
implement_unit(si, si, millicandela_per_square_metre, dim::luminance_t, prefix::milli);
implement_unit(si, si, centicandela_per_square_metre, dim::luminance_t, prefix::centi);
implement_unit(si, si, decicandela_per_square_metre, dim::luminance_t, prefix::deci);
implement_unit(si, si, candela_per_square_metre, dim::luminance_t, prefix::one);
implement_unit(si, si, decacandela_per_square_metre, dim::luminance_t, prefix::deca);
implement_unit(si, si, hectocandela_per_square_metre, dim::luminance_t, prefix::hecto);
implement_unit(si, si, kilocandela_per_square_metre, dim::luminance_t, prefix::kilo);
implement_unit(si, si, megacandela_per_square_metre, dim::luminance_t, prefix::mega);
implement_unit(si, si, gigacandela_per_square_metre, dim::luminance_t, prefix::giga);
implement_unit(si, si, teracandela_per_square_metre, dim::luminance_t, prefix::tera);
implement_unit(si, si, petacandela_per_square_metre, dim::luminance_t, prefix::peta);
implement_unit(si, si, exacandela_per_square_metre, dim::luminance_t, prefix::exa);
implement_unit(si, si, zettacandela_per_square_metre, dim::luminance_t, prefix::zetta);
implement_unit(si, si, yottacandela_per_square_metre, dim::luminance_t, prefix::yotta);
#pragma endregion
#pragma region plane angle
implement_unit(si, si, gon, dim::plane_angle_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 200>>));
implement_unit(si, si, revolution, dim::plane_angle_t, prefix::two_pi_t);
#pragma endregion
#pragma region solid angle
implement_unit(si, si, steradian, dim::solid_angle_t, prefix::one);
#pragma endregion
#pragma region hertz(frequency)
implement_unit(si, si, yoctohertz, dim::frequency_t, prefix::yocto);
implement_unit(si, si, zeptohertz, dim::frequency_t, prefix::zepto);
implement_unit(si, si, attohertz, dim::frequency_t, prefix::atto);
implement_unit(si, si, femtohertz, dim::frequency_t, prefix::femto);
implement_unit(si, si, picohertz, dim::frequency_t, prefix::pico);
implement_unit(si, si, nanohertz, dim::frequency_t, prefix::nano);
implement_unit(si, si, microhertz, dim::frequency_t, prefix::micro);
implement_unit(si, si, millihertz, dim::frequency_t, prefix::milli);
implement_unit(si, si, centihertz, dim::frequency_t, prefix::centi);
implement_unit(si, si, decihertz, dim::frequency_t, prefix::deci);
implement_unit(si, si, hertz, dim::frequency_t, prefix::one);
implement_unit(si, si, decahertz, dim::frequency_t, prefix::deca);
implement_unit(si, si, hectohertz, dim::frequency_t, prefix::hecto);
implement_unit(si, si, kilohertz, dim::frequency_t, prefix::kilo);
implement_unit(si, si, megahertz, dim::frequency_t, prefix::mega);
implement_unit(si, si, gigahertz, dim::frequency_t, prefix::giga);
implement_unit(si, si, terahertz, dim::frequency_t, prefix::tera);
implement_unit(si, si, petahertz, dim::frequency_t, prefix::peta);
implement_unit(si, si, exahertz, dim::frequency_t, prefix::exa);
implement_unit(si, si, zettahertz, dim::frequency_t, prefix::zetta);
implement_unit(si, si, yottahertz, dim::frequency_t, prefix::yotta);
#pragma endregion
#pragma region newton(force)
implement_unit(si, si, yoctonewton, dim::force_t, prefix::yocto);
implement_unit(si, si, zeptonewton, dim::force_t, prefix::zepto);
implement_unit(si, si, attonewton, dim::force_t, prefix::atto);
implement_unit(si, si, femtonewton, dim::force_t, prefix::femto);
implement_unit(si, si, piconewton, dim::force_t, prefix::pico);
implement_unit(si, si, nanonewton, dim::force_t, prefix::nano);
implement_unit(si, si, micronewton, dim::force_t, prefix::micro);
implement_unit(si, si, millinewton, dim::force_t, prefix::milli);
implement_unit(si, si, centinewton, dim::force_t, prefix::centi);
implement_unit(si, si, decinewton, dim::force_t, prefix::deci);
implement_unit(si, si, newton, dim::force_t, prefix::one);
implement_unit(si, si, decanewton, dim::force_t, prefix::deca);
implement_unit(si, si, hectonewton, dim::force_t, prefix::hecto);
implement_unit(si, si, kilonewton, dim::force_t, prefix::kilo);
implement_unit(si, si, meganewton, dim::force_t, prefix::mega);
implement_unit(si, si, giganewton, dim::force_t, prefix::giga);
implement_unit(si, si, teranewton, dim::force_t, prefix::tera);
implement_unit(si, si, petanewton, dim::force_t, prefix::peta);
implement_unit(si, si, exanewton, dim::force_t, prefix::exa);
implement_unit(si, si, zettanewton, dim::force_t, prefix::zetta);
implement_unit(si, si, yottanewton, dim::force_t, prefix::yotta);
#pragma endregion
#pragma region pascal(pressure)
implement_unit(si, si, yoctopascal, dim::pressure_t, prefix::yocto);
implement_unit(si, si, zeptopascal, dim::pressure_t, prefix::zepto);
implement_unit(si, si, attopascal, dim::pressure_t, prefix::atto);
implement_unit(si, si, femtopascal, dim::pressure_t, prefix::femto);
implement_unit(si, si, picopascal, dim::pressure_t, prefix::pico);
implement_unit(si, si, nanopascal, dim::pressure_t, prefix::nano);
implement_unit(si, si, micropascal, dim::pressure_t, prefix::micro);
implement_unit(si, si, millipascal, dim::pressure_t, prefix::milli);
implement_unit(si, si, centipascal, dim::pressure_t, prefix::centi);
implement_unit(si, si, decipascal, dim::pressure_t, prefix::deci);
implement_unit(si, si, pascal, dim::pressure_t, prefix::one);
implement_unit(si, si, decapascal, dim::pressure_t, prefix::deca);
implement_unit(si, si, hectopascal, dim::pressure_t, prefix::hecto);
implement_unit(si, si, kilopascal, dim::pressure_t, prefix::kilo);
implement_unit(si, si, megapascal, dim::pressure_t, prefix::mega);
implement_unit(si, si, gigapascal, dim::pressure_t, prefix::giga);
implement_unit(si, si, terapascal, dim::pressure_t, prefix::tera);
implement_unit(si, si, petapascal, dim::pressure_t, prefix::peta);
implement_unit(si, si, exapascal, dim::pressure_t, prefix::exa);
implement_unit(si, si, zettapascal, dim::pressure_t, prefix::zetta);
implement_unit(si, si, yottapascal, dim::pressure_t, prefix::yotta);
#pragma endregion
#pragma region bar, mmHg, ...(pressure)
implement_unit(si, si, yoctobar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::yocto, make_power_list_t<5>>));
implement_unit(si, si, zeptobar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::zepto, make_power_list_t<5>>));
implement_unit(si, si, attobar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::atto, make_power_list_t<5>>));
implement_unit(si, si, femtobar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::femto, make_power_list_t<5>>));
implement_unit(si, si, picobar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::pico, make_power_list_t<5>>));
implement_unit(si, si, nanobar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::nano, make_power_list_t<5>>));
link_unit(microbar, decipascal);
link_unit(millibar, hectopascal);
link_unit(centibar, kilopascal);
implement_unit(si, si, decibar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::deci, make_power_list_t<5>>));
implement_unit(si, si, bar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::one, make_power_list_t<5>>));
link_unit(decabar, megapascal);
implement_unit(si, si, hectobar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::hecto, make_power_list_t<5>>));
implement_unit(si, si, kilobar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::kilo, make_power_list_t<5>>));
implement_unit(si, si, megabar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::mega, make_power_list_t<5>>));
implement_unit(si, si, gigabar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::giga, make_power_list_t<5>>));
implement_unit(si, si, terabar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::tera, make_power_list_t<5>>));
implement_unit(si, si, petabar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::peta, make_power_list_t<5>>));
implement_unit(si, si, exabar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::exa, make_power_list_t<5>>));
implement_unit(si, si, zettabar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::zetta, make_power_list_t<5>>));
implement_unit(si, si, yottabar, dim::pressure_t, fix(impl::multiply_lists_t<prefix::yotta, make_power_list_t<5>>));

implement_unit(si, si, millimeter_of_mercury, dim::pressure_t, fix(make_fraction_list_t<133322,1000>));
implement_unit(si, si, atmosphere, dim::pressure_t, make_fraction_list_t<101325>);
implement_unit(si, si, torr, dim::pressure_t, fix(make_fraction_list_t<101325,760>));
#pragma endregion
#pragma region joule(energy)
implement_unit(si, si, yoctojoule, dim::energy_t, prefix::yocto);
implement_unit(si, si, zeptojoule, dim::energy_t, prefix::zepto);
implement_unit(si, si, attojoule, dim::energy_t, prefix::atto);
implement_unit(si, si, femtojoule, dim::energy_t, prefix::femto);
implement_unit(si, si, picojoule, dim::energy_t, prefix::pico);
implement_unit(si, si, nanojoule, dim::energy_t, prefix::nano);
implement_unit(si, si, microjoule, dim::energy_t, prefix::micro);
implement_unit(si, si, millijoule, dim::energy_t, prefix::milli);
implement_unit(si, si, centijoule, dim::energy_t, prefix::centi);
implement_unit(si, si, decijoule, dim::energy_t, prefix::deci);
implement_unit(si, si, joule, dim::energy_t, prefix::one);
implement_unit(si, si, decajoule, dim::energy_t, prefix::deca);
implement_unit(si, si, hectojoule, dim::energy_t, prefix::hecto);
implement_unit(si, si, kilojoule, dim::energy_t, prefix::kilo);
implement_unit(si, si, megajoule, dim::energy_t, prefix::mega);
implement_unit(si, si, gigajoule, dim::energy_t, prefix::giga);
implement_unit(si, si, terajoule, dim::energy_t, prefix::tera);
implement_unit(si, si, petajoule, dim::energy_t, prefix::peta);
implement_unit(si, si, exajoule, dim::energy_t, prefix::exa);
implement_unit(si, si, zettajoule, dim::energy_t, prefix::zetta);
implement_unit(si, si, yottajoule, dim::energy_t, prefix::yotta);
#pragma endregion
#pragma region electron volt, hartree(energy)
implement_unit(si, si, yoctoelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::yocto,prefix::elementary_charge_t>));
implement_unit(si, si, zeptoelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::zepto,prefix::elementary_charge_t>));
implement_unit(si, si, attoelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::atto,prefix::elementary_charge_t>));
implement_unit(si, si, femtoelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::femto,prefix::elementary_charge_t>));
implement_unit(si, si, picoelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::pico,prefix::elementary_charge_t>));
implement_unit(si, si, nanoelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::nano,prefix::elementary_charge_t>));
implement_unit(si, si, microelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::micro,prefix::elementary_charge_t>));
implement_unit(si, si, millielectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::milli,prefix::elementary_charge_t>));
implement_unit(si, si, centielectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::centi,prefix::elementary_charge_t>));
implement_unit(si, si, decielectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::deci,prefix::elementary_charge_t>));
implement_unit(si, si, electron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::one,prefix::elementary_charge_t>));
implement_unit(si, si, decaelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::deca,prefix::elementary_charge_t>));
implement_unit(si, si, hectoelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::hecto,prefix::elementary_charge_t>));
implement_unit(si, si, kiloelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::kilo,prefix::elementary_charge_t>));
implement_unit(si, si, megaelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::mega,prefix::elementary_charge_t>));
implement_unit(si, si, gigaelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::giga,prefix::elementary_charge_t>));
implement_unit(si, si, teraelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::tera,prefix::elementary_charge_t>));
implement_unit(si, si, petaelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::peta,prefix::elementary_charge_t>));
implement_unit(si, si, exaelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::exa,prefix::elementary_charge_t>));
implement_unit(si, si, zettaelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::zetta,prefix::elementary_charge_t>));
implement_unit(si, si, yottaelectron_volt, dim::energy_t, fix(impl::multiply_lists_t<prefix::yotta,prefix::elementary_charge_t>));

implement_unit(si, si, yoctohartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::yocto,prefix::hartree_energy_t>));
implement_unit(si, si, zeptohartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::zepto,prefix::hartree_energy_t>));
implement_unit(si, si, attohartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::atto,prefix::hartree_energy_t>));
implement_unit(si, si, femtohartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::femto,prefix::hartree_energy_t>));
implement_unit(si, si, picohartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::pico,prefix::hartree_energy_t>));
implement_unit(si, si, nanohartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::nano,prefix::hartree_energy_t>));
implement_unit(si, si, microhartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::micro,prefix::hartree_energy_t>));
implement_unit(si, si, millihartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::milli,prefix::hartree_energy_t>));
implement_unit(si, si, centihartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::centi,prefix::hartree_energy_t>));
implement_unit(si, si, decihartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::deci,prefix::hartree_energy_t>));
implement_unit(si, si, hartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::one,prefix::hartree_energy_t>));
implement_unit(si, si, decahartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::deca,prefix::hartree_energy_t>));
implement_unit(si, si, hectohartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::hecto,prefix::hartree_energy_t>));
implement_unit(si, si, kilohartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::kilo,prefix::hartree_energy_t>));
implement_unit(si, si, megahartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::mega,prefix::hartree_energy_t>));
implement_unit(si, si, gigahartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::giga,prefix::hartree_energy_t>));
implement_unit(si, si, terahartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::tera,prefix::hartree_energy_t>));
implement_unit(si, si, petahartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::peta,prefix::hartree_energy_t>));
implement_unit(si, si, exahartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::exa,prefix::hartree_energy_t>));
implement_unit(si, si, zettahartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::zetta,prefix::hartree_energy_t>));
implement_unit(si, si, yottahartree, dim::energy_t, fix(impl::multiply_lists_t<prefix::yotta,prefix::hartree_energy_t>));
#pragma endregion
#pragma region watt minute(energy)
implement_unit(si, si, yoctowatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yocto>));
implement_unit(si, si, zeptowatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zepto>));
implement_unit(si, si, attowatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::atto>));
implement_unit(si, si, femtowatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::femto>));
implement_unit(si, si, picowatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::pico>));
implement_unit(si, si, nanowatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::nano>));
implement_unit(si, si, microwatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::micro>));
implement_unit(si, si, milliwatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::milli>));
implement_unit(si, si, centiwatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::centi>));
implement_unit(si, si, deciwatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deci>));
implement_unit(si, si, watt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::one>));
implement_unit(si, si, decawatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deca>));
implement_unit(si, si, hectowatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::hecto>));
implement_unit(si, si, kilowatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::kilo>));
implement_unit(si, si, megawatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::mega>));
implement_unit(si, si, gigawatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::giga>));
implement_unit(si, si, terawatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::tera>));
implement_unit(si, si, petawatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::peta>));
implement_unit(si, si, exawatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::exa>));
implement_unit(si, si, zettawatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zetta>));
implement_unit(si, si, yottawatt_minute, dim::energy_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yotta>));
#pragma endregion
#pragma region watt hour(energy)
implement_unit(si, si, yoctowatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yocto>));
implement_unit(si, si, zeptowatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zepto>));
implement_unit(si, si, attowatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::atto>));
implement_unit(si, si, femtowatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::femto>));
implement_unit(si, si, picowatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::pico>));
implement_unit(si, si, nanowatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::nano>));
implement_unit(si, si, microwatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::micro>));
implement_unit(si, si, milliwatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::milli>));
implement_unit(si, si, centiwatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::centi>));
implement_unit(si, si, deciwatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deci>));
implement_unit(si, si, watt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::one>));
implement_unit(si, si, decawatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deca>));
implement_unit(si, si, hectowatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::hecto>));
implement_unit(si, si, kilowatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::kilo>));
implement_unit(si, si, megawatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::mega>));
implement_unit(si, si, gigawatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::giga>));
implement_unit(si, si, terawatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::tera>));
implement_unit(si, si, petawatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::peta>));
implement_unit(si, si, exawatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::exa>));
implement_unit(si, si, zettawatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zetta>));
implement_unit(si, si, yottawatt_hour, dim::energy_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yotta>));
#pragma endregion
#pragma region watt(power)
implement_unit(si, si, yoctowatt, dim::power_t, prefix::yocto);
implement_unit(si, si, zeptowatt, dim::power_t, prefix::zepto);
implement_unit(si, si, attowatt, dim::power_t, prefix::atto);
implement_unit(si, si, femtowatt, dim::power_t, prefix::femto);
implement_unit(si, si, picowatt, dim::power_t, prefix::pico);
implement_unit(si, si, nanowatt, dim::power_t, prefix::nano);
implement_unit(si, si, microwatt, dim::power_t, prefix::micro);
implement_unit(si, si, milliwatt, dim::power_t, prefix::milli);
implement_unit(si, si, centiwatt, dim::power_t, prefix::centi);
implement_unit(si, si, deciwatt, dim::power_t, prefix::deci);
implement_unit(si, si, watt, dim::power_t, prefix::one);
implement_unit(si, si, decawatt, dim::power_t, prefix::deca);
implement_unit(si, si, hectowatt, dim::power_t, prefix::hecto);
implement_unit(si, si, kilowatt, dim::power_t, prefix::kilo);
implement_unit(si, si, megawatt, dim::power_t, prefix::mega);
implement_unit(si, si, gigawatt, dim::power_t, prefix::giga);
implement_unit(si, si, terawatt, dim::power_t, prefix::tera);
implement_unit(si, si, petawatt, dim::power_t, prefix::peta);
implement_unit(si, si, exawatt, dim::power_t, prefix::exa);
implement_unit(si, si, zettawatt, dim::power_t, prefix::zetta);
implement_unit(si, si, yottawatt, dim::power_t, prefix::yotta);
#pragma endregion
#pragma region coulomb(electric charge)
implement_unit(si, si, yoctocoulomb, dim::electric_charge_t, prefix::yocto);
implement_unit(si, si, zeptocoulomb, dim::electric_charge_t, prefix::zepto);
implement_unit(si, si, attocoulomb, dim::electric_charge_t, prefix::atto);
implement_unit(si, si, femtocoulomb, dim::electric_charge_t, prefix::femto);
implement_unit(si, si, picocoulomb, dim::electric_charge_t, prefix::pico);
implement_unit(si, si, nanocoulomb, dim::electric_charge_t, prefix::nano);
implement_unit(si, si, microcoulomb, dim::electric_charge_t, prefix::micro);
implement_unit(si, si, millicoulomb, dim::electric_charge_t, prefix::milli);
implement_unit(si, si, centicoulomb, dim::electric_charge_t, prefix::centi);
implement_unit(si, si, decicoulomb, dim::electric_charge_t, prefix::deci);
implement_unit(si, si, coulomb, dim::electric_charge_t, prefix::one);
implement_unit(si, si, decacoulomb, dim::electric_charge_t, prefix::deca);
implement_unit(si, si, hectocoulomb, dim::electric_charge_t, prefix::hecto);
implement_unit(si, si, kilocoulomb, dim::electric_charge_t, prefix::kilo);
implement_unit(si, si, megacoulomb, dim::electric_charge_t, prefix::mega);
implement_unit(si, si, gigacoulomb, dim::electric_charge_t, prefix::giga);
implement_unit(si, si, teracoulomb, dim::electric_charge_t, prefix::tera);
implement_unit(si, si, petacoulomb, dim::electric_charge_t, prefix::peta);
implement_unit(si, si, exacoulomb, dim::electric_charge_t, prefix::exa);
implement_unit(si, si, zettacoulomb, dim::electric_charge_t, prefix::zetta);
implement_unit(si, si, yottacoulomb, dim::electric_charge_t, prefix::yotta);
#pragma endregion
#pragma region ampere minute(electric charge)
implement_unit(si, si, yoctoampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yocto>));
implement_unit(si, si, zeptoampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zepto>));
implement_unit(si, si, attoampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::atto>));
implement_unit(si, si, femtoampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::femto>));
implement_unit(si, si, picoampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::pico>));
implement_unit(si, si, nanoampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::nano>));
implement_unit(si, si, microampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::micro>));
implement_unit(si, si, milliampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::milli>));
implement_unit(si, si, centiampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::centi>));
implement_unit(si, si, deciampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deci>));
implement_unit(si, si, ampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::one>));
implement_unit(si, si, decaampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deca>));
implement_unit(si, si, hectoampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::hecto>));
implement_unit(si, si, kiloampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::kilo>));
implement_unit(si, si, megaampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::mega>));
implement_unit(si, si, gigaampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::giga>));
implement_unit(si, si, teraampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::tera>));
implement_unit(si, si, petaampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::peta>));
implement_unit(si, si, exaampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::exa>));
implement_unit(si, si, zettaampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zetta>));
implement_unit(si, si, yottaampere_minute, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yotta>));
#pragma endregion
#pragma region ampere hour(electric charge)
implement_unit(si, si, yoctoampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yocto>));
implement_unit(si, si, zeptoampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zepto>));
implement_unit(si, si, attoampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::atto>));
implement_unit(si, si, femtoampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::femto>));
implement_unit(si, si, picoampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::pico>));
implement_unit(si, si, nanoampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::nano>));
implement_unit(si, si, microampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::micro>));
implement_unit(si, si, milliampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::milli>));
implement_unit(si, si, centiampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::centi>));
implement_unit(si, si, deciampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deci>));
implement_unit(si, si, ampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::one>));
implement_unit(si, si, decaampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deca>));
implement_unit(si, si, hectoampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::hecto>));
implement_unit(si, si, kiloampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::kilo>));
implement_unit(si, si, megaampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::mega>));
implement_unit(si, si, gigaampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::giga>));
implement_unit(si, si, teraampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::tera>));
implement_unit(si, si, petaampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::peta>));
implement_unit(si, si, exaampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::exa>));
implement_unit(si, si, zettaampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zetta>));
implement_unit(si, si, yottaampere_hour, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yotta>));
#pragma endregion
#pragma region electron/elementary charge(electric charge)
implement_unit(si, si, yoctoelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::yocto,prefix::elementary_charge_t>));
implement_unit(si, si, zeptoelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::zepto,prefix::elementary_charge_t>));
implement_unit(si, si, attoelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::atto,prefix::elementary_charge_t>));
implement_unit(si, si, femtoelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::femto,prefix::elementary_charge_t>));
implement_unit(si, si, picoelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::pico,prefix::elementary_charge_t>));
implement_unit(si, si, nanoelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::nano,prefix::elementary_charge_t>));
implement_unit(si, si, microelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::micro,prefix::elementary_charge_t>));
implement_unit(si, si, millielectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::milli,prefix::elementary_charge_t>));
implement_unit(si, si, centielectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::centi,prefix::elementary_charge_t>));
implement_unit(si, si, decielectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::deci,prefix::elementary_charge_t>));
implement_unit(si, si, electron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::one,prefix::elementary_charge_t>));
implement_unit(si, si, decaelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::deca,prefix::elementary_charge_t>));
implement_unit(si, si, hectoelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::hecto,prefix::elementary_charge_t>));
implement_unit(si, si, kiloelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::kilo,prefix::elementary_charge_t>));
implement_unit(si, si, megaelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::mega,prefix::elementary_charge_t>));
implement_unit(si, si, gigaelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::giga,prefix::elementary_charge_t>));
implement_unit(si, si, teraelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::tera,prefix::elementary_charge_t>));
implement_unit(si, si, petaelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::peta,prefix::elementary_charge_t>));
implement_unit(si, si, exaelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::exa,prefix::elementary_charge_t>));
implement_unit(si, si, zettaelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::zetta,prefix::elementary_charge_t>));
implement_unit(si, si, yottaelectron, dim::electric_charge_t, fix(impl::multiply_lists_t<prefix::yotta,prefix::elementary_charge_t>));
#pragma endregion
#pragma region volt(electric potential)
implement_unit(si, si, yoctovolt, dim::electric_potential_t, prefix::yocto);
implement_unit(si, si, zeptovolt, dim::electric_potential_t, prefix::zepto);
implement_unit(si, si, attovolt, dim::electric_potential_t, prefix::atto);
implement_unit(si, si, femtovolt, dim::electric_potential_t, prefix::femto);
implement_unit(si, si, picovolt, dim::electric_potential_t, prefix::pico);
implement_unit(si, si, nanovolt, dim::electric_potential_t, prefix::nano);
implement_unit(si, si, microvolt, dim::electric_potential_t, prefix::micro);
implement_unit(si, si, millivolt, dim::electric_potential_t, prefix::milli);
implement_unit(si, si, centivolt, dim::electric_potential_t, prefix::centi);
implement_unit(si, si, decivolt, dim::electric_potential_t, prefix::deci);
implement_unit(si, si, volt, dim::electric_potential_t, prefix::one);
implement_unit(si, si, decavolt, dim::electric_potential_t, prefix::deca);
implement_unit(si, si, hectovolt, dim::electric_potential_t, prefix::hecto);
implement_unit(si, si, kilovolt, dim::electric_potential_t, prefix::kilo);
implement_unit(si, si, megavolt, dim::electric_potential_t, prefix::mega);
implement_unit(si, si, gigavolt, dim::electric_potential_t, prefix::giga);
implement_unit(si, si, teravolt, dim::electric_potential_t, prefix::tera);
implement_unit(si, si, petavolt, dim::electric_potential_t, prefix::peta);
implement_unit(si, si, exavolt, dim::electric_potential_t, prefix::exa);
implement_unit(si, si, zettavolt, dim::electric_potential_t, prefix::zetta);
implement_unit(si, si, yottavolt, dim::electric_potential_t, prefix::yotta);
#pragma endregion
#pragma region farad(capacitance)
implement_unit(si, si, yoctofarad, dim::capacitance_t, prefix::yocto);
implement_unit(si, si, zeptofarad, dim::capacitance_t, prefix::zepto);
implement_unit(si, si, attofarad, dim::capacitance_t, prefix::atto);
implement_unit(si, si, femtofarad, dim::capacitance_t, prefix::femto);
implement_unit(si, si, picofarad, dim::capacitance_t, prefix::pico);
implement_unit(si, si, nanofarad, dim::capacitance_t, prefix::nano);
implement_unit(si, si, microfarad, dim::capacitance_t, prefix::micro);
implement_unit(si, si, millifarad, dim::capacitance_t, prefix::milli);
implement_unit(si, si, centifarad, dim::capacitance_t, prefix::centi);
implement_unit(si, si, decifarad, dim::capacitance_t, prefix::deci);
implement_unit(si, si, farad, dim::capacitance_t, prefix::one);
implement_unit(si, si, decafarad, dim::capacitance_t, prefix::deca);
implement_unit(si, si, hectofarad, dim::capacitance_t, prefix::hecto);
implement_unit(si, si, kilofarad, dim::capacitance_t, prefix::kilo);
implement_unit(si, si, megafarad, dim::capacitance_t, prefix::mega);
implement_unit(si, si, gigafarad, dim::capacitance_t, prefix::giga);
implement_unit(si, si, terafarad, dim::capacitance_t, prefix::tera);
implement_unit(si, si, petafarad, dim::capacitance_t, prefix::peta);
implement_unit(si, si, exafarad, dim::capacitance_t, prefix::exa);
implement_unit(si, si, zettafarad, dim::capacitance_t, prefix::zetta);
implement_unit(si, si, yottafarad, dim::capacitance_t, prefix::yotta);
#pragma endregion
#pragma region ohm(electric resistance)
implement_unit(si, si, yoctoohm, dim::electric_resistance_t, prefix::yocto);
implement_unit(si, si, zeptoohm, dim::electric_resistance_t, prefix::zepto);
implement_unit(si, si, attoohm, dim::electric_resistance_t, prefix::atto);
implement_unit(si, si, femtoohm, dim::electric_resistance_t, prefix::femto);
implement_unit(si, si, picoohm, dim::electric_resistance_t, prefix::pico);
implement_unit(si, si, nanoohm, dim::electric_resistance_t, prefix::nano);
implement_unit(si, si, microohm, dim::electric_resistance_t, prefix::micro);
implement_unit(si, si, milliohm, dim::electric_resistance_t, prefix::milli);
implement_unit(si, si, centiohm, dim::electric_resistance_t, prefix::centi);
implement_unit(si, si, deciohm, dim::electric_resistance_t, prefix::deci);
implement_unit(si, si, ohm, dim::electric_resistance_t, prefix::one);
implement_unit(si, si, decaohm, dim::electric_resistance_t, prefix::deca);
implement_unit(si, si, hectoohm, dim::electric_resistance_t, prefix::hecto);
implement_unit(si, si, kiloohm, dim::electric_resistance_t, prefix::kilo);
implement_unit(si, si, megaohm, dim::electric_resistance_t, prefix::mega);
implement_unit(si, si, gigaohm, dim::electric_resistance_t, prefix::giga);
implement_unit(si, si, teraohm, dim::electric_resistance_t, prefix::tera);
implement_unit(si, si, petaohm, dim::electric_resistance_t, prefix::peta);
implement_unit(si, si, exaohm, dim::electric_resistance_t, prefix::exa);
implement_unit(si, si, zettaohm, dim::electric_resistance_t, prefix::zetta);
implement_unit(si, si, yottaohm, dim::electric_resistance_t, prefix::yotta);
#pragma endregion
#pragma region siemens(electric conductance)
implement_unit(si, si, yoctosiemens, dim::electric_conductance_t, prefix::yocto);
implement_unit(si, si, zeptosiemens, dim::electric_conductance_t, prefix::zepto);
implement_unit(si, si, attosiemens, dim::electric_conductance_t, prefix::atto);
implement_unit(si, si, femtosiemens, dim::electric_conductance_t, prefix::femto);
implement_unit(si, si, picosiemens, dim::electric_conductance_t, prefix::pico);
implement_unit(si, si, nanosiemens, dim::electric_conductance_t, prefix::nano);
implement_unit(si, si, microsiemens, dim::electric_conductance_t, prefix::micro);
implement_unit(si, si, millisiemens, dim::electric_conductance_t, prefix::milli);
implement_unit(si, si, centisiemens, dim::electric_conductance_t, prefix::centi);
implement_unit(si, si, decisiemens, dim::electric_conductance_t, prefix::deci);
implement_unit(si, si, siemens, dim::electric_conductance_t, prefix::one);
implement_unit(si, si, decasiemens, dim::electric_conductance_t, prefix::deca);
implement_unit(si, si, hectosiemens, dim::electric_conductance_t, prefix::hecto);
implement_unit(si, si, kilosiemens, dim::electric_conductance_t, prefix::kilo);
implement_unit(si, si, megasiemens, dim::electric_conductance_t, prefix::mega);
implement_unit(si, si, gigasiemens, dim::electric_conductance_t, prefix::giga);
implement_unit(si, si, terasiemens, dim::electric_conductance_t, prefix::tera);
implement_unit(si, si, petasiemens, dim::electric_conductance_t, prefix::peta);
implement_unit(si, si, exasiemens, dim::electric_conductance_t, prefix::exa);
implement_unit(si, si, zettasiemens, dim::electric_conductance_t, prefix::zetta);
implement_unit(si, si, yottasiemens, dim::electric_conductance_t, prefix::yotta);
#pragma endregion
#pragma region weber(magnetic flux)
implement_unit(si, si, yoctoweber, dim::magnetic_flux_t, prefix::yocto);
implement_unit(si, si, zeptoweber, dim::magnetic_flux_t, prefix::zepto);
implement_unit(si, si, attoweber, dim::magnetic_flux_t, prefix::atto);
implement_unit(si, si, femtoweber, dim::magnetic_flux_t, prefix::femto);
implement_unit(si, si, picoweber, dim::magnetic_flux_t, prefix::pico);
implement_unit(si, si, nanoweber, dim::magnetic_flux_t, prefix::nano);
implement_unit(si, si, microweber, dim::magnetic_flux_t, prefix::micro);
implement_unit(si, si, milliweber, dim::magnetic_flux_t, prefix::milli);
implement_unit(si, si, centiweber, dim::magnetic_flux_t, prefix::centi);
implement_unit(si, si, deciweber, dim::magnetic_flux_t, prefix::deci);
implement_unit(si, si, weber, dim::magnetic_flux_t, prefix::one);
implement_unit(si, si, decaweber, dim::magnetic_flux_t, prefix::deca);
implement_unit(si, si, hectoweber, dim::magnetic_flux_t, prefix::hecto);
implement_unit(si, si, kiloweber, dim::magnetic_flux_t, prefix::kilo);
implement_unit(si, si, megaweber, dim::magnetic_flux_t, prefix::mega);
implement_unit(si, si, gigaweber, dim::magnetic_flux_t, prefix::giga);
implement_unit(si, si, teraweber, dim::magnetic_flux_t, prefix::tera);
implement_unit(si, si, petaweber, dim::magnetic_flux_t, prefix::peta);
implement_unit(si, si, exaweber, dim::magnetic_flux_t, prefix::exa);
implement_unit(si, si, zettaweber, dim::magnetic_flux_t, prefix::zetta);
implement_unit(si, si, yottaweber, dim::magnetic_flux_t, prefix::yotta);
#pragma endregion
#pragma region tesla(magnetic flux density)
implement_unit(si, si, yoctotesla, dim::magnetic_flux_density_t, prefix::yocto);
implement_unit(si, si, zeptotesla, dim::magnetic_flux_density_t, prefix::zepto);
implement_unit(si, si, attotesla, dim::magnetic_flux_density_t, prefix::atto);
implement_unit(si, si, femtotesla, dim::magnetic_flux_density_t, prefix::femto);
implement_unit(si, si, picotesla, dim::magnetic_flux_density_t, prefix::pico);
implement_unit(si, si, nanotesla, dim::magnetic_flux_density_t, prefix::nano);
implement_unit(si, si, microtesla, dim::magnetic_flux_density_t, prefix::micro);
implement_unit(si, si, millitesla, dim::magnetic_flux_density_t, prefix::milli);
implement_unit(si, si, centitesla, dim::magnetic_flux_density_t, prefix::centi);
implement_unit(si, si, decitesla, dim::magnetic_flux_density_t, prefix::deci);
implement_unit(si, si, tesla, dim::magnetic_flux_density_t, prefix::one);
implement_unit(si, si, decatesla, dim::magnetic_flux_density_t, prefix::deca);
implement_unit(si, si, hectotesla, dim::magnetic_flux_density_t, prefix::hecto);
implement_unit(si, si, kilotesla, dim::magnetic_flux_density_t, prefix::kilo);
implement_unit(si, si, megatesla, dim::magnetic_flux_density_t, prefix::mega);
implement_unit(si, si, gigatesla, dim::magnetic_flux_density_t, prefix::giga);
implement_unit(si, si, teratesla, dim::magnetic_flux_density_t, prefix::tera);
implement_unit(si, si, petatesla, dim::magnetic_flux_density_t, prefix::peta);
implement_unit(si, si, exatesla, dim::magnetic_flux_density_t, prefix::exa);
implement_unit(si, si, zettatesla, dim::magnetic_flux_density_t, prefix::zetta);
implement_unit(si, si, yottatesla, dim::magnetic_flux_density_t, prefix::yotta);
#pragma endregion
#pragma region henry(inductance)
implement_unit(si, si, yoctohenry, dim::inductance_t, prefix::yocto);
implement_unit(si, si, zeptohenry, dim::inductance_t, prefix::zepto);
implement_unit(si, si, attohenry, dim::inductance_t, prefix::atto);
implement_unit(si, si, femtohenry, dim::inductance_t, prefix::femto);
implement_unit(si, si, picohenry, dim::inductance_t, prefix::pico);
implement_unit(si, si, nanohenry, dim::inductance_t, prefix::nano);
implement_unit(si, si, microhenry, dim::inductance_t, prefix::micro);
implement_unit(si, si, millihenry, dim::inductance_t, prefix::milli);
implement_unit(si, si, centihenry, dim::inductance_t, prefix::centi);
implement_unit(si, si, decihenry, dim::inductance_t, prefix::deci);
implement_unit(si, si, henry, dim::inductance_t, prefix::one);
implement_unit(si, si, decahenry, dim::inductance_t, prefix::deca);
implement_unit(si, si, hectohenry, dim::inductance_t, prefix::hecto);
implement_unit(si, si, kilohenry, dim::inductance_t, prefix::kilo);
implement_unit(si, si, megahenry, dim::inductance_t, prefix::mega);
implement_unit(si, si, gigahenry, dim::inductance_t, prefix::giga);
implement_unit(si, si, terahenry, dim::inductance_t, prefix::tera);
implement_unit(si, si, petahenry, dim::inductance_t, prefix::peta);
implement_unit(si, si, exahenry, dim::inductance_t, prefix::exa);
implement_unit(si, si, zettahenry, dim::inductance_t, prefix::zetta);
implement_unit(si, si, yottahenry, dim::inductance_t, prefix::yotta);
#pragma endregion
#pragma region lumen(luminous flux)
implement_unit(si, si, yoctolumen, dim::luminous_flux_t, prefix::yocto);
implement_unit(si, si, zeptolumen, dim::luminous_flux_t, prefix::zepto);
implement_unit(si, si, attolumen, dim::luminous_flux_t, prefix::atto);
implement_unit(si, si, femtolumen, dim::luminous_flux_t, prefix::femto);
implement_unit(si, si, picolumen, dim::luminous_flux_t, prefix::pico);
implement_unit(si, si, nanolumen, dim::luminous_flux_t, prefix::nano);
implement_unit(si, si, microlumen, dim::luminous_flux_t, prefix::micro);
implement_unit(si, si, millilumen, dim::luminous_flux_t, prefix::milli);
implement_unit(si, si, centilumen, dim::luminous_flux_t, prefix::centi);
implement_unit(si, si, decilumen, dim::luminous_flux_t, prefix::deci);
implement_unit(si, si, lumen, dim::luminous_flux_t, prefix::one);
implement_unit(si, si, decalumen, dim::luminous_flux_t, prefix::deca);
implement_unit(si, si, hectolumen, dim::luminous_flux_t, prefix::hecto);
implement_unit(si, si, kilolumen, dim::luminous_flux_t, prefix::kilo);
implement_unit(si, si, megalumen, dim::luminous_flux_t, prefix::mega);
implement_unit(si, si, gigalumen, dim::luminous_flux_t, prefix::giga);
implement_unit(si, si, teralumen, dim::luminous_flux_t, prefix::tera);
implement_unit(si, si, petalumen, dim::luminous_flux_t, prefix::peta);
implement_unit(si, si, exalumen, dim::luminous_flux_t, prefix::exa);
implement_unit(si, si, zettalumen, dim::luminous_flux_t, prefix::zetta);
implement_unit(si, si, yottalumen, dim::luminous_flux_t, prefix::yotta);
#pragma endregion
#pragma region lux(illuminance)
implement_unit(si, si, yoctolux, dim::illuminance_t, prefix::yocto);
implement_unit(si, si, zeptolux, dim::illuminance_t, prefix::zepto);
implement_unit(si, si, attolux, dim::illuminance_t, prefix::atto);
implement_unit(si, si, femtolux, dim::illuminance_t, prefix::femto);
implement_unit(si, si, picolux, dim::illuminance_t, prefix::pico);
implement_unit(si, si, nanolux, dim::illuminance_t, prefix::nano);
implement_unit(si, si, microlux, dim::illuminance_t, prefix::micro);
implement_unit(si, si, millilux, dim::illuminance_t, prefix::milli);
implement_unit(si, si, centilux, dim::illuminance_t, prefix::centi);
implement_unit(si, si, decilux, dim::illuminance_t, prefix::deci);
implement_unit(si, si, lux, dim::illuminance_t, prefix::one);
implement_unit(si, si, decalux, dim::illuminance_t, prefix::deca);
implement_unit(si, si, hectolux, dim::illuminance_t, prefix::hecto);
implement_unit(si, si, kilolux, dim::illuminance_t, prefix::kilo);
implement_unit(si, si, megalux, dim::illuminance_t, prefix::mega);
implement_unit(si, si, gigalux, dim::illuminance_t, prefix::giga);
implement_unit(si, si, teralux, dim::illuminance_t, prefix::tera);
implement_unit(si, si, petalux, dim::illuminance_t, prefix::peta);
implement_unit(si, si, exalux, dim::illuminance_t, prefix::exa);
implement_unit(si, si, zettalux, dim::illuminance_t, prefix::zetta);
implement_unit(si, si, yottalux, dim::illuminance_t, prefix::yotta);
#pragma endregion
#pragma region watt per steradian(luminosity)
implement_unit(si, si, yoctowatt_per_steradian, dim::luminosity_t, prefix::yocto);
implement_unit(si, si, zeptowatt_per_steradian, dim::luminosity_t, prefix::zepto);
implement_unit(si, si, attowatt_per_steradian, dim::luminosity_t, prefix::atto);
implement_unit(si, si, femtowatt_per_steradian, dim::luminosity_t, prefix::femto);
implement_unit(si, si, picowatt_per_steradian, dim::luminosity_t, prefix::pico);
implement_unit(si, si, nanowatt_per_steradian, dim::luminosity_t, prefix::nano);
implement_unit(si, si, microwatt_per_steradian, dim::luminosity_t, prefix::micro);
implement_unit(si, si, milliwatt_per_steradian, dim::luminosity_t, prefix::milli);
implement_unit(si, si, centiwatt_per_steradian, dim::luminosity_t, prefix::centi);
implement_unit(si, si, deciwatt_per_steradian, dim::luminosity_t, prefix::deci);
implement_unit(si, si, watt_per_steradian, dim::luminosity_t, prefix::one);
implement_unit(si, si, decawatt_per_steradian, dim::luminosity_t, prefix::deca);
implement_unit(si, si, hectowatt_per_steradian, dim::luminosity_t, prefix::hecto);
implement_unit(si, si, kilowatt_per_steradian, dim::luminosity_t, prefix::kilo);
implement_unit(si, si, megawatt_per_steradian, dim::luminosity_t, prefix::mega);
implement_unit(si, si, gigawatt_per_steradian, dim::luminosity_t, prefix::giga);
implement_unit(si, si, terawatt_per_steradian, dim::luminosity_t, prefix::tera);
implement_unit(si, si, petawatt_per_steradian, dim::luminosity_t, prefix::peta);
implement_unit(si, si, exawatt_per_steradian, dim::luminosity_t, prefix::exa);
implement_unit(si, si, zettawatt_per_steradian, dim::luminosity_t, prefix::zetta);
implement_unit(si, si, yottawatt_per_steradian, dim::luminosity_t, prefix::yotta);
#pragma endregion
#pragma region becquerel(activity referred to a radionuclide)
implement_unit(si, si, yoctobecquerel, dim::activity_of_radionuclide_t, prefix::yocto);
implement_unit(si, si, zeptobecquerel, dim::activity_of_radionuclide_t, prefix::zepto);
implement_unit(si, si, attobecquerel, dim::activity_of_radionuclide_t, prefix::atto);
implement_unit(si, si, femtobecquerel, dim::activity_of_radionuclide_t, prefix::femto);
implement_unit(si, si, picobecquerel, dim::activity_of_radionuclide_t, prefix::pico);
implement_unit(si, si, nanobecquerel, dim::activity_of_radionuclide_t, prefix::nano);
implement_unit(si, si, microbecquerel, dim::activity_of_radionuclide_t, prefix::micro);
implement_unit(si, si, millibecquerel, dim::activity_of_radionuclide_t, prefix::milli);
implement_unit(si, si, centibecquerel, dim::activity_of_radionuclide_t, prefix::centi);
implement_unit(si, si, decibecquerel, dim::activity_of_radionuclide_t, prefix::deci);
implement_unit(si, si, becquerel, dim::activity_of_radionuclide_t, prefix::one);
implement_unit(si, si, decabecquerel, dim::activity_of_radionuclide_t, prefix::deca);
implement_unit(si, si, hectobecquerel, dim::activity_of_radionuclide_t, prefix::hecto);
implement_unit(si, si, kilobecquerel, dim::activity_of_radionuclide_t, prefix::kilo);
implement_unit(si, si, megabecquerel, dim::activity_of_radionuclide_t, prefix::mega);
implement_unit(si, si, gigabecquerel, dim::activity_of_radionuclide_t, prefix::giga);
implement_unit(si, si, terabecquerel, dim::activity_of_radionuclide_t, prefix::tera);
implement_unit(si, si, petabecquerel, dim::activity_of_radionuclide_t, prefix::peta);
implement_unit(si, si, exabecquerel, dim::activity_of_radionuclide_t, prefix::exa);
implement_unit(si, si, zettabecquerel, dim::activity_of_radionuclide_t, prefix::zetta);
implement_unit(si, si, yottabecquerel, dim::activity_of_radionuclide_t, prefix::yotta);
#pragma endregion
#pragma region gray(specific energy)
implement_unit(si, si, yoctogray, dim::absorbed_dose_t, prefix::yocto);
implement_unit(si, si, zeptogray, dim::absorbed_dose_t, prefix::zepto);
implement_unit(si, si, attogray, dim::absorbed_dose_t, prefix::atto);
implement_unit(si, si, femtogray, dim::absorbed_dose_t, prefix::femto);
implement_unit(si, si, picogray, dim::absorbed_dose_t, prefix::pico);
implement_unit(si, si, nanogray, dim::absorbed_dose_t, prefix::nano);
implement_unit(si, si, microgray, dim::absorbed_dose_t, prefix::micro);
implement_unit(si, si, milligray, dim::absorbed_dose_t, prefix::milli);
implement_unit(si, si, centigray, dim::absorbed_dose_t, prefix::centi);
implement_unit(si, si, decigray, dim::absorbed_dose_t, prefix::deci);
implement_unit(si, si, gray, dim::absorbed_dose_t, prefix::one);
implement_unit(si, si, decagray, dim::absorbed_dose_t, prefix::deca);
implement_unit(si, si, hectogray, dim::absorbed_dose_t, prefix::hecto);
implement_unit(si, si, kilogray, dim::absorbed_dose_t, prefix::kilo);
implement_unit(si, si, megagray, dim::absorbed_dose_t, prefix::mega);
implement_unit(si, si, gigagray, dim::absorbed_dose_t, prefix::giga);
implement_unit(si, si, teragray, dim::absorbed_dose_t, prefix::tera);
implement_unit(si, si, petagray, dim::absorbed_dose_t, prefix::peta);
implement_unit(si, si, exagray, dim::absorbed_dose_t, prefix::exa);
implement_unit(si, si, zettagray, dim::absorbed_dose_t, prefix::zetta);
implement_unit(si, si, yottagray, dim::absorbed_dose_t, prefix::yotta);
#pragma endregion
#pragma region sievert(dose equivalent)
implement_unit(si, si, yoctosievert, dim::dose_equivalent_t, prefix::yocto);
implement_unit(si, si, zeptosievert, dim::dose_equivalent_t, prefix::zepto);
implement_unit(si, si, attosievert, dim::dose_equivalent_t, prefix::atto);
implement_unit(si, si, femtosievert, dim::dose_equivalent_t, prefix::femto);
implement_unit(si, si, picosievert, dim::dose_equivalent_t, prefix::pico);
implement_unit(si, si, nanosievert, dim::dose_equivalent_t, prefix::nano);
implement_unit(si, si, microsievert, dim::dose_equivalent_t, prefix::micro);
implement_unit(si, si, millisievert, dim::dose_equivalent_t, prefix::milli);
implement_unit(si, si, centisievert, dim::dose_equivalent_t, prefix::centi);
implement_unit(si, si, decisievert, dim::dose_equivalent_t, prefix::deci);
implement_unit(si, si, sievert, dim::dose_equivalent_t, prefix::one);
implement_unit(si, si, decasievert, dim::dose_equivalent_t, prefix::deca);
implement_unit(si, si, hectosievert, dim::dose_equivalent_t, prefix::hecto);
implement_unit(si, si, kilosievert, dim::dose_equivalent_t, prefix::kilo);
implement_unit(si, si, megasievert, dim::dose_equivalent_t, prefix::mega);
implement_unit(si, si, gigasievert, dim::dose_equivalent_t, prefix::giga);
implement_unit(si, si, terasievert, dim::dose_equivalent_t, prefix::tera);
implement_unit(si, si, petasievert, dim::dose_equivalent_t, prefix::peta);
implement_unit(si, si, exasievert, dim::dose_equivalent_t, prefix::exa);
implement_unit(si, si, zettasievert, dim::dose_equivalent_t, prefix::zetta);
implement_unit(si, si, yottasievert, dim::dose_equivalent_t, prefix::yotta);
#pragma endregion
#pragma region katal(catalytic activity)
implement_unit(si, si, yoctokatal, dim::catalytic_activity_t, prefix::yocto);
implement_unit(si, si, zeptokatal, dim::catalytic_activity_t, prefix::zepto);
implement_unit(si, si, attokatal, dim::catalytic_activity_t, prefix::atto);
implement_unit(si, si, femtokatal, dim::catalytic_activity_t, prefix::femto);
implement_unit(si, si, picokatal, dim::catalytic_activity_t, prefix::pico);
implement_unit(si, si, nanokatal, dim::catalytic_activity_t, prefix::nano);
implement_unit(si, si, microkatal, dim::catalytic_activity_t, prefix::micro);
implement_unit(si, si, millikatal, dim::catalytic_activity_t, prefix::milli);
implement_unit(si, si, centikatal, dim::catalytic_activity_t, prefix::centi);
implement_unit(si, si, decikatal, dim::catalytic_activity_t, prefix::deci);
implement_unit(si, si, katal, dim::catalytic_activity_t, prefix::one);
implement_unit(si, si, decakatal, dim::catalytic_activity_t, prefix::deca);
implement_unit(si, si, hectokatal, dim::catalytic_activity_t, prefix::hecto);
implement_unit(si, si, kilokatal, dim::catalytic_activity_t, prefix::kilo);
implement_unit(si, si, megakatal, dim::catalytic_activity_t, prefix::mega);
implement_unit(si, si, gigakatal, dim::catalytic_activity_t, prefix::giga);
implement_unit(si, si, terakatal, dim::catalytic_activity_t, prefix::tera);
implement_unit(si, si, petakatal, dim::catalytic_activity_t, prefix::peta);
implement_unit(si, si, exakatal, dim::catalytic_activity_t, prefix::exa);
implement_unit(si, si, zettakatal, dim::catalytic_activity_t, prefix::zetta);
implement_unit(si, si, yottakatal, dim::catalytic_activity_t, prefix::yotta);
#pragma endregion
#pragma region pascal second(dynamic viscosity)
implement_unit(si, si, yoctopascal_second, dim::dynamic_viscosity_t, prefix::yocto);
implement_unit(si, si, zeptopascal_second, dim::dynamic_viscosity_t, prefix::zepto);
implement_unit(si, si, attopascal_second, dim::dynamic_viscosity_t, prefix::atto);
implement_unit(si, si, femtopascal_second, dim::dynamic_viscosity_t, prefix::femto);
implement_unit(si, si, picopascal_second, dim::dynamic_viscosity_t, prefix::pico);
implement_unit(si, si, nanopascal_second, dim::dynamic_viscosity_t, prefix::nano);
implement_unit(si, si, micropascal_second, dim::dynamic_viscosity_t, prefix::micro);
implement_unit(si, si, millipascal_second, dim::dynamic_viscosity_t, prefix::milli);
implement_unit(si, si, centipascal_second, dim::dynamic_viscosity_t, prefix::centi);
implement_unit(si, si, decipascal_second, dim::dynamic_viscosity_t, prefix::deci);
implement_unit(si, si, pascal_second, dim::dynamic_viscosity_t, prefix::one);
implement_unit(si, si, decapascal_second, dim::dynamic_viscosity_t, prefix::deca);
implement_unit(si, si, hectopascal_second, dim::dynamic_viscosity_t, prefix::hecto);
implement_unit(si, si, kilopascal_second, dim::dynamic_viscosity_t, prefix::kilo);
implement_unit(si, si, megapascal_second, dim::dynamic_viscosity_t, prefix::mega);
implement_unit(si, si, gigapascal_second, dim::dynamic_viscosity_t, prefix::giga);
implement_unit(si, si, terapascal_second, dim::dynamic_viscosity_t, prefix::tera);
implement_unit(si, si, petapascal_second, dim::dynamic_viscosity_t, prefix::peta);
implement_unit(si, si, exapascal_second, dim::dynamic_viscosity_t, prefix::exa);
implement_unit(si, si, zettapascal_second, dim::dynamic_viscosity_t, prefix::zetta);
implement_unit(si, si, yottapascal_second, dim::dynamic_viscosity_t, prefix::yotta);
#pragma endregion
#pragma region pascal minute(dynamic viscosity)
implement_unit(si, si, yoctopascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yocto>));
implement_unit(si, si, zeptopascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zepto>));
implement_unit(si, si, attopascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::atto>));
implement_unit(si, si, femtopascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::femto>));
implement_unit(si, si, picopascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::pico>));
implement_unit(si, si, nanopascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::nano>));
implement_unit(si, si, micropascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::micro>));
implement_unit(si, si, millipascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::milli>));
implement_unit(si, si, centipascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::centi>));
implement_unit(si, si, decipascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deci>));
implement_unit(si, si, pascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::one>));
implement_unit(si, si, decapascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deca>));
implement_unit(si, si, hectopascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::hecto>));
implement_unit(si, si, kilopascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::kilo>));
implement_unit(si, si, megapascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::mega>));
implement_unit(si, si, gigapascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::giga>));
implement_unit(si, si, terapascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::tera>));
implement_unit(si, si, petapascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::peta>));
implement_unit(si, si, exapascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::exa>));
implement_unit(si, si, zettapascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zetta>));
implement_unit(si, si, yottapascal_minute, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yotta>));
#pragma endregion
#pragma region pascal hour(dynamic viscosity)
implement_unit(si, si, yoctopascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yocto>));
implement_unit(si, si, zeptopascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zepto>));
implement_unit(si, si, attopascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::atto>));
implement_unit(si, si, femtopascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::femto>));
implement_unit(si, si, picopascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::pico>));
implement_unit(si, si, nanopascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::nano>));
implement_unit(si, si, micropascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::micro>));
implement_unit(si, si, millipascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::milli>));
implement_unit(si, si, centipascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::centi>));
implement_unit(si, si, decipascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deci>));
implement_unit(si, si, pascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::one>));
implement_unit(si, si, decapascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deca>));
implement_unit(si, si, hectopascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::hecto>));
implement_unit(si, si, kilopascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::kilo>));
implement_unit(si, si, megapascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::mega>));
implement_unit(si, si, gigapascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::giga>));
implement_unit(si, si, terapascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::tera>));
implement_unit(si, si, petapascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::peta>));
implement_unit(si, si, exapascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::exa>));
implement_unit(si, si, zettapascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zetta>));
implement_unit(si, si, yottapascal_hour, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yotta>));
#pragma endregion
#pragma region joule per radian(torque)
implement_unit(si, si, yoctojoule_per_radian, dim::torque_t, prefix::yocto);
implement_unit(si, si, zeptojoule_per_radian, dim::torque_t, prefix::zepto);
implement_unit(si, si, attojoule_per_radian, dim::torque_t, prefix::atto);
implement_unit(si, si, femtojoule_per_radian, dim::torque_t, prefix::femto);
implement_unit(si, si, picojoule_per_radian, dim::torque_t, prefix::pico);
implement_unit(si, si, nanojoule_per_radian, dim::torque_t, prefix::nano);
implement_unit(si, si, microjoule_per_radian, dim::torque_t, prefix::micro);
implement_unit(si, si, millijoule_per_radian, dim::torque_t, prefix::milli);
implement_unit(si, si, centijoule_per_radian, dim::torque_t, prefix::centi);
implement_unit(si, si, decijoule_per_radian, dim::torque_t, prefix::deci);
implement_unit(si, si, joule_per_radian, dim::torque_t, prefix::one);
implement_unit(si, si, decajoule_per_radian, dim::torque_t, prefix::deca);
implement_unit(si, si, hectojoule_per_radian, dim::torque_t, prefix::hecto);
implement_unit(si, si, kilojoule_per_radian, dim::torque_t, prefix::kilo);
implement_unit(si, si, megajoule_per_radian, dim::torque_t, prefix::mega);
implement_unit(si, si, gigajoule_per_radian, dim::torque_t, prefix::giga);
implement_unit(si, si, terajoule_per_radian, dim::torque_t, prefix::tera);
implement_unit(si, si, petajoule_per_radian, dim::torque_t, prefix::peta);
implement_unit(si, si, exajoule_per_radian, dim::torque_t, prefix::exa);
implement_unit(si, si, zettajoule_per_radian, dim::torque_t, prefix::zetta);
implement_unit(si, si, yottajoule_per_radian, dim::torque_t, prefix::yotta);
#pragma endregion
#pragma region joule per degree, ...(torque)
implement_unit(si, si, joule_per_degree, dim::torque_t, fix(impl::divide_lists_t<prefix::one, impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 180>>>));
implement_unit(si, si, joule_per_arcminute, dim::torque_t, fix(impl::divide_lists_t<prefix::one, impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 10800>>>));
implement_unit(si, si, joule_per_arcsecond, dim::torque_t, fix(impl::divide_lists_t<prefix::one, impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 648000>>>));
#pragma endregion
#pragma region radian per second(angular velocity)
implement_unit(si, si, yoctoradian_per_second, dim::angular_velocity_t, prefix::yocto);
implement_unit(si, si, zeptoradian_per_second, dim::angular_velocity_t, prefix::zepto);
implement_unit(si, si, attoradian_per_second, dim::angular_velocity_t, prefix::atto);
implement_unit(si, si, femtoradian_per_second, dim::angular_velocity_t, prefix::femto);
implement_unit(si, si, picoradian_per_second, dim::angular_velocity_t, prefix::pico);
implement_unit(si, si, nanoradian_per_second, dim::angular_velocity_t, prefix::nano);
implement_unit(si, si, microradian_per_second, dim::angular_velocity_t, prefix::micro);
implement_unit(si, si, milliradian_per_second, dim::angular_velocity_t, prefix::milli);
implement_unit(si, si, centiradian_per_second, dim::angular_velocity_t, prefix::centi);
implement_unit(si, si, deciradian_per_second, dim::angular_velocity_t, prefix::deci);
implement_unit(si, si, radian_per_second, dim::angular_velocity_t, prefix::one);
implement_unit(si, si, degree_per_second, dim::angular_velocity_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 180>>));
implement_unit(si, si, arcminute_per_second, dim::angular_velocity_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 10800>>));
implement_unit(si, si, arcsecond_per_second, dim::angular_velocity_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 648000>>));
#pragma endregion
#pragma region radian per minute(angular velocity)
implement_unit(si, si, yoctoradian_per_minute, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::yocto, prefix::minute>));
implement_unit(si, si, zeptoradian_per_minute, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::zepto, prefix::minute>));
implement_unit(si, si, attoradian_per_minute, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::atto, prefix::minute>));
implement_unit(si, si, femtoradian_per_minute, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::femto, prefix::minute>));
implement_unit(si, si, picoradian_per_minute, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::pico, prefix::minute>));
implement_unit(si, si, nanoradian_per_minute, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::nano, prefix::minute>));
implement_unit(si, si, microradian_per_minute, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::micro, prefix::minute>));
implement_unit(si, si, milliradian_per_minute, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::milli, prefix::minute>));
implement_unit(si, si, centiradian_per_minute, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::centi, prefix::minute>));
implement_unit(si, si, deciradian_per_minute, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::deci, prefix::minute>));
implement_unit(si, si, radian_per_minute, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::one, prefix::minute>));
link_unit(degree_per_minute, arcminute_per_second);
link_unit(arcminute_per_minute, arcsecond_per_second);
implement_unit(si, si, arcsecond_per_minute, dim::angular_velocity_t, fix(impl::divide_lists_t<impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 648000>>, prefix::minute>));
#pragma endregion
#pragma region radian per hour(angular velocity)
implement_unit(si, si, yoctoradian_per_hour, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::yocto, prefix::hour>));
implement_unit(si, si, zeptoradian_per_hour, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::zepto, prefix::hour>));
implement_unit(si, si, attoradian_per_hour, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::atto, prefix::hour>));
implement_unit(si, si, femtoradian_per_hour, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::femto, prefix::hour>));
implement_unit(si, si, picoradian_per_hour, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::pico, prefix::hour>));
implement_unit(si, si, nanoradian_per_hour, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::nano, prefix::hour>));
implement_unit(si, si, microradian_per_hour, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::micro, prefix::hour>));
implement_unit(si, si, milliradian_per_hour, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::milli, prefix::hour>));
implement_unit(si, si, centiradian_per_hour, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::centi, prefix::hour>));
implement_unit(si, si, deciradian_per_hour, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::deci, prefix::hour>));
implement_unit(si, si, radian_per_hour, dim::angular_velocity_t, fix(impl::divide_lists_t<prefix::one, prefix::hour>));
link_unit(degree_per_hour, arcsecond_per_second);
link_unit(arcminute_per_hour, arcsecond_per_minute);
implement_unit(si, si, arcsecond_per_hour, dim::angular_velocity_t, fix(impl::divide_lists_t<impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 648000>>, prefix::hour>));
#pragma endregion
#pragma region radian per square second(angular acceleration)
implement_unit(si, si, yoctoradian_per_square_second, dim::angular_acceleration_t, prefix::yocto);
implement_unit(si, si, zeptoradian_per_square_second, dim::angular_acceleration_t, prefix::zepto);
implement_unit(si, si, attoradian_per_square_second, dim::angular_acceleration_t, prefix::atto);
implement_unit(si, si, femtoradian_per_square_second, dim::angular_acceleration_t, prefix::femto);
implement_unit(si, si, picoradian_per_square_second, dim::angular_acceleration_t, prefix::pico);
implement_unit(si, si, nanoradian_per_square_second, dim::angular_acceleration_t, prefix::nano);
implement_unit(si, si, microradian_per_square_second, dim::angular_acceleration_t, prefix::micro);
implement_unit(si, si, milliradian_per_square_second, dim::angular_acceleration_t, prefix::milli);
implement_unit(si, si, centiradian_per_square_second, dim::angular_acceleration_t, prefix::centi);
implement_unit(si, si, deciradian_per_square_second, dim::angular_acceleration_t, prefix::deci);
implement_unit(si, si, radian_per_square_second, dim::angular_acceleration_t, prefix::one);
implement_unit(si, si, degree_per_square_second, dim::angular_acceleration_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 180>>));
implement_unit(si, si, arcminute_per_square_second, dim::angular_acceleration_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 10800>>));
implement_unit(si, si, arcsecond_per_square_second, dim::angular_acceleration_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 648000>>));
#pragma endregion
#pragma region radian per square minute(angular acceleration)
implement_unit(si, si, yoctoradian_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::yocto, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, zeptoradian_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::zepto, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, attoradian_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::atto, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, femtoradian_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::femto, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, picoradian_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::pico, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, nanoradian_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::nano, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, microradian_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::micro, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, milliradian_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::milli, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, centiradian_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::centi, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, deciradian_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::deci, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, radian_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::one, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
link_unit(degree_per_square_minute, arcsecond_per_square_second);
implement_unit(si, si, arcminute_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 648000>>, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
implement_unit(si, si, arcsecond_per_square_minute, dim::angular_acceleration_t, fix(impl::divide_lists_t<impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 10800>>, impl::pow_list_t<prefix::minute, std::ratio<2>>>));
#pragma endregion
#pragma region radian per hour(angular acceleration)
implement_unit(si, si, yoctoradian_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::yocto, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, zeptoradian_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::zepto, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, attoradian_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::atto, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, femtoradian_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::femto, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, picoradian_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::pico, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, nanoradian_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::nano, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, microradian_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::micro, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, milliradian_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::milli, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, centiradian_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::centi, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, deciradian_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::deci, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, radian_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<prefix::one, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
link_unit(degree_per_square_hour, arcminute_per_square_minute);
implement_unit(si, si, arcminute_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 648000>>, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
implement_unit(si, si, arcsecond_per_square_hour, dim::angular_acceleration_t, fix(impl::divide_lists_t<impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 10800>>, impl::pow_list_t<prefix::hour, std::ratio<2>>>));
#pragma endregion
#pragma region watt per square metre(heat flux density)
implement_unit(si, si, yoctowatt_per_square_metre, dim::heat_flux_density_t, prefix::yocto);
implement_unit(si, si, zeptowatt_per_square_metre, dim::heat_flux_density_t, prefix::zepto);
implement_unit(si, si, attowatt_per_square_metre, dim::heat_flux_density_t, prefix::atto);
implement_unit(si, si, femtowatt_per_square_metre, dim::heat_flux_density_t, prefix::femto);
implement_unit(si, si, picowatt_per_square_metre, dim::heat_flux_density_t, prefix::pico);
implement_unit(si, si, nanowatt_per_square_metre, dim::heat_flux_density_t, prefix::nano);
implement_unit(si, si, microwatt_per_square_metre, dim::heat_flux_density_t, prefix::micro);
implement_unit(si, si, milliwatt_per_square_metre, dim::heat_flux_density_t, prefix::milli);
implement_unit(si, si, centiwatt_per_square_metre, dim::heat_flux_density_t, prefix::centi);
implement_unit(si, si, deciwatt_per_square_metre, dim::heat_flux_density_t, prefix::deci);
implement_unit(si, si, watt_per_square_metre, dim::heat_flux_density_t, prefix::one);
implement_unit(si, si, decawatt_per_square_metre, dim::heat_flux_density_t, prefix::deca);
implement_unit(si, si, hectowatt_per_square_metre, dim::heat_flux_density_t, prefix::hecto);
implement_unit(si, si, kilowatt_per_square_metre, dim::heat_flux_density_t, prefix::kilo);
implement_unit(si, si, megawatt_per_square_metre, dim::heat_flux_density_t, prefix::mega);
implement_unit(si, si, gigawatt_per_square_metre, dim::heat_flux_density_t, prefix::giga);
implement_unit(si, si, terawatt_per_square_metre, dim::heat_flux_density_t, prefix::tera);
implement_unit(si, si, petawatt_per_square_metre, dim::heat_flux_density_t, prefix::peta);
implement_unit(si, si, exawatt_per_square_metre, dim::heat_flux_density_t, prefix::exa);
implement_unit(si, si, zettawatt_per_square_metre, dim::heat_flux_density_t, prefix::zetta);
implement_unit(si, si, yottawatt_per_square_metre, dim::heat_flux_density_t, prefix::yotta);
#pragma endregion
#pragma region watt per square metre hertz(spectral heat flux density)
implement_unit(si, si, yoctowatt_per_square_metre_hertz, dim::surface_tension_t, prefix::yocto);
implement_unit(si, si, zeptowatt_per_square_metre_hertz, dim::surface_tension_t, prefix::zepto);
implement_unit(si, si, attowatt_per_square_metre_hertz, dim::surface_tension_t, prefix::atto);
implement_unit(si, si, femtowatt_per_square_metre_hertz, dim::surface_tension_t, prefix::femto);
implement_unit(si, si, picowatt_per_square_metre_hertz, dim::surface_tension_t, prefix::pico);
implement_unit(si, si, nanowatt_per_square_metre_hertz, dim::surface_tension_t, prefix::nano);
implement_unit(si, si, microwatt_per_square_metre_hertz, dim::surface_tension_t, prefix::micro);
implement_unit(si, si, milliwatt_per_square_metre_hertz, dim::surface_tension_t, prefix::milli);
implement_unit(si, si, centiwatt_per_square_metre_hertz, dim::surface_tension_t, prefix::centi);
implement_unit(si, si, deciwatt_per_square_metre_hertz, dim::surface_tension_t, prefix::deci);
implement_unit(si, si, watt_per_square_metre_hertz, dim::surface_tension_t, prefix::one);
implement_unit(si, si, decawatt_per_square_metre_hertz, dim::surface_tension_t, prefix::deca);
implement_unit(si, si, hectowatt_per_square_metre_hertz, dim::surface_tension_t, prefix::hecto);
implement_unit(si, si, kilowatt_per_square_metre_hertz, dim::surface_tension_t, prefix::kilo);
implement_unit(si, si, megawatt_per_square_metre_hertz, dim::surface_tension_t, prefix::mega);
implement_unit(si, si, gigawatt_per_square_metre_hertz, dim::surface_tension_t, prefix::giga);
implement_unit(si, si, terawatt_per_square_metre_hertz, dim::surface_tension_t, prefix::tera);
implement_unit(si, si, petawatt_per_square_metre_hertz, dim::surface_tension_t, prefix::peta);
implement_unit(si, si, exawatt_per_square_metre_hertz, dim::surface_tension_t, prefix::exa);
implement_unit(si, si, zettawatt_per_square_metre_hertz, dim::surface_tension_t, prefix::zetta);
implement_unit(si, si, yottawatt_per_square_metre_hertz, dim::surface_tension_t, prefix::yotta);
#pragma endregion
#pragma region jansky(spectral heat flux density)
implement_unit(si, si, yoctojansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::yocto>));
implement_unit(si, si, zeptojansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::zepto>));
implement_unit(si, si, attojansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::atto>));
implement_unit(si, si, femtojansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::femto>));
implement_unit(si, si, picojansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::pico>));
implement_unit(si, si, nanojansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::nano>));
implement_unit(si, si, microjansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::micro>));
implement_unit(si, si, millijansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::milli>));
implement_unit(si, si, centijansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::centi>));
implement_unit(si, si, decijansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::deci>));
implement_unit(si, si, jansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::one>));
implement_unit(si, si, decajansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::deca>));
link_unit(hectojansky, yoctowatt_per_square_metre_hertz);
implement_unit(si, si, kilojansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::kilo>));
implement_unit(si, si, megajansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::mega>));
implement_unit(si, si, gigajansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::giga>));
implement_unit(si, si, terajansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::tera>));
implement_unit(si, si, petajansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::peta>));
implement_unit(si, si, exajansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::exa>));
implement_unit(si, si, zettajansky, dim::surface_tension_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::yocto,prefix::centi>,prefix::zetta>));
link_unit(yottajansky, centiwatt_per_square_metre_hertz);
#pragma endregion
#pragma region joule per kelvin(heat capacity)
implement_unit(si, si, yoctojoule_per_kelvin, dim::heat_capacity_t, prefix::yocto);
implement_unit(si, si, zeptojoule_per_kelvin, dim::heat_capacity_t, prefix::zepto);
implement_unit(si, si, attojoule_per_kelvin, dim::heat_capacity_t, prefix::atto);
implement_unit(si, si, femtojoule_per_kelvin, dim::heat_capacity_t, prefix::femto);
implement_unit(si, si, picojoule_per_kelvin, dim::heat_capacity_t, prefix::pico);
implement_unit(si, si, nanojoule_per_kelvin, dim::heat_capacity_t, prefix::nano);
implement_unit(si, si, microjoule_per_kelvin, dim::heat_capacity_t, prefix::micro);
implement_unit(si, si, millijoule_per_kelvin, dim::heat_capacity_t, prefix::milli);
implement_unit(si, si, centijoule_per_kelvin, dim::heat_capacity_t, prefix::centi);
implement_unit(si, si, decijoule_per_kelvin, dim::heat_capacity_t, prefix::deci);
implement_unit(si, si, joule_per_kelvin, dim::heat_capacity_t, prefix::one);
implement_unit(si, si, decajoule_per_kelvin, dim::heat_capacity_t, prefix::deca);
implement_unit(si, si, hectojoule_per_kelvin, dim::heat_capacity_t, prefix::hecto);
implement_unit(si, si, kilojoule_per_kelvin, dim::heat_capacity_t, prefix::kilo);
implement_unit(si, si, megajoule_per_kelvin, dim::heat_capacity_t, prefix::mega);
implement_unit(si, si, gigajoule_per_kelvin, dim::heat_capacity_t, prefix::giga);
implement_unit(si, si, terajoule_per_kelvin, dim::heat_capacity_t, prefix::tera);
implement_unit(si, si, petajoule_per_kelvin, dim::heat_capacity_t, prefix::peta);
implement_unit(si, si, exajoule_per_kelvin, dim::heat_capacity_t, prefix::exa);
implement_unit(si, si, zettajoule_per_kelvin, dim::heat_capacity_t, prefix::zetta);
implement_unit(si, si, yottajoule_per_kelvin, dim::heat_capacity_t, prefix::yotta);
#pragma endregion
#pragma region joule per kilogram kelvin(specific heat capacity)
implement_unit(si, si, yoctojoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::yocto);
implement_unit(si, si, zeptojoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::zepto);
implement_unit(si, si, attojoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::atto);
implement_unit(si, si, femtojoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::femto);
implement_unit(si, si, picojoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::pico);
implement_unit(si, si, nanojoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::nano);
implement_unit(si, si, microjoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::micro);
implement_unit(si, si, millijoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::milli);
implement_unit(si, si, centijoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::centi);
implement_unit(si, si, decijoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::deci);
implement_unit(si, si, joule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::one);
implement_unit(si, si, decajoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::deca);
implement_unit(si, si, hectojoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::hecto);
implement_unit(si, si, kilojoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::kilo);
implement_unit(si, si, megajoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::mega);
implement_unit(si, si, gigajoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::giga);
implement_unit(si, si, terajoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::tera);
implement_unit(si, si, petajoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::peta);
implement_unit(si, si, exajoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::exa);
implement_unit(si, si, zettajoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::zetta);
implement_unit(si, si, yottajoule_per_kilogram_kelvin, dim::specific_heat_capacity_t, prefix::yotta);
#pragma endregion
#pragma region joule per kilogram(specific energy)
link_unit(yoctojoule_per_kilogram, yoctogray);
link_unit(zeptojoule_per_kilogram, zeptogray);
link_unit(attojoule_per_kilogram, attogray);
link_unit(femtojoule_per_kilogram, femtogray);
link_unit(picojoule_per_kilogram, picogray);
link_unit(nanojoule_per_kilogram, nanogray);
link_unit(microjoule_per_kilogram, microgray);
link_unit(millijoule_per_kilogram, milligray);
link_unit(centijoule_per_kilogram, centigray);
link_unit(decijoule_per_kilogram, decigray);
link_unit(joule_per_kilogram, gray);
link_unit(decajoule_per_kilogram, decagray);
link_unit(hectojoule_per_kilogram, hectogray);
link_unit(kilojoule_per_kilogram, kilogray);
link_unit(megajoule_per_kilogram, megagray);
link_unit(gigajoule_per_kilogram, gigagray);
link_unit(terajoule_per_kilogram, teragray);
link_unit(petajoule_per_kilogram, petagray);
link_unit(exajoule_per_kilogram, exagray);
link_unit(zettajoule_per_kilogram, zettagray);
link_unit(yottajoule_per_kilogram, yottagray);
#pragma endregion
#pragma region watt per metre kelvin(thermal conductivity)
implement_unit(si, si, yoctowatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::yocto);
implement_unit(si, si, zeptowatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::zepto);
implement_unit(si, si, attowatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::atto);
implement_unit(si, si, femtowatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::femto);
implement_unit(si, si, picowatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::pico);
implement_unit(si, si, nanowatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::nano);
implement_unit(si, si, microwatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::micro);
implement_unit(si, si, milliwatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::milli);
implement_unit(si, si, centiwatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::centi);
implement_unit(si, si, deciwatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::deci);
implement_unit(si, si, watt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::one);
implement_unit(si, si, decawatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::deca);
implement_unit(si, si, hectowatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::hecto);
implement_unit(si, si, kilowatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::kilo);
implement_unit(si, si, megawatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::mega);
implement_unit(si, si, gigawatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::giga);
implement_unit(si, si, terawatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::tera);
implement_unit(si, si, petawatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::peta);
implement_unit(si, si, exawatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::exa);
implement_unit(si, si, zettawatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::zetta);
implement_unit(si, si, yottawatt_per_metre_kelvin, dim::thermal_conductivity_t, prefix::yotta);
#pragma endregion
#pragma region joule per cubic metre(energy density)
link_unit(yoctojoule_per_cubic_metre, yoctopascal);
link_unit(zeptojoule_per_cubic_metre, zeptopascal);
link_unit(attojoule_per_cubic_metre, attopascal);
link_unit(femtojoule_per_cubic_metre, femtopascal);
link_unit(picojoule_per_cubic_metre, picopascal);
link_unit(nanojoule_per_cubic_metre, nanopascal);
link_unit(microjoule_per_cubic_metre, micropascal);
link_unit(millijoule_per_cubic_metre, millipascal);
link_unit(centijoule_per_cubic_metre, centipascal);
link_unit(decijoule_per_cubic_metre, decipascal);
link_unit(joule_per_cubic_metre, pascal);
link_unit(decajoule_per_cubic_metre, decapascal);
link_unit(hectojoule_per_cubic_metre, hectopascal);
link_unit(kilojoule_per_cubic_metre, kilopascal);
link_unit(megajoule_per_cubic_metre, megapascal);
link_unit(gigajoule_per_cubic_metre, gigapascal);
link_unit(terajoule_per_cubic_metre, terapascal);
link_unit(petajoule_per_cubic_metre, petapascal);
link_unit(exajoule_per_cubic_metre, exapascal);
link_unit(zettajoule_per_cubic_metre, zettapascal);
link_unit(yottajoule_per_cubic_metre, yottapascal);
#pragma endregion
#pragma region volt per metre(electric field strength)
implement_unit(si, si, yoctovolt_per_metre, dim::electric_field_strength_t, prefix::yocto);
implement_unit(si, si, zeptovolt_per_metre, dim::electric_field_strength_t, prefix::zepto);
implement_unit(si, si, attovolt_per_metre, dim::electric_field_strength_t, prefix::atto);
implement_unit(si, si, femtovolt_per_metre, dim::electric_field_strength_t, prefix::femto);
implement_unit(si, si, picovolt_per_metre, dim::electric_field_strength_t, prefix::pico);
implement_unit(si, si, nanovolt_per_metre, dim::electric_field_strength_t, prefix::nano);
implement_unit(si, si, microvolt_per_metre, dim::electric_field_strength_t, prefix::micro);
implement_unit(si, si, millivolt_per_metre, dim::electric_field_strength_t, prefix::milli);
implement_unit(si, si, centivolt_per_metre, dim::electric_field_strength_t, prefix::centi);
implement_unit(si, si, decivolt_per_metre, dim::electric_field_strength_t, prefix::deci);
implement_unit(si, si, volt_per_metre, dim::electric_field_strength_t, prefix::one);
implement_unit(si, si, decavolt_per_metre, dim::electric_field_strength_t, prefix::deca);
implement_unit(si, si, hectovolt_per_metre, dim::electric_field_strength_t, prefix::hecto);
implement_unit(si, si, kilovolt_per_metre, dim::electric_field_strength_t, prefix::kilo);
implement_unit(si, si, megavolt_per_metre, dim::electric_field_strength_t, prefix::mega);
implement_unit(si, si, gigavolt_per_metre, dim::electric_field_strength_t, prefix::giga);
implement_unit(si, si, teravolt_per_metre, dim::electric_field_strength_t, prefix::tera);
implement_unit(si, si, petavolt_per_metre, dim::electric_field_strength_t, prefix::peta);
implement_unit(si, si, exavolt_per_metre, dim::electric_field_strength_t, prefix::exa);
implement_unit(si, si, zettavolt_per_metre, dim::electric_field_strength_t, prefix::zetta);
implement_unit(si, si, yottavolt_per_metre, dim::electric_field_strength_t, prefix::yotta);
#pragma endregion
#pragma region coulomb per cubic metre(electric charge density)
implement_unit(si, si, yoctocoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::yocto);
implement_unit(si, si, zeptocoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::zepto);
implement_unit(si, si, attocoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::atto);
implement_unit(si, si, femtocoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::femto);
implement_unit(si, si, picocoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::pico);
implement_unit(si, si, nanocoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::nano);
implement_unit(si, si, microcoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::micro);
implement_unit(si, si, millicoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::milli);
implement_unit(si, si, centicoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::centi);
implement_unit(si, si, decicoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::deci);
implement_unit(si, si, coulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::one);
implement_unit(si, si, decacoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::deca);
implement_unit(si, si, hectocoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::hecto);
implement_unit(si, si, kilocoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::kilo);
implement_unit(si, si, megacoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::mega);
implement_unit(si, si, gigacoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::giga);
implement_unit(si, si, teracoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::tera);
implement_unit(si, si, petacoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::peta);
implement_unit(si, si, exacoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::exa);
implement_unit(si, si, zettacoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::zetta);
implement_unit(si, si, yottacoulomb_per_cubic_metre, dim::electric_charge_density_t, prefix::yotta);
#pragma endregion
#pragma region coulomb per square metre(electric charge density)
implement_unit(si, si, yoctocoulomb_per_square_metre, dim::electric_flux_density_t, prefix::yocto);
implement_unit(si, si, zeptocoulomb_per_square_metre, dim::electric_flux_density_t, prefix::zepto);
implement_unit(si, si, attocoulomb_per_square_metre, dim::electric_flux_density_t, prefix::atto);
implement_unit(si, si, femtocoulomb_per_square_metre, dim::electric_flux_density_t, prefix::femto);
implement_unit(si, si, picocoulomb_per_square_metre, dim::electric_flux_density_t, prefix::pico);
implement_unit(si, si, nanocoulomb_per_square_metre, dim::electric_flux_density_t, prefix::nano);
implement_unit(si, si, microcoulomb_per_square_metre, dim::electric_flux_density_t, prefix::micro);
implement_unit(si, si, millicoulomb_per_square_metre, dim::electric_flux_density_t, prefix::milli);
implement_unit(si, si, centicoulomb_per_square_metre, dim::electric_flux_density_t, prefix::centi);
implement_unit(si, si, decicoulomb_per_square_metre, dim::electric_flux_density_t, prefix::deci);
implement_unit(si, si, coulomb_per_square_metre, dim::electric_flux_density_t, prefix::one);
implement_unit(si, si, decacoulomb_per_square_metre, dim::electric_flux_density_t, prefix::deca);
implement_unit(si, si, hectocoulomb_per_square_metre, dim::electric_flux_density_t, prefix::hecto);
implement_unit(si, si, kilocoulomb_per_square_metre, dim::electric_flux_density_t, prefix::kilo);
implement_unit(si, si, megacoulomb_per_square_metre, dim::electric_flux_density_t, prefix::mega);
implement_unit(si, si, gigacoulomb_per_square_metre, dim::electric_flux_density_t, prefix::giga);
implement_unit(si, si, teracoulomb_per_square_metre, dim::electric_flux_density_t, prefix::tera);
implement_unit(si, si, petacoulomb_per_square_metre, dim::electric_flux_density_t, prefix::peta);
implement_unit(si, si, exacoulomb_per_square_metre, dim::electric_flux_density_t, prefix::exa);
implement_unit(si, si, zettacoulomb_per_square_metre, dim::electric_flux_density_t, prefix::zetta);
implement_unit(si, si, yottacoulomb_per_square_metre, dim::electric_flux_density_t, prefix::yotta);
#pragma endregion
#pragma region farad per metre(permittivity)
implement_unit(si, si, yoctofarad_per_metre, dim::permittivity_t, prefix::yocto);
implement_unit(si, si, zeptofarad_per_metre, dim::permittivity_t, prefix::zepto);
implement_unit(si, si, attofarad_per_metre, dim::permittivity_t, prefix::atto);
implement_unit(si, si, femtofarad_per_metre, dim::permittivity_t, prefix::femto);
implement_unit(si, si, picofarad_per_metre, dim::permittivity_t, prefix::pico);
implement_unit(si, si, nanofarad_per_metre, dim::permittivity_t, prefix::nano);
implement_unit(si, si, microfarad_per_metre, dim::permittivity_t, prefix::micro);
implement_unit(si, si, millifarad_per_metre, dim::permittivity_t, prefix::milli);
implement_unit(si, si, centifarad_per_metre, dim::permittivity_t, prefix::centi);
implement_unit(si, si, decifarad_per_metre, dim::permittivity_t, prefix::deci);
implement_unit(si, si, farad_per_metre, dim::permittivity_t, prefix::one);
implement_unit(si, si, decafarad_per_metre, dim::permittivity_t, prefix::deca);
implement_unit(si, si, hectofarad_per_metre, dim::permittivity_t, prefix::hecto);
implement_unit(si, si, kilofarad_per_metre, dim::permittivity_t, prefix::kilo);
implement_unit(si, si, megafarad_per_metre, dim::permittivity_t, prefix::mega);
implement_unit(si, si, gigafarad_per_metre, dim::permittivity_t, prefix::giga);
implement_unit(si, si, terafarad_per_metre, dim::permittivity_t, prefix::tera);
implement_unit(si, si, petafarad_per_metre, dim::permittivity_t, prefix::peta);
implement_unit(si, si, exafarad_per_metre, dim::permittivity_t, prefix::exa);
implement_unit(si, si, zettafarad_per_metre, dim::permittivity_t, prefix::zetta);
implement_unit(si, si, yottafarad_per_metre, dim::permittivity_t, prefix::yotta);
#pragma endregion
#pragma region henry per metre(permeability)
implement_unit(si, si, yoctohenry_per_metre, dim::permeability_t, prefix::yocto);
implement_unit(si, si, zeptohenry_per_metre, dim::permeability_t, prefix::zepto);
implement_unit(si, si, attohenry_per_metre, dim::permeability_t, prefix::atto);
implement_unit(si, si, femtohenry_per_metre, dim::permeability_t, prefix::femto);
implement_unit(si, si, picohenry_per_metre, dim::permeability_t, prefix::pico);
implement_unit(si, si, nanohenry_per_metre, dim::permeability_t, prefix::nano);
implement_unit(si, si, microhenry_per_metre, dim::permeability_t, prefix::micro);
implement_unit(si, si, millihenry_per_metre, dim::permeability_t, prefix::milli);
implement_unit(si, si, centihenry_per_metre, dim::permeability_t, prefix::centi);
implement_unit(si, si, decihenry_per_metre, dim::permeability_t, prefix::deci);
implement_unit(si, si, henry_per_metre, dim::permeability_t, prefix::one);
implement_unit(si, si, decahenry_per_metre, dim::permeability_t, prefix::deca);
implement_unit(si, si, hectohenry_per_metre, dim::permeability_t, prefix::hecto);
implement_unit(si, si, kilohenry_per_metre, dim::permeability_t, prefix::kilo);
implement_unit(si, si, megahenry_per_metre, dim::permeability_t, prefix::mega);
implement_unit(si, si, gigahenry_per_metre, dim::permeability_t, prefix::giga);
implement_unit(si, si, terahenry_per_metre, dim::permeability_t, prefix::tera);
implement_unit(si, si, petahenry_per_metre, dim::permeability_t, prefix::peta);
implement_unit(si, si, exahenry_per_metre, dim::permeability_t, prefix::exa);
implement_unit(si, si, zettahenry_per_metre, dim::permeability_t, prefix::zetta);
implement_unit(si, si, yottahenry_per_metre, dim::permeability_t, prefix::yotta);
#pragma endregion
#pragma region joule per mole(molar energy)
implement_unit(si, si, yoctojoule_per_mole, dim::molar_energy_t, prefix::yocto);
implement_unit(si, si, zeptojoule_per_mole, dim::molar_energy_t, prefix::zepto);
implement_unit(si, si, attojoule_per_mole, dim::molar_energy_t, prefix::atto);
implement_unit(si, si, femtojoule_per_mole, dim::molar_energy_t, prefix::femto);
implement_unit(si, si, picojoule_per_mole, dim::molar_energy_t, prefix::pico);
implement_unit(si, si, nanojoule_per_mole, dim::molar_energy_t, prefix::nano);
implement_unit(si, si, microjoule_per_mole, dim::molar_energy_t, prefix::micro);
implement_unit(si, si, millijoule_per_mole, dim::molar_energy_t, prefix::milli);
implement_unit(si, si, centijoule_per_mole, dim::molar_energy_t, prefix::centi);
implement_unit(si, si, decijoule_per_mole, dim::molar_energy_t, prefix::deci);
implement_unit(si, si, joule_per_mole, dim::molar_energy_t, prefix::one);
implement_unit(si, si, decajoule_per_mole, dim::molar_energy_t, prefix::deca);
implement_unit(si, si, hectojoule_per_mole, dim::molar_energy_t, prefix::hecto);
implement_unit(si, si, kilojoule_per_mole, dim::molar_energy_t, prefix::kilo);
implement_unit(si, si, megajoule_per_mole, dim::molar_energy_t, prefix::mega);
implement_unit(si, si, gigajoule_per_mole, dim::molar_energy_t, prefix::giga);
implement_unit(si, si, terajoule_per_mole, dim::molar_energy_t, prefix::tera);
implement_unit(si, si, petajoule_per_mole, dim::molar_energy_t, prefix::peta);
implement_unit(si, si, exajoule_per_mole, dim::molar_energy_t, prefix::exa);
implement_unit(si, si, zettajoule_per_mole, dim::molar_energy_t, prefix::zetta);
implement_unit(si, si, yottajoule_per_mole, dim::molar_energy_t, prefix::yotta);
#pragma endregion
#pragma region joule per mole kelvin(molar heat capacity)
implement_unit(si, si, yoctojoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::yocto);
implement_unit(si, si, zeptojoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::zepto);
implement_unit(si, si, attojoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::atto);
implement_unit(si, si, femtojoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::femto);
implement_unit(si, si, picojoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::pico);
implement_unit(si, si, nanojoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::nano);
implement_unit(si, si, microjoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::micro);
implement_unit(si, si, millijoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::milli);
implement_unit(si, si, centijoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::centi);
implement_unit(si, si, decijoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::deci);
implement_unit(si, si, joule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::one);
implement_unit(si, si, decajoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::deca);
implement_unit(si, si, hectojoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::hecto);
implement_unit(si, si, kilojoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::kilo);
implement_unit(si, si, megajoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::mega);
implement_unit(si, si, gigajoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::giga);
implement_unit(si, si, terajoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::tera);
implement_unit(si, si, petajoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::peta);
implement_unit(si, si, exajoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::exa);
implement_unit(si, si, zettajoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::zetta);
implement_unit(si, si, yottajoule_per_mole_kelvin, dim::molar_heat_capacity_t, prefix::yotta);
#pragma endregion
#pragma region coulomb per kilogram(exposure)
implement_unit(si, si, yoctocoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::yocto);
implement_unit(si, si, zeptocoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::zepto);
implement_unit(si, si, attocoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::atto);
implement_unit(si, si, femtocoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::femto);
implement_unit(si, si, picocoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::pico);
implement_unit(si, si, nanocoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::nano);
implement_unit(si, si, microcoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::micro);
implement_unit(si, si, millicoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::milli);
implement_unit(si, si, centicoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::centi);
implement_unit(si, si, decicoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::deci);
implement_unit(si, si, coulomb_per_kilogram, dim::radioactive_exposure_t, prefix::one);
implement_unit(si, si, decacoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::deca);
implement_unit(si, si, hectocoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::hecto);
implement_unit(si, si, kilocoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::kilo);
implement_unit(si, si, megacoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::mega);
implement_unit(si, si, gigacoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::giga);
implement_unit(si, si, teracoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::tera);
implement_unit(si, si, petacoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::peta);
implement_unit(si, si, exacoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::exa);
implement_unit(si, si, zettacoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::zetta);
implement_unit(si, si, yottacoulomb_per_kilogram, dim::radioactive_exposure_t, prefix::yotta);
#pragma endregion
#pragma region gray per second(absorbed dose rate)
implement_unit(si, si, yoctogray_per_second, dim::absorbed_dose_rate_t, prefix::yocto);
implement_unit(si, si, zeptogray_per_second, dim::absorbed_dose_rate_t, prefix::zepto);
implement_unit(si, si, attogray_per_second, dim::absorbed_dose_rate_t, prefix::atto);
implement_unit(si, si, femtogray_per_second, dim::absorbed_dose_rate_t, prefix::femto);
implement_unit(si, si, picogray_per_second, dim::absorbed_dose_rate_t, prefix::pico);
implement_unit(si, si, nanogray_per_second, dim::absorbed_dose_rate_t, prefix::nano);
implement_unit(si, si, microgray_per_second, dim::absorbed_dose_rate_t, prefix::micro);
implement_unit(si, si, milligray_per_second, dim::absorbed_dose_rate_t, prefix::milli);
implement_unit(si, si, centigray_per_second, dim::absorbed_dose_rate_t, prefix::centi);
implement_unit(si, si, decigray_per_second, dim::absorbed_dose_rate_t, prefix::deci);
implement_unit(si, si, gray_per_second, dim::absorbed_dose_rate_t, prefix::one);
implement_unit(si, si, decagray_per_second, dim::absorbed_dose_rate_t, prefix::deca);
implement_unit(si, si, hectogray_per_second, dim::absorbed_dose_rate_t, prefix::hecto);
implement_unit(si, si, kilogray_per_second, dim::absorbed_dose_rate_t, prefix::kilo);
implement_unit(si, si, megagray_per_second, dim::absorbed_dose_rate_t, prefix::mega);
implement_unit(si, si, gigagray_per_second, dim::absorbed_dose_rate_t, prefix::giga);
implement_unit(si, si, teragray_per_second, dim::absorbed_dose_rate_t, prefix::tera);
implement_unit(si, si, petagray_per_second, dim::absorbed_dose_rate_t, prefix::peta);
implement_unit(si, si, exagray_per_second, dim::absorbed_dose_rate_t, prefix::exa);
implement_unit(si, si, zettagray_per_second, dim::absorbed_dose_rate_t, prefix::zetta);
implement_unit(si, si, yottagray_per_second, dim::absorbed_dose_rate_t, prefix::yotta);
#pragma endregion
#pragma region gray per minute(absorbed dose rate)
implement_unit(si, si, yoctogray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::yocto, prefix::minute>));
implement_unit(si, si, zeptogray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::zepto, prefix::minute>));
implement_unit(si, si, attogray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::atto, prefix::minute>));
implement_unit(si, si, femtogray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::femto, prefix::minute>));
implement_unit(si, si, picogray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::pico, prefix::minute>));
implement_unit(si, si, nanogray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::nano, prefix::minute>));
implement_unit(si, si, microgray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::micro, prefix::minute>));
implement_unit(si, si, milligray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::milli, prefix::minute>));
implement_unit(si, si, centigray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::centi, prefix::minute>));
implement_unit(si, si, decigray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::deci, prefix::minute>));
implement_unit(si, si, gray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::one, prefix::minute>));
implement_unit(si, si, decagray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::deca, prefix::minute>));
implement_unit(si, si, hectogray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::hecto, prefix::minute>));
implement_unit(si, si, kilogray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::kilo, prefix::minute>));
implement_unit(si, si, megagray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::mega, prefix::minute>));
implement_unit(si, si, gigagray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::giga, prefix::minute>));
implement_unit(si, si, teragray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::tera, prefix::minute>));
implement_unit(si, si, petagray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::peta, prefix::minute>));
implement_unit(si, si, exagray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::exa, prefix::minute>));
implement_unit(si, si, zettagray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::zetta, prefix::minute>));
implement_unit(si, si, yottagray_per_minute, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::yotta, prefix::minute>));
#pragma endregion
#pragma region gray per hour(absorbed dose rate)
implement_unit(si, si, yoctogray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::yocto, prefix::hour>));
implement_unit(si, si, zeptogray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::zepto, prefix::hour>));
implement_unit(si, si, attogray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::atto, prefix::hour>));
implement_unit(si, si, femtogray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::femto, prefix::hour>));
implement_unit(si, si, picogray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::pico, prefix::hour>));
implement_unit(si, si, nanogray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::nano, prefix::hour>));
implement_unit(si, si, microgray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::micro, prefix::hour>));
implement_unit(si, si, milligray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::milli, prefix::hour>));
implement_unit(si, si, centigray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::centi, prefix::hour>));
implement_unit(si, si, decigray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::deci, prefix::hour>));
implement_unit(si, si, gray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::one, prefix::hour>));
implement_unit(si, si, decagray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::deca, prefix::hour>));
implement_unit(si, si, hectogray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::hecto, prefix::hour>));
implement_unit(si, si, kilogray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::kilo, prefix::hour>));
implement_unit(si, si, megagray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::mega, prefix::hour>));
implement_unit(si, si, gigagray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::giga, prefix::hour>));
implement_unit(si, si, teragray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::tera, prefix::hour>));
implement_unit(si, si, petagray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::peta, prefix::hour>));
implement_unit(si, si, exagray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::exa, prefix::hour>));
implement_unit(si, si, zettagray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::zetta, prefix::hour>));
implement_unit(si, si, yottagray_per_hour, dim::absorbed_dose_rate_t, fix(impl::divide_lists_t<prefix::yotta, prefix::hour>));
#pragma endregion
#pragma region watt per square metre steradian(radiance)
implement_unit(si, si, yoctowatt_per_square_metre_steradian, dim::radiance_t, prefix::yocto);
implement_unit(si, si, zeptowatt_per_square_metre_steradian, dim::radiance_t, prefix::zepto);
implement_unit(si, si, attowatt_per_square_metre_steradian, dim::radiance_t, prefix::atto);
implement_unit(si, si, femtowatt_per_square_metre_steradian, dim::radiance_t, prefix::femto);
implement_unit(si, si, picowatt_per_square_metre_steradian, dim::radiance_t, prefix::pico);
implement_unit(si, si, nanowatt_per_square_metre_steradian, dim::radiance_t, prefix::nano);
implement_unit(si, si, microwatt_per_square_metre_steradian, dim::radiance_t, prefix::micro);
implement_unit(si, si, milliwatt_per_square_metre_steradian, dim::radiance_t, prefix::milli);
implement_unit(si, si, centiwatt_per_square_metre_steradian, dim::radiance_t, prefix::centi);
implement_unit(si, si, deciwatt_per_square_metre_steradian, dim::radiance_t, prefix::deci);
implement_unit(si, si, watt_per_square_metre_steradian, dim::radiance_t, prefix::one);
implement_unit(si, si, decawatt_per_square_metre_steradian, dim::radiance_t, prefix::deca);
implement_unit(si, si, hectowatt_per_square_metre_steradian, dim::radiance_t, prefix::hecto);
implement_unit(si, si, kilowatt_per_square_metre_steradian, dim::radiance_t, prefix::kilo);
implement_unit(si, si, megawatt_per_square_metre_steradian, dim::radiance_t, prefix::mega);
implement_unit(si, si, gigawatt_per_square_metre_steradian, dim::radiance_t, prefix::giga);
implement_unit(si, si, terawatt_per_square_metre_steradian, dim::radiance_t, prefix::tera);
implement_unit(si, si, petawatt_per_square_metre_steradian, dim::radiance_t, prefix::peta);
implement_unit(si, si, exawatt_per_square_metre_steradian, dim::radiance_t, prefix::exa);
implement_unit(si, si, zettawatt_per_square_metre_steradian, dim::radiance_t, prefix::zetta);
implement_unit(si, si, yottawatt_per_square_metre_steradian, dim::radiance_t, prefix::yotta);
#pragma endregion
#pragma region katal per cubic metre(catalytic activity concentration)
implement_unit(si, si, yoctokatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::yocto);
implement_unit(si, si, zeptokatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::zepto);
implement_unit(si, si, attokatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::atto);
implement_unit(si, si, femtokatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::femto);
implement_unit(si, si, picokatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::pico);
implement_unit(si, si, nanokatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::nano);
implement_unit(si, si, microkatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::micro);
implement_unit(si, si, millikatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::milli);
implement_unit(si, si, centikatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::centi);
implement_unit(si, si, decikatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::deci);
implement_unit(si, si, katal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::one);
implement_unit(si, si, decakatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::deca);
implement_unit(si, si, hectokatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::hecto);
implement_unit(si, si, kilokatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::kilo);
implement_unit(si, si, megakatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::mega);
implement_unit(si, si, gigakatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::giga);
implement_unit(si, si, terakatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::tera);
implement_unit(si, si, petakatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::peta);
implement_unit(si, si, exakatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::exa);
implement_unit(si, si, zettakatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::zetta);
implement_unit(si, si, yottakatal_per_cubic_metre, dim::catalytic_activity_concentration_t, prefix::yotta);
#pragma endregion
#pragma region joule second(action)
implement_unit(si, si, yoctojoule_second, dim::action_t, prefix::yocto);
implement_unit(si, si, zeptojoule_second, dim::action_t, prefix::zepto);
implement_unit(si, si, attojoule_second, dim::action_t, prefix::atto);
implement_unit(si, si, femtojoule_second, dim::action_t, prefix::femto);
implement_unit(si, si, picojoule_second, dim::action_t, prefix::pico);
implement_unit(si, si, nanojoule_second, dim::action_t, prefix::nano);
implement_unit(si, si, microjoule_second, dim::action_t, prefix::micro);
implement_unit(si, si, millijoule_second, dim::action_t, prefix::milli);
implement_unit(si, si, centijoule_second, dim::action_t, prefix::centi);
implement_unit(si, si, decijoule_second, dim::action_t, prefix::deci);
implement_unit(si, si, joule_second, dim::action_t, prefix::one);
implement_unit(si, si, decajoule_second, dim::action_t, prefix::deca);
implement_unit(si, si, hectojoule_second, dim::action_t, prefix::hecto);
implement_unit(si, si, kilojoule_second, dim::action_t, prefix::kilo);
implement_unit(si, si, megajoule_second, dim::action_t, prefix::mega);
implement_unit(si, si, gigajoule_second, dim::action_t, prefix::giga);
implement_unit(si, si, terajoule_second, dim::action_t, prefix::tera);
implement_unit(si, si, petajoule_second, dim::action_t, prefix::peta);
implement_unit(si, si, exajoule_second, dim::action_t, prefix::exa);
implement_unit(si, si, zettajoule_second, dim::action_t, prefix::zetta);
implement_unit(si, si, yottajoule_second, dim::action_t, prefix::yotta);
#pragma endregion
#pragma region joule minute(action)
implement_unit(si, si, yoctojoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yocto>));
implement_unit(si, si, zeptojoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zepto>));
implement_unit(si, si, attojoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::atto>));
implement_unit(si, si, femtojoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::femto>));
implement_unit(si, si, picojoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::pico>));
implement_unit(si, si, nanojoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::nano>));
implement_unit(si, si, microjoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::micro>));
implement_unit(si, si, millijoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::milli>));
implement_unit(si, si, centijoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::centi>));
implement_unit(si, si, decijoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deci>));
implement_unit(si, si, joule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::one>));
implement_unit(si, si, decajoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deca>));
implement_unit(si, si, hectojoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::hecto>));
implement_unit(si, si, kilojoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::kilo>));
implement_unit(si, si, megajoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::mega>));
implement_unit(si, si, gigajoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::giga>));
implement_unit(si, si, terajoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::tera>));
implement_unit(si, si, petajoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::peta>));
implement_unit(si, si, exajoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::exa>));
implement_unit(si, si, zettajoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zetta>));
implement_unit(si, si, yottajoule_minute, dim::action_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yotta>));
#pragma endregion
#pragma region joule hour(action)
implement_unit(si, si, yoctojoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yocto>));
implement_unit(si, si, zeptojoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zepto>));
implement_unit(si, si, attojoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::atto>));
implement_unit(si, si, femtojoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::femto>));
implement_unit(si, si, picojoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::pico>));
implement_unit(si, si, nanojoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::nano>));
implement_unit(si, si, microjoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::micro>));
implement_unit(si, si, millijoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::milli>));
implement_unit(si, si, centijoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::centi>));
implement_unit(si, si, decijoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deci>));
implement_unit(si, si, joule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::one>));
implement_unit(si, si, decajoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deca>));
implement_unit(si, si, hectojoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::hecto>));
implement_unit(si, si, kilojoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::kilo>));
implement_unit(si, si, megajoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::mega>));
implement_unit(si, si, gigajoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::giga>));
implement_unit(si, si, terajoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::tera>));
implement_unit(si, si, petajoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::peta>));
implement_unit(si, si, exajoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::exa>));
implement_unit(si, si, zettajoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zetta>));
implement_unit(si, si, yottajoule_hour, dim::action_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yotta>));
#pragma endregion
#pragma region square metre per second(kinematic viscosity)
implement_unit(si, si, square_metre_per_second, dim::kinematic_viscosity_t, prefix::one);
#pragma endregion
#pragma region kilogram per metre(line density)
implement_unit(si, si, yoctogram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::yocto, prefix::milli>));
implement_unit(si, si, zeptogram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::zepto, prefix::milli>));
implement_unit(si, si, attogram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::atto, prefix::milli>));
implement_unit(si, si, femtogram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::femto, prefix::milli>));
implement_unit(si, si, picogram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::pico, prefix::milli>));
implement_unit(si, si, nanogram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::nano, prefix::milli>));
implement_unit(si, si, microgram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::micro, prefix::milli>));
implement_unit(si, si, milligram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::milli, prefix::milli>));
implement_unit(si, si, centigram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::centi, prefix::milli>));
implement_unit(si, si, decigram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::deci, prefix::milli>));
implement_unit(si, si, gram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::one, prefix::milli>));
implement_unit(si, si, decagram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::deca, prefix::milli>));
implement_unit(si, si, hectogram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::hecto, prefix::milli>));
implement_unit(si, si, kilogram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::kilo, prefix::milli>));
implement_unit(si, si, megagram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::mega, prefix::milli>));
link_unit(tonne_per_metre, megagram_per_metre);
implement_unit(si, si, gigagram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::giga, prefix::milli>));
link_unit(kilotonne_per_metre, gigagram_per_metre);
implement_unit(si, si, teragram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::tera, prefix::milli>));
link_unit(megatonne_per_metre, teragram_per_metre);
implement_unit(si, si, petagram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::peta, prefix::milli>));
link_unit(gigatonne_per_metre, petagram_per_metre);
implement_unit(si, si, exagram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::exa, prefix::milli>));
implement_unit(si, si, zettagram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::zetta, prefix::milli>));
implement_unit(si, si, yottagram_per_metre, dim::line_density_t, fix(impl::multiply_lists_t<prefix::yotta, prefix::milli>));
#pragma endregion
#pragma region metre second(absement)
implement_unit(si, si, yoctometre_second, dim::absement_t, prefix::yocto);
implement_unit(si, si, zeptometre_second, dim::absement_t, prefix::zepto);
implement_unit(si, si, attometre_second, dim::absement_t, prefix::atto);
implement_unit(si, si, femtometre_second, dim::absement_t, prefix::femto);
implement_unit(si, si, picometre_second, dim::absement_t, prefix::pico);
implement_unit(si, si, nanometre_second, dim::absement_t, prefix::nano);
implement_unit(si, si, micrometre_second, dim::absement_t, prefix::micro);
implement_unit(si, si, millimetre_second, dim::absement_t, prefix::milli);
implement_unit(si, si, centimetre_second, dim::absement_t, prefix::centi);
implement_unit(si, si, decimetre_second, dim::absement_t, prefix::deci);
implement_unit(si, si, metre_second, dim::absement_t, prefix::one);
implement_unit(si, si, decametre_second, dim::absement_t, prefix::deca);
implement_unit(si, si, hectometre_second, dim::absement_t, prefix::hecto);
implement_unit(si, si, kilometre_second, dim::absement_t, prefix::kilo);
implement_unit(si, si, megametre_second, dim::absement_t, prefix::mega);
implement_unit(si, si, gigametre_second, dim::absement_t, prefix::giga);
implement_unit(si, si, terametre_second, dim::absement_t, prefix::tera);
implement_unit(si, si, petametre_second, dim::absement_t, prefix::peta);
implement_unit(si, si, exametre_second, dim::absement_t, prefix::exa);
implement_unit(si, si, zettametre_second, dim::absement_t, prefix::zetta);
implement_unit(si, si, yottametre_second, dim::absement_t, prefix::yotta);
#pragma endregion
#pragma region metre minute(absement)
implement_unit(si, si, yoctometre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yocto>));
implement_unit(si, si, zeptometre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zepto>));
implement_unit(si, si, attometre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::atto>));
implement_unit(si, si, femtometre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::femto>));
implement_unit(si, si, picometre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::pico>));
implement_unit(si, si, nanometre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::nano>));
implement_unit(si, si, micrometre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::micro>));
implement_unit(si, si, millimetre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::milli>));
implement_unit(si, si, centimetre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::centi>));
implement_unit(si, si, decimetre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deci>));
implement_unit(si, si, metre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::one>));
implement_unit(si, si, decametre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deca>));
implement_unit(si, si, hectometre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::hecto>));
implement_unit(si, si, kilometre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::kilo>));
implement_unit(si, si, megametre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::mega>));
implement_unit(si, si, gigametre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::giga>));
implement_unit(si, si, terametre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::tera>));
implement_unit(si, si, petametre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::peta>));
implement_unit(si, si, exametre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::exa>));
implement_unit(si, si, zettametre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zetta>));
implement_unit(si, si, yottametre_minute, dim::absement_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yotta>));
#pragma endregion
#pragma region metre hour(absement)
implement_unit(si, si, yoctometre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yocto>));
implement_unit(si, si, zeptometre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zepto>));
implement_unit(si, si, attometre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::atto>));
implement_unit(si, si, femtometre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::femto>));
implement_unit(si, si, picometre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::pico>));
implement_unit(si, si, nanometre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::nano>));
implement_unit(si, si, micrometre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::micro>));
implement_unit(si, si, millimetre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::milli>));
implement_unit(si, si, centimetre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::centi>));
implement_unit(si, si, decimetre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deci>));
implement_unit(si, si, metre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::one>));
implement_unit(si, si, decametre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deca>));
implement_unit(si, si, hectometre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::hecto>));
implement_unit(si, si, kilometre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::kilo>));
implement_unit(si, si, megametre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::mega>));
implement_unit(si, si, gigametre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::giga>));
implement_unit(si, si, terametre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::tera>));
implement_unit(si, si, petametre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::peta>));
implement_unit(si, si, exametre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::exa>));
implement_unit(si, si, zettametre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zetta>));
implement_unit(si, si, yottametre_hour, dim::absement_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yotta>));
#pragma endregion
#pragma region siemens per metre(electric conductivity)
implement_unit(si, si, yoctosiemens_per_metre, dim::electric_conductivity_t, prefix::yocto);
implement_unit(si, si, zeptosiemens_per_metre, dim::electric_conductivity_t, prefix::zepto);
implement_unit(si, si, attosiemens_per_metre, dim::electric_conductivity_t, prefix::atto);
implement_unit(si, si, femtosiemens_per_metre, dim::electric_conductivity_t, prefix::femto);
implement_unit(si, si, picosiemens_per_metre, dim::electric_conductivity_t, prefix::pico);
implement_unit(si, si, nanosiemens_per_metre, dim::electric_conductivity_t, prefix::nano);
implement_unit(si, si, microsiemens_per_metre, dim::electric_conductivity_t, prefix::micro);
implement_unit(si, si, millisiemens_per_metre, dim::electric_conductivity_t, prefix::milli);
implement_unit(si, si, centisiemens_per_metre, dim::electric_conductivity_t, prefix::centi);
implement_unit(si, si, decisiemens_per_metre, dim::electric_conductivity_t, prefix::deci);
implement_unit(si, si, siemens_per_metre, dim::electric_conductivity_t, prefix::one);
implement_unit(si, si, decasiemens_per_metre, dim::electric_conductivity_t, prefix::deca);
implement_unit(si, si, hectosiemens_per_metre, dim::electric_conductivity_t, prefix::hecto);
implement_unit(si, si, kilosiemens_per_metre, dim::electric_conductivity_t, prefix::kilo);
implement_unit(si, si, megasiemens_per_metre, dim::electric_conductivity_t, prefix::mega);
implement_unit(si, si, gigasiemens_per_metre, dim::electric_conductivity_t, prefix::giga);
implement_unit(si, si, terasiemens_per_metre, dim::electric_conductivity_t, prefix::tera);
implement_unit(si, si, petasiemens_per_metre, dim::electric_conductivity_t, prefix::peta);
implement_unit(si, si, exasiemens_per_metre, dim::electric_conductivity_t, prefix::exa);
implement_unit(si, si, zettasiemens_per_metre, dim::electric_conductivity_t, prefix::zetta);
implement_unit(si, si, yottasiemens_per_metre, dim::electric_conductivity_t, prefix::yotta);
#pragma endregion
#pragma region ohm metre(electric resitivity)
implement_unit(si, si, yoctoohm_metre, dim::electric_resistivity_t, prefix::yocto);
implement_unit(si, si, zeptoohm_metre, dim::electric_resistivity_t, prefix::zepto);
implement_unit(si, si, attoohm_metre, dim::electric_resistivity_t, prefix::atto);
implement_unit(si, si, femtoohm_metre, dim::electric_resistivity_t, prefix::femto);
implement_unit(si, si, picoohm_metre, dim::electric_resistivity_t, prefix::pico);
implement_unit(si, si, nanoohm_metre, dim::electric_resistivity_t, prefix::nano);
implement_unit(si, si, microohm_metre, dim::electric_resistivity_t, prefix::micro);
implement_unit(si, si, milliohm_metre, dim::electric_resistivity_t, prefix::milli);
implement_unit(si, si, centiohm_metre, dim::electric_resistivity_t, prefix::centi);
implement_unit(si, si, deciohm_metre, dim::electric_resistivity_t, prefix::deci);
implement_unit(si, si, ohm_metre, dim::electric_resistivity_t, prefix::one);
implement_unit(si, si, decaohm_metre, dim::electric_resistivity_t, prefix::deca);
implement_unit(si, si, hectoohm_metre, dim::electric_resistivity_t, prefix::hecto);
implement_unit(si, si, kiloohm_metre, dim::electric_resistivity_t, prefix::kilo);
implement_unit(si, si, megaohm_metre, dim::electric_resistivity_t, prefix::mega);
implement_unit(si, si, gigaohm_metre, dim::electric_resistivity_t, prefix::giga);
implement_unit(si, si, teraohm_metre, dim::electric_resistivity_t, prefix::tera);
implement_unit(si, si, petaohm_metre, dim::electric_resistivity_t, prefix::peta);
implement_unit(si, si, exaohm_metre, dim::electric_resistivity_t, prefix::exa);
implement_unit(si, si, zettaohm_metre, dim::electric_resistivity_t, prefix::zetta);
implement_unit(si, si, yottaohm_metre, dim::electric_resistivity_t, prefix::yotta);
#pragma endregion
#pragma region newton second(momentum)
implement_unit(si, si, yoctonewton_second, dim::momentum_t, prefix::yocto);
implement_unit(si, si, zeptonewton_second, dim::momentum_t, prefix::zepto);
implement_unit(si, si, attonewton_second, dim::momentum_t, prefix::atto);
implement_unit(si, si, femtonewton_second, dim::momentum_t, prefix::femto);
implement_unit(si, si, piconewton_second, dim::momentum_t, prefix::pico);
implement_unit(si, si, nanonewton_second, dim::momentum_t, prefix::nano);
implement_unit(si, si, micronewton_second, dim::momentum_t, prefix::micro);
implement_unit(si, si, millinewton_second, dim::momentum_t, prefix::milli);
implement_unit(si, si, centinewton_second, dim::momentum_t, prefix::centi);
implement_unit(si, si, decinewton_second, dim::momentum_t, prefix::deci);
implement_unit(si, si, newton_second, dim::momentum_t, prefix::one);
implement_unit(si, si, decanewton_second, dim::momentum_t, prefix::deca);
implement_unit(si, si, hectonewton_second, dim::momentum_t, prefix::hecto);
implement_unit(si, si, kilonewton_second, dim::momentum_t, prefix::kilo);
implement_unit(si, si, meganewton_second, dim::momentum_t, prefix::mega);
implement_unit(si, si, giganewton_second, dim::momentum_t, prefix::giga);
implement_unit(si, si, teranewton_second, dim::momentum_t, prefix::tera);
implement_unit(si, si, petanewton_second, dim::momentum_t, prefix::peta);
implement_unit(si, si, exanewton_second, dim::momentum_t, prefix::exa);
implement_unit(si, si, zettanewton_second, dim::momentum_t, prefix::zetta);
implement_unit(si, si, yottanewton_second, dim::momentum_t, prefix::yotta);
#pragma endregion
#pragma region newton minute(momentum)
implement_unit(si, si, yoctonewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yocto>));
implement_unit(si, si, zeptonewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zepto>));
implement_unit(si, si, attonewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::atto>));
implement_unit(si, si, femtonewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::femto>));
implement_unit(si, si, piconewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::pico>));
implement_unit(si, si, nanonewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::nano>));
implement_unit(si, si, micronewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::micro>));
implement_unit(si, si, millinewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::milli>));
implement_unit(si, si, centinewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::centi>));
implement_unit(si, si, decinewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deci>));
implement_unit(si, si, newton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::one>));
implement_unit(si, si, decanewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deca>));
implement_unit(si, si, hectonewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::hecto>));
implement_unit(si, si, kilonewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::kilo>));
implement_unit(si, si, meganewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::mega>));
implement_unit(si, si, giganewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::giga>));
implement_unit(si, si, teranewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::tera>));
implement_unit(si, si, petanewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::peta>));
implement_unit(si, si, exanewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::exa>));
implement_unit(si, si, zettanewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zetta>));
implement_unit(si, si, yottanewton_minute, dim::momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yotta>));
#pragma endregion
#pragma region newton hour(momentum)
implement_unit(si, si, yoctonewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yocto>));
implement_unit(si, si, zeptonewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zepto>));
implement_unit(si, si, attonewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::atto>));
implement_unit(si, si, femtonewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::femto>));
implement_unit(si, si, piconewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::pico>));
implement_unit(si, si, nanonewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::nano>));
implement_unit(si, si, micronewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::micro>));
implement_unit(si, si, millinewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::milli>));
implement_unit(si, si, centinewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::centi>));
implement_unit(si, si, decinewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deci>));
implement_unit(si, si, newton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::one>));
implement_unit(si, si, decanewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deca>));
implement_unit(si, si, hectonewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::hecto>));
implement_unit(si, si, kilonewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::kilo>));
implement_unit(si, si, meganewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::mega>));
implement_unit(si, si, giganewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::giga>));
implement_unit(si, si, teranewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::tera>));
implement_unit(si, si, petanewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::peta>));
implement_unit(si, si, exanewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::exa>));
implement_unit(si, si, zettanewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zetta>));
implement_unit(si, si, yottanewton_hour, dim::momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yotta>));
#pragma endregion
#pragma region newton metre second per radian(angular momentum)
implement_unit(si, si, yoctonewton_metre_second_per_radian, dim::angular_momentum_t, prefix::yocto);
implement_unit(si, si, zeptonewton_metre_second_per_radian, dim::angular_momentum_t, prefix::zepto);
implement_unit(si, si, attonewton_metre_second_per_radian, dim::angular_momentum_t, prefix::atto);
implement_unit(si, si, femtonewton_metre_second_per_radian, dim::angular_momentum_t, prefix::femto);
implement_unit(si, si, piconewton_metre_second_per_radian, dim::angular_momentum_t, prefix::pico);
implement_unit(si, si, nanonewton_metre_second_per_radian, dim::angular_momentum_t, prefix::nano);
implement_unit(si, si, micronewton_metre_second_per_radian, dim::angular_momentum_t, prefix::micro);
implement_unit(si, si, millinewton_metre_second_per_radian, dim::angular_momentum_t, prefix::milli);
implement_unit(si, si, centinewton_metre_second_per_radian, dim::angular_momentum_t, prefix::centi);
implement_unit(si, si, decinewton_metre_second_per_radian, dim::angular_momentum_t, prefix::deci);
implement_unit(si, si, newton_metre_second_per_radian, dim::angular_momentum_t, prefix::one);
implement_unit(si, si, decanewton_metre_second_per_radian, dim::angular_momentum_t, prefix::deca);
implement_unit(si, si, hectonewton_metre_second_per_radian, dim::angular_momentum_t, prefix::hecto);
implement_unit(si, si, kilonewton_metre_second_per_radian, dim::angular_momentum_t, prefix::kilo);
implement_unit(si, si, meganewton_metre_second_per_radian, dim::angular_momentum_t, prefix::mega);
implement_unit(si, si, giganewton_metre_second_per_radian, dim::angular_momentum_t, prefix::giga);
implement_unit(si, si, teranewton_metre_second_per_radian, dim::angular_momentum_t, prefix::tera);
implement_unit(si, si, petanewton_metre_second_per_radian, dim::angular_momentum_t, prefix::peta);
implement_unit(si, si, exanewton_metre_second_per_radian, dim::angular_momentum_t, prefix::exa);
implement_unit(si, si, zettanewton_metre_second_per_radian, dim::angular_momentum_t, prefix::zetta);
implement_unit(si, si, yottanewton_metre_second_per_radian, dim::angular_momentum_t, prefix::yotta);
#pragma endregion
#pragma region newton metre minute per radian(angular momentum)
implement_unit(si, si, yoctonewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yocto>));
implement_unit(si, si, zeptonewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zepto>));
implement_unit(si, si, attonewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::atto>));
implement_unit(si, si, femtonewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::femto>));
implement_unit(si, si, piconewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::pico>));
implement_unit(si, si, nanonewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::nano>));
implement_unit(si, si, micronewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::micro>));
implement_unit(si, si, millinewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::milli>));
implement_unit(si, si, centinewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::centi>));
implement_unit(si, si, decinewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deci>));
implement_unit(si, si, newton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::one>));
implement_unit(si, si, decanewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::deca>));
implement_unit(si, si, hectonewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::hecto>));
implement_unit(si, si, kilonewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::kilo>));
implement_unit(si, si, meganewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::mega>));
implement_unit(si, si, giganewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::giga>));
implement_unit(si, si, teranewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::tera>));
implement_unit(si, si, petanewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::peta>));
implement_unit(si, si, exanewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::exa>));
implement_unit(si, si, zettanewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::zetta>));
implement_unit(si, si, yottanewton_metre_minute_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::minute, prefix::yotta>));
#pragma endregion
#pragma region newton metre hour per radian(angular momentum)
implement_unit(si, si, yoctonewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yocto>));
implement_unit(si, si, zeptonewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zepto>));
implement_unit(si, si, attonewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::atto>));
implement_unit(si, si, femtonewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::femto>));
implement_unit(si, si, piconewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::pico>));
implement_unit(si, si, nanonewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::nano>));
implement_unit(si, si, micronewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::micro>));
implement_unit(si, si, millinewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::milli>));
implement_unit(si, si, centinewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::centi>));
implement_unit(si, si, decinewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deci>));
implement_unit(si, si, newton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::one>));
implement_unit(si, si, decanewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::deca>));
implement_unit(si, si, hectonewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::hecto>));
implement_unit(si, si, kilonewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::kilo>));
implement_unit(si, si, meganewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::mega>));
implement_unit(si, si, giganewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::giga>));
implement_unit(si, si, teranewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::tera>));
implement_unit(si, si, petanewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::peta>));
implement_unit(si, si, exanewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::exa>));
implement_unit(si, si, zettanewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::zetta>));
implement_unit(si, si, yottanewton_metre_hour_per_radian, dim::angular_momentum_t, fix(impl::multiply_lists_t<prefix::hour, prefix::yotta>));
#pragma endregion
#pragma region square metre kilogram per steradian(moment of inertia)
implement_unit(si, si, square_metre_yoctogram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::yocto, prefix::milli>));
implement_unit(si, si, square_metre_zeptogram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::zepto, prefix::milli>));
implement_unit(si, si, square_metre_attogram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::atto, prefix::milli>));
implement_unit(si, si, square_metre_femtogram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::femto, prefix::milli>));
implement_unit(si, si, square_metre_picogram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::pico, prefix::milli>));
implement_unit(si, si, square_metre_nanogram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::nano, prefix::milli>));
implement_unit(si, si, square_metre_microgram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::micro, prefix::milli>));
implement_unit(si, si, square_metre_milligram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::milli, prefix::milli>));
implement_unit(si, si, square_metre_centigram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::centi, prefix::milli>));
implement_unit(si, si, square_metre_decigram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::deci, prefix::milli>));
implement_unit(si, si, square_metre_gram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::one, prefix::milli>));
implement_unit(si, si, square_metre_decagram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::deca, prefix::milli>));
implement_unit(si, si, square_metre_hectogram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::hecto, prefix::milli>));
implement_unit(si, si, square_metre_kilogram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::kilo, prefix::milli>));
implement_unit(si, si, square_metre_megagram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::mega, prefix::milli>));
link_unit(square_metre_tonne_per_steradian, square_metre_megagram_per_steradian);
implement_unit(si, si, square_metre_gigagram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::giga, prefix::milli>));
link_unit(square_metre_kilotonne_per_steradian, square_metre_gigagram_per_steradian);
implement_unit(si, si, square_metre_teragram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::tera, prefix::milli>));
link_unit(square_metre_megatonne_per_steradian, square_metre_teragram_per_steradian);
implement_unit(si, si, square_metre_petagram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::peta, prefix::milli>));
link_unit(square_metre_gigatonne_per_steradian, square_metre_petagram_per_steradian);
implement_unit(si, si, square_metre_exagram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::exa, prefix::milli>));
implement_unit(si, si, square_metre_zettagram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::zetta, prefix::milli>));
implement_unit(si, si, square_metre_yottagram_per_steradian, dim::moment_of_inertia_t, fix(impl::multiply_lists_t<prefix::yotta, prefix::milli>));
#pragma endregion
#pragma endregion
#pragma region special units for the constants
#pragma region joule per tesla(bohr magneton)
implement_unit(si, si, yoctojoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::yocto);
implement_unit(si, si, zeptojoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::zepto);
implement_unit(si, si, attojoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::atto);
implement_unit(si, si, femtojoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::femto);
implement_unit(si, si, picojoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::pico);
implement_unit(si, si, nanojoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::nano);
implement_unit(si, si, microjoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::micro);
implement_unit(si, si, millijoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::milli);
implement_unit(si, si, centijoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::centi);
implement_unit(si, si, decijoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::deci);
implement_unit(si, si, joule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::one);
implement_unit(si, si, decajoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::deca);
implement_unit(si, si, hectojoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::hecto);
implement_unit(si, si, kilojoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::kilo);
implement_unit(si, si, megajoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::mega);
implement_unit(si, si, gigajoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::giga);
implement_unit(si, si, terajoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::tera);
implement_unit(si, si, petajoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::peta);
implement_unit(si, si, exajoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::exa);
implement_unit(si, si, zettajoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::zetta);
implement_unit(si, si, yottajoule_per_tesla, fix(impl::divide_lists_t<dim::energy_t, dim::magnetic_flux_density_t>), prefix::yotta);
#pragma endregion
#pragma region one per mole(avogadro constant)
implement_unit(si, si, one_per_yoctomole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::yocto>));
implement_unit(si, si, one_per_zeptomole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::zepto>));
implement_unit(si, si, one_per_attomole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::atto>));
implement_unit(si, si, one_per_femtomole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::femto>));
implement_unit(si, si, one_per_picomole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::pico>));
implement_unit(si, si, one_per_nanomole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::nano>));
implement_unit(si, si, one_per_micromole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::micro>));
implement_unit(si, si, one_per_millimole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::milli>));
implement_unit(si, si, one_per_centimole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::centi>));
implement_unit(si, si, one_per_decimole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::deci>));
implement_unit(si, si, one_per_mole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::one>));
implement_unit(si, si, one_per_decamole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::deca>));
implement_unit(si, si, one_per_hectomole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::hecto>));
implement_unit(si, si, one_per_kilomole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::kilo>));
implement_unit(si, si, one_per_megamole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::mega>));
implement_unit(si, si, one_per_gigamole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::giga>));
implement_unit(si, si, one_per_teramole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::tera>));
implement_unit(si, si, one_per_petamole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::peta>));
implement_unit(si, si, one_per_examole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::exa>));
implement_unit(si, si, one_per_zettamole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::zetta>));
implement_unit(si, si, one_per_yottamole, fix(impl::divide_lists_t<dim::dimensionless_t, dim::amount_of_substance_t>), fix(impl::divide_lists_t<prefix::one, prefix::yotta>));
#pragma endregion
#pragma region coulomb per mole(faraday constant)
implement_unit(si, si, yoctocoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::yocto);
implement_unit(si, si, zeptocoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::zepto);
implement_unit(si, si, attocoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::atto);
implement_unit(si, si, femtocoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::femto);
implement_unit(si, si, picocoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::pico);
implement_unit(si, si, nanocoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::nano);
implement_unit(si, si, microcoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::micro);
implement_unit(si, si, millicoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::milli);
implement_unit(si, si, centicoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::centi);
implement_unit(si, si, decicoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::deci);
implement_unit(si, si, coulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::one);
implement_unit(si, si, decacoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::deca);
implement_unit(si, si, hectocoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::hecto);
implement_unit(si, si, kilocoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::kilo);
implement_unit(si, si, megacoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::mega);
implement_unit(si, si, gigacoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::giga);
implement_unit(si, si, teracoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::tera);
implement_unit(si, si, petacoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::peta);
implement_unit(si, si, exacoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::exa);
implement_unit(si, si, zettacoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::zetta);
implement_unit(si, si, yottacoulomb_per_mole, fix(impl::divide_lists_t<dim::electric_charge_t, dim::amount_of_substance_t>), prefix::yotta);
#pragma endregion
#pragma region hertz per volt(josephson constant)
implement_unit(si, si, yoctohertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::yocto);
implement_unit(si, si, zeptohertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::zepto);
implement_unit(si, si, attohertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::atto);
implement_unit(si, si, femtohertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::femto);
implement_unit(si, si, picohertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::pico);
implement_unit(si, si, nanohertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::nano);
implement_unit(si, si, microhertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::micro);
implement_unit(si, si, millihertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::milli);
implement_unit(si, si, centihertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::centi);
implement_unit(si, si, decihertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::deci);
implement_unit(si, si, hertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::one);
implement_unit(si, si, decahertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::deca);
implement_unit(si, si, hectohertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::hecto);
implement_unit(si, si, kilohertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::kilo);
implement_unit(si, si, megahertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::mega);
implement_unit(si, si, gigahertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::giga);
implement_unit(si, si, terahertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::tera);
implement_unit(si, si, petahertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::peta);
implement_unit(si, si, exahertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::exa);
implement_unit(si, si, zettahertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::zetta);
implement_unit(si, si, yottahertz_per_volt, fix(impl::divide_lists_t<dim::dimensionless_t, dim::magnetic_flux_t>), prefix::yotta);
#pragma endregion
#pragma region newton per square metre kilogram(gravitational constant)
implement_unit(si, si, yoctonewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::yocto);
implement_unit(si, si, zeptonewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::zepto);
implement_unit(si, si, attonewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::atto);
implement_unit(si, si, femtonewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::femto);
implement_unit(si, si, piconewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::pico);
implement_unit(si, si, nanonewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::nano);
implement_unit(si, si, micronewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::micro);
implement_unit(si, si, millinewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::milli);
implement_unit(si, si, centinewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::centi);
implement_unit(si, si, decinewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::deci);
implement_unit(si, si, newton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::one);
implement_unit(si, si, decanewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::deca);
implement_unit(si, si, hectonewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::hecto);
implement_unit(si, si, kilonewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::kilo);
implement_unit(si, si, meganewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::mega);
implement_unit(si, si, giganewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::giga);
implement_unit(si, si, teranewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::tera);
implement_unit(si, si, petanewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::peta);
implement_unit(si, si, exanewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::exa);
implement_unit(si, si, zettanewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::zetta);
implement_unit(si, si, yottanewton_square_metre_per_square_kilogram, fix(impl::multiply_lists_t<dim::force_t, impl::divide_lists_t<dim::area_t, impl::multiply_lists_t<dim::mass_t, dim::mass_t>>>), prefix::yotta);
#pragma endregion
#pragma region watt per square metre quartic kelvin steradian(stefan - boltzmann constant)
implement_unit(si, si, yoctowatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::yocto);
implement_unit(si, si, zeptowatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::zepto);
implement_unit(si, si, attowatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::atto);
implement_unit(si, si, femtowatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::femto);
implement_unit(si, si, picowatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::pico);
implement_unit(si, si, nanowatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::nano);
implement_unit(si, si, microwatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::micro);
implement_unit(si, si, milliwatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::milli);
implement_unit(si, si, centiwatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::centi);
implement_unit(si, si, deciwatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::deci);
implement_unit(si, si, watt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::one);
implement_unit(si, si, decawatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::deca);
implement_unit(si, si, hectowatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::hecto);
implement_unit(si, si, kilowatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::kilo);
implement_unit(si, si, megawatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::mega);
implement_unit(si, si, gigawatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::giga);
implement_unit(si, si, terawatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::tera);
implement_unit(si, si, petawatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::peta);
implement_unit(si, si, exawatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::exa);
implement_unit(si, si, zettawatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::zetta);
implement_unit(si, si, yottawatt_per_square_metre_quartic_kelvin_steradian, fix(impl::divide_lists_t<dim::power_t, impl::multiply_lists_t<dim::area_t, impl::multiply_lists_t<impl::multiply_lists_t<impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>, impl::multiply_lists_t<dim::thermodynamic_temperature_t, dim::thermodynamic_temperature_t>>, dim::solid_angle_t>>>), prefix::yotta);
#pragma endregion
#pragma endregion
#pragma region constants
namespace constant
{
using namespace benri::si::base;
#pragma region physical constants
create_constant(speed_of_light, prefix::speed_of_light_v, metre_per_second_t);
create_constant(magnetic_constant, prefix::magnetic_constant_v, henry_per_metre_t);
create_constant(electric_constant, prefix::electric_constant_v, farad_per_metre_t);
create_constant(gravitational_constant, prefix::gravitational_constant_v, newton_square_metre_per_square_kilogram_t);
create_constant(planck_constant, prefix::planck_constant_v, joule_second_t);
create_constant(reduced_planck_constant, prefix::reduced_planck_constant_v, joule_second_t);
create_constant(elementary_charge, prefix::elementary_charge_v, coulomb_t);
create_constant(fine_structure_constant, prefix::fine_structure_constant_v, one_t);
create_constant(inverse_fine_structure_constant, prefix::inverse_fine_structure_constant_v, one_t);
create_constant(electron_mass, prefix::electron_mass_v, kilogram_t);
create_constant(proton_mass, prefix::proton_mass_v, kilogram_t);
create_constant(muon_mass, prefix::muon_mass_v, kilogram_t);
create_constant(tau_mass, prefix::tau_mass_v, kilogram_t);
create_constant(neutron_mass, prefix::neutron_mass_v, kilogram_t);
create_constant(deuteron_mass, prefix::deuteron_mass_v, kilogram_t);
create_constant(triton_mass, prefix::triton_mass_v, kilogram_t);
create_constant(helion_mass, prefix::helion_mass_v, kilogram_t);
create_constant(alpha_particle_mass, prefix::alpha_particle_mass_v, kilogram_t);
create_constant(rydberg_constant, prefix::rydberg_constant_v, one_per_metre_t);
create_constant(bohr_radius, prefix::bohr_radius_v, metre_t);
create_constant(bohr_magneton, prefix::bohr_magneton_v, joule_per_tesla_t);
create_constant(avogadro_constant, prefix::avogadro_constant_v, one_per_mole_t);
create_constant(faraday_constant, prefix::faraday_constant_v, coulomb_per_mole_t);
create_constant(molar_gas_constant, prefix::molar_gas_constant_v, joule_per_mole_kelvin_t);
create_constant(boltzmann_constant, prefix::boltzmann_constant_v, joule_per_kelvin_t);
create_constant(stefan_boltzmann_constant, prefix::stefan_boltzmann_constant_v, watt_per_square_metre_quartic_kelvin_steradian_t);
create_constant(magnetic_flux_quantum, prefix::magnetic_flux_quantum_v, weber_t);
create_constant(josephson_constant, prefix::josephson_constant_v, hertz_per_volt_t);
create_constant(von_klitzing_constant, prefix::von_klitzing_constant_v, ohm_t);
create_constant(atomic_mass_unit, prefix::atomic_mass_unit_v, kilogram_t);
create_constant(hartree_energy, prefix::hartree_energy_v, joule_t);
create_constant(conductance_quantum, prefix::conductance_quantum_v, siemens_t);
create_constant(inverse_conductance_quantum, prefix::inverse_conductance_quantum_v, ohm_t);
create_constant(vacuum_impedance, prefix::vacuum_impedance_v, ohm_t);
create_constant(nuclear_magneton, prefix::nuclear_magneton_v, joule_per_tesla_t);
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