#pragma once
#include <benri/quantity.h>
#include <benri/impl/config.h>
#include <benri/impl/dimensions.h>
#include <benri/impl/unit.h>
#include <cmath>
#include <type_traits>

namespace benri
{
#pragma region quantity_point class helpers
//quantity_point forward declaration
template <class Unit, class ValueType>
class quantity_point;
//The is_quantity_point function checks if a given type is a quantity_point
//object.
template <class T>
using is_quantity_point = typename std::enable_if<std::is_same<T, quantity_point<typename T::unit_type, typename T::value_type>>::value>::type;
#pragma endregion
#pragma region quantity_point class
//The quantity_point type handles physical quantities. It checks the units
//in calculations and handles conversions, etc. The type in general
//should be compile time constexpr and if in some context contexpr
//cannot be used, it should still be optimized into a single variable
//of type ValueType.
template <class Unit, class ValueType = Precision>
class quantity_point
{
public:
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
    template <class ResultValueType, class ArgumentUnit, class ArgumentValueType>
    friend constexpr inline auto value_type_cast(const quantity_point<ArgumentUnit, ArgumentValueType> &rhs) noexcept -> quantity_point<ArgumentUnit, ResultValueType>;
    template <class ResultUnit, class ArgumentUnit, class ArgumentValueType>
    friend constexpr inline auto simple_cast(const quantity_point<ArgumentUnit, ArgumentValueType> &rhs) noexcept -> std::enable_if_t<std::is_same<typename ResultUnit::dimensions, typename ArgumentUnit::dimensions>::value && type::detect_if<ResultUnit, type::is_unit>, quantity_point<ResultUnit, ArgumentValueType>>;
    template <class ResultUnit, class ArgumentUnit, class ArgumentValueType>
    friend constexpr inline auto unit_cast(const quantity_point<ArgumentUnit, ArgumentValueType> &rhs) noexcept -> std::enable_if_t<std::is_same<typename ResultUnit::dimensions, typename ArgumentUnit::dimensions>::value && type::detect_if<ResultUnit, type::is_unit>, quantity_point<ResultUnit, ArgumentValueType>>;
    template <class ResultValueType, class ArgumentUnit, class ArgumentValueType>
    friend constexpr inline auto remove_prefix(const quantity_point<ArgumentUnit, ArgumentValueType> &rhs) noexcept -> quantity_point<remove_unit_prefix<ArgumentUnit>, ResultValueType>;
#pragma endregion
#pragma region rule of three
    //default constructor
    constexpr inline quantity_point() noexcept = default;
    //value constructor
    explicit constexpr inline quantity_point(value_type value) noexcept : _value(value) {}
    //copy constructor
    constexpr inline quantity_point(const quantity_point &) noexcept = default;
    //move constructor
    constexpr inline quantity_point(quantity_point &&) noexcept = default;
    //default destructor
    inline ~quantity_point() noexcept = default;
    //copy assignment
    constexpr inline quantity_point &operator=(const quantity_point &) noexcept = default;
    //move assignment
    constexpr inline quantity_point &operator=(quantity_point &&) noexcept = default;
#pragma endregion
#pragma region math declarations / a bit implementation
#pragma region unary operators
    [[nodiscard]] constexpr inline auto operator+() const noexcept
    {
        return quantity_point{_value};
    }
    [[nodiscard]] constexpr inline auto operator-() const noexcept
    {
        return quantity_point{value_type{-1} * _value};
    }
#pragma endregion
#pragma region addition
    constexpr inline auto operator+=(const quantity<unit_type, value_type> &rhs) noexcept
    {
        this->_value += rhs._value;
        return *this;
    }

    [[nodiscard]] friend constexpr inline auto operator+(const quantity<unit_type, value_type> &lhs, const quantity_point &rhs) noexcept -> quantity_point
    {
        return quantity_point{lhs._value + rhs._value};
    }
    [[nodiscard]] friend constexpr inline auto operator+(const quantity_point &lhs, const quantity<unit_type, value_type> &rhs) noexcept -> quantity_point
    {
        return quantity_point{lhs._value + rhs._value};
    }

    constexpr inline auto operator-=(const quantity<unit_type, value_type> &rhs) noexcept
    {
        this->_value -= rhs._value;
        return *this;
    }

    [[nodiscard]] friend constexpr inline auto operator-(const quantity_point &lhs, const quantity_point &rhs) noexcept
    {
        return quantity<unit_type, value_type>{lhs._value - rhs._value};
    }
    [[nodiscard]] friend constexpr inline auto operator-(const quantity<unit_type, value_type> &lhs, const quantity_point &rhs) noexcept -> quantity_point
    {
        return quantity_point{lhs._value - rhs._value};
    }
    [[nodiscard]] friend constexpr inline auto operator-(const quantity_point &lhs, const quantity<unit_type, value_type> &rhs) noexcept -> quantity_point
    {
        return quantity_point{lhs._value - rhs._value};
    }
#pragma endregion
#pragma region comparisons
    [[nodiscard]] friend constexpr inline auto operator==(const quantity_point &lhs, const quantity_point &rhs) noexcept
    {
        return lhs._value == rhs._value;
    }
    [[nodiscard]] friend constexpr inline auto operator!=(const quantity_point &lhs, const quantity_point &rhs) noexcept
    {
        return !(lhs == rhs);
    }
    [[nodiscard]] friend constexpr inline auto operator<(const quantity_point &lhs, const quantity_point &rhs) noexcept
    {
        return lhs._value < rhs._value;
    }
    [[nodiscard]] friend constexpr inline auto operator>(const quantity_point &lhs, const quantity_point &rhs) noexcept
    {
        return rhs < lhs;
    }
    [[nodiscard]] friend constexpr inline auto operator<=(const quantity_point &lhs, const quantity_point &rhs) noexcept
    {
        return !(rhs < lhs);
    }
    [[nodiscard]] friend constexpr inline auto operator>=(const quantity_point &lhs, const quantity_point &rhs) noexcept
    {
        return !(lhs < rhs);
    }
#pragma endregion
#pragma endregion
};
#pragma region math(rest) implementation
#pragma endregion
#pragma endregion
#pragma region casting functions
//The value_type_cast function lets you cast the value_type of a quantity_point
//to another value_type.
template <class ResultValueType, class ArgumentUnit, class ArgumentValueType>
[[nodiscard]] constexpr inline auto value_type_cast(const quantity_point<ArgumentUnit, ArgumentValueType> &rhs) noexcept -> quantity_point<ArgumentUnit, ResultValueType>
{
    return quantity_point<ArgumentUnit, ResultValueType>{static_cast<ResultValueType>(rhs._value)};
}
//The simple_cast function lets you cast one quantity_point to another unit.
//This is done by multiplying the value of the quantity_point with the right
//conversion constant. The simple_cast function relies on a custom imple-
//mentation of the power function, which allows it to be evaluated at
//compile time. However, the implementation has a restriction, that it is
//not compatible with roots of units.
template <class ResultUnit, class ArgumentUnit, class ArgumentValueType>
[[nodiscard]] constexpr inline auto simple_cast(const quantity_point<ArgumentUnit, ArgumentValueType> &rhs) noexcept -> std::enable_if_t<std::is_same<typename ResultUnit::dimensions, typename ArgumentUnit::dimensions>::value && type::detect_if<ResultUnit, type::is_unit>, quantity_point<ResultUnit, ArgumentValueType>>
{
    constexpr auto factor = type::multiply_elements<ArgumentValueType, divide_lists<typename ArgumentUnit::prefix, typename ResultUnit::prefix>>;
    return quantity_point<ResultUnit, ArgumentValueType>{rhs._value * factor};
}
template <class ResultUnit, class ArgumentUnit, class ArgumentValueType>
[[nodiscard]] constexpr inline auto simple_cast(const quantity_point<ArgumentUnit, ArgumentValueType> &rhs) noexcept -> std::enable_if_t<type::detect_if<ResultUnit, is_quantity>, quantity_point<typename ResultUnit::unit_type, ArgumentValueType>>
{
    return simple_cast<typename ResultUnit::unit_type>(rhs);
}
//The unit_cast function lets you cast one quantity_point to another unit.
//This is done by multiplying the value of the quantity_point with the right
//conversion constant. The unit_cast function uses std::pow for the
//conversion. This allows it to calculate arbitrary roots, but makes
//it incompatible with compile time evaluation. The function is still
//marked constexpr, to be forward compatible with a constexpr std::pow
//implementation.
template <class ResultUnit, class ArgumentUnit, class ArgumentValueType>
[[nodiscard]] constexpr inline auto unit_cast(const quantity_point<ArgumentUnit, ArgumentValueType> &rhs) noexcept -> std::enable_if_t<std::is_same<typename ResultUnit::dimensions, typename ArgumentUnit::dimensions>::value && type::detect_if<ResultUnit, type::is_unit>, quantity_point<ResultUnit, ArgumentValueType>>
{
    const auto factor = type::runtime_multiply_elements<ArgumentValueType>(divide_lists<typename ArgumentUnit::prefix, typename ResultUnit::prefix>{});
    return quantity_point<ResultUnit, ArgumentValueType>{rhs._value * factor};
}
template <class ResultUnit, class ArgumentUnit, class ArgumentValueType>
[[nodiscard]] constexpr inline auto unit_cast(const quantity_point<ArgumentUnit, ArgumentValueType> &rhs) noexcept -> std::enable_if_t<type::detect_if<ResultUnit, is_quantity>, quantity_point<typename ResultUnit::unit_type, ArgumentValueType>>
{
    return unit_cast<typename ResultUnit::unit_type>(rhs);
}
//The remove_prefix function lets you get rid of the prefix of an arbitrary
//unit, by multiplying the value of the quantity_point with the prefix value.
//The remove_prefix function uses std::pow for the conversion. This allows
//it to remove arbitrary roots, but makes it incompatible with compile time
//evaluation. The function is still marked constexpr, to be forward compa-
//tible with a constexpr std::pow implementation.
//Furthermore, you can provide a ResultValueType for the function, in the case that
//the transformation would lead to conversion errors.
template <class ResultValueType, class ArgumentUnit, class ArgumentValueType>
[[nodiscard]] constexpr inline auto remove_prefix(const quantity_point<ArgumentUnit, ArgumentValueType> &rhs) noexcept -> quantity_point<remove_unit_prefix<ArgumentUnit>, ResultValueType>
{
    using PrefixType = typename ArgumentUnit::prefix;
    const auto factor = type::runtime_multiply_elements<ResultValueType>(PrefixType{});
    return quantity_point<remove_unit_prefix<ArgumentUnit>, ResultValueType>{static_cast<ResultValueType>(rhs._value) * factor};
}
template <class ArgumentUnit, class ArgumentValueType>
[[nodiscard]] constexpr inline auto remove_prefix(const quantity_point<ArgumentUnit, ArgumentValueType> &rhs) noexcept
{
    return remove_prefix<ArgumentValueType>(rhs);
}
#pragma endregion
} // namespace benri