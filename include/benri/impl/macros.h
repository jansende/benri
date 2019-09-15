#pragma once

#define fix(...) __VA_ARGS__

#define implement_unit(NAME, DIMENSIONS, PREFIX)                                                  \
    using NAME##_t = unit<sort<DIMENSIONS>, sort<PREFIX>>;                              \
    [[nodiscard]] constexpr inline auto operator"" _##NAME(long double value) noexcept            \
    {                                                                                             \
        return quantity<NAME##_t, Precision>{static_cast<Precision>(value)};                      \
    }                                                                                             \
    [[nodiscard]] constexpr inline auto operator"" _##NAME(unsigned long long int value) noexcept \
    {                                                                                             \
        return quantity<NAME##_t, Precision>{static_cast<Precision>(value)};                      \
    }                                                                                             \
    constexpr auto NAME = quantity<NAME##_t, Precision>{static_cast<Precision>(1)};

#define link_unit(NAME, ALIAS)                                                                    \
    using NAME##_t = ALIAS##_t;                                                                   \
    [[nodiscard]] constexpr inline auto operator"" _##NAME(long double value) noexcept            \
    {                                                                                             \
        return quantity<NAME##_t>{static_cast<Precision>(value)};                                 \
    }                                                                                             \
    [[nodiscard]] constexpr inline auto operator"" _##NAME(unsigned long long int value) noexcept \
    {                                                                                             \
        return quantity<NAME##_t>{static_cast<Precision>(value)};                                 \
    }                                                                                             \
    constexpr auto NAME = ALIAS;
#define link_unit_point(NAME, ALIAS)                                                              \
    using NAME##_t = ALIAS##_t;                                                                   \
    [[nodiscard]] constexpr inline auto operator"" _##NAME(long double value) noexcept            \
    {                                                                                             \
        return quantity_point<NAME##_t>{static_cast<Precision>(value)};                           \
    }                                                                                             \
    [[nodiscard]] constexpr inline auto operator"" _##NAME(unsigned long long int value) noexcept \
    {                                                                                             \
        return quantity_point<NAME##_t>{static_cast<Precision>(value)};                           \
    }

#define create_symbol(NAME, DIMENSIONS, PREFIX) \
    constexpr auto NAME = quantity<unit<sort<DIMENSIONS>, sort<PREFIX>>>{static_cast<Precision>(1)};
#define create_constant(NAME, VALUE, UNIT) \
    constexpr auto NAME = quantity<UNIT, Precision>{impl::multiply_elements<Precision, VALUE>};

#define create_and_register_dimension(NAME, ...) \
    using NAME##_t = sort<list<__VA_ARGS__>>;