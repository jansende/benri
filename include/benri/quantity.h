#pragma once
#include <benri/impl/config.h>
#include <benri/impl/dimensions.h>
#include <benri/impl/unit.h>
#include <cmath>
#include <type_traits>

namespace benri
{
template <class T>
[[nodiscard]] constexpr inline auto square(T val) noexcept
{
    return val * val;
}
template <class T>
[[nodiscard]] constexpr inline auto cubic(T val) noexcept
{
    return val * val * val;
}
template <class T>
[[nodiscard]] constexpr inline auto quartic(T val) noexcept
{
    return val * val * val * val;
}
#pragma region quantity class helpers
//quantity forward declaration
template <class Unit, class ValueType>
class quantity;
//The is_quantity function checks if a given type is a quantity
//object.
template <class T>
struct is_quantity : std::false_type
{
};
template <class Unit, class ValueType>
struct is_quantity<quantity<Unit, ValueType>> : std::true_type
{
};
template <class T>
constexpr bool is_quantity_v = is_quantity<T>::value;
#pragma endregion
#pragma region quantity class
//quantity_point forward declaration
template <class Unit, class ValueType>
class quantity_point;
//The quantity type handles physical quantities. It checks the units
//in calculations and handles conversions, etc. The type in general
//should be compile time constexpr and if in some context contexpr
//cannot be used, it should still be optimized into a single variable
//of type ValueType.
template <class Unit, class ValueType = Precision>
class quantity
{
  public:
    template <class, class>
    friend class quantity;
    template <class, class>
    friend class quantity_point;

    using value_type = ValueType;
    using unit_type = Unit;

  private:
    value_type _value;

  public:
    [[nodiscard]] constexpr inline auto value() const noexcept
    {
        return _value;
    }
#pragma region casting
    //Friend declaration for the casting functions.
    template <class ResultValueType, class Unit, class ValueType>
    friend constexpr inline auto value_type_cast(const quantity<Unit, ValueType> &rhs) noexcept -> quantity<Unit, ResultValueType>;
    template <class ResultUnit, class Unit, class ValueType>
    friend constexpr inline auto simple_cast(const quantity<Unit, ValueType> &rhs) noexcept -> std::enable_if_t<std::is_same<typename ResultUnit::dimensions, typename Unit::dimensions>::value && is_unit_v<ResultUnit>, quantity<ResultUnit, ValueType>>;
    template <class ResultUnit, class Unit, class ValueType>
    friend constexpr inline auto unit_cast(const quantity<Unit, ValueType> &rhs) noexcept -> std::enable_if_t<std::is_same<typename ResultUnit::dimensions, typename Unit::dimensions>::value && is_unit_v<ResultUnit>, quantity<ResultUnit, ValueType>>;
    template <class ResultValueType, class Unit, class ValueType>
    friend constexpr inline auto remove_prefix(const quantity<Unit, ValueType> &rhs) noexcept -> quantity<remove_unit_prefix<Unit>, ResultValueType>;
#pragma endregion
#pragma region rule of three
    //default constructor
    constexpr inline quantity() noexcept = default;
    //value constructor
    explicit constexpr inline quantity(const value_type &value) noexcept : _value(value) {}
    explicit constexpr inline quantity(value_type &&value) noexcept : _value(std::move(value)) {}
    //implicit constructor
    template <class Dummy = void, typename = std::enable_if_t<is_one_v<unit_type>, Dummy>>
    constexpr inline quantity(const value_type &value) noexcept : _value(value) {}
    template <class Dummy = void, typename = std::enable_if_t<is_one_v<unit_type>, Dummy>>
    constexpr inline quantity(value_type &&value) noexcept : _value(std::move(value)) {}
    template <class rhsUnit, class Dummy = void, typename = std::enable_if_t<is_compatible_v<unit_type, rhsUnit>, Dummy>>
    constexpr inline quantity(const quantity<rhsUnit, value_type> &rhs) noexcept : _value(rhs._value) {}
    template <class rhsUnit, class Dummy = void, typename = std::enable_if_t<is_compatible_v<unit_type, rhsUnit>, Dummy>>
    constexpr inline quantity(quantity<rhsUnit, value_type> &&rhs) noexcept : _value(std::move(rhs._value)) {}

    //copy constructor
    constexpr inline quantity(const quantity &) noexcept = default;
    //move constructor
    constexpr inline quantity(quantity &&) noexcept = default;
    //default destructor
    inline ~quantity() noexcept = default;
    //copy assignment
    constexpr inline quantity &operator=(const quantity &) noexcept = default;
    //move assignment
    constexpr inline quantity &operator=(quantity &&) noexcept = default;
    //explicit type conversion
    template <class Dummy = value_type, typename = std::enable_if_t<is_one_v<unit_type>, Dummy>>
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
    constexpr inline auto operator+=(const quantity &rhs) noexcept
    {
        this->_value += rhs._value;
        return *this;
    }
    [[nodiscard]] friend constexpr inline auto operator+(const quantity &lhs, const quantity &rhs) noexcept
    {
        return quantity{lhs._value + rhs._value};
    }
    template <class rhsUnit>
    [[nodiscard]] friend constexpr inline auto operator+(const quantity &lhs, const quantity<rhsUnit, value_type> &rhs) noexcept -> std::enable_if_t<is_compatible_v<unit_type, rhsUnit>, quantity>
    {
        return quantity{lhs._value + rhs._value};
    }
    constexpr inline auto operator-=(const quantity &rhs) noexcept
    {
        this->_value -= rhs._value;
        return *this;
    }
    [[nodiscard]] friend constexpr inline auto operator-(const quantity &lhs, const quantity &rhs) noexcept
    {
        return quantity{lhs._value - rhs._value};
    }
    template <class rhsUnit>
    [[nodiscard]] friend constexpr inline auto operator-(const quantity &lhs, const quantity<rhsUnit, value_type> &rhs) noexcept -> std::enable_if_t<is_compatible_v<unit_type, rhsUnit>, quantity>
    {
        return quantity{lhs._value - rhs._value};
    }
#pragma endregion
#pragma region multiplication
    constexpr inline auto &operator*=(const value_type &rhs) noexcept
    {
        this->_value *= rhs;
        return *this;
    }
    template <class rhsUnit>
    constexpr inline auto operator*=(const quantity<rhsUnit, value_type> &rhs) noexcept -> std::enable_if_t<is_one_v<rhsUnit>, quantity &>
    {
        this->_value *= rhs.value();
        return *this;
    }
    template <class lhsUnit, class rhsUnit, class ValueType>
    friend constexpr inline auto operator*(const quantity<lhsUnit, ValueType> &lhs, const quantity<rhsUnit, ValueType> &rhs) noexcept -> quantity<multiply_units<lhsUnit, rhsUnit>, ValueType>;
    [[nodiscard]] friend constexpr inline auto operator*(const quantity &lhs, const value_type &rhs) noexcept
    {
        return quantity{lhs._value * rhs};
    }
    [[nodiscard]] friend constexpr inline auto operator*(const value_type &lhs, const quantity &rhs) noexcept
    {
        return quantity{lhs * rhs._value};
    }
    constexpr inline auto &operator/=(const value_type &rhs) noexcept
    {
        this->_value /= rhs;
        return *this;
    }
    template <class rhsUnit>
    constexpr inline auto operator/=(const quantity<rhsUnit, value_type> &rhs) noexcept -> std::enable_if_t<is_one_v<rhsUnit>, quantity &>
    {
        this->_value /= rhs.value();
        return *this;
    }
    template <class lhsUnit, class rhsUnit, class ValueType>
    friend constexpr inline auto operator/(const quantity<lhsUnit, ValueType> &lhs, const quantity<rhsUnit, ValueType> &rhs) noexcept -> quantity<divide_units<lhsUnit, rhsUnit>, ValueType>;
    [[nodiscard]] friend constexpr inline auto operator/(const quantity &lhs, const value_type &rhs) noexcept
    {
        return quantity{lhs._value / rhs};
    }
    [[nodiscard]] friend constexpr inline auto operator/(const value_type &lhs, const quantity &rhs) noexcept
    {
        return quantity<pow_unit<unit_type, std::ratio<-1>>, value_type>{lhs / rhs._value};
    }
#pragma endregion
#pragma region comparisons
    [[nodiscard]] friend constexpr inline auto operator==(const quantity &lhs, const quantity &rhs) noexcept
    {
        return lhs._value == rhs._value;
    }
    template <class rhsUnit>
    [[nodiscard]] friend constexpr inline auto operator==(const quantity &lhs, const quantity<rhsUnit, value_type> &rhs) noexcept -> std::enable_if_t<is_compatible_v<unit_type, rhsUnit>, bool>
    {
        return lhs._value == rhs._value;
    }
    [[nodiscard]] friend constexpr inline auto operator!=(const quantity &lhs, const quantity &rhs) noexcept
    {
        return !(lhs == rhs);
    }
    template <class rhsUnit>
    [[nodiscard]] friend constexpr inline auto operator!=(const quantity &lhs, const quantity<rhsUnit, value_type> &rhs) noexcept -> std::enable_if_t<is_compatible_v<unit_type, rhsUnit>, bool>
    {
        return !(lhs == rhs);
    }
    [[nodiscard]] friend constexpr inline auto operator<(const quantity &lhs, const quantity &rhs) noexcept
    {
        return lhs._value < rhs._value;
    }
    template <class rhsUnit>
    [[nodiscard]] friend constexpr inline auto operator<(const quantity &lhs, const quantity<rhsUnit, value_type> &rhs) noexcept -> std::enable_if_t<is_compatible_v<unit_type, rhsUnit>, bool>
    {
        return lhs._value < rhs._value;
    }
    [[nodiscard]] friend constexpr inline auto operator>(const quantity &lhs, const quantity &rhs) noexcept
    {
        return rhs < lhs;
    }
    template <class rhsUnit>
    [[nodiscard]] friend constexpr inline auto operator>(const quantity &lhs, const quantity<rhsUnit, value_type> &rhs) noexcept -> std::enable_if_t<is_compatible_v<unit_type, rhsUnit>, bool>
    {
        return rhs < lhs;
    }
    [[nodiscard]] friend constexpr inline auto operator<=(const quantity &lhs, const quantity &rhs) noexcept
    {
        return !(rhs < lhs);
    }
    template <class rhsUnit>
    [[nodiscard]] friend constexpr inline auto operator<=(const quantity &lhs, const quantity<rhsUnit, value_type> &rhs) noexcept -> std::enable_if_t<is_compatible_v<unit_type, rhsUnit>, bool>
    {
        return !(rhs < lhs);
    }
    [[nodiscard]] friend constexpr inline auto operator>=(const quantity &lhs, const quantity &rhs) noexcept
    {
        return !(lhs < rhs);
    }
    template <class rhsUnit>
    [[nodiscard]] friend constexpr inline auto operator>=(const quantity &lhs, const quantity<rhsUnit, value_type> &rhs) noexcept -> std::enable_if_t<is_compatible_v<unit_type, rhsUnit>, bool>
    {
        return !(lhs < rhs);
    }
#pragma endregion
#pragma endregion
};
template <class lhsUnit, class rhsUnit, class ValueType>
[[nodiscard]] constexpr inline auto operator*(const quantity<lhsUnit, ValueType> &lhs, const quantity<rhsUnit, ValueType> &rhs) noexcept -> quantity<multiply_units<lhsUnit, rhsUnit>, ValueType>
{
    return quantity<multiply_units<lhsUnit, rhsUnit>, ValueType>{lhs._value * rhs._value};
}
template <class lhsUnit, class rhsUnit, class ValueType>
[[nodiscard]] constexpr inline auto operator/(const quantity<lhsUnit, ValueType> &lhs, const quantity<rhsUnit, ValueType> &rhs) noexcept -> quantity<divide_units<lhsUnit, rhsUnit>, ValueType>
{
    return quantity<divide_units<lhsUnit, rhsUnit>, ValueType>{lhs._value / rhs._value};
}
#pragma region casting functions
//The value_type_cast function lets you cast the value_type of a quantity
//to another value_type.
template <class ResultValueType, class Unit, class ValueType>
[[nodiscard]] constexpr inline auto value_type_cast(const quantity<Unit, ValueType> &rhs) noexcept -> quantity<Unit, ResultValueType>
{
    return quantity<Unit, ResultValueType>{static_cast<ResultValueType>(rhs._value)};
}
//The simple_cast function lets you cast one quantity to another unit.
//This is done by multiplying the value of the quantity with the right
//conversion constant. The simple_cast function relies on a custom imple-
//mentation of the power function, which allows it to be evaluated at
//compile time. However, the implementation has a restriction, that it is
//not compatible with roots of units.
template <class ResultUnit, class Unit, class ValueType>
[[nodiscard]] constexpr inline auto simple_cast(const quantity<Unit, ValueType> &rhs) noexcept -> std::enable_if_t<std::is_same<typename ResultUnit::dimensions, typename Unit::dimensions>::value && is_unit_v<ResultUnit>, quantity<ResultUnit, ValueType>>
{
    constexpr auto factor = impl::multiply_elements<ValueType, divide_lists<typename Unit::prefix, typename ResultUnit::prefix>>;
    return quantity<ResultUnit, ValueType>{rhs._value * factor};
}
template <class ResultUnit, class Unit, class ValueType>
[[nodiscard]] constexpr inline auto simple_cast(const quantity<Unit, ValueType> &rhs) noexcept -> std::enable_if_t<is_quantity_v<ResultUnit>, quantity<typename ResultUnit::unit_type, ValueType>>
{
    return simple_cast<typename ResultUnit::unit_type>(rhs);
}
//The unit_cast function lets you cast one quantity to another unit.
//This is done by multiplying the value of the quantity with the right
//conversion constant. The unit_cast function uses std::pow for the
//conversion. This allows it to calculate arbitrary roots, but makes
//it incompatible with compile time evaluation. The function is still
//marked constexpr, to be forward compatible with a constexpr std::pow
//implementation.
template <class ResultUnit, class Unit, class ValueType>
[[nodiscard]] constexpr inline auto unit_cast(const quantity<Unit, ValueType> &rhs) noexcept -> std::enable_if_t<std::is_same<typename ResultUnit::dimensions, typename Unit::dimensions>::value && is_unit_v<ResultUnit>, quantity<ResultUnit, ValueType>>
{
    const auto factor = impl::runtime_multiply_elements<ValueType>(divide_lists<typename Unit::prefix, typename ResultUnit::prefix>{});
    return quantity<ResultUnit, ValueType>{rhs._value * factor};
}
template <class ResultUnit, class Unit, class ValueType>
[[nodiscard]] constexpr inline auto unit_cast(const quantity<Unit, ValueType> &rhs) noexcept -> std::enable_if_t<is_quantity_v<ResultUnit>, quantity<typename ResultUnit::unit_type, ValueType>>
{
    return unit_cast<typename ResultUnit::unit_type>(rhs);
}
//The remove_prefix function lets you get rid of the prefix of an arbitrary
//unit, by multiplying the value of the quantity with the prefix value.
//The remove_prefix function uses std::pow for the conversion. This allows
//it to remove arbitrary roots, but makes it incompatible with compile time
//evaluation. The function is still marked constexpr, to be forward compa-
//tible with a constexpr std::pow implementation.
//Furthermore, you can provide a ResultValueType for the function, in the case that
//the transformation would lead to conversion errors.
template <class ResultValueType, class Unit, class ValueType>
[[nodiscard]] constexpr inline auto remove_prefix(const quantity<Unit, ValueType> &rhs) noexcept -> quantity<remove_unit_prefix<Unit>, ResultValueType>
{
    using PrefixType = typename Unit::prefix;
    const auto factor = impl::runtime_multiply_elements<ResultValueType>(PrefixType{});
    return quantity<remove_unit_prefix<Unit>, ResultValueType>{static_cast<ResultValueType>(rhs._value) * factor};
}
template <class Unit, class ValueType>
[[nodiscard]] constexpr inline auto remove_prefix(const quantity<Unit, ValueType> &rhs) noexcept
{
    return remove_prefix<ValueType>(rhs);
}
#pragma endregion
} // namespace benri