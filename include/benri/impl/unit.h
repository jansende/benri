#pragma once
#include <benri/impl/list.h>
#include <benri/impl/sorting.h>

namespace benri
{
#pragma region unit type
//The unit type saves the dimensions and prefix of a physical unit.
template <class Dimensions, class Prefix>
struct unit
{
    using dimensions = Dimensions;
    using prefix = Prefix;
};
//The has_type function checks if a type has the ::dimensions attribute
//using SFINAE.
template <class T>
struct has_dimensions
{
    template <class U>
    static constexpr auto test(typename U::dimensions *) { return true; }
    template <class U>
    static constexpr auto test(...) { return false; }

    static constexpr auto value = test<T>(0);
};
template <class T>
constexpr bool has_dimensions_v = has_dimensions<T>::value;
//The dimension_is_list function checks if a given type has a ::dimensions
//attribute which is a list. The check is only done, when the given
//bool is true.
template <bool, class T>
struct dimensions_is_list_impl;
template <class T>
struct dimensions_is_list_impl<true, T>
{
    static constexpr auto value = impl::is_list_v<typename T::dimensions>;
};
template <class T>
struct dimensions_is_list_impl<false, T>
{
    static constexpr auto value = false;
};
template <bool Check, class T>
struct dimensions_is_list : std::integral_constant<bool, dimensions_is_list_impl<Check, T>::value>
{
};
template <bool Check, class T>
constexpr bool dimensions_is_list_v = dimensions_is_list<Check, T>::value;
//The has_valid_dimensions function checks if a given type has a ::dimensions
//attribute which is a list.
template <class T>
struct has_valid_dimensions : std::integral_constant<bool, dimensions_is_list_v<has_dimensions_v<T>, T>>
{
};
template <class T>
constexpr bool has_valid_dimensions_v = has_valid_dimensions<T>::value;
//The has_type function checks if a type has the ::prefix attribute
//using SFINAE.
template <class T>
struct has_prefix
{
    template <class U>
    static constexpr auto test(typename U::prefix *) { return true; }
    template <class U>
    static constexpr auto test(...) { return false; }

    static constexpr auto value = test<T>(0);
};
template <class T>
constexpr bool has_prefix_v = has_prefix<T>::value;
//The prefix_is_list function checks if a given type has a ::prefix
//attribute which is a list. The check is only done, when the given
//bool is true.
template <bool, class T>
struct prefix_is_list_impl;
template <class T>
struct prefix_is_list_impl<true, T>
{
    static constexpr auto value = impl::is_list_v<typename T::prefix>;
};
template <class T>
struct prefix_is_list_impl<false, T>
{
    static constexpr auto value = false;
};
template <bool Check, class T>
struct prefix_is_list : std::integral_constant<bool, prefix_is_list_impl<Check, T>::value>
{
};
template <bool Check, class T>
constexpr bool prefix_is_list_v = prefix_is_list<Check, T>::value;
//The has_valid_prefix function checks if a given type has a ::prefix
//attribute which is a list.
template <class T>
struct has_valid_prefix : std::integral_constant<bool, prefix_is_list_v<has_prefix_v<T>, T>>
{
};
template <class T>
constexpr bool has_valid_prefix_v = has_valid_prefix<T>::value;
//The is_unit function checks if a type has a ::dimensions and a ::prefix
//attribute. This does not mean, we have an unit type, but we do not
//care, as we can do the necessary calculations.
template <class T>
struct is_unit : std::integral_constant<bool, has_valid_dimensions_v<T> && has_valid_prefix_v<T>> //TODO: - check if Power is a ratio
{
};
template <class T>
constexpr bool is_unit_v = is_unit<T>::value;
//TODO: - Put this into a unit test folder.
//basic tests
static_assert(!is_unit_v<int>, "");
static_assert(!is_unit_v<unit<double, double>>, "");
static_assert(is_unit_v<unit<list<>, list<>>>, "");
template <class T>
struct is_dimensionless : std::integral_constant<bool, std::is_same_v<typename T::dimensions, list<>>>
{
};
template <class T>
constexpr bool is_dimensionless_v = is_dimensionless<T>::value;
template <class T>
struct is_one : std::integral_constant<bool, std::is_same_v<typename T::dimensions, list<>> && std::is_same_v<typename T::prefix, list<>>>
{
};
template <class T>
constexpr bool is_one_v = is_one<T>::value;
#pragma endregion
#pragma region unit functions
#pragma region multiplication
//The multiply_units function multiplies two units.
template <class...Lists>
struct multiply_units_impl {
    using type = void;
};
template <class lhsUnit, class rhsUnit>
struct multiply_units_impl<lhsUnit, rhsUnit> {
    using type = unit<multiply_lists<typename lhsUnit::dimensions, typename rhsUnit::dimensions>, multiply_lists<typename lhsUnit::prefix, typename rhsUnit::prefix>>;
};
template <class lhsUnit, class rhsUnit, class...Rest>
struct multiply_units_impl<lhsUnit, rhsUnit, Rest...> {
    using type = typename multiply_units_impl<typename multiply_units_impl<lhsUnit, rhsUnit>::type, Rest...>::type;
};

template <class...Lists>
using multiply_units = typename multiply_units_impl<Lists...>::type;
#pragma endregion
#pragma region power
//The pow_unit function applies a given power to a unit.
template <class Unit, class Power>
using pow_unit = unit<pow_list<typename Unit::dimensions, Power>, pow_list<typename Unit::prefix, Power>>;
#pragma endregion
#pragma region division
//The divide_units function divide two units.
template <class lhsUnit, class rhsUnit>
using divide_units = unit<divide_lists<typename lhsUnit::dimensions, typename rhsUnit::dimensions>,divide_lists<typename lhsUnit::prefix, typename rhsUnit::prefix>>;
#pragma endregion
#pragma endregion
#pragma region unit compatibility checker
//The is_compatible function checks if two units should be handled
//as if they are equivalent, even if they are not.
template <class LDimensions, class LPrefix, class RDimensions, class RPrefix>
struct is_compatible_impl : std::false_type
{
};
template <class L, class R>
struct is_compatible : std::integral_constant<bool, is_compatible_impl<typename L::dimensions, typename L::prefix, typename R::dimensions, typename R::prefix>::value>
{
};
template <class L, class R>
constexpr bool is_compatible_v = is_compatible<L, R>::value;
#pragma endregion
#pragma region remove prefix
template <class Unit>
using remove_unit_prefix = unit<typename Unit::dimensions, list<>>;
#pragma endregion
} // namespace benri