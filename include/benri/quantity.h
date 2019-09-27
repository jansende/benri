#pragma once
#include <benri/impl/config.h>
#include <benri/impl/unit.h>
#include <cmath>
#include <type_traits>

namespace benri
{
// quantity_point forward declaration
template <class Unit, class ValueType>
class quantity_point;
// quantity forward declaration
template <class Unit, class ValueType>
class quantity;
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto square(quantity<Unit, ValueType> val) noexcept
{
    return val * val;
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto cubic(quantity<Unit, ValueType> val) noexcept
{
    return val * val * val;
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto quartic(quantity<Unit, ValueType> val) noexcept
{
    return val * val * val * val;
}
#pragma region quantity class
// The quantity type handles physical quantities. It checks the units
// in calculations and handles conversions, etc. The type in general
// should be compile time constexpr and if in some context contexpr
// cannot be used, it should still be optimized into a single variable
// of type ValueType.
template <class Unit, class ValueType = Precision>
class quantity
{
  public:
    template <class, class>
    friend class quantity;
    template <class, class>
    friend class quantity_point;
    template <class, class>
    friend struct convert;

    using value_type = ValueType;
    using unit_type  = Unit;

    friend constexpr inline auto
        operator+(const quantity<unit_type, value_type>&       lhs,
                  const quantity_point<unit_type, value_type>& rhs) noexcept
        -> quantity_point<unit_type, value_type>;
    friend constexpr inline auto
        operator+(const quantity_point<unit_type, value_type>& lhs,
                  const quantity<unit_type, value_type>&       rhs) noexcept
        -> quantity_point<unit_type, value_type>;

    friend constexpr inline auto
        operator-(const quantity<unit_type, value_type>&       lhs,
                  const quantity_point<unit_type, value_type>& rhs) noexcept
        -> quantity_point<unit_type, value_type>;
    friend constexpr inline auto
        operator-(const quantity_point<unit_type, value_type>& lhs,
                  const quantity<unit_type, value_type>&       rhs) noexcept
        -> quantity_point<unit_type, value_type>;

  private:
    value_type _value;

  public:
    [[nodiscard]] constexpr inline auto value() const noexcept { return _value; }
#pragma region casting
    // Friend declaration for the casting functions.
    template <class ResultValueType, class ArgumentUnit, class ArgumentValueType>
    friend constexpr inline auto
        value_type_cast(const quantity<ArgumentUnit, ArgumentValueType>& rhs) noexcept
        -> quantity<ArgumentUnit, ResultValueType>;
    template <class ResultUnit, class ArgumentUnit, class ArgumentValueType>
    friend constexpr inline auto
        simple_cast(const quantity<ArgumentUnit, ArgumentValueType>& rhs) noexcept
        -> std::enable_if_t<std::is_same<typename ResultUnit::dimension,
                                         typename ArgumentUnit::dimension>::value
                                && type::detect_if<ResultUnit, type::is_unit>,
                            quantity<ResultUnit, ArgumentValueType>>;
    template <class ResultUnit, class ArgumentUnit, class ArgumentValueType>
    friend constexpr inline auto
        unit_cast(const quantity<ArgumentUnit, ArgumentValueType>& rhs) noexcept
        -> std::enable_if_t<std::is_same<typename ResultUnit::dimension,
                                         typename ArgumentUnit::dimension>::value
                                && type::detect_if<ResultUnit, type::is_unit>,
                            quantity<ResultUnit, ArgumentValueType>>;
    template <class ResultValueType, class ArgumentUnit, class ArgumentValueType>
    friend constexpr inline auto
        remove_prefix(const quantity<ArgumentUnit, ArgumentValueType>& rhs) noexcept
        -> quantity<drop_unit_prefix<ArgumentUnit>, ResultValueType>;
#pragma endregion
#pragma region rule of three
    // default constructor
    constexpr inline quantity() noexcept = default;
    // value constructor
    explicit constexpr inline quantity(const value_type& value) noexcept : _value(value)
    {
    }
    explicit constexpr inline quantity(value_type&& value) noexcept :
        _value(std::move(value))
    {
    }
    // implicit constructor
    template <class Other, class Dummy = void,
              typename = std::enable_if_t<
                  type::detect_if<Other, is_convertible_into, quantity>, Dummy>>
    constexpr inline quantity(const Other& rhs) noexcept :
        quantity(convert<std::remove_cv_t<Other>, std::remove_cv_t<quantity>>{}(rhs))
    {
    }
    template <class Other, class Dummy = void,
              typename = std::enable_if_t<
                  type::detect_if<Other, is_convertible_into, quantity>, Dummy>>
    constexpr inline quantity(Other&& rhs) noexcept :
        quantity(std::move(convert<std::remove_cv_t<Other>, std::remove_cv_t<quantity>>{}(
            std::move(rhs))))
    {
    }

    template <class Other, class Dummy = void,
              typename = std::enable_if_t<
                  type::detect_if<quantity, is_convertible_into, Other>, Dummy>>
    [[nodiscard]] constexpr inline explicit operator Other() const noexcept
    {
        return convert<std::remove_cv_t<quantity>, std::remove_cv_t<Other>>{}(*this);
    }

    // copy constructor
    constexpr inline quantity(const quantity&) noexcept = default;
    // move constructor
    constexpr inline quantity(quantity&&) noexcept = default;
    // default destructor
    inline ~quantity() noexcept = default;
    // copy assignment
    constexpr inline quantity& operator=(const quantity&) noexcept = default;
    // move assignment
    constexpr inline quantity& operator=(quantity&&) noexcept = default;
    // explicit type conversion
    template <
        class Dummy = value_type,
        typename    = std::enable_if_t<type::detect_if<unit_type, type::is_one>, Dummy>>
    [[nodiscard]] constexpr inline explicit operator value_type() const noexcept
    {
        return _value;
    }
#pragma endregion
#pragma region math declarations / a bit implementation
#pragma region unary operators
    [[nodiscard]] constexpr inline auto operator+() const noexcept
    {
        return quantity{_value};
    }
    [[nodiscard]] constexpr inline auto operator-() const noexcept
    {
        return quantity{value_type{-1} * _value};
    }
#pragma endregion
#pragma region addition
    constexpr inline auto operator+=(const quantity& rhs) noexcept
    {
        this->_value += rhs._value;
        return *this;
    }
    [[nodiscard]] friend constexpr inline auto operator+(const quantity& lhs,
                                                         const quantity& rhs) noexcept
    {
        return quantity{lhs._value + rhs._value};
    }
    template <class Other, class Dummy = void,
              typename = std::enable_if_t<
                  type::detect_if<Other, is_convertible_into, quantity>, Dummy>>
    [[nodiscard]] friend constexpr inline auto operator+(const quantity& lhs,
                                                         const Other&    rhs) noexcept
    {
        return lhs + convert<std::remove_cv_t<Other>, std::remove_cv_t<quantity>>{}(rhs);
    }

    constexpr inline auto operator-=(const quantity& rhs) noexcept
    {
        this->_value -= rhs._value;
        return *this;
    }
    [[nodiscard]] friend constexpr inline auto operator-(const quantity& lhs,
                                                         const quantity& rhs) noexcept
    {
        return quantity{lhs._value - rhs._value};
    }
    template <class Other, class Dummy = void,
              typename = std::enable_if_t<
                  type::detect_if<Other, is_convertible_into, quantity>, Dummy>>
    [[nodiscard]] friend constexpr inline auto operator-(const quantity& lhs,
                                                         const Other&    rhs) noexcept
    {
        return lhs - convert<std::remove_cv_t<Other>, std::remove_cv_t<quantity>>{}(rhs);
    }
#pragma endregion
#pragma region multiplication
    constexpr inline auto& operator*=(const quantity<one, value_type>& rhs) noexcept
    {
        this->_value *= rhs.value();
        return *this;
    }
    template <class lhsUnit, class rhsUnit, class rhsValueType>
    friend constexpr inline auto
        operator*(const quantity<lhsUnit, rhsValueType>& lhs,
                  const quantity<rhsUnit, rhsValueType>& rhs) noexcept
        -> quantity<multiply_units<lhsUnit, rhsUnit>, rhsValueType>;
    [[nodiscard]] friend constexpr inline auto operator*(const quantity&   lhs,
                                                         const value_type& rhs) noexcept
    {
        return quantity{lhs._value * rhs};
    }
    [[nodiscard]] friend constexpr inline auto operator*(const value_type& lhs,
                                                         const quantity&   rhs) noexcept
    {
        return quantity{lhs * rhs._value};
    }
    constexpr inline auto& operator/=(const quantity<one, value_type>& rhs) noexcept
    {
        this->_value /= rhs.value();
        return *this;
    }
    template <class lhsUnit, class rhsUnit, class rhsValueType>
    friend constexpr inline auto
        operator/(const quantity<lhsUnit, rhsValueType>& lhs,
                  const quantity<rhsUnit, rhsValueType>& rhs) noexcept
        -> quantity<divide_units<lhsUnit, rhsUnit>, rhsValueType>;
    [[nodiscard]] friend constexpr inline auto operator/(const quantity&   lhs,
                                                         const value_type& rhs) noexcept
    {
        return quantity{lhs._value / rhs};
    }
    [[nodiscard]] friend constexpr inline auto operator/(const value_type& lhs,
                                                         const quantity&   rhs) noexcept
    {
        return quantity<pow_unit<unit_type, std::ratio<-1>>, value_type>{lhs
                                                                         / rhs._value};
    }
#pragma endregion
#pragma region comparisons
    [[nodiscard]] friend constexpr inline auto operator==(const quantity& lhs,
                                                          const quantity& rhs) noexcept
    {
        return lhs._value == rhs._value;
    }
    template <class Other, class Dummy = void,
              typename = std::enable_if_t<
                  type::detect_if<Other, is_convertible_into, quantity>, Dummy>>
    [[nodiscard]] friend constexpr inline auto operator==(const quantity& lhs,
                                                          const Other&    rhs) noexcept
    {
        return lhs == convert<std::remove_cv_t<Other>, std::remove_cv_t<quantity>>{}(rhs);
    }
    [[nodiscard]] friend constexpr inline auto operator!=(const quantity& lhs,
                                                          const quantity& rhs) noexcept
    {
        return !(lhs == rhs);
    }
    template <class Other, class Dummy = void,
              typename = std::enable_if_t<
                  type::detect_if<Other, is_convertible_into, quantity>, Dummy>>
    [[nodiscard]] friend constexpr inline auto operator!=(const quantity& lhs,
                                                          const Other&    rhs) noexcept
    {
        return lhs != convert<std::remove_cv_t<Other>, std::remove_cv_t<quantity>>{}(rhs);
    }
    [[nodiscard]] friend constexpr inline auto operator<(const quantity& lhs,
                                                         const quantity& rhs) noexcept
    {
        return lhs._value < rhs._value;
    }
    template <class Other, class Dummy = void,
              typename = std::enable_if_t<
                  type::detect_if<Other, is_convertible_into, quantity>, Dummy>>
    [[nodiscard]] friend constexpr inline auto operator<(const quantity& lhs,
                                                         const Other&    rhs) noexcept
    {
        return lhs < convert<std::remove_cv_t<Other>, std::remove_cv_t<quantity>>{}(rhs);
    }
    [[nodiscard]] friend constexpr inline auto operator>(const quantity& lhs,
                                                         const quantity& rhs) noexcept
    {
        return rhs < lhs;
    }
    template <class Other, class Dummy = void,
              typename = std::enable_if_t<
                  type::detect_if<Other, is_convertible_into, quantity>, Dummy>>
    [[nodiscard]] friend constexpr inline auto operator>(const quantity& lhs,
                                                         const Other&    rhs) noexcept
    {
        return lhs > convert<std::remove_cv_t<Other>, std::remove_cv_t<quantity>>{}(rhs);
    }
    [[nodiscard]] friend constexpr inline auto operator<=(const quantity& lhs,
                                                          const quantity& rhs) noexcept
    {
        return !(rhs < lhs);
    }
    template <class Other, class Dummy = void,
              typename = std::enable_if_t<
                  type::detect_if<Other, is_convertible_into, quantity>, Dummy>>
    [[nodiscard]] friend constexpr inline auto operator<=(const quantity& lhs,
                                                          const Other&    rhs) noexcept
    {
        return lhs <= convert<std::remove_cv_t<Other>, std::remove_cv_t<quantity>>{}(rhs);
    }
    [[nodiscard]] friend constexpr inline auto operator>=(const quantity& lhs,
                                                          const quantity& rhs) noexcept
    {
        return !(lhs < rhs);
    }
    template <class Other, class Dummy = void,
              typename = std::enable_if_t<
                  type::detect_if<Other, is_convertible_into, quantity>, Dummy>>
    [[nodiscard]] friend constexpr inline auto operator>=(const quantity& lhs,
                                                          const Other&    rhs) noexcept
    {
        return lhs >= convert<std::remove_cv_t<Other>, std::remove_cv_t<quantity>>{}(rhs);
    }
#pragma endregion
#pragma endregion
};
template <class lhsUnit, class rhsUnit, class rhsValueType>
[[nodiscard]] constexpr inline auto
    operator*(const quantity<lhsUnit, rhsValueType>& lhs,
              const quantity<rhsUnit, rhsValueType>& rhs) noexcept
    -> quantity<multiply_units<lhsUnit, rhsUnit>, rhsValueType>
{
    return quantity<multiply_units<lhsUnit, rhsUnit>, rhsValueType>{lhs._value
                                                                    * rhs._value};
}
template <class lhsUnit, class rhsUnit, class rhsValueType>
[[nodiscard]] constexpr inline auto
    operator/(const quantity<lhsUnit, rhsValueType>& lhs,
              const quantity<rhsUnit, rhsValueType>& rhs) noexcept
    -> quantity<divide_units<lhsUnit, rhsUnit>, rhsValueType>
{
    return quantity<divide_units<lhsUnit, rhsUnit>, rhsValueType>{lhs._value
                                                                  / rhs._value};
}
// Conversion operator for the unit without prefix and dimension
template <class ValueType>
struct convert<ValueType, quantity<one, ValueType>>
{
    constexpr auto operator()(const ValueType& rhs) -> quantity<one, ValueType>
    {
        return quantity<one, ValueType>{rhs};
    }
    constexpr auto operator()(ValueType&& rhs) -> quantity<one, ValueType>
    {
        return quantity<one, ValueType>{std::move(rhs)};
    }
};
#pragma region casting functions
// The value_type_cast function lets you cast the value_type of a quantity
// to another value_type.
template <class ResultValueType, class ArgumentUnit, class ArgumentValueType>
[[nodiscard]] constexpr inline auto
    value_type_cast(const quantity<ArgumentUnit, ArgumentValueType>& rhs) noexcept
    -> quantity<ArgumentUnit, ResultValueType>
{
    return quantity<ArgumentUnit, ResultValueType>{
        static_cast<ResultValueType>(rhs._value)};
}
// The simple_cast function lets you cast one quantity to another unit.
// This is done by multiplying the value of the quantity with the right
// conversion constant. The simple_cast function relies on a custom imple-
// mentation of the power function, which allows it to be evaluated at
// compile time. However, the implementation has a restriction, that it is
// not compatible with roots of units.
template <class ResultUnit, class ArgumentUnit, class ArgumentValueType>
[[nodiscard]] constexpr inline auto
    simple_cast(const quantity<ArgumentUnit, ArgumentValueType>& rhs) noexcept
    -> std::enable_if_t<std::is_same<typename ResultUnit::dimension,
                                     typename ArgumentUnit::dimension>::value
                            && type::detect_if<ResultUnit, type::is_unit>,
                        quantity<ResultUnit, ArgumentValueType>>
{
    constexpr auto factor = expand_prefix_list<
        ArgumentValueType,
        type::divide_lists<typename ArgumentUnit::prefix, typename ResultUnit::prefix>>;
    return quantity<ResultUnit, ArgumentValueType>{rhs._value * factor};
}
template <class ResultUnit, class ArgumentUnit, class ArgumentValueType>
[[nodiscard]] constexpr inline auto
    simple_cast(const quantity<ArgumentUnit, ArgumentValueType>& rhs) noexcept
    -> std::enable_if_t<type::detect_if<ResultUnit, type::is_quantity>,
                        quantity<typename ResultUnit::unit_type, ArgumentValueType>>
{
    return simple_cast<typename ResultUnit::unit_type>(rhs);
}
// The unit_cast function lets you cast one quantity to another unit.
// This is done by multiplying the value of the quantity with the right
// conversion constant. The unit_cast function uses std::pow for the
// conversion. This allows it to calculate arbitrary roots, but makes
// it incompatible with compile time evaluation. The function is still
// marked constexpr, to be forward compatible with a constexpr std::pow
// implementation.
template <class ResultUnit, class ArgumentUnit, class ArgumentValueType>
[[nodiscard]] constexpr inline auto
    unit_cast(const quantity<ArgumentUnit, ArgumentValueType>& rhs) noexcept
    -> std::enable_if_t<std::is_same<typename ResultUnit::dimension,
                                     typename ArgumentUnit::dimension>::value
                            && type::detect_if<ResultUnit, type::is_unit>,
                        quantity<ResultUnit, ArgumentValueType>>
{
    const auto factor = runtime_expand_prefix_list<ArgumentValueType>(
        type::divide_lists<typename ArgumentUnit::prefix, typename ResultUnit::prefix>{});
    return quantity<ResultUnit, ArgumentValueType>{rhs._value * factor};
}
template <class ResultUnit, class ArgumentUnit, class ArgumentValueType>
[[nodiscard]] constexpr inline auto
    unit_cast(const quantity<ArgumentUnit, ArgumentValueType>& rhs) noexcept
    -> std::enable_if_t<type::detect_if<ResultUnit, type::is_quantity>,
                        quantity<typename ResultUnit::unit_type, ArgumentValueType>>
{
    return unit_cast<typename ResultUnit::unit_type>(rhs);
}
// The remove_prefix function lets you get rid of the prefix of an arbitrary
// unit, by multiplying the value of the quantity with the prefix value.
// The remove_prefix function uses std::pow for the conversion. This allows
// it to remove arbitrary roots, but makes it incompatible with compile time
// evaluation. The function is still marked constexpr, to be forward compa-
// tible with a constexpr std::pow implementation.
// Furthermore, you can provide a ResultValueType for the function, in the case
// that the transformation would lead to conversion errors.
template <class ResultValueType, class ArgumentUnit, class ArgumentValueType>
[[nodiscard]] constexpr inline auto
    remove_prefix(const quantity<ArgumentUnit, ArgumentValueType>& rhs) noexcept
    -> quantity<drop_unit_prefix<ArgumentUnit>, ResultValueType>
{
    using PrefixType  = typename ArgumentUnit::prefix;
    const auto factor = runtime_expand_prefix_list<ResultValueType>(PrefixType{});
    return quantity<drop_unit_prefix<ArgumentUnit>, ResultValueType>{
        static_cast<ResultValueType>(rhs._value) * factor};
}
template <class ArgumentUnit, class ArgumentValueType>
[[nodiscard]] constexpr inline auto
    remove_prefix(const quantity<ArgumentUnit, ArgumentValueType>& rhs) noexcept
{
    return remove_prefix<ArgumentValueType>(rhs);
}
#pragma endregion
#pragma region argument dependent lookup helper
namespace casts
{
using benri::remove_prefix;
using benri::simple_cast;
using benri::unit_cast;
using benri::value_type_cast;
} // namespace casts
#pragma endregion
} // namespace benri