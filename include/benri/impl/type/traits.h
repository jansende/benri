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
//"The 'Detection idiom:' A Better Way to SFINAE".
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
constexpr bool all_true = meta::accumulate(meta::array<bool, sizeof...(bs)>{bs...}, true,
                                           std::logical_and<bool>{});
template <bool... bs>
constexpr bool any_true = meta::accumulate(meta::array<bool, sizeof...(bs)>{bs...}, false,
                                           std::logical_or<bool>{});
template <bool... bs>
constexpr bool none_true = !any_true<bs...>;
#pragma endregion
#pragma region forward declarations
template <class... Elements>
struct list;
template <class... Elements>
struct sorted_list;
} // namespace type
template <class Dimension, class Prefix>
struct unit;
template <class T, class Power>
struct dim;
template <class T, class Power>
struct pre;
namespace type
{
#pragma endregion
#pragma region type traits
//Check if a type is a either a list or a sorted_list.
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
//Check if a type is a either a empty list or a empty sorted_list.
template <class>
struct is_empty_list_impl : std::false_type
{
};
template <>
struct is_empty_list_impl<sorted_list<>> : std::true_type
{
};
template <>
struct is_empty_list_impl<list<>> : std::true_type
{
};
template <class T>
using is_empty_list = std::enable_if_t<is_empty_list_impl<T>::value>;
//Check if a type is a sorted_list.
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
//Check if a type is a unit.
template <class>
struct is_unit_impl : std::false_type
{
};
template <class Dimension, class Prefix>
struct is_unit_impl<unit<Dimension, Prefix>> : std::true_type
{
};
template <class T>
using is_unit = std::enable_if_t<is_unit_impl<T>::value>;
//Check if a type is a unit without prefix and dimension.
template <class T>
using is_one = typename std::enable_if_t<
    detect_if<T, is_unit> &&
    detect_if<typename T::prefix, is_empty_list> &&
    detect_if<typename T::dimensions, is_empty_list>>;
//Check if a type is a unit without dimension.
template <class T>
using is_dimensionless = typename std::enable_if_t<
    detect_if<T, is_unit> &&
    detect_if<typename T::dimensions, is_empty_list>>;
//Check if a type is a dimension.
template <class>
struct is_dimension_impl : std::false_type
{
};
template <class T, class Power>
struct is_dimension_impl<dim<T, Power>> : std::true_type
{
};
template <class T>
using is_dimension = std::enable_if_t<is_dimension_impl<T>::value>;
//Check if a type is a prefix.
template <class>
struct is_prefix_impl : std::false_type
{
};
template <class T, class Power>
struct is_prefix_impl<pre<T, Power>> : std::true_type
{
};
template <class T>
using is_prefix = std::enable_if_t<is_prefix_impl<T>::value>;
//Check if a type is std::ratio.
template <class>
struct is_std_ratio_impl : std::false_type
{
};
template <intmax_t Num, intmax_t Den>
struct is_std_ratio_impl<std::ratio<Num, Den>> : std::true_type
{
};
template <class T>
using is_std_ratio = typename std::enable_if<is_std_ratio_impl<T>::value>::type;
//Check if a type is std::ratio with an integer value (no ratio).
template <class T>
using is_integer_ratio = typename std::enable_if_t<
    detect_if<T, is_std_ratio> &&
    (T::den == 1)>;
//Basic tests
static_assert(detect_if<std::ratio<2>, is_integer_ratio>, "2 is an integer.");
static_assert(detect_if<std::ratio<-2>, is_integer_ratio>, "-2 is an integer.");
static_assert(!detect_if<std::ratio<3, 5>, is_integer_ratio>, "3/5 is not an integer.");
static_assert(!detect_if<std::ratio<5, 3>, is_integer_ratio>, "5/3 is not an integer.");
static_assert(detect_if<std::ratio<5, 5>, is_integer_ratio>, "5/5 is an integer.");
//Check if a type has a ::type attribute using SFINAE.
template <class T>
using has_type = typename T::type;
//Check if a type has a static constexpr ::name attribute using SFINAE.
template <class T>
using has_name = decltype(T::name);
//Check if a type has a static constexpr ::value attribute using SFINAE.
template <class T>
using has_value = decltype(T::value);
#pragma endregion
} // namespace type
} // namespace benri