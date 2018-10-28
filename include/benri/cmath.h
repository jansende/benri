#pragma once
#include <benri/quantity.h>
#include <benri/units/dimensions.h>
#include <benri/unit.h>
#include <benri/impl/meta_math.h>
#include <benri/impl/list.h>
#include <cstdlib>
#include <cmath>

//TODO: - ALL MATH functions need to be checked, that they return the right unit
namespace benri
{
#pragma region helper
//helper
template <class Unit>
using make_one_t = back_substitution_t<unit<typename Unit::system, typename dim::dimensionless_t, list<>>>;
template <class Unit>
using make_plane_angle_t = back_substitution_t<unit<typename Unit::system, typename dim::plane_angle_t, list<>>>;
#pragma endregion
#pragma region custom math
#pragma endregion
#pragma region cmath
#pragma region basic operations
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
constexpr auto fabs(quantity<Unit, ValueType> val) -> quantity<Unit, decltype(std::fabs(val.value()))>
{
    using ResultType = decltype(std::fabs(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<Unit, ResultType>{std::fabs(val.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class xValueType, class yUnit, class yValueType>
auto fmod(quantity<xUnit, xValueType> x, quantity<yUnit, yValueType> y) -> quantity<xUnit, decltype(std::fmod(x.value(), y.value()))>
{
    static_assert(std::is_same_v<typename yUnit::system, typename xUnit::system>, "You can only calculate the fmod of quantities from the same unit system.");
    static_assert(std::is_same_v<yValueType, xValueType>, "You can only calculate the fmod of quantities with the same value_type.");
    using ResultType = decltype(std::fmod(x.value(), y.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<yValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_plane_angle_t<yUnit>, ResultType>{std::fmod(x.value(), y.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class xValueType, class yUnit, class yValueType>
auto remquo(quantity<xUnit, xValueType> x, quantity<yUnit, yValueType> y, int *quo) -> quantity<xUnit, decltype(std::remquo(x.value(), y.value(), quo))>
{
    static_assert(std::is_same_v<typename yUnit::system, typename xUnit::system>, "You can only calculate the remquo of quantities from the same unit system.");
    static_assert(std::is_same_v<yValueType, xValueType>, "You can only calculate the remquo of quantities with the same value_type.");
    using ResultType = decltype(std::remquo(x.value(), y.value(), quo));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<yValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_plane_angle_t<yUnit>, ResultType>{std::remquo(x.value(), y.value(), quo)};
}
template <bool AllowImplicitConversion = false, class xUnit, class xValueType, class yUnit, class yValueType, class zUnit, class zValueType>
constexpr auto fma(quantity<xUnit, xValueType> x, quantity<yUnit, yValueType> y, quantity<zUnit, zValueType> z) -> quantity<zUnit, decltype(std::fma(x.value(), y.value(), z.value()))>
{
    static_assert(std::is_same_v<multiply_units_t<xUnit, yUnit>, zUnit>, "You can only calculate the fma of quantities with the units being x*y == z.");
    static_assert(std::is_same_v<xValueType, yValueType> && std::is_same_v<yValueType, zValueType>, "You can only calculate the fma of quantities with the same value_type.");
    using ResultType = decltype(std::fma(x.value(), y.value(), z.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<zValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<zUnit, ResultType>{std::fma(x.value(), y.value(), z.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class xValueType, class yUnit, class yValueType>
constexpr auto fmax(quantity<xUnit, xValueType> x, quantity<yUnit, yValueType> y) -> quantity<xUnit, decltype(std::fmax(x.value(), y.value()))>
{
    static_assert(std::is_same_v<xUnit, yUnit>, "You can only calculate the fmax of quantities with the same unit.");
    static_assert(std::is_same_v<xValueType, yValueType>, "You can only calculate the fmax of quantities with the same value_type.");
    using ResultType = decltype(std::fmax(x.value(), y.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<xValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<xUnit, ResultType>{std::fmax(x.value(), y.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class xValueType, class yUnit, class yValueType>
constexpr auto fmin(quantity<xUnit, xValueType> x, quantity<yUnit, yValueType> y) -> quantity<xUnit, decltype(std::fmin(x.value(), y.value()))>
{
    static_assert(std::is_same_v<xUnit, yUnit>, "You can only calculate the fmin of quantities with the same unit.");
    static_assert(std::is_same_v<xValueType, yValueType>, "You can only calculate the fmin of quantities with the same value_type.");
    using ResultType = decltype(std::fmin(x.value(), y.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<xValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<xUnit, ResultType>{std::fmin(x.value(), y.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class xValueType, class yUnit, class yValueType>
constexpr auto fdim(quantity<xUnit, xValueType> x, quantity<yUnit, yValueType> y) -> quantity<xUnit, decltype(std::fdim(x.value(), y.value()))>
{
    static_assert(std::is_same_v<xUnit, yUnit>, "You can only calculate the fdim of quantities with the same unit.");
    static_assert(std::is_same_v<xValueType, yValueType>, "You can only calculate the fdim of quantities with the same value_type.");
    using ResultType = decltype(std::fdim(x.value(), y.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<xValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<xUnit, ResultType>{std::fdim(x.value(), y.value())};
}
#pragma endregion
#pragma region exponential functions
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto exp(quantity<Unit, ValueType> val) -> quantity<make_one_t<Unit>, decltype(std::exp(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the exp of a dimensionless quantity.");
    using ResultType = decltype(std::exp(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one_t<Unit>, ResultType>{std::exp(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto exp2(quantity<Unit, ValueType> val) -> quantity<make_one_t<Unit>, decltype(std::exp2(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the exp2 of a dimensionless quantity.");
    using ResultType = decltype(std::exp2(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one_t<Unit>, ResultType>{std::exp2(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto expm1(quantity<Unit, ValueType> val) -> quantity<make_one_t<Unit>, decltype(std::expm1(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the expm1 of a dimensionless quantity.");
    using ResultType = decltype(std::expm1(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one_t<Unit>, ResultType>{std::expm1(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto log(quantity<Unit, ValueType> val) -> quantity<make_one_t<Unit>, decltype(std::log(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the log of a dimensionless quantity.");
    using ResultType = decltype(std::log(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one_t<Unit>, ResultType>{std::log(remove_prefix(val).value())};
}
template <class ScalingUnit, bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto log(quantity<Unit, ValueType> val) -> quantity<make_one_t<Unit>, decltype(std::log(remove_prefix(unit_cast<ScalingUnit>(val)).value()))>
{
    static_assert(std::is_same_v<typename ScalingUnit::system, typename Unit::system>, "Your unit and your scaling unit need to be from the same unit system.");
    static_assert(std::is_same_v<typename ScalingUnit::dimensions, typename Unit::dimensions>, "Your unit and your scaling unit have to have the same dimensions.");
    using ResultType = decltype(std::log(remove_prefix(unit_cast<ScalingUnit>(val)).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one_t<Unit>, ResultType>{std::log(remove_prefix(unit_cast<ScalingUnit>(val)).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto log10(quantity<Unit, ValueType> val) -> quantity<make_one_t<Unit>, decltype(std::log10(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the log10 of a dimensionless quantity.");
    using ResultType = decltype(std::log10(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one_t<Unit>, ResultType>{std::log10(remove_prefix(val).value())};
}
template <class ScalingUnit, bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto log10(quantity<Unit, ValueType> val) -> quantity<make_one_t<Unit>, decltype(std::log10(remove_prefix(unit_cast<ScalingUnit>(val)).value()))>
{
    static_assert(std::is_same_v<typename ScalingUnit::system, typename Unit::system>, "Your unit and your scaling unit need to be from the same unit system.");
    static_assert(std::is_same_v<typename ScalingUnit::dimensions, typename Unit::dimensions>, "Your unit and your scaling unit have to have the same dimensions.");
    using ResultType = decltype(std::log10(remove_prefix(unit_cast<ScalingUnit>(val)).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one_t<Unit>, ResultType>{std::log10(remove_prefix(unit_cast<ScalingUnit>(val)).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto log2(quantity<Unit, ValueType> val) -> quantity<make_one_t<Unit>, decltype(std::log2(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the log2 of a dimensionless quantity.");
    using ResultType = decltype(std::log2(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one_t<Unit>, ResultType>{std::log2(remove_prefix(val).value())};
}
template <class ScalingUnit, bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto log2(quantity<Unit, ValueType> val) -> quantity<make_one_t<Unit>, decltype(std::log2(remove_prefix(unit_cast<ScalingUnit>(val)).value()))>
{
    static_assert(std::is_same_v<typename ScalingUnit::system, typename Unit::system>, "Your unit and your scaling unit need to be from the same unit system.");
    static_assert(std::is_same_v<typename ScalingUnit::dimensions, typename Unit::dimensions>, "Your unit and your scaling unit have to have the same dimensions.");
    using ResultType = decltype(std::log2(remove_prefix(unit_cast<ScalingUnit>(val)).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one_t<Unit>, ResultType>{std::log2(remove_prefix(unit_cast<ScalingUnit>(val)).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto log1p(quantity<Unit, ValueType> val) -> quantity<make_one_t<Unit>, decltype(std::log1p(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the log1p of a dimensionless quantity.");
    using ResultType = decltype(std::log1p(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one_t<Unit>, ResultType>{std::log1p(remove_prefix(val).value())};
}
#pragma endregion
#pragma region power functions
template <class Exponent, bool AllowImplicitConversion = false, class baseUnit, class baseValueType>
constexpr auto pow(quantity<baseUnit, baseValueType> base) -> quantity<back_substitution_t<pow_unit_t<baseUnit, Exponent>>, decltype(std::pow(base.value(), baseValueType(Exponent::num) / baseValueType(Exponent::den)))>
{
    static_assert(impl::is_ratio_v<Exponent>, "The Exponent needs to be a std::ratio.");
    using ResultType = decltype(std::pow(base.value(), baseValueType(Exponent::num) / baseValueType(Exponent::den)));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<baseValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<back_substitution_t<pow_unit_t<baseUnit, Exponent>>, ResultType>{std::pow(base.value(), baseValueType(Exponent::num) / baseValueType(Exponent::den))};
}
template <intmax_t num, bool AllowImplicitConversion = false, class baseUnit, class baseValueType>
constexpr auto pow(quantity<baseUnit, baseValueType> base)
{
    return pow<std::ratio<num>, AllowImplicitConversion>(base);
}
template <intmax_t num, intmax_t den, bool AllowImplicitConversion = false, class baseUnit, class baseValueType>
constexpr auto pow(quantity<baseUnit, baseValueType> base)
{
    return pow<std::ratio<num, den>, AllowImplicitConversion>(base);
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto sqrt(quantity<Unit, ValueType> val) -> quantity<back_substitution_t<pow_unit_t<Unit, std::ratio<1, 2>>>, decltype(std::sqrt(val.value()))>
{
    using ResultType = decltype(std::sqrt(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<back_substitution_t<pow_unit_t<Unit, std::ratio<1, 2>>>, ResultType>{std::sqrt(val.value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto cbrt(quantity<Unit, ValueType> val) -> quantity<back_substitution_t<pow_unit_t<Unit, std::ratio<1, 3>>>, decltype(std::cbrt(val.value()))>
{
    using ResultType = decltype(std::cbrt(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<back_substitution_t<pow_unit_t<Unit, std::ratio<1, 3>>>, ResultType>{std::cbrt(val.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class xValueType, class yUnit, class yValueType>
constexpr auto hypot(quantity<xUnit, xValueType> x, quantity<yUnit, yValueType> y) -> quantity<xUnit, decltype(std::hypot(x.value(), y.value()))>
{
    static_assert(std::is_same_v<xUnit, yUnit>, "You can only calculate the hypot of quantities with the same unit.");
    static_assert(std::is_same_v<xValueType, yValueType>, "You can only calculate the hypot of quantities with the same value_type.");
    using ResultType = decltype(std::hypot(x.value(), y.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<xValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<xUnit, ResultType>{std::hypot(x.value(), y.value())};
}
#if __cplusplus >= 201703L
template <bool AllowImplicitConversion = false, class xUnit, class xValueType, class yUnit, class yValueType, class zUnit, class zValueType>
constexpr auto hypot(quantity<xUnit, xValueType> x, quantity<yUnit, yValueType> y, quantity<zUnit, zValueType> z) -> quantity<xUnit, decltype(std::hypot(x.value(), y.value(), z.value()))>
{
    static_assert(std::is_same_v<xUnit, yUnit> && std::is_same_v<yUnit, zUnit>, "You can only calculate the hypot of quantities with the same unit.");
    static_assert(std::is_same_v<xValueType, yValueType> && std::is_same_v<yValueType, zValueType>, "You can only calculate the hypot of quantities with the same value_type.");
    using ResultType = decltype(std::hypot(x.value(), y.value(), z.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<xValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<xUnit, ResultType>{std::hypot(x.value(), y.value(), z.value())};
}
#endif
#pragma endregion
#pragma region trigonometric functions
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto sin(quantity<Unit, ValueType> val) -> quantity<make_one_t<Unit>, decltype(std::sin(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t> || std::is_same_v<typename Unit::dimensions, dim::plane_angle_t>, "You can only calculate the sin of a dimensionless quantity or an angle.");
    using ResultType = decltype(std::sin(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one_t<Unit>, ResultType>{std::sin(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto cos(quantity<Unit, ValueType> val) -> quantity<make_one_t<Unit>, decltype(std::cos(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t> || std::is_same_v<typename Unit::dimensions, dim::plane_angle_t>, "You can only calculate the cos of a dimensionless quantity or an angle.");
    using ResultType = decltype(std::cos(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one_t<Unit>, ResultType>{std::cos(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto tan(quantity<Unit, ValueType> val) -> quantity<make_one_t<Unit>, decltype(std::tan(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t> || std::is_same_v<typename Unit::dimensions, dim::plane_angle_t>, "You can only calculate the tan of a dimensionless quantity or an angle.");
    using ResultType = decltype(std::tan(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one_t<Unit>, ResultType>{std::tan(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto asin(quantity<Unit, ValueType> val) -> quantity<make_plane_angle_t<Unit>, decltype(std::asin(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the asin of a dimensionless quantity.");
    using ResultType = decltype(std::asin(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_plane_angle_t<Unit>, ResultType>{std::asin(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto acos(quantity<Unit, ValueType> val) -> quantity<make_plane_angle_t<Unit>, decltype(std::acos(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the acos of a dimensionless quantity.");
    using ResultType = decltype(std::acos(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_plane_angle_t<Unit>, ResultType>{std::acos(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto atan(quantity<Unit, ValueType> val) -> quantity<make_plane_angle_t<Unit>, decltype(std::atan(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the atan of a dimensionless quantity.");
    using ResultType = decltype(std::atan(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_plane_angle_t<Unit>, ResultType>{std::atan(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class yUnit, class yValueType, class xUnit, class xValueType>
auto atan2(quantity<yUnit, yValueType> y, quantity<xUnit, xValueType> x) -> quantity<make_plane_angle_t<yUnit>, decltype(std::atan2(remove_prefix(y).value(), remove_prefix(x).value()))>
{
    static_assert(std::is_same_v<typename yUnit::system, typename xUnit::system>, "You can only calculate the atan2 of quantities from the same unit system.");
    static_assert(std::is_same_v<typename yUnit::dimensions, typename xUnit::dimensions>, "You can only calculate the atan2 of quantities with the same dimensions.");
    static_assert(std::is_same_v<yValueType, xValueType>, "You can only calculate the atan2 of quantities with the same value_type.");
    using ResultType = decltype(std::atan2(remove_prefix(y).value(), remove_prefix(x).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<yValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_plane_angle_t<yUnit>, ResultType>{std::atan2(remove_prefix(y).value(), remove_prefix(x).value())};
}
#pragma endregion
#pragma region hyperbolic functions
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto sinh(quantity<Unit, ValueType> val) -> quantity<make_one_t<Unit>, decltype(std::sinh(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the sinh of a dimensionless quantity.");
    using ResultType = decltype(std::sinh(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one_t<Unit>, ResultType>{std::sinh(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto cosh(quantity<Unit, ValueType> val) -> quantity<make_one_t<Unit>, decltype(std::cosh(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the cosh of a dimensionless quantity.");
    using ResultType = decltype(std::cosh(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one_t<Unit>, ResultType>{std::cosh(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto tanh(quantity<Unit, ValueType> val) -> quantity<make_one_t<Unit>, decltype(std::tanh(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the tanh of a dimensionless quantity.");
    using ResultType = decltype(std::tanh(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one_t<Unit>, ResultType>{std::tanh(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto asinh(quantity<Unit, ValueType> val) -> quantity<make_one_t<Unit>, decltype(std::asinh(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the asinh of a dimensionless quantity.");
    using ResultType = decltype(std::asinh(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one_t<Unit>, ResultType>{std::asinh(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto acosh(quantity<Unit, ValueType> val) -> quantity<make_one_t<Unit>, decltype(std::acosh(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the acosh of a dimensionless quantity.");
    using ResultType = decltype(std::acosh(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one_t<Unit>, ResultType>{std::acosh(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto atanh(quantity<Unit, ValueType> val) -> quantity<make_one_t<Unit>, decltype(std::atanh(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the atanh of a dimensionless quantity.");
    using ResultType = decltype(std::atanh(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one_t<Unit>, ResultType>{std::atanh(remove_prefix(val).value())};
}
#pragma endregion
#pragma region error and gamma functions
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto erf(quantity<Unit, ValueType> val) -> quantity<make_one_t<Unit>, decltype(std::erf(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the erf of a dimensionless quantity.");
    using ResultType = decltype(std::erf(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one_t<Unit>, ResultType>{std::erf(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto erfc(quantity<Unit, ValueType> val) -> quantity<make_one_t<Unit>, decltype(std::erfc(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the erfc of a dimensionless quantity.");
    using ResultType = decltype(std::erfc(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one_t<Unit>, ResultType>{std::erfc(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto tgamma(quantity<Unit, ValueType> val) -> quantity<make_one_t<Unit>, decltype(std::tgamma(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the tgamma of a dimensionless quantity.");
    using ResultType = decltype(std::tgamma(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one_t<Unit>, ResultType>{std::tgamma(remove_prefix(val).value())};
}
template <bool AllowImplicitConversion = false, class Unit, class ValueType>
constexpr auto lgamma(quantity<Unit, ValueType> val) -> quantity<make_one_t<Unit>, decltype(std::lgamma(remove_prefix(val).value()))>
{
    static_assert(std::is_same_v<typename Unit::dimensions, dim::dimensionless_t>, "You can only calculate the lgamma of a dimensionless quantity.");
    using ResultType = decltype(std::lgamma(remove_prefix(val).value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<make_one_t<Unit>, ResultType>{std::lgamma(remove_prefix(val).value())};
}
#pragma endregion
#pragma region nearest integer floating point operations
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
constexpr auto floor(quantity<Unit, ValueType> val) -> quantity<Unit, decltype(std::floor(val.value()))>
{
    using ResultType = decltype(std::floor(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<Unit, ResultType>{std::floor(val.value())};
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
constexpr auto round(quantity<Unit, ValueType> val) -> quantity<Unit, decltype(std::round(val.value()))>
{
    using ResultType = decltype(std::round(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<Unit, ResultType>{std::round(val.value())};
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
constexpr auto llround(quantity<Unit, ValueType> val) -> quantity<Unit, decltype(std::llround(val.value()))>
{
    using ResultType = decltype(std::llround(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<Unit, ResultType>{std::llround(val.value())};
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
constexpr auto rint(quantity<Unit, ValueType> val) -> quantity<Unit, decltype(std::rint(val.value()))>
{
    using ResultType = decltype(std::rint(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<Unit, ResultType>{std::rint(val.value())};
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
constexpr auto llrint(quantity<Unit, ValueType> val) -> quantity<Unit, decltype(std::llrint(val.value()))>
{
    using ResultType = decltype(std::llrint(val.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<ValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<Unit, ResultType>{std::llrint(val.value())};
}
#pragma endregion
#pragma region floating point manipulation functions
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
constexpr auto logb(quantity<Unit, ValueType> val)
{
    return std::logb(val.value());
}
template <bool AllowImplicitConversion = false, class fromUnit, class fromValueType, class toUnit, class toValueType>
constexpr auto nextafter(quantity<fromUnit, fromValueType> from, quantity<toUnit, toValueType> to) -> quantity<fromUnit, decltype(std::nextafter(from.value(), to.value()))>
{
    static_assert(std::is_same_v<fromUnit, toUnit>, "You can only calculate the nextafter of quantities with the same unit.");
    static_assert(std::is_same_v<fromValueType, toValueType>, "You can only calculate the nextafter of quantities with the same value_type.");
    using ResultType = decltype(std::nextafter(from.value(), to.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<fromValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<fromUnit, ResultType>{std::nextafter(from.value(), to.value())};
}
template <bool AllowImplicitConversion = false, class fromUnit, class fromValueType, class toUnit, class toValueType>
constexpr auto nexttoward(quantity<fromUnit, fromValueType> from, quantity<toUnit, toValueType> to) -> quantity<fromUnit, decltype(std::nexttoward(from.value(), to.value()))>
{
    static_assert(std::is_same_v<fromUnit, toUnit>, "You can only calculate the nexttoward of quantities with the same unit.");
    static_assert(std::is_same_v<fromValueType, toValueType>, "You can only calculate the nexttoward of quantities with the same value_type.");
    using ResultType = decltype(std::nexttoward(from.value(), to.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<fromValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<fromUnit, ResultType>{std::nexttoward(from.value(), to.value())};
}
template <bool AllowImplicitConversion = false, class xUnit, class xValueType, class yUnit, class yValueType>
constexpr auto copysign(quantity<xUnit, xValueType> x, quantity<yUnit, yValueType> y) -> quantity<xUnit, decltype(std::copysign(x.value(), y.value()))>
{
    static_assert(std::is_same_v<xUnit, yUnit>, "You can only calculate the copysign of quantities with the same unit.");
    static_assert(std::is_same_v<xValueType, yValueType>, "You can only calculate the copysign of quantities with the same value_type.");
    using ResultType = decltype(std::copysign(x.value(), y.value()));
#ifndef BENRI_ALLOW_IMPLICIT_CONVERSIONS
    static_assert(std::is_same_v<xValueType, ResultType> || AllowImplicitConversion, "Your value_type is implicitly converted.");
#endif
    return quantity<xUnit, ResultType>{std::copysign(x.value(), y.value())};
}
#pragma endregion
#pragma region classification and comparison
template <class Unit, class ValueType>
constexpr auto fpclassify(quantity<Unit, ValueType> val)
{
    return std::fpclassify(val.value());
}
template <class Unit, class ValueType>
constexpr auto isfinite(quantity<Unit, ValueType> val)
{
    return std::isfinite(val.value());
}
template <class Unit, class ValueType>
constexpr auto isinf(quantity<Unit, ValueType> val)
{
    return std::isinf(val.value());
}
template <class Unit, class ValueType>
constexpr auto isnan(quantity<Unit, ValueType> val)
{
    return std::isnan(val.value());
}
template <class Unit, class ValueType>
constexpr auto isnormal(quantity<Unit, ValueType> val)
{
    return std::isnormal(val.value());
}
template <class Unit, class ValueType>
constexpr auto signbit(quantity<Unit, ValueType> val)
{
    return std::signbit(val.value());
}
template <class xUnit, class xValueType, class yUnit, class yValueType>
constexpr auto isgreater(quantity<xUnit, xValueType> x, quantity<yUnit, yValueType> y)
{
    static_assert(std::is_same_v<xUnit, yUnit>, "You can only calculate the isgreater of quantities with the same unit.");
    static_assert(std::is_same_v<xValueType, yValueType>, "You can only calculate the isgreater of quantities with the same value_type.");
    return std::isgreater(x.value(), y.value());
}
template <class xUnit, class xValueType, class yUnit, class yValueType>
constexpr auto isgreaterequal(quantity<xUnit, xValueType> x, quantity<yUnit, yValueType> y)
{
    static_assert(std::is_same_v<xUnit, yUnit>, "You can only calculate the isgreaterequal of quantities with the same unit.");
    static_assert(std::is_same_v<xValueType, yValueType>, "You can only calculate the isgreaterequal of quantities with the same value_type.");
    return std::isgreaterequal(x.value(), y.value());
}
template <class xUnit, class xValueType, class yUnit, class yValueType>
constexpr auto isless(quantity<xUnit, xValueType> x, quantity<yUnit, yValueType> y)
{
    static_assert(std::is_same_v<xUnit, yUnit>, "You can only calculate the isless of quantities with the same unit.");
    static_assert(std::is_same_v<xValueType, yValueType>, "You can only calculate the isless of quantities with the same value_type.");
    return std::isless(x.value(), y.value());
}
template <class xUnit, class xValueType, class yUnit, class yValueType>
constexpr auto islessequal(quantity<xUnit, xValueType> x, quantity<yUnit, yValueType> y)
{
    static_assert(std::is_same_v<xUnit, yUnit>, "You can only calculate the islessequal of quantities with the same unit.");
    static_assert(std::is_same_v<xValueType, yValueType>, "You can only calculate the islessequal of quantities with the same value_type.");
    return std::islessequal(x.value(), y.value());
}
template <class xUnit, class xValueType, class yUnit, class yValueType>
constexpr auto islessgreater(quantity<xUnit, xValueType> x, quantity<yUnit, yValueType> y)
{
    static_assert(std::is_same_v<xUnit, yUnit>, "You can only calculate the islessgreater of quantities with the same unit.");
    static_assert(std::is_same_v<xValueType, yValueType>, "You can only calculate the islessgreater of quantities with the same value_type.");
    return std::islessgreater(x.value(), y.value());
}
template <class xUnit, class xValueType, class yUnit, class yValueType>
constexpr auto isunordered(quantity<xUnit, xValueType> x, quantity<yUnit, yValueType> y)
{
    static_assert(std::is_same_v<xUnit, yUnit>, "You can only calculate the isunordered of quantities with the same unit.");
    static_assert(std::is_same_v<xValueType, yValueType>, "You can only calculate the isunordered of quantities with the same value_type.");
    return std::isunordered(x.value(), y.value());
}
#pragma endregion
#pragma region special mathematical functions
#if __cplusplus >= 201703L
#endif
#pragma endregion
#pragma endregion
} // namespace benri
