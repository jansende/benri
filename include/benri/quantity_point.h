#pragma once
#include <benri/impl/config.h>
#include <benri/impl/unit.h>
#include <benri/quantity.h>
#include <cmath>
#include <type_traits>

namespace benri
{
#pragma region quantity_point class
// The quantity_point type handles physical quantities. It checks the units
// in calculations and handles conversions, etc. The type in general
// should be compile time constexpr and if in some context contexpr
// cannot be used, it should still be optimized into a single variable
// of type ValueType.
template <class Unit, class ValueType = Precision>
class quantity_point
{
  public:
    template <class, class>
    friend class quantity_point;
    template <class, class>
    friend struct convert;

    using value_type = ValueType;
    using unit_type  = Unit;

  private:
    value_type _value;

  public:
    [[nodiscard]] constexpr auto value() const noexcept { return _value; }
#pragma region rule of three
    // default constructor
    constexpr quantity_point() noexcept = default;
    // value constructor
    explicit constexpr quantity_point(value_type value) noexcept : _value(value) {}
    template <class Other, class Dummy = void,
              typename = std::enable_if_t<
                  type::detect_if<Other, is_convertible_into, quantity_point>, Dummy>>
    constexpr quantity_point(const Other& rhs) noexcept :
        quantity_point(
            convert<std::remove_cv_t<Other>, std::remove_cv_t<quantity_point>>{}(rhs))
    {
    }
    template <class Other, class Dummy = void,
              typename = std::enable_if_t<
                  type::detect_if<Other, is_convertible_into, quantity_point>, Dummy>>
    constexpr quantity_point(Other&& rhs) noexcept :
        quantity_point(std::move(
            convert<std::remove_cv_t<Other>, std::remove_cv_t<quantity_point>>{}(
                std::move(rhs))))
    {
    }

    // copy constructor
    constexpr quantity_point(const quantity_point&) noexcept = default;
    // move constructor
    constexpr quantity_point(quantity_point&&) noexcept = default;
    // default destructor
    inline ~quantity_point() noexcept = default;
    // copy assignment
    constexpr quantity_point& operator=(const quantity_point&) noexcept = default;
    // move assignment
    constexpr quantity_point& operator=(quantity_point&&) noexcept = default;
#pragma endregion
#pragma region math declarations / a bit implementation
#pragma region unary operators
    [[nodiscard]] constexpr auto operator+() const noexcept
    {
        return quantity_point{_value};
    }
    [[nodiscard]] constexpr auto operator-() const noexcept
    {
        return quantity_point{value_type{-1} * _value};
    }
#pragma endregion
#pragma region addition
    constexpr auto operator+=(const quantity<unit_type, value_type>& rhs) noexcept
    {
        this->_value += rhs._value;
        return *this;
    }
    template <
        class Other, class Dummy = void,
        typename = std::enable_if_t<
            type::detect_if<Other, is_convertible_into, quantity<unit_type, value_type>>,
            Dummy>>
    constexpr auto operator+=(const Other& rhs) noexcept
    {
        return *this += convert<std::remove_cv_t<Other>,
                                std::remove_cv_t<quantity<unit_type, value_type>>>{}(rhs);
    }

    [[nodiscard]] friend constexpr auto
        operator+(const quantity<unit_type, value_type>& lhs,
                  const quantity_point&                  rhs) noexcept -> quantity_point
    {
        return quantity_point{lhs._value + rhs._value};
    }
    template <
        class Other, class Dummy = void,
        typename = std::enable_if_t<
            type::detect_if<Other, is_convertible_into, quantity<unit_type, value_type>>,
            Dummy>>
    [[nodiscard]] friend constexpr auto operator+(const Other&          lhs,
                                                  const quantity_point& rhs) noexcept
        -> quantity_point
    {
        return convert<std::remove_cv_t<Other>,
                       std::remove_cv_t<quantity<unit_type, value_type>>>{}(lhs)
               + rhs;
    }
    [[nodiscard]] friend constexpr auto
        operator+(const quantity_point&                  lhs,
                  const quantity<unit_type, value_type>& rhs) noexcept -> quantity_point
    {
        return quantity_point{lhs._value + rhs._value};
    }
    template <
        class Other, class Dummy = void,
        typename = std::enable_if_t<
            type::detect_if<Other, is_convertible_into, quantity<unit_type, value_type>>,
            Dummy>>
    [[nodiscard]] friend constexpr auto operator+(const quantity_point& lhs,
                                                  const Other&          rhs) noexcept
        -> quantity_point
    {
        return lhs
               + convert<std::remove_cv_t<Other>,
                         std::remove_cv_t<quantity<unit_type, value_type>>>{}(rhs);
    }

    constexpr auto operator-=(const quantity<unit_type, value_type>& rhs) noexcept
    {
        this->_value -= rhs._value;
        return *this;
    }
    template <
        class Other, class Dummy = void,
        typename = std::enable_if_t<
            type::detect_if<Other, is_convertible_into, quantity<unit_type, value_type>>,
            Dummy>>
    constexpr auto operator-=(const Other& rhs) noexcept
    {
        return *this -= convert<std::remove_cv_t<Other>,
                                std::remove_cv_t<quantity<unit_type, value_type>>>{}(rhs);
    }

    [[nodiscard]] friend constexpr auto operator-(const quantity_point& lhs,
                                                  const quantity_point& rhs) noexcept
    {
        return quantity<unit_type, value_type>{lhs._value - rhs._value};
    }
    template <class Other, class Dummy = void,
              typename = std::enable_if_t<
                  type::detect_if<Other, is_convertible_into, quantity_point>, Dummy>>
    [[nodiscard]] friend constexpr auto operator-(const quantity_point& lhs,
                                                  const Other&          rhs) noexcept
    {
        return lhs
               - convert<std::remove_cv_t<Other>, std::remove_cv_t<quantity_point>>{}(
                   rhs);
    }
    [[nodiscard]] friend constexpr auto
        operator-(const quantity<unit_type, value_type>& lhs,
                  const quantity_point&                  rhs) noexcept -> quantity_point
    {
        return quantity_point{lhs._value - rhs._value};
    }
    template <
        class Other, class Dummy = void,
        typename = std::enable_if_t<
            type::detect_if<Other, is_convertible_into, quantity<unit_type, value_type>>,
            Dummy>>
    [[nodiscard]] friend constexpr auto operator-(const Other&          lhs,
                                                  const quantity_point& rhs) noexcept
        -> quantity_point
    {
        return convert<std::remove_cv_t<Other>,
                       std::remove_cv_t<quantity<unit_type, value_type>>>{}(lhs)-rhs;
    }
    [[nodiscard]] friend constexpr auto
        operator-(const quantity_point&                  lhs,
                  const quantity<unit_type, value_type>& rhs) noexcept -> quantity_point
    {
        return quantity_point{lhs._value - rhs._value};
    }
    template <
        class Other, class Dummy = void,
        typename = std::enable_if_t<
            type::detect_if<Other, is_convertible_into, quantity<unit_type, value_type>>,
            Dummy>>
    [[nodiscard]] friend constexpr auto operator-(const quantity_point& lhs,
                                                  const Other&          rhs) noexcept
        -> quantity_point
    {
        return lhs
               - convert<std::remove_cv_t<Other>,
                         std::remove_cv_t<quantity<unit_type, value_type>>>{}(rhs);
    }
#pragma endregion
#pragma region comparisons
    [[nodiscard]] friend constexpr auto operator==(const quantity_point& lhs,
                                                   const quantity_point& rhs) noexcept
    {
        return lhs._value == rhs._value;
    }
    template <class Other, class Dummy = void,
              typename = std::enable_if_t<
                  type::detect_if<Other, is_convertible_into, quantity_point>, Dummy>>
    [[nodiscard]] friend constexpr auto operator==(const quantity_point& lhs,
                                                   const Other&          rhs) noexcept
    {
        return lhs
               == convert<std::remove_cv_t<Other>, std::remove_cv_t<quantity_point>>{}(
                   rhs);
    }
    [[nodiscard]] friend constexpr auto operator!=(const quantity_point& lhs,
                                                   const quantity_point& rhs) noexcept
    {
        return !(lhs == rhs);
    }
    template <class Other, class Dummy = void,
              typename = std::enable_if_t<
                  type::detect_if<Other, is_convertible_into, quantity_point>, Dummy>>
    [[nodiscard]] friend constexpr auto operator!=(const quantity_point& lhs,
                                                   const Other&          rhs) noexcept
    {
        return lhs
               != convert<std::remove_cv_t<Other>, std::remove_cv_t<quantity_point>>{}(
                   rhs);
    }
    [[nodiscard]] friend constexpr auto operator<(const quantity_point& lhs,
                                                  const quantity_point& rhs) noexcept
    {
        return lhs._value < rhs._value;
    }
    template <class Other, class Dummy = void,
              typename = std::enable_if_t<
                  type::detect_if<Other, is_convertible_into, quantity_point>, Dummy>>
    [[nodiscard]] friend constexpr auto operator<(const quantity_point& lhs,
                                                  const Other&          rhs) noexcept
    {
        return lhs < convert<std::remove_cv_t<Other>, std::remove_cv_t<quantity_point>>{}(
                   rhs);
    }
    [[nodiscard]] friend constexpr auto operator>(const quantity_point& lhs,
                                                  const quantity_point& rhs) noexcept
    {
        return rhs < lhs;
    }
    template <class Other, class Dummy = void,
              typename = std::enable_if_t<
                  type::detect_if<Other, is_convertible_into, quantity_point>, Dummy>>
    [[nodiscard]] friend constexpr auto operator>(const quantity_point& lhs,
                                                  const Other&          rhs) noexcept
    {
        return lhs > convert<std::remove_cv_t<Other>, std::remove_cv_t<quantity_point>>{}(
                   rhs);
    }
    [[nodiscard]] friend constexpr auto operator<=(const quantity_point& lhs,
                                                   const quantity_point& rhs) noexcept
    {
        return !(rhs < lhs);
    }
    template <class Other, class Dummy = void,
              typename = std::enable_if_t<
                  type::detect_if<Other, is_convertible_into, quantity_point>, Dummy>>
    [[nodiscard]] friend constexpr auto operator<=(const quantity_point& lhs,
                                                   const Other&          rhs) noexcept
    {
        return lhs
               <= convert<std::remove_cv_t<Other>, std::remove_cv_t<quantity_point>>{}(
                   rhs);
    }
    [[nodiscard]] friend constexpr auto operator>=(const quantity_point& lhs,
                                                   const quantity_point& rhs) noexcept
    {
        return !(lhs < rhs);
    }
    template <class Other, class Dummy = void,
              typename = std::enable_if_t<
                  type::detect_if<Other, is_convertible_into, quantity_point>, Dummy>>
    [[nodiscard]] friend constexpr auto operator>=(const quantity_point& lhs,
                                                   const Other&          rhs) noexcept
    {
        return lhs
               >= convert<std::remove_cv_t<Other>, std::remove_cv_t<quantity_point>>{}(
                   rhs);
    }
#pragma endregion
#pragma endregion
};
#pragma region math(rest) implementation
#pragma endregion
#pragma endregion
} // namespace benri