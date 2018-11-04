#pragma once
#include <benri/si/system.h>
#include <benri/units/dimensions.h>
#include <benri/units/macros.h>
#include <benri/units/prefix.h>

namespace benri
{
namespace si
{
namespace base
{
#pragma region metre(length)
implement_subunit(si, si, base, yoctometre, _yoctometre, dim::length_t, prefix::yocto);
implement_subunit(si, si, base, zeptometre, _zeptometre, dim::length_t, prefix::zepto);
implement_subunit(si, si, base, attometre, _attometre, dim::length_t, prefix::atto);
implement_subunit(si, si, base, femtometre, _femtometre, dim::length_t, prefix::femto);
implement_subunit(si, si, base, picometre, _picometre, dim::length_t, prefix::pico);
implement_subunit(si, si, base, nanometre, _nanometre, dim::length_t, prefix::nano);
implement_subunit(si, si, base, micrometre, _micrometre, dim::length_t, prefix::micro);
implement_subunit(si, si, base, millimetre, _millimetre, dim::length_t, prefix::milli);
implement_subunit(si, si, base, centimetre, _centimetre, dim::length_t, prefix::centi);
implement_subunit(si, si, base, decimetre, _decimetre, dim::length_t, prefix::deci);
implement_subunit(si, si, base, metre, _metre, dim::length_t, prefix::one);
implement_subunit(si, si, base, decametre, _decametre, dim::length_t, prefix::deca);
implement_subunit(si, si, base, hectometre, _hectometre, dim::length_t, prefix::hecto);
implement_subunit(si, si, base, kilometre, _kilometre, dim::length_t, prefix::kilo);
implement_subunit(si, si, base, megametre, _megametre, dim::length_t, prefix::mega);
implement_subunit(si, si, base, gigametre, _gigametre, dim::length_t, prefix::giga);
implement_subunit(si, si, base, terametre, _terametre, dim::length_t, prefix::tera);
implement_subunit(si, si, base, petametre, _petametre, dim::length_t, prefix::peta);
implement_subunit(si, si, base, exametre, _exametre, dim::length_t, prefix::exa);
implement_subunit(si, si, base, zettametre, _zettametre, dim::length_t, prefix::zetta);
implement_subunit(si, si, base, yottametre, _yottametre, dim::length_t, prefix::yotta);
#pragma endregion
#pragma region kilogram(mass)
implement_subunit(si, si, base, yoctogram, _yoctogram, dim::mass_t, fix(impl::multiply_lists_t<prefix::yocto, prefix::milli>));
implement_subunit(si, si, base, zeptogram, _zeptogram, dim::mass_t, fix(impl::multiply_lists_t<prefix::zepto, prefix::milli>));
implement_subunit(si, si, base, attogram, _attogram, dim::mass_t, fix(impl::multiply_lists_t<prefix::atto, prefix::milli>));
implement_subunit(si, si, base, femtogram, _femtogram, dim::mass_t, fix(impl::multiply_lists_t<prefix::femto, prefix::milli>));
implement_subunit(si, si, base, picogram, _picogram, dim::mass_t, fix(impl::multiply_lists_t<prefix::pico, prefix::milli>));
implement_subunit(si, si, base, nanogram, _nanogram, dim::mass_t, fix(impl::multiply_lists_t<prefix::nano, prefix::milli>));
implement_subunit(si, si, base, microgram, _microgram, dim::mass_t, fix(impl::multiply_lists_t<prefix::micro, prefix::milli>));
implement_subunit(si, si, base, milligram, _milligram, dim::mass_t, fix(impl::multiply_lists_t<prefix::milli, prefix::milli>));
implement_subunit(si, si, base, centigram, _centigram, dim::mass_t, fix(impl::multiply_lists_t<prefix::centi, prefix::milli>));
implement_subunit(si, si, base, decigram, _decigram, dim::mass_t, fix(impl::multiply_lists_t<prefix::deci, prefix::milli>));
implement_subunit(si, si, base, gram, _gram, dim::mass_t, fix(impl::multiply_lists_t<prefix::one, prefix::milli>));
implement_subunit(si, si, base, decagram, _decagram, dim::mass_t, fix(impl::multiply_lists_t<prefix::deca, prefix::milli>));
implement_subunit(si, si, base, hectogram, _hectogram, dim::mass_t, fix(impl::multiply_lists_t<prefix::hecto, prefix::milli>));
implement_subunit(si, si, base, kilogram, _kilogram, dim::mass_t, fix(impl::multiply_lists_t<prefix::kilo, prefix::milli>));
implement_subunit(si, si, base, megagram, _megagram, dim::mass_t, fix(impl::multiply_lists_t<prefix::mega, prefix::milli>));
link_unit(tonne, _tonne, megagram);
implement_subunit(si, si, base, gigagram, _gigagram, dim::mass_t, fix(impl::multiply_lists_t<prefix::giga, prefix::milli>));
link_unit(kilotonne, _kilotonne, gigagram);
implement_subunit(si, si, base, teragram, _teragram, dim::mass_t, fix(impl::multiply_lists_t<prefix::tera, prefix::milli>));
link_unit(megatonne, _megatonne, teragram);
implement_subunit(si, si, base, petagram, _petagram, dim::mass_t, fix(impl::multiply_lists_t<prefix::peta, prefix::milli>));
link_unit(gigatonne, _gigatonne, petagram);
implement_subunit(si, si, base, exagram, _exagram, dim::mass_t, fix(impl::multiply_lists_t<prefix::exa, prefix::milli>));
implement_subunit(si, si, base, zettagram, _zettagram, dim::mass_t, fix(impl::multiply_lists_t<prefix::zetta, prefix::milli>));
implement_subunit(si, si, base, yottagram, _yottagram, dim::mass_t, fix(impl::multiply_lists_t<prefix::yotta, prefix::milli>));
#pragma endregion
#pragma region second(time)
implement_subunit(si, si, base, yoctosecond, _yoctosecond, dim::time_t, prefix::yocto);
implement_subunit(si, si, base, zeptosecond, _zeptosecond, dim::time_t, prefix::zepto);
implement_subunit(si, si, base, attosecond, _attosecond, dim::time_t, prefix::atto);
implement_subunit(si, si, base, femtosecond, _femtosecond, dim::time_t, prefix::femto);
implement_subunit(si, si, base, picosecond, _picosecond, dim::time_t, prefix::pico);
implement_subunit(si, si, base, nanosecond, _nanosecond, dim::time_t, prefix::nano);
implement_subunit(si, si, base, microsecond, _microsecond, dim::time_t, prefix::micro);
implement_subunit(si, si, base, millisecond, _millisecond, dim::time_t, prefix::milli);
implement_subunit(si, si, base, centisecond, _centisecond, dim::time_t, prefix::centi);
implement_subunit(si, si, base, decisecond, _decisecond, dim::time_t, prefix::deci);
implement_subunit(si, si, base, second, _second, dim::time_t, prefix::one);
implement_subunit(si, si, base, decasecond, _decasecond, dim::time_t, prefix::deca);
implement_subunit(si, si, base, hectosecond, _hectosecond, dim::time_t, prefix::hecto);
implement_subunit(si, si, base, kilosecond, _kilosecond, dim::time_t, prefix::kilo);
implement_subunit(si, si, base, megasecond, _megasecond, dim::time_t, prefix::mega);
implement_subunit(si, si, base, gigasecond, _gigasecond, dim::time_t, prefix::giga);
implement_subunit(si, si, base, terasecond, _terasecond, dim::time_t, prefix::tera);
implement_subunit(si, si, base, petasecond, _petasecond, dim::time_t, prefix::peta);
implement_subunit(si, si, base, exasecond, _exasecond, dim::time_t, prefix::exa);
implement_subunit(si, si, base, zettasecond, _zettasecond, dim::time_t, prefix::zetta);
implement_subunit(si, si, base, yottasecond, _yottasecond, dim::time_t, prefix::yotta);
#pragma endregion
#pragma region ampere(electric current)
implement_subunit(si, si, base, yoctoampere, _yoctoampere, dim::electric_current_t, prefix::yocto);
implement_subunit(si, si, base, zeptoampere, _zeptoampere, dim::electric_current_t, prefix::zepto);
implement_subunit(si, si, base, attoampere, _attoampere, dim::electric_current_t, prefix::atto);
implement_subunit(si, si, base, femtoampere, _femtoampere, dim::electric_current_t, prefix::femto);
implement_subunit(si, si, base, picoampere, _picoampere, dim::electric_current_t, prefix::pico);
implement_subunit(si, si, base, nanoampere, _nanoampere, dim::electric_current_t, prefix::nano);
implement_subunit(si, si, base, microampere, _microampere, dim::electric_current_t, prefix::micro);
implement_subunit(si, si, base, milliampere, _milliampere, dim::electric_current_t, prefix::milli);
implement_subunit(si, si, base, centiampere, _centiampere, dim::electric_current_t, prefix::centi);
implement_subunit(si, si, base, deciampere, _deciampere, dim::electric_current_t, prefix::deci);
implement_subunit(si, si, base, ampere, _ampere, dim::electric_current_t, prefix::one);
implement_subunit(si, si, base, decaampere, _decaampere, dim::electric_current_t, prefix::deca);
implement_subunit(si, si, base, hectoampere, _hectoampere, dim::electric_current_t, prefix::hecto);
implement_subunit(si, si, base, kiloampere, _kiloampere, dim::electric_current_t, prefix::kilo);
implement_subunit(si, si, base, megaampere, _megaampere, dim::electric_current_t, prefix::mega);
implement_subunit(si, si, base, gigaampere, _gigaampere, dim::electric_current_t, prefix::giga);
implement_subunit(si, si, base, teraampere, _teraampere, dim::electric_current_t, prefix::tera);
implement_subunit(si, si, base, petaampere, _petaampere, dim::electric_current_t, prefix::peta);
implement_subunit(si, si, base, exaampere, _exaampere, dim::electric_current_t, prefix::exa);
implement_subunit(si, si, base, zettaampere, _zettaampere, dim::electric_current_t, prefix::zetta);
implement_subunit(si, si, base, yottaampere, _yottaampere, dim::electric_current_t, prefix::yotta);
#pragma endregion
#pragma region kelvin(thermodynamic temperature)
implement_subunit(si, si, base, yoctokelvin, _yoctokelvin, dim::thermodynamic_temperature_t, prefix::yocto);
implement_subunit(si, si, base, zeptokelvin, _zeptokelvin, dim::thermodynamic_temperature_t, prefix::zepto);
implement_subunit(si, si, base, attokelvin, _attokelvin, dim::thermodynamic_temperature_t, prefix::atto);
implement_subunit(si, si, base, femtokelvin, _femtokelvin, dim::thermodynamic_temperature_t, prefix::femto);
implement_subunit(si, si, base, picokelvin, _picokelvin, dim::thermodynamic_temperature_t, prefix::pico);
implement_subunit(si, si, base, nanokelvin, _nanokelvin, dim::thermodynamic_temperature_t, prefix::nano);
implement_subunit(si, si, base, microkelvin, _microkelvin, dim::thermodynamic_temperature_t, prefix::micro);
implement_subunit(si, si, base, millikelvin, _millikelvin, dim::thermodynamic_temperature_t, prefix::milli);
implement_subunit(si, si, base, centikelvin, _centikelvin, dim::thermodynamic_temperature_t, prefix::centi);
implement_subunit(si, si, base, decikelvin, _decikelvin, dim::thermodynamic_temperature_t, prefix::deci);
implement_subunit(si, si, base, kelvin, _kelvin, dim::thermodynamic_temperature_t, prefix::one);
implement_subunit(si, si, base, decakelvin, _decakelvin, dim::thermodynamic_temperature_t, prefix::deca);
implement_subunit(si, si, base, hectokelvin, _hectokelvin, dim::thermodynamic_temperature_t, prefix::hecto);
implement_subunit(si, si, base, kilokelvin, _kilokelvin, dim::thermodynamic_temperature_t, prefix::kilo);
implement_subunit(si, si, base, megakelvin, _megakelvin, dim::thermodynamic_temperature_t, prefix::mega);
implement_subunit(si, si, base, gigakelvin, _gigakelvin, dim::thermodynamic_temperature_t, prefix::giga);
implement_subunit(si, si, base, terakelvin, _terakelvin, dim::thermodynamic_temperature_t, prefix::tera);
implement_subunit(si, si, base, petakelvin, _petakelvin, dim::thermodynamic_temperature_t, prefix::peta);
implement_subunit(si, si, base, exakelvin, _exakelvin, dim::thermodynamic_temperature_t, prefix::exa);
implement_subunit(si, si, base, zettakelvin, _zettakelvin, dim::thermodynamic_temperature_t, prefix::zetta);
implement_subunit(si, si, base, yottakelvin, _yottakelvin, dim::thermodynamic_temperature_t, prefix::yotta);
#pragma endregion
#pragma region celsius(thermodynamic temperature)
implement_subunit(si, si, base, yoctocelsius, _yoctocelsius, dim::celsius_temperature_t, prefix::yocto);
implement_subunit(si, si, base, zeptocelsius, _zeptocelsius, dim::celsius_temperature_t, prefix::zepto);
implement_subunit(si, si, base, attocelsius, _attocelsius, dim::celsius_temperature_t, prefix::atto);
implement_subunit(si, si, base, femtocelsius, _femtocelsius, dim::celsius_temperature_t, prefix::femto);
implement_subunit(si, si, base, picocelsius, _picocelsius, dim::celsius_temperature_t, prefix::pico);
implement_subunit(si, si, base, nanocelsius, _nanocelsius, dim::celsius_temperature_t, prefix::nano);
implement_subunit(si, si, base, microcelsius, _microcelsius, dim::celsius_temperature_t, prefix::micro);
implement_subunit(si, si, base, millicelsius, _millicelsius, dim::celsius_temperature_t, prefix::milli);
implement_subunit(si, si, base, centicelsius, _centicelsius, dim::celsius_temperature_t, prefix::centi);
implement_subunit(si, si, base, decicelsius, _decicelsius, dim::celsius_temperature_t, prefix::deci);
implement_subunit(si, si, base, celsius, _celsius, dim::celsius_temperature_t, prefix::one);
implement_subunit(si, si, base, decacelsius, _decacelsius, dim::celsius_temperature_t, prefix::deca);
implement_subunit(si, si, base, hectocelsius, _hectocelsius, dim::celsius_temperature_t, prefix::hecto);
implement_subunit(si, si, base, kilocelsius, _kilocelsius, dim::celsius_temperature_t, prefix::kilo);
implement_subunit(si, si, base, megacelsius, _megacelsius, dim::celsius_temperature_t, prefix::mega);
implement_subunit(si, si, base, gigacelsius, _gigacelsius, dim::celsius_temperature_t, prefix::giga);
implement_subunit(si, si, base, teracelsius, _teracelsius, dim::celsius_temperature_t, prefix::tera);
implement_subunit(si, si, base, petacelsius, _petacelsius, dim::celsius_temperature_t, prefix::peta);
implement_subunit(si, si, base, exacelsius, _exacelsius, dim::celsius_temperature_t, prefix::exa);
implement_subunit(si, si, base, zettacelsius, _zettacelsius, dim::celsius_temperature_t, prefix::zetta);
implement_subunit(si, si, base, yottacelsius, _yottacelsius, dim::celsius_temperature_t, prefix::yotta);
} // namespace base
} // namespace si
template <class System, class lhsDimensions, class rhsDimensions, class Prefix>
struct is_compatible_impl<System, lhsDimensions, Prefix, System, rhsDimensions, Prefix, std::enable_if_t<(impl::is_equivalent_list_v<lhsDimensions, dim::celsius_temperature_t> && impl::is_equivalent_list_v<rhsDimensions, dim::thermodynamic_temperature_t>) || (impl::is_equivalent_list_v<lhsDimensions, dim::thermodynamic_temperature_t> && impl::is_equivalent_list_v<rhsDimensions, dim::celsius_temperature_t>)>> : std::true_type
{
};
namespace si
{
namespace base
{
#pragma endregion
#pragma region rankine(thermodynamic temperature)
implement_subunit(si, si, base, yoctorankine, _yoctorankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::yocto, prefix::rankine_t>));
implement_subunit(si, si, base, zeptorankine, _zeptorankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::zepto, prefix::rankine_t>));
implement_subunit(si, si, base, attorankine, _attorankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::atto, prefix::rankine_t>));
implement_subunit(si, si, base, femtorankine, _femtorankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::femto, prefix::rankine_t>));
implement_subunit(si, si, base, picorankine, _picorankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::pico, prefix::rankine_t>));
implement_subunit(si, si, base, nanorankine, _nanorankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::nano, prefix::rankine_t>));
implement_subunit(si, si, base, microrankine, _microrankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::micro, prefix::rankine_t>));
implement_subunit(si, si, base, millirankine, _millirankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::milli, prefix::rankine_t>));
implement_subunit(si, si, base, centirankine, _centirankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::centi, prefix::rankine_t>));
implement_subunit(si, si, base, decirankine, _decirankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::deci, prefix::rankine_t>));
implement_subunit(si, si, base, rankine, _rankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::one, prefix::rankine_t>));
implement_subunit(si, si, base, decarankine, _decarankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::deca, prefix::rankine_t>));
implement_subunit(si, si, base, hectorankine, _hectorankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::hecto, prefix::rankine_t>));
implement_subunit(si, si, base, kilorankine, _kilorankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::kilo, prefix::rankine_t>));
implement_subunit(si, si, base, megarankine, _megarankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::mega, prefix::rankine_t>));
implement_subunit(si, si, base, gigarankine, _gigarankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::giga, prefix::rankine_t>));
implement_subunit(si, si, base, terarankine, _terarankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::tera, prefix::rankine_t>));
implement_subunit(si, si, base, petarankine, _petarankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::peta, prefix::rankine_t>));
implement_subunit(si, si, base, exarankine, _exarankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::exa, prefix::rankine_t>));
implement_subunit(si, si, base, zettarankine, _zettarankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::zetta, prefix::rankine_t>));
implement_subunit(si, si, base, yottarankine, _yottarankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::yotta, prefix::rankine_t>));
#pragma endregion
#pragma region fahrenheit(thermodynamic temperature)
implement_subunit(si, si, base, yoctofahrenheit, _yoctofahrenheit, dim::fahrenheit_temperature_t, prefix::yocto);
implement_subunit(si, si, base, zeptofahrenheit, _zeptofahrenheit, dim::fahrenheit_temperature_t, prefix::zepto);
implement_subunit(si, si, base, attofahrenheit, _attofahrenheit, dim::fahrenheit_temperature_t, prefix::atto);
implement_subunit(si, si, base, femtofahrenheit, _femtofahrenheit, dim::fahrenheit_temperature_t, prefix::femto);
implement_subunit(si, si, base, picofahrenheit, _picofahrenheit, dim::fahrenheit_temperature_t, prefix::pico);
implement_subunit(si, si, base, nanofahrenheit, _nanofahrenheit, dim::fahrenheit_temperature_t, prefix::nano);
implement_subunit(si, si, base, microfahrenheit, _microfahrenheit, dim::fahrenheit_temperature_t, prefix::micro);
implement_subunit(si, si, base, millifahrenheit, _millifahrenheit, dim::fahrenheit_temperature_t, prefix::milli);
implement_subunit(si, si, base, centifahrenheit, _centifahrenheit, dim::fahrenheit_temperature_t, prefix::centi);
implement_subunit(si, si, base, decifahrenheit, _decifahrenheit, dim::fahrenheit_temperature_t, prefix::deci);
implement_subunit(si, si, base, fahrenheit, _fahrenheit, dim::fahrenheit_temperature_t, prefix::one);
implement_subunit(si, si, base, decafahrenheit, _decafahrenheit, dim::fahrenheit_temperature_t, prefix::deca);
implement_subunit(si, si, base, hectofahrenheit, _hectofahrenheit, dim::fahrenheit_temperature_t, prefix::hecto);
implement_subunit(si, si, base, kilofahrenheit, _kilofahrenheit, dim::fahrenheit_temperature_t, prefix::kilo);
implement_subunit(si, si, base, megafahrenheit, _megafahrenheit, dim::fahrenheit_temperature_t, prefix::mega);
implement_subunit(si, si, base, gigafahrenheit, _gigafahrenheit, dim::fahrenheit_temperature_t, prefix::giga);
implement_subunit(si, si, base, terafahrenheit, _terafahrenheit, dim::fahrenheit_temperature_t, prefix::tera);
implement_subunit(si, si, base, petafahrenheit, _petafahrenheit, dim::fahrenheit_temperature_t, prefix::peta);
implement_subunit(si, si, base, exafahrenheit, _exafahrenheit, dim::fahrenheit_temperature_t, prefix::exa);
implement_subunit(si, si, base, zettafahrenheit, _zettafahrenheit, dim::fahrenheit_temperature_t, prefix::zetta);
implement_subunit(si, si, base, yottafahrenheit, _yottafahrenheit, dim::fahrenheit_temperature_t, prefix::yotta);
} // namespace base
} // namespace si
template <class System, class lhsDimensions, class lhsPrefix, class rhsDimensions, class rhsPrefix>
struct is_compatible_impl<System, lhsDimensions, lhsPrefix, System, rhsDimensions, rhsPrefix, std::enable_if_t<((impl::is_equivalent_list_v<lhsDimensions, dim::fahrenheit_temperature_t> && impl::is_equivalent_list_v<rhsDimensions, dim::thermodynamic_temperature_t>) || (impl::is_equivalent_list_v<lhsDimensions, dim::thermodynamic_temperature_t> && impl::is_equivalent_list_v<rhsDimensions, dim::fahrenheit_temperature_t>)) && ((impl::is_equivalent_list_v<lhsPrefix, impl::multiply_lists_t<rhsPrefix, prefix::rankine_t>>) || (impl::is_equivalent_list_v<impl::multiply_lists_t<lhsPrefix, prefix::rankine_t>, rhsPrefix>))>> : std::true_type
{
};
namespace si
{
namespace base
{
#pragma endregion
#pragma region degree_kelvin(thermodynamic temperature)
link_unit_point(degree_kelvin, _degree_kelvin, kelvin);
#pragma endregion
#pragma region degree celsius(thermodynamic temperature)
link_unit_point(degree_celsius, _degree_celsius, celsius);
#pragma endregion
#pragma region degree_rankine(thermodynamic temperature)
link_unit_point(degree_rankine, _degree_rankine, rankine);
#pragma region degree fahrenheit(thermodynamic temperature)
link_unit_point(degree_fahrenheit, _degree_fahrenheit, fahrenheit);
#pragma endregion
#pragma region simple_cast / unit_cast overloads
//conversion overload (we need an actual overload, because partial function template specialization is not allowed)
//celsius to kelvin
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<degree_celsius, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_kelvin>, quantity_point<degree_kelvin, ValueType>>
{
    return quantity_point<degree_kelvin, ValueType>{rhs.value() + static_cast<ValueType>(prefix::absolute_zero::value)};
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<degree_celsius, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_kelvin>, quantity_point<degree_kelvin, ValueType>>
{
    return simple_cast<degree_kelvin>(rhs);
}
//kelvin to celsius
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<degree_kelvin, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_celsius>, quantity_point<degree_celsius, ValueType>>
{
    return quantity_point<degree_celsius, ValueType>{rhs.value() - static_cast<ValueType>(prefix::absolute_zero::value)};
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<degree_kelvin, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_celsius>, quantity_point<degree_celsius, ValueType>>
{
    return simple_cast<degree_celsius>(rhs);
}
//celsius to rankine
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<degree_celsius, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_rankine>, quantity_point<degree_rankine, ValueType>>
{
    return simple_cast<degree_rankine>(simple_cast<degree_kelvin>(rhs));
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<degree_celsius, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_rankine>, quantity_point<degree_rankine, ValueType>>
{
    return simple_cast<degree_rankine>(rhs);
}
//rankine to celsius
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<degree_rankine, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_celsius>, quantity_point<degree_celsius, ValueType>>
{
    return simple_cast<degree_celsius>(simple_cast<degree_kelvin>(rhs));
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<degree_rankine, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_celsius>, quantity_point<degree_celsius, ValueType>>
{
    return simple_cast<degree_celsius>(rhs);
}
//fahrenheit to kelvin
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<degree_fahrenheit, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_kelvin>, quantity_point<degree_kelvin, ValueType>>
{
    return quantity_point<degree_kelvin, ValueType>{(rhs.value() - static_cast<ValueType>(prefix::fahrenheit_zero::value)) / static_cast<ValueType>(prefix::rankine::value)};
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<degree_fahrenheit, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_kelvin>, quantity_point<degree_kelvin, ValueType>>
{
    return simple_cast<degree_kelvin>(rhs);
}
//kelvin to fahrenheit
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<degree_kelvin, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_fahrenheit>, quantity_point<degree_fahrenheit, ValueType>>
{
    return quantity_point<degree_fahrenheit, ValueType>{rhs.value() * static_cast<ValueType>(prefix::rankine::value) + static_cast<ValueType>(prefix::fahrenheit_zero::value)};
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<degree_kelvin, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_fahrenheit>, quantity_point<degree_fahrenheit, ValueType>>
{
    return simple_cast<degree_fahrenheit>(rhs);
}
//fahrenheit to celsius
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<degree_fahrenheit, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_celsius>, quantity_point<degree_celsius, ValueType>>
{
    return simple_cast<degree_celsius>(simple_cast<degree_kelvin>(rhs));
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<degree_fahrenheit, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_celsius>, quantity_point<degree_celsius, ValueType>>
{
    return simple_cast<degree_celsius>(rhs);
}
//celsius to fahrenheit
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<degree_celsius, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_fahrenheit>, quantity_point<degree_fahrenheit, ValueType>>
{
    return simple_cast<degree_fahrenheit>(simple_cast<degree_kelvin>(rhs));
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<degree_celsius, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_fahrenheit>, quantity_point<degree_fahrenheit, ValueType>>
{
    return simple_cast<degree_fahrenheit>(rhs);
}
//fahrenheit to rankine
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<degree_fahrenheit, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_rankine>, quantity_point<degree_rankine, ValueType>>
{
    return simple_cast<degree_rankine>(simple_cast<degree_kelvin>(rhs));
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<degree_fahrenheit, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_rankine>, quantity_point<degree_rankine, ValueType>>
{
    return simple_cast<degree_rankine>(rhs);
}
//rankine to fahrenheit
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<degree_rankine, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_fahrenheit>, quantity_point<degree_fahrenheit, ValueType>>
{
    return simple_cast<degree_fahrenheit>(simple_cast<degree_kelvin>(rhs));
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<degree_rankine, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_fahrenheit>, quantity_point<degree_fahrenheit, ValueType>>
{
    return simple_cast<degree_fahrenheit>(rhs);
}
#pragma endregion
#pragma region mole(amount of substance)
implement_subunit(si, si, base, yoctomole, _yoctomole, dim::amount_of_substance_t, prefix::yocto);
implement_subunit(si, si, base, zeptomole, _zeptomole, dim::amount_of_substance_t, prefix::zepto);
implement_subunit(si, si, base, attomole, _attomole, dim::amount_of_substance_t, prefix::atto);
implement_subunit(si, si, base, femtomole, _femtomole, dim::amount_of_substance_t, prefix::femto);
implement_subunit(si, si, base, picomole, _picomole, dim::amount_of_substance_t, prefix::pico);
implement_subunit(si, si, base, nanomole, _nanomole, dim::amount_of_substance_t, prefix::nano);
implement_subunit(si, si, base, micromole, _micromole, dim::amount_of_substance_t, prefix::micro);
implement_subunit(si, si, base, millimole, _millimole, dim::amount_of_substance_t, prefix::milli);
implement_subunit(si, si, base, centimole, _centimole, dim::amount_of_substance_t, prefix::centi);
implement_subunit(si, si, base, decimole, _decimole, dim::amount_of_substance_t, prefix::deci);
implement_subunit(si, si, base, mole, _mole, dim::amount_of_substance_t, prefix::one);
implement_subunit(si, si, base, decamole, _decamole, dim::amount_of_substance_t, prefix::deca);
implement_subunit(si, si, base, hectomole, _hectomole, dim::amount_of_substance_t, prefix::hecto);
implement_subunit(si, si, base, kilomole, _kilomole, dim::amount_of_substance_t, prefix::kilo);
implement_subunit(si, si, base, megamole, _megamole, dim::amount_of_substance_t, prefix::mega);
implement_subunit(si, si, base, gigamole, _gigamole, dim::amount_of_substance_t, prefix::giga);
implement_subunit(si, si, base, teramole, _teramole, dim::amount_of_substance_t, prefix::tera);
implement_subunit(si, si, base, petamole, _petamole, dim::amount_of_substance_t, prefix::peta);
implement_subunit(si, si, base, examole, _examole, dim::amount_of_substance_t, prefix::exa);
implement_subunit(si, si, base, zettamole, _zettamole, dim::amount_of_substance_t, prefix::zetta);
implement_subunit(si, si, base, yottamole, _yottamole, dim::amount_of_substance_t, prefix::yotta);
#pragma endregion
#pragma region candela(luminous intensity)
implement_subunit(si, si, base, yoctocandela, _yoctocandela, dim::luminous_intensity_t, prefix::yocto);
implement_subunit(si, si, base, zeptocandela, _zeptocandela, dim::luminous_intensity_t, prefix::zepto);
implement_subunit(si, si, base, attocandela, _attocandela, dim::luminous_intensity_t, prefix::atto);
implement_subunit(si, si, base, femtocandela, _femtocandela, dim::luminous_intensity_t, prefix::femto);
implement_subunit(si, si, base, picocandela, _picocandela, dim::luminous_intensity_t, prefix::pico);
implement_subunit(si, si, base, nanocandela, _nanocandela, dim::luminous_intensity_t, prefix::nano);
implement_subunit(si, si, base, microcandela, _microcandela, dim::luminous_intensity_t, prefix::micro);
implement_subunit(si, si, base, millicandela, _millicandela, dim::luminous_intensity_t, prefix::milli);
implement_subunit(si, si, base, centicandela, _centicandela, dim::luminous_intensity_t, prefix::centi);
implement_subunit(si, si, base, decicandela, _decicandela, dim::luminous_intensity_t, prefix::deci);
implement_subunit(si, si, base, candela, _candela, dim::luminous_intensity_t, prefix::one);
implement_subunit(si, si, base, decacandela, _decacandela, dim::luminous_intensity_t, prefix::deca);
implement_subunit(si, si, base, hectocandela, _hectocandela, dim::luminous_intensity_t, prefix::hecto);
implement_subunit(si, si, base, kilocandela, _kilocandela, dim::luminous_intensity_t, prefix::kilo);
implement_subunit(si, si, base, megacandela, _megacandela, dim::luminous_intensity_t, prefix::mega);
implement_subunit(si, si, base, gigacandela, _gigacandela, dim::luminous_intensity_t, prefix::giga);
implement_subunit(si, si, base, teracandela, _teracandela, dim::luminous_intensity_t, prefix::tera);
implement_subunit(si, si, base, petacandela, _petacandela, dim::luminous_intensity_t, prefix::peta);
implement_subunit(si, si, base, exacandela, _exacandela, dim::luminous_intensity_t, prefix::exa);
implement_subunit(si, si, base, zettacandela, _zettacandela, dim::luminous_intensity_t, prefix::zetta);
implement_subunit(si, si, base, yottacandela, _yottacandela, dim::luminous_intensity_t, prefix::yotta);
#pragma endregion
#pragma region radian(plane angle)
implement_subunit(si, si, base, yoctoradian, _yoctoradian, dim::plane_angle_t, prefix::yocto);
implement_subunit(si, si, base, zeptoradian, _zeptoradian, dim::plane_angle_t, prefix::zepto);
implement_subunit(si, si, base, attoradian, _attoradian, dim::plane_angle_t, prefix::atto);
implement_subunit(si, si, base, femtoradian, _femtoradian, dim::plane_angle_t, prefix::femto);
implement_subunit(si, si, base, picoradian, _picoradian, dim::plane_angle_t, prefix::pico);
implement_subunit(si, si, base, nanoradian, _nanoradian, dim::plane_angle_t, prefix::nano);
implement_subunit(si, si, base, microradian, _microradian, dim::plane_angle_t, prefix::micro);
implement_subunit(si, si, base, milliradian, _milliradian, dim::plane_angle_t, prefix::milli);
implement_subunit(si, si, base, centiradian, _centiradian, dim::plane_angle_t, prefix::centi);
implement_subunit(si, si, base, deciradian, _deciradian, dim::plane_angle_t, prefix::deci);
implement_subunit(si, si, base, radian, _radian, dim::plane_angle_t, prefix::one);
implement_subunit(si, si, base, degree, _degree, dim::plane_angle_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 180>>));
implement_subunit(si, si, base, arcminute, _arcminute, dim::plane_angle_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 10800>>));
implement_subunit(si, si, base, arcsecond, _arcsecond, dim::plane_angle_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 648000>>));
#pragma endregion
#pragma region count(number of radioactive events)
implement_subunit(si, si, base, count, _count, dim::number_of_radioactive_events_t, prefix::one);
#pragma endregion
#pragma region sievert per gray(radiation weighting factor)
implement_subunit(si, si, base, sievert_per_gray, _sievert_per_gray, dim::radiation_weighting_factor_t, prefix::one);
#pragma endregion
#pragma region number(dimensionless data)
implement_subunit(si, si, base, one, _one, dim::dimensionless_t, prefix::one);
implement_subunit(si, si, base, percent, _percent, dim::dimensionless_t, prefix::centi);
implement_subunit(si, si, base, permille, _permille, dim::dimensionless_t, prefix::milli);
implement_subunit(si, si, base, parts_per_million, _parts_per_million, dim::dimensionless_t, prefix::micro);
#pragma endregion
} // namespace base
#pragma region constants
namespace constant
{
using namespace benri::si::base;
#pragma region mathematical constants
create_constant(quarter_pi, prefix::quarter_pi_v, one);
create_constant(half_pi, prefix::half_pi_v, one);
create_constant(pi, prefix::pi_v, one);
create_constant(two_pi, prefix::two_pi_v, one);
create_constant(e, prefix::e_v, one);
create_constant(phi, prefix::phi_v, one);
create_constant(gamma, prefix::gamma_v, one);
create_constant(root_two, prefix::root_two_v, one);
#pragma endregion
} // namespace constant
#pragma endregion
#pragma region symbols
namespace symbol
{
#pragma region prefixes
create_symbol(si, yocto, dim::dimensionless_t, prefix::yocto);
create_symbol(si, zepto, dim::dimensionless_t, prefix::zepto);
create_symbol(si, atto, dim::dimensionless_t, prefix::atto);
create_symbol(si, femto, dim::dimensionless_t, prefix::femto);
create_symbol(si, pico, dim::dimensionless_t, prefix::pico);
create_symbol(si, nano, dim::dimensionless_t, prefix::nano);
create_symbol(si, micro, dim::dimensionless_t, prefix::micro);
create_symbol(si, milli, dim::dimensionless_t, prefix::milli);
create_symbol(si, centi, dim::dimensionless_t, prefix::centi);
create_symbol(si, deci, dim::dimensionless_t, prefix::deci);
create_symbol(si, deca, dim::dimensionless_t, prefix::deca);
create_symbol(si, hecto, dim::dimensionless_t, prefix::hecto);
create_symbol(si, kilo, dim::dimensionless_t, prefix::kilo);
create_symbol(si, mega, dim::dimensionless_t, prefix::mega);
create_symbol(si, giga, dim::dimensionless_t, prefix::giga);
create_symbol(si, tera, dim::dimensionless_t, prefix::tera);
create_symbol(si, peta, dim::dimensionless_t, prefix::peta);
create_symbol(si, exa, dim::dimensionless_t, prefix::exa);
create_symbol(si, zetta, dim::dimensionless_t, prefix::zetta);
create_symbol(si, yotta, dim::dimensionless_t, prefix::yotta);
#pragma endregion
#pragma region mathematical constants
create_symbol(si, quarter_pi, dim::dimensionless_t, prefix::quarter_pi_t);
create_symbol(si, half_pi, dim::dimensionless_t, prefix::half_pi_t);
create_symbol(si, pi, dim::dimensionless_t, prefix::pi_t);
create_symbol(si, two_pi, dim::dimensionless_t, prefix::two_pi_t);
create_symbol(si, e, dim::dimensionless_t, prefix::e_t);
create_symbol(si, phi, dim::dimensionless_t, prefix::phi_t);
create_symbol(si, gamma, dim::dimensionless_t, prefix::gamma_t);
create_symbol(si, root_two, dim::dimensionless_t, prefix::root_two_t);
#pragma endregion
} // namespace symbol
#pragma endregion
} // namespace si
} // namespace benri