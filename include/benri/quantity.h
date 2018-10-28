#pragma once
#include <cmath>
#include <benri/unit.h>
#include <benri/config.h>

namespace benri
{
#pragma region quantity class helpers
//quantity forward declaration
template <class Unit, class ValueType = Precision>
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
constexpr auto is_quantity_v = is_quantity<T>::value;
#pragma endregion
#pragma region quantity class
//The quantity type handles physical quantities. It checks the units
//in calculations and handles conversions, etc. The type in general
//should be compile time constexpr and if in some context contexpr
//cannot be used, it should still be optimized into a single variable
//of type ValueType.
template <class Unit, class ValueType>
class quantity
{
  public:
    constexpr quantity(ValueType value) : _value(value) {}
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
    template <class L, class R>
    friend constexpr auto simple_cast(R rhs) -> quantity<L, typename R::value_type>;
    template <class L, class R>
    friend constexpr auto unit_cast(R rhs) -> quantity<L, typename R::value_type>;
    template <class ResultType, class Unit, class ValueType>
    friend constexpr auto remove_prefix(quantity<Unit, ValueType> val) -> quantity<unit<typename Unit::system, typename Unit::dimensions, list<>>, ResultType>;
#pragma endregion
#pragma region rule of three(actually two)
    //The default constructor is disabled to force users to give useful data for the
    //quantity every time.
    quantity() = delete;
    constexpr quantity(const quantity<Unit, ValueType> &) = default;
    constexpr quantity(quantity<Unit, ValueType> &&) = default;
    template <class R>
    constexpr auto operator=(const R &rhs) noexcept -> std::enable_if_t<!std::is_same_v<R, ValueType>, decltype(*this)> //copy assignment
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<R>, "rhs has to be a quantity.");
        static_assert(std::is_same_v<value_type, typename R::value_type>, "rhs has to have the same value_type.");
        static_assert(is_equivalent_v<unit_type, typename R::unit_type>, "rhs has to have the same unit_type.");
        //no self-assignment
        if (this != &rhs)
        {
            //copy values
            this->_value = rhs._value;
        }
        return *this;
    }
    constexpr auto operator=(const ValueType &rhs) noexcept
    {
        using namespace impl;
        //type checking
        static_assert(std::is_same_v<typename unit_type::dimensions, list<>>, "You can only assign bare values to dimensionless types.");
        //assignment
        _value = rhs;
        return *this;
    }
    template <class R>
    constexpr auto operator=(R &&rhs) noexcept -> std::enable_if_t<!std::is_same_v<R, ValueType>, decltype(*this)> //move assignment
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<R>, "rhs has to be a quantity.");
        static_assert(std::is_same_v<value_type, typename R::value_type>, "rhs has to have the same value_type.");
        static_assert(is_equivalent_v<unit_type, typename R::unit_type>, "rhs has to have the same unit_type.");
        //no self-assignment
        if (this != &rhs)
        {
            //copy values
            this->_value = rhs._value;
        }
        return *this;
    }
    constexpr auto operator=(ValueType &&rhs) noexcept
    {
        using namespace impl;
        //type checking
        static_assert(std::is_same_v<typename unit_type::dimensions, list<>>, "You can only assign bare values to dimensionless types.");
        //assignment
        _value = rhs;
        return *this;
    }
#pragma endregion
#pragma region math
#pragma region unary operators
    constexpr auto operator+() const
    {
        return quantity<unit_type, value_type>{_value};
    }
    constexpr auto operator-() const
    {
        return quantity<unit_type, value_type>{value_type{-1} * _value};
    }
#pragma endregion
#pragma region addition
    template <class R>
    constexpr auto operator+=(const R &rhs) -> std::enable_if_t<!std::is_same_v<R, ValueType>, decltype(*this)>
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<R>, "rhs has to be a quantity.");
        static_assert(std::is_same_v<value_type, typename R::value_type>, "rhs has to have the same value_type.");
        static_assert(is_equivalent_v<unit_type, typename R::unit_type>, "rhs has to have the same unit_type.");
        //calculation
        this->_value += rhs._value;
        return *this;
    }
    constexpr auto operator+=(const ValueType &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(std::is_same_v<typename unit_type::dimensions, list<>>, "You can only add bare values to dimensionless types.");
        //calculation
        this->_value += rhs;
        return *this;
    }
    template <class L, class R>
    friend constexpr auto operator+(L lhs, const R &rhs) -> std::enable_if_t<!std::is_same_v<L, ValueType> && !std::is_same_v<R, ValueType>, L>
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<L> && is_quantity_v<R>, "lhs and rhs have to be a quantity.");
        static_assert(std::is_same_v<typename L::value_type, typename R::value_type>, "lhs and rhs have to have the same value_type.");
        static_assert(is_equivalent_v<typename L::unit_type, typename R::unit_type>, "lhs and rhs have to have the same unit_type.");
        //calculation
        lhs += rhs;
        return lhs;
    }
    template <class L>
    friend constexpr auto operator+(const L &lhs, const typename L::value_type &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(std::is_same_v<typename L::unit_type::dimensions, list<>>, "You can only add dimensionless types to bare values.");
        //calculation
        return lhs + L{rhs};
    }
    template <class R>
    friend constexpr auto operator+(const typename R::value_type &lhs, const R &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(std::is_same_v<typename R::unit_type::dimensions, list<>>, "You can only add dimensionless types to bare values.");
        //calculation
        return R{lhs} + rhs;
    }
    template <class R>
    constexpr auto operator-=(const R &rhs) -> std::enable_if_t<!std::is_same_v<R, ValueType>, decltype(*this)>
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<R>, "rhs has to be a quantity.");
        static_assert(std::is_same_v<value_type, typename R::value_type>, "rhs has to have the same value_type.");
        static_assert(is_equivalent_v<unit_type, typename R::unit_type>, "rhs has to have the same unit_type.");
        //calculation
        this->_value -= rhs._value;
        return *this;
    }
    constexpr auto operator-=(const ValueType &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(std::is_same_v<typename unit_type::dimensions, list<>>, "You can only subtract bare values from dimensionless types.");
        //calculation
        this->_value -= rhs;
        return *this;
    }
    template <class L, class R>
    friend constexpr auto operator-(L lhs, const R &rhs) -> std::enable_if_t<!std::is_same_v<L, ValueType> && !std::is_same_v<R, ValueType>, L>
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<L> && is_quantity_v<R>, "lhs and rhs have to be a quantity.");
        static_assert(std::is_same_v<typename L::value_type, typename R::value_type>, "lhs and rhs have to have the same value_type.");
        static_assert(is_equivalent_v<typename L::unit_type, typename R::unit_type>, "lhs and rhs have to have the same unit_type.");
        //calculation
        lhs -= rhs;
        return lhs;
    }
    template <class L>
    friend constexpr auto operator-(const L &lhs, const typename L::value_type &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(std::is_same_v<typename L::unit_type::dimensions, list<>>, "You can only subtract dimensionless types from bare values.");
        //calculation
        return lhs - L{rhs};
    }
    template <class R>
    friend constexpr auto operator-(const typename R::value_type &lhs, const R &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(std::is_same_v<typename R::unit_type::dimensions, list<>>, "You can only subtract dimensionless types from bare values.");
        //calculation
        return R{lhs} - rhs;
    }
#pragma endregion
#pragma region multiplication
    constexpr auto &operator*=(const ValueType &rhs)
    {
        this->_value *= rhs;
        return *this;
    }
    template <class L, class R>
    friend constexpr auto operator*(const L &lhs, const R &rhs) -> std::enable_if_t<!std::is_same_v<L, ValueType> && !std::is_same_v<R, ValueType>, quantity<multiply_units_t<typename L::unit_type, typename R::unit_type>, typename L::value_type>>
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<L> && is_quantity_v<R>, "lhs and rhs have to be a quantity.");
        static_assert(std::is_same_v<typename L::value_type, typename R::value_type>, "lhs and rhs have to have the same value_type.");
        //calculation
        return quantity<multiply_units_t<typename L::unit_type, typename R::unit_type>, typename L::value_type>{lhs._value * rhs._value};
    }
    template <class L>
    friend constexpr auto operator*(L lhs, const typename L::value_type &rhs)
    {
        lhs._value *= rhs;
        return lhs;
    }
    template <class R>
    friend constexpr auto operator*(const typename R::value_type &lhs, R rhs)
    {
        return rhs * lhs;
    }
    constexpr auto &operator/=(const ValueType &rhs)
    {
        this->_value /= rhs;
        return *this;
    }
    template <class L, class R>
    friend constexpr auto operator/(const L &lhs, const R &rhs) -> std::enable_if_t<!std::is_same_v<L, ValueType> && !std::is_same_v<R, ValueType>, quantity<divide_units_t<typename L::unit_type, typename R::unit_type>, typename L::value_type>>
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<L> && is_quantity_v<R>, "lhs and rhs have to be a quantity.");
        static_assert(std::is_same_v<typename L::value_type, typename R::value_type>, "lhs and rhs have to have the same value_type.");
        //calculation
        return quantity<divide_units_t<typename L::unit_type, typename R::unit_type>, typename L::value_type>{lhs._value / rhs._value};
    }
    template <class L>
    friend constexpr auto operator/(L lhs, const typename L::value_type &rhs)
    {
        lhs._value /= rhs;
        return lhs;
    }
    template <class R>
    friend constexpr auto operator/(const typename R::value_type &lhs, const R &rhs)
    {
        using namespace impl;
        //calculation
        return quantity<pow_unit_t<typename R::unit_type, std::ratio<-1>>, typename R::value_type>{lhs / rhs._value};
    }
#pragma endregion
#pragma region comparisons
    template <class L, class R>
    friend constexpr auto operator==(const L &lhs, const R &rhs) -> std::enable_if_t<!std::is_same_v<L, ValueType> && !std::is_same_v<R, ValueType>, bool>
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<L> && is_quantity_v<R>, "lhs and rhs have to be a quantity.");
        static_assert(std::is_same_v<typename L::value_type, typename R::value_type>, "lhs and rhs have to have the same value_type.");
        static_assert(is_equivalent_v<typename L::unit_type, typename R::unit_type>, "lhs and rhs have to have the same unit_type.");
        //calculation
        return lhs._value == rhs._value;
    }
    template <class L>
    friend constexpr auto operator==(const L &lhs, const typename L::value_type &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(std::is_same_v<typename L::unit_type::dimensions, list<>>, "You can only compare dimensionless types to bare values.");
        //calculation
        return lhs == L{rhs};
    }
    template <class R>
    friend constexpr auto operator==(const typename R::value_type &lhs, const R &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(std::is_same_v<typename R::unit_type::dimensions, list<>>, "You can only compare dimensionless types to bare values.");
        //calculation
        return R{lhs} == rhs;
    }
    template <class L, class R>
    friend constexpr auto operator!=(const L &lhs, const R &rhs) -> std::enable_if_t<!std::is_same_v<L, ValueType> && !std::is_same_v<R, ValueType>, bool>
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<L> && is_quantity_v<R>, "lhs and rhs have to be a quantity.");
        static_assert(std::is_same_v<typename L::value_type, typename R::value_type>, "lhs and rhs have to have the same value_type.");
        static_assert(is_equivalent_v<typename L::unit_type, typename R::unit_type>, "lhs and rhs have to have the same unit_type.");
        //calculation
        return !(lhs == rhs);
    }
    template <class L>
    friend constexpr auto operator!=(const L &lhs, const typename L::value_type &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(std::is_same_v<typename L::unit_type::dimensions, list<>>, "You can only compare dimensionless types to bare values.");
        //calculation
        return lhs != L{rhs};
    }
    template <class R>
    friend constexpr auto operator!=(const typename R::value_type &lhs, const R &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(std::is_same_v<typename R::unit_type::dimensions, list<>>, "You can only compare dimensionless types to bare values.");
        //calculation
        return R{lhs} != rhs;
    }
    template <class L, class R>
    friend constexpr auto operator<(const L &lhs, const R &rhs) -> std::enable_if_t<!std::is_same_v<L, ValueType> && !std::is_same_v<R, ValueType>, bool>
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<L> && is_quantity_v<R>, "lhs and rhs have to be a quantity.");
        static_assert(std::is_same_v<typename L::value_type, typename R::value_type>, "lhs and rhs have to have the same value_type.");
        static_assert(is_equivalent_v<typename L::unit_type, typename R::unit_type>, "lhs and rhs have to have the same unit_type.");
        //calculation
        return lhs._value < rhs._value;
    }
    template <class L>
    friend constexpr auto operator<(const L &lhs, const typename L::value_type &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(std::is_same_v<typename L::unit_type::dimensions, list<>>, "You can only compare dimensionless types to bare values.");
        //calculation
        return lhs < L{rhs};
    }
    template <class R>
    friend constexpr auto operator<(const typename R::value_type &lhs, const R &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(std::is_same_v<typename R::unit_type::dimensions, list<>>, "You can only compare dimensionless types to bare values.");
        //calculation
        return R{lhs} < rhs;
    }
    template <class L, class R>
    friend constexpr auto operator>(const L &lhs, const R &rhs) -> std::enable_if_t<!std::is_same_v<L, ValueType> && !std::is_same_v<R, ValueType>, bool>
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<L> && is_quantity_v<R>, "lhs and rhs have to be a quantity.");
        static_assert(std::is_same_v<typename L::value_type, typename R::value_type>, "lhs and rhs have to have the same value_type.");
        static_assert(is_equivalent_v<typename L::unit_type, typename R::unit_type>, "lhs and rhs have to have the same unit_type.");
        //calculation
        return rhs < lhs;
    }
    template <class L>
    friend constexpr auto operator>(const L &lhs, const typename L::value_type &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(std::is_same_v<typename L::unit_type::dimensions, list<>>, "You can only compare dimensionless types to bare values.");
        //calculation
        return lhs > L{rhs};
    }
    template <class R>
    friend constexpr auto operator>(const typename R::value_type &lhs, const R &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(std::is_same_v<typename R::unit_type::dimensions, list<>>, "You can only compare dimensionless types to bare values.");
        //calculation
        return R{lhs} > rhs;
    }
    template <class L, class R>
    friend constexpr auto operator<=(const L &lhs, const R &rhs) -> std::enable_if_t<!std::is_same_v<L, ValueType> && !std::is_same_v<R, ValueType>, bool>
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<L> && is_quantity_v<R>, "lhs and rhs have to be a quantity.");
        static_assert(std::is_same_v<typename L::value_type, typename R::value_type>, "lhs and rhs have to have the same value_type.");
        static_assert(is_equivalent_v<typename L::unit_type, typename R::unit_type>, "lhs and rhs have to have the same unit_type.");
        //calculation
        return !(rhs < lhs);
    }
    template <class L>
    friend constexpr auto operator<=(const L &lhs, const typename L::value_type &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(std::is_same_v<typename L::unit_type::dimensions, list<>>, "You can only compare dimensionless types to bare values.");
        //calculation
        return lhs <= L{rhs};
    }
    template <class R>
    friend constexpr auto operator<=(const typename R::value_type &lhs, const R &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(std::is_same_v<typename R::unit_type::dimensions, list<>>, "You can only compare dimensionless types to bare values.");
        //calculation
        return R{lhs} <= rhs;
    }
    template <class L, class R>
    friend constexpr auto operator>=(const L &lhs, const R &rhs) -> std::enable_if_t<!std::is_same_v<L, ValueType> && !std::is_same_v<R, ValueType>, bool>
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<L> && is_quantity_v<R>, "lhs and rhs have to be a quantity.");
        static_assert(std::is_same_v<typename L::value_type, typename R::value_type>, "lhs and rhs have to have the same value_type.");
        static_assert(is_equivalent_v<typename L::unit_type, typename R::unit_type>, "lhs and rhs have to have the same unit_type.");
        //calculation
        return !(lhs < rhs);
    }
    template <class L>
    friend constexpr auto operator>=(const L &lhs, const typename L::value_type &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(std::is_same_v<typename L::unit_type::dimensions, list<>>, "You can only compare dimensionless types to bare values.");
        //calculation
        return lhs >= L{rhs};
    }
    template <class R>
    friend constexpr auto operator>=(const typename R::value_type &lhs, const R &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(std::is_same_v<typename R::unit_type::dimensions, list<>>, "You can only compare dimensionless types to bare values.");
        //calculation
        return R{lhs} >= rhs;
    }
#pragma endregion
#pragma endregion
};
//The simple_cast function lets you cast one quantity to another unit.
//This is done by multiplying the value of the quantity with the right
//conversion constant. The simple_cast function relies on a custom imple-
//mentation of the power function, which allows it to be evaluated at
//compile time. However, the implementation has a restriction, that it is
//not compatible with roots of units.
template <class L, class R>
constexpr auto simple_cast(R rhs) -> quantity<L, typename R::value_type>
{
    //type checking
    static_assert(is_quantity_v<R>, "rhs has to be a quantity.");
    static_assert(is_unit_v<L>, "lhs has to be a unit.");
    static_assert(std::is_same_v<typename L::system, typename R::unit_type::system>, "lhs and rhs have to be from the same unit system.");
    static_assert(impl::is_equivalent_list_v<typename L::dimensions, typename R::unit_type::dimensions>, "lhs and rhs have to have the same dimensions.");
    //calculation
    return quantity<L, typename R::value_type>{rhs._value * impl::expand_list_v<typename R::value_type, impl::divide_lists_t<typename R::unit_type::prefix, typename L::prefix>>};
}
//The unit_cast function lets you cast one quantity to another unit.
//This is done by multiplying the value of the quantity with the right
//conversion constant. The unit_cast function uses std::pow for the
//conversion. This allows it to calculate arbitrary roots, but makes
//it incompatible with compile time evaluation. The function is still
//marked constexpr, to be forward compatible with a constexpr std::pow
//implementation.
template <class L, class R>
constexpr auto unit_cast(R rhs) -> quantity<L, typename R::value_type>
{
    //type checking
    static_assert(is_quantity_v<R>, "rhs has to be a quantity.");
    static_assert(is_unit_v<L>, "lhs has to be a unit.");
    static_assert(std::is_same_v<typename L::system, typename R::unit_type::system>, "lhs and rhs have to be from the same unit system.");
    static_assert(impl::is_equivalent_list_v<typename L::dimensions, typename R::unit_type::dimensions>, "lhs and rhs have to have the same dimensions.");
    //calculation
    return quantity<L, typename R::value_type>{rhs._value * impl::runtime_expand_list<typename R::value_type>(impl::divide_lists_t<typename R::unit_type::prefix, typename L::prefix>{})};
}
//The remove_prefix function lets you get rid of the prefix of an arbitrary
//unit, by multiplying the value of the quantity with the prefix value.
//The remove_prefix function uses std::pow for the conversion. This allows
//it to remove arbitrary roots, but makes it incompatible with compile time
//evaluation. The function is still marked constexpr, to be forward compa-
//tible with a constexpr std::pow implementation.
//Furthermore, you can provide a ResultType for the function, in the case that
//the transformation would lead to conversion errors.
template <class ResultType, class Unit, class ValueType>
constexpr auto remove_prefix(quantity<Unit, ValueType> val) -> quantity<unit<typename Unit::system, typename Unit::dimensions, list<>>, ResultType>
{
    //calculation
    return quantity<unit<typename Unit::system, typename Unit::dimensions, list<>>, ResultType>{static_cast<ResultType>(val._value) * impl::runtime_expand_list<ResultType>((typename Unit::prefix){})};
}
template <class Unit, class ValueType>
constexpr auto remove_prefix(quantity<Unit, ValueType> val)
{
    return remove_prefix<ValueType>(val);
}
#pragma endregion
} // namespace benri