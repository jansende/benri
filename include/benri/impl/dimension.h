#pragma once
#include <benri/impl/type/traits.h>
#include <ratio>

namespace benri
{
#pragma region dimension type
//Container type for saving dimensions with their associated power.
template <class T, class Power = std::ratio<1>>
struct dim
{
    static_assert(type::detect_if<Power, type::is_std_ratio>, "Power has to be a std::ratio.");
    using type = T;
    using power = Power;
};
#pragma endregion
} // namespace benri