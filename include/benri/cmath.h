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
//one_unit creates a dimensionless type from the given Unit
using one_unit = unit<typename dim::dimensionless_t, list<>>;
//plane_angle_unit creates an angle type from the given Unit
using plane_angle_unit = unit<typename dim::plane_angle_t, list<>>;
//conversion_type resolves the common type/type promotion for functions.
template <class lhsQuantity, class rhsQuantity, bool AllowPoints>
struct conversion_type
{
    static_assert(std::is_same<lhsQuantity, rhsQuantity>::value, "all arguments have to have the same type.\n(You tried to use an implicit conversion to one for all arguments.)");
    using type = std::conditional_t<std::is_same<lhsQuantity, rhsQuantity>::value, quantity<one_unit, lhsQuantity>, void>;
};
template <class rhsUnit, class ValueType, bool AllowPoints>
struct conversion_type<ValueType, quantity<rhsUnit, ValueType>, AllowPoints>
{
    using type = quantity<rhsUnit, ValueType>;
};
template <class lhsUnit, class ValueType, bool AllowPoints>
struct conversion_type<quantity<lhsUnit, ValueType>, ValueType, AllowPoints>
{
    using type = quantity<lhsUnit, ValueType>;
};
template <class rhsUnit, class ValueType>
struct conversion_type<ValueType, quantity_point<rhsUnit, ValueType>, true>
{
    using type = quantity_point<rhsUnit, ValueType>;
};
template <class lhsUnit, class ValueType>
struct conversion_type<quantity_point<lhsUnit, ValueType>, ValueType, true>
{
    using type = quantity_point<lhsUnit, ValueType>;
};
template <class lhsUnit, class rhsUnit, class ValueType, bool AllowPoints>
struct conversion_type<quantity<lhsUnit, ValueType>, quantity<rhsUnit, ValueType>, AllowPoints>
{
    static_assert(std::is_same<lhsUnit, rhsUnit>::value || detect_if<lhsUnit, is_compatible_with, rhsUnit>, "all arguments have to have the same or compatible units.");
    using type = std::conditional_t<std::is_same<lhsUnit, rhsUnit>::value || detect_if<lhsUnit, is_compatible_with, rhsUnit>, quantity<lhsUnit, ValueType>, void>;
};
template <class lhsUnit, class rhsUnit, class ValueType>
struct conversion_type<quantity_point<lhsUnit, ValueType>, quantity_point<rhsUnit, ValueType>, true>
{
    static_assert(std::is_same<lhsUnit, rhsUnit>::value, "all arguments have to have the same units.");
    using type = std::conditional_t<std::is_same<lhsUnit, rhsUnit>::value, quantity_point<lhsUnit, ValueType>, void>;
};
template <class lhsQuantity, class rhsQuantity, bool AllowPoints = false>
using conversion_type_t = typename conversion_type<lhsQuantity, rhsQuantity, AllowPoints>::type;
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
//output value_type are manually set in the source code, and the programme
//will not compile, if they differ.
//
//All functions are marked as noexcept, as they are expexted to only use
//integral types.
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
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto max_impl(const quantity<Unit, ValueType> x, const quantity<Unit, ValueType> y) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = std::remove_cvref_t<decltype(std::max(x.value(), y.value()))>;
    return quantity<Unit, ResultType>{std::max(x.value(), y.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto max_impl(const quantity_point<Unit, ValueType> x, const quantity_point<Unit, ValueType> y) noexcept -> quantity_point<Unit, ValueType>
{
    using ResultType = std::remove_cvref_t<decltype(std::max(x.value(), y.value()))>;
    return quantity_point<Unit, ResultType>{std::max(x.value(), y.value())};
}
template <class lhsQuantity, class rhsQuantity>
[[nodiscard]] constexpr inline auto max(const lhsQuantity x, const rhsQuantity y)
{
    using ConversionType = conversion_type_t<lhsQuantity, rhsQuantity, true>;
    return max_impl<typename ConversionType::unit_type, typename ConversionType::value_type>(x, y);
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto min_impl(const quantity<Unit, ValueType> x, const quantity<Unit, ValueType> y) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = std::remove_cvref_t<decltype(std::min(x.value(), y.value()))>;
    return quantity<Unit, ResultType>{std::min(x.value(), y.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto min_impl(const quantity_point<Unit, ValueType> x, const quantity_point<Unit, ValueType> y) noexcept -> quantity_point<Unit, ValueType>
{
    using ResultType = std::remove_cvref_t<decltype(std::min(x.value(), y.value()))>;
    return quantity_point<Unit, ResultType>{std::min(x.value(), y.value())};
}
template <class lhsQuantity, class rhsQuantity>
[[nodiscard]] constexpr inline auto min(lhsQuantity x, rhsQuantity y)
{
    using ConversionType = conversion_type_t<lhsQuantity, rhsQuantity, true>;
    return min_impl<typename ConversionType::unit_type, typename ConversionType::value_type>(x, y);
}
#pragma endregion
#pragma region basic operations
//The abs, and fabs functions calculate the absolute value of quantities
//without looking at the underlying unit.
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto abs(const quantity<Unit, ValueType> val) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = decltype(std::abs(val.value()));
    return quantity<Unit, ResultType>{std::abs(val.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto abs(const quantity_point<Unit, ValueType> val) noexcept -> quantity_point<Unit, ValueType>
{
    using ResultType = decltype(std::abs(val.value()));
    return quantity_point<Unit, ResultType>{std::abs(val.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto fabs(const quantity<Unit, ValueType> val) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = decltype(std::fabs(val.value()));
    return quantity<Unit, ResultType>{std::fabs(val.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto fabs(const quantity_point<Unit, ValueType> val) noexcept -> quantity_point<Unit, ValueType>
{
    using ResultType = decltype(std::fabs(val.value()));
    return quantity_point<Unit, ResultType>{std::fabs(val.value())};
}
//The fmod, remainder, and remquo functions calculate the remainder of the
//division of two quantities without looking at the units.
template <class xUnit, class yUnit, class ValueType>
[[nodiscard]] constexpr inline auto fmod(const quantity<xUnit, ValueType> x, const quantity<yUnit, ValueType> y) noexcept -> quantity<xUnit, ValueType>
{
    using ResultType = decltype(std::fmod(x.value(), y.value()));
    return quantity<xUnit, ResultType>{std::fmod(x.value(), y.value())};
}
template <class xUnit, class ValueType>
[[nodiscard]] constexpr inline auto fmod(const quantity<xUnit, ValueType> x, ValueType y) noexcept -> quantity<xUnit, ValueType>
{
    using ResultType = decltype(std::fmod(x.value(), y));
    return quantity<xUnit, ResultType>{std::fmod(x.value(), y)};
}
template <class yUnit, class ValueType>
[[nodiscard]] constexpr inline auto fmod(ValueType x, const quantity<yUnit, ValueType> y) noexcept -> quantity<one_unit, ValueType>
{
    using ResultType = decltype(std::fmod(x, y.value()));
    return quantity<one_unit, ResultType>{std::fmod(x, y.value())};
}
template <class xUnit, class yUnit, class ValueType>
[[nodiscard]] constexpr inline auto remainder(const quantity<xUnit, ValueType> x, const quantity<yUnit, ValueType> y) noexcept -> quantity<xUnit, ValueType>
{
    using ResultType = decltype(std::remainder(x.value(), y.value()));
    return quantity<xUnit, ResultType>{std::remainder(x.value(), y.value())};
}
template <class xUnit, class ValueType>
[[nodiscard]] constexpr inline auto remainder(const quantity<xUnit, ValueType> x, ValueType y) noexcept -> quantity<xUnit, ValueType>
{
    using ResultType = decltype(std::remainder(x.value(), y));
    return quantity<xUnit, ResultType>{std::remainder(x.value(), y)};
}
template <class yUnit, class ValueType>
[[nodiscard]] constexpr inline auto remainder(ValueType x, const quantity<yUnit, ValueType> y) noexcept -> quantity<one_unit, ValueType>
{
    using ResultType = decltype(std::remainder(x, y.value()));
    return quantity<one_unit, ResultType>{std::remainder(x, y.value())};
}
template <class xUnit, class yUnit, class ValueType>
[[nodiscard]] constexpr inline auto remquo(const quantity<xUnit, ValueType> x, const quantity<yUnit, ValueType> y, int *quo) noexcept -> quantity<xUnit, ValueType>
{
    using ResultType = decltype(std::remquo(x.value(), y.value(), quo));
    return quantity<xUnit, ResultType>{std::remquo(x.value(), y.value(), quo)};
}
template <class xUnit, class ValueType>
[[nodiscard]] constexpr inline auto remquo(const quantity<xUnit, ValueType> x, ValueType y, int *quo) noexcept -> quantity<xUnit, ValueType>
{
    using ResultType = decltype(std::remquo(x.value(), y, quo));
    return quantity<xUnit, ResultType>{std::remquo(x.value(), y, quo)};
}
template <class yUnit, class ValueType>
[[nodiscard]] constexpr inline auto remquo(ValueType x, const quantity<yUnit, ValueType> y, int *quo) noexcept -> quantity<one_unit, ValueType>
{
    using ResultType = decltype(std::remquo(x, y.value(), quo));
    return quantity<one_unit, ResultType>{std::remquo(x, y.value(), quo)};
}
//The fma function combines a multiplication and addition operation of the quantities
//x, y, z. The result is x*y+z. The units of x*y and z must be equal.
template <class xUnit, class yUnit, class zUnit, class ValueType>
[[nodiscard]] constexpr inline auto fma(const quantity<xUnit, ValueType> x, const quantity<yUnit, ValueType> y, const quantity<zUnit, ValueType> z) noexcept -> std::enable_if_t<std::is_same<multiply_units<xUnit, yUnit>, zUnit>::value || detect_if<multiply_units<xUnit, yUnit>, is_compatible_with, zUnit>, quantity<zUnit, ValueType>>
{
    using ResultType = decltype(std::fma(x.value(), y.value(), z.value()));
    return quantity<zUnit, ResultType>{std::fma(x.value(), y.value(), z.value())};
}
template <class xUnit, class yUnit, class zUnit, class ValueType>
[[nodiscard]] constexpr inline auto fma(const quantity<xUnit, ValueType> x, const quantity<yUnit, ValueType> y, const quantity_point<zUnit, ValueType> z) noexcept -> std::enable_if_t<std::is_same<multiply_units<xUnit, yUnit>, zUnit>::value || detect_if<multiply_units<xUnit, yUnit>, is_compatible_with, zUnit>, quantity_point<zUnit, ValueType>>
{
    using ResultType = decltype(std::fma(x.value(), y.value(), z.value()));
    return quantity_point<zUnit, ResultType>{std::fma(x.value(), y.value(), z.value())};
}
template <class yUnit, class zUnit, class ValueType>
[[nodiscard]] constexpr inline auto fma(ValueType x, const quantity<yUnit, ValueType> y, const quantity<zUnit, ValueType> z) noexcept -> std::enable_if_t<std::is_same<yUnit, zUnit>::value || detect_if<yUnit, is_compatible_with, zUnit>, quantity<zUnit, ValueType>>
{
    using ResultType = decltype(std::fma(x, y.value(), z.value()));
    return quantity<zUnit, ResultType>{std::fma(x, y.value(), z.value())};
}
template <class yUnit, class zUnit, class ValueType>
[[nodiscard]] constexpr inline auto fma(ValueType x, const quantity<yUnit, ValueType> y, const quantity_point<zUnit, ValueType> z) noexcept -> std::enable_if_t<std::is_same<yUnit, zUnit>::value || detect_if<yUnit, is_compatible_with, zUnit>, quantity_point<zUnit, ValueType>>
{
    using ResultType = decltype(std::fma(x, y.value(), z.value()));
    return quantity_point<zUnit, ResultType>{std::fma(x, y.value(), z.value())};
}
template <class xUnit, class zUnit, class ValueType>
[[nodiscard]] constexpr inline auto fma(const quantity<xUnit, ValueType> x, ValueType y, const quantity<zUnit, ValueType> z) noexcept -> std::enable_if_t<std::is_same<xUnit, zUnit>::value || detect_if<xUnit, is_compatible_with, zUnit>, quantity<zUnit, ValueType>>
{
    using ResultType = decltype(std::fma(x.value(), y, z.value()));
    return quantity<zUnit, ResultType>{std::fma(x.value(), y, z.value())};
}
template <class xUnit, class zUnit, class ValueType>
[[nodiscard]] constexpr inline auto fma(const quantity<xUnit, ValueType> x, ValueType y, const quantity_point<zUnit, ValueType> z) noexcept -> std::enable_if_t<std::is_same<xUnit, zUnit>::value || detect_if<xUnit, is_compatible_with, zUnit>, quantity_point<zUnit, ValueType>>
{
    using ResultType = decltype(std::fma(x.value(), y, z.value()));
    return quantity_point<zUnit, ResultType>{std::fma(x.value(), y, z.value())};
}
template <class xUnit, class yUnit, class ValueType>
[[nodiscard]] constexpr inline auto fma(const quantity<xUnit, ValueType> x, const quantity<yUnit, ValueType> y, ValueType z) noexcept -> std::enable_if_t<std::is_same<multiply_units<xUnit, yUnit>, one_unit>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::fma(x.value(), y.value(), z));
    return quantity<one_unit, ResultType>{std::fma(x.value(), y.value(), z)};
}
//The fmax, and fmin functions return the max/min of two quantities with
//the same unit.
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto fmax_impl(const quantity<Unit, ValueType> x, const quantity<Unit, ValueType> y) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = std::remove_cvref_t<decltype(std::fmax(x.value(), y.value()))>;
    return quantity<Unit, ResultType>{std::fmax(x.value(), y.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto fmax_impl(const quantity_point<Unit, ValueType> x, const quantity_point<Unit, ValueType> y) noexcept -> quantity_point<Unit, ValueType>
{
    using ResultType = std::remove_cvref_t<decltype(std::fmax(x.value(), y.value()))>;
    return quantity_point<Unit, ResultType>{std::fmax(x.value(), y.value())};
}
template <class lhsQuantity, class rhsQuantity>
[[nodiscard]] constexpr inline auto fmax(lhsQuantity x, rhsQuantity y)
{
    using ConversionType = conversion_type_t<lhsQuantity, rhsQuantity, true>;
    return fmax_impl<typename ConversionType::unit_type, typename ConversionType::value_type>(x, y);
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto fmin_impl(const quantity<Unit, ValueType> x, const quantity<Unit, ValueType> y) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = std::remove_cvref_t<decltype(std::fmin(x.value(), y.value()))>;
    return quantity<Unit, ResultType>{std::fmin(x.value(), y.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto fmin_impl(const quantity_point<Unit, ValueType> x, const quantity_point<Unit, ValueType> y) noexcept -> quantity_point<Unit, ValueType>
{
    using ResultType = std::remove_cvref_t<decltype(std::fmin(x.value(), y.value()))>;
    return quantity_point<Unit, ResultType>{std::fmin(x.value(), y.value())};
}
template <class lhsQuantity, class rhsQuantity>
[[nodiscard]] constexpr inline auto fmin(lhsQuantity x, rhsQuantity y)
{
    using ConversionType = conversion_type_t<lhsQuantity, rhsQuantity, true>;
    return fmin_impl<typename ConversionType::unit_type, typename ConversionType::value_type>(x, y);
}
//The fdim function returns the positive difference (max(0,x-y)) of two quan-
//tities with the same unit.
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto fdim_impl(const quantity<Unit, ValueType> x, const quantity<Unit, ValueType> y) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = std::remove_cvref_t<decltype(std::fdim(x.value(), y.value()))>;
    return quantity<Unit, ResultType>{std::fdim(x.value(), y.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto fdim_impl(const quantity_point<Unit, ValueType> x, const quantity_point<Unit, ValueType> y) noexcept -> quantity_point<Unit, ValueType>
{
    using ResultType = std::remove_cvref_t<decltype(std::fdim(x.value(), y.value()))>;
    return quantity<Unit, ResultType>{std::fdim(x.value(), y.value())};
}
template <class lhsQuantity, class rhsQuantity>
[[nodiscard]] constexpr inline auto fdim(lhsQuantity x, rhsQuantity y)
{
    using ConversionType = conversion_type_t<lhsQuantity, rhsQuantity, true>;
    return fdim_impl<typename ConversionType::unit_type, typename ConversionType::value_type>(x, y);
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
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto exp(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename Unit::dimensions, dim::dimensionless_t>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::exp(remove_prefix(val).value()));
    return quantity<one_unit, ResultType>{std::exp(remove_prefix(val).value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto exp2(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename Unit::dimensions, dim::dimensionless_t>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::exp2(remove_prefix(val).value()));
    return quantity<one_unit, ResultType>{std::exp2(remove_prefix(val).value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto expm1(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename Unit::dimensions, dim::dimensionless_t>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::expm1(remove_prefix(val).value()));
    return quantity<one_unit, ResultType>{std::expm1(remove_prefix(val).value())};
}
//The log, log10, log2, and log1p functions calculate various versions of the logarithm
//function of dimensionless quantities. Prefixes are removed automatically. This allows
//correct calculation of percent, ...
//Furthermore, the log, log10, and log2 functions provide an overload that allows auto-
//matic scaling of the input. For example: log<metre>(1_kilometre) is the same as
//log(1_kilometre/1_metre)
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto log(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename Unit::dimensions, dim::dimensionless_t>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::log(remove_prefix(val).value()));
    return quantity<one_unit, ResultType>{std::log(remove_prefix(val).value())};
}
template <class ScalingUnit, class Unit, class ValueType>
[[nodiscard]] constexpr inline auto log(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename ScalingUnit::dimensions, typename Unit::dimensions>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::log(remove_prefix(unit_cast<ScalingUnit>(val)).value()));
    return quantity<one_unit, ResultType>{std::log(remove_prefix(unit_cast<ScalingUnit>(val)).value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto log10(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename Unit::dimensions, dim::dimensionless_t>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::log10(remove_prefix(val).value()));
    return quantity<one_unit, ResultType>{std::log10(remove_prefix(val).value())};
}
template <class ScalingUnit, class Unit, class ValueType>
[[nodiscard]] constexpr inline auto log10(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename ScalingUnit::dimensions, typename Unit::dimensions>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::log10(remove_prefix(unit_cast<ScalingUnit>(val)).value()));
    return quantity<one_unit, ResultType>{std::log10(remove_prefix(unit_cast<ScalingUnit>(val)).value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto log2(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename Unit::dimensions, dim::dimensionless_t>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::log2(remove_prefix(val).value()));
    return quantity<one_unit, ResultType>{std::log2(remove_prefix(val).value())};
}
template <class ScalingUnit, class Unit, class ValueType>
[[nodiscard]] constexpr inline auto log2(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename ScalingUnit::dimensions, typename Unit::dimensions>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::log2(remove_prefix(unit_cast<ScalingUnit>(val)).value()));
    return quantity<one_unit, ResultType>{std::log2(remove_prefix(unit_cast<ScalingUnit>(val)).value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto log1p(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename Unit::dimensions, dim::dimensionless_t>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::log1p(remove_prefix(val).value()));
    return quantity<one_unit, ResultType>{std::log1p(remove_prefix(val).value())};
}
#pragma endregion
#pragma region power functions
//The pow<> function calculates the power of a given quantity, changing the unit.
//Three overloads are provided. You can either provide the power as a std::ratio:
//pow<std::ratio<1,2>> or using integers pow<1,2>. With the denominator being
//optional: pow<std::ratio<2>> = pow<2>.
template <class Exponent, class baseUnit, class ValueType>
[[nodiscard]] constexpr inline auto pow(const quantity<baseUnit, ValueType> base) noexcept -> std::enable_if_t<detect_if<Exponent, impl::is_std_ratio>, quantity<pow_unit<baseUnit, Exponent>, ValueType>>
{
    using ResultType = decltype(std::pow(base.value(), ValueType(Exponent::num) / ValueType(Exponent::den)));
    return quantity<pow_unit<baseUnit, Exponent>, ResultType>{std::pow(base.value(), ValueType(Exponent::num) / ValueType(Exponent::den))};
}
template <intmax_t num, intmax_t den = 1, class baseUnit, class ValueType>
[[nodiscard]] constexpr inline auto pow(const quantity<baseUnit, ValueType> base)
{
    return pow<std::ratio<num, den>>(base);
}
//The pow function calculates the power of a given dimensionless quantity, without
//changing the unit.
template <class baseUnit, class exponentUnit, class ValueType>
[[nodiscard]] constexpr inline auto pow(const quantity<baseUnit, ValueType> y, const quantity<exponentUnit, ValueType> x) noexcept -> std::enable_if_t<std::is_same<typename baseUnit::dimensions, dim::dimensionless_t>::value && std::is_same<typename exponentUnit::dimensions, dim::dimensionless_t>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::pow(remove_prefix(y).value(), remove_prefix(x).value()));
    return quantity<one_unit, ResultType>{std::pow(remove_prefix(y).value(), remove_prefix(x).value())};
}
template <class exponentUnit, class ValueType>
[[nodiscard]] constexpr inline auto pow(ValueType y, const quantity<exponentUnit, ValueType> x) noexcept -> std::enable_if_t<std::is_same<typename exponentUnit::dimensions, dim::dimensionless_t>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::pow(y, remove_prefix(x).value()));
    return quantity<one_unit, ResultType>{std::pow(y, remove_prefix(x).value())};
}
template <class baseUnit, class ValueType>
[[nodiscard]] constexpr inline auto pow(const quantity<baseUnit, ValueType> y, ValueType x) noexcept -> std::enable_if_t<std::is_same<typename baseUnit::dimensions, dim::dimensionless_t>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::pow(remove_prefix(y).value(), x));
    return quantity<one_unit, ResultType>{std::pow(remove_prefix(y).value(), x)};
}
//The sqrt, and cbrt functions calculate roots of given quantities, changing the
//unit. While the pow function could be used as well, the sqrt and cbrt functions
//directly access the std equivalents instead of using std::pow.
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto sqrt(const quantity<Unit, ValueType> val) noexcept -> quantity<pow_unit<Unit, std::ratio<1, 2>>, ValueType>
{
    using ResultType = decltype(std::sqrt(val.value()));
    return quantity<pow_unit<Unit, std::ratio<1, 2>>, ResultType>{std::sqrt(val.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto cbrt(const quantity<Unit, ValueType> val) noexcept -> quantity<pow_unit<Unit, std::ratio<1, 3>>, ValueType>
{
    using ResultType = decltype(std::cbrt(val.value()));
    return quantity<pow_unit<Unit, std::ratio<1, 3>>, ResultType>{std::cbrt(val.value())};
}
//The hypot function returns the norm of two quantities x, and y with the same unit.
//(hypot(x,y) = sqrt(x^2+y^2))
//An overload for people using c++17 is provided.
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto hypot_impl(const quantity<Unit, ValueType> x, const quantity<Unit, ValueType> y) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = decltype(std::hypot(x.value(), y.value()));
    return quantity<Unit, ResultType>{std::hypot(x.value(), y.value())};
}
template <class lhsQuantity, class rhsQuantity>
[[nodiscard]] constexpr inline auto hypot(lhsQuantity x, rhsQuantity y)
{
    using ConversionType = conversion_type_t<lhsQuantity, rhsQuantity>;
    return hypot_impl<typename ConversionType::unit_type, typename ConversionType::value_type>(x, y);
}
#if __cplusplus >= 201703L
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto hypot_impl(const quantity<Unit, ValueType> x, const quantity<Unit, ValueType> y, const quantity<Unit, ValueType> z) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = decltype(std::hypot(x.value(), y.value(), z.value()));
    return quantity<Unit, ResultType>{std::hypot(x.value(), y.value(), z.value())};
}
template <class lhsQuantity, class midQuantity, class rhsQuantity>
[[nodiscard]] constexpr inline auto hypot(lhsQuantity x, midQuantity y, rhsQuantity z)
{
    using ConversionType = conversion_type_t<lhsQuantity, conversion_type_t<midQuantity, rhsQuantity>>;
    return hypot_impl<typename ConversionType::unit_type, typename ConversionType::value_type>(x, y, z);
}
#endif
#pragma endregion
#pragma region trigonometric functions
//The sin, cos, and tan functions calculate various versions of the trigono-
//metric functions of dimensionless or plane_angle quantities. Prefixes are
//removed automatically. This allows correct calculation of percent, ...
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto sin(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename Unit::dimensions, dim::dimensionless_t>::value || std::is_same<typename Unit::dimensions, dim::plane_angle_t>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::sin(remove_prefix(val).value()));
    return quantity<one_unit, ResultType>{std::sin(remove_prefix(val).value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto cos(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename Unit::dimensions, dim::dimensionless_t>::value || std::is_same<typename Unit::dimensions, dim::plane_angle_t>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::cos(remove_prefix(val).value()));
    return quantity<one_unit, ResultType>{std::cos(remove_prefix(val).value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto tan(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename Unit::dimensions, dim::dimensionless_t>::value || std::is_same<typename Unit::dimensions, dim::plane_angle_t>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::tan(remove_prefix(val).value()));
    return quantity<one_unit, ResultType>{std::tan(remove_prefix(val).value())};
}
//The asin, acos, and atan functions calculate various versions of the inverse
//trigonometric functions of dimensionless quantities. The return type is always
//a plane_angle. Prefixes are removed automatically. This allows correct calcu-
//lation of percent, ...
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto asin(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename Unit::dimensions, dim::dimensionless_t>::value, quantity<plane_angle_unit, ValueType>>
{
    using ResultType = decltype(std::asin(remove_prefix(val).value()));
    return quantity<plane_angle_unit, ResultType>{std::asin(remove_prefix(val).value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto acos(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename Unit::dimensions, dim::dimensionless_t>::value, quantity<plane_angle_unit, ValueType>>
{
    using ResultType = decltype(std::acos(remove_prefix(val).value()));
    return quantity<plane_angle_unit, ResultType>{std::acos(remove_prefix(val).value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto atan(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename Unit::dimensions, dim::dimensionless_t>::value, quantity<plane_angle_unit, ValueType>>
{
    using ResultType = decltype(std::atan(remove_prefix(val).value()));
    return quantity<plane_angle_unit, ResultType>{std::atan(remove_prefix(val).value())};
}
//The atan2 function calculates the atan of y/x given two quantities x and y with
//the same dimension. The return type is always a plane_angle. Prefixes of y and y
//are removed automatically. This allows correct calcution of
//atan2(1_kilometre,1_metre), ...
template <class yUnit, class xUnit, class ValueType>
[[nodiscard]] constexpr inline auto atan2(const quantity<yUnit, ValueType> y, const quantity<xUnit, ValueType> x) noexcept -> std::enable_if_t<std::is_same<typename yUnit::dimensions, typename xUnit::dimensions>::value, quantity<plane_angle_unit, ValueType>>
{
    using ResultType = decltype(std::atan2(remove_prefix(y).value(), remove_prefix(x).value()));
    return quantity<plane_angle_unit, ResultType>{std::atan2(remove_prefix(y).value(), remove_prefix(x).value())};
}
template <class xUnit, class ValueType>
[[nodiscard]] constexpr inline auto atan2(ValueType y, const quantity<xUnit, ValueType> x) noexcept -> std::enable_if_t<std::is_same<typename xUnit::dimensions, dim::dimensionless_t>::value, quantity<plane_angle_unit, ValueType>>
{
    using ResultType = decltype(std::atan2(y, remove_prefix(x).value()));
    return quantity<plane_angle_unit, ResultType>{std::atan2(y, remove_prefix(x).value())};
}
template <class yUnit, class ValueType>
[[nodiscard]] constexpr inline auto atan2(const quantity<yUnit, ValueType> y, ValueType x) noexcept -> std::enable_if_t<std::is_same<typename yUnit::dimensions, dim::dimensionless_t>::value, quantity<plane_angle_unit, ValueType>>
{
    using ResultType = decltype(std::atan2(remove_prefix(y).value(), x));
    return quantity<plane_angle_unit, ResultType>{std::atan2(remove_prefix(y).value(), x)};
}
#pragma endregion
#pragma region hyperbolic functions
//The sinh, cosh, tanh, asinh, acosh, and atanh functions calculate various versions
//of the hyperbolic functions and their inverses of dimensionless quantities. Pre-
//fixes are removed automatically. This allows correct calculation of percent, ...
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto sinh(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename Unit::dimensions, dim::dimensionless_t>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::sinh(remove_prefix(val).value()));
    return quantity<one_unit, ResultType>{std::sinh(remove_prefix(val).value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto cosh(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename Unit::dimensions, dim::dimensionless_t>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::cosh(remove_prefix(val).value()));
    return quantity<one_unit, ResultType>{std::cosh(remove_prefix(val).value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto tanh(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename Unit::dimensions, dim::dimensionless_t>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::tanh(remove_prefix(val).value()));
    return quantity<one_unit, ResultType>{std::tanh(remove_prefix(val).value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto asinh(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename Unit::dimensions, dim::dimensionless_t>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::asinh(remove_prefix(val).value()));
    return quantity<one_unit, ResultType>{std::asinh(remove_prefix(val).value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto acosh(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename Unit::dimensions, dim::dimensionless_t>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::acosh(remove_prefix(val).value()));
    return quantity<one_unit, ResultType>{std::acosh(remove_prefix(val).value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto atanh(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename Unit::dimensions, dim::dimensionless_t>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::atanh(remove_prefix(val).value()));
    return quantity<one_unit, ResultType>{std::atanh(remove_prefix(val).value())};
}
#pragma endregion
#pragma region error and gamma functions
//The erf, and erfc functions calculate various versions of the error function of
//dimensionless quantities. Prefixes are removed automatically. This allows correct
//calculation of percent, ...
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto erf(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename Unit::dimensions, dim::dimensionless_t>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::erf(remove_prefix(val).value()));
    return quantity<one_unit, ResultType>{std::erf(remove_prefix(val).value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto erfc(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename Unit::dimensions, dim::dimensionless_t>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::erfc(remove_prefix(val).value()));
    return quantity<one_unit, ResultType>{std::erfc(remove_prefix(val).value())};
}
//The tgamma, and lgamma functions calculate various versions of the gamma function
//of dimensionless quantities. Prefixes are removed automatically. This allows correct
//calculation of percent, ...
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto tgamma(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename Unit::dimensions, dim::dimensionless_t>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::tgamma(remove_prefix(val).value()));
    return quantity<one_unit, ResultType>{std::tgamma(remove_prefix(val).value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto lgamma(const quantity<Unit, ValueType> val) noexcept -> std::enable_if_t<std::is_same<typename Unit::dimensions, dim::dimensionless_t>::value, quantity<one_unit, ValueType>>
{
    using ResultType = decltype(std::lgamma(remove_prefix(val).value()));
    return quantity<one_unit, ResultType>{std::lgamma(remove_prefix(val).value())};
}
#pragma endregion
#pragma region nearest integer floating point operations
//The ceil, floor, trunc, and nearbyint functions provide nearest integer
//floating point operations for a quantity, ignoring the unit.
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto ceil(const quantity<Unit, ValueType> val) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = decltype(std::ceil(val.value()));
    return quantity<Unit, ResultType>{std::ceil(val.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto ceil(const quantity_point<Unit, ValueType> val) noexcept -> quantity_point<Unit, ValueType>
{
    using ResultType = decltype(std::ceil(val.value()));
    return quantity_point<Unit, ResultType>{std::ceil(val.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto floor(const quantity<Unit, ValueType> val) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = decltype(std::floor(val.value()));
    return quantity<Unit, ResultType>{std::floor(val.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto floor(const quantity_point<Unit, ValueType> val) noexcept -> quantity_point<Unit, ValueType>
{
    using ResultType = decltype(std::floor(val.value()));
    return quantity_point<Unit, ResultType>{std::floor(val.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto trunc(const quantity<Unit, ValueType> val) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = decltype(std::trunc(val.value()));
    return quantity<Unit, ResultType>{std::trunc(val.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto trunc(const quantity_point<Unit, ValueType> val) noexcept -> quantity_point<Unit, ValueType>
{
    using ResultType = decltype(std::trunc(val.value()));
    return quantity_point<Unit, ResultType>{std::trunc(val.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto nearbyint(const quantity<Unit, ValueType> val) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = decltype(std::nearbyint(val.value()));
    return quantity<Unit, ResultType>{std::nearbyint(val.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto nearbyint(const quantity_point<Unit, ValueType> val) noexcept -> quantity_point<Unit, ValueType>
{
    using ResultType = decltype(std::nearbyint(val.value()));
    return quantity_point<Unit, ResultType>{std::nearbyint(val.value())};
}
//The round, lround, llround, rint, lrint, and llrint functions provide nearest integer
//floating point operations for a quantity, ignoring the unit.
//round, and rint will round the value and try to preserve the value_type of the quantity.
//lround, llround, lrint, and llrint will change the value_type to long/long long.
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto round(const quantity<Unit, ValueType> val) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = decltype(std::round(val.value()));
    return quantity<Unit, ResultType>{std::round(val.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto round(const quantity_point<Unit, ValueType> val) noexcept -> quantity_point<Unit, ValueType>
{
    using ResultType = decltype(std::round(val.value()));
    return quantity_point<Unit, ResultType>{std::round(val.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto lround(const quantity<Unit, ValueType> val) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = decltype(std::lround(val.value()));
    return quantity<Unit, ResultType>{std::lround(val.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto lround(const quantity_point<Unit, ValueType> val) noexcept -> quantity_point<Unit, ValueType>
{
    using ResultType = decltype(std::lround(val.value()));
    return quantity_point<Unit, ResultType>{std::lround(val.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto llround(const quantity<Unit, ValueType> val) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = decltype(std::llround(val.value()));
    return quantity<Unit, ResultType>{std::llround(val.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto llround(const quantity_point<Unit, ValueType> val) noexcept -> quantity_point<Unit, ValueType>
{
    using ResultType = decltype(std::llround(val.value()));
    return quantity_point<Unit, ResultType>{std::llround(val.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto rint(const quantity<Unit, ValueType> val) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = decltype(std::rint(val.value()));
    return quantity<Unit, ResultType>{std::rint(val.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto rint(const quantity_point<Unit, ValueType> val) noexcept -> quantity_point<Unit, ValueType>
{
    using ResultType = decltype(std::rint(val.value()));
    return quantity_point<Unit, ResultType>{std::rint(val.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto lrint(const quantity<Unit, ValueType> val) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = decltype(std::lrint(val.value()));
    return quantity<Unit, ResultType>{std::lrint(val.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto lrint(const quantity_point<Unit, ValueType> val) noexcept -> quantity_point<Unit, ValueType>
{
    using ResultType = decltype(std::lrint(val.value()));
    return quantity_point<Unit, ResultType>{std::lrint(val.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto llrint(const quantity<Unit, ValueType> val) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = decltype(std::llrint(val.value()));
    return quantity<Unit, ResultType>{std::llrint(val.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto llrint(const quantity_point<Unit, ValueType> val) noexcept -> quantity_point<Unit, ValueType>
{
    using ResultType = decltype(std::llrint(val.value()));
    return quantity_point<Unit, ResultType>{std::llrint(val.value())};
}
#pragma endregion
#pragma region floating point manipulation functions
//The frexp, ldexp, modf, scalbn, scalbln, ilogb, and logb functions let
//you manipulate the value of a quantity, ignoring the unit.
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto frexp(const quantity<Unit, ValueType> arg, int *exp) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = decltype(std::frexp(arg.value(), exp));
    return quantity<Unit, ResultType>{std::frexp(arg.value(), exp)};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto frexp(const quantity_point<Unit, ValueType> arg, int *exp) noexcept -> quantity_point<Unit, ValueType>
{
    using ResultType = decltype(std::frexp(arg.value(), exp));
    return quantity_point<Unit, ResultType>{std::frexp(arg.value(), exp)};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto ldexp(const quantity<Unit, ValueType> x, int exp) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = decltype(std::ldexp(x.value(), exp));
    return quantity<Unit, ResultType>{std::ldexp(x.value(), exp)};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto modf(const quantity<Unit, ValueType> x, ValueType *iptr) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = decltype(std::modf(x.value(), iptr));
    return quantity<Unit, ResultType>{std::modf(x.value(), iptr)};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto scalbn(const quantity<Unit, ValueType> x, int exp) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = decltype(std::scalbn(x.value(), exp));
    return quantity<Unit, ResultType>{std::scalbn(x.value(), exp)};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto scalbln(const quantity<Unit, ValueType> x, long exp) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = decltype(std::scalbln(x.value(), exp));
    return quantity<Unit, ResultType>{std::scalbln(x.value(), exp)};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto ilogb(const quantity<Unit, ValueType> val)
{
    return std::ilogb(val.value());
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto ilogb(const quantity_point<Unit, ValueType> val)
{
    return std::ilogb(val.value());
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto logb(const quantity<Unit, ValueType> val)
{
    return std::logb(val.value());
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto logb(const quantity_point<Unit, ValueType> val)
{
    return std::logb(val.value());
}
//The nextafter, nexttoward, and copysign functions let you manipulate the value of
//two quantities with the same unit.
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto nextafter_impl(const quantity<Unit, ValueType> x, const quantity<Unit, ValueType> y) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = decltype(std::nextafter(x.value(), y.value()));
    return quantity<Unit, ResultType>{std::nextafter(x.value(), y.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto nextafter_impl(const quantity_point<Unit, ValueType> x, const quantity_point<Unit, ValueType> y) noexcept -> quantity_point<Unit, ValueType>
{
    using ResultType = decltype(std::nextafter(x.value(), y.value()));
    return quantity_point<Unit, ResultType>{std::nextafter(x.value(), y.value())};
}
template <class lhsQuantity, class rhsQuantity>
[[nodiscard]] constexpr inline auto nextafter(lhsQuantity x, rhsQuantity y)
{
    using ConversionType = conversion_type_t<lhsQuantity, rhsQuantity, true>;
    return nextafter_impl<typename ConversionType::unit_type, typename ConversionType::value_type>(x, y);
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto nexttoward_impl(const quantity<Unit, ValueType> x, const quantity<Unit, ValueType> y) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = decltype(std::nexttoward(x.value(), static_cast<long double>(y.value())));
    return quantity<Unit, ResultType>{std::nexttoward(x.value(), static_cast<long double>(y.value()))};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto nexttoward_impl(const quantity_point<Unit, ValueType> x, const quantity_point<Unit, ValueType> y) noexcept -> quantity_point<Unit, ValueType>
{
    using ResultType = decltype(std::nexttoward(x.value(), static_cast<long double>(y.value())));
    return quantity_point<Unit, ResultType>{std::nexttoward(x.value(), static_cast<long double>(y.value()))};
}
template <class lhsQuantity, class rhsQuantity>
[[nodiscard]] constexpr inline auto nexttoward(lhsQuantity x, rhsQuantity y)
{
    using ConversionType = conversion_type_t<lhsQuantity, rhsQuantity, true>;
    return nexttoward_impl<typename ConversionType::unit_type, typename ConversionType::value_type>(x, y);
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto copysign_impl(const quantity<Unit, ValueType> x, const quantity<Unit, ValueType> y) noexcept -> quantity<Unit, ValueType>
{
    using ResultType = decltype(std::copysign(x.value(), y.value()));
    return quantity<Unit, ResultType>{std::copysign(x.value(), y.value())};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto copysign_impl(const quantity_point<Unit, ValueType> x, const quantity_point<Unit, ValueType> y) noexcept -> quantity_point<Unit, ValueType>
{
    using ResultType = decltype(std::copysign(x.value(), y.value()));
    return quantity_point<Unit, ResultType>{std::copysign(x.value(), y.value())};
}
template <class lhsQuantity, class rhsQuantity>
[[nodiscard]] constexpr inline auto copysign(lhsQuantity x, rhsQuantity y)
{
    using ConversionType = conversion_type_t<lhsQuantity, rhsQuantity, true>;
    return copysign_impl<typename ConversionType::unit_type, typename ConversionType::value_type>(x, y);
}
#pragma endregion
#pragma region classification and comparison
//The fpclassify, isfinite, isinf, isnan, isnormal, and signbit functions
//provide informations on the stored value of a quantity, ignoring the unit.
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto fpclassify(const quantity<Unit, ValueType> val) noexcept -> int
{
    return std::fpclassify(val.value());
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto fpclassify(const quantity_point<Unit, ValueType> val) noexcept -> int
{
    return std::fpclassify(val.value());
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto isfinite(const quantity<Unit, ValueType> val) noexcept -> bool
{
    return std::isfinite(val.value());
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto isfinite(const quantity_point<Unit, ValueType> val) noexcept -> bool
{
    return std::isfinite(val.value());
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto isinf(const quantity<Unit, ValueType> val) noexcept -> bool
{
    return std::isinf(val.value());
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto isinf(const quantity_point<Unit, ValueType> val) noexcept -> bool
{
    return std::isinf(val.value());
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto isnan(const quantity<Unit, ValueType> val) noexcept -> bool
{
    return std::isnan(val.value());
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto isnan(const quantity_point<Unit, ValueType> val) noexcept -> bool
{
    return std::isnan(val.value());
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto isnormal(const quantity<Unit, ValueType> val) noexcept -> bool
{
    return std::isnormal(val.value());
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto isnormal(const quantity_point<Unit, ValueType> val) noexcept -> bool
{
    return std::isnormal(val.value());
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto signbit(const quantity<Unit, ValueType> val) noexcept -> bool
{
    return std::signbit(val.value());
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto signbit(const quantity_point<Unit, ValueType> val) noexcept -> bool
{
    return std::signbit(val.value());
}
//The isgreater, isgreaterequal, isless, islessequal, islessgreater, and
//isunordered functions lets you compare two quantities with the same unit.
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto isgreater_impl(const quantity<Unit, ValueType> x, const quantity<Unit, ValueType> y) noexcept -> bool
{
    return std::isgreater(x.value(), y.value());
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto isgreater_impl(const quantity_point<Unit, ValueType> x, const quantity_point<Unit, ValueType> y) noexcept -> bool
{
    return std::isgreater(x.value(), y.value());
}
template <class lhsQuantity, class rhsQuantity>
[[nodiscard]] constexpr inline auto isgreater(lhsQuantity x, rhsQuantity y)
{
    using ConversionType = conversion_type_t<lhsQuantity, rhsQuantity, true>;
    return isgreater_impl<typename ConversionType::unit_type, typename ConversionType::value_type>(x, y);
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto isgreaterequal_impl(const quantity<Unit, ValueType> x, const quantity<Unit, ValueType> y) noexcept -> bool
{
    return std::isgreaterequal(x.value(), y.value());
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto isgreaterequal_impl(const quantity_point<Unit, ValueType> x, const quantity_point<Unit, ValueType> y) noexcept -> bool
{
    return std::isgreaterequal(x.value(), y.value());
}
template <class lhsQuantity, class rhsQuantity>
[[nodiscard]] constexpr inline auto isgreaterequal(lhsQuantity x, rhsQuantity y)
{
    using ConversionType = conversion_type_t<lhsQuantity, rhsQuantity, true>;
    return isgreaterequal_impl<typename ConversionType::unit_type, typename ConversionType::value_type>(x, y);
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto isless_impl(const quantity<Unit, ValueType> x, const quantity<Unit, ValueType> y) noexcept -> bool
{
    return std::isless(x.value(), y.value());
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto isless_impl(const quantity_point<Unit, ValueType> x, const quantity_point<Unit, ValueType> y) noexcept -> bool
{
    return std::isless(x.value(), y.value());
}
template <class lhsQuantity, class rhsQuantity>
[[nodiscard]] constexpr inline auto isless(lhsQuantity x, rhsQuantity y)
{
    using ConversionType = conversion_type_t<lhsQuantity, rhsQuantity, true>;
    return isless_impl<typename ConversionType::unit_type, typename ConversionType::value_type>(x, y);
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto islessequal_impl(const quantity<Unit, ValueType> x, const quantity<Unit, ValueType> y) noexcept -> bool
{
    return std::islessequal(x.value(), y.value());
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto islessequal_impl(const quantity_point<Unit, ValueType> x, const quantity_point<Unit, ValueType> y) noexcept -> bool
{
    return std::islessequal(x.value(), y.value());
}
template <class lhsQuantity, class rhsQuantity>
[[nodiscard]] constexpr inline auto islessequal(lhsQuantity x, rhsQuantity y)
{
    using ConversionType = conversion_type_t<lhsQuantity, rhsQuantity, true>;
    return islessequal_impl<typename ConversionType::unit_type, typename ConversionType::value_type>(x, y);
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto islessgreater_impl(const quantity<Unit, ValueType> x, const quantity<Unit, ValueType> y) noexcept -> bool
{
    return std::islessgreater(x.value(), y.value());
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto islessgreater_impl(const quantity_point<Unit, ValueType> x, const quantity_point<Unit, ValueType> y) noexcept -> bool
{
    return std::islessgreater(x.value(), y.value());
}
template <class lhsQuantity, class rhsQuantity>
[[nodiscard]] constexpr inline auto islessgreater(lhsQuantity x, rhsQuantity y)
{
    using ConversionType = conversion_type_t<lhsQuantity, rhsQuantity, true>;
    return islessgreater_impl<typename ConversionType::unit_type, typename ConversionType::value_type>(x, y);
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto isunordered_impl(const quantity<Unit, ValueType> x, const quantity<Unit, ValueType> y) noexcept -> bool
{
    return std::isunordered(x.value(), y.value());
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto isunordered_impl(const quantity_point<Unit, ValueType> x, const quantity_point<Unit, ValueType> y) noexcept -> bool
{
    return std::isunordered(x.value(), y.value());
}
template <class lhsQuantity, class rhsQuantity>
[[nodiscard]] constexpr inline auto isunordered(lhsQuantity x, rhsQuantity y)
{
    using ConversionType = conversion_type_t<lhsQuantity, rhsQuantity, true>;
    return isunordered_impl<typename ConversionType::unit_type, typename ConversionType::value_type>(x, y);
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