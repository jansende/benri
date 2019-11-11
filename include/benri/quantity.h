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

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnon-template-friend"
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
#pragma GCC diagnostic pop

  private:
    value_type _value;

  public:
    [[nodiscard]] constexpr inline auto value() const noexcept { return _value; }
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
} // namespace benri