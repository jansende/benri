#pragma once
#include <benri/impl/quantity.h>

namespace benri
{
#pragma region power
template <class Exponent, class T>
constexpr auto pow(T val) -> quantity<pow_unit_t<typename T::unit_type, Exponent>, typename T::value_type>
{
    return quantity<pow_unit_t<typename T::unit_type, Exponent>, typename T::value_type>{std::pow(val._value, typename T::value_type(Exponent::num) / typename T::value_type(Exponent::den))};
}
template <intmax_t num, intmax_t den = 1, class T>
constexpr auto pow(T val)
{
    return pow<std::ratio<num, den>>(val);
}
#pragma endregion
} // namespace benri
namespace std
{
using benri::pow;
}
