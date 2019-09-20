#pragma once
#include <type_traits>
#include <ratio>
#include <benri/impl/meta/array.h>
#include <benri/impl/meta/algorithm.h>

namespace benri
{
namespace type
{
#pragma region detector
//Detector idea taken from C++Now 2017 talk of Marshall Clow, called
//"The 'Detection idiom:' A Better Way to SFINAE"
//See: https://www.youtube.com/watch?v=U3jGdnRL3KI
template <class...>
using voidify = void;

template <class Default, class VoidType, template <class...> class Op, class... Args>
struct detector
{
    static constexpr bool value = false;
    using type = Default;
};
template <class Default, template <class...> class Op, class... Args>
struct detector<Default, voidify<Op<Args...>>, Op, Args...>
{
    static constexpr bool value = true;
    using type = Op<Args...>;
};

template <class T, template <class...> class Op, class... Args>
constexpr bool detect_if = detector<void, void, Op, T, Args...>::value;

//Shortcut for running detect_if over a type list.
template <bool... bs>
constexpr bool all_true = meta::accumulate(meta::array<bool, sizeof...(bs)>{bs...}, true, std::logical_and<bool>{});
template <bool... bs>
constexpr bool any_true = meta::accumulate(meta::array<bool, sizeof...(bs)>{bs...}, false, std::logical_or<bool>{});
template <bool... bs>
constexpr bool none_true = !any_true<bs...>;
#pragma endregion
#pragma region type traits
template <class... Elements>
struct list;
template <class... Elements>
struct sorted_list;

template <class>
struct is_list_impl : std::false_type
{
};
template <class... Elements>
struct is_list_impl<sorted_list<Elements...>> : std::true_type
{
};
template <class... Elements>
struct is_list_impl<list<Elements...>> : std::true_type
{
};
template <class T>
using is_list = std::enable_if_t<is_list_impl<T>::value>;

template <class>
struct is_sorted_list_impl : std::false_type
{
};
template <class... Elements>
struct is_sorted_list_impl<sorted_list<Elements...>> : std::true_type
{
};
template <class T>
using is_sorted_list = std::enable_if_t<is_sorted_list_impl<T>::value>;
#pragma endregion
} // namespace type
} // namespace benri