#pragma once
#include <benri/si/si.h>
#include <chrono>
#include <ratio>

namespace benri
{
namespace dimension
{
#pragma region dimension symbols
struct SystemT
{
    static constexpr auto name = meta::static_string{"SystemT"};
}; // std::chrono::system_clock
struct SteadyT
{
    static constexpr auto name = meta::static_string{"SteadyT"};
}; // std::chrono::steady_clock
struct HighResT
{
    static constexpr auto name = meta::static_string{"HighResT"};
}; // std::chrono::high_resolution_clock
#pragma endregion
#pragma region base dimensions
using system_clock_t          = make_dimension<helper<SystemT>>;
using steady_clock_t          = make_dimension<helper<SteadyT>>;
using high_resolution_clock_t = make_dimension<helper<HighResT>>;
#pragma endregion
} // namespace dimension
namespace si
{
#pragma region constants
namespace constant
{
create_constant_point(system_epoch, prefix::zero_t,
                      fix(unit<dimension::system_clock_t, prefix::second_t>));
create_constant_point(steady_epoch, prefix::zero_t,
                      fix(unit<dimension::steady_clock_t, prefix::second_t>));
create_constant_point(high_resolution_epoch, prefix::zero_t,
                      fix(unit<dimension::high_resolution_clock_t, prefix::second_t>));
} // namespace constant
#pragma endregion
#pragma region symbols
namespace symbol
{
create_symbol_point(system_epoch, dimension::system_clock_t, prefix::second_t,
                    prefix::zero_t);
create_symbol_point(steady_epoch, dimension::steady_clock_t, prefix::second_t,
                    prefix::zero_t);
create_symbol_point(high_resolution_epoch, dimension::high_resolution_clock_t,
                    prefix::second_t, prefix::zero_t);
} // namespace symbol
#pragma endregion
#pragma region units
implement_unit_point(seconds_since_system_epoch, dimension::system_clock_t,
                     prefix::second_t);
implement_unit_point(seconds_since_steady_epoch, dimension::steady_clock_t,
                     prefix::second_t);
implement_unit_point(seconds_since_high_resolution_epoch,
                     dimension::high_resolution_clock_t, prefix::second_t);
implement_unit_point(minutes_since_system_epoch, dimension::system_clock_t,
                     prefix::minute_t);
implement_unit_point(minutes_since_steady_epoch, dimension::steady_clock_t,
                     prefix::minute_t);
implement_unit_point(minutes_since_high_resolution_epoch,
                     dimension::high_resolution_clock_t, prefix::minute_t);
implement_unit_point(hours_since_system_epoch, dimension::system_clock_t, prefix::hour_t);
implement_unit_point(hours_since_steady_epoch, dimension::steady_clock_t, prefix::hour_t);
implement_unit_point(hours_since_high_resolution_epoch,
                     dimension::high_resolution_clock_t, prefix::hour_t);
implement_unit_point(days_since_system_epoch, dimension::system_clock_t, prefix::day_t);
implement_unit_point(days_since_steady_epoch, dimension::steady_clock_t, prefix::day_t);
implement_unit_point(days_since_high_resolution_epoch, dimension::high_resolution_clock_t,
                     prefix::day_t);
implement_unit_point(weeks_since_system_epoch, dimension::system_clock_t, prefix::week_t);
implement_unit_point(weeks_since_steady_epoch, dimension::steady_clock_t, prefix::week_t);
implement_unit_point(weeks_since_high_resolution_epoch,
                     dimension::high_resolution_clock_t, prefix::week_t);
implement_unit_point(months_since_system_epoch, dimension::system_clock_t,
                     prefix::month_t);
implement_unit_point(months_since_steady_epoch, dimension::steady_clock_t,
                     prefix::month_t);
implement_unit_point(months_since_high_resolution_epoch,
                     dimension::high_resolution_clock_t, prefix::month_t);
implement_unit_point(years_since_system_epoch, dimension::system_clock_t, prefix::year_t);
implement_unit_point(years_since_steady_epoch, dimension::steady_clock_t, prefix::year_t);
implement_unit_point(years_since_high_resolution_epoch,
                     dimension::high_resolution_clock_t, prefix::year_t);
#pragma endregion
} // namespace si
#pragma region type helper
template <class Clock>
using get_clock_dimension = std::conditional_t<
    std::is_same<Clock, std::chrono::system_clock>::value,
    typename dimension::system_clock_t,
    std::conditional_t<std::is_same<Clock, std::chrono::steady_clock>::value,
                       typename dimension::steady_clock_t,
                       typename dimension::high_resolution_clock_t>>;
#pragma endregion
#pragma region chrono conversions
// std::chrono::duration to quantity
template <class Period, class ValueType>
struct convert<std::chrono::duration<ValueType, Period>,
               quantity<unit<dimension::time_t,
                             decltype(type::make_prefix<Period::num, Period::den>{})>,
                        ValueType>>
{
    constexpr auto operator()(const std::chrono::duration<ValueType, Period>& rhs)
        -> quantity<unit<dimension::time_t,
                         decltype(type::make_prefix<Period::num, Period::den>{})>,
                    ValueType>
    {
        return quantity<unit<dimension::time_t,
                             decltype(type::make_prefix<Period::num, Period::den>{})>,
                        ValueType>{rhs.count()};
    }
    constexpr auto operator()(std::chrono::duration<ValueType, Period>&& rhs) -> quantity<
        unit<dimension::time_t, decltype(type::make_prefix<Period::num, Period::den>{})>,
        ValueType>
    {
        return quantity<unit<dimension::time_t,
                             decltype(type::make_prefix<Period::num, Period::den>{})>,
                        ValueType>{rhs.count()};
    }
};
template <class Period, class ValueType>
struct convert<std::chrono::duration<ValueType, Period>,
               quantity<unit<dimension::system_clock_t,
                             decltype(type::make_prefix<Period::num, Period::den>{})>,
                        ValueType>>
{
    constexpr auto operator()(const std::chrono::duration<ValueType, Period>& rhs)
        -> quantity<unit<dimension::system_clock_t,
                         decltype(type::make_prefix<Period::num, Period::den>{})>,
                    ValueType>
    {
        return quantity<unit<dimension::system_clock_t,
                             decltype(type::make_prefix<Period::num, Period::den>{})>,
                        ValueType>{rhs.count()};
    }
    constexpr auto operator()(std::chrono::duration<ValueType, Period>&& rhs)
        -> quantity<unit<dimension::system_clock_t,
                         decltype(type::make_prefix<Period::num, Period::den>{})>,
                    ValueType>
    {
        return quantity<unit<dimension::system_clock_t,
                             decltype(type::make_prefix<Period::num, Period::den>{})>,
                        ValueType>{rhs.count()};
    }
};
template <class Period, class ValueType>
struct convert<std::chrono::duration<ValueType, Period>,
               quantity<unit<dimension::steady_clock_t,
                             decltype(type::make_prefix<Period::num, Period::den>{})>,
                        ValueType>>
{
    constexpr auto operator()(const std::chrono::duration<ValueType, Period>& rhs)
        -> quantity<unit<dimension::steady_clock_t,
                         decltype(type::make_prefix<Period::num, Period::den>{})>,
                    ValueType>
    {
        return quantity<unit<dimension::steady_clock_t,
                             decltype(type::make_prefix<Period::num, Period::den>{})>,
                        ValueType>{rhs.count()};
    }
    constexpr auto operator()(std::chrono::duration<ValueType, Period>&& rhs)
        -> quantity<unit<dimension::steady_clock_t,
                         decltype(type::make_prefix<Period::num, Period::den>{})>,
                    ValueType>
    {
        return quantity<unit<dimension::steady_clock_t,
                             decltype(type::make_prefix<Period::num, Period::den>{})>,
                        ValueType>{rhs.count()};
    }
};
template <class Period, class ValueType>
struct convert<std::chrono::duration<ValueType, Period>,
               quantity<unit<dimension::high_resolution_clock_t,
                             decltype(type::make_prefix<Period::num, Period::den>{})>,
                        ValueType>>
{
    constexpr auto operator()(const std::chrono::duration<ValueType, Period>& rhs)
        -> quantity<unit<dimension::high_resolution_clock_t,
                         decltype(type::make_prefix<Period::num, Period::den>{})>,
                    ValueType>
    {
        return quantity<unit<dimension::high_resolution_clock_t,
                             decltype(type::make_prefix<Period::num, Period::den>{})>,
                        ValueType>{rhs.count()};
    }
    constexpr auto operator()(std::chrono::duration<ValueType, Period>&& rhs)
        -> quantity<unit<dimension::high_resolution_clock_t,
                         decltype(type::make_prefix<Period::num, Period::den>{})>,
                    ValueType>
    {
        return quantity<unit<dimension::high_resolution_clock_t,
                             decltype(type::make_prefix<Period::num, Period::den>{})>,
                        ValueType>{rhs.count()};
    }
};
// quantity to std::chrono::duration
template <class Period, class ValueType>
struct convert<quantity<unit<dimension::time_t,
                             decltype(type::make_prefix<Period::num, Period::den>{})>,
                        ValueType>,
               std::chrono::duration<ValueType, Period>>
{
    constexpr auto operator()(
        const quantity<unit<dimension::time_t,
                            decltype(type::make_prefix<Period::num, Period::den>{})>,
                       ValueType>& rhs) -> std::chrono::duration<ValueType, Period>
    {
        return std::chrono::duration<ValueType, Period>{rhs._value};
    }
    constexpr auto
        operator()(quantity<unit<dimension::time_t,
                                 decltype(type::make_prefix<Period::num, Period::den>{})>,
                            ValueType>&& rhs) -> std::chrono::duration<ValueType, Period>
    {
        return std::chrono::duration<ValueType, Period>{std::move(rhs._value)};
    }
};
template <class Period, class ValueType>
struct convert<quantity<unit<dimension::system_clock_t,
                             decltype(type::make_prefix<Period::num, Period::den>{})>,
                        ValueType>,
               std::chrono::duration<ValueType, Period>>
{
    constexpr auto operator()(
        const quantity<unit<dimension::system_clock_t,
                            decltype(type::make_prefix<Period::num, Period::den>{})>,
                       ValueType>& rhs) -> std::chrono::duration<ValueType, Period>
    {
        return std::chrono::duration<ValueType, Period>{rhs._value};
    }
    constexpr auto
        operator()(quantity<unit<dimension::system_clock_t,
                                 decltype(type::make_prefix<Period::num, Period::den>{})>,
                            ValueType>&& rhs) -> std::chrono::duration<ValueType, Period>
    {
        return std::chrono::duration<ValueType, Period>{std::move(rhs._value)};
    }
};
template <class Period, class ValueType>
struct convert<quantity<unit<dimension::steady_clock_t,
                             decltype(type::make_prefix<Period::num, Period::den>{})>,
                        ValueType>,
               std::chrono::duration<ValueType, Period>>
{
    constexpr auto operator()(
        const quantity<unit<dimension::steady_clock_t,
                            decltype(type::make_prefix<Period::num, Period::den>{})>,
                       ValueType>& rhs) -> std::chrono::duration<ValueType, Period>
    {
        return std::chrono::duration<ValueType, Period>{rhs._value};
    }
    constexpr auto
        operator()(quantity<unit<dimension::steady_clock_t,
                                 decltype(type::make_prefix<Period::num, Period::den>{})>,
                            ValueType>&& rhs) -> std::chrono::duration<ValueType, Period>
    {
        return std::chrono::duration<ValueType, Period>{std::move(rhs._value)};
    }
};
template <class Period, class ValueType>
struct convert<quantity<unit<dimension::high_resolution_clock_t,
                             decltype(type::make_prefix<Period::num, Period::den>{})>,
                        ValueType>,
               std::chrono::duration<ValueType, Period>>
{
    constexpr auto operator()(
        const quantity<unit<dimension::high_resolution_clock_t,
                            decltype(type::make_prefix<Period::num, Period::den>{})>,
                       ValueType>& rhs) -> std::chrono::duration<ValueType, Period>
    {
        return std::chrono::duration<ValueType, Period>{rhs._value};
    }
    constexpr auto
        operator()(quantity<unit<dimension::high_resolution_clock_t,
                                 decltype(type::make_prefix<Period::num, Period::den>{})>,
                            ValueType>&& rhs) -> std::chrono::duration<ValueType, Period>
    {
        return std::chrono::duration<ValueType, Period>{std::move(rhs._value)};
    }
};
// std::chrono::time_point to quantity_point
template <class Clock, class Period, class ValueType>
struct convert<
    std::chrono::time_point<Clock, std::chrono::duration<ValueType, Period>>,
    quantity_point<unit<get_clock_dimension<Clock>,
                        decltype(type::make_prefix<Period::num, Period::den>{})>,
                   ValueType>>
{
    constexpr auto operator()(
        const std::chrono::time_point<Clock, std::chrono::duration<ValueType, Period>>&
            rhs)
        -> quantity_point<unit<get_clock_dimension<Clock>,
                               decltype(type::make_prefix<Period::num, Period::den>{})>,
                          ValueType>
    {
        return quantity_point<
            unit<get_clock_dimension<Clock>,
                 decltype(type::make_prefix<Period::num, Period::den>{})>,
            ValueType>{rhs.time_since_epoch().count()};
    }
    constexpr auto operator()(
        std::chrono::time_point<Clock, std::chrono::duration<ValueType, Period>>&& rhs)
        -> quantity_point<unit<get_clock_dimension<Clock>,
                               decltype(type::make_prefix<Period::num, Period::den>{})>,
                          ValueType>
    {
        return quantity_point<
            unit<get_clock_dimension<Clock>,
                 decltype(type::make_prefix<Period::num, Period::den>{})>,
            ValueType>{rhs.time_since_epoch().count()};
    }
};
// quantity_point to std::chrono::time_point
template <class Clock, class Period, class ValueType>
struct convert<
    quantity_point<unit<get_clock_dimension<Clock>,
                        decltype(type::make_prefix<Period::num, Period::den>{})>,
                   ValueType>,
    std::chrono::time_point<Clock, std::chrono::duration<ValueType, Period>>>
{
    constexpr auto
        operator()(const quantity_point<
                   unit<get_clock_dimension<Clock>,
                        decltype(type::make_prefix<Period::num, Period::den>{})>,
                   ValueType>& rhs)
            -> std::chrono::time_point<Clock, std::chrono::duration<ValueType, Period>>
    {
        return std::chrono::time_point<Clock, std::chrono::duration<ValueType, Period>>{
            std::chrono::duration<ValueType, Period>{rhs.value()}};
    }
    constexpr auto operator()(
        quantity_point<unit<get_clock_dimension<Clock>,
                            decltype(type::make_prefix<Period::num, Period::den>{})>,
                       ValueType>&& rhs)
        -> std::chrono::time_point<Clock, std::chrono::duration<ValueType, Period>>
    {
        return std::chrono::time_point<Clock, std::chrono::duration<ValueType, Period>>{
            std::chrono::duration<ValueType, Period>{rhs.value()}};
    }
};
#pragma endregion
#pragma region benri conversions
// All the time dimensions are considered to be equivalent, when used as a quantity.
template <class Prefix, class ValueType>
struct convert<quantity<unit<dimension::system_clock_t, Prefix>, ValueType>,
               quantity<unit<dimension::time_t, Prefix>, ValueType>>
{
    constexpr auto operator()(
        const quantity<unit<dimension::system_clock_t, Prefix>, ValueType>& rhs)
        -> quantity<unit<dimension::time_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::time_t, Prefix>, ValueType>{rhs._value};
    }
    constexpr auto
        operator()(quantity<unit<dimension::system_clock_t, Prefix>, ValueType>&& rhs)
            -> quantity<unit<dimension::time_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::time_t, Prefix>, ValueType>{
            std::move(rhs._value)};
    }
};
template <class Prefix, class ValueType>
struct convert<quantity<unit<dimension::time_t, Prefix>, ValueType>,
               quantity<unit<dimension::system_clock_t, Prefix>, ValueType>>
{
    constexpr auto
        operator()(const quantity<unit<dimension::time_t, Prefix>, ValueType>& rhs)
            -> quantity<unit<dimension::system_clock_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::system_clock_t, Prefix>, ValueType>{rhs._value};
    }
    constexpr auto operator()(quantity<unit<dimension::time_t, Prefix>, ValueType>&& rhs)
        -> quantity<unit<dimension::system_clock_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::system_clock_t, Prefix>, ValueType>{
            std::move(rhs._value)};
    }
};
template <class Prefix, class ValueType>
struct convert<quantity<unit<dimension::steady_clock_t, Prefix>, ValueType>,
               quantity<unit<dimension::time_t, Prefix>, ValueType>>
{
    constexpr auto operator()(
        const quantity<unit<dimension::steady_clock_t, Prefix>, ValueType>& rhs)
        -> quantity<unit<dimension::time_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::time_t, Prefix>, ValueType>{rhs._value};
    }
    constexpr auto
        operator()(quantity<unit<dimension::steady_clock_t, Prefix>, ValueType>&& rhs)
            -> quantity<unit<dimension::time_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::time_t, Prefix>, ValueType>{
            std::move(rhs._value)};
    }
};
template <class Prefix, class ValueType>
struct convert<quantity<unit<dimension::time_t, Prefix>, ValueType>,
               quantity<unit<dimension::steady_clock_t, Prefix>, ValueType>>
{
    constexpr auto
        operator()(const quantity<unit<dimension::time_t, Prefix>, ValueType>& rhs)
            -> quantity<unit<dimension::steady_clock_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::steady_clock_t, Prefix>, ValueType>{rhs._value};
    }
    constexpr auto operator()(quantity<unit<dimension::time_t, Prefix>, ValueType>&& rhs)
        -> quantity<unit<dimension::steady_clock_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::steady_clock_t, Prefix>, ValueType>{
            std::move(rhs._value)};
    }
};
template <class Prefix, class ValueType>
struct convert<quantity<unit<dimension::high_resolution_clock_t, Prefix>, ValueType>,
               quantity<unit<dimension::time_t, Prefix>, ValueType>>
{
    constexpr auto operator()(
        const quantity<unit<dimension::high_resolution_clock_t, Prefix>, ValueType>& rhs)
        -> quantity<unit<dimension::time_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::time_t, Prefix>, ValueType>{rhs._value};
    }
    constexpr auto operator()(
        quantity<unit<dimension::high_resolution_clock_t, Prefix>, ValueType>&& rhs)
        -> quantity<unit<dimension::time_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::time_t, Prefix>, ValueType>{
            std::move(rhs._value)};
    }
};
template <class Prefix, class ValueType>
struct convert<quantity<unit<dimension::time_t, Prefix>, ValueType>,
               quantity<unit<dimension::high_resolution_clock_t, Prefix>, ValueType>>
{
    constexpr auto
        operator()(const quantity<unit<dimension::time_t, Prefix>, ValueType>& rhs)
            -> quantity<unit<dimension::high_resolution_clock_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::high_resolution_clock_t, Prefix>, ValueType>{
            rhs._value};
    }
    constexpr auto operator()(quantity<unit<dimension::time_t, Prefix>, ValueType>&& rhs)
        -> quantity<unit<dimension::high_resolution_clock_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::high_resolution_clock_t, Prefix>, ValueType>{
            std::move(rhs._value)};
    }
};
template <class Prefix, class ValueType>
struct convert<quantity<unit<dimension::system_clock_t, Prefix>, ValueType>,
               quantity<unit<dimension::steady_clock_t, Prefix>, ValueType>>
{
    constexpr auto operator()(
        const quantity<unit<dimension::system_clock_t, Prefix>, ValueType>& rhs)
        -> quantity<unit<dimension::steady_clock_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::steady_clock_t, Prefix>, ValueType>{rhs._value};
    }
    constexpr auto
        operator()(quantity<unit<dimension::system_clock_t, Prefix>, ValueType>&& rhs)
            -> quantity<unit<dimension::steady_clock_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::steady_clock_t, Prefix>, ValueType>{
            std::move(rhs._value)};
    }
};
template <class Prefix, class ValueType>
struct convert<quantity<unit<dimension::steady_clock_t, Prefix>, ValueType>,
               quantity<unit<dimension::system_clock_t, Prefix>, ValueType>>
{
    constexpr auto operator()(
        const quantity<unit<dimension::steady_clock_t, Prefix>, ValueType>& rhs)
        -> quantity<unit<dimension::system_clock_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::system_clock_t, Prefix>, ValueType>{rhs._value};
    }
    constexpr auto
        operator()(quantity<unit<dimension::steady_clock_t, Prefix>, ValueType>&& rhs)
            -> quantity<unit<dimension::system_clock_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::system_clock_t, Prefix>, ValueType>{
            std::move(rhs._value)};
    }
};
template <class Prefix, class ValueType>
struct convert<quantity<unit<dimension::system_clock_t, Prefix>, ValueType>,
               quantity<unit<dimension::high_resolution_clock_t, Prefix>, ValueType>>
{
    constexpr auto operator()(
        const quantity<unit<dimension::system_clock_t, Prefix>, ValueType>& rhs)
        -> quantity<unit<dimension::high_resolution_clock_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::high_resolution_clock_t, Prefix>, ValueType>{
            rhs._value};
    }
    constexpr auto
        operator()(quantity<unit<dimension::system_clock_t, Prefix>, ValueType>&& rhs)
            -> quantity<unit<dimension::high_resolution_clock_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::high_resolution_clock_t, Prefix>, ValueType>{
            std::move(rhs._value)};
    }
};
template <class Prefix, class ValueType>
struct convert<quantity<unit<dimension::high_resolution_clock_t, Prefix>, ValueType>,
               quantity<unit<dimension::system_clock_t, Prefix>, ValueType>>
{
    constexpr auto operator()(
        const quantity<unit<dimension::high_resolution_clock_t, Prefix>, ValueType>& rhs)
        -> quantity<unit<dimension::system_clock_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::system_clock_t, Prefix>, ValueType>{rhs._value};
    }
    constexpr auto operator()(
        quantity<unit<dimension::high_resolution_clock_t, Prefix>, ValueType>&& rhs)
        -> quantity<unit<dimension::system_clock_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::system_clock_t, Prefix>, ValueType>{
            std::move(rhs._value)};
    }
};
template <class Prefix, class ValueType>
struct convert<quantity<unit<dimension::steady_clock_t, Prefix>, ValueType>,
               quantity<unit<dimension::high_resolution_clock_t, Prefix>, ValueType>>
{
    constexpr auto operator()(
        const quantity<unit<dimension::steady_clock_t, Prefix>, ValueType>& rhs)
        -> quantity<unit<dimension::high_resolution_clock_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::high_resolution_clock_t, Prefix>, ValueType>{
            rhs._value};
    }
    constexpr auto
        operator()(quantity<unit<dimension::steady_clock_t, Prefix>, ValueType>&& rhs)
            -> quantity<unit<dimension::high_resolution_clock_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::high_resolution_clock_t, Prefix>, ValueType>{
            std::move(rhs._value)};
    }
};
template <class Prefix, class ValueType>
struct convert<quantity<unit<dimension::high_resolution_clock_t, Prefix>, ValueType>,
               quantity<unit<dimension::steady_clock_t, Prefix>, ValueType>>
{
    constexpr auto operator()(
        const quantity<unit<dimension::high_resolution_clock_t, Prefix>, ValueType>& rhs)
        -> quantity<unit<dimension::steady_clock_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::steady_clock_t, Prefix>, ValueType>{rhs._value};
    }
    constexpr auto operator()(
        quantity<unit<dimension::high_resolution_clock_t, Prefix>, ValueType>&& rhs)
        -> quantity<unit<dimension::steady_clock_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::steady_clock_t, Prefix>, ValueType>{
            std::move(rhs._value)};
    }
};
#pragma endregion
#pragma region now function
template <class Clock,
          class Unit      = unit<get_clock_dimension<Clock>,
                            decltype(type::make_prefix<Clock::duration::period::num,
                                                       Clock::duration::period::den>{})>,
          class ValueType = Precision>
constexpr inline auto now() noexcept -> quantity_point<Unit, ValueType>
{
    const auto chrono_now = std::chrono::time_point_cast<
        std::chrono::duration<ValueType, typename Clock::duration::period>>(Clock::now());
    const auto benri_now =
        quantity_point<unit<get_clock_dimension<Clock>,
                            decltype(type::make_prefix<Clock::duration::period::num,
                                                       Clock::duration::period::den>{})>,
                       ValueType>{chrono_now};
    return simple_cast<Unit>(benri_now);
}
#pragma endregion
#pragma region math helpers
// When std::chrono::time_point is added to/subtracted from quantity<second_t>, the
// compiler can now understand that we actually want to convert both to a quantity_point
// with the unit of std::chrono::time_point.
template <class Clock, class Period, class ValueType>
[[nodiscard]] constexpr inline auto operator+(
    const quantity<
        unit<dimension::time_t, decltype(type::make_prefix<Period::num, Period::den>{})>,
        ValueType>& lhs,
    const std::chrono::time_point<Clock, std::chrono::duration<ValueType, Period>>&
        rhs) noexcept
    -> quantity_point<unit<get_clock_dimension<Clock>,
                           decltype(type::make_prefix<Period::num, Period::den>{})>,
                      ValueType>
{
    return lhs
           + quantity_point<unit<get_clock_dimension<Clock>,
                                 decltype(type::make_prefix<Period::num, Period::den>{})>,
                            ValueType>{rhs};
}
template <class Clock, class Period, class ValueType>
[[nodiscard]] constexpr inline auto operator+(
    const std::chrono::time_point<Clock, std::chrono::duration<ValueType, Period>>& lhs,
    const quantity<
        unit<dimension::time_t, decltype(type::make_prefix<Period::num, Period::den>{})>,
        ValueType>& rhs) noexcept
    -> quantity_point<unit<get_clock_dimension<Clock>,
                           decltype(type::make_prefix<Period::num, Period::den>{})>,
                      ValueType>
{
    return quantity_point<unit<get_clock_dimension<Clock>,
                               decltype(type::make_prefix<Period::num, Period::den>{})>,
                          ValueType>{lhs}
           + rhs;
}

template <class Clock, class Period, class ValueType>
[[nodiscard]] constexpr inline auto operator-(
    const quantity<
        unit<dimension::time_t, decltype(type::make_prefix<Period::num, Period::den>{})>,
        ValueType>& lhs,
    const std::chrono::time_point<Clock, std::chrono::duration<ValueType, Period>>&
        rhs) noexcept
    -> quantity_point<unit<get_clock_dimension<Clock>,
                           decltype(type::make_prefix<Period::num, Period::den>{})>,
                      ValueType>
{
    return lhs
           - quantity_point<unit<get_clock_dimension<Clock>,
                                 decltype(type::make_prefix<Period::num, Period::den>{})>,
                            ValueType>{rhs};
}
template <class Clock, class Period, class ValueType>
[[nodiscard]] constexpr inline auto operator-(
    const std::chrono::time_point<Clock, std::chrono::duration<ValueType, Period>>& lhs,
    const quantity<
        unit<dimension::time_t, decltype(type::make_prefix<Period::num, Period::den>{})>,
        ValueType>& rhs) noexcept
    -> quantity_point<unit<get_clock_dimension<Clock>,
                           decltype(type::make_prefix<Period::num, Period::den>{})>,
                      ValueType>
{
    return quantity_point<unit<get_clock_dimension<Clock>,
                               decltype(type::make_prefix<Period::num, Period::den>{})>,
                          ValueType>{lhs}
           - rhs;
}
#pragma endregion
} // namespace benri
