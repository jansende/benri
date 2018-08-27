#pragma once

#define fix(...) __VA_ARGS__
#define _create_unit(SYSTEM, NAME, DIMENSIONS, PREFIX) \
    struct NAME                                        \
    {                                                  \
        using dimensions = DIMENSIONS;                 \
        using prefix = PREFIX;                         \
        using system = SYSTEM;                         \
    };
#define _register_unit(NAMESPACE, NAME)                                                                                                      \
    template <>                                                                                                                              \
    struct back_substitution<unit<typename NAMESPACE::NAME::system, typename NAMESPACE::NAME::dimensions, typename NAMESPACE::NAME::prefix>> \
    {                                                                                                                                        \
        using type = NAMESPACE::NAME;                                                                                                        \
    };
#define _create_literal(NAME, LITERAL)                              \
    constexpr auto operator"" LITERAL(long double value)            \
    {                                                               \
        return quantity<NAME>{Precision(value)};                    \
    }                                                               \
    constexpr auto operator"" LITERAL(unsigned long long int value) \
    {                                                               \
        return quantity<NAME>{Precision(value)};                    \
    }
#define _create_and_register_unit(SYSTEM, NAMESPACE, NAME, DIMENSIONS, PREFIX) \
    _create_unit(SYSTEM, NAME, fix(DIMENSIONS), fix(PREFIX));                  \
    }                                                                          \
    _register_unit(NAMESPACE, NAME);                                           \
    namespace NAMESPACE                                                        \
    {
#define _create_and_register_unit_with_literal(SYSTEM, NAMESPACE, NAME, LITERAL, DIMENSIONS, PREFIX) \
    _create_and_register_unit(SYSTEM, NAMESPACE, NAME, fix(DIMENSIONS), fix(PREFIX));                \
    _create_literal(NAME, LITERAL);
#define implement_unit(SYSTEM, NAMESPACE, NAME, LITERAL, DIMENSIONS, PREFIX) \
    _create_and_register_unit_with_literal(SYSTEM, NAMESPACE, NAME, LITERAL, fix(DIMENSIONS), fix(PREFIX));
#define create_constant(SYSTEM, NAME, DIMENSIONS, PREFIX) \
    constexpr auto NAME = quantity<unit<SYSTEM, DIMENSIONS, PREFIX>>{Precision(1)};

#define _create_dimension(NAME, ...)    \
    struct NAME                         \
    {                                   \
        using type = list<__VA_ARGS__>; \
    };                                  \
    using NAME##_t = NAME::type;
#define _register_dimension(NAME)                      \
    template <>                                        \
    struct back_substitution<typename dim::NAME::type> \
    {                                                  \
        using type = dim::NAME;                        \
    };
#define create_and_register_dimension(NAME, ...) \
    _create_dimension(NAME, __VA_ARGS__);        \
    }                                            \
    _register_dimension(NAME);                   \
    namespace dim                                \
    {