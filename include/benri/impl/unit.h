#pragma once
#include <benri/impl/list.h>

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
    static constexpr auto test(typename U::dimensions *) { return true; };
    template <class U>
    static constexpr auto test(...) { return false; };

    static constexpr auto value = test<T>(0);
};
template <class T>
constexpr auto has_dimensions_v = has_dimensions<T>::value;
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
constexpr auto dimensions_is_list_v = dimensions_is_list<Check, T>::value;
//The has_valid_dimensions function checks if a given type has a ::dimensions
//attribute which is a list.
template <class T>
struct has_valid_dimensions : std::integral_constant<bool, dimensions_is_list_v<has_dimensions_v<T>, T>>
{
};
template <class T>
constexpr auto has_valid_dimensions_v = has_valid_dimensions<T>::value;
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
constexpr auto has_prefix_v = has_prefix<T>::value;
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
constexpr auto prefix_is_list_v = prefix_is_list<Check, T>::value;
//The has_valid_prefix function checks if a given type has a ::prefix
//attribute which is a list.
template <class T>
struct has_valid_prefix : std::integral_constant<bool, prefix_is_list_v<has_prefix_v<T>, T>>
{
};
template <class T>
constexpr auto has_valid_prefix_v = has_valid_prefix<T>::value;
//The is_unit function checks if a type has a ::dimensions and a ::prefix
//attribute. This does not mean, we have an unit type, but we do not
//care, as we can do the necessary calculations.
template <class T>
struct is_unit : std::integral_constant<bool, has_valid_dimensions_v<T> && has_valid_prefix_v<T>> //TODO: - check if Power is a ratio
{
};
template <class T>
constexpr auto is_unit_v = is_unit<T>::value;
//TODO: - Put this into a unit test folder.
auto test_is_unit()
{
    static_assert(!is_unit_v<int>, "");
    static_assert(!is_unit_v<unit<double, double>>, "");
    static_assert(is_unit_v<unit<list<>, list<>>>, "");
}
#pragma endregion
#pragma region back substitution
//The back_substituion function provides overloads to simplify
//complicated units by returning their shortcuts.
template <class T>
struct back_substitution
{
    using type = T;
};
template <class T>
using back_substitution_t = typename back_substitution<T>::type;
#pragma endregion
#pragma region unit functions
#pragma region multiplication
//The multiply_units_t function multiplies two units.
template <class L, class R>
struct multiply_units
{
    static_assert(is_unit_v<L> && is_unit_v<R>, "pow_unit takes a unit and a std::ratio, but one of them is not a unit.");
    using type = typename multiply_units<unit<typename L::dimensions, typename L::prefix>, unit<typename R::dimensions, typename R::prefix>>::type;
};
template <template <class, class> class Unit, class Dimensions, class Prefix, class R>
struct multiply_units<Unit<Dimensions, Prefix>, R>
{
    static_assert(is_unit_v<R>, "pow_unit takes a unit and a std::ratio, but R is not a unit.");
    using type = typename multiply_units<Unit<Dimensions, Prefix>, unit<typename R::dimensions, typename R::prefix>>::type;
};
template <class L, template <class, class> class Unit, class Dimensions, class Prefix>
struct multiply_units<L, Unit<Dimensions, Prefix>>
{
    static_assert(is_unit_v<L>, "pow_unit takes a unit and a std::ratio, but L is not a unit.");
    using type = typename multiply_units<unit<typename L::dimensions, typename L::prefix>, Unit<Dimensions, Prefix>>::type;
};
template <template <class, class> class LUnit, class LDimensions, class LPrefix, template <class, class> class RUnit, class RDimensions, class RPrefix>
struct multiply_units<LUnit<LDimensions, LPrefix>, RUnit<RDimensions, RPrefix>>
{
    using type = back_substitution_t<unit<impl::multiply_lists_t<LDimensions, RDimensions>, impl::multiply_lists_t<LPrefix, RPrefix>>>;
};
template <class L, class R>
using multiply_units_t = typename multiply_units<L, R>::type;
//The divide_units function divide two units.
template <class L, class R>
struct divide_units
{
    static_assert(is_unit_v<L> && is_unit_v<R>, "pow_unit takes a unit and a std::ratio, but one of them is not a unit.");
    using type = typename divide_units<unit<typename L::dimensions, typename L::prefix>, unit<typename R::dimensions, typename R::prefix>>::type;
};
template <template <class, class> class Unit, class Dimensions, class Prefix, class R>
struct divide_units<Unit<Dimensions, Prefix>, R>
{
    static_assert(is_unit_v<R>, "pow_unit takes a unit and a std::ratio, but R is not a unit.");
    using type = typename divide_units<Unit<Dimensions, Prefix>, unit<typename R::dimensions, typename R::prefix>>::type;
};
template <class L, template <class, class> class Unit, class Dimensions, class Prefix>
struct divide_units<L, Unit<Dimensions, Prefix>>
{
    static_assert(is_unit_v<L>, "pow_unit takes a unit and a std::ratio, but L is not a unit.");
    using type = typename divide_units<unit<typename L::dimensions, typename L::prefix>, Unit<Dimensions, Prefix>>::type;
};
template <template <class, class> class LUnit, class LDimensions, class LPrefix, template <class, class> class RUnit, class RDimensions, class RPrefix>
struct divide_units<LUnit<LDimensions, LPrefix>, RUnit<RDimensions, RPrefix>>
{
    using type = back_substitution_t<unit<impl::divide_lists_t<LDimensions, RDimensions>, impl::divide_lists_t<LPrefix, RPrefix>>>;
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
    using type = typename pow_unit<unit<typename L::dimensions, typename L::prefix>, R>::type;
};
template <template <class, class> class Unit, class Dimensions, class Prefix, intmax_t num, intmax_t den>
struct pow_unit<Unit<Dimensions, Prefix>, std::ratio<num, den>>
{
    using type = back_substitution_t<unit<impl::pow_list_t<Dimensions, std::ratio<num, den>>, impl::pow_list_t<Prefix, std::ratio<num, den>>>>;
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
constexpr auto is_equivalent_v = is_equivalent<L, R>::value;
#pragma endregion
} // namespace benri