#pragma once
#include <benri/quantity.h>
#include <benri/quantity_point.h>
#include <benri/si/base.h>
#include <benri/si/dimensions.h>
#include <benri/si/macros.h>
#include <benri/si/prefixes.h>

namespace benri
{
namespace si
{
namespace temperature
{
#pragma region celsius temperature
implement_unit(celsius, dimension::celsius_temperature_t, prefix::one_t);
link_unit_point(degree_celsius, celsius);
#pragma endregion
#pragma region rankine temperature
implement_unit(rankine, dimension::thermodynamic_temperature_t,
               fix(type::pow_list<prefix::rankine_t, std::ratio<-1>>));
link_unit_point(degree_rankine, rankine);
#pragma endregion
#pragma region fahrenheit temperature
implement_unit(fahrenheit, dimension::fahrenheit_temperature_t,
               fix(type::pow_list<prefix::rankine_t, std::ratio<-1>>));
link_unit_point(degree_fahrenheit, fahrenheit);
#pragma endregion
} // namespace temperature
} // namespace si
#pragma region is_compatible definitions
template <class Prefix>
struct is_compatible<dimension::celsius_temperature_t, Prefix,
                     dimension::thermodynamic_temperature_t, Prefix> : std::true_type
{
};
template <class Prefix>
struct is_compatible<dimension::fahrenheit_temperature_t, Prefix,
                     dimension::thermodynamic_temperature_t, Prefix> : std::true_type
{
};
#pragma endregion
#pragma region simple_cast / unit_cast overloads
// conversion overload for quantity points (we need an actual overload, because
// partial function template specialization is not allowed)

// celsius to kelvin
template <class ResultUnit, class ValueType>
constexpr auto
    simple_cast(const quantity_point<si::temperature::degree_celsius_t, ValueType>& rhs)
        -> std::enable_if_t<std::is_same<ResultUnit, si::degree_kelvin_t>::value,
                            quantity_point<si::degree_kelvin_t, ValueType>>
{
    return quantity_point<si::degree_kelvin_t, ValueType>{
        rhs.value() - static_cast<ValueType>(prefix::absolute_zero::value)};
}
template <class ResultUnit, class ValueType>
constexpr auto
    unit_cast(const quantity_point<si::temperature::degree_celsius_t, ValueType>& rhs)
        -> std::enable_if_t<std::is_same<ResultUnit, si::degree_kelvin_t>::value,
                            quantity_point<si::degree_kelvin_t, ValueType>>
{
    return simple_cast<si::degree_kelvin_t>(rhs);
}
// kelvin to celsius
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<si::degree_kelvin_t, ValueType>& rhs)
    -> std::enable_if_t<
        std::is_same<ResultUnit, si::temperature::degree_celsius_t>::value,
        quantity_point<si::temperature::degree_celsius_t, ValueType>>
{
    return quantity_point<si::temperature::degree_celsius_t, ValueType>{
        rhs.value() + static_cast<ValueType>(prefix::absolute_zero::value)};
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<si::degree_kelvin_t, ValueType>& rhs)
    -> std::enable_if_t<
        std::is_same<ResultUnit, si::temperature::degree_celsius_t>::value,
        quantity_point<si::temperature::degree_celsius_t, ValueType>>
{
    return simple_cast<si::temperature::degree_celsius_t>(rhs);
}
// celsius to rankine
template <class ResultUnit, class ValueType>
constexpr auto
    simple_cast(const quantity_point<si::temperature::degree_celsius_t, ValueType>& rhs)
        -> std::enable_if_t<
            std::is_same<ResultUnit, si::temperature::degree_rankine_t>::value,
            quantity_point<si::temperature::degree_rankine_t, ValueType>>
{
    return quantity_point<si::temperature::degree_rankine_t, ValueType>{
        rhs.value() * static_cast<ValueType>(prefix::rankine::value)
        - static_cast<ValueType>(prefix::absolute_zero::value)
              * static_cast<ValueType>(prefix::rankine::value)};
}
template <class ResultUnit, class ValueType>
constexpr auto
    unit_cast(const quantity_point<si::temperature::degree_celsius_t, ValueType>& rhs)
        -> std::enable_if_t<
            std::is_same<ResultUnit, si::temperature::degree_rankine_t>::value,
            quantity_point<si::temperature::degree_rankine_t, ValueType>>
{
    return simple_cast<si::temperature::degree_rankine_t>(rhs);
}
// rankine to celsius
template <class ResultUnit, class ValueType>
constexpr auto
    simple_cast(const quantity_point<si::temperature::degree_rankine_t, ValueType>& rhs)
        -> std::enable_if_t<
            std::is_same<ResultUnit, si::temperature::degree_celsius_t>::value,
            quantity_point<si::temperature::degree_celsius_t, ValueType>>
{
    return quantity_point<si::temperature::degree_celsius_t, ValueType>{
        rhs.value() / static_cast<ValueType>(prefix::rankine::value)
        + static_cast<ValueType>(prefix::absolute_zero::value)};
}
template <class ResultUnit, class ValueType>
constexpr auto
    unit_cast(const quantity_point<si::temperature::degree_rankine_t, ValueType>& rhs)
        -> std::enable_if_t<
            std::is_same<ResultUnit, si::temperature::degree_celsius_t>::value,
            quantity_point<si::temperature::degree_celsius_t, ValueType>>
{
    return simple_cast<si::temperature::degree_celsius_t>(rhs);
}
// fahrenheit to kelvin
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(
    const quantity_point<si::temperature::degree_fahrenheit_t, ValueType>& rhs)
    -> std::enable_if_t<std::is_same<ResultUnit, si::degree_kelvin_t>::value,
                        quantity_point<si::degree_kelvin_t, ValueType>>
{
    return quantity_point<si::degree_kelvin_t, ValueType>{
        rhs.value() / static_cast<ValueType>(prefix::rankine::value)
        - static_cast<ValueType>(prefix::fahrenheit_zero::value)
              / static_cast<ValueType>(prefix::rankine::value)};
}
template <class ResultUnit, class ValueType>
constexpr auto
    unit_cast(const quantity_point<si::temperature::degree_fahrenheit_t, ValueType>& rhs)
        -> std::enable_if_t<std::is_same<ResultUnit, si::degree_kelvin_t>::value,
                            quantity_point<si::degree_kelvin_t, ValueType>>
{
    return simple_cast<si::degree_kelvin_t>(rhs);
}
// kelvin to fahrenheit
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(const quantity_point<si::degree_kelvin_t, ValueType>& rhs)
    -> std::enable_if_t<
        std::is_same<ResultUnit, si::temperature::degree_fahrenheit_t>::value,
        quantity_point<si::temperature::degree_fahrenheit_t, ValueType>>
{
    return quantity_point<si::temperature::degree_fahrenheit_t, ValueType>{
        rhs.value() * static_cast<ValueType>(prefix::rankine::value)
        + static_cast<ValueType>(prefix::fahrenheit_zero::value)};
}
template <class ResultUnit, class ValueType>
constexpr auto unit_cast(const quantity_point<si::degree_kelvin_t, ValueType>& rhs)
    -> std::enable_if_t<
        std::is_same<ResultUnit, si::temperature::degree_fahrenheit_t>::value,
        quantity_point<si::temperature::degree_fahrenheit_t, ValueType>>
{
    return simple_cast<si::temperature::degree_fahrenheit_t>(rhs);
}
// fahrenheit to celsius
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(
    const quantity_point<si::temperature::degree_fahrenheit_t, ValueType>& rhs)
    -> std::enable_if_t<
        std::is_same<ResultUnit, si::temperature::degree_celsius_t>::value,
        quantity_point<si::temperature::degree_celsius_t, ValueType>>
{
    return quantity_point<si::temperature::degree_celsius_t, ValueType>{
        (rhs.value() - static_cast<ValueType>(prefix::freezing_point::value))
        / static_cast<ValueType>(prefix::rankine::value)};
}
template <class ResultUnit, class ValueType>
constexpr auto
    unit_cast(const quantity_point<si::temperature::degree_fahrenheit_t, ValueType>& rhs)
        -> std::enable_if_t<
            std::is_same<ResultUnit, si::temperature::degree_celsius_t>::value,
            quantity_point<si::temperature::degree_celsius_t, ValueType>>
{
    return simple_cast<si::temperature::degree_celsius_t>(rhs);
}
// celsius to fahrenheit
template <class ResultUnit, class ValueType>
constexpr auto
    simple_cast(const quantity_point<si::temperature::degree_celsius_t, ValueType>& rhs)
        -> std::enable_if_t<
            std::is_same<ResultUnit, si::temperature::degree_fahrenheit_t>::value,
            quantity_point<si::temperature::degree_fahrenheit_t, ValueType>>
{
    return quantity_point<si::temperature::degree_fahrenheit_t, ValueType>{
        rhs.value() * static_cast<ValueType>(prefix::rankine::value)
        + static_cast<ValueType>(prefix::fahrenheit_zero::value)
        - static_cast<ValueType>(prefix::rankine::value)
              * static_cast<ValueType>(prefix::absolute_zero::value)};
}
template <class ResultUnit, class ValueType>
constexpr auto
    unit_cast(const quantity_point<si::temperature::degree_celsius_t, ValueType>& rhs)
        -> std::enable_if_t<
            std::is_same<ResultUnit, si::temperature::degree_fahrenheit_t>::value,
            quantity_point<si::temperature::degree_fahrenheit_t, ValueType>>
{
    return simple_cast<si::temperature::degree_fahrenheit_t>(rhs);
}
// fahrenheit to rankine
template <class ResultUnit, class ValueType>
constexpr auto simple_cast(
    const quantity_point<si::temperature::degree_fahrenheit_t, ValueType>& rhs)
    -> std::enable_if_t<
        std::is_same<ResultUnit, si::temperature::degree_rankine_t>::value,
        quantity_point<si::temperature::degree_rankine_t, ValueType>>
{
    return quantity_point<si::temperature::degree_rankine_t, ValueType>{
        rhs.value() - static_cast<ValueType>(prefix::fahrenheit_zero::value)};
}
template <class ResultUnit, class ValueType>
constexpr auto
    unit_cast(const quantity_point<si::temperature::degree_fahrenheit_t, ValueType>& rhs)
        -> std::enable_if_t<
            std::is_same<ResultUnit, si::temperature::degree_rankine_t>::value,
            quantity_point<si::temperature::degree_rankine_t, ValueType>>
{
    return simple_cast<si::temperature::degree_rankine_t>(rhs);
}
// rankine to fahrenheit
template <class ResultUnit, class ValueType>
constexpr auto
    simple_cast(const quantity_point<si::temperature::degree_rankine_t, ValueType>& rhs)
        -> std::enable_if_t<
            std::is_same<ResultUnit, si::temperature::degree_fahrenheit_t>::value,
            quantity_point<si::temperature::degree_fahrenheit_t, ValueType>>
{
    return quantity_point<si::temperature::degree_fahrenheit_t, ValueType>{
        rhs.value() + static_cast<ValueType>(prefix::fahrenheit_zero::value)};
}
template <class ResultUnit, class ValueType>
constexpr auto
    unit_cast(const quantity_point<si::temperature::degree_rankine_t, ValueType>& rhs)
        -> std::enable_if_t<
            std::is_same<ResultUnit, si::temperature::degree_fahrenheit_t>::value,
            quantity_point<si::temperature::degree_fahrenheit_t, ValueType>>
{
    return simple_cast<si::temperature::degree_fahrenheit_t>(rhs);
}
#pragma endregion
#pragma region simple_cast / unit_cast overloads
// conversion overload for quantities (we need an actual overload, because
// partial function template specialization is not allowed)

// celsius to kelvin
template <class ResultUnit, class Prefix, class ValueType>
constexpr auto simple_cast(
    const quantity<unit<dimension::celsius_temperature_t, Prefix>, ValueType>& rhs)
    -> std::enable_if_t<std::is_same<typename ResultUnit::dimension,
                                     dimension::thermodynamic_temperature_t>::value,
                        quantity<ResultUnit, ValueType>>
{
    return quantity<ResultUnit, ValueType>{
        rhs.value()
        * expand_prefix_list<ValueType,
                             type::divide_lists<Prefix, typename ResultUnit::prefix>>};
}
template <class ResultUnit, class Prefix, class ValueType>
constexpr auto unit_cast(
    const quantity<unit<dimension::celsius_temperature_t, Prefix>, ValueType>& rhs)
    -> std::enable_if_t<std::is_same<typename ResultUnit::dimension,
                                     dimension::thermodynamic_temperature_t>::value,
                        quantity<ResultUnit, ValueType>>
{
    return quantity<ResultUnit, ValueType>{
        rhs.value()
        * runtime_expand_prefix_list<ValueType>(
            type::divide_lists<Prefix, typename ResultUnit::prefix>{})};
}
// kelvin to celsius
template <class ResultUnit, class Prefix, class ValueType>
constexpr auto simple_cast(
    const quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>& rhs)
    -> std::enable_if_t<std::is_same<typename ResultUnit::dimension,
                                     dimension::celsius_temperature_t>::value,
                        quantity<ResultUnit, ValueType>>
{
    return quantity<ResultUnit, ValueType>{
        rhs.value()
        * expand_prefix_list<ValueType,
                             type::divide_lists<Prefix, typename ResultUnit::prefix>>};
}
template <class ResultUnit, class Prefix, class ValueType>
constexpr auto unit_cast(
    const quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>& rhs)
    -> std::enable_if_t<std::is_same<typename ResultUnit::dimension,
                                     dimension::celsius_temperature_t>::value,
                        quantity<ResultUnit, ValueType>>
{
    return quantity<ResultUnit, ValueType>{
        rhs.value()
        * runtime_expand_prefix_list<ValueType>(
            type::divide_lists<Prefix, typename ResultUnit::prefix>{})};
}
// fahrenheit to kelvin
template <class ResultUnit, class Prefix, class ValueType>
constexpr auto simple_cast(
    const quantity<unit<dimension::fahrenheit_temperature_t, Prefix>, ValueType>& rhs)
    -> std::enable_if_t<std::is_same<typename ResultUnit::dimension,
                                     dimension::thermodynamic_temperature_t>::value,
                        quantity<ResultUnit, ValueType>>
{
    return quantity<ResultUnit, ValueType>{
        rhs.value()
        * expand_prefix_list<ValueType,
                             type::divide_lists<Prefix, typename ResultUnit::prefix>>};
}
template <class ResultUnit, class Prefix, class ValueType>
constexpr auto unit_cast(
    const quantity<unit<dimension::fahrenheit_temperature_t, Prefix>, ValueType>& rhs)
    -> std::enable_if_t<std::is_same<typename ResultUnit::dimension,
                                     dimension::thermodynamic_temperature_t>::value,
                        quantity<ResultUnit, ValueType>>
{
    return quantity<ResultUnit, ValueType>{
        rhs.value()
        * runtime_expand_prefix_list<ValueType>(
            type::divide_lists<Prefix, typename ResultUnit::prefix>{})};
}
// kelvin to fahrenheit
template <class ResultUnit, class Prefix, class ValueType>
constexpr auto simple_cast(
    const quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>& rhs)
    -> std::enable_if_t<std::is_same<typename ResultUnit::dimension,
                                     dimension::fahrenheit_temperature_t>::value,
                        quantity<ResultUnit, ValueType>>
{
    return quantity<ResultUnit, ValueType>{
        rhs.value()
        * expand_prefix_list<ValueType,
                             type::divide_lists<Prefix, typename ResultUnit::prefix>>};
}
template <class ResultUnit, class Prefix, class ValueType>
constexpr auto unit_cast(
    const quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>& rhs)
    -> std::enable_if_t<std::is_same<typename ResultUnit::dimension,
                                     dimension::fahrenheit_temperature_t>::value,
                        quantity<ResultUnit, ValueType>>
{
    return quantity<ResultUnit, ValueType>{
        rhs.value()
        * runtime_expand_prefix_list<ValueType>(
            type::divide_lists<Prefix, typename ResultUnit::prefix>{})};
}
// fahrenheit to celsius
template <class ResultUnit, class Prefix, class ValueType>
constexpr auto simple_cast(
    const quantity<unit<dimension::fahrenheit_temperature_t, Prefix>, ValueType>& rhs)
    -> std::enable_if_t<std::is_same<typename ResultUnit::dimension,
                                     dimension::celsius_temperature_t>::value,
                        quantity<ResultUnit, ValueType>>
{
    return quantity<ResultUnit, ValueType>{
        rhs.value()
        * expand_prefix_list<ValueType,
                             type::divide_lists<Prefix, typename ResultUnit::prefix>>};
}
template <class ResultUnit, class Prefix, class ValueType>
constexpr auto unit_cast(
    const quantity<unit<dimension::fahrenheit_temperature_t, Prefix>, ValueType>& rhs)
    -> std::enable_if_t<std::is_same<typename ResultUnit::dimension,
                                     dimension::celsius_temperature_t>::value,
                        quantity<ResultUnit, ValueType>>
{
    return quantity<ResultUnit, ValueType>{
        rhs.value()
        * runtime_expand_prefix_list<ValueType>(
            type::divide_lists<Prefix, typename ResultUnit::prefix>{})};
}
// celsius to fahrenheit
template <class ResultUnit, class Prefix, class ValueType>
constexpr auto simple_cast(
    const quantity<unit<dimension::celsius_temperature_t, Prefix>, ValueType>& rhs)
    -> std::enable_if_t<std::is_same<typename ResultUnit::dimension,
                                     dimension::fahrenheit_temperature_t>::value,
                        quantity<ResultUnit, ValueType>>
{
    return quantity<ResultUnit, ValueType>{
        rhs.value()
        * expand_prefix_list<ValueType,
                             type::divide_lists<Prefix, typename ResultUnit::prefix>>};
}
template <class ResultUnit, class Prefix, class ValueType>
constexpr auto unit_cast(
    const quantity<unit<dimension::celsius_temperature_t, Prefix>, ValueType>& rhs)
    -> std::enable_if_t<std::is_same<typename ResultUnit::dimension,
                                     dimension::fahrenheit_temperature_t>::value,
                        quantity<ResultUnit, ValueType>>
{
    return quantity<ResultUnit, ValueType>{
        rhs.value()
        * runtime_expand_prefix_list<ValueType>(
            type::divide_lists<Prefix, typename ResultUnit::prefix>{})};
}
#pragma endregion
#pragma region helper function
template <class Unit, class ValueType>
constexpr auto zero_point(const quantity<Unit, ValueType>&)
{
    return quantity_point<Unit, ValueType>{ValueType{0}};
}
template <class Unit, class ValueType>
constexpr auto zero_point(const quantity_point<Unit, ValueType>&)
{
    return quantity_point<Unit, ValueType>{ValueType{0}};
}
#pragma endregion
} // namespace benri