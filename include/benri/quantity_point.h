#pragma once
//Windows headers might define the pascal macro. This conflicts with
//our pascal unit. Therefore, we save the content in BENRI_PASCAL and
//remove the macro.
#ifdef pascal
#define BENRI_PASCAL pascal
#undef pascal
#endif

#include <cmath>
#include <benri/units/dimensions.h>
#include <benri/unit.h>
#include <benri/config.h>
#include <benri/quantity.h>

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
    constexpr quantity_point(ValueType value) : _value(value) {}
    using value_type = ValueType;
    using unit_type = Unit;

  private:
    ValueType _value;

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
    friend constexpr auto simple_cast(const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<typename ResultUnit::system, typename Unit::system> && impl::is_equivalent_list_v<typename ResultUnit::dimensions, typename Unit::dimensions>, quantity_point<ResultUnit, ValueType>>;
    template <class ResultUnit, class Unit, class ValueType>
    friend constexpr auto unit_cast(const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<typename ResultUnit::system, typename Unit::system> && impl::is_equivalent_list_v<typename ResultUnit::dimensions, typename Unit::dimensions>, quantity_point<ResultUnit, ValueType>>;
    template <class ResultValueType, class Unit, class ValueType>
    friend constexpr auto remove_prefix(const quantity_point<Unit, ValueType> &rhs) -> quantity_point<no_prefix_unit_t<Unit>, ResultValueType>;
#pragma endregion
#pragma region rule of three
    //default constructor
    constexpr quantity_point() = default;
    //copy constructor
    constexpr quantity_point(const quantity_point &) = default;
    //move constructor
    constexpr quantity_point(quantity_point &&) = default;
    //default constructor
    ~quantity_point() = default;
    //copy assignment
    constexpr quantity_point& operator=(const quantity_point&) = default;
    template <class rhsUnit, class ValueType>
    constexpr auto operator=(const quantity_point<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<unit_type, rhsUnit>, quantity_point &>
    {
        _value = rhs._value;
        return *this;
    }
    constexpr auto operator=(const value_type &rhs) noexcept
    {
        static_assert(is_one_v<unit_type>, "You can only assign value_types to dimensionless quantities without prefix.");
        _value = rhs;
        return *this;
    }
    //move assignment
    constexpr quantity_point& operator=(quantity_point&&) = default;
    template <class rhsUnit, class ValueType>
    constexpr auto operator=(quantity_point<rhsUnit, ValueType> &&rhs) -> std::enable_if_t<is_equivalent_v<unit_type, rhsUnit>, quantity_point &>
    {
        _value = std::move(rhs._value);
        return *this;
    }
    constexpr auto operator=(value_type &&rhs) noexcept
    {
        static_assert(is_one_v<unit_type>, "You can only assign value_types to dimensionless quantities without prefix.");
        _value = std::move(rhs);
        return *this;
    }
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
    template <class lhsUnit, class rhsUnit, class ValueType>
    friend constexpr auto operator+=(quantity_point<lhsUnit, ValueType> &lhs, const quantity<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit> || is_compatible_v<lhsUnit, rhsUnit>, quantity_point<lhsUnit, ValueType> &>;
    template <class lhsUnit, class ValueType>
    friend constexpr auto operator+=(quantity_point<lhsUnit, ValueType> &lhs, const ValueType &rhs) -> std::enable_if_t<is_one_v<lhsUnit>, quantity_point<lhsUnit, ValueType> &>;
    template <class lhsUnit, class rhsUnit, class ValueType>
    friend constexpr auto operator+(const quantity<lhsUnit, ValueType> &lhs, const quantity_point<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit> || is_compatible_v<lhsUnit, rhsUnit>, quantity_point<lhsUnit, ValueType>>;
    template <class lhsUnit, class rhsUnit, class ValueType>
    friend constexpr auto operator+(const quantity_point<lhsUnit, ValueType> &lhs, const quantity<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit> || is_compatible_v<lhsUnit, rhsUnit>, quantity_point<lhsUnit, ValueType>>;
    template <class Unit, class ValueType>
    friend constexpr auto operator+(const ValueType &lhs, const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<is_one_v<Unit>, quantity_point<Unit, ValueType>>;
    template <class Unit, class ValueType>
    friend constexpr auto operator+(const quantity_point<Unit, ValueType> &lhs, const ValueType &rhs) -> std::enable_if_t<is_one_v<Unit>, quantity_point<Unit, ValueType>>;
    template <class lhsUnit, class rhsUnit, class ValueType>
    friend constexpr auto operator-=(quantity_point<lhsUnit, ValueType> &lhs, const quantity<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit> || is_compatible_v<lhsUnit, rhsUnit>, quantity_point<lhsUnit, ValueType> &>;
    template <class lhsUnit, class ValueType>
    friend constexpr auto operator-=(quantity_point<lhsUnit, ValueType> &lhs, const ValueType &rhs) -> std::enable_if_t<is_one_v<lhsUnit>, quantity_point<lhsUnit, ValueType> &>;
    template <class lhsUnit, class rhsUnit, class ValueType>
    friend constexpr auto operator-(const quantity_point<lhsUnit, ValueType> &lhs, const quantity_point<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit>, quantity<lhsUnit, ValueType>>;
    template <class lhsUnit, class rhsUnit, class ValueType>
    friend constexpr auto operator-(const quantity<lhsUnit, ValueType> &lhs, const quantity_point<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit> || is_compatible_v<lhsUnit, rhsUnit>, quantity_point<lhsUnit, ValueType>>;
    template <class lhsUnit, class rhsUnit, class ValueType>
    friend constexpr auto operator-(const quantity_point<lhsUnit, ValueType> &lhs, const quantity<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit> || is_compatible_v<lhsUnit, rhsUnit>, quantity_point<lhsUnit, ValueType>>;
    template <class Unit, class ValueType>
    friend constexpr auto operator-(const ValueType &lhs, const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<is_one_v<Unit>, quantity_point<Unit, ValueType>>;
    template <class Unit, class ValueType>
    friend constexpr auto operator-(const quantity_point<Unit, ValueType> &lhs, const ValueType &rhs) -> std::enable_if_t<is_one_v<Unit>, quantity_point<Unit, ValueType>>;
#pragma endregion
#pragma region comparisons
    template <class lhsUnit, class rhsUnit, class ValueType>
    friend constexpr auto operator==(const quantity_point<lhsUnit, ValueType> &lhs, const quantity_point<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit>, bool>;
    template <class Unit, class ValueType>
    friend constexpr auto operator==(const ValueType &lhs, const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<is_one_v<Unit>, bool>;
    template <class Unit, class ValueType>
    friend constexpr auto operator==(const quantity_point<Unit, ValueType> &lhs, const ValueType &rhs) -> std::enable_if_t<is_one_v<Unit>, bool>;
    template <class lhsUnit, class rhsUnit, class ValueType>
    friend constexpr auto operator!=(const quantity_point<lhsUnit, ValueType> &lhs, const quantity_point<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit>, bool>;
    template <class Unit, class ValueType>
    friend constexpr auto operator!=(const ValueType &lhs, const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<is_one_v<Unit>, bool>;
    template <class Unit, class ValueType>
    friend constexpr auto operator!=(const quantity_point<Unit, ValueType> &lhs, const ValueType &rhs) -> std::enable_if_t<is_one_v<Unit>, bool>;
    template <class lhsUnit, class rhsUnit, class ValueType>
    friend constexpr auto operator<(const quantity_point<lhsUnit, ValueType> &lhs, const quantity_point<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit>, bool>;
    template <class Unit, class ValueType>
    friend constexpr auto operator<(const ValueType &lhs, const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<is_one_v<Unit>, bool>;
    template <class Unit, class ValueType>
    friend constexpr auto operator<(const quantity_point<Unit, ValueType> &lhs, const ValueType &rhs) -> std::enable_if_t<is_one_v<Unit>, bool>;
    template <class lhsUnit, class rhsUnit, class ValueType>
    friend constexpr auto operator>(const quantity_point<lhsUnit, ValueType> &lhs, const quantity_point<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit>, bool>;
    template <class Unit, class ValueType>
    friend constexpr auto operator>(const ValueType &lhs, const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<is_one_v<Unit>, bool>;
    template <class Unit, class ValueType>
    friend constexpr auto operator>(const quantity_point<Unit, ValueType> &lhs, const ValueType &rhs) -> std::enable_if_t<is_one_v<Unit>, bool>;
    template <class lhsUnit, class rhsUnit, class ValueType>
    friend constexpr auto operator<=(const quantity_point<lhsUnit, ValueType> &lhs, const quantity_point<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit>, bool>;
    template <class Unit, class ValueType>
    friend constexpr auto operator<=(const ValueType &lhs, const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<is_one_v<Unit>, bool>;
    template <class Unit, class ValueType>
    friend constexpr auto operator<=(const quantity_point<Unit, ValueType> &lhs, const ValueType &rhs) -> std::enable_if_t<is_one_v<Unit>, bool>;
    template <class lhsUnit, class rhsUnit, class ValueType>
    friend constexpr auto operator>=(const quantity_point<lhsUnit, ValueType> &lhs, const quantity_point<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit>, bool>;
    template <class Unit, class ValueType>
    friend constexpr auto operator>=(const ValueType &lhs, const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<is_one_v<Unit>, bool>;
    template <class Unit, class ValueType>
    friend constexpr auto operator>=(const quantity_point<Unit, ValueType> &lhs, const ValueType &rhs) -> std::enable_if_t<is_one_v<Unit>, bool>;
#pragma endregion
#pragma endregion
};
#pragma region math(rest) implementation
#pragma region addition
template <class lhsUnit, class rhsUnit, class ValueType>
constexpr auto operator+=(quantity_point<lhsUnit, ValueType> &lhs, const quantity<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit> || is_compatible_v<lhsUnit, rhsUnit>, quantity_point<lhsUnit, ValueType> &>
{
    lhs._value += rhs._value;
    return lhs;
}
template <class lhsUnit, class ValueType>
constexpr auto operator+=(quantity_point<lhsUnit, ValueType> &lhs, const ValueType &rhs) -> std::enable_if_t<is_one_v<lhsUnit>, quantity_point<lhsUnit, ValueType> &>
{
    lhs._value += rhs;
    return lhs;
}
template <class lhsUnit, class rhsUnit, class ValueType>
constexpr auto operator+(const quantity<lhsUnit, ValueType> &lhs, const quantity_point<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit> || is_compatible_v<lhsUnit, rhsUnit>, quantity_point<lhsUnit, ValueType>>
{
    return quantity_point<lhsUnit, ValueType>{lhs._value + rhs._value};
}
template <class lhsUnit, class rhsUnit, class ValueType>
constexpr auto operator+(const quantity_point<lhsUnit, ValueType> &lhs, const quantity<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit> || is_compatible_v<lhsUnit, rhsUnit>, quantity_point<lhsUnit, ValueType>>
{
    return quantity_point<lhsUnit, ValueType>{lhs._value + rhs._value};
}
template <class Unit, class ValueType>
constexpr auto operator+(const ValueType &lhs, const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<is_one_v<Unit>, quantity_point<Unit, ValueType>>
{
    return quantity_point<Unit, ValueType>{lhs + rhs._value};
}
template <class Unit, class ValueType>
constexpr auto operator+(const quantity_point<Unit, ValueType> &lhs, const ValueType &rhs) -> std::enable_if_t<is_one_v<Unit>, quantity_point<Unit, ValueType>>
{
    return quantity_point<Unit, ValueType>{lhs._value + rhs};
}
template <class lhsUnit, class rhsUnit, class ValueType>
constexpr auto operator-=(quantity_point<lhsUnit, ValueType> &lhs, const quantity<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit> || is_compatible_v<lhsUnit, rhsUnit>, quantity_point<lhsUnit, ValueType> &>
{
    lhs._value -= rhs._value;
    return lhs;
}
template <class lhsUnit, class ValueType>
constexpr auto operator-=(quantity_point<lhsUnit, ValueType> &lhs, const ValueType &rhs) -> std::enable_if_t<is_one_v<lhsUnit>, quantity_point<lhsUnit, ValueType> &>
{
    lhs._value -= rhs;
    return lhs;
}
template <class lhsUnit, class rhsUnit, class ValueType>
constexpr auto operator-(const quantity_point<lhsUnit, ValueType> &lhs, const quantity_point<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit>, quantity<lhsUnit, ValueType>>
{
    return quantity<lhsUnit, ValueType>{lhs._value - rhs._value};
}
template <class lhsUnit, class rhsUnit, class ValueType>
constexpr auto operator-(const quantity<lhsUnit, ValueType> &lhs, const quantity_point<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit> || is_compatible_v<lhsUnit, rhsUnit>, quantity_point<lhsUnit, ValueType>>
{
    return quantity_point<lhsUnit, ValueType>{lhs._value - rhs._value};
}
template <class lhsUnit, class rhsUnit, class ValueType>
constexpr auto operator-(const quantity_point<lhsUnit, ValueType> &lhs, const quantity<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit> || is_compatible_v<lhsUnit, rhsUnit>, quantity_point<lhsUnit, ValueType>>
{
    return quantity_point<lhsUnit, ValueType>{lhs._value - rhs._value};
}
template <class Unit, class ValueType>
constexpr auto operator-(const ValueType &lhs, const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<is_one_v<Unit>, quantity_point<Unit, ValueType>>
{
    return quantity_point<Unit, ValueType>{lhs - rhs._value};
}
template <class Unit, class ValueType>
constexpr auto operator-(const quantity_point<Unit, ValueType> &lhs, const ValueType &rhs) -> std::enable_if_t<is_one_v<Unit>, quantity_point<Unit, ValueType>>
{
    return quantity_point<Unit, ValueType>{lhs._value - rhs};
}
#pragma endregion
#pragma region comparisons
template <class lhsUnit, class rhsUnit, class ValueType>
constexpr auto operator==(const quantity_point<lhsUnit, ValueType> &lhs, const quantity_point<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit>, bool>
{
    return lhs._value == rhs._value;
}
template <class Unit, class ValueType>
constexpr auto operator==(const ValueType &lhs, const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<is_one_v<Unit>, bool>
{
    return lhs == rhs._value;
}
template <class Unit, class ValueType>
constexpr auto operator==(const quantity_point<Unit, ValueType> &lhs, const ValueType &rhs) -> std::enable_if_t<is_one_v<Unit>, bool>
{
    return lhs._value == rhs;
}
template <class lhsUnit, class rhsUnit, class ValueType>
constexpr auto operator!=(const quantity_point<lhsUnit, ValueType> &lhs, const quantity_point<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit>, bool>
{
    return !(lhs == rhs);
}
template <class Unit, class ValueType>
constexpr auto operator!=(const ValueType &lhs, const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<is_one_v<Unit>, bool>
{
    return !(lhs == rhs);
}
template <class Unit, class ValueType>
constexpr auto operator!=(const quantity_point<Unit, ValueType> &lhs, const ValueType &rhs) -> std::enable_if_t<is_one_v<Unit>, bool>
{
    return !(lhs == rhs);
}
template <class lhsUnit, class rhsUnit, class ValueType>
constexpr auto operator<(const quantity_point<lhsUnit, ValueType> &lhs, const quantity_point<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit>, bool>
{
    return lhs._value < rhs._value;
}
template <class Unit, class ValueType>
constexpr auto operator<(const ValueType &lhs, const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<is_one_v<Unit>, bool>
{
    return lhs < rhs._value;
}
template <class Unit, class ValueType>
constexpr auto operator<(const quantity_point<Unit, ValueType> &lhs, const ValueType &rhs) -> std::enable_if_t<is_one_v<Unit>, bool>
{
    return lhs._value < rhs;
}
template <class lhsUnit, class rhsUnit, class ValueType>
constexpr auto operator>(const quantity_point<lhsUnit, ValueType> &lhs, const quantity_point<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit>, bool>
{
    return rhs < lhs;
}
template <class Unit, class ValueType>
constexpr auto operator>(const ValueType &lhs, const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<is_one_v<Unit>, bool>
{
    return rhs < lhs;
}
template <class Unit, class ValueType>
constexpr auto operator>(const quantity_point<Unit, ValueType> &lhs, const ValueType &rhs) -> std::enable_if_t<is_one_v<Unit>, bool>
{
    return rhs < lhs;
}
template <class lhsUnit, class rhsUnit, class ValueType>
constexpr auto operator<=(const quantity_point<lhsUnit, ValueType> &lhs, const quantity_point<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit>, bool>
{
    return !(rhs < lhs);
}
template <class Unit, class ValueType>
constexpr auto operator<=(const ValueType &lhs, const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<is_one_v<Unit>, bool>
{
    return !(rhs < lhs);
}
template <class Unit, class ValueType>
constexpr auto operator<=(const quantity_point<Unit, ValueType> &lhs, const ValueType &rhs) -> std::enable_if_t<is_one_v<Unit>, bool>
{
    return !(rhs < lhs);
}
template <class lhsUnit, class rhsUnit, class ValueType>
constexpr auto operator>=(const quantity_point<lhsUnit, ValueType> &lhs, const quantity_point<rhsUnit, ValueType> &rhs) -> std::enable_if_t<is_equivalent_v<lhsUnit, rhsUnit>, bool>
{
    return !(lhs < rhs);
}
template <class Unit, class ValueType>
constexpr auto operator>=(const ValueType &lhs, const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<is_one_v<Unit>, bool>
{
    return !(lhs < rhs);
}
template <class Unit, class ValueType>
constexpr auto operator>=(const quantity_point<Unit, ValueType> &lhs, const ValueType &rhs) -> std::enable_if_t<is_one_v<Unit>, bool>
{
    return !(lhs < rhs);
}
#pragma endregion
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
constexpr auto simple_cast(const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<typename ResultUnit::system, typename Unit::system> && impl::is_equivalent_list_v<typename ResultUnit::dimensions, typename Unit::dimensions>, quantity_point<ResultUnit, ValueType>>
{
    //calculation
    return quantity_point<ResultUnit, ValueType>{rhs._value * impl::expand_list_v<ValueType, impl::divide_lists_t<typename Unit::prefix, typename ResultUnit::prefix>>};
}
//The unit_cast function lets you cast one quantity_point to another unit.
//This is done by multiplying the value of the quantity_point with the right
//conversion constant. The unit_cast function uses std::pow for the
//conversion. This allows it to calculate arbitrary roots, but makes
//it incompatible with compile time evaluation. The function is still
//marked constexpr, to be forward compatible with a constexpr std::pow
//implementation.
template <class ResultUnit, class Unit, class ValueType>
constexpr auto unit_cast(const quantity_point<Unit, ValueType> &rhs) -> std::enable_if_t<std::is_same_v<typename ResultUnit::system, typename Unit::system> && impl::is_equivalent_list_v<typename ResultUnit::dimensions, typename Unit::dimensions>, quantity_point<ResultUnit, ValueType>>
{
    //calculation
    return quantity_point<ResultUnit, ValueType>{rhs._value * impl::runtime_expand_list<ValueType>(impl::divide_lists_t<typename Unit::prefix, typename ResultUnit::prefix>{})};
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
constexpr auto remove_prefix(const quantity_point<Unit, ValueType> &rhs) -> quantity_point<no_prefix_unit_t<Unit>, ResultValueType>
{
    //calculation
    using PrefixType = typename Unit::prefix;
    return quantity_point<no_prefix_unit_t<Unit>, ResultValueType>{static_cast<ResultValueType>(rhs._value) * impl::runtime_expand_list<ResultValueType>(PrefixType{})};
}
template <class Unit, class ValueType>
constexpr auto remove_prefix(const quantity_point<Unit, ValueType> &rhs)
{
    return remove_prefix<ValueType>(rhs);
}
#pragma endregion
} // namespace benri

//Restore the value of the pascal macro, if necessary.
#ifdef BENRI_PASCAL
#define pascal BENRI_PASCAL
#undef BENRI_PASCAL
#endif