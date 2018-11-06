#pragma once
#include <benri/quantity.h>
#include <benri/quantity_point.h>
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
implement_subunit(si, si, base, yoctometre, dim::length_t, prefix::yocto);
implement_subunit(si, si, base, zeptometre, dim::length_t, prefix::zepto);
implement_subunit(si, si, base, attometre, dim::length_t, prefix::atto);
implement_subunit(si, si, base, femtometre, dim::length_t, prefix::femto);
implement_subunit(si, si, base, picometre, dim::length_t, prefix::pico);
implement_subunit(si, si, base, nanometre, dim::length_t, prefix::nano);
implement_subunit(si, si, base, micrometre, dim::length_t, prefix::micro);
implement_subunit(si, si, base, millimetre, dim::length_t, prefix::milli);
implement_subunit(si, si, base, centimetre, dim::length_t, prefix::centi);
implement_subunit(si, si, base, decimetre, dim::length_t, prefix::deci);
implement_subunit(si, si, base, metre, dim::length_t, prefix::one);
implement_subunit(si, si, base, decametre, dim::length_t, prefix::deca);
implement_subunit(si, si, base, hectometre, dim::length_t, prefix::hecto);
implement_subunit(si, si, base, kilometre, dim::length_t, prefix::kilo);
implement_subunit(si, si, base, megametre, dim::length_t, prefix::mega);
implement_subunit(si, si, base, gigametre, dim::length_t, prefix::giga);
implement_subunit(si, si, base, terametre, dim::length_t, prefix::tera);
implement_subunit(si, si, base, petametre, dim::length_t, prefix::peta);
implement_subunit(si, si, base, exametre, dim::length_t, prefix::exa);
implement_subunit(si, si, base, zettametre, dim::length_t, prefix::zetta);
implement_subunit(si, si, base, yottametre, dim::length_t, prefix::yotta);
#pragma endregion
#pragma region kilogram(mass)
implement_subunit(si, si, base, yoctogram, dim::mass_t, fix(impl::multiply_lists_t<prefix::yocto, prefix::milli>));
implement_subunit(si, si, base, zeptogram, dim::mass_t, fix(impl::multiply_lists_t<prefix::zepto, prefix::milli>));
implement_subunit(si, si, base, attogram, dim::mass_t, fix(impl::multiply_lists_t<prefix::atto, prefix::milli>));
implement_subunit(si, si, base, femtogram, dim::mass_t, fix(impl::multiply_lists_t<prefix::femto, prefix::milli>));
implement_subunit(si, si, base, picogram, dim::mass_t, fix(impl::multiply_lists_t<prefix::pico, prefix::milli>));
implement_subunit(si, si, base, nanogram, dim::mass_t, fix(impl::multiply_lists_t<prefix::nano, prefix::milli>));
implement_subunit(si, si, base, microgram, dim::mass_t, fix(impl::multiply_lists_t<prefix::micro, prefix::milli>));
implement_subunit(si, si, base, milligram, dim::mass_t, fix(impl::multiply_lists_t<prefix::milli, prefix::milli>));
implement_subunit(si, si, base, centigram, dim::mass_t, fix(impl::multiply_lists_t<prefix::centi, prefix::milli>));
implement_subunit(si, si, base, decigram, dim::mass_t, fix(impl::multiply_lists_t<prefix::deci, prefix::milli>));
implement_subunit(si, si, base, gram, dim::mass_t, fix(impl::multiply_lists_t<prefix::one, prefix::milli>));
implement_subunit(si, si, base, decagram, dim::mass_t, fix(impl::multiply_lists_t<prefix::deca, prefix::milli>));
implement_subunit(si, si, base, hectogram, dim::mass_t, fix(impl::multiply_lists_t<prefix::hecto, prefix::milli>));
implement_subunit(si, si, base, kilogram, dim::mass_t, fix(impl::multiply_lists_t<prefix::kilo, prefix::milli>));
implement_subunit(si, si, base, megagram, dim::mass_t, fix(impl::multiply_lists_t<prefix::mega, prefix::milli>));
link_unit(tonne, megagram);
implement_subunit(si, si, base, gigagram, dim::mass_t, fix(impl::multiply_lists_t<prefix::giga, prefix::milli>));
link_unit(kilotonne, gigagram);
implement_subunit(si, si, base, teragram, dim::mass_t, fix(impl::multiply_lists_t<prefix::tera, prefix::milli>));
link_unit(megatonne, teragram);
implement_subunit(si, si, base, petagram, dim::mass_t, fix(impl::multiply_lists_t<prefix::peta, prefix::milli>));
link_unit(gigatonne, petagram);
implement_subunit(si, si, base, exagram, dim::mass_t, fix(impl::multiply_lists_t<prefix::exa, prefix::milli>));
implement_subunit(si, si, base, zettagram, dim::mass_t, fix(impl::multiply_lists_t<prefix::zetta, prefix::milli>));
implement_subunit(si, si, base, yottagram, dim::mass_t, fix(impl::multiply_lists_t<prefix::yotta, prefix::milli>));
#pragma endregion
#pragma region second(time)
implement_subunit(si, si, base, yoctosecond, dim::time_t, prefix::yocto);
implement_subunit(si, si, base, zeptosecond, dim::time_t, prefix::zepto);
implement_subunit(si, si, base, attosecond, dim::time_t, prefix::atto);
implement_subunit(si, si, base, femtosecond, dim::time_t, prefix::femto);
implement_subunit(si, si, base, picosecond, dim::time_t, prefix::pico);
implement_subunit(si, si, base, nanosecond, dim::time_t, prefix::nano);
implement_subunit(si, si, base, microsecond, dim::time_t, prefix::micro);
implement_subunit(si, si, base, millisecond, dim::time_t, prefix::milli);
implement_subunit(si, si, base, centisecond, dim::time_t, prefix::centi);
implement_subunit(si, si, base, decisecond, dim::time_t, prefix::deci);
implement_subunit(si, si, base, second, dim::time_t, prefix::one);
implement_subunit(si, si, base, decasecond, dim::time_t, prefix::deca);
implement_subunit(si, si, base, hectosecond, dim::time_t, prefix::hecto);
implement_subunit(si, si, base, kilosecond, dim::time_t, prefix::kilo);
implement_subunit(si, si, base, megasecond, dim::time_t, prefix::mega);
implement_subunit(si, si, base, gigasecond, dim::time_t, prefix::giga);
implement_subunit(si, si, base, terasecond, dim::time_t, prefix::tera);
implement_subunit(si, si, base, petasecond, dim::time_t, prefix::peta);
implement_subunit(si, si, base, exasecond, dim::time_t, prefix::exa);
implement_subunit(si, si, base, zettasecond, dim::time_t, prefix::zetta);
implement_subunit(si, si, base, yottasecond, dim::time_t, prefix::yotta);
#pragma endregion
#pragma region ampere(electric current)
implement_subunit(si, si, base, yoctoampere, dim::electric_current_t, prefix::yocto);
implement_subunit(si, si, base, zeptoampere, dim::electric_current_t, prefix::zepto);
implement_subunit(si, si, base, attoampere, dim::electric_current_t, prefix::atto);
implement_subunit(si, si, base, femtoampere, dim::electric_current_t, prefix::femto);
implement_subunit(si, si, base, picoampere, dim::electric_current_t, prefix::pico);
implement_subunit(si, si, base, nanoampere, dim::electric_current_t, prefix::nano);
implement_subunit(si, si, base, microampere, dim::electric_current_t, prefix::micro);
implement_subunit(si, si, base, milliampere, dim::electric_current_t, prefix::milli);
implement_subunit(si, si, base, centiampere, dim::electric_current_t, prefix::centi);
implement_subunit(si, si, base, deciampere, dim::electric_current_t, prefix::deci);
implement_subunit(si, si, base, ampere, dim::electric_current_t, prefix::one);
implement_subunit(si, si, base, decaampere, dim::electric_current_t, prefix::deca);
implement_subunit(si, si, base, hectoampere, dim::electric_current_t, prefix::hecto);
implement_subunit(si, si, base, kiloampere, dim::electric_current_t, prefix::kilo);
implement_subunit(si, si, base, megaampere, dim::electric_current_t, prefix::mega);
implement_subunit(si, si, base, gigaampere, dim::electric_current_t, prefix::giga);
implement_subunit(si, si, base, teraampere, dim::electric_current_t, prefix::tera);
implement_subunit(si, si, base, petaampere, dim::electric_current_t, prefix::peta);
implement_subunit(si, si, base, exaampere, dim::electric_current_t, prefix::exa);
implement_subunit(si, si, base, zettaampere, dim::electric_current_t, prefix::zetta);
implement_subunit(si, si, base, yottaampere, dim::electric_current_t, prefix::yotta);
#pragma endregion
#pragma region kelvin(thermodynamic temperature)
implement_subunit(si, si, base, yoctokelvin, dim::thermodynamic_temperature_t, prefix::yocto);
implement_subunit(si, si, base, zeptokelvin, dim::thermodynamic_temperature_t, prefix::zepto);
implement_subunit(si, si, base, attokelvin, dim::thermodynamic_temperature_t, prefix::atto);
implement_subunit(si, si, base, femtokelvin, dim::thermodynamic_temperature_t, prefix::femto);
implement_subunit(si, si, base, picokelvin, dim::thermodynamic_temperature_t, prefix::pico);
implement_subunit(si, si, base, nanokelvin, dim::thermodynamic_temperature_t, prefix::nano);
implement_subunit(si, si, base, microkelvin, dim::thermodynamic_temperature_t, prefix::micro);
implement_subunit(si, si, base, millikelvin, dim::thermodynamic_temperature_t, prefix::milli);
implement_subunit(si, si, base, centikelvin, dim::thermodynamic_temperature_t, prefix::centi);
implement_subunit(si, si, base, decikelvin, dim::thermodynamic_temperature_t, prefix::deci);
implement_subunit(si, si, base, kelvin, dim::thermodynamic_temperature_t, prefix::one);
implement_subunit(si, si, base, decakelvin, dim::thermodynamic_temperature_t, prefix::deca);
implement_subunit(si, si, base, hectokelvin, dim::thermodynamic_temperature_t, prefix::hecto);
implement_subunit(si, si, base, kilokelvin, dim::thermodynamic_temperature_t, prefix::kilo);
implement_subunit(si, si, base, megakelvin, dim::thermodynamic_temperature_t, prefix::mega);
implement_subunit(si, si, base, gigakelvin, dim::thermodynamic_temperature_t, prefix::giga);
implement_subunit(si, si, base, terakelvin, dim::thermodynamic_temperature_t, prefix::tera);
implement_subunit(si, si, base, petakelvin, dim::thermodynamic_temperature_t, prefix::peta);
implement_subunit(si, si, base, exakelvin, dim::thermodynamic_temperature_t, prefix::exa);
implement_subunit(si, si, base, zettakelvin, dim::thermodynamic_temperature_t, prefix::zetta);
implement_subunit(si, si, base, yottakelvin, dim::thermodynamic_temperature_t, prefix::yotta);
#pragma endregion
#pragma region celsius(thermodynamic temperature)
implement_subunit(si, si, base, yoctocelsius, dim::celsius_temperature_t, prefix::yocto);
implement_subunit(si, si, base, zeptocelsius, dim::celsius_temperature_t, prefix::zepto);
implement_subunit(si, si, base, attocelsius, dim::celsius_temperature_t, prefix::atto);
implement_subunit(si, si, base, femtocelsius, dim::celsius_temperature_t, prefix::femto);
implement_subunit(si, si, base, picocelsius, dim::celsius_temperature_t, prefix::pico);
implement_subunit(si, si, base, nanocelsius, dim::celsius_temperature_t, prefix::nano);
implement_subunit(si, si, base, microcelsius, dim::celsius_temperature_t, prefix::micro);
implement_subunit(si, si, base, millicelsius, dim::celsius_temperature_t, prefix::milli);
implement_subunit(si, si, base, centicelsius, dim::celsius_temperature_t, prefix::centi);
implement_subunit(si, si, base, decicelsius, dim::celsius_temperature_t, prefix::deci);
implement_subunit(si, si, base, celsius, dim::celsius_temperature_t, prefix::one);
implement_subunit(si, si, base, decacelsius, dim::celsius_temperature_t, prefix::deca);
implement_subunit(si, si, base, hectocelsius, dim::celsius_temperature_t, prefix::hecto);
implement_subunit(si, si, base, kilocelsius, dim::celsius_temperature_t, prefix::kilo);
implement_subunit(si, si, base, megacelsius, dim::celsius_temperature_t, prefix::mega);
implement_subunit(si, si, base, gigacelsius, dim::celsius_temperature_t, prefix::giga);
implement_subunit(si, si, base, teracelsius, dim::celsius_temperature_t, prefix::tera);
implement_subunit(si, si, base, petacelsius, dim::celsius_temperature_t, prefix::peta);
implement_subunit(si, si, base, exacelsius, dim::celsius_temperature_t, prefix::exa);
implement_subunit(si, si, base, zettacelsius, dim::celsius_temperature_t, prefix::zetta);
implement_subunit(si, si, base, yottacelsius, dim::celsius_temperature_t, prefix::yotta);
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
implement_subunit(si, si, base, yoctorankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::yocto, prefix::rankine_t>));
implement_subunit(si, si, base, zeptorankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::zepto, prefix::rankine_t>));
implement_subunit(si, si, base, attorankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::atto, prefix::rankine_t>));
implement_subunit(si, si, base, femtorankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::femto, prefix::rankine_t>));
implement_subunit(si, si, base, picorankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::pico, prefix::rankine_t>));
implement_subunit(si, si, base, nanorankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::nano, prefix::rankine_t>));
implement_subunit(si, si, base, microrankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::micro, prefix::rankine_t>));
implement_subunit(si, si, base, millirankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::milli, prefix::rankine_t>));
implement_subunit(si, si, base, centirankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::centi, prefix::rankine_t>));
implement_subunit(si, si, base, decirankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::deci, prefix::rankine_t>));
implement_subunit(si, si, base, rankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::one, prefix::rankine_t>));
implement_subunit(si, si, base, decarankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::deca, prefix::rankine_t>));
implement_subunit(si, si, base, hectorankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::hecto, prefix::rankine_t>));
implement_subunit(si, si, base, kilorankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::kilo, prefix::rankine_t>));
implement_subunit(si, si, base, megarankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::mega, prefix::rankine_t>));
implement_subunit(si, si, base, gigarankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::giga, prefix::rankine_t>));
implement_subunit(si, si, base, terarankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::tera, prefix::rankine_t>));
implement_subunit(si, si, base, petarankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::peta, prefix::rankine_t>));
implement_subunit(si, si, base, exarankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::exa, prefix::rankine_t>));
implement_subunit(si, si, base, zettarankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::zetta, prefix::rankine_t>));
implement_subunit(si, si, base, yottarankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::yotta, prefix::rankine_t>));
#pragma endregion
#pragma region fahrenheit(thermodynamic temperature)
implement_subunit(si, si, base, yoctofahrenheit, dim::fahrenheit_temperature_t, prefix::yocto);
implement_subunit(si, si, base, zeptofahrenheit, dim::fahrenheit_temperature_t, prefix::zepto);
implement_subunit(si, si, base, attofahrenheit, dim::fahrenheit_temperature_t, prefix::atto);
implement_subunit(si, si, base, femtofahrenheit, dim::fahrenheit_temperature_t, prefix::femto);
implement_subunit(si, si, base, picofahrenheit, dim::fahrenheit_temperature_t, prefix::pico);
implement_subunit(si, si, base, nanofahrenheit, dim::fahrenheit_temperature_t, prefix::nano);
implement_subunit(si, si, base, microfahrenheit, dim::fahrenheit_temperature_t, prefix::micro);
implement_subunit(si, si, base, millifahrenheit, dim::fahrenheit_temperature_t, prefix::milli);
implement_subunit(si, si, base, centifahrenheit, dim::fahrenheit_temperature_t, prefix::centi);
implement_subunit(si, si, base, decifahrenheit, dim::fahrenheit_temperature_t, prefix::deci);
implement_subunit(si, si, base, fahrenheit, dim::fahrenheit_temperature_t, prefix::one);
implement_subunit(si, si, base, decafahrenheit, dim::fahrenheit_temperature_t, prefix::deca);
implement_subunit(si, si, base, hectofahrenheit, dim::fahrenheit_temperature_t, prefix::hecto);
implement_subunit(si, si, base, kilofahrenheit, dim::fahrenheit_temperature_t, prefix::kilo);
implement_subunit(si, si, base, megafahrenheit, dim::fahrenheit_temperature_t, prefix::mega);
implement_subunit(si, si, base, gigafahrenheit, dim::fahrenheit_temperature_t, prefix::giga);
implement_subunit(si, si, base, terafahrenheit, dim::fahrenheit_temperature_t, prefix::tera);
implement_subunit(si, si, base, petafahrenheit, dim::fahrenheit_temperature_t, prefix::peta);
implement_subunit(si, si, base, exafahrenheit, dim::fahrenheit_temperature_t, prefix::exa);
implement_subunit(si, si, base, zettafahrenheit, dim::fahrenheit_temperature_t, prefix::zetta);
implement_subunit(si, si, base, yottafahrenheit, dim::fahrenheit_temperature_t, prefix::yotta);
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
link_unit_point(degree_kelvin, kelvin);
#pragma endregion
#pragma region degree celsius(thermodynamic temperature)
link_unit_point(degree_celsius, celsius);
#pragma endregion
#pragma region degree_rankine(thermodynamic temperature)
link_unit_point(degree_rankine, rankine);
#pragma region degree fahrenheit(thermodynamic temperature)
link_unit_point(degree_fahrenheit, fahrenheit);
#pragma endregion
#pragma region simple_cast / unit_cast overloads
//conversion overload (we need an actual overload, because partial function template specialization is not allowed)
//celsius to kelvin
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<degree_celsius_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_kelvin_t>, quantity_point<degree_kelvin_t, ValueType>>
{
    return quantity_point<degree_kelvin_t, ValueType>{rhs.value() + static_cast<ValueType>(prefix::absolute_zero::value)};
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<degree_celsius_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_kelvin_t>, quantity_point<degree_kelvin_t, ValueType>>
{
    return simple_cast<degree_kelvin_t>(rhs);
}
//kelvin to celsius
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<degree_kelvin_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_celsius_t>, quantity_point<degree_celsius_t, ValueType>>
{
    return quantity_point<degree_celsius_t, ValueType>{rhs.value() - static_cast<ValueType>(prefix::absolute_zero::value)};
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<degree_kelvin_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_celsius_t>, quantity_point<degree_celsius_t, ValueType>>
{
    return simple_cast<degree_celsius_t>(rhs);
}
//celsius to rankine
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<degree_celsius_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_rankine_t>, quantity_point<degree_rankine_t, ValueType>>
{
    return simple_cast<degree_rankine_t>(simple_cast<degree_kelvin_t>(rhs));
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<degree_celsius_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_rankine_t>, quantity_point<degree_rankine_t, ValueType>>
{
    return simple_cast<degree_rankine_t>(rhs);
}
//rankine to celsius
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<degree_rankine_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_celsius_t>, quantity_point<degree_celsius_t, ValueType>>
{
    return simple_cast<degree_celsius_t>(simple_cast<degree_kelvin_t>(rhs));
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<degree_rankine_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_celsius_t>, quantity_point<degree_celsius_t, ValueType>>
{
    return simple_cast<degree_celsius_t>(rhs);
}
//fahrenheit to kelvin
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<degree_fahrenheit_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_kelvin_t>, quantity_point<degree_kelvin_t, ValueType>>
{
    return quantity_point<degree_kelvin_t, ValueType>{(rhs.value() - static_cast<ValueType>(prefix::fahrenheit_zero::value)) / static_cast<ValueType>(prefix::rankine::value)};
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<degree_fahrenheit_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_kelvin_t>, quantity_point<degree_kelvin_t, ValueType>>
{
    return simple_cast<degree_kelvin_t>(rhs);
}
//kelvin to fahrenheit
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<degree_kelvin_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_fahrenheit_t>, quantity_point<degree_fahrenheit_t, ValueType>>
{
    return quantity_point<degree_fahrenheit_t, ValueType>{rhs.value() * static_cast<ValueType>(prefix::rankine::value) + static_cast<ValueType>(prefix::fahrenheit_zero::value)};
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<degree_kelvin_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_fahrenheit_t>, quantity_point<degree_fahrenheit_t, ValueType>>
{
    return simple_cast<degree_fahrenheit_t>(rhs);
}
//fahrenheit to celsius
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<degree_fahrenheit_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_celsius_t>, quantity_point<degree_celsius_t, ValueType>>
{
    return simple_cast<degree_celsius_t>(simple_cast<degree_kelvin_t>(rhs));
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<degree_fahrenheit_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_celsius_t>, quantity_point<degree_celsius_t, ValueType>>
{
    return simple_cast<degree_celsius_t>(rhs);
}
//celsius to fahrenheit
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<degree_celsius_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_fahrenheit_t>, quantity_point<degree_fahrenheit_t, ValueType>>
{
    return simple_cast<degree_fahrenheit_t>(simple_cast<degree_kelvin_t>(rhs));
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<degree_celsius_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_fahrenheit_t>, quantity_point<degree_fahrenheit_t, ValueType>>
{
    return simple_cast<degree_fahrenheit_t>(rhs);
}
//fahrenheit to rankine
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<degree_fahrenheit_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_rankine_t>, quantity_point<degree_rankine_t, ValueType>>
{
    return simple_cast<degree_rankine_t>(simple_cast<degree_kelvin_t>(rhs));
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<degree_fahrenheit_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_rankine_t>, quantity_point<degree_rankine_t, ValueType>>
{
    return simple_cast<degree_rankine_t>(rhs);
}
//rankine to fahrenheit
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<degree_rankine_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_fahrenheit_t>, quantity_point<degree_fahrenheit_t, ValueType>>
{
    return simple_cast<degree_fahrenheit_t>(simple_cast<degree_kelvin_t>(rhs));
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<degree_rankine_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, degree_fahrenheit_t>, quantity_point<degree_fahrenheit_t, ValueType>>
{
    return simple_cast<degree_fahrenheit_t>(rhs);
}
#pragma endregion
#pragma region mole(amount of substance)
implement_subunit(si, si, base, yoctomole, dim::amount_of_substance_t, prefix::yocto);
implement_subunit(si, si, base, zeptomole, dim::amount_of_substance_t, prefix::zepto);
implement_subunit(si, si, base, attomole, dim::amount_of_substance_t, prefix::atto);
implement_subunit(si, si, base, femtomole, dim::amount_of_substance_t, prefix::femto);
implement_subunit(si, si, base, picomole, dim::amount_of_substance_t, prefix::pico);
implement_subunit(si, si, base, nanomole, dim::amount_of_substance_t, prefix::nano);
implement_subunit(si, si, base, micromole, dim::amount_of_substance_t, prefix::micro);
implement_subunit(si, si, base, millimole, dim::amount_of_substance_t, prefix::milli);
implement_subunit(si, si, base, centimole, dim::amount_of_substance_t, prefix::centi);
implement_subunit(si, si, base, decimole, dim::amount_of_substance_t, prefix::deci);
implement_subunit(si, si, base, mole, dim::amount_of_substance_t, prefix::one);
implement_subunit(si, si, base, decamole, dim::amount_of_substance_t, prefix::deca);
implement_subunit(si, si, base, hectomole, dim::amount_of_substance_t, prefix::hecto);
implement_subunit(si, si, base, kilomole, dim::amount_of_substance_t, prefix::kilo);
implement_subunit(si, si, base, megamole, dim::amount_of_substance_t, prefix::mega);
implement_subunit(si, si, base, gigamole, dim::amount_of_substance_t, prefix::giga);
implement_subunit(si, si, base, teramole, dim::amount_of_substance_t, prefix::tera);
implement_subunit(si, si, base, petamole, dim::amount_of_substance_t, prefix::peta);
implement_subunit(si, si, base, examole, dim::amount_of_substance_t, prefix::exa);
implement_subunit(si, si, base, zettamole, dim::amount_of_substance_t, prefix::zetta);
implement_subunit(si, si, base, yottamole, dim::amount_of_substance_t, prefix::yotta);
#pragma endregion
#pragma region candela(luminous intensity)
implement_subunit(si, si, base, yoctocandela, dim::luminous_intensity_t, prefix::yocto);
implement_subunit(si, si, base, zeptocandela, dim::luminous_intensity_t, prefix::zepto);
implement_subunit(si, si, base, attocandela, dim::luminous_intensity_t, prefix::atto);
implement_subunit(si, si, base, femtocandela, dim::luminous_intensity_t, prefix::femto);
implement_subunit(si, si, base, picocandela, dim::luminous_intensity_t, prefix::pico);
implement_subunit(si, si, base, nanocandela, dim::luminous_intensity_t, prefix::nano);
implement_subunit(si, si, base, microcandela, dim::luminous_intensity_t, prefix::micro);
implement_subunit(si, si, base, millicandela, dim::luminous_intensity_t, prefix::milli);
implement_subunit(si, si, base, centicandela, dim::luminous_intensity_t, prefix::centi);
implement_subunit(si, si, base, decicandela, dim::luminous_intensity_t, prefix::deci);
implement_subunit(si, si, base, candela, dim::luminous_intensity_t, prefix::one);
implement_subunit(si, si, base, decacandela, dim::luminous_intensity_t, prefix::deca);
implement_subunit(si, si, base, hectocandela, dim::luminous_intensity_t, prefix::hecto);
implement_subunit(si, si, base, kilocandela, dim::luminous_intensity_t, prefix::kilo);
implement_subunit(si, si, base, megacandela, dim::luminous_intensity_t, prefix::mega);
implement_subunit(si, si, base, gigacandela, dim::luminous_intensity_t, prefix::giga);
implement_subunit(si, si, base, teracandela, dim::luminous_intensity_t, prefix::tera);
implement_subunit(si, si, base, petacandela, dim::luminous_intensity_t, prefix::peta);
implement_subunit(si, si, base, exacandela, dim::luminous_intensity_t, prefix::exa);
implement_subunit(si, si, base, zettacandela, dim::luminous_intensity_t, prefix::zetta);
implement_subunit(si, si, base, yottacandela, dim::luminous_intensity_t, prefix::yotta);
#pragma endregion
#pragma region radian(plane angle)
implement_subunit(si, si, base, yoctoradian, dim::plane_angle_t, prefix::yocto);
implement_subunit(si, si, base, zeptoradian, dim::plane_angle_t, prefix::zepto);
implement_subunit(si, si, base, attoradian, dim::plane_angle_t, prefix::atto);
implement_subunit(si, si, base, femtoradian, dim::plane_angle_t, prefix::femto);
implement_subunit(si, si, base, picoradian, dim::plane_angle_t, prefix::pico);
implement_subunit(si, si, base, nanoradian, dim::plane_angle_t, prefix::nano);
implement_subunit(si, si, base, microradian, dim::plane_angle_t, prefix::micro);
implement_subunit(si, si, base, milliradian, dim::plane_angle_t, prefix::milli);
implement_subunit(si, si, base, centiradian, dim::plane_angle_t, prefix::centi);
implement_subunit(si, si, base, deciradian, dim::plane_angle_t, prefix::deci);
implement_subunit(si, si, base, radian, dim::plane_angle_t, prefix::one);
implement_subunit(si, si, base, degree, dim::plane_angle_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 180>>));
implement_subunit(si, si, base, arcminute, dim::plane_angle_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 10800>>));
implement_subunit(si, si, base, arcsecond, dim::plane_angle_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list_t<1, 648000>>));
#pragma endregion
#pragma region count(number of radioactive events)
implement_subunit(si, si, base, count, dim::number_of_radioactive_events_t, prefix::one);
#pragma endregion
#pragma region sievert per gray(radiation weighting factor)
implement_subunit(si, si, base, sievert_per_gray, dim::radiation_weighting_factor_t, prefix::one);
#pragma endregion
#pragma region number(dimensionless data)
implement_subunit(si, si, base, one, dim::dimensionless_t, prefix::one);
implement_subunit(si, si, base, percent, dim::dimensionless_t, prefix::centi);
implement_subunit(si, si, base, permille, dim::dimensionless_t, prefix::milli);
implement_subunit(si, si, base, parts_per_million, dim::dimensionless_t, prefix::micro);
#pragma endregion
} // namespace base
#pragma region constants
namespace constant
{
using namespace benri::si::base;
#pragma region mathematical constants
create_constant(quarter_pi, prefix::quarter_pi_v, one_t);
create_constant(half_pi, prefix::half_pi_v, one_t);
create_constant(pi, prefix::pi_v, one_t);
create_constant(two_pi, prefix::two_pi_v, one_t);
create_constant(e, prefix::e_v, one_t);
create_constant(phi, prefix::phi_v, one_t);
create_constant(gamma, prefix::gamma_v, one_t);
create_constant(root_two, prefix::root_two_v, one_t);
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