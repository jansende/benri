#pragma once
#include <benri/impl/helpers.h>

#define fix(...) __VA_ARGS__

#define implement_unit(NAME, DIMENSION, PREFIX)                                        \
    using NAME##_t = benri::make_unit<DIMENSION, PREFIX>;                              \
    [[nodiscard]] constexpr inline auto operator"" _##NAME(long double value) noexcept \
    {                                                                                  \
        return benri::make_quantity<NAME##_t, benri::Precision>(value);                \
    }                                                                                  \
    [[nodiscard]] constexpr inline auto operator"" _##NAME(                            \
        unsigned long long int value) noexcept                                         \
    {                                                                                  \
        return benri::make_quantity<NAME##_t, benri::Precision>(value);                \
    }                                                                                  \
    constexpr auto NAME = benri::make_quantity<NAME##_t, benri::Precision>(1);
#define implement_unit_point(NAME, DIMENSION, PREFIX)                                  \
    using NAME##_t = benri::make_unit<DIMENSION, PREFIX>;                              \
    [[nodiscard]] constexpr inline auto operator"" _##NAME(long double value) noexcept \
    {                                                                                  \
        return benri::make_quantity_point<NAME##_t, benri::Precision>(value);          \
    }                                                                                  \
    [[nodiscard]] constexpr inline auto operator"" _##NAME(                            \
        unsigned long long int value) noexcept                                         \
    {                                                                                  \
        return benri::make_quantity_point<NAME##_t, benri::Precision>(value);          \
    }                                                                                  \
    constexpr auto NAME = benri::make_quantity_point<NAME##_t, benri::Precision>(1);

#define link_unit(NAME, ALIAS)                                                         \
    using NAME##_t = ALIAS##_t;                                                        \
    [[nodiscard]] constexpr inline auto operator"" _##NAME(long double value) noexcept \
    {                                                                                  \
        return benri::make_quantity<NAME##_t, benri::Precision>(value);                \
    }                                                                                  \
    [[nodiscard]] constexpr inline auto operator"" _##NAME(                            \
        unsigned long long int value) noexcept                                         \
    {                                                                                  \
        return benri::make_quantity<NAME##_t, benri::Precision>(value);                \
    }                                                                                  \
    constexpr auto NAME = ALIAS;
#define link_unit_point(NAME, ALIAS)                                                   \
    using NAME##_t = ALIAS##_t;                                                        \
    [[nodiscard]] constexpr inline auto operator"" _##NAME(long double value) noexcept \
    {                                                                                  \
        return benri::make_quantity_point<NAME##_t, benri::Precision>(value);          \
    }                                                                                  \
    [[nodiscard]] constexpr inline auto operator"" _##NAME(                            \
        unsigned long long int value) noexcept                                         \
    {                                                                                  \
        return benri::make_quantity_point<NAME##_t, benri::Precision>(value);          \
    }

#define create_symbol(NAME, DIMENSION, PREFIX)                            \
    constexpr auto NAME =                                                 \
        benri::make_symbol<DIMENSION, PREFIX, benri::type::sorted_list<>, \
                           benri::Precision>;
#define create_constant(NAME, VALUE, UNIT) \
    constexpr auto NAME = benri::make_constant<UNIT, VALUE, benri::Precision>;
#define create_symbol_point(NAME, DIMENSION, PREFIX, VALUE) \
    constexpr auto NAME =                                   \
        benri::make_symbol_point<DIMENSION, PREFIX, VALUE, benri::Precision>;
#define create_constant_point(NAME, VALUE, UNIT) \
    constexpr auto NAME = benri::make_constant_point<UNIT, VALUE, benri::Precision>;

#define create_and_register_dimension(NAME, ...) \
    using NAME##_t = benri::make_dimension<__VA_ARGS__>;