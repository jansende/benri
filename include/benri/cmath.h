#pragma once
#include <benri/quantity.h>
#include <benri/quantity_point.h>
#include <benri/impl/dimensions.h>
#include <benri/impl/list.h>
#include <benri/impl/meta_math.h>
#include <benri/impl/unit.h>
#include <algorithm>
#include <cmath>
#include <cstdlib>
namespace std
{
template <class T>
struct remove_cvref
{
    typedef std::remove_cv_t<std::remove_reference_t<T>> type;
};
template <class T>
using remove_cvref_t = typename remove_cvref<T>::type;
} // namespace std

namespace benri
{
#pragma region helpers
//make_dimensionless is a shortcut for dimensionless types
template <class Prefix>
using make_dimensionless = unit<typename dim::dimensionless_t, Prefix>;
//make_one creates a dimensionless type from the given Unit
template <class Unit>
using make_one = unit<typename dim::dimensionless_t, list<>>;
//make_plane_angle creates an angle type from the given Unit
template <class Unit>
using make_plane_angle = unit<typename dim::plane_angle_t, list<>>;
#pragma endregion
#pragma region cmath
//In the following, most functions of <cmath> are implemented. The order and
//classification follows: https://en.cppreference.com/w/cpp/header/cmath
//
//By default, functions will not compile if the value_type of the input is
//implicitly converted. This helps to protect against implicit conversions,
//which are especially confusion for beginners. For example, if you calcu-
//late fabs(quantity<one,int>{-1}), the result is quantity<one,double>{1.0}
//and not quantity<one,int>{1}, which one would expect.
//In order to protect against these kind of conversions, the input and the
//output value_type are statically compared, and the code will not compile,
//if they differ.
//There are four possibilities to make the code compile again:
//1. value_type_cast the quantity to the right type:
//   fabs(value_type_cast<double>(quantity<one,int>{-1}))
//
//   This approach still results in a quantity<one,double>{1.0}, but the
//   conversion is now visible. (If one still wants the result to be of
//   value_type int, one has to use an appropriate function for the back
//   conversion.)
//2. Use the right types from the get go: fabs(quantity<one,double>{-1.0})
//3. Allow implicit conversions, just for this function:
//   fabs<true>(quantity<one,int>{-1})
//4. Always allow implicit conversions by defining the helper macro
//   BENRI_ALLOW_IMPLICIT_CONVERSIONS, before importing benri.
//   (This is only recommended for experienced programmers.)
//
//Some of the functions have overloads, to take mixed inputs of quantities
//and value types, in order to allow sensible operations. For example:
//atan2(quantity<one,double>{1.0}, 1.0) compiles, even though 1.0 is not a
//quantity. However, none of these overloads will work on value_types
//alone: atan2(1.0,1.0) is not possible. Use the std functions instead!
//
//Note: Most functions have an explicit (trailing) return type. This is
//actually unnecessary, because the return type can be deduced from the
//calculation. However, specifying the return type helps in finding implemen-
//tation bugs, plus it should reduce the number of error messages in the case
//of faulty input parameters.
//For example: atan2(1_metre,1_second) is faulty, and will not compile. How-
//ever, we know that the output of atan2 will be an angle, no matter the
//input. Thus, only an error message for the faulty input is shown, and none
//for the code which depends on the result of the atan2 call. (Which might be
//deduced wrongly from the input.)
#pragma region standard min / max
//The max, and min functions return the max/min of two quantities with
//the same unit.
template <bool AllowImplicitConversion = false, class xUnit, class yUnit, class ValueType>
constexpr auto max(quantity<xUnit, ValueType> x, quantity<yUnit, ValueType> y) -> quantity<xUnit, std::remove_cvref_t<decltype(std::max(x.value(), y.value()))>>
{
    static_assert(std::is_same_v<xUnit, yUnit> || is_compatible_v<xUnit, yUnit>, "You can only calculate the max of quantities with the same unit.");
    using ResultType = std::remove_cvref_t<decltype(std::max(x.value(), y.value()))>;
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<xUnit, ResultType>{std::max(x.value(), y.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class yUnit, class ValueType>
constexpr auto max(quantity_point<xUnit, ValueType> x, quantity_point<yUnit, ValueType> y) -> quantity_point<xUnit, std::remove_cvref_t<decltype(std::max(x.value(), y.value()))>>
{
    static_assert(std::is_same_v<xUnit, yUnit>, "You can only calculate the max of quantities with the same unit.");
    using ResultType = std::remove_cvref_t<decltype(std::max(x.value(), y.value()))>;
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<xUnit, ResultType>{std::max(x.value(), y.value())};
}
template <bool AllowImplicitConversion = false, class yUnit, class ValueType>
constexpr auto max(ValueType x, quantity<yUnit, ValueType> y) -> quantity<make_one<yUnit>, std::remove_cvref_t<decltype(std::max(x, y.value()))>>
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit>, "You can only calculate the max of quantities with the same unit.");
    using ResultType = std::remove_cvref_t<decltype(std::max(x, y.value()))>;
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<yUnit>, ResultType>{std::max(x, y.value())};
}
template <bool AllowImplicitConversion = false, class yUnit, class ValueType>
constexpr auto max(ValueType x, quantity_point<yUnit, ValueType> y) -> quantity_point<make_one<yUnit>, std::remove_cvref_t<decltype(std::max(x, y.value()))>>
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit>, "You can only calculate the max of quantities with the same unit.");
    using ResultType = std::remove_cvref_t<decltype(std::max(x, y.value()))>;
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<make_one<yUnit>, ResultType>{std::max(x, y.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class ValueType>
constexpr auto max(quantity<xUnit, ValueType> x, ValueType y) -> quantity<make_one<xUnit>, std::remove_cvref_t<decltype(std::max(x.value(), y))>>
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit>, "You can only calculate the max of quantities with the same unit.");
    using ResultType = std::remove_cvref_t<decltype(std::max(x.value(), y))>;
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<xUnit>, ResultType>{std::max(x.value(), y)};
}
template <bool AllowImplicitConversion = false, class xUnit, class ValueType>
constexpr auto max(quantity_point<xUnit, ValueType> x, ValueType y) -> quantity_point<make_one<xUnit>, std::remove_cvref_t<decltype(std::max(x.value(), y))>>
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit>, "You can only calculate the max of quantities with the same unit.");
    using ResultType = std::remove_cvref_t<decltype(std::max(x.value(), y))>;
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<make_one<xUnit>, ResultType>{std::max(x.value(), y)};
}
template <bool AllowImplicitConversion = false, class xUnit, class yUnit, class ValueType>
constexpr auto min(quantity<xUnit, ValueType> x, quantity<yUnit, ValueType> y) -> quantity<xUnit, std::remove_cvref_t<decltype(std::min(x.value(), y.value()))>>
{
    static_assert(std::is_same_v<xUnit, yUnit> || is_compatible_v<xUnit, yUnit>, "You can only calculate the min of quantities with the same unit.");
    using ResultType = std::remove_cvref_t<decltype(std::min(x.value(), y.value()))>;
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<xUnit, ResultType>{std::min(x.value(), y.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class yUnit, class ValueType>
constexpr auto min(quantity_point<xUnit, ValueType> x, quantity_point<yUnit, ValueType> y) -> quantity_point<xUnit, std::remove_cvref_t<decltype(std::min(x.value(), y.value()))>>
{
    static_assert(std::is_same_v<xUnit, yUnit>, "You can only calculate the min of quantities with the same unit.");
    using ResultType = std::remove_cvref_t<decltype(std::min(x.value(), y.value()))>;
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<xUnit, ResultType>{std::min(x.value(), y.value())};
}
template <bool AllowImplicitConversion = false, class yUnit, class ValueType>
constexpr auto min(ValueType x, quantity<yUnit, ValueType> y) -> quantity<make_one<yUnit>, std::remove_cvref_t<decltype(std::min(x, y.value()))>>
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit>, "You can only calculate the min of quantities with the same unit.");
    using ResultType = std::remove_cvref_t<decltype(std::min(x, y.value()))>;
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<yUnit>, ResultType>{std::min(x, y.value())};
}
template <bool AllowImplicitConversion = false, class yUnit, class ValueType>
constexpr auto min(ValueType x, quantity_point<yUnit, ValueType> y) -> quantity_point<make_one<yUnit>, std::remove_cvref_t<decltype(std::min(x, y.value()))>>
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit>, "You can only calculate the min of quantities with the same unit.");
    using ResultType = std::remove_cvref_t<decltype(std::min(x, y.value()))>;
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<make_one<yUnit>, ResultType>{std::min(x, y.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class ValueType>
constexpr auto min(quantity<xUnit, ValueType> x, ValueType y) -> quantity<make_one<xUnit>, std::remove_cvref_t<decltype(std::min(x.value(), y))>>
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit>, "You can only calculate the min of quantities with the same unit.");
    using ResultType = std::remove_cvref_t<decltype(std::min(x.value(), y))>;
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<xUnit>, ResultType>{std::min(x.value(), y)};
}
template <bool AllowImplicitConversion = false, class xUnit, class ValueType>
constexpr auto min(quantity_point<xUnit, ValueType> x, ValueType y) -> quantity_point<make_one<xUnit>, std::remove_cvref_t<decltype(std::min(x.value(), y))>>
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit>, "You can only calculate the min of quantities with the same unit.");
    using ResultType = std::remove_cvref_t<decltype(std::min(x.value(), y))>;
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<make_one<xUnit>, ResultType>{std::min(x.value(), y)};
}
#pragma endregion
#pragma region basic operations
//The abs, and fabs functions calculate the absolute value of quantities
//without looking at the underlying unit.
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto abs(quantity<Unit, ValueType> val) -> quantity<Unit, decltype(std::abs(val.value()))>
{
    using ResultType = decltype(std::abs(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<Unit, ResultType>{std::abs(val.value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto abs(quantity_point<Unit, ValueType> val) -> quantity_point<Unit, decltype(std::abs(val.value()))>
{
    using ResultType = decltype(std::abs(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<Unit, ResultType>{std::abs(val.value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto fabs(quantity<Unit, ValueType> val) -> quantity<Unit, decltype(std::fabs(val.value()))>
{
    using ResultType = decltype(std::fabs(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<Unit, ResultType>{std::fabs(val.value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto fabs(quantity_point<Unit, ValueType> val) -> quantity_point<Unit, decltype(std::fabs(val.value()))>
{
    using ResultType = decltype(std::fabs(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<Unit, ResultType>{std::fabs(val.value())};
}
//The fmod, remainder, and remquo functions calculate the remainder of the
//division of two quantities without looking at the units.
template <bool AllowImplicitConversion = false, class xUnit, class yUnit, class ValueType>
constexpr auto fmod(quantity<xUnit, ValueType> x, quantity<yUnit, ValueType> y) -> quantity<xUnit, decltype(std::fmod(x.value(), y.value()))>
{
    using ResultType = decltype(std::fmod(x.value(), y.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<xUnit, ResultType>{std::fmod(x.value(), y.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class ValueType>
constexpr auto fmod(quantity<xUnit, ValueType> x, ValueType y) -> quantity<xUnit, decltype(std::fmod(x.value(), y))>
{
    using ResultType = decltype(std::fmod(x.value(), y));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<xUnit, ResultType>{std::fmod(x.value(), y)};
}
template <bool AllowImplicitConversion = false, class yUnit, class ValueType>
constexpr auto fmod(ValueType x, quantity<yUnit, ValueType> y) -> quantity<make_one<yUnit>, decltype(std::fmod(x, y.value()))>
{
    using ResultType = decltype(std::fmod(x, y.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<yUnit>, ResultType>{std::fmod(x, y.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class yUnit, class ValueType>
constexpr auto remainder(quantity<xUnit, ValueType> x, quantity<yUnit, ValueType> y) -> quantity<xUnit, decltype(std::remainder(x.value(), y.value()))>
{
    using ResultType = decltype(std::remainder(x.value(), y.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<xUnit, ResultType>{std::remainder(x.value(), y.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class ValueType>
constexpr auto remainder(quantity<xUnit, ValueType> x, ValueType y) -> quantity<xUnit, decltype(std::remainder(x.value(), y))>
{
    using ResultType = decltype(std::remainder(x.value(), y));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<xUnit, ResultType>{std::remainder(x.value(), y)};
}
template <bool AllowImplicitConversion = false, class yUnit, class ValueType>
constexpr auto remainder(ValueType x, quantity<yUnit, ValueType> y) -> quantity<make_one<yUnit>, decltype(std::remainder(x, y.value()))>
{
    using ResultType = decltype(std::remainder(x, y.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<yUnit>, ResultType>{std::remainder(x, y.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class yUnit, class ValueType>
constexpr auto remquo(quantity<xUnit, ValueType> x, quantity<yUnit, ValueType> y, int *quo) -> quantity<xUnit, decltype(std::remquo(x.value(), y.value(), quo))>
{
    using ResultType = decltype(std::remquo(x.value(), y.value(), quo));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<xUnit, ResultType>{std::remquo(x.value(), y.value(), quo)};
}
template <bool AllowImplicitConversion = false, class xUnit, class ValueType>
constexpr auto remquo(quantity<xUnit, ValueType> x, ValueType y, int *quo) -> quantity<xUnit, decltype(std::remquo(x.value(), y, quo))>
{
    using ResultType = decltype(std::remquo(x.value(), y, quo));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<xUnit, ResultType>{std::remquo(x.value(), y, quo)};
}
template <bool AllowImplicitConversion = false, class yUnit, class ValueType>
constexpr auto remquo(ValueType x, quantity<yUnit, ValueType> y, int *quo) -> quantity<make_one<yUnit>, decltype(std::remquo(x, y.value(), quo))>
{
    using ResultType = decltype(std::remquo(x, y.value(), quo));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<yUnit>, ResultType>{std::remquo(x, y.value(), quo)};
}
//The fma function combines a multiplication and addition operation of the quantities
//x, y, z. The result is x*y+z. The units of x*y and z must be equal.
template <bool AllowImplicitConversion = false, class xUnit, class yUnit, class zUnit, class ValueType>
constexpr auto fma(quantity<xUnit, ValueType> x, quantity<yUnit, ValueType> y, quantity<zUnit, ValueType> z) -> quantity<zUnit, decltype(std::fma(x.value(), y.value(), z.value()))>
{
    static_assert(std::is_same_v<multiply_units_t<xUnit, yUnit>, zUnit> || is_compatible_v<multiply_units_t<xUnit, yUnit>, zUnit>, "You can only calculate the fma of quantities with the units being x*y == z.");
    using ResultType = decltype(std::fma(x.value(), y.value(), z.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<zUnit, ResultType>{std::fma(x.value(), y.value(), z.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class yUnit, class zUnit, class ValueType>
constexpr auto fma(quantity<xUnit, ValueType> x, quantity<yUnit, ValueType> y, quantity_point<zUnit, ValueType> z) -> quantity_point<zUnit, decltype(std::fma(x.value(), y.value(), z.value()))>
{
    static_assert(std::is_same_v<multiply_units_t<xUnit, yUnit>, zUnit> || is_compatible_v<multiply_units_t<xUnit, yUnit>, zUnit>, "You can only calculate the fma of quantities with the units being x*y == z.");
    using ResultType = decltype(std::fma(x.value(), y.value(), z.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<zUnit, ResultType>{std::fma(x.value(), y.value(), z.value())};
}
template <bool AllowImplicitConversion = false, class yUnit, class zUnit, class ValueType>
constexpr auto fma(ValueType x, quantity<yUnit, ValueType> y, quantity<zUnit, ValueType> z) -> quantity<zUnit, decltype(std::fma(x, y.value(), z.value()))>
{
    static_assert(std::is_same_v<yUnit, zUnit> || is_compatible_v<yUnit, zUnit>, "You can only calculate the fma of quantities with the units being x*y == z.");
    using ResultType = decltype(std::fma(x, y.value(), z.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<zUnit, ResultType>{std::fma(x, y.value(), z.value())};
}
template <bool AllowImplicitConversion = false, class yUnit, class zUnit, class ValueType>
constexpr auto fma(ValueType x, quantity<yUnit, ValueType> y, quantity_point<zUnit, ValueType> z) -> quantity_point<zUnit, decltype(std::fma(x, y.value(), z.value()))>
{
    static_assert(std::is_same_v<yUnit, zUnit> || is_compatible_v<yUnit, zUnit>, "You can only calculate the fma of quantities with the units being x*y == z.");
    using ResultType = decltype(std::fma(x, y.value(), z.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<zUnit, ResultType>{std::fma(x, y.value(), z.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class zUnit, class ValueType>
constexpr auto fma(quantity<xUnit, ValueType> x, ValueType y, quantity<zUnit, ValueType> z) -> quantity<zUnit, decltype(std::fma(x.value(), y, z.value()))>
{
    static_assert(std::is_same_v<xUnit, zUnit> || is_compatible_v<xUnit, zUnit>, "You can only calculate the fma of quantities with the units being x*y == z.");
    using ResultType = decltype(std::fma(x.value(), y, z.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<zUnit, ResultType>{std::fma(x.value(), y, z.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class zUnit, class ValueType>
constexpr auto fma(quantity<xUnit, ValueType> x, ValueType y, quantity_point<zUnit, ValueType> z) -> quantity_point<zUnit, decltype(std::fma(x.value(), y, z.value()))>
{
    static_assert(std::is_same_v<xUnit, zUnit> || is_compatible_v<xUnit, zUnit>, "You can only calculate the fma of quantities with the units being x*y == z.");
    using ResultType = decltype(std::fma(x.value(), y, z.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<zUnit, ResultType>{std::fma(x.value(), y, z.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class yUnit, class ValueType>
constexpr auto fma(quantity<xUnit, ValueType> x, quantity<yUnit, ValueType> y, ValueType z) -> quantity<make_one<xUnit>, decltype(std::fma(x.value(), y.value(), z))>
{
    static_assert(std::is_same_v<multiply_units_t<xUnit, yUnit>, make_one<xUnit>>, "You can only calculate the fma of quantities with the units being x*y == z.");
    using ResultType = decltype(std::fma(x.value(), y.value(), z));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<xUnit>, ResultType>{std::fma(x.value(), y.value(), z)};
}
//The fmax, and fmin functions return the max/min of two quantities with
//the same unit.
template <bool AllowImplicitConversion = false, class xUnit, class yUnit, class ValueType>
constexpr auto fmax(quantity<xUnit, ValueType> x, quantity<yUnit, ValueType> y) -> quantity<xUnit, decltype(std::fmax(x.value(), y.value()))>
{
    static_assert(std::is_same_v<xUnit, yUnit> || is_compatible_v<xUnit, yUnit>, "You can only calculate the fmax of quantities with the same unit.");
    using ResultType = decltype(std::fmax(x.value(), y.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<xUnit, ResultType>{std::fmax(x.value(), y.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class yUnit, class ValueType>
constexpr auto fmax(quantity_point<xUnit, ValueType> x, quantity_point<yUnit, ValueType> y) -> quantity_point<xUnit, decltype(std::fmax(x.value(), y.value()))>
{
    static_assert(std::is_same_v<xUnit, yUnit> || is_compatible_v<xUnit, yUnit>, "You can only calculate the fmax of quantities with the same unit.");
    using ResultType = decltype(std::fmax(x.value(), y.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<xUnit, ResultType>{std::fmax(x.value(), y.value())};
}
template <bool AllowImplicitConversion = false, class yUnit, class ValueType>
constexpr auto fmax(ValueType x, quantity<yUnit, ValueType> y) -> quantity<make_one<yUnit>, decltype(std::fmax(x, y.value()))>
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit>, "You can only calculate the fmax of quantities with the same unit.");
    using ResultType = decltype(std::fmax(x, y.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<yUnit>, ResultType>{std::fmax(x, y.value())};
}
template <bool AllowImplicitConversion = false, class yUnit, class ValueType>
constexpr auto fmax(ValueType x, quantity_point<yUnit, ValueType> y) -> quantity_point<make_one<yUnit>, decltype(std::fmax(x, y.value()))>
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit>, "You can only calculate the fmax of quantities with the same unit.");
    using ResultType = decltype(std::fmax(x, y.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<make_one<yUnit>, ResultType>{std::fmax(x, y.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class ValueType>
constexpr auto fmax(quantity<xUnit, ValueType> x, ValueType y) -> quantity<make_one<xUnit>, decltype(std::fmax(x.value(), y))>
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit>, "You can only calculate the fmax of quantities with the same unit.");
    using ResultType = decltype(std::fmax(x.value(), y));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<xUnit>, ResultType>{std::fmax(x.value(), y)};
}
template <bool AllowImplicitConversion = false, class xUnit, class ValueType>
constexpr auto fmax(quantity_point<xUnit, ValueType> x, ValueType y) -> quantity_point<make_one<xUnit>, decltype(std::fmax(x.value(), y))>
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit>, "You can only calculate the fmax of quantities with the same unit.");
    using ResultType = decltype(std::fmax(x.value(), y));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<make_one<xUnit>, ResultType>{std::fmax(x.value(), y)};
}
template <bool AllowImplicitConversion = false, class xUnit, class yUnit, class ValueType>
constexpr auto fmin(quantity<xUnit, ValueType> x, quantity<yUnit, ValueType> y) -> quantity<xUnit, decltype(std::fmin(x.value(), y.value()))>
{
    static_assert(std::is_same_v<xUnit, yUnit> || is_compatible_v<xUnit, yUnit>, "You can only calculate the fmin of quantities with the same unit.");
    using ResultType = decltype(std::fmin(x.value(), y.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<xUnit, ResultType>{std::fmin(x.value(), y.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class yUnit, class ValueType>
constexpr auto fmin(quantity_point<xUnit, ValueType> x, quantity_point<yUnit, ValueType> y) -> quantity_point<xUnit, decltype(std::fmin(x.value(), y.value()))>
{
    static_assert(std::is_same_v<xUnit, yUnit> || is_compatible_v<xUnit, yUnit>, "You can only calculate the fmin of quantities with the same unit.");
    using ResultType = decltype(std::fmin(x.value(), y.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<xUnit, ResultType>{std::fmin(x.value(), y.value())};
}
template <bool AllowImplicitConversion = false, class yUnit, class ValueType>
constexpr auto fmin(ValueType x, quantity<yUnit, ValueType> y) -> quantity<make_one<yUnit>, decltype(std::fmin(x, y.value()))>
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit>, "You can only calculate the fmin of quantities with the same unit.");
    using ResultType = decltype(std::fmin(x, y.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<yUnit>, ResultType>{std::fmin(x, y.value())};
}
template <bool AllowImplicitConversion = false, class yUnit, class ValueType>
constexpr auto fmin(ValueType x, quantity_point<yUnit, ValueType> y) -> quantity_point<make_one<yUnit>, decltype(std::fmin(x, y.value()))>
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit>, "You can only calculate the fmin of quantities with the same unit.");
    using ResultType = decltype(std::fmin(x, y.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<make_one<yUnit>, ResultType>{std::fmin(x, y.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class ValueType>
constexpr auto fmin(quantity<xUnit, ValueType> x, ValueType y) -> quantity<make_one<xUnit>, decltype(std::fmin(x.value(), y))>
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit>, "You can only calculate the fmin of quantities with the same unit.");
    using ResultType = decltype(std::fmin(x.value(), y));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<xUnit>, ResultType>{std::fmin(x.value(), y)};
}
template <bool AllowImplicitConversion = false, class xUnit, class ValueType>
constexpr auto fmin(quantity_point<xUnit, ValueType> x, ValueType y) -> quantity_point<make_one<xUnit>, decltype(std::fmin(x.value(), y))>
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit>, "You can only calculate the fmin of quantities with the same unit.");
    using ResultType = decltype(std::fmin(x.value(), y));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<make_one<xUnit>, ResultType>{std::fmin(x.value(), y)};
}
//The fdim function returns the positive difference (max(0,x-y)) of two quan-
//tities with the same unit.
template <bool AllowImplicitConversion = false, class xUnit, class yUnit, class ValueType>
constexpr auto fdim(quantity<xUnit, ValueType> x, quantity<yUnit, ValueType> y) -> quantity<xUnit, decltype(std::fdim(x.value(), y.value()))>
{
    static_assert(std::is_same_v<xUnit, yUnit> || is_compatible_v<xUnit, yUnit>, "You can only calculate the fdim of quantities with the same unit.");
    using ResultType = decltype(std::fdim(x.value(), y.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<xUnit, ResultType>{std::fdim(x.value(), y.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class yUnit, class ValueType>
constexpr auto fdim(quantity_point<xUnit, ValueType> x, quantity_point<yUnit, ValueType> y) -> quantity<xUnit, decltype(std::fdim(x.value(), y.value()))>
{
    static_assert(std::is_same_v<xUnit, yUnit>, "You can only calculate the fdim of quantities with the same unit.");
    using ResultType = decltype(std::fdim(x.value(), y.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<xUnit, ResultType>{std::fdim(x.value(), y.value())};
}
template <bool AllowImplicitConversion = false, class yUnit, class ValueType>
constexpr auto fdim(ValueType x, quantity<yUnit, ValueType> y) -> quantity<make_one<yUnit>, decltype(std::fdim(x, y.value()))>
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit>, "You can only calculate the fdim of quantities with the same unit.");
    using ResultType = decltype(std::fdim(x, y.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<yUnit>, ResultType>{std::fdim(x, y.value())};
}
template <bool AllowImplicitConversion = false, class yUnit, class ValueType>
constexpr auto fdim(ValueType x, quantity_point<yUnit, ValueType> y) -> quantity<make_one<yUnit>, decltype(std::fdim(x, y.value()))>
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit>, "You can only calculate the fdim of quantities with the same unit.");
    using ResultType = decltype(std::fdim(x, y.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<yUnit>, ResultType>{std::fdim(x, y.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class ValueType>
constexpr auto fdim(quantity<xUnit, ValueType> x, ValueType y) -> quantity<make_one<xUnit>, decltype(std::fdim(x.value(), y))>
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit>, "You can only calculate the fdim of quantities with the same unit.");
    using ResultType = decltype(std::fdim(x.value(), y));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<xUnit>, ResultType>{std::fdim(x.value(), y)};
}
template <bool AllowImplicitConversion = false, class xUnit, class ValueType>
constexpr auto fdim(quantity_point<xUnit, ValueType> x, ValueType y) -> quantity<make_one<xUnit>, decltype(std::fdim(x.value(), y))>
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit>, "You can only calculate the fdim of quantities with the same unit.");
    using ResultType = decltype(std::fdim(x.value(), y));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<xUnit>, ResultType>{std::fdim(x.value(), y)};
}
//The following functions are not implemented:
//nan
//nanf
//nanl
#pragma endregion
#pragma region exponential functions
//The exp, exp2, and expm1 functions calculate various versions of the exponen-
//tial function of dimensionless quantities. Prefixes are removed automatically.
//This allows correct calculation of percent, ...
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto exp(quantity<Unit, ValueType> val) -> quantity<make_one<Unit>, decltype(std::exp(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the exp of a dimensionless quantity.");
    using ResultType = decltype(std::exp(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<Unit>, ResultType>{std::exp(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto exp2(quantity<Unit, ValueType> val) -> quantity<make_one<Unit>, decltype(std::exp2(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the exp2 of a dimensionless quantity.");
    using ResultType = decltype(std::exp2(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<Unit>, ResultType>{std::exp2(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto expm1(quantity<Unit, ValueType> val) -> quantity<make_one<Unit>, decltype(std::expm1(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the expm1 of a dimensionless quantity.");
    using ResultType = decltype(std::expm1(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<Unit>, ResultType>{std::expm1(remove_prefix(val).value())};
}
//The log, log10, log2, and log1p functions calculate various versions of the logarithm
//function of dimensionless quantities. Prefixes are removed automatically. This allows
//correct calculation of percent, ...
//Furthermore, the log, log10, and log2 functions provide an overload that allows auto-
//matic scaling of the input. For example: log<metre>(1_kilometre) is the same as
//log(1_kilometre/1_metre)
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto log(quantity<Unit, ValueType> val) -> quantity<make_one<Unit>, decltype(std::log(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the log of a dimensionless quantity.");
    using ResultType = decltype(std::log(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<Unit>, ResultType>{std::log(remove_prefix(val).value())};
}
template <class ScalingUnit, bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto log(quantity<Unit, ValueType> val) -> quantity<make_one<Unit>, decltype(std::log(remove_prefix(unit_cast<ScalingUnit>(val)).value()))>
{
    static_assert(std::is_same_v<typename ScalingUnit::dimensions, typename Unit::dimensions>, "Your unit and your scaling unit have to have the same dimensions.");
    using ResultType = decltype(std::log(remove_prefix(unit_cast<ScalingUnit>(val)).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<Unit>, ResultType>{std::log(remove_prefix(unit_cast<ScalingUnit>(val)).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto log10(quantity<Unit, ValueType> val) -> quantity<make_one<Unit>, decltype(std::log10(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the log10 of a dimensionless quantity.");
    using ResultType = decltype(std::log10(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<Unit>, ResultType>{std::log10(remove_prefix(val).value())};
}
template <class ScalingUnit, bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto log10(quantity<Unit, ValueType> val) -> quantity<make_one<Unit>, decltype(std::log10(remove_prefix(unit_cast<ScalingUnit>(val)).value()))>
{
    static_assert(std::is_same_v<typename ScalingUnit::dimensions, typename Unit::dimensions>, "Your unit and your scaling unit have to have the same dimensions.");
    using ResultType = decltype(std::log10(remove_prefix(unit_cast<ScalingUnit>(val)).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<Unit>, ResultType>{std::log10(remove_prefix(unit_cast<ScalingUnit>(val)).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto log2(quantity<Unit, ValueType> val) -> quantity<make_one<Unit>, decltype(std::log2(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the log2 of a dimensionless quantity.");
    using ResultType = decltype(std::log2(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<Unit>, ResultType>{std::log2(remove_prefix(val).value())};
}
template <class ScalingUnit, bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto log2(quantity<Unit, ValueType> val) -> quantity<make_one<Unit>, decltype(std::log2(remove_prefix(unit_cast<ScalingUnit>(val)).value()))>
{
    static_assert(std::is_same_v<typename ScalingUnit::dimensions, typename Unit::dimensions>, "Your unit and your scaling unit have to have the same dimensions.");
    using ResultType = decltype(std::log2(remove_prefix(unit_cast<ScalingUnit>(val)).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<Unit>, ResultType>{std::log2(remove_prefix(unit_cast<ScalingUnit>(val)).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto log1p(quantity<Unit, ValueType> val) -> quantity<make_one<Unit>, decltype(std::log1p(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the log1p of a dimensionless quantity.");
    using ResultType = decltype(std::log1p(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<Unit>, ResultType>{std::log1p(remove_prefix(val).value())};
}
#pragma endregion
#pragma region power functions
//The pow<> function calculates the power of a given quantity, changing the unit.
//Three overloads are provided. You can either provide the power as a std::ratio:
//pow<std::ratio<1,2>> or using integers pow<1,2>. With the denominator being
//optional: pow<std::ratio<2>> = pow<2>.
template <class Exponent, bool AllowImplicitConversion = false, class baseUnit, class ValueType>
constexpr auto pow(quantity<baseUnit, ValueType> base) -> quantity<pow_unit_t<baseUnit, Exponent>, decltype(std::pow(base.value(), ValueType(Exponent::num) / ValueType(Exponent::den)))>
{
    static_assert(impl::is_ratio_v<Exponent>, "The Exponent needs to be a std::ratio.");
    using ResultType = decltype(std::pow(base.value(), ValueType(Exponent::num) / ValueType(Exponent::den)));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<pow_unit_t<baseUnit, Exponent>, ResultType>{std::pow(base.value(), ValueType(Exponent::num) / ValueType(Exponent::den))};
}
template <intmax_t num, intmax_t den = 1, bool AllowImplicitConversion = false, class baseUnit, class ValueType>
constexpr auto pow(quantity<baseUnit, ValueType> base)
{
    return pow<std::ratio<num, den>, AllowImplicitConversion>(base);
}
//The pow function calculates the power of a given dimensionless quantity, without
//changing the unit.
template <bool AllowImplicitConversion = false, class baseUnit, class exponentUnit, class ValueType>
constexpr auto pow(quantity<baseUnit, ValueType> y, quantity<exponentUnit, ValueType> x) -> quantity<make_one<baseUnit>, decltype(std::pow(remove_prefix(y).value(), remove_prefix(x).value()))>
{
    static_assert(std::is_same_v<typename baseUnit::dimensions, dim::dimensionless_t> && std::is_same_v<typename exponentUnit::dimensions, dim::dimensionless_t>, "You can only calculate the pow of dimensionless quantities.");
    using ResultType = decltype(std::pow(remove_prefix(y).value(), remove_prefix(x).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<baseUnit>, ResultType>{std::pow(remove_prefix(y).value(), remove_prefix(x).value())};
}
template <bool AllowImplicitConversion = false, class exponentUnit, class ValueType>
constexpr auto pow(ValueType y, quantity<exponentUnit, ValueType> x) -> quantity<make_one<exponentUnit>, decltype(std::pow(y, remove_prefix(x).value()))>
{
    static_assert(std::is_same_v<typename exponentUnit::dimensions, dim::dimensionless_t>, "You can only calculate the pow of dimensionless quantities.");
    using ResultType = decltype(std::pow(y, remove_prefix(x).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<exponentUnit>, ResultType>{std::pow(y, remove_prefix(x).value())};
}
template <bool AllowImplicitConversion = false, class baseUnit, class ValueType>
constexpr auto pow(quantity<baseUnit, ValueType> y, ValueType x) -> quantity<make_one<baseUnit>, decltype(std::pow(remove_prefix(y).value(), x))>
{
    static_assert(std::is_same_v<typename baseUnit::dimensions, dim::dimensionless_t>, "You can only calculate the pow of dimensionless quantities.");
    using ResultType = decltype(std::pow(remove_prefix(y).value(), x));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<baseUnit>, ResultType>{std::pow(remove_prefix(y).value(), x)};
}
//The sqrt, and cbrt functions calculate roots of given quantities, changing the
//unit. While the pow function could be used as well, the sqrt and cbrt functions
//directly access the std equivalents instead of using std::pow.
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto sqrt(quantity<Unit, ValueType> val) -> quantity<pow_unit_t<Unit, std::ratio<1, 2>>, decltype(std::sqrt(val.value()))>
{
    using ResultType = decltype(std::sqrt(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<pow_unit_t<Unit, std::ratio<1, 2>>, ResultType>{std::sqrt(val.value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto cbrt(quantity<Unit, ValueType> val) -> quantity<pow_unit_t<Unit, std::ratio<1, 3>>, decltype(std::cbrt(val.value()))>
{
    using ResultType = decltype(std::cbrt(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<pow_unit_t<Unit, std::ratio<1, 3>>, ResultType>{std::cbrt(val.value())};
}
//The hypot function returns the norm of two quantities x, and y with the same unit.
//(hypot(x,y) = sqrt(x^2+y^2))
//An overload for people using c++17 is provided.
template <bool AllowImplicitConversion = false, class xUnit, class yUnit, class ValueType>
constexpr auto hypot(quantity<xUnit, ValueType> x, quantity<yUnit, ValueType> y) -> quantity<xUnit, decltype(std::hypot(x.value(), y.value()))>
{
    static_assert(std::is_same_v<xUnit, yUnit> || is_compatible_v<xUnit, yUnit>, "You can only calculate the hypot of quantities with the same unit.");
    using ResultType = decltype(std::hypot(x.value(), y.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<xUnit, ResultType>{std::hypot(x.value(), y.value())};
}
template <bool AllowImplicitConversion = false, class yUnit, class ValueType>
constexpr auto hypot(ValueType x, quantity<yUnit, ValueType> y) -> quantity<make_one<yUnit>, decltype(std::hypot(x, y.value()))>
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit>, "You can only calculate the hypot of quantities with the same unit.");
    using ResultType = decltype(std::hypot(x, y.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<yUnit>, ResultType>{std::hypot(x, y.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class ValueType>
constexpr auto hypot(quantity<xUnit, ValueType> x, ValueType y) -> quantity<make_one<xUnit>, decltype(std::hypot(x.value(), y))>
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit>, "You can only calculate the hypot of quantities with the same unit.");
    using ResultType = decltype(std::hypot(x.value(), y));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<xUnit>, ResultType>{std::hypot(x.value(), y)};
}
#if __cplusplus >= 201703L
template <bool AllowImplicitConversion = false, class xUnit, class yUnit, class zUnit, class ValueType>
constexpr auto hypot(quantity<xUnit, ValueType> x, quantity<yUnit, ValueType> y, quantity<zUnit, ValueType> z) -> quantity<xUnit, decltype(std::hypot(x.value(), y.value(), z.value()))>
{
    static_assert((std::is_same_v<xUnit, yUnit> || is_compatible_v<xUnit, yUnit>)&&(std::is_same_v<yUnit, zUnit> || is_compatible_v<yUnit, zUnit>), "You can only calculate the hypot of quantities with the same unit.");
    using ResultType = decltype(std::hypot(x.value(), y.value(), z.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<xUnit, ResultType>{std::hypot(x.value(), y.value(), z.value())};
}
template <bool AllowImplicitConversion = false, class yUnit, class zUnit, class ValueType>
constexpr auto hypot(ValueType x, quantity<yUnit, ValueType> y, quantity<zUnit, ValueType> z) -> quantity<make_one<yUnit>, decltype(std::hypot(x, y.value(), z.value()))>
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit> && std::is_same_v<yUnit, zUnit>, "You can only calculate the hypot of quantities with the same unit.");
    using ResultType = decltype(std::hypot(x, y.value(), z.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<yUnit>, ResultType>{std::hypot(x, y.value(), z.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class zUnit, class ValueType>
constexpr auto hypot(quantity<xUnit, ValueType> x, ValueType y, quantity<zUnit, ValueType> z) -> quantity<make_one<xUnit>, decltype(std::hypot(x.value(), y, z.value()))>
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit> && std::is_same_v<xUnit, zUnit>, "You can only calculate the hypot of quantities with the same unit.");
    using ResultType = decltype(std::hypot(x.value(), y, z.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<xUnit>, ResultType>{std::hypot(x.value(), y, z.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class yUnit, class ValueType>
constexpr auto hypot(quantity<xUnit, ValueType> x, quantity<yUnit, ValueType> y, ValueType z) -> quantity<make_one<xUnit>, decltype(std::hypot(x.value(), y.value(), z))>
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit> && std::is_same_v<xUnit, yUnit>, "You can only calculate the hypot of quantities with the same unit.");
    using ResultType = decltype(std::hypot(x.value(), y.value(), z));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<xUnit>, ResultType>{std::hypot(x.value(), y.value(), z)};
}
template <bool AllowImplicitConversion = false, class zUnit, class ValueType>
constexpr auto hypot(ValueType x, ValueType y, quantity<zUnit, ValueType> z) -> quantity<make_one<zUnit>, decltype(std::hypot(x, y, z.value()))>
{
    static_assert(std::is_same_v<make_one<zUnit>, zUnit>, "You can only calculate the hypot of quantities with the same unit.");
    using ResultType = decltype(std::hypot(x, y, z.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<zUnit>, ResultType>{std::hypot(x, y, z.value())};
}
template <bool AllowImplicitConversion = false, class yUnit, class ValueType>
constexpr auto hypot(ValueType x, quantity<yUnit, ValueType> y, ValueType z) -> quantity<make_one<yUnit>, decltype(std::hypot(x, y.value(), z))>
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit>, "You can only calculate the hypot of quantities with the same unit.");
    using ResultType = decltype(std::hypot(x, y.value(), z));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<yUnit>, ResultType>{std::hypot(x, y.value(), z)};
}
template <bool AllowImplicitConversion = false, class xUnit, class ValueType>
constexpr auto hypot(quantity<xUnit, ValueType> x, ValueType y, ValueType z) -> quantity<make_one<xUnit>, decltype(std::hypot(x.value(), y, z))>
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit>, "You can only calculate the hypot of quantities with the same unit.");
    using ResultType = decltype(std::hypot(x.value(), y, z));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<xUnit>, ResultType>{std::hypot(x.value(), y, z)};
}
#endif
#pragma endregion
#pragma region trigonometric functions
//The sin, cos, and tan functions calculate various versions of the trigono-
//metric functions of dimensionless or plane_angle quantities. Prefixes are
//removed automatically. This allows correct calculation of percent, ...
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto sin(quantity<Unit, ValueType> val) -> quantity<make_one<Unit>, decltype(std::sin(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t> || std::is_same_v<typename Unit::dimensions, dim::plane_angle_t>, "You can only calculate the sin of a dimensionless quantity or an angle.");
    using ResultType = decltype(std::sin(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<Unit>, ResultType>{std::sin(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto cos(quantity<Unit, ValueType> val) -> quantity<make_one<Unit>, decltype(std::cos(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t> || std::is_same_v<typename Unit::dimensions, dim::plane_angle_t>, "You can only calculate the cos of a dimensionless quantity or an angle.");
    using ResultType = decltype(std::cos(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<Unit>, ResultType>{std::cos(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto tan(quantity<Unit, ValueType> val) -> quantity<make_one<Unit>, decltype(std::tan(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t> || std::is_same_v<typename Unit::dimensions, dim::plane_angle_t>, "You can only calculate the tan of a dimensionless quantity or an angle.");
    using ResultType = decltype(std::tan(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<Unit>, ResultType>{std::tan(remove_prefix(val).value())};
}
//The asin, acos, and atan functions calculate various versions of the inverse
//trigonometric functions of dimensionless quantities. The return type is always
//a plane_angle. Prefixes are removed automatically. This allows correct calcu-
//lation of percent, ...
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto asin(quantity<Unit, ValueType> val) -> quantity<make_plane_angle<Unit>, decltype(std::asin(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the asin of a dimensionless quantity.");
    using ResultType = decltype(std::asin(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_plane_angle<Unit>, ResultType>{std::asin(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto acos(quantity<Unit, ValueType> val) -> quantity<make_plane_angle<Unit>, decltype(std::acos(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the acos of a dimensionless quantity.");
    using ResultType = decltype(std::acos(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_plane_angle<Unit>, ResultType>{std::acos(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto atan(quantity<Unit, ValueType> val) -> quantity<make_plane_angle<Unit>, decltype(std::atan(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the atan of a dimensionless quantity.");
    using ResultType = decltype(std::atan(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_plane_angle<Unit>, ResultType>{std::atan(remove_prefix(val).value())};
}
//The atan2 function calculates the atan of y/x given two quantities x and y with
//the same dimension. The return type is always a plane_angle. Prefixes of y and y
//are removed automatically. This allows correct calcution of
//atan2(1_kilometre,1_metre), ...
template <bool AllowImplicitConversion = false, class yUnit, class xUnit, class ValueType>
constexpr auto atan2(quantity<yUnit, ValueType> y, quantity<xUnit, ValueType> x) -> quantity<make_plane_angle<yUnit>, decltype(std::atan2(remove_prefix(y).value(), remove_prefix(x).value()))>
{
    static_assert(std::is_same_v<typename yUnit::dimensions, typename xUnit::dimensions>, "You can only calculate the atan2 of quantities with the same dimensions.");
    using ResultType = decltype(std::atan2(remove_prefix(y).value(), remove_prefix(x).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_plane_angle<yUnit>, ResultType>{std::atan2(remove_prefix(y).value(), remove_prefix(x).value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class ValueType>
constexpr auto atan2(ValueType y, quantity<xUnit, ValueType> x) -> quantity<make_plane_angle<xUnit>, decltype(std::atan2(y, remove_prefix(x).value()))>
{
    static_assert(std::is_same_v<typename xUnit::dimensions, dim::dimensionless_t>, "You can only calculate the atan2 of quantities with the same dimensions.");
    using ResultType = decltype(std::atan2(y, remove_prefix(x).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_plane_angle<xUnit>, ResultType>{std::atan2(y, remove_prefix(x).value())};
}
template <bool AllowImplicitConversion = false, class yUnit, class ValueType>
constexpr auto atan2(quantity<yUnit, ValueType> y, ValueType x) -> quantity<make_plane_angle<yUnit>, decltype(std::atan2(remove_prefix(y).value(), x))>
{
    static_assert(std::is_same_v<typename yUnit::dimensions, dim::dimensionless_t>, "You can only calculate the atan2 of quantities with the same dimensions.");
    using ResultType = decltype(std::atan2(remove_prefix(y).value(), x));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_plane_angle<yUnit>, ResultType>{std::atan2(remove_prefix(y).value(), x)};
}
#pragma endregion
#pragma region hyperbolic functions
//The sinh, cosh, tanh, asinh, acosh, and atanh functions calculate various versions
//of the hyperbolic functions and their inverses of dimensionless quantities. Pre-
//fixes are removed automatically. This allows correct calculation of percent, ...
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto sinh(quantity<Unit, ValueType> val) -> quantity<make_one<Unit>, decltype(std::sinh(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the sinh of a dimensionless quantity.");
    using ResultType = decltype(std::sinh(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<Unit>, ResultType>{std::sinh(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto cosh(quantity<Unit, ValueType> val) -> quantity<make_one<Unit>, decltype(std::cosh(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the cosh of a dimensionless quantity.");
    using ResultType = decltype(std::cosh(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<Unit>, ResultType>{std::cosh(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto tanh(quantity<Unit, ValueType> val) -> quantity<make_one<Unit>, decltype(std::tanh(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the tanh of a dimensionless quantity.");
    using ResultType = decltype(std::tanh(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<Unit>, ResultType>{std::tanh(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto asinh(quantity<Unit, ValueType> val) -> quantity<make_one<Unit>, decltype(std::asinh(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the asinh of a dimensionless quantity.");
    using ResultType = decltype(std::asinh(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<Unit>, ResultType>{std::asinh(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto acosh(quantity<Unit, ValueType> val) -> quantity<make_one<Unit>, decltype(std::acosh(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the acosh of a dimensionless quantity.");
    using ResultType = decltype(std::acosh(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<Unit>, ResultType>{std::acosh(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto atanh(quantity<Unit, ValueType> val) -> quantity<make_one<Unit>, decltype(std::atanh(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the atanh of a dimensionless quantity.");
    using ResultType = decltype(std::atanh(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<Unit>, ResultType>{std::atanh(remove_prefix(val).value())};
}
#pragma endregion
#pragma region error and gamma functions
//The erf, and erfc functions calculate various versions of the error function of
//dimensionless quantities. Prefixes are removed automatically. This allows correct
//calculation of percent, ...
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto erf(quantity<Unit, ValueType> val) -> quantity<make_one<Unit>, decltype(std::erf(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the erf of a dimensionless quantity.");
    using ResultType = decltype(std::erf(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<Unit>, ResultType>{std::erf(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto erfc(quantity<Unit, ValueType> val) -> quantity<make_one<Unit>, decltype(std::erfc(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the erfc of a dimensionless quantity.");
    using ResultType = decltype(std::erfc(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<Unit>, ResultType>{std::erfc(remove_prefix(val).value())};
}
//The tgamma, and lgamma functions calculate various versions of the gamma function
//of dimensionless quantities. Prefixes are removed automatically. This allows correct
//calculation of percent, ...
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto tgamma(quantity<Unit, ValueType> val) -> quantity<make_one<Unit>, decltype(std::tgamma(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the tgamma of a dimensionless quantity.");
    using ResultType = decltype(std::tgamma(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<Unit>, ResultType>{std::tgamma(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto lgamma(quantity<Unit, ValueType> val) -> quantity<make_one<Unit>, decltype(std::lgamma(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the lgamma of a dimensionless quantity.");
    using ResultType = decltype(std::lgamma(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<Unit>, ResultType>{std::lgamma(remove_prefix(val).value())};
}
#pragma endregion
#pragma region nearest integer floating point operations
//The ceil, floor, trunc, and nearbyint functions provide nearest integer
//floating point operations for a quantity, ignoring the unit.
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto ceil(quantity<Unit, ValueType> val) -> quantity<Unit, decltype(std::ceil(val.value()))>
{
    using ResultType = decltype(std::ceil(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<Unit, ResultType>{std::ceil(val.value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto ceil(quantity_point<Unit, ValueType> val) -> quantity_point<Unit, decltype(std::ceil(val.value()))>
{
    using ResultType = decltype(std::ceil(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<Unit, ResultType>{std::ceil(val.value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto floor(quantity<Unit, ValueType> val) -> quantity<Unit, decltype(std::floor(val.value()))>
{
    using ResultType = decltype(std::floor(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<Unit, ResultType>{std::floor(val.value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto floor(quantity_point<Unit, ValueType> val) -> quantity_point<Unit, decltype(std::floor(val.value()))>
{
    using ResultType = decltype(std::floor(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<Unit, ResultType>{std::floor(val.value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto trunc(quantity<Unit, ValueType> val) -> quantity<Unit, decltype(std::trunc(val.value()))>
{
    using ResultType = decltype(std::trunc(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<Unit, ResultType>{std::trunc(val.value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto trunc(quantity_point<Unit, ValueType> val) -> quantity_point<Unit, decltype(std::trunc(val.value()))>
{
    using ResultType = decltype(std::trunc(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<Unit, ResultType>{std::trunc(val.value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto nearbyint(quantity<Unit, ValueType> val) -> quantity<Unit, decltype(std::nearbyint(val.value()))>
{
    using ResultType = decltype(std::nearbyint(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<Unit, ResultType>{std::nearbyint(val.value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto nearbyint(quantity_point<Unit, ValueType> val) -> quantity_point<Unit, decltype(std::nearbyint(val.value()))>
{
    using ResultType = decltype(std::nearbyint(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<Unit, ResultType>{std::nearbyint(val.value())};
}
//The round, lround, llround, rint, lrint, and llrint functions provide nearest integer
//floating point operations for a quantity, ignoring the unit.
//round, and rint will round the value and try to preserve the value_type of the quantity.
//lround, llround, lrint, and llrint will change the value_type to long/long long.
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto round(quantity<Unit, ValueType> val) -> quantity<Unit, decltype(std::round(val.value()))>
{
    using ResultType = decltype(std::round(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<Unit, ResultType>{std::round(val.value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto round(quantity_point<Unit, ValueType> val) -> quantity_point<Unit, decltype(std::round(val.value()))>
{
    using ResultType = decltype(std::round(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<Unit, ResultType>{std::round(val.value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto lround(quantity<Unit, ValueType> val) -> quantity<Unit, decltype(std::lround(val.value()))>
{
    using ResultType = decltype(std::lround(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<Unit, ResultType>{std::lround(val.value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto lround(quantity_point<Unit, ValueType> val) -> quantity_point<Unit, decltype(std::lround(val.value()))>
{
    using ResultType = decltype(std::lround(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<Unit, ResultType>{std::lround(val.value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto llround(quantity<Unit, ValueType> val) -> quantity<Unit, decltype(std::llround(val.value()))>
{
    using ResultType = decltype(std::llround(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<Unit, ResultType>{std::llround(val.value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto llround(quantity_point<Unit, ValueType> val) -> quantity_point<Unit, decltype(std::llround(val.value()))>
{
    using ResultType = decltype(std::llround(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<Unit, ResultType>{std::llround(val.value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto rint(quantity<Unit, ValueType> val) -> quantity<Unit, decltype(std::rint(val.value()))>
{
    using ResultType = decltype(std::rint(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<Unit, ResultType>{std::rint(val.value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto rint(quantity_point<Unit, ValueType> val) -> quantity_point<Unit, decltype(std::rint(val.value()))>
{
    using ResultType = decltype(std::rint(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<Unit, ResultType>{std::rint(val.value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto lrint(quantity<Unit, ValueType> val) -> quantity<Unit, decltype(std::lrint(val.value()))>
{
    using ResultType = decltype(std::lrint(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<Unit, ResultType>{std::lrint(val.value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto lrint(quantity_point<Unit, ValueType> val) -> quantity_point<Unit, decltype(std::lrint(val.value()))>
{
    using ResultType = decltype(std::lrint(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<Unit, ResultType>{std::lrint(val.value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto llrint(quantity<Unit, ValueType> val) -> quantity<Unit, decltype(std::llrint(val.value()))>
{
    using ResultType = decltype(std::llrint(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<Unit, ResultType>{std::llrint(val.value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto llrint(quantity_point<Unit, ValueType> val) -> quantity_point<Unit, decltype(std::llrint(val.value()))>
{
    using ResultType = decltype(std::llrint(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<Unit, ResultType>{std::llrint(val.value())};
}
#pragma endregion
#pragma region floating point manipulation functions
//The frexp, ldexp, modf, scalbn, scalbln, ilogb, and logb functions let
//you manipulate the value of a quantity, ignoring the unit.
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto frexp(quantity<Unit, ValueType> arg, int *exp) -> quantity<Unit, decltype(std::frexp(arg.value(), exp))>
{
    using ResultType = decltype(std::frexp(arg.value(), exp));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<Unit, ResultType>{std::frexp(arg.value(), exp)};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto frexp(quantity_point<Unit, ValueType> arg, int *exp) -> quantity_point<Unit, decltype(std::frexp(arg.value(), exp))>
{
    using ResultType = decltype(std::frexp(arg.value(), exp));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<Unit, ResultType>{std::frexp(arg.value(), exp)};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto ldexp(quantity<Unit, ValueType> x, int exp) -> quantity<Unit, decltype(std::ldexp(x.value(), exp))>
{
    using ResultType = decltype(std::ldexp(x.value(), exp));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<Unit, ResultType>{std::ldexp(x.value(), exp)};
}
template <class Unit, class ValueType>
constexpr auto modf(quantity<Unit, ValueType> x, ValueType *iptr) -> quantity<Unit, decltype(std::modf(x.value(), iptr))>
{
    using ResultType = decltype(std::modf(x.value(), iptr));
    return quantity<Unit, ResultType>{std::modf(x.value(), iptr)};
}
template <class Unit, class ValueType>
constexpr auto modf(quantity_point<Unit, ValueType> x, ValueType *iptr) -> quantity_point<Unit, decltype(std::modf(x.value(), iptr))>
{
    using ResultType = decltype(std::modf(x.value(), iptr));
    return quantity_point<Unit, ResultType>{std::modf(x.value(), iptr)};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto scalbn(quantity<Unit, ValueType> x, int exp) -> quantity<Unit, decltype(std::scalbn(x.value(), exp))>
{
    using ResultType = decltype(std::scalbn(x.value(), exp));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<Unit, ResultType>{std::scalbn(x.value(), exp)};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto scalbln(quantity<Unit, ValueType> x, long exp) -> quantity<Unit, decltype(std::scalbln(x.value(), exp))>
{
    using ResultType = decltype(std::scalbln(x.value(), exp));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<Unit, ResultType>{std::scalbln(x.value(), exp)};
}
template <class Unit, class ValueType>
constexpr auto ilogb(quantity<Unit, ValueType> val)
{
    return std::ilogb(val.value());
}
template <class Unit, class ValueType>
constexpr auto ilogb(quantity_point<Unit, ValueType> val)
{
    return std::ilogb(val.value());
}
template <class Unit, class ValueType>
constexpr auto logb(quantity<Unit, ValueType> val)
{
    return std::logb(val.value());
}
template <class Unit, class ValueType>
constexpr auto logb(quantity_point<Unit, ValueType> val)
{
    return std::logb(val.value());
}
//The nextafter, nexttoward, and copysign functions let you manipulate the value of
//two quantities with the same unit.
template <bool AllowImplicitConversion = false, class fromUnit, class toUnit, class ValueType>
constexpr auto nextafter(quantity<fromUnit, ValueType> from, quantity<toUnit, ValueType> to) -> quantity<fromUnit, decltype(std::nextafter(from.value(), to.value()))>
{
    static_assert(std::is_same_v<fromUnit, toUnit> || is_compatible_v<fromUnit, toUnit>, "You can only calculate the nextafter of quantities with the same unit.");
    using ResultType = decltype(std::nextafter(from.value(), to.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<fromUnit, ResultType>{std::nextafter(from.value(), to.value())};
}
template <bool AllowImplicitConversion = false, class fromUnit, class toUnit, class ValueType>
constexpr auto nextafter(quantity_point<fromUnit, ValueType> from, quantity_point<toUnit, ValueType> to) -> quantity_point<fromUnit, decltype(std::nextafter(from.value(), to.value()))>
{
    static_assert(std::is_same_v<fromUnit, toUnit>, "You can only calculate the nextafter of quantities with the same unit.");
    using ResultType = decltype(std::nextafter(from.value(), to.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<fromUnit, ResultType>{std::nextafter(from.value(), to.value())};
}
template <bool AllowImplicitConversion = false, class toUnit, class ValueType>
constexpr auto nextafter(ValueType from, quantity<toUnit, ValueType> to) -> quantity<make_one<toUnit>, decltype(std::nextafter(from, to.value()))>
{
    static_assert(std::is_same_v<make_one<toUnit>, toUnit>, "You can only calculate the nextafter of quantities with the same unit.");
    using ResultType = decltype(std::nextafter(from, to.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<toUnit>, ResultType>{std::nextafter(from, to.value())};
}
template <bool AllowImplicitConversion = false, class toUnit, class ValueType>
constexpr auto nextafter(ValueType from, quantity_point<toUnit, ValueType> to) -> quantity_point<make_one<toUnit>, decltype(std::nextafter(from, to.value()))>
{
    static_assert(std::is_same_v<make_one<toUnit>, toUnit>, "You can only calculate the nextafter of quantities with the same unit.");
    using ResultType = decltype(std::nextafter(from, to.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<make_one<toUnit>, ResultType>{std::nextafter(from, to.value())};
}
template <bool AllowImplicitConversion = false, class fromUnit, class ValueType>
constexpr auto nextafter(quantity<fromUnit, ValueType> from, ValueType to) -> quantity<make_one<fromUnit>, decltype(std::nextafter(from.value(), to))>
{
    static_assert(std::is_same_v<make_one<fromUnit>, fromUnit>, "You can only calculate the nextafter of quantities with the same unit.");
    using ResultType = decltype(std::nextafter(from.value(), to));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<fromUnit>, ResultType>{std::nextafter(from.value(), to)};
}
template <bool AllowImplicitConversion = false, class fromUnit, class ValueType>
constexpr auto nextafter(quantity_point<fromUnit, ValueType> from, ValueType to) -> quantity_point<make_one<fromUnit>, decltype(std::nextafter(from.value(), to))>
{
    static_assert(std::is_same_v<make_one<fromUnit>, fromUnit>, "You can only calculate the nextafter of quantities with the same unit.");
    using ResultType = decltype(std::nextafter(from.value(), to));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<make_one<fromUnit>, ResultType>{std::nextafter(from.value(), to)};
}
template <bool AllowImplicitConversion = false, class fromUnit, class toUnit, class ValueType>
constexpr auto nexttoward(quantity<fromUnit, ValueType> from, quantity<toUnit, ValueType> to) -> quantity<fromUnit, decltype(std::nexttoward(from.value(), to.value()))>
{
    static_assert(std::is_same_v<fromUnit, toUnit> || is_compatible_v<fromUnit, toUnit>, "You can only calculate the nexttoward of quantities with the same unit.");
    using ResultType = decltype(std::nexttoward(from.value(), to.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<fromUnit, ResultType>{std::nexttoward(from.value(), to.value())};
}
template <bool AllowImplicitConversion = false, class fromUnit, class toUnit, class ValueType>
constexpr auto nexttoward(quantity_point<fromUnit, ValueType> from, quantity_point<toUnit, ValueType> to) -> quantity_point<fromUnit, decltype(std::nexttoward(from.value(), to.value()))>
{
    static_assert(std::is_same_v<fromUnit, toUnit>, "You can only calculate the nexttoward of quantities with the same unit.");
    using ResultType = decltype(std::nexttoward(from.value(), to.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<fromUnit, ResultType>{std::nexttoward(from.value(), to.value())};
}
template <bool AllowImplicitConversion = false, class toUnit, class ValueType>
constexpr auto nexttoward(ValueType from, quantity<toUnit, ValueType> to) -> quantity<make_one<toUnit>, decltype(std::nexttoward(from, to.value()))>
{
    static_assert(std::is_same_v<make_one<toUnit>, toUnit>, "You can only calculate the nexttoward of quantities with the same unit.");
    using ResultType = decltype(std::nexttoward(from, to.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<toUnit>, ResultType>{std::nexttoward(from, to.value())};
}
template <bool AllowImplicitConversion = false, class toUnit, class ValueType>
constexpr auto nexttoward(ValueType from, quantity_point<toUnit, ValueType> to) -> quantity_point<make_one<toUnit>, decltype(std::nexttoward(from, to.value()))>
{
    static_assert(std::is_same_v<make_one<toUnit>, toUnit>, "You can only calculate the nexttoward of quantities with the same unit.");
    using ResultType = decltype(std::nexttoward(from, to.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<make_one<toUnit>, ResultType>{std::nexttoward(from, to.value())};
}
template <bool AllowImplicitConversion = false, class fromUnit, class ValueType>
constexpr auto nexttoward(quantity<fromUnit, ValueType> from, ValueType to) -> quantity<make_one<fromUnit>, decltype(std::nexttoward(from.value(), to))>
{
    static_assert(std::is_same_v<make_one<fromUnit>, fromUnit>, "You can only calculate the nexttoward of quantities with the same unit.");
    using ResultType = decltype(std::nexttoward(from.value(), to));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<fromUnit>, ResultType>{std::nexttoward(from.value(), to)};
}
template <bool AllowImplicitConversion = false, class fromUnit, class ValueType>
constexpr auto nexttoward(quantity_point<fromUnit, ValueType> from, ValueType to) -> quantity_point<make_one<fromUnit>, decltype(std::nexttoward(from.value(), to))>
{
    static_assert(std::is_same_v<make_one<fromUnit>, fromUnit>, "You can only calculate the nexttoward of quantities with the same unit.");
    using ResultType = decltype(std::nexttoward(from.value(), to));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<make_one<fromUnit>, ResultType>{std::nexttoward(from.value(), to)};
}
template <bool AllowImplicitConversion = false, class fromUnit, class toUnit, class ValueType>
constexpr auto copysign(quantity<fromUnit, ValueType> from, quantity<toUnit, ValueType> to) -> quantity<fromUnit, decltype(std::copysign(from.value(), to.value()))>
{
    static_assert(std::is_same_v<fromUnit, toUnit> || is_compatible_v<fromUnit, toUnit>, "You can only calculate the copysign of quantities with the same unit.");
    using ResultType = decltype(std::copysign(from.value(), to.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<fromUnit, ResultType>{std::copysign(from.value(), to.value())};
}
template <bool AllowImplicitConversion = false, class fromUnit, class toUnit, class ValueType>
constexpr auto copysign(quantity_point<fromUnit, ValueType> from, quantity_point<toUnit, ValueType> to) -> quantity_point<fromUnit, decltype(std::copysign(from.value(), to.value()))>
{
    static_assert(std::is_same_v<fromUnit, toUnit>, "You can only calculate the copysign of quantities with the same unit.");
    using ResultType = decltype(std::copysign(from.value(), to.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<fromUnit, ResultType>{std::copysign(from.value(), to.value())};
}
template <bool AllowImplicitConversion = false, class toUnit, class ValueType>
constexpr auto copysign(ValueType from, quantity<toUnit, ValueType> to) -> quantity<make_one<toUnit>, decltype(std::copysign(from, to.value()))>
{
    static_assert(std::is_same_v<make_one<toUnit>, toUnit>, "You can only calculate the copysign of quantities with the same unit.");
    using ResultType = decltype(std::copysign(from, to.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<toUnit>, ResultType>{std::copysign(from, to.value())};
}
template <bool AllowImplicitConversion = false, class toUnit, class ValueType>
constexpr auto copysign(ValueType from, quantity_point<toUnit, ValueType> to) -> quantity_point<make_one<toUnit>, decltype(std::copysign(from, to.value()))>
{
    static_assert(std::is_same_v<make_one<toUnit>, toUnit>, "You can only calculate the copysign of quantities with the same unit.");
    using ResultType = decltype(std::copysign(from, to.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<make_one<toUnit>, ResultType>{std::copysign(from, to.value())};
}
template <bool AllowImplicitConversion = false, class fromUnit, class ValueType>
constexpr auto copysign(quantity<fromUnit, ValueType> from, ValueType to) -> quantity<make_one<fromUnit>, decltype(std::copysign(from.value(), to))>
{
    static_assert(std::is_same_v<make_one<fromUnit>, fromUnit>, "You can only calculate the copysign of quantities with the same unit.");
    using ResultType = decltype(std::copysign(from.value(), to));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one<fromUnit>, ResultType>{std::copysign(from.value(), to)};
}
template <bool AllowImplicitConversion = false, class fromUnit, class ValueType>
constexpr auto copysign(quantity_point<fromUnit, ValueType> from, ValueType to) -> quantity_point<make_one<fromUnit>, decltype(std::copysign(from.value(), to))>
{
    static_assert(std::is_same_v<make_one<fromUnit>, fromUnit>, "You can only calculate the copysign of quantities with the same unit.");
    using ResultType = decltype(std::copysign(from.value(), to));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity_point<make_one<fromUnit>, ResultType>{std::copysign(from.value(), to)};
}
#pragma endregion
#pragma region classification and comparison
//The fpclassify, isfinite, isinf, isnan, isnormal, and signbit functions
//provide informations on the stored value of a quantity, ignoring the unit.
template <class Unit, class ValueType>
constexpr auto fpclassify(quantity<Unit, ValueType> val) -> decltype(std::fpclassify(val.value()))
{
    return std::fpclassify(val.value());
}
template <class Unit, class ValueType>
constexpr auto fpclassify(quantity_point<Unit, ValueType> val) -> decltype(std::fpclassify(val.value()))
{
    return std::fpclassify(val.value());
}
template <class Unit, class ValueType>
constexpr auto isfinite(quantity<Unit, ValueType> val) -> decltype(std::isfinite(val.value()))
{
    return std::isfinite(val.value());
}
template <class Unit, class ValueType>
constexpr auto isfinite(quantity_point<Unit, ValueType> val) -> decltype(std::isfinite(val.value()))
{
    return std::isfinite(val.value());
}
template <class Unit, class ValueType>
constexpr auto isinf(quantity<Unit, ValueType> val) -> decltype(std::isinf(val.value()))
{
    return std::isinf(val.value());
}
template <class Unit, class ValueType>
constexpr auto isinf(quantity_point<Unit, ValueType> val) -> decltype(std::isinf(val.value()))
{
    return std::isinf(val.value());
}
template <class Unit, class ValueType>
constexpr auto isnan(quantity<Unit, ValueType> val) -> decltype(std::isnan(val.value()))
{
    return std::isnan(val.value());
}
template <class Unit, class ValueType>
constexpr auto isnan(quantity_point<Unit, ValueType> val) -> decltype(std::isnan(val.value()))
{
    return std::isnan(val.value());
}
template <class Unit, class ValueType>
constexpr auto isnormal(quantity<Unit, ValueType> val) -> decltype(std::isnormal(val.value()))
{
    return std::isnormal(val.value());
}
template <class Unit, class ValueType>
constexpr auto isnormal(quantity_point<Unit, ValueType> val) -> decltype(std::isnormal(val.value()))
{
    return std::isnormal(val.value());
}
template <class Unit, class ValueType>
constexpr auto signbit(quantity<Unit, ValueType> val) -> decltype(std::signbit(val.value()))
{
    return std::signbit(val.value());
}
template <class Unit, class ValueType>
constexpr auto signbit(quantity_point<Unit, ValueType> val) -> decltype(std::signbit(val.value()))
{
    return std::signbit(val.value());
}
//The isgreater, isgreaterequal, isless, islessequal, islessgreater, and
//isunordered functions lets you compare two quantities with the same unit.
template <class xUnit, class yUnit, class ValueType>
constexpr auto isgreater(quantity<xUnit, ValueType> x, quantity<yUnit, ValueType> y) -> decltype(std::isgreater(x.value(), y.value()))
{
    static_assert(std::is_same_v<xUnit, yUnit> || is_compatible_v<xUnit, yUnit>, "You can only calculate the isgreater of quantities with the same unit.");
    return std::isgreater(x.value(), y.value());
}
template <class xUnit, class yUnit, class ValueType>
constexpr auto isgreater(quantity_point<xUnit, ValueType> x, quantity_point<yUnit, ValueType> y) -> decltype(std::isgreater(x.value(), y.value()))
{
    static_assert(std::is_same_v<xUnit, yUnit>, "You can only calculate the isgreater of quantities with the same unit.");
    return std::isgreater(x.value(), y.value());
}
template <class yUnit, class ValueType>
constexpr auto isgreater(ValueType x, quantity<yUnit, ValueType> y) -> decltype(std::isgreater(x, y.value()))
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit>, "You can only calculate the isgreater of quantities with the same unit.");
    return std::isgreater(x, y.value());
}
template <class yUnit, class ValueType>
constexpr auto isgreater(ValueType x, quantity_point<yUnit, ValueType> y) -> decltype(std::isgreater(x, y.value()))
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit>, "You can only calculate the isgreater of quantities with the same unit.");
    return std::isgreater(x, y.value());
}
template <class xUnit, class ValueType>
constexpr auto isgreater(quantity<xUnit, ValueType> x, ValueType y) -> decltype(std::isgreater(x.value(), y))
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit>, "You can only calculate the isgreater of quantities with the same unit.");
    return std::isgreater(x.value(), y);
}
template <class xUnit, class ValueType>
constexpr auto isgreater(quantity_point<xUnit, ValueType> x, ValueType y) -> decltype(std::isgreater(x.value(), y))
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit>, "You can only calculate the isgreater of quantities with the same unit.");
    return std::isgreater(x.value(), y);
}
template <class xUnit, class yUnit, class ValueType>
constexpr auto isgreaterequal(quantity<xUnit, ValueType> x, quantity<yUnit, ValueType> y) -> decltype(std::isgreaterequal(x.value(), y.value()))
{
    static_assert(std::is_same_v<xUnit, yUnit> || is_compatible_v<xUnit, yUnit>, "You can only calculate the isgreaterequal of quantities with the same unit.");
    return std::isgreaterequal(x.value(), y.value());
}
template <class xUnit, class yUnit, class ValueType>
constexpr auto isgreaterequal(quantity_point<xUnit, ValueType> x, quantity_point<yUnit, ValueType> y) -> decltype(std::isgreaterequal(x.value(), y.value()))
{
    static_assert(std::is_same_v<xUnit, yUnit>, "You can only calculate the isgreaterequal of quantities with the same unit.");
    return std::isgreaterequal(x.value(), y.value());
}
template <class yUnit, class ValueType>
constexpr auto isgreaterequal(ValueType x, quantity<yUnit, ValueType> y) -> decltype(std::isgreaterequal(x, y.value()))
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit>, "You can only calculate the isgreaterequal of quantities with the same unit.");
    return std::isgreaterequal(x, y.value());
}
template <class yUnit, class ValueType>
constexpr auto isgreaterequal(ValueType x, quantity_point<yUnit, ValueType> y) -> decltype(std::isgreaterequal(x, y.value()))
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit>, "You can only calculate the isgreaterequal of quantities with the same unit.");
    return std::isgreaterequal(x, y.value());
}
template <class xUnit, class ValueType>
constexpr auto isgreaterequal(quantity<xUnit, ValueType> x, ValueType y) -> decltype(std::isgreaterequal(x.value(), y))
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit>, "You can only calculate the isgreaterequal of quantities with the same unit.");
    return std::isgreaterequal(x.value(), y);
}
template <class xUnit, class ValueType>
constexpr auto isgreaterequal(quantity_point<xUnit, ValueType> x, ValueType y) -> decltype(std::isgreaterequal(x.value(), y))
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit>, "You can only calculate the isgreaterequal of quantities with the same unit.");
    return std::isgreaterequal(x.value(), y);
}
template <class xUnit, class yUnit, class ValueType>
constexpr auto isless(quantity<xUnit, ValueType> x, quantity<yUnit, ValueType> y) -> decltype(std::isless(x.value(), y.value()))
{
    static_assert(std::is_same_v<xUnit, yUnit> || is_compatible_v<xUnit, yUnit>, "You can only calculate the isless of quantities with the same unit.");
    return std::isless(x.value(), y.value());
}
template <class xUnit, class yUnit, class ValueType>
constexpr auto isless(quantity_point<xUnit, ValueType> x, quantity_point<yUnit, ValueType> y) -> decltype(std::isless(x.value(), y.value()))
{
    static_assert(std::is_same_v<xUnit, yUnit>, "You can only calculate the isless of quantities with the same unit.");
    return std::isless(x.value(), y.value());
}
template <class yUnit, class ValueType>
constexpr auto isless(ValueType x, quantity<yUnit, ValueType> y) -> decltype(std::isless(x, y.value()))
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit>, "You can only calculate the isless of quantities with the same unit.");
    return std::isless(x, y.value());
}
template <class yUnit, class ValueType>
constexpr auto isless(ValueType x, quantity_point<yUnit, ValueType> y) -> decltype(std::isless(x, y.value()))
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit>, "You can only calculate the isless of quantities with the same unit.");
    return std::isless(x, y.value());
}
template <class xUnit, class ValueType>
constexpr auto isless(quantity<xUnit, ValueType> x, ValueType y) -> decltype(std::isless(x.value(), y))
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit>, "You can only calculate the isless of quantities with the same unit.");
    return std::isless(x.value(), y);
}
template <class xUnit, class ValueType>
constexpr auto isless(quantity_point<xUnit, ValueType> x, ValueType y) -> decltype(std::isless(x.value(), y))
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit>, "You can only calculate the isless of quantities with the same unit.");
    return std::isless(x.value(), y);
}
template <class xUnit, class yUnit, class ValueType>
constexpr auto islessequal(quantity<xUnit, ValueType> x, quantity<yUnit, ValueType> y) -> decltype(std::islessequal(x.value(), y.value()))
{
    static_assert(std::is_same_v<xUnit, yUnit> || is_compatible_v<xUnit, yUnit>, "You can only calculate the islessequal of quantities with the same unit.");
    return std::islessequal(x.value(), y.value());
}
template <class xUnit, class yUnit, class ValueType>
constexpr auto islessequal(quantity_point<xUnit, ValueType> x, quantity_point<yUnit, ValueType> y) -> decltype(std::islessequal(x.value(), y.value()))
{
    static_assert(std::is_same_v<xUnit, yUnit>, "You can only calculate the islessequal of quantities with the same unit.");
    return std::islessequal(x.value(), y.value());
}
template <class yUnit, class ValueType>
constexpr auto islessequal(ValueType x, quantity<yUnit, ValueType> y) -> decltype(std::islessequal(x, y.value()))
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit>, "You can only calculate the islessequal of quantities with the same unit.");
    return std::islessequal(x, y.value());
}
template <class yUnit, class ValueType>
constexpr auto islessequal(ValueType x, quantity_point<yUnit, ValueType> y) -> decltype(std::islessequal(x, y.value()))
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit>, "You can only calculate the islessequal of quantities with the same unit.");
    return std::islessequal(x, y.value());
}
template <class xUnit, class ValueType>
constexpr auto islessequal(quantity<xUnit, ValueType> x, ValueType y) -> decltype(std::islessequal(x.value(), y))
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit>, "You can only calculate the islessequal of quantities with the same unit.");
    return std::islessequal(x.value(), y);
}
template <class xUnit, class ValueType>
constexpr auto islessequal(quantity_point<xUnit, ValueType> x, ValueType y) -> decltype(std::islessequal(x.value(), y))
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit>, "You can only calculate the islessequal of quantities with the same unit.");
    return std::islessequal(x.value(), y);
}
template <class xUnit, class yUnit, class ValueType>
constexpr auto islessgreater(quantity<xUnit, ValueType> x, quantity<yUnit, ValueType> y) -> decltype(std::islessgreater(x.value(), y.value()))
{
    static_assert(std::is_same_v<xUnit, yUnit> || is_compatible_v<xUnit, yUnit>, "You can only calculate the islessgreater of quantities with the same unit.");
    return std::islessgreater(x.value(), y.value());
}
template <class xUnit, class yUnit, class ValueType>
constexpr auto islessgreater(quantity_point<xUnit, ValueType> x, quantity_point<yUnit, ValueType> y) -> decltype(std::islessgreater(x.value(), y.value()))
{
    static_assert(std::is_same_v<xUnit, yUnit>, "You can only calculate the islessgreater of quantities with the same unit.");
    return std::islessgreater(x.value(), y.value());
}
template <class yUnit, class ValueType>
constexpr auto islessgreater(ValueType x, quantity<yUnit, ValueType> y) -> decltype(std::islessgreater(x, y.value()))
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit>, "You can only calculate the islessgreater of quantities with the same unit.");
    return std::islessgreater(x, y.value());
}
template <class yUnit, class ValueType>
constexpr auto islessgreater(ValueType x, quantity_point<yUnit, ValueType> y) -> decltype(std::islessgreater(x, y.value()))
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit>, "You can only calculate the islessgreater of quantities with the same unit.");
    return std::islessgreater(x, y.value());
}
template <class xUnit, class ValueType>
constexpr auto islessgreater(quantity<xUnit, ValueType> x, ValueType y) -> decltype(std::islessgreater(x.value(), y))
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit>, "You can only calculate the islessgreater of quantities with the same unit.");
    return std::islessgreater(x.value(), y);
}
template <class xUnit, class ValueType>
constexpr auto islessgreater(quantity_point<xUnit, ValueType> x, ValueType y) -> decltype(std::islessgreater(x.value(), y))
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit>, "You can only calculate the islessgreater of quantities with the same unit.");
    return std::islessgreater(x.value(), y);
}
template <class xUnit, class yUnit, class ValueType>
constexpr auto isunordered(quantity<xUnit, ValueType> x, quantity<yUnit, ValueType> y) -> decltype(std::isunordered(x.value(), y.value()))
{
    static_assert(std::is_same_v<xUnit, yUnit> || is_compatible_v<xUnit, yUnit>, "You can only calculate the isunordered of quantities with the same unit.");
    return std::isunordered(x.value(), y.value());
}
template <class xUnit, class yUnit, class ValueType>
constexpr auto isunordered(quantity_point<xUnit, ValueType> x, quantity_point<yUnit, ValueType> y) -> decltype(std::isunordered(x.value(), y.value()))
{
    static_assert(std::is_same_v<xUnit, yUnit>, "You can only calculate the isunordered of quantities with the same unit.");
    return std::isunordered(x.value(), y.value());
}
template <class yUnit, class ValueType>
constexpr auto isunordered(ValueType x, quantity<yUnit, ValueType> y) -> decltype(std::isunordered(x, y.value()))
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit>, "You can only calculate the isunordered of quantities with the same unit.");
    return std::isunordered(x, y.value());
}
template <class yUnit, class ValueType>
constexpr auto isunordered(ValueType x, quantity_point<yUnit, ValueType> y) -> decltype(std::isunordered(x, y.value()))
{
    static_assert(std::is_same_v<make_one<yUnit>, yUnit>, "You can only calculate the isunordered of quantities with the same unit.");
    return std::isunordered(x, y.value());
}
template <class xUnit, class ValueType>
constexpr auto isunordered(quantity<xUnit, ValueType> x, ValueType y) -> decltype(std::isunordered(x.value(), y))
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit>, "You can only calculate the isunordered of quantities with the same unit.");
    return std::isunordered(x.value(), y);
}
template <class xUnit, class ValueType>
constexpr auto isunordered(quantity_point<xUnit, ValueType> x, ValueType y) -> decltype(std::isunordered(x.value(), y))
{
    static_assert(std::is_same_v<make_one<xUnit>, xUnit>, "You can only calculate the isunordered of quantities with the same unit.");
    return std::isunordered(x.value(), y);
}
#pragma endregion
#pragma region special mathematical functions
#if __cplusplus >= 201703L
//The following functions are not implemented, but could be in the future:
//assoc_laguerre
//assoc_laguerref
//assoc_laguerrel
//assoc_legendre
//assoc_legendref
//assoc_legendrel
//beta
//betaf
//betal
//comp_ellint_1
//comp_ellint_1f
//comp_ellint_1l
//comp_ellint_2
//comp_ellint_2f
//comp_ellint_2l
//comp_ellint_3
//comp_ellint_3f
//comp_ellint_3l
//cyl_bessel_i
//cyl_bessel_if
//cyl_bessel_il
//cyl_bessel_j
//cyl_bessel_jf
//cyl_bessel_jl
//cyl_bessel_k
//cyl_bessel_kf
//cyl_bessel_kl
//cyl_neumann
//cyl_neumannf
//cyl_neumannl
//ellint_1
//ellint_1f
//ellint_1l
//ellint_2
//ellint_2f
//ellint_2l
//ellint_3
//ellint_3f
//ellint_3l
//expint
//expintf
//expintl
//hermite
//hermitef
//hermitel
//legendre
//legendref
//legendrel
//laguerre
//laguerref
//laguerrel
//riemann_zeta
//riemann_zetaf
//riemann_zetal
//sph_bessel
//sph_besself
//sph_bessell
//sph_legendre
//sph_legendref
//sph_legendrel
//sph_neumann
//sph_neumannf
//sph_neumannl
#endif
#pragma endregion
#pragma region custom math
//The following functions are not inside <cmath>, but could be implemented in the future:
//sinc
#pragma endregion
#pragma endregion
} // namespace benri