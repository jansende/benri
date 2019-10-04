#pragma once
#include <benri/casts.h>
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
#pragma region convert definitions
template <class Prefix, class ValueType>
struct convert<quantity<unit<dimension::celsius_temperature_t, Prefix>, ValueType>,
               quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>>
{
    constexpr auto operator()(
        const quantity<unit<dimension::celsius_temperature_t, Prefix>, ValueType>& rhs)
        -> quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>{
            rhs._value};
    }
    constexpr auto operator()(
        quantity<unit<dimension::celsius_temperature_t, Prefix>, ValueType>&& rhs)
        -> quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>{
            std::move(rhs._value)};
    }
};
template <class Prefix, class ValueType>
struct convert<quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>,
               quantity<unit<dimension::celsius_temperature_t, Prefix>, ValueType>>
{
    constexpr auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>&
            rhs) -> quantity<unit<dimension::celsius_temperature_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::celsius_temperature_t, Prefix>, ValueType>{
            rhs._value};
    }
    constexpr auto operator()(
        quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>&& rhs)
        -> quantity<unit<dimension::celsius_temperature_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::celsius_temperature_t, Prefix>, ValueType>{
            std::move(rhs._value)};
    }
};
template <class Prefix, class ValueType>
struct convert<quantity<unit<dimension::fahrenheit_temperature_t, Prefix>, ValueType>,
               quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>>
{
    constexpr auto operator()(
        const quantity<unit<dimension::fahrenheit_temperature_t, Prefix>, ValueType>& rhs)
        -> quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>{
            rhs._value};
    }
    constexpr auto operator()(
        quantity<unit<dimension::fahrenheit_temperature_t, Prefix>, ValueType>&& rhs)
        -> quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>{
            std::move(rhs._value)};
    }
};
template <class Prefix, class ValueType>
struct convert<quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>,
               quantity<unit<dimension::fahrenheit_temperature_t, Prefix>, ValueType>>
{
    constexpr auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>&
            rhs) -> quantity<unit<dimension::fahrenheit_temperature_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::fahrenheit_temperature_t, Prefix>, ValueType>{
            rhs._value};
    }
    constexpr auto operator()(
        quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>&& rhs)
        -> quantity<unit<dimension::fahrenheit_temperature_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::fahrenheit_temperature_t, Prefix>, ValueType>{
            std::move(rhs._value)};
    }
};
#pragma endregion
#pragma region simple_cast
// quantity_point
template <class ResultValueType>
struct simple_cast_impl<quantity_point<si::degree_kelvin_t, ResultValueType>, void>
{
    // From celsius to kelvin
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>& rhs)
        const noexcept -> quantity_point<si::degree_kelvin_t, ResultValueType>
    {
        return quantity_point<si::degree_kelvin_t, ResultValueType>{
            static_cast<ResultValueType>(
                rhs.value()
                - static_cast<ArgumentValueType>(prefix::absolute_zero::value))};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_celsius_t, ResultValueType>& rhs)
        const noexcept -> quantity_point<si::degree_kelvin_t, ResultValueType>
    {
        return quantity_point<si::degree_kelvin_t, ResultValueType>{
            rhs.value() - static_cast<ResultValueType>(prefix::absolute_zero::value)};
    }
    // From fahrenheit to kelvin
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_fahrenheit_t, ArgumentValueType>&
            rhs) const noexcept -> quantity_point<si::degree_kelvin_t, ResultValueType>
    {
        return quantity_point<si::degree_kelvin_t, ResultValueType>{
            static_cast<ResultValueType>(
                rhs.value() / static_cast<ArgumentValueType>(prefix::rankine::value)
                - static_cast<ArgumentValueType>(prefix::fahrenheit_zero::value)
                      / static_cast<ArgumentValueType>(prefix::rankine::value))};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>& rhs)
        const noexcept -> quantity_point<si::degree_kelvin_t, ResultValueType>
    {
        return quantity_point<si::degree_kelvin_t, ResultValueType>{
            rhs.value() / static_cast<ResultValueType>(prefix::rankine::value)
            - static_cast<ResultValueType>(prefix::fahrenheit_zero::value)
                  / static_cast<ResultValueType>(prefix::rankine::value)};
    }
    // From kelvin to kelvin
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                             ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::degree_kelvin_t, ResultValueType>
    {
        constexpr auto factor = expand_prefix_list<
            ArgumentValueType,
            type::divide_lists<ArgumentPrefix, typename si::degree_kelvin_t::prefix>>;
        return quantity_point<si::degree_kelvin_t, ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                             ResultValueType>& rhs) const noexcept
        -> quantity_point<si::degree_kelvin_t, ResultValueType>
    {
        constexpr auto factor = expand_prefix_list<
            ResultValueType,
            type::divide_lists<ArgumentPrefix, typename si::degree_kelvin_t::prefix>>;
        return quantity_point<si::degree_kelvin_t, ResultValueType>{rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::degree_kelvin_t, ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::degree_kelvin_t, ResultValueType>
    {
        return quantity_point<si::degree_kelvin_t, ResultValueType>{
            static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto
        operator()(const quantity_point<si::degree_kelvin_t, ResultValueType>& rhs) const
        noexcept -> quantity_point<si::degree_kelvin_t, ResultValueType>
    {
        return rhs;
    }
    // From Other to kelvin
    template <class Other>
    [[nodiscard]] constexpr inline auto operator()(const Other& rhs) const noexcept
        -> std::enable_if_t<
            type::detect_if<Other, is_convertible_into,
                            quantity_point<si::degree_kelvin_t, ResultValueType>>,
            quantity_point<si::degree_kelvin_t, ResultValueType>>
    {
        return quantity_point<si::degree_kelvin_t, ResultValueType>{rhs};
    }
};
template <>
struct simple_cast_impl<si::degree_kelvin_t, void>
{
    // From celsius to kelvin
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<si::temperature::degree_celsius_t, ArgumentValueType>& rhs) const
        noexcept -> quantity<si::degree_kelvin_t, ArgumentValueType>
    {
        return simple_cast_impl<quantity<si::degree_kelvin_t, ArgumentValueType>, void>{}(
            rhs);
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>& rhs)
        const noexcept -> quantity_point<si::degree_kelvin_t, ArgumentValueType>
    {
        return simple_cast_impl<quantity_point<si::degree_kelvin_t, ArgumentValueType>,
                                void>{}(rhs);
    }
    // From fahrenheit to kelvin
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<si::temperature::degree_fahrenheit_t, ArgumentValueType>& rhs)
        const noexcept -> quantity<si::degree_kelvin_t, ArgumentValueType>
    {
        return simple_cast_impl<quantity<si::degree_kelvin_t, ArgumentValueType>, void>{}(
            rhs);
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_fahrenheit_t, ArgumentValueType>&
            rhs) const noexcept -> quantity_point<si::degree_kelvin_t, ArgumentValueType>
    {
        return simple_cast_impl<quantity_point<si::degree_kelvin_t, ArgumentValueType>,
                                void>{}(rhs);
    }
    // From kelvin to kelvin
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<si::degree_kelvin_t, ArgumentValueType>
    {
        return simple_cast_impl<quantity<si::degree_kelvin_t, ArgumentValueType>, void>{}(
            rhs);
    }
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                             ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::degree_kelvin_t, ArgumentValueType>
    {
        return simple_cast_impl<quantity_point<si::degree_kelvin_t, ArgumentValueType>,
                                void>{}(rhs);
    }
};
template <class ResultValueType>
struct simple_cast_impl<
    quantity_point<si::temperature::degree_celsius_t, ResultValueType>, void>
{
    // From rankine to celsius
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_rankine_t, ArgumentValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_celsius_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_celsius_t, ResultValueType>{
            static_cast<ResultValueType>(
                rhs.value() / static_cast<ArgumentValueType>(prefix::rankine::value)
                + static_cast<ArgumentValueType>(prefix::absolute_zero::value))};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_rankine_t, ResultValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_celsius_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_celsius_t, ResultValueType>{
            rhs.value() / static_cast<ResultValueType>(prefix::rankine::value)
            + static_cast<ResultValueType>(prefix::absolute_zero::value)};
    }
    // From kelvin to celsius
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::degree_kelvin_t, ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_celsius_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_celsius_t, ResultValueType>{
            static_cast<ResultValueType>(
                rhs.value()
                + static_cast<ArgumentValueType>(prefix::absolute_zero::value))};
    }
    [[nodiscard]] constexpr inline auto
        operator()(const quantity_point<si::degree_kelvin_t, ResultValueType>& rhs) const
        noexcept -> quantity_point<si::temperature::degree_celsius_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_celsius_t, ResultValueType>{
            rhs.value() + static_cast<ResultValueType>(prefix::absolute_zero::value)};
    }
    // From fahrenheit to celsius
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity_point<si::temperature::degree_fahrenheit_t,
                                        ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_celsius_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_celsius_t, ResultValueType>{
            static_cast<ResultValueType>(
                (rhs.value()
                 - static_cast<ArgumentValueType>(prefix::freezing_point::value))
                / static_cast<ArgumentValueType>(prefix::rankine::value))};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_celsius_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_celsius_t, ResultValueType>{
            (rhs.value() - static_cast<ResultValueType>(prefix::freezing_point::value))
            / static_cast<ResultValueType>(prefix::rankine::value)};
    }
    // From celsius to celsius
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                             ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_celsius_t, ResultValueType>
    {
        constexpr auto factor = expand_prefix_list<
            ArgumentValueType,
            type::divide_lists<ArgumentPrefix,
                               typename si::temperature::degree_celsius_t::prefix>>;
        return quantity_point<si::temperature::degree_celsius_t, ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                             ResultValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_celsius_t, ResultValueType>
    {
        constexpr auto factor = expand_prefix_list<
            ResultValueType,
            type::divide_lists<ArgumentPrefix,
                               typename si::temperature::degree_celsius_t::prefix>>;
        return quantity_point<si::temperature::degree_celsius_t, ResultValueType>{
            rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_celsius_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_celsius_t, ResultValueType>{
            static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_celsius_t, ResultValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_celsius_t, ResultValueType>
    {
        return rhs;
    }
    // From Other to celsius
    template <class Other>
    [[nodiscard]] constexpr inline auto operator()(const Other& rhs) const noexcept
        -> std::enable_if_t<
            type::detect_if<
                Other, is_convertible_into,
                quantity_point<si::temperature::degree_celsius_t, ResultValueType>>,
            quantity_point<si::temperature::degree_celsius_t, ResultValueType>>
    {
        return quantity_point<si::temperature::degree_celsius_t, ResultValueType>{rhs};
    }
};
template <>
struct simple_cast_impl<si::temperature::degree_celsius_t, void>
{
    // From celsius to kelvin
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<si::temperature::degree_celsius_t, ArgumentValueType>& rhs) const
        noexcept -> quantity<si::temperature::degree_celsius_t, ArgumentValueType>
    {
        return simple_cast_impl<
            quantity<si::temperature::degree_celsius_t, ArgumentValueType>, void>{}(rhs);
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>
    {
        return simple_cast_impl<
            quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>, void>{}(
            rhs);
    }
    // From fahrenheit to kelvin
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<si::temperature::degree_fahrenheit_t, ArgumentValueType>& rhs)
        const noexcept -> quantity<si::temperature::degree_celsius_t, ArgumentValueType>
    {
        return simple_cast_impl<
            quantity<si::temperature::degree_celsius_t, ArgumentValueType>, void>{}(rhs);
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity_point<si::temperature::degree_fahrenheit_t,
                                        ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>
    {
        return simple_cast_impl<
            quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>, void>{}(
            rhs);
    }
    // From kelvin to kelvin
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<si::temperature::degree_celsius_t, ArgumentValueType>
    {
        return simple_cast_impl<
            quantity<si::temperature::degree_celsius_t, ArgumentValueType>, void>{}(rhs);
    }
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                             ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>
    {
        return simple_cast_impl<
            quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>, void>{}(
            rhs);
    }
};
template <class ResultValueType>
struct simple_cast_impl<
    quantity_point<si::temperature::degree_rankine_t, ResultValueType>, void>
{
    // From celsius to rankine
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_rankine_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_rankine_t, ResultValueType>{
            static_cast<ResultValueType>(
                rhs.value() * static_cast<ArgumentValueType>(prefix::rankine::value)
                - static_cast<ArgumentValueType>(prefix::absolute_zero::value)
                      * static_cast<ArgumentValueType>(prefix::rankine::value))};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_celsius_t, ResultValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_rankine_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_rankine_t, ResultValueType>{
            rhs.value() * static_cast<ResultValueType>(prefix::rankine::value)
            - static_cast<ResultValueType>(prefix::absolute_zero::value)
                  * static_cast<ResultValueType>(prefix::rankine::value)};
    }
    // From fahrenheit to rankine
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity_point<si::temperature::degree_fahrenheit_t,
                                        ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_rankine_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_rankine_t, ResultValueType>{
            static_cast<ResultValueType>(
                rhs.value()
                - static_cast<ArgumentValueType>(prefix::fahrenheit_zero::value))};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_rankine_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_rankine_t, ResultValueType>{
            rhs.value() - static_cast<ResultValueType>(prefix::fahrenheit_zero::value)};
    }
    // From rankine to rankine
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                             ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_rankine_t, ResultValueType>
    {
        constexpr auto factor = expand_prefix_list<
            ArgumentValueType,
            type::divide_lists<ArgumentPrefix,
                               typename si::temperature::degree_rankine_t::prefix>>;
        return quantity_point<si::temperature::degree_rankine_t, ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                             ResultValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_rankine_t, ResultValueType>
    {
        constexpr auto factor = expand_prefix_list<
            ResultValueType,
            type::divide_lists<ArgumentPrefix,
                               typename si::temperature::degree_rankine_t::prefix>>;
        return quantity_point<si::temperature::degree_rankine_t, ResultValueType>{
            rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_rankine_t, ArgumentValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_rankine_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_rankine_t, ResultValueType>{
            static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_rankine_t, ResultValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_rankine_t, ResultValueType>
    {
        return rhs;
    }
    // From Other to rankine
    template <class Other>
    [[nodiscard]] constexpr inline auto operator()(const Other& rhs) const noexcept
        -> std::enable_if_t<
            type::detect_if<
                Other, is_convertible_into,
                quantity_point<si::temperature::degree_rankine_t, ResultValueType>>,
            quantity_point<si::temperature::degree_rankine_t, ResultValueType>>
    {
        return quantity_point<si::temperature::degree_rankine_t, ResultValueType>{rhs};
    }
};
template <>
struct simple_cast_impl<si::temperature::degree_rankine_t, void>
{
    // From celsius to kelvin
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<si::temperature::degree_celsius_t, ArgumentValueType>& rhs) const
        noexcept -> quantity<si::temperature::degree_rankine_t, ArgumentValueType>
    {
        return simple_cast_impl<
            quantity<si::temperature::degree_rankine_t, ArgumentValueType>, void>{}(rhs);
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_rankine_t, ArgumentValueType>
    {
        return simple_cast_impl<
            quantity_point<si::temperature::degree_rankine_t, ArgumentValueType>, void>{}(
            rhs);
    }
    // From fahrenheit to kelvin
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<si::temperature::degree_fahrenheit_t, ArgumentValueType>& rhs)
        const noexcept -> quantity<si::temperature::degree_rankine_t, ArgumentValueType>
    {
        return simple_cast_impl<
            quantity<si::temperature::degree_rankine_t, ArgumentValueType>, void>{}(rhs);
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity_point<si::temperature::degree_fahrenheit_t,
                                        ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_rankine_t, ArgumentValueType>
    {
        return simple_cast_impl<
            quantity_point<si::temperature::degree_rankine_t, ArgumentValueType>, void>{}(
            rhs);
    }
    // From kelvin to kelvin
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<si::temperature::degree_rankine_t, ArgumentValueType>
    {
        return simple_cast_impl<
            quantity<si::temperature::degree_rankine_t, ArgumentValueType>, void>{}(rhs);
    }
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                             ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_rankine_t, ArgumentValueType>
    {
        return simple_cast_impl<
            quantity_point<si::temperature::degree_rankine_t, ArgumentValueType>, void>{}(
            rhs);
    }
};
template <class ResultValueType>
struct simple_cast_impl<
    quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>, void>
{
    // From kelvin to fahrenheit
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::degree_kelvin_t, ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>{
            static_cast<ResultValueType>(
                rhs.value() * static_cast<ArgumentValueType>(prefix::rankine::value)
                + static_cast<ArgumentValueType>(prefix::fahrenheit_zero::value))};
    }
    [[nodiscard]] constexpr inline auto
        operator()(const quantity_point<si::degree_kelvin_t, ResultValueType>& rhs) const
        noexcept -> quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>{
            rhs.value() * static_cast<ResultValueType>(prefix::rankine::value)
            + static_cast<ResultValueType>(prefix::fahrenheit_zero::value)};
    }
    // From celsius to fahrenheit
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>{
            static_cast<ResultValueType>(
                rhs.value() * static_cast<ArgumentValueType>(prefix::rankine::value)
                + static_cast<ArgumentValueType>(prefix::fahrenheit_zero::value)
                - static_cast<ArgumentValueType>(prefix::rankine::value)
                      * static_cast<ArgumentValueType>(prefix::absolute_zero::value))};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_celsius_t, ResultValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>{
            rhs.value() * static_cast<ResultValueType>(prefix::rankine::value)
            + static_cast<ResultValueType>(prefix::fahrenheit_zero::value)
            - static_cast<ResultValueType>(prefix::rankine::value)
                  * static_cast<ResultValueType>(prefix::absolute_zero::value)};
    }
    // From rankine to fahrenheit
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_rankine_t, ArgumentValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>{
            static_cast<ResultValueType>(
                rhs.value()
                + static_cast<ArgumentValueType>(prefix::fahrenheit_zero::value))};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_rankine_t, ResultValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>{
            rhs.value() + static_cast<ResultValueType>(prefix::fahrenheit_zero::value)};
    }
    // From fahrenheit to fahrenheit
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                             ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>
    {
        constexpr auto factor = expand_prefix_list<
            ArgumentValueType,
            type::divide_lists<ArgumentPrefix,
                               typename si::temperature::degree_fahrenheit_t::prefix>>;
        return quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                             ResultValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>
    {
        constexpr auto factor = expand_prefix_list<
            ResultValueType,
            type::divide_lists<ArgumentPrefix,
                               typename si::temperature::degree_fahrenheit_t::prefix>>;
        return quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>{
            rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity_point<si::temperature::degree_fahrenheit_t,
                                        ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>{
            static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>
    {
        return rhs;
    }
    // From Other to fahrenheit
    template <class Other>
    [[nodiscard]] constexpr inline auto operator()(const Other& rhs) const noexcept
        -> std::enable_if_t<
            type::detect_if<
                Other, is_convertible_into,
                quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>>,
            quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>>
    {
        return quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>{rhs};
    }
};
template <>
struct simple_cast_impl<si::temperature::degree_fahrenheit_t, void>
{
    // From celsius to kelvin
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<si::temperature::degree_celsius_t, ArgumentValueType>& rhs) const
        noexcept -> quantity<si::temperature::degree_fahrenheit_t, ArgumentValueType>
    {
        return simple_cast_impl<
            quantity<si::temperature::degree_fahrenheit_t, ArgumentValueType>, void>{}(
            rhs);
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_fahrenheit_t, ArgumentValueType>
    {
        return simple_cast_impl<
            quantity_point<si::temperature::degree_fahrenheit_t, ArgumentValueType>,
            void>{}(rhs);
    }
    // From fahrenheit to kelvin
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<si::temperature::degree_fahrenheit_t, ArgumentValueType>& rhs)
        const noexcept
        -> quantity<si::temperature::degree_fahrenheit_t, ArgumentValueType>
    {
        return simple_cast_impl<
            quantity<si::temperature::degree_fahrenheit_t, ArgumentValueType>, void>{}(
            rhs);
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity_point<si::temperature::degree_fahrenheit_t,
                                        ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_fahrenheit_t, ArgumentValueType>
    {
        return simple_cast_impl<
            quantity_point<si::temperature::degree_fahrenheit_t, ArgumentValueType>,
            void>{}(rhs);
    }
    // From kelvin to kelvin
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<si::temperature::degree_fahrenheit_t, ArgumentValueType>
    {
        return simple_cast_impl<
            quantity<si::temperature::degree_fahrenheit_t, ArgumentValueType>, void>{}(
            rhs);
    }
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                             ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_fahrenheit_t, ArgumentValueType>
    {
        return simple_cast_impl<
            quantity_point<si::temperature::degree_fahrenheit_t, ArgumentValueType>,
            void>{}(rhs);
    }
};
// quantity
template <class ResultPrefix, class ResultValueType>
struct simple_cast_impl<
    quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>, ResultValueType>,
    void>
{
    // From thermodynamic_temperature to thermodynamic_temperature
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        constexpr auto factor =
            expand_prefix_list<ArgumentValueType,
                               type::divide_lists<ArgumentPrefix, ResultPrefix>>;
        return quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                        ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                       ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        constexpr auto factor =
            expand_prefix_list<ResultValueType,
                               type::divide_lists<ArgumentPrefix, ResultPrefix>>;
        return quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                        ResultValueType>{rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        return quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                        ResultValueType>{static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                       ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        return rhs;
    }
    // From celsius_temperature to thermodynamic_temperature
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::celsius_temperature_t, ArgumentPrefix>,
                                  ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        constexpr auto factor =
            expand_prefix_list<ArgumentValueType,
                               type::divide_lists<ArgumentPrefix, ResultPrefix>>;
        return quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                        ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::celsius_temperature_t, ArgumentPrefix>,
                                  ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        constexpr auto factor =
            expand_prefix_list<ResultValueType,
                               type::divide_lists<ArgumentPrefix, ResultPrefix>>;
        return quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                        ResultValueType>{rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                                  ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        return quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                        ResultValueType>{static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                                  ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        return rhs;
    }
    // From fahrenheit_temperature to thermodynamic_temperature
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::fahrenheit_temperature_t, ArgumentPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        constexpr auto factor =
            expand_prefix_list<ArgumentValueType,
                               type::divide_lists<ArgumentPrefix, ResultPrefix>>;
        return quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                        ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::fahrenheit_temperature_t, ArgumentPrefix>,
                       ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        constexpr auto factor =
            expand_prefix_list<ResultValueType,
                               type::divide_lists<ArgumentPrefix, ResultPrefix>>;
        return quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                        ResultValueType>{rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                                  ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        return quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                        ResultValueType>{static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                                  ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        return rhs;
    }
    // From Other to thermodynamic_temperature
    template <class Other>
    [[nodiscard]] constexpr inline auto operator()(const Other& rhs) const noexcept
        -> std::enable_if_t<
            type::detect_if<
                Other, is_convertible_into,
                quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                         ResultValueType>>,
            quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                     ResultValueType>>
    {
        return quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                        ResultValueType>{rhs};
    }
};
template <class ResultPrefix, class ResultValueType>
struct simple_cast_impl<
    quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>, void>
{
    // From thermodynamic_temperature to celsius_temperature
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>
    {
        constexpr auto factor =
            expand_prefix_list<ArgumentValueType,
                               type::divide_lists<ArgumentPrefix, ResultPrefix>>;
        return quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                        ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                       ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>
    {
        constexpr auto factor =
            expand_prefix_list<ResultValueType,
                               type::divide_lists<ArgumentPrefix, ResultPrefix>>;
        return quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                        ResultValueType>{rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>
    {
        return quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                        ResultValueType>{static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                       ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>
    {
        return rhs;
    }
    // From celsius_temperature to celsius_temperature
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::celsius_temperature_t, ArgumentPrefix>,
                                  ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>
    {
        constexpr auto factor =
            expand_prefix_list<ArgumentValueType,
                               type::divide_lists<ArgumentPrefix, ResultPrefix>>;
        return quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                        ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::celsius_temperature_t, ArgumentPrefix>,
                                  ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>
    {
        constexpr auto factor =
            expand_prefix_list<ResultValueType,
                               type::divide_lists<ArgumentPrefix, ResultPrefix>>;
        return quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                        ResultValueType>{rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                                  ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>
    {
        return quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                        ResultValueType>{static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                                  ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>
    {
        return rhs;
    }
    // From fahrenheit_temperature to celsius_temperature
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::fahrenheit_temperature_t, ArgumentPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>
    {
        constexpr auto factor =
            expand_prefix_list<ArgumentValueType,
                               type::divide_lists<ArgumentPrefix, ResultPrefix>>;
        return quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                        ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::fahrenheit_temperature_t, ArgumentPrefix>,
                       ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>
    {
        constexpr auto factor =
            expand_prefix_list<ResultValueType,
                               type::divide_lists<ArgumentPrefix, ResultPrefix>>;
        return quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                        ResultValueType>{rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                                  ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>
    {
        return quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                        ResultValueType>{static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                                  ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>
    {
        return rhs;
    }
    // From Other to celsius_temperature
    template <class Other>
    [[nodiscard]] constexpr inline auto operator()(const Other& rhs) const noexcept
        -> std::enable_if_t<
            type::detect_if<Other, is_convertible_into,
                            quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                                     ResultValueType>>,
            quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                     ResultValueType>>
    {
        return quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                        ResultValueType>{rhs};
    }
};
template <class ResultPrefix, class ResultValueType>
struct simple_cast_impl<
    quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>, ResultValueType>,
    void>
{
    // From thermodynamic_temperature to fahrenheit_temperature
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        constexpr auto factor =
            expand_prefix_list<ArgumentValueType,
                               type::divide_lists<ArgumentPrefix, ResultPrefix>>;
        return quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                        ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                       ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        constexpr auto factor =
            expand_prefix_list<ResultValueType,
                               type::divide_lists<ArgumentPrefix, ResultPrefix>>;
        return quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                        ResultValueType>{rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        return quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                        ResultValueType>{static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                       ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        return rhs;
    }
    // From celsius_temperature to fahrenheit_temperature
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::celsius_temperature_t, ArgumentPrefix>,
                                  ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        constexpr auto factor =
            expand_prefix_list<ArgumentValueType,
                               type::divide_lists<ArgumentPrefix, ResultPrefix>>;
        return quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                        ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::celsius_temperature_t, ArgumentPrefix>,
                                  ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        constexpr auto factor =
            expand_prefix_list<ResultValueType,
                               type::divide_lists<ArgumentPrefix, ResultPrefix>>;
        return quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                        ResultValueType>{rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                                  ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        return quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                        ResultValueType>{static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                                  ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        return rhs;
    }
    // From fahrenheit_temperature to fahrenheit_temperature
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::fahrenheit_temperature_t, ArgumentPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        constexpr auto factor =
            expand_prefix_list<ArgumentValueType,
                               type::divide_lists<ArgumentPrefix, ResultPrefix>>;
        return quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                        ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::fahrenheit_temperature_t, ArgumentPrefix>,
                       ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        constexpr auto factor =
            expand_prefix_list<ResultValueType,
                               type::divide_lists<ArgumentPrefix, ResultPrefix>>;
        return quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                        ResultValueType>{rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                                  ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        return quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                        ResultValueType>{static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                                  ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        return rhs;
    }
    // From Other to fahrenheit_temperature
    template <class Other>
    [[nodiscard]] constexpr inline auto operator()(const Other& rhs) const noexcept
        -> std::enable_if_t<
            type::detect_if<
                Other, is_convertible_into,
                quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                         ResultValueType>>,
            quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                     ResultValueType>>
    {
        return quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                        ResultValueType>{rhs};
    }
};
#pragma endregion
#pragma region unit_cast
// quantity_point
template <class ResultValueType>
struct unit_cast_impl<quantity_point<si::degree_kelvin_t, ResultValueType>, void>
{
    // From celsius to kelvin
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>& rhs)
        const noexcept -> quantity_point<si::degree_kelvin_t, ResultValueType>
    {
        return quantity_point<si::degree_kelvin_t, ResultValueType>{
            static_cast<ResultValueType>(
                rhs.value()
                - static_cast<ArgumentValueType>(prefix::absolute_zero::value))};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_celsius_t, ResultValueType>& rhs)
        const noexcept -> quantity_point<si::degree_kelvin_t, ResultValueType>
    {
        return quantity_point<si::degree_kelvin_t, ResultValueType>{
            rhs.value() - static_cast<ResultValueType>(prefix::absolute_zero::value)};
    }
    // From fahrenheit to kelvin
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_fahrenheit_t, ArgumentValueType>&
            rhs) const noexcept -> quantity_point<si::degree_kelvin_t, ResultValueType>
    {
        return quantity_point<si::degree_kelvin_t, ResultValueType>{
            static_cast<ResultValueType>(
                rhs.value() / static_cast<ArgumentValueType>(prefix::rankine::value)
                - static_cast<ArgumentValueType>(prefix::fahrenheit_zero::value)
                      / static_cast<ArgumentValueType>(prefix::rankine::value))};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>& rhs)
        const noexcept -> quantity_point<si::degree_kelvin_t, ResultValueType>
    {
        return quantity_point<si::degree_kelvin_t, ResultValueType>{
            rhs.value() / static_cast<ResultValueType>(prefix::rankine::value)
            - static_cast<ResultValueType>(prefix::fahrenheit_zero::value)
                  / static_cast<ResultValueType>(prefix::rankine::value)};
    }
    // From kelvin to kelvin
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                             ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::degree_kelvin_t, ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ArgumentValueType>(
            type::divide_lists<ArgumentPrefix, typename si::degree_kelvin_t::prefix>{});
        return quantity_point<si::degree_kelvin_t, ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                             ResultValueType>& rhs) const noexcept
        -> quantity_point<si::degree_kelvin_t, ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ResultValueType>(
            type::divide_lists<ArgumentPrefix, typename si::degree_kelvin_t::prefix>{});
        return quantity_point<si::degree_kelvin_t, ResultValueType>{rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::degree_kelvin_t, ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::degree_kelvin_t, ResultValueType>
    {
        return quantity_point<si::degree_kelvin_t, ResultValueType>{
            static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto
        operator()(const quantity_point<si::degree_kelvin_t, ResultValueType>& rhs) const
        noexcept -> quantity_point<si::degree_kelvin_t, ResultValueType>
    {
        return rhs;
    }
    // From Other to kelvin
    template <class Other>
    [[nodiscard]] constexpr inline auto operator()(const Other& rhs) const noexcept
        -> std::enable_if_t<
            type::detect_if<Other, is_convertible_into,
                            quantity_point<si::degree_kelvin_t, ResultValueType>>,
            quantity_point<si::degree_kelvin_t, ResultValueType>>
    {
        return quantity_point<si::degree_kelvin_t, ResultValueType>{rhs};
    }
};
template <>
struct unit_cast_impl<si::degree_kelvin_t, void>
{
    // From celsius to kelvin
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<si::temperature::degree_celsius_t, ArgumentValueType>& rhs) const
        noexcept -> quantity<si::degree_kelvin_t, ArgumentValueType>
    {
        return unit_cast_impl<quantity<si::degree_kelvin_t, ArgumentValueType>, void>{}(
            rhs);
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>& rhs)
        const noexcept -> quantity_point<si::degree_kelvin_t, ArgumentValueType>
    {
        return unit_cast_impl<quantity_point<si::degree_kelvin_t, ArgumentValueType>,
                              void>{}(rhs);
    }
    // From fahrenheit to kelvin
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<si::temperature::degree_fahrenheit_t, ArgumentValueType>& rhs)
        const noexcept -> quantity<si::degree_kelvin_t, ArgumentValueType>
    {
        return unit_cast_impl<quantity<si::degree_kelvin_t, ArgumentValueType>, void>{}(
            rhs);
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_fahrenheit_t, ArgumentValueType>&
            rhs) const noexcept -> quantity_point<si::degree_kelvin_t, ArgumentValueType>
    {
        return unit_cast_impl<quantity_point<si::degree_kelvin_t, ArgumentValueType>,
                              void>{}(rhs);
    }
    // From kelvin to kelvin
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<si::degree_kelvin_t, ArgumentValueType>
    {
        return unit_cast_impl<quantity<si::degree_kelvin_t, ArgumentValueType>, void>{}(
            rhs);
    }
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                             ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::degree_kelvin_t, ArgumentValueType>
    {
        return unit_cast_impl<quantity_point<si::degree_kelvin_t, ArgumentValueType>,
                              void>{}(rhs);
    }
};
template <class ResultValueType>
struct unit_cast_impl<quantity_point<si::temperature::degree_celsius_t, ResultValueType>,
                      void>
{
    // From rankine to celsius
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_rankine_t, ArgumentValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_celsius_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_celsius_t, ResultValueType>{
            static_cast<ResultValueType>(
                rhs.value() / static_cast<ArgumentValueType>(prefix::rankine::value)
                + static_cast<ArgumentValueType>(prefix::absolute_zero::value))};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_rankine_t, ResultValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_celsius_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_celsius_t, ResultValueType>{
            rhs.value() / static_cast<ResultValueType>(prefix::rankine::value)
            + static_cast<ResultValueType>(prefix::absolute_zero::value)};
    }
    // From kelvin to celsius
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::degree_kelvin_t, ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_celsius_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_celsius_t, ResultValueType>{
            static_cast<ResultValueType>(
                rhs.value()
                + static_cast<ArgumentValueType>(prefix::absolute_zero::value))};
    }
    [[nodiscard]] constexpr inline auto
        operator()(const quantity_point<si::degree_kelvin_t, ResultValueType>& rhs) const
        noexcept -> quantity_point<si::temperature::degree_celsius_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_celsius_t, ResultValueType>{
            rhs.value() + static_cast<ResultValueType>(prefix::absolute_zero::value)};
    }
    // From fahrenheit to celsius
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity_point<si::temperature::degree_fahrenheit_t,
                                        ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_celsius_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_celsius_t, ResultValueType>{
            static_cast<ResultValueType>(
                (rhs.value()
                 - static_cast<ArgumentValueType>(prefix::freezing_point::value))
                / static_cast<ArgumentValueType>(prefix::rankine::value))};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_celsius_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_celsius_t, ResultValueType>{
            (rhs.value() - static_cast<ResultValueType>(prefix::freezing_point::value))
            / static_cast<ResultValueType>(prefix::rankine::value)};
    }
    // From celsius to celsius
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                             ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_celsius_t, ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ArgumentValueType>(
            type::divide_lists<ArgumentPrefix,
                               typename si::temperature::degree_celsius_t::prefix>{});
        return quantity_point<si::temperature::degree_celsius_t, ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                             ResultValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_celsius_t, ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ResultValueType>(
            type::divide_lists<ArgumentPrefix,
                               typename si::temperature::degree_celsius_t::prefix>{});
        return quantity_point<si::temperature::degree_celsius_t, ResultValueType>{
            rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_celsius_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_celsius_t, ResultValueType>{
            static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_celsius_t, ResultValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_celsius_t, ResultValueType>
    {
        return rhs;
    }
    // From Other to celsius
    template <class Other>
    [[nodiscard]] constexpr inline auto operator()(const Other& rhs) const noexcept
        -> std::enable_if_t<
            type::detect_if<
                Other, is_convertible_into,
                quantity_point<si::temperature::degree_celsius_t, ResultValueType>>,
            quantity_point<si::temperature::degree_celsius_t, ResultValueType>>
    {
        return quantity_point<si::temperature::degree_celsius_t, ResultValueType>{rhs};
    }
};
template <>
struct unit_cast_impl<si::temperature::degree_celsius_t, void>
{
    // From celsius to kelvin
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<si::temperature::degree_celsius_t, ArgumentValueType>& rhs) const
        noexcept -> quantity<si::temperature::degree_celsius_t, ArgumentValueType>
    {
        return unit_cast_impl<
            quantity<si::temperature::degree_celsius_t, ArgumentValueType>, void>{}(rhs);
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>
    {
        return unit_cast_impl<
            quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>, void>{}(
            rhs);
    }
    // From fahrenheit to kelvin
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<si::temperature::degree_fahrenheit_t, ArgumentValueType>& rhs)
        const noexcept -> quantity<si::temperature::degree_celsius_t, ArgumentValueType>
    {
        return unit_cast_impl<
            quantity<si::temperature::degree_celsius_t, ArgumentValueType>, void>{}(rhs);
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity_point<si::temperature::degree_fahrenheit_t,
                                        ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>
    {
        return unit_cast_impl<
            quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>, void>{}(
            rhs);
    }
    // From kelvin to kelvin
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<si::temperature::degree_celsius_t, ArgumentValueType>
    {
        return unit_cast_impl<
            quantity<si::temperature::degree_celsius_t, ArgumentValueType>, void>{}(rhs);
    }
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                             ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>
    {
        return unit_cast_impl<
            quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>, void>{}(
            rhs);
    }
};
template <class ResultValueType>
struct unit_cast_impl<quantity_point<si::temperature::degree_rankine_t, ResultValueType>,
                      void>
{
    // From celsius to rankine
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_rankine_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_rankine_t, ResultValueType>{
            static_cast<ResultValueType>(
                rhs.value() * static_cast<ArgumentValueType>(prefix::rankine::value)
                - static_cast<ArgumentValueType>(prefix::absolute_zero::value)
                      * static_cast<ArgumentValueType>(prefix::rankine::value))};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_celsius_t, ResultValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_rankine_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_rankine_t, ResultValueType>{
            rhs.value() * static_cast<ResultValueType>(prefix::rankine::value)
            - static_cast<ResultValueType>(prefix::absolute_zero::value)
                  * static_cast<ResultValueType>(prefix::rankine::value)};
    }
    // From fahrenheit to rankine
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity_point<si::temperature::degree_fahrenheit_t,
                                        ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_rankine_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_rankine_t, ResultValueType>{
            static_cast<ResultValueType>(
                rhs.value()
                - static_cast<ArgumentValueType>(prefix::fahrenheit_zero::value))};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_rankine_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_rankine_t, ResultValueType>{
            rhs.value() - static_cast<ResultValueType>(prefix::fahrenheit_zero::value)};
    }
    // From rankine to rankine
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                             ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_rankine_t, ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ArgumentValueType>(
            type::divide_lists<ArgumentPrefix,
                               typename si::temperature::degree_rankine_t::prefix>{});
        return quantity_point<si::temperature::degree_rankine_t, ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                             ResultValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_rankine_t, ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ResultValueType>(
            type::divide_lists<ArgumentPrefix,
                               typename si::temperature::degree_rankine_t::prefix>{});
        return quantity_point<si::temperature::degree_rankine_t, ResultValueType>{
            rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_rankine_t, ArgumentValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_rankine_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_rankine_t, ResultValueType>{
            static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_rankine_t, ResultValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_rankine_t, ResultValueType>
    {
        return rhs;
    }
    // From Other to rankine
    template <class Other>
    [[nodiscard]] constexpr inline auto operator()(const Other& rhs) const noexcept
        -> std::enable_if_t<
            type::detect_if<
                Other, is_convertible_into,
                quantity_point<si::temperature::degree_rankine_t, ResultValueType>>,
            quantity_point<si::temperature::degree_rankine_t, ResultValueType>>
    {
        return quantity_point<si::temperature::degree_rankine_t, ResultValueType>{rhs};
    }
};
template <>
struct unit_cast_impl<si::temperature::degree_rankine_t, void>
{
    // From celsius to kelvin
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<si::temperature::degree_celsius_t, ArgumentValueType>& rhs) const
        noexcept -> quantity<si::temperature::degree_rankine_t, ArgumentValueType>
    {
        return unit_cast_impl<
            quantity<si::temperature::degree_rankine_t, ArgumentValueType>, void>{}(rhs);
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_rankine_t, ArgumentValueType>
    {
        return unit_cast_impl<
            quantity_point<si::temperature::degree_rankine_t, ArgumentValueType>, void>{}(
            rhs);
    }
    // From fahrenheit to kelvin
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<si::temperature::degree_fahrenheit_t, ArgumentValueType>& rhs)
        const noexcept -> quantity<si::temperature::degree_rankine_t, ArgumentValueType>
    {
        return unit_cast_impl<
            quantity<si::temperature::degree_rankine_t, ArgumentValueType>, void>{}(rhs);
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity_point<si::temperature::degree_fahrenheit_t,
                                        ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_rankine_t, ArgumentValueType>
    {
        return unit_cast_impl<
            quantity_point<si::temperature::degree_rankine_t, ArgumentValueType>, void>{}(
            rhs);
    }
    // From kelvin to kelvin
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<si::temperature::degree_rankine_t, ArgumentValueType>
    {
        return unit_cast_impl<
            quantity<si::temperature::degree_rankine_t, ArgumentValueType>, void>{}(rhs);
    }
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                             ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_rankine_t, ArgumentValueType>
    {
        return unit_cast_impl<
            quantity_point<si::temperature::degree_rankine_t, ArgumentValueType>, void>{}(
            rhs);
    }
};
template <class ResultValueType>
struct unit_cast_impl<
    quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>, void>
{
    // From kelvin to fahrenheit
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::degree_kelvin_t, ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>{
            static_cast<ResultValueType>(
                rhs.value() * static_cast<ArgumentValueType>(prefix::rankine::value)
                + static_cast<ArgumentValueType>(prefix::fahrenheit_zero::value))};
    }
    [[nodiscard]] constexpr inline auto
        operator()(const quantity_point<si::degree_kelvin_t, ResultValueType>& rhs) const
        noexcept -> quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>{
            rhs.value() * static_cast<ResultValueType>(prefix::rankine::value)
            + static_cast<ResultValueType>(prefix::fahrenheit_zero::value)};
    }
    // From celsius to fahrenheit
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>{
            static_cast<ResultValueType>(
                rhs.value() * static_cast<ArgumentValueType>(prefix::rankine::value)
                + static_cast<ArgumentValueType>(prefix::fahrenheit_zero::value)
                - static_cast<ArgumentValueType>(prefix::rankine::value)
                      * static_cast<ArgumentValueType>(prefix::absolute_zero::value))};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_celsius_t, ResultValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>{
            rhs.value() * static_cast<ResultValueType>(prefix::rankine::value)
            + static_cast<ResultValueType>(prefix::fahrenheit_zero::value)
            - static_cast<ResultValueType>(prefix::rankine::value)
                  * static_cast<ResultValueType>(prefix::absolute_zero::value)};
    }
    // From rankine to fahrenheit
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_rankine_t, ArgumentValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>{
            static_cast<ResultValueType>(
                rhs.value()
                + static_cast<ArgumentValueType>(prefix::fahrenheit_zero::value))};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_rankine_t, ResultValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>{
            rhs.value() + static_cast<ResultValueType>(prefix::fahrenheit_zero::value)};
    }
    // From fahrenheit to fahrenheit
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                             ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>
    {
        constexpr auto factor = runtime_expand_prefix_list<ArgumentValueType>(
            type::divide_lists<ArgumentPrefix,
                               typename si::temperature::degree_fahrenheit_t::prefix>{});
        return quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                             ResultValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>
    {
        constexpr auto factor = runtime_expand_prefix_list<ResultValueType>(
            type::divide_lists<ArgumentPrefix,
                               typename si::temperature::degree_fahrenheit_t::prefix>{});
        return quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>{
            rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity_point<si::temperature::degree_fahrenheit_t,
                                        ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>
    {
        return quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>{
            static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>
    {
        return rhs;
    }
    // From Other to fahrenheit
    template <class Other>
    [[nodiscard]] constexpr inline auto operator()(const Other& rhs) const noexcept
        -> std::enable_if_t<
            type::detect_if<
                Other, is_convertible_into,
                quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>>,
            quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>>
    {
        return quantity_point<si::temperature::degree_fahrenheit_t, ResultValueType>{rhs};
    }
};
template <>
struct unit_cast_impl<si::temperature::degree_fahrenheit_t, void>
{
    // From celsius to kelvin
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<si::temperature::degree_celsius_t, ArgumentValueType>& rhs) const
        noexcept -> quantity<si::temperature::degree_fahrenheit_t, ArgumentValueType>
    {
        return unit_cast_impl<
            quantity<si::temperature::degree_fahrenheit_t, ArgumentValueType>, void>{}(
            rhs);
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<si::temperature::degree_celsius_t, ArgumentValueType>& rhs)
        const noexcept
        -> quantity_point<si::temperature::degree_fahrenheit_t, ArgumentValueType>
    {
        return unit_cast_impl<
            quantity_point<si::temperature::degree_fahrenheit_t, ArgumentValueType>,
            void>{}(rhs);
    }
    // From fahrenheit to kelvin
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<si::temperature::degree_fahrenheit_t, ArgumentValueType>& rhs)
        const noexcept
        -> quantity<si::temperature::degree_fahrenheit_t, ArgumentValueType>
    {
        return unit_cast_impl<
            quantity<si::temperature::degree_fahrenheit_t, ArgumentValueType>, void>{}(
            rhs);
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity_point<si::temperature::degree_fahrenheit_t,
                                        ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_fahrenheit_t, ArgumentValueType>
    {
        return unit_cast_impl<
            quantity_point<si::temperature::degree_fahrenheit_t, ArgumentValueType>,
            void>{}(rhs);
    }
    // From kelvin to kelvin
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<si::temperature::degree_fahrenheit_t, ArgumentValueType>
    {
        return unit_cast_impl<
            quantity<si::temperature::degree_fahrenheit_t, ArgumentValueType>, void>{}(
            rhs);
    }
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity_point<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                             ArgumentValueType>& rhs) const noexcept
        -> quantity_point<si::temperature::degree_fahrenheit_t, ArgumentValueType>
    {
        return unit_cast_impl<
            quantity_point<si::temperature::degree_fahrenheit_t, ArgumentValueType>,
            void>{}(rhs);
    }
};
// quantity
template <class ResultPrefix, class ResultValueType>
struct unit_cast_impl<
    quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>, ResultValueType>,
    void>
{
    // From thermodynamic_temperature to thermodynamic_temperature
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ArgumentValueType>(
            type::divide_lists<ArgumentPrefix, ResultPrefix>{});
        return quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                        ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                       ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ResultValueType>(
            type::divide_lists<ArgumentPrefix, ResultPrefix>{});
        return quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                        ResultValueType>{rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        return quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                        ResultValueType>{static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                       ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        return rhs;
    }
    // From celsius_temperature to thermodynamic_temperature
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::celsius_temperature_t, ArgumentPrefix>,
                                  ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ArgumentValueType>(
            type::divide_lists<ArgumentPrefix, ResultPrefix>{});
        return quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                        ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::celsius_temperature_t, ArgumentPrefix>,
                                  ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ResultValueType>(
            type::divide_lists<ArgumentPrefix, ResultPrefix>{});
        return quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                        ResultValueType>{rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                                  ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        return quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                        ResultValueType>{static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                                  ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        return rhs;
    }
    // From fahrenheit_temperature to thermodynamic_temperature
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::fahrenheit_temperature_t, ArgumentPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ArgumentValueType>(
            type::divide_lists<ArgumentPrefix, ResultPrefix>{});
        return quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                        ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::fahrenheit_temperature_t, ArgumentPrefix>,
                       ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ResultValueType>(
            type::divide_lists<ArgumentPrefix, ResultPrefix>{});
        return quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                        ResultValueType>{rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                                  ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        return quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                        ResultValueType>{static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                                  ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        return rhs;
    }
    // From Other to thermodynamic_temperature
    template <class Other>
    [[nodiscard]] constexpr inline auto operator()(const Other& rhs) const noexcept
        -> std::enable_if_t<
            type::detect_if<
                Other, is_convertible_into,
                quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                         ResultValueType>>,
            quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                     ResultValueType>>
    {
        return quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                        ResultValueType>{rhs};
    }
};
template <class ResultPrefix, class ResultValueType>
struct unit_cast_impl<
    quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>, void>
{
    // From thermodynamic_temperature to celsius_temperature
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ArgumentValueType>(
            type::divide_lists<ArgumentPrefix, ResultPrefix>{});
        return quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                        ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                       ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ResultValueType>(
            type::divide_lists<ArgumentPrefix, ResultPrefix>{});
        return quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                        ResultValueType>{rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>
    {
        return quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                        ResultValueType>{static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                       ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>
    {
        return rhs;
    }
    // From celsius_temperature to celsius_temperature
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::celsius_temperature_t, ArgumentPrefix>,
                                  ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ArgumentValueType>(
            type::divide_lists<ArgumentPrefix, ResultPrefix>{});
        return quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                        ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::celsius_temperature_t, ArgumentPrefix>,
                                  ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ResultValueType>(
            type::divide_lists<ArgumentPrefix, ResultPrefix>{});
        return quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                        ResultValueType>{rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                                  ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>
    {
        return quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                        ResultValueType>{static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                                  ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>
    {
        return rhs;
    }
    // From fahrenheit_temperature to celsius_temperature
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::fahrenheit_temperature_t, ArgumentPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ArgumentValueType>(
            type::divide_lists<ArgumentPrefix, ResultPrefix>{});
        return quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                        ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::fahrenheit_temperature_t, ArgumentPrefix>,
                       ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ResultValueType>(
            type::divide_lists<ArgumentPrefix, ResultPrefix>{});
        return quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                        ResultValueType>{rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                                  ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>
    {
        return quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                        ResultValueType>{static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                                  ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::celsius_temperature_t, ResultPrefix>, ResultValueType>
    {
        return rhs;
    }
    // From Other to celsius_temperature
    template <class Other>
    [[nodiscard]] constexpr inline auto operator()(const Other& rhs) const noexcept
        -> std::enable_if_t<
            type::detect_if<Other, is_convertible_into,
                            quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                                     ResultValueType>>,
            quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                     ResultValueType>>
    {
        return quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                        ResultValueType>{rhs};
    }
};
template <class ResultPrefix, class ResultValueType>
struct unit_cast_impl<
    quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>, ResultValueType>,
    void>
{
    // From thermodynamic_temperature to fahrenheit_temperature
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ArgumentValueType>(
            type::divide_lists<ArgumentPrefix, ResultPrefix>{});
        return quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                        ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ArgumentPrefix>,
                       ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ResultValueType>(
            type::divide_lists<ArgumentPrefix, ResultPrefix>{});
        return quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                        ResultValueType>{rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        return quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                        ResultValueType>{static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::thermodynamic_temperature_t, ResultPrefix>,
                       ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        return rhs;
    }
    // From celsius_temperature to fahrenheit_temperature
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::celsius_temperature_t, ArgumentPrefix>,
                                  ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ArgumentValueType>(
            type::divide_lists<ArgumentPrefix, ResultPrefix>{});
        return quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                        ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::celsius_temperature_t, ArgumentPrefix>,
                                  ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ResultValueType>(
            type::divide_lists<ArgumentPrefix, ResultPrefix>{});
        return quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                        ResultValueType>{rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                                  ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        return quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                        ResultValueType>{static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::celsius_temperature_t, ResultPrefix>,
                                  ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        return rhs;
    }
    // From fahrenheit_temperature to fahrenheit_temperature
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::fahrenheit_temperature_t, ArgumentPrefix>,
                       ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ArgumentValueType>(
            type::divide_lists<ArgumentPrefix, ResultPrefix>{});
        return quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                        ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr inline auto operator()(
        const quantity<unit<dimension::fahrenheit_temperature_t, ArgumentPrefix>,
                       ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ResultValueType>(
            type::divide_lists<ArgumentPrefix, ResultPrefix>{});
        return quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                        ResultValueType>{rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                                  ArgumentValueType>& rhs) const noexcept
        -> quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        return quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                        ResultValueType>{static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr inline auto
        operator()(const quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                                  ResultValueType>& rhs) const noexcept
        -> quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                    ResultValueType>
    {
        return rhs;
    }
    // From Other to fahrenheit_temperature
    template <class Other>
    [[nodiscard]] constexpr inline auto operator()(const Other& rhs) const noexcept
        -> std::enable_if_t<
            type::detect_if<
                Other, is_convertible_into,
                quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                         ResultValueType>>,
            quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                     ResultValueType>>
    {
        return quantity<unit<dimension::fahrenheit_temperature_t, ResultPrefix>,
                        ResultValueType>{rhs};
    }
};
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