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
struct is_quantity_point : std::false_type
{
};
template <class Unit, class ValueType>
struct is_quantity_point<quantity_point<Unit, ValueType>> : std::true_type
{
};
template <class T>
constexpr bool is_quantity_point_v = is_quantity_point<T>::value;
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
    template <class Unit, class ValueType>
    friend class quantity_point;
    
    using value_type = ValueType;
    using unit_type = Unit;

  private:
    value_type _value;

  public:
    constexpr auto value() const
    {
        return _value;
    }
#pragma region casting
    //Friend declaration for the casting functions.
    template <class ResultValueType, class Unit, class ValueType>
    friend constexpr auto value_type_cast(const quantity_point<Unit, ValueType> &rhs) -> quantity_point<Unit, ResultValueType>;
    template <class ResultUnit, class Unit, class ValueType>
    friend constexpr auto simple_cast(const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<typename ResultUnit::dimensions, typename Unit::dimensions> && is_unit_v<ResultUnit>, quantity_point<ResultUnit, ValueType>>;
    template <class ResultUnit, class Unit, class ValueType>
    friend constexpr auto unit_cast(const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<typename ResultUnit::dimensions, typename Unit::dimensions> && is_unit_v<ResultUnit>, quantity_point<ResultUnit, ValueType>>;
    template <class ResultValueType, class Unit, class ValueType>
    friend constexpr auto remove_prefix(const quantity_point<Unit, ValueType> &rhs) -> quantity_point<remove_unit_prefix<Unit>, ResultValueType>;
#pragma endregion
#pragma region rule of three
    //default constructor
    constexpr quantity_point() = default;
    //value constructor
    explicit constexpr quantity_point(value_type value) : _value(value) {}
    //copy constructor
    constexpr quantity_point(const quantity_point &) = default;
    //move constructor
    constexpr quantity_point(quantity_point &&) = default;
    //default constructor
    ~quantity_point() = default;
    //copy assignment
    constexpr quantity_point &operator=(const quantity_point &) = default;
    //move assignment
    constexpr quantity_point &operator=(quantity_point &&) = default;
#pragma endregion
#pragma region math declarations / a bit implementation
#pragma region unary operators
    constexpr auto operator+() const
    {
        return quantity_point{_value};
    }
    constexpr auto operator-() const
    {
        return quantity_point{value_type{-1} * _value};
    }
#pragma endregion
#pragma region addition
    constexpr auto operator+=(const quantity<unit_type, value_type> &rhs)
    {
        this->_value += rhs._value;
        return *this;
    }

    friend constexpr auto operator+(const quantity<unit_type, value_type> &lhs, const quantity_point &rhs)
    {
        return quantity_point{lhs._value + rhs._value};
    }
    friend constexpr auto operator+(const quantity_point &lhs, const quantity<unit_type, value_type> &rhs)
    {
        return quantity_point{lhs._value + rhs._value};
    }

    constexpr auto operator-=(const quantity<unit_type, value_type> &rhs)
    {
        this->_value -= rhs._value;
        return *this;
    }

    friend constexpr auto operator-(const quantity_point &lhs, const quantity_point &rhs)
    {
        return quantity<unit_type, value_type>{lhs._value - rhs._value};
    }
    friend constexpr auto operator-(const quantity<unit_type, value_type> &lhs, const quantity_point &rhs)
    {
        return quantity_point{lhs._value - rhs._value};
    }
    friend constexpr auto operator-(const quantity_point &lhs, const quantity<unit_type, value_type> &rhs)
    {
        return quantity_point{lhs._value - rhs._value};
    }
#pragma endregion
#pragma region comparisons
    friend constexpr auto operator==(const quantity_point &lhs, const quantity_point &rhs)
    {
        return lhs._value == rhs._value;
    }
    friend constexpr auto operator!=(const quantity_point &lhs, const quantity_point &rhs)
    {
        return !(lhs == rhs);
    }
    friend constexpr auto operator<(const quantity_point &lhs, const quantity_point &rhs)
    {
        return lhs._value < rhs._value;
    }
    friend constexpr auto operator>(const quantity_point &lhs, const quantity_point &rhs)
    {
        return rhs < lhs;
    }
    friend constexpr auto operator<=(const quantity_point &lhs, const quantity_point &rhs)
    {
        return !(rhs < lhs);
    }
    friend constexpr auto operator>=(const quantity_point &lhs, const quantity_point &rhs)
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
template <class ResultValueType, class Unit, class ValueType>
constexpr auto value_type_cast(const quantity_point<Unit, ValueType> &rhs) -> quantity_point<Unit, ResultValueType>
{
    return quantity_point<Unit, ResultValueType>{static_cast<ResultValueType>(rhs._value)};
}
//The simple_cast function lets you cast one quantity_point to another unit.
//This is done by multiplying the value of the quantity_point with the right
//conversion constant. The simple_cast function relies on a custom imple-
//mentation of the power function, which allows it to be evaluated at
//compile time. However, the implementation has a restriction, that it is
//not compatible with roots of units.
template <class ResultUnit, class Unit, class ValueType>
constexpr auto simple_cast(const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<typename ResultUnit::dimensions, typename Unit::dimensions> && is_unit_v<ResultUnit>, quantity_point<ResultUnit, ValueType>>
{
    //calculation
    return quantity_point<ResultUnit, ValueType>{rhs._value * impl::multiply_elements<ValueType, divide_lists<typename Unit::prefix, typename ResultUnit::prefix>>};
}
template <class ResultUnit, class Unit, class ValueType>
constexpr auto simple_cast(const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<is_quantity_v<ResultUnit>, quantity_point<typename ResultUnit::unit_type, ValueType>>
{
    //calculation
    return simple_cast<typename ResultUnit::unit_type>(rhs);
}
//The unit_cast function lets you cast one quantity_point to another unit.
//This is done by multiplying the value of the quantity_point with the right
//conversion constant. The unit_cast function uses std::pow for the
//conversion. This allows it to calculate arbitrary roots, but makes
//it incompatible with compile time evaluation. The function is still
//marked constexpr, to be forward compatible with a constexpr std::pow
//implementation.
template <class ResultUnit, class Unit, class ValueType>
constexpr auto unit_cast(const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<typename ResultUnit::dimensions, typename Unit::dimensions> && is_unit_v<ResultUnit>, quantity_point<ResultUnit, ValueType>>
{
    //calculation
    return quantity_point<ResultUnit, ValueType>{rhs._value * impl::runtime_multiply_elements<ValueType>(divide_lists<typename Unit::prefix, typename ResultUnit::prefix>{})};
}
template <class ResultUnit, class Unit, class ValueType>
constexpr auto unit_cast(const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<is_quantity_v<ResultUnit>, quantity_point<typename ResultUnit::unit_type, ValueType>>
{
    //calculation
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
template <class ResultValueType, class Unit, class ValueType>
constexpr auto remove_prefix(const quantity_point<Unit, ValueType> &rhs) -> quantity_point<remove_unit_prefix<Unit>, ResultValueType>
{
    //calculation
    using PrefixType = typename Unit::prefix;
    return quantity_point<remove_unit_prefix<Unit>, ResultValueType>{static_cast<ResultValueType>(rhs._value) * impl::runtime_multiply_elements<ResultValueType>(PrefixType{})};
}
template <class Unit, class ValueType>
constexpr auto remove_prefix(const quantity_point<Unit, ValueType> &rhs)
{
    return remove_prefix<ValueType>(rhs);
}
#pragma endregion
} // namespace benri