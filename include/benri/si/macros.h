#pragma once
#include <benri/impl/helpers.h>

#define fix(...) __VA_ARGS__

#define implement_unit(NAME, DIMENSION, PREFIX)                                        \
    using NAME##_t =                                                                   \
        benri::unit<benri::type::sort<DIMENSION>, benri::type::sort<PREFIX>>;          \
    [[nodiscard]] constexpr inline auto operator"" _##NAME(long double value) noexcept \
    {                                                                                  \
        return benri::quantity<NAME##_t, benri::Precision>{                            \
            static_cast<benri::Precision>(value)};                                     \
    }                                                                                  \
    [[nodiscard]] constexpr inline auto operator"" _##NAME(                            \
        unsigned long long int value) noexcept                                         \
    {                                                                                  \
        return benri::quantity<NAME##_t, benri::Precision>{                            \
            static_cast<benri::Precision>(value)};                                     \
    }                                                                                  \
    constexpr auto NAME =                                                              \
        benri::quantity<NAME##_t, benri::Precision>{static_cast<benri::Precision>(1)};
#define implement_unit_point(NAME, DIMENSION, PREFIX)                                  \
    using NAME##_t =                                                                   \
        benri::unit<benri::type::sort<DIMENSION>, benri::type::sort<PREFIX>>;          \
    [[nodiscard]] constexpr inline auto operator"" _##NAME(long double value) noexcept \
    {                                                                                  \
        return benri::quantity_point<NAME##_t, benri::Precision>{                      \
            static_cast<benri::Precision>(value)};                                     \
    }                                                                                  \
    [[nodiscard]] constexpr inline auto operator"" _##NAME(                            \
        unsigned long long int value) noexcept                                         \
    {                                                                                  \
        return benri::quantity_point<NAME##_t, benri::Precision>{                      \
            static_cast<benri::Precision>(value)};                                     \
    }                                                                                  \
    constexpr auto NAME = benri::quantity_point<NAME##_t, benri::Precision>{           \
        static_cast<benri::Precision>(1)};

#define link_unit(NAME, ALIAS)                                                         \
    using NAME##_t = ALIAS##_t;                                                        \
    [[nodiscard]] constexpr inline auto operator"" _##NAME(long double value) noexcept \
    {                                                                                  \
        return benri::quantity<NAME##_t>{static_cast<benri::Precision>(value)};        \
    }                                                                                  \
    [[nodiscard]] constexpr inline auto operator"" _##NAME(                            \
        unsigned long long int value) noexcept                                         \
    {                                                                                  \
        return benri::quantity<NAME##_t>{static_cast<benri::Precision>(value)};        \
    }                                                                                  \
    constexpr auto NAME = ALIAS;
#define link_unit_point(NAME, ALIAS)                                                   \
    using NAME##_t = ALIAS##_t;                                                        \
    [[nodiscard]] constexpr inline auto operator"" _##NAME(long double value) noexcept \
    {                                                                                  \
        return benri::quantity_point<NAME##_t>{static_cast<benri::Precision>(value)};  \
    }                                                                                  \
    [[nodiscard]] constexpr inline auto operator"" _##NAME(                            \
        unsigned long long int value) noexcept                                         \
    {                                                                                  \
        return benri::quantity_point<NAME##_t>{static_cast<benri::Precision>(value)};  \
    }

#define create_symbol(NAME, DIMENSION, PREFIX)                                 \
    constexpr auto NAME = benri::quantity<                                     \
        benri::unit<benri::type::sort<DIMENSION>, benri::type::sort<PREFIX>>>{ \
        static_cast<benri::Precision>(1)};
#define create_constant(NAME, VALUE, UNIT)                         \
    constexpr auto NAME = benri::quantity<UNIT, benri::Precision>{ \
        benri::expand_prefix_list<benri::Precision, VALUE>};
#define create_symbol_point(NAME, DIMENSION, PREFIX, VALUE)                    \
    constexpr auto NAME = benri::quantity_point<                               \
        benri::unit<benri::type::sort<DIMENSION>, benri::type::sort<PREFIX>>>{ \
        benri::expand_prefix_list<benri::Precision, VALUE>};
#define create_constant_point(NAME, VALUE, UNIT)                         \
    constexpr auto NAME = benri::quantity_point<UNIT, benri::Precision>{ \
        benri::expand_prefix_list<benri::Precision, VALUE>};

#define create_and_register_dimension(NAME, ...) \
    using NAME##_t = benri::make_dimension<__VA_ARGS__>;