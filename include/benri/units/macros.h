#pragma once

#define fix(...) __VA_ARGS__
#define implement_unit(SYSTEM, NAMESPACE, NAME, DIMENSIONS, PREFIX)                  \
    using NAME##_t = unit<SYSTEM, DIMENSIONS, PREFIX>;                               \
    constexpr auto operator"" _##NAME(long double value)                             \
    {                                                                                \
        return quantity<NAME##_t, Precision>{static_cast<Precision>(value)};         \
    }                                                                                \
    constexpr auto operator"" _##NAME(unsigned long long int value)                  \
    {                                                                                \
        return quantity<NAME##_t, Precision>{static_cast<Precision>(value)};         \
    }                                                                                \
    constexpr auto NAME = quantity<NAME##_t, Precision>{static_cast<Precision>(1)};  \
    }                                                                                \
    template <>                                                                      \
    struct resolve_name<quantity<typename NAMESPACE::NAME##_t, Precision>>           \
    {                                                                                \
        static constexpr auto name = #NAME;                                          \
    };                                                                               \
    template <>                                                                      \
    struct resolve_name<typename NAMESPACE::NAME##_t>                                \
    {                                                                                \
        static constexpr auto name = #NAME;                                          \
    };                                                                               \
    namespace NAMESPACE                                                              \
    {
#define implement_subunit(SYSTEM, NAMESPACE, SUBSPACE, NAME, DIMENSIONS, PREFIX)     \
    using NAME##_t = unit<SYSTEM, DIMENSIONS, PREFIX>;                               \
    constexpr auto operator"" _##NAME(long double value)                             \
    {                                                                                \
        return quantity<NAME##_t, Precision>{static_cast<Precision>(value)};         \
    }                                                                                \
    constexpr auto operator"" _##NAME(unsigned long long int value)                  \
    {                                                                                \
        return quantity<NAME##_t, Precision>{static_cast<Precision>(value)};         \
    }                                                                                \
    constexpr auto NAME = quantity<NAME##_t, Precision>{static_cast<Precision>(1)};  \
    }                                                                                \
    }                                                                                \
    template <>                                                                      \
    struct resolve_name<quantity<typename NAMESPACE::SUBSPACE::NAME##_t, Precision>> \
    {                                                                                \
        static constexpr auto name = #NAME;                                          \
    };                                                                               \
    template <>                                                                      \
    struct resolve_name<typename NAMESPACE::SUBSPACE::NAME##_t>                      \
    {                                                                                \
        static constexpr auto name = #NAME;                                          \
    };                                                                               \
    namespace NAMESPACE                                                              \
    {                                                                                \
    namespace SUBSPACE                                                               \
    {

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

#define create_symbol(SYSTEM, NAME, DIMENSIONS, PREFIX) \
    constexpr auto NAME = quantity<unit<SYSTEM, DIMENSIONS, PREFIX>>{static_cast<Precision>(1)};
#define create_constant(NAME, VALUE, UNIT) \
    constexpr auto NAME = quantity<UNIT, Precision>{impl::expand_list_v<Precision, VALUE>};

#define create_and_register_dimension(NAME, ...) \
    using NAME##_t = list<__VA_ARGS__>;          \
    }                                            \
    template <>                                  \
    struct resolve_name<typename dim::NAME##_t>  \
    {                                            \
        static constexpr auto name = #NAME;      \
    };                                           \
    namespace dim                                \
    {