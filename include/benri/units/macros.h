#pragma once

#define fix(...) __VA_ARGS__
#define implement_unit(SYSTEM, NAMESPACE, NAME, LITERAL, DIMENSIONS, PREFIX)                        \
    using NAME = unit<SYSTEM, DIMENSIONS, PREFIX>;                                                  \
    constexpr auto operator"" LITERAL(long double value)                                            \
    {                                                                                               \
        return quantity<unit<SYSTEM, DIMENSIONS, PREFIX>,Precision>{static_cast<Precision>(value)}; \
    }                                                                                               \
    constexpr auto operator"" LITERAL(unsigned long long int value)                                 \
    {                                                                                               \
        return quantity<unit<SYSTEM, DIMENSIONS, PREFIX>,Precision>{static_cast<Precision>(value)}; \
    }                                                                                               \
    }                                                                                               \
    template <>                                                                                     \
    struct resolve_name<quantity<unit<typename NAMESPACE::SYSTEM, DIMENSIONS, PREFIX>, Precision>>  \
    {                                                                                               \
        static constexpr auto name = "NAME";                                                        \
    };                                                                                              \
    template <>                                                                                     \
    struct resolve_name<unit<typename NAMESPACE::SYSTEM, DIMENSIONS, PREFIX>>                       \
    {                                                                                               \
        static constexpr auto name = "NAME";                                                        \
    };                                                                                              \
    namespace NAMESPACE                                                                             \
    {
#define implement_subunit(SYSTEM, NAMESPACE, SUBSPACE, NAME, LITERAL, DIMENSIONS, PREFIX)           \
    using NAME = unit<SYSTEM, DIMENSIONS, PREFIX>;                                                  \
    constexpr auto operator"" LITERAL(long double value)                                            \
    {                                                                                               \
        return quantity<unit<SYSTEM, DIMENSIONS, PREFIX>,Precision>{static_cast<Precision>(value)}; \
    }                                                                                               \
    constexpr auto operator"" LITERAL(unsigned long long int value)                                 \
    {                                                                                               \
        return quantity<unit<SYSTEM, DIMENSIONS, PREFIX>,Precision>{static_cast<Precision>(value)}; \
    }                                                                                               \
    }                                                                                               \
    }                                                                                               \
    template <>                                                                                     \
    struct resolve_name<quantity<unit<typename NAMESPACE::SYSTEM, DIMENSIONS, PREFIX>,Precision>>   \
    {                                                                                               \
        static constexpr auto name = #NAME;                                                         \
    };                                                                                              \
    template <>                                                                                     \
    struct resolve_name<unit<typename NAMESPACE::SYSTEM, DIMENSIONS, PREFIX>>                       \
    {                                                                                               \
        static constexpr auto name = #NAME;                                                         \
    };                                                                                              \
    namespace NAMESPACE                                                                             \
    {                                                                                               \
    namespace SUBSPACE                                                                              \
    {

#define link_unit(NAME, LITERAL, ALIAS)                             \
    using NAME = ALIAS;                                             \
    constexpr auto operator"" LITERAL(long double value)            \
    {                                                               \
        return quantity<NAME>{Precision(value)};                    \
    }                                                               \
    constexpr auto operator"" LITERAL(unsigned long long int value) \
    {                                                               \
        return quantity<NAME>{Precision(value)};                    \
    }
#define link_unit_point(NAME, LITERAL, ALIAS)                       \
    using NAME = ALIAS;                                             \
    constexpr auto operator"" LITERAL(long double value)            \
    {                                                               \
        return quantity_point<NAME>{Precision(value)};              \
    }                                                               \
    constexpr auto operator"" LITERAL(unsigned long long int value) \
    {                                                               \
        return quantity_point<NAME>{Precision(value)};              \
    }

#define create_symbol(SYSTEM, NAME, DIMENSIONS, PREFIX) \
    constexpr auto NAME = quantity<unit<SYSTEM, DIMENSIONS, PREFIX>>{Precision(1)};
#define create_constant(NAME, VALUE, UNIT) \
    constexpr auto NAME = quantity<UNIT>{impl::expand_list_v<Precision, VALUE>};

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