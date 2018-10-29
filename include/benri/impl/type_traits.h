#pragma once
#include <type_traits>

#pragma region helper
//The all_true function helps to check if every type of a parameter pack has
//a certain property.
template <bool...>
struct bool_pack;
template <bool... bs>
struct all_true : std::integral_constant<bool, std::is_same_v<bool_pack<bs..., true>, bool_pack<true, bs...>>>
{
};
template <bool... bs>
constexpr bool all_true_v = all_true<bs...>::value;
#pragma endregion