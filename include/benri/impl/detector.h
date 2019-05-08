#pragma once
#include <type_traits>
#include <ratio>

namespace benri
{
//The detection idom idea was taken from C++Now 2017 talk of Marshall Clow,
//called "The 'Detection idiom:' A Better Way to SFINAE"
//See: https://www.youtube.com/watch?v=U3jGdnRL3KI
template <class...>
using voidify = void;

template <class Default, class VoidType, template <class...> class Op, class... Args>
struct detector
{
    static constexpr bool value = false;
};
template <class Default, template <class...> class Op, class... Args>
struct detector<Default, voidify<Op<Args...>>, Op, Args...>
{
    static constexpr bool value = true;
};

template <class T, template <class...> class Op, class... Args>
constexpr bool detect_if = detector<void, void, Op, T, Args...>::value;
} // namespace benri