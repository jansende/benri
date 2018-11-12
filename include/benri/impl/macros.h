#pragma once

#define fix(...) __VA_ARGS__

#define implement_unit(NAMESPACE, NAME, DIMENSIONS, PREFIX)                  \
    using NAME##_t = unit<sort_list<DIMENSIONS>, sort_list<PREFIX>>;         \
    constexpr auto operator"" _##NAME(long double value)                     \
    {                                                                        \
        return quantity<NAME##_t, Precision>{static_cast<Precision>(value)}; \
    }                                                                        \
    constexpr auto operator"" _##NAME(unsigned long long int value)          \
    {                                                                        \
        return quantity<NAME##_t, Precision>{static_cast<Precision>(value)}; \
    }                                                                        \
    constexpr auto NAME = quantity<NAME##_t, Precision>{static_cast<Precision>(1)};
#define implement_subunit(NAMESPACE, SUBSPACE, NAME, DIMENSIONS, PREFIX)     \
    using NAME##_t = unit<sort_list<DIMENSIONS>, sort_list<PREFIX>>;         \
    constexpr auto operator"" _##NAME(long double value)                     \
    {                                                                        \
        return quantity<NAME##_t, Precision>{static_cast<Precision>(value)}; \
    }                                                                        \
    constexpr auto operator"" _##NAME(unsigned long long int value)          \
    {                                                                        \
        return quantity<NAME##_t, Precision>{static_cast<Precision>(value)}; \
    }                                                                        \
    constexpr auto NAME = quantity<NAME##_t, Precision>{static_cast<Precision>(1)};

#define link_unit(NAME, ALIAS)                                      \
    using NAME##_t = ALIAS##_t;                                     \
    constexpr auto operator"" _##NAME(long double value)            \
    {                                                               \
        return quantity<NAME##_t>{Precision(value)};                \
    }                                                               \
    constexpr auto operator"" _##NAME(unsigned long long int value) \
    {                                                               \
        return quantity<NAME##_t>{Precision(value)};                \
    }                                                               \
    constexpr auto NAME = ALIAS;
#define link_unit_point(NAME, ALIAS)                                \
    using NAME##_t = ALIAS##_t;                                     \
    constexpr auto operator"" _##NAME(long double value)            \
    {                                                               \
        return quantity_point<NAME##_t>{Precision(value)};          \
    }                                                               \
    constexpr auto operator"" _##NAME(unsigned long long int value) \
    {                                                               \
        return quantity_point<NAME##_t>{Precision(value)};          \
    }

#define create_symbol(NAME, DIMENSIONS, PREFIX) \
    constexpr auto NAME = quantity<unit<sort_list<DIMENSIONS>, sort_list<PREFIX>>>{static_cast<Precision>(1)};
#define create_constant(NAME, VALUE, UNIT) \
    constexpr auto NAME = quantity<UNIT, Precision>{impl::multiply_elements<Precision, VALUE>};

#define create_and_register_dimension(NAME, ...)   \
    using NAME##_t = sort_list<list<__VA_ARGS__>>;