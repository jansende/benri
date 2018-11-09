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
implement_subunit(si, si, base, metre, dim::length_t, prefix::one);
#pragma endregion
#pragma region kilogram(mass)
implement_subunit(si, si, base, gram, dim::mass_t, fix(impl::multiply_lists_t<prefix::one, prefix::milli>));
implement_subunit(si, si, base, kilogram, dim::mass_t, fix(impl::multiply_lists_t<prefix::kilo, prefix::milli>));
implement_subunit(si, si, base, tonne, dim::mass_t, fix(impl::multiply_lists_t<prefix::mega, prefix::milli>));
#pragma endregion
#pragma region second(time)
implement_subunit(si, si, base, second, dim::time_t, prefix::one);
#pragma endregion
#pragma region ampere(electric current)
implement_subunit(si, si, base, ampere, dim::electric_current_t, prefix::one);
#pragma endregion
#pragma region kelvin(thermodynamic temperature)
implement_subunit(si, si, base, kelvin, dim::thermodynamic_temperature_t, prefix::one);
#pragma endregion
#pragma region celsius(thermodynamic temperature)
implement_subunit(si, si, base, celsius, dim::celsius_temperature_t, prefix::one);
} // namespace base
} // namespace si
template <class System, class lhsDimensions, class rhsDimensions, class Prefix>
struct is_compatible_impl<System, lhsDimensions, Prefix, System, rhsDimensions, Prefix, std::enable_if_t<(std::is_same_v<lhsDimensions, dim::celsius_temperature_t> && std::is_same_v<rhsDimensions, dim::thermodynamic_temperature_t>) || (std::is_same_v<lhsDimensions, dim::thermodynamic_temperature_t> && std::is_same_v<rhsDimensions, dim::celsius_temperature_t>)>> : std::true_type
{
};
namespace si
{
namespace base
{
#pragma endregion
#pragma region rankine(thermodynamic temperature)
implement_subunit(si, si, base, rankine, dim::thermodynamic_temperature_t, fix(impl::multiply_lists_t<prefix::one, prefix::rankine_t>));
#pragma endregion
#pragma region fahrenheit(thermodynamic temperature)
implement_subunit(si, si, base, fahrenheit, dim::fahrenheit_temperature_t, prefix::one);
} // namespace base
} // namespace si
template <class System, class lhsDimensions, class lhsPrefix, class rhsDimensions, class rhsPrefix>
struct is_compatible_impl<System, lhsDimensions, lhsPrefix, System, rhsDimensions, rhsPrefix, std::enable_if_t<((std::is_same_v<lhsDimensions, dim::fahrenheit_temperature_t> && std::is_same_v<rhsDimensions, dim::thermodynamic_temperature_t>) || (std::is_same_v<lhsDimensions, dim::thermodynamic_temperature_t> && std::is_same_v<rhsDimensions, dim::fahrenheit_temperature_t>)) && ((std::is_same_v<lhsPrefix, impl::multiply_lists_t<rhsPrefix, prefix::rankine_t>>) || (std::is_same_v<impl::multiply_lists_t<lhsPrefix, prefix::rankine_t>, rhsPrefix>))>> : std::true_type
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
implement_subunit(si, si, base, mole, dim::amount_of_substance_t, prefix::one);
#pragma endregion
#pragma region candela(luminous intensity)
implement_subunit(si, si, base, candela, dim::luminous_intensity_t, prefix::one);
#pragma endregion
#pragma region radian(plane angle)
implement_subunit(si, si, base, radian, dim::plane_angle_t, prefix::one);
implement_subunit(si, si, base, degree, dim::plane_angle_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list<1, 180>>));
implement_subunit(si, si, base, arcminute, dim::plane_angle_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list<1, 10800>>));
implement_subunit(si, si, base, arcsecond, dim::plane_angle_t, fix(impl::multiply_lists_t<prefix::pi_t, make_fraction_list<1, 648000>>));
#pragma endregion
#pragma region count(number of radioactive events)
implement_subunit(si, si, base, count, dim::number_of_radioactive_events_t, prefix::one);
#pragma endregion
#pragma region sievert per gray(radiation weighting factor)
implement_subunit(si, si, base, sievert_per_gray, dim::radiation_weighting_factor_t, prefix::one);
#pragma endregion
#pragma region number(dimensionless data)
implement_subunit(si, si, base, percent, dim::dimensionless_t, prefix::centi);
implement_subunit(si, si, base, permille, dim::dimensionless_t, prefix::milli);
implement_subunit(si, si, base, parts_per_million, dim::dimensionless_t, prefix::micro);


implement_subunit(si, si, base, yocto, dim::dimensionless_t, prefix::yocto);
implement_subunit(si, si, base, zepto, dim::dimensionless_t, prefix::zepto);
implement_subunit(si, si, base, atto, dim::dimensionless_t, prefix::atto);
implement_subunit(si, si, base, femto, dim::dimensionless_t, prefix::femto);
implement_subunit(si, si, base, pico, dim::dimensionless_t, prefix::pico);
implement_subunit(si, si, base, nano, dim::dimensionless_t, prefix::nano);
implement_subunit(si, si, base, micro, dim::dimensionless_t, prefix::micro);
implement_subunit(si, si, base, milli, dim::dimensionless_t, prefix::milli);
implement_subunit(si, si, base, centi, dim::dimensionless_t, prefix::centi);
implement_subunit(si, si, base, deci, dim::dimensionless_t, prefix::deci);
implement_subunit(si, si, base, one, dim::dimensionless_t, prefix::one);
implement_subunit(si, si, base, deca, dim::dimensionless_t, prefix::deca);
implement_subunit(si, si, base, hecto, dim::dimensionless_t, prefix::hecto);
implement_subunit(si, si, base, kilo, dim::dimensionless_t, prefix::kilo);
implement_subunit(si, si, base, mega, dim::dimensionless_t, prefix::mega);
implement_subunit(si, si, base, giga, dim::dimensionless_t, prefix::giga);
implement_subunit(si, si, base, tera, dim::dimensionless_t, prefix::tera);
implement_subunit(si, si, base, peta, dim::dimensionless_t, prefix::peta);
implement_subunit(si, si, base, exa, dim::dimensionless_t, prefix::exa);
implement_subunit(si, si, base, zetta, dim::dimensionless_t, prefix::zetta);
implement_subunit(si, si, base, yotta, dim::dimensionless_t, prefix::yotta);
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