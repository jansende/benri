#pragma once
#include <type_traits>

#pragma region helper
//The all_true function helps to check if every type of a parameter pack has
//a certain property.
template <bool...>
struct bool_pack;
template <bool... bs>
constexpr bool all_true = std::is_same<bool_pack<bs..., true>, bool_pack<true, bs...>>::value;
#pragma endregion