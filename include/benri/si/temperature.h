#pragma once
#include <benri/quantity.h>
#include <benri/quantity_point.h>
#include <benri/impl/dimensions.h>
#include <benri/impl/macros.h>
#include <benri/impl/prefix.h>
#include <benri/si/base.h>

namespace benri
{
namespace si
{
namespace temperature
{
#pragma region celsius temperature
implement_subunit(si, temperature, celsius, dim::celsius_temperature_t, prefix::one_t);
link_unit_point(degree_celsius, celsius);
#pragma endregion
#pragma region rankine temperature
implement_subunit(si, temperature, rankine, dim::thermodynamic_temperature_t, prefix::rankine_t);
link_unit_point(degree_rankine, rankine);
#pragma endregion
#pragma region fahrenheit temperature
implement_subunit(si, temperature, fahrenheit, dim::fahrenheit_temperature_t, prefix::one_t);
link_unit_point(degree_fahrenheit, fahrenheit);
#pragma endregion
} // namespace temperature
} // namespace si
#pragma region is_compatible definitions
template <class lhsDimensions, class rhsDimensions, class Prefix>
struct is_compatible_impl<lhsDimensions, Prefix, rhsDimensions, Prefix, std::enable_if_t<(std::is_same_v<lhsDimensions, dim::celsius_temperature_t> && std::is_same_v<rhsDimensions, dim::thermodynamic_temperature_t>) || (std::is_same_v<lhsDimensions, dim::thermodynamic_temperature_t> && std::is_same_v<rhsDimensions, dim::celsius_temperature_t>)>> : std::true_type
{
};
template <class lhsDimensions, class lhsPrefix, class rhsDimensions, class rhsPrefix>
struct is_compatible_impl<lhsDimensions, lhsPrefix, rhsDimensions, rhsPrefix, std::enable_if_t<((std::is_same_v<lhsDimensions, dim::fahrenheit_temperature_t> && std::is_same_v<rhsDimensions, dim::thermodynamic_temperature_t>) || (std::is_same_v<lhsDimensions, dim::thermodynamic_temperature_t> && std::is_same_v<rhsDimensions, dim::fahrenheit_temperature_t>)) && ((std::is_same_v<lhsPrefix, multiply_lists<rhsPrefix, prefix::rankine_t>>) || (std::is_same_v<multiply_lists<lhsPrefix, prefix::rankine_t>, rhsPrefix>))>> : std::true_type
{
};
#pragma endregion
#pragma region simple_cast / unit_cast overloads
//conversion overload (we need an actual overload, because partial function template specialization is not allowed)
//celsius to kelvin
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<si::temperature::degree_celsius_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, si::degree_kelvin_t>, quantity_point<si::degree_kelvin_t, ValueType>>
{
    return quantity_point<si::degree_kelvin_t, ValueType>{rhs.value() + static_cast<ValueType>(prefix::absolute_zero::value)};
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<si::temperature::degree_celsius_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, si::degree_kelvin_t>, quantity_point<si::degree_kelvin_t, ValueType>>
{
    return simple_cast<si::degree_kelvin_t>(rhs);
}
//kelvin to celsius
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<si::degree_kelvin_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, si::temperature::degree_celsius_t>, quantity_point<si::temperature::degree_celsius_t, ValueType>>
{
    return quantity_point<si::temperature::degree_celsius_t, ValueType>{rhs.value() - static_cast<ValueType>(prefix::absolute_zero::value)};
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<si::degree_kelvin_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, si::temperature::degree_celsius_t>, quantity_point<si::temperature::degree_celsius_t, ValueType>>
{
    return simple_cast<si::temperature::degree_celsius_t>(rhs);
}
//celsius to rankine
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<si::temperature::degree_celsius_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, si::temperature::degree_rankine_t>, quantity_point<si::temperature::degree_rankine_t, ValueType>>
{
    return simple_cast<si::temperature::degree_rankine_t>(simple_cast<si::degree_kelvin_t>(rhs));
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<si::temperature::degree_celsius_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, si::temperature::degree_rankine_t>, quantity_point<si::temperature::degree_rankine_t, ValueType>>
{
    return simple_cast<si::temperature::degree_rankine_t>(rhs);
}
//rankine to celsius
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<si::temperature::degree_rankine_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, si::temperature::degree_celsius_t>, quantity_point<si::temperature::degree_celsius_t, ValueType>>
{
    return simple_cast<si::temperature::degree_celsius_t>(simple_cast<si::degree_kelvin_t>(rhs));
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<si::temperature::degree_rankine_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, si::temperature::degree_celsius_t>, quantity_point<si::temperature::degree_celsius_t, ValueType>>
{
    return simple_cast<si::temperature::degree_celsius_t>(rhs);
}
//fahrenheit to kelvin
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<si::temperature::degree_fahrenheit_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, si::degree_kelvin_t>, quantity_point<si::degree_kelvin_t, ValueType>>
{
    return quantity_point<si::degree_kelvin_t, ValueType>{(rhs.value() - static_cast<ValueType>(prefix::fahrenheit_zero::value)) / static_cast<ValueType>(prefix::rankine::value)};
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<si::temperature::degree_fahrenheit_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, si::degree_kelvin_t>, quantity_point<si::degree_kelvin_t, ValueType>>
{
    return simple_cast<si::degree_kelvin_t>(rhs);
}
//kelvin to fahrenheit
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<si::degree_kelvin_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, si::temperature::degree_fahrenheit_t>, quantity_point<si::temperature::degree_fahrenheit_t, ValueType>>
{
    return quantity_point<si::temperature::degree_fahrenheit_t, ValueType>{rhs.value() * static_cast<ValueType>(prefix::rankine::value) + static_cast<ValueType>(prefix::fahrenheit_zero::value)};
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<si::degree_kelvin_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, si::temperature::degree_fahrenheit_t>, quantity_point<si::temperature::degree_fahrenheit_t, ValueType>>
{
    return simple_cast<si::temperature::degree_fahrenheit_t>(rhs);
}
//fahrenheit to celsius
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<si::temperature::degree_fahrenheit_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, si::temperature::degree_celsius_t>, quantity_point<si::temperature::degree_celsius_t, ValueType>>
{
    return simple_cast<si::temperature::degree_celsius_t>(simple_cast<si::degree_kelvin_t>(rhs));
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<si::temperature::degree_fahrenheit_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, si::temperature::degree_celsius_t>, quantity_point<si::temperature::degree_celsius_t, ValueType>>
{
    return simple_cast<si::temperature::degree_celsius_t>(rhs);
}
//celsius to fahrenheit
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<si::temperature::degree_celsius_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, si::temperature::degree_fahrenheit_t>, quantity_point<si::temperature::degree_fahrenheit_t, ValueType>>
{
    return simple_cast<si::temperature::degree_fahrenheit_t>(simple_cast<si::degree_kelvin_t>(rhs));
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<si::temperature::degree_celsius_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, si::temperature::degree_fahrenheit_t>, quantity_point<si::temperature::degree_fahrenheit_t, ValueType>>
{
    return simple_cast<si::temperature::degree_fahrenheit_t>(rhs);
}
//fahrenheit to rankine
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<si::temperature::degree_fahrenheit_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, si::temperature::degree_rankine_t>, quantity_point<si::temperature::degree_rankine_t, ValueType>>
{
    return simple_cast<si::temperature::degree_rankine_t>(simple_cast<si::degree_kelvin_t>(rhs));
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<si::temperature::degree_fahrenheit_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, si::temperature::degree_rankine_t>, quantity_point<si::temperature::degree_rankine_t, ValueType>>
{
    return simple_cast<si::temperature::degree_rankine_t>(rhs);
}
//rankine to fahrenheit
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<si::temperature::degree_rankine_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, si::temperature::degree_fahrenheit_t>, quantity_point<si::temperature::degree_fahrenheit_t, ValueType>>
{
    return simple_cast<si::temperature::degree_fahrenheit_t>(simple_cast<si::degree_kelvin_t>(rhs));
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<si::temperature::degree_rankine_t, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<ResultUnit, si::temperature::degree_fahrenheit_t>, quantity_point<si::temperature::degree_fahrenheit_t, ValueType>>
{
    return simple_cast<si::temperature::degree_fahrenheit_t>(rhs);
}
#pragma endregion
} // namespace benri