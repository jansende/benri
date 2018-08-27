#pragma once
#include <cmath>
#include <benri/unit.h>
#include <benri/config.h>

namespace benri
{
#pragma region quantity class helpers
//quantity forward declaration
template <class Unit, class T = Precision>
class quantity;
//The is_quantity function checks if a given type is a quantity
//object.
template <class T>
struct is_quantity : std::false_type
{
};
template <class Unit, class T>
struct is_quantity<quantity<Unit, T>> : std::true_type
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
//of type T.
template <class Unit, class T>
class quantity
{
  public:
    constexpr quantity(T value) : _value(value) {}
    using value_type = T;
    using unit_type = Unit;

  private:
    T _value;

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
#pragma endregion
#pragma region rule of three(actually two)
    //The default constructor is disabled to force users to give useful data for the
    //quantity every time.
    quantity() = delete;
    //TODO: - Implement a different copy constructor?
    constexpr quantity(const quantity<Unit, T> &) = default;
    template <class R>
    constexpr auto &operator=(const R &rhs) noexcept //copy assignment
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<R>, "rhs has to be a quantity.");
        static_assert(std::is_same_v<T, typename R::value_type>, "rhs has to have the same value_type.");
        static_assert(is_equivalent_v<Unit, typename R::unit_type>, "rhs has to have the same unit_type.");
        //no self-assignment
        if (this != &rhs)
        {
            //copy values
            _value = rhs._value;
        }
        return *this;
    }
    template <class R>
    constexpr auto &operator=(R &&rhs) noexcept //move assignment
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<R>, "rhs has to be a quantity.");
        static_assert(std::is_same_v<T, typename R::value_type>, "rhs has to have the same value_type.");
        static_assert(is_equivalent_v<Unit, typename R::unit_type>, "rhs has to have the same unit_type.");
        //no self-assignment
        if (this != &rhs)
        {
            //copy values
            _value = rhs._value;
        }
        return *this;
    }
#pragma endregion
#pragma region math
#pragma region addition
    template <class R>
    constexpr auto operator+=(const R &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<R>, "rhs has to be a quantity.");
        static_assert(std::is_same_v<T, typename R::value_type>, "rhs has to have the same value_type.");
        static_assert(is_equivalent_v<Unit, typename R::unit_type>, "rhs has to have the same unit_type.");
        //calculation
        this->_value += rhs._value;
        return *this;
    }
    template <class L, class R>
    friend constexpr auto operator+(L lhs, const R &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<L> && is_quantity_v<R>, "lhs and rhs have to be a quantities.");
        static_assert(std::is_same_v<typename L::value_type, typename R::value_type>, "lhs and rhs have to have the same value_type.");
        static_assert(is_equivalent_v<typename L::unit_type, typename R::unit_type>, "lhs and rhs have to have the same unit_type.");
        //calculation
        lhs += rhs;
        return lhs;
    }
    template <class R>
    constexpr auto &operator-=(const R &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<R>, "rhs has to be a quantity.");
        static_assert(std::is_same_v<T, typename R::value_type>, "rhs has to have the same value_type.");
        static_assert(is_equivalent_v<Unit, typename R::unit_type>, "rhs has to have the same unit_type.");
        //calculation
        this->_value -= rhs._value;
        return *this;
    }
    template <class L, class R>
    friend constexpr auto operator-(L lhs, const R &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<L> && is_quantity_v<R>, "lhs and rhs have to be a quantities.");
        static_assert(std::is_same_v<typename L::value_type, typename R::value_type>, "lhs and rhs have to have the same value_type.");
        static_assert(is_equivalent_v<typename L::unit_type, typename R::unit_type>, "lhs and rhs have to have the same unit_type.");
        //calculation
        lhs -= rhs;
        return lhs;
    }
#pragma endregion
#pragma region multiplication
    constexpr auto &operator*=(const T &rhs)
    {
        //calculation
        this->_value *= rhs;
        return *this;
    }
    template <class L, class R>
    friend constexpr auto operator*(const L &lhs, const R &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<L> && is_quantity_v<R>, "lhs and rhs have to be a quantities.");
        static_assert(std::is_same_v<typename L::value_type, typename R::value_type>, "lhs and rhs have to have the same value_type.");
        //calculation
        return quantity<multiply_units_t<typename L::unit_type, typename R::unit_type>, typename L::value_type>{lhs._value * rhs._value};
    }
    template <class L>
    friend constexpr auto operator*(L lhs, const typename L::value_type &rhs)
    {
        //calculation
        lhs._value *= rhs;
        return lhs;
    }
    template <class R>
    friend constexpr auto operator*(const typename R::value_type &lhs, R rhs)
    {
        return rhs * lhs;
    }
    constexpr auto &operator/=(const T &rhs)
    {
        //calculation
        this->_value /= rhs;
        return *this;
    }
    template <class L, class R>
    friend constexpr auto operator/(const L &lhs, const R &rhs) -> std::enable_if_t<!std::is_arithmetic_v<L> && !std::is_arithmetic_v<R>, quantity<divide_units_t<typename L::unit_type, typename R::unit_type>, typename L::value_type>>
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<L> && is_quantity_v<R>, "lhs and rhs have to be a quantities.");
        static_assert(std::is_same_v<typename L::value_type, typename R::value_type>, "lhs and rhs have to have the same value_type.");
        //calculation
        return quantity<divide_units_t<typename L::unit_type, typename R::unit_type>, typename L::value_type>{lhs._value / rhs._value};
    }
    template <class L>
    friend constexpr auto operator/(L lhs, const typename L::value_type &rhs)
    {
        //calculation
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
    friend constexpr auto operator==(const L &lhs, const R &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<L> && is_quantity_v<R>, "lhs and rhs have to be a quantities.");
        static_assert(std::is_same_v<typename L::value_type, typename R::value_type>, "lhs and rhs have to have the same value_type.");
        static_assert(is_equivalent_v<typename L::unit_type, typename R::unit_type>, "lhs and rhs have to have the same unit_type.");
        //calculation
        return lhs._value == rhs._value;
    }
    template <class L, class R>
    friend constexpr auto operator!=(const L &lhs, const R &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<L> && is_quantity_v<R>, "lhs and rhs have to be a quantities.");
        static_assert(std::is_same_v<typename L::value_type, typename R::value_type>, "lhs and rhs have to have the same value_type.");
        static_assert(is_equivalent_v<typename L::unit_type, typename R::unit_type>, "lhs and rhs have to have the same unit_type.");
        //calculation
        return !(lhs == rhs);
    }
    template <class L, class R>
    friend constexpr auto operator<(const L &lhs, const R &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<L> && is_quantity_v<R>, "lhs and rhs have to be a quantities.");
        static_assert(std::is_same_v<typename L::value_type, typename R::value_type>, "lhs and rhs have to have the same value_type.");
        static_assert(is_equivalent_v<typename L::unit_type, typename R::unit_type>, "lhs and rhs have to have the same unit_type.");
        //calculation
        return lhs._value < rhs._value;
    }
    template <class L, class R>
    friend constexpr auto operator>(const L &lhs, const R &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<L> && is_quantity_v<R>, "lhs and rhs have to be a quantities.");
        static_assert(std::is_same_v<typename L::value_type, typename R::value_type>, "lhs and rhs have to have the same value_type.");
        static_assert(is_equivalent_v<typename L::unit_type, typename R::unit_type>, "lhs and rhs have to have the same unit_type.");
        //calculation
        return rhs < lhs;
    }
    template <class L, class R>
    friend constexpr auto operator<=(const L &lhs, const R &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<L> && is_quantity_v<R>, "lhs and rhs have to be a quantities.");
        static_assert(std::is_same_v<typename L::value_type, typename R::value_type>, "lhs and rhs have to have the same value_type.");
        static_assert(is_equivalent_v<typename L::unit_type, typename R::unit_type>, "lhs and rhs have to have the same unit_type.");
        //calculation
        return !(rhs < lhs);
    }
    template <class L, class R>
    friend constexpr auto operator>=(const L &lhs, const R &rhs)
    {
        using namespace impl;
        //type checking
        static_assert(is_quantity_v<L> && is_quantity_v<R>, "lhs and rhs have to be a quantities.");
        static_assert(std::is_same_v<typename L::value_type, typename R::value_type>, "lhs and rhs have to have the same value_type.");
        static_assert(is_equivalent_v<typename L::unit_type, typename R::unit_type>, "lhs and rhs have to have the same unit_type.");
        //calculation
        return !(lhs < rhs);
    }
#pragma endregion
#pragma endregion
#pragma region cmath
    template <class Exponent, class T>
    friend constexpr auto pow(T val) -> quantity<pow_unit_t<typename T::unit_type, Exponent>, typename T::value_type>;
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
    static_assert(is_quantity_v<R>, "rhs has to be a quantities.");
    static_assert(is_unit_v<L>, "lhs has to be a unit.");
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
    static_assert(is_quantity_v<R>, "rhs has to be a quantities.");
    static_assert(is_unit_v<L>, "lhs has to be a unit.");
    static_assert(impl::is_equivalent_list_v<typename L::dimensions, typename R::unit_type::dimensions>, "lhs and rhs have to have the same dimensions.");
    //calculation
    return quantity<L, typename R::value_type>{rhs._value * impl::runtime_expand_list<typename R::value_type>(impl::divide_lists_t<typename R::unit_type::prefix, typename L::prefix>{})};
}
#pragma endregion
} // namespace benri