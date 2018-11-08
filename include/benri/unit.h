#pragma once
#include <benri/impl/list.h>
#include <benri/impl/sorting.h>

namespace benri
{
#pragma region unit type
//The unit type saves the dimensions and prefix of a physical unit.
template <class System, class Dimensions, class Prefix>
struct unit
{
    using dimensions = Dimensions;
    using prefix = Prefix;
    using system = System;
};
//The has_type function checks if a type has the ::dimensions attribute
//using SFINAE.
template <class T>
struct has_dimensions
{
    template <class U>
    static constexpr auto test(typename U::dimensions *) { return true; };
    template <class U>
    static constexpr auto test(...) { return false; };

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
    static constexpr auto test(typename U::prefix *) { return true; };
    template <class U>
    static constexpr auto test(...) { return false; };

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
//The has_system function checks if a type has the ::system attribute
//using SFINAE.
template <class T>
struct has_system
{
    template <class U>
    static constexpr auto test(typename U::system *) { return true; };
    template <class U>
    static constexpr auto test(...) { return false; };

    static constexpr auto value = test<T>(0);
};
template <class T>
constexpr bool has_system_v = has_system<T>::value;
//The is_unit function checks if a type has a ::dimensions and a ::prefix
//attribute. This does not mean, we have an unit type, but we do not
//care, as we can do the necessary calculations.
template <class T>
struct is_unit : std::integral_constant<bool, has_valid_dimensions_v<T> && has_valid_prefix_v<T> && has_system_v<T>> //TODO: - check if Power is a ratio
{
};
template <class T>
constexpr bool is_unit_v = is_unit<T>::value;
//TODO: - Put this into a unit test folder.
auto test_is_unit()
{
    static_assert(!is_unit_v<int>, "");
    static_assert(!is_unit_v<unit<double, double, double>>, "");
    static_assert(is_unit_v<unit<double, list<>, list<>>>, "");
}
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
#pragma region name resolution
//The resolve_name function provides overloads to get the
//name of complicated units.
template <class T>
struct resolve_name
{
    static constexpr auto name = "unknown";
};
template <class T>
constexpr auto resolve_name_v = resolve_name<T>::name;
#pragma endregion
#pragma region unit functions
#pragma region multiplication
//The multiply_units_t function multiplies two units.
template <class L, class R>
struct multiply_units
{
    static_assert(is_unit_v<L> && is_unit_v<R>, "pow_unit takes a unit and a std::ratio, but one of them is not a unit.");
    static_assert(std::is_same_v<typename L::system, typename R::system>, "Both L and R have to have the same unit system.");
    using type = typename multiply_units<unit<typename L::system, typename L::dimensions, typename L::prefix>, unit<typename R::system, typename R::dimensions, typename R::prefix>>::type;
};
template <template <class, class, class> class Unit, class System, class Dimensions, class Prefix, class R>
struct multiply_units<Unit<System, Dimensions, Prefix>, R>
{
    static_assert(is_unit_v<R>, "pow_unit takes a unit and a std::ratio, but R is not a unit.");
    using type = typename multiply_units<Unit<System, Dimensions, Prefix>, unit<typename R::system, typename R::dimensions, typename R::prefix>>::type;
};
template <class L, template <class, class, class> class Unit, class System, class Dimensions, class Prefix>
struct multiply_units<L, Unit<System, Dimensions, Prefix>>
{
    static_assert(is_unit_v<L>, "pow_unit takes a unit and a std::ratio, but L is not a unit.");
    using type = typename multiply_units<unit<typename L::system, typename L::dimensions, typename L::prefix>, Unit<System, Dimensions, Prefix>>::type;
};
template <template <class, class, class> class LUnit, class LSystem, class LDimensions, class LPrefix, template <class, class, class> class RUnit, class RSystem, class RDimensions, class RPrefix>
struct multiply_units<LUnit<LSystem, LDimensions, LPrefix>, RUnit<RSystem, RDimensions, RPrefix>>
{
    static_assert(std::is_same_v<LSystem, RSystem>, "Both L and R have to have the same unit system.");
    using type = unit<LSystem, impl::multiply_lists_t<LDimensions, RDimensions>, impl::multiply_lists_t<LPrefix, RPrefix>>;
};
template <class L, class R>
using multiply_units_t = typename multiply_units<L, R>::type;
//The divide_units function divide two units.
template <class L, class R>
struct divide_units
{
    static_assert(is_unit_v<L> && is_unit_v<R>, "pow_unit takes a unit and a std::ratio, but one of them is not a unit.");
    static_assert(std::is_same_v<typename L::system, typename R::system>, "Both L and R have to have the same unit system.");
    using type = typename divide_units<unit<typename L::system, typename L::dimensions, typename L::prefix>, unit<typename R::system, typename R::dimensions, typename R::prefix>>::type;
};
template <template <class, class, class> class Unit, class System, class Dimensions, class Prefix, class R>
struct divide_units<Unit<System, Dimensions, Prefix>, R>
{
    static_assert(is_unit_v<R>, "pow_unit takes a unit and a std::ratio, but R is not a unit.");
    using type = typename divide_units<Unit<System, Dimensions, Prefix>, unit<typename R::system, typename R::dimensions, typename R::prefix>>::type;
};
template <class L, template <class, class, class> class Unit, class System, class Dimensions, class Prefix>
struct divide_units<L, Unit<System, Dimensions, Prefix>>
{
    static_assert(is_unit_v<L>, "pow_unit takes a unit and a std::ratio, but L is not a unit.");
    using type = typename divide_units<unit<typename L::system, typename L::dimensions, typename L::prefix>, Unit<System, Dimensions, Prefix>>::type;
};
template <template <class, class, class> class LUnit, class LSystem, class LDimensions, class LPrefix, template <class, class, class> class RUnit, class RSystem, class RDimensions, class RPrefix>
struct divide_units<LUnit<LSystem, LDimensions, LPrefix>, RUnit<RSystem, RDimensions, RPrefix>>
{
    static_assert(std::is_same_v<LSystem, RSystem>, "Both L and R have to have the same unit system.");
    using type = unit<LSystem, impl::divide_lists_t<LDimensions, RDimensions>, impl::divide_lists_t<LPrefix, RPrefix>>;
};
template <class L, class R>
using divide_units_t = typename divide_units<L, R>::type;
#pragma endregion
#pragma region power
//The pow_unit function applies a given power to a unit.
template <class L, class R>
struct pow_unit
{
    static_assert(is_unit_v<L>, "pow_unit takes a unit and a std::ratio, but your L is not a unit.");
    static_assert(impl::is_ratio_v<R>, "pow_unit takes a unit and a std::ratio, but your R is not a std::ratio.");
    using type = typename pow_unit<unit<typename L::system, typename L::dimensions, typename L::prefix>, R>::type;
};
template <template <class, class, class> class Unit, class System, class Dimensions, class Prefix, intmax_t num, intmax_t den>
struct pow_unit<Unit<System, Dimensions, Prefix>, std::ratio<num, den>>
{
    using type = unit<System, impl::pow_list<Dimensions, std::ratio<num, den>>, impl::pow_list<Prefix, std::ratio<num, den>>>;
};
template <class L, class R>
using pow_unit_t = typename pow_unit<L, R>::type;
#pragma endregion
#pragma endregion
#pragma region unit equivalence checker
//The is_equivalent function checks if two units are equivalent.
//Meaning that the dimensions and prefixes are equal.
template <class L, class R>
struct is_equivalent : std::integral_constant<bool, impl::is_equivalent_list_v<typename L::dimensions, typename R::dimensions> && impl::is_equivalent_list_v<typename L::prefix, typename R::prefix>>
{
};
template <class L, class R>
constexpr bool is_equivalent_v = is_equivalent<L, R>::value;
#pragma endregion
#pragma region unit compatibility checker
//The is_compatible function checks if two units should be handled
//as if they are equivalent, even if they are not.
template <class LSystem, class LDimensions, class LPrefix, class RSystem, class RDimensions, class RPrefix, class Enable = void>
struct is_compatible_impl : std::false_type
{
};
template <class L, class R>
struct is_compatible : std::integral_constant<bool, is_compatible_impl<typename L::system, typename L::dimensions, typename L::prefix, typename R::system, typename R::dimensions, typename R::prefix>::value>
{
};
template <class L, class R>
constexpr bool is_compatible_v = is_compatible<L, R>::value;
#pragma endregion
#pragma region remove prefix
template <class T>
struct no_prefix_unit
{
    static_assert(is_unit_v<T>, "no_prefix_unit takes a unit, but your T is not a unit.");
    using type = unit<typename T::system, typename T::dimensions, list<>>;
};
template <class System, class Dimensions, class Prefix>
struct no_prefix_unit<unit<System, Dimensions, Prefix>>
{
    using type = unit<System, Dimensions, list<>>;
};
template <class T>
using no_prefix_unit_t = typename no_prefix_unit<T>::type;
#pragma endregion
} // namespace benri