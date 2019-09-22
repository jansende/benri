#pragma once
#include <benri/impl/dimension.h>
#include <benri/impl/meta/string.h>
#include <benri/impl/prefix.h>
#include <benri/impl/type/list.h>

namespace benri
{
#pragma region type hash
// Function for ordering types.
template <class T>
struct type_hash_impl
{
    // We implicitly assume that types which are not specialized, provide a
    // ::value attribute.
    static constexpr float value = static_cast<float>(T::value);
};
template <>
struct type_hash_impl<bool>
{
    static constexpr float value = 1;
};
template <>
struct type_hash_impl<short int>
{
    static constexpr float value = 2;
};
template <>
struct type_hash_impl<unsigned short int>
{
    static constexpr float value = 3;
};
template <>
struct type_hash_impl<int>
{
    static constexpr float value = 4;
};
template <>
struct type_hash_impl<unsigned int>
{
    static constexpr float value = 5;
};
template <>
struct type_hash_impl<long int>
{
    static constexpr float value = 6;
};
template <>
struct type_hash_impl<unsigned long int>
{
    static constexpr float value = 7;
};
template <>
struct type_hash_impl<long long int>
{
    static constexpr float value = 8;
};
template <>
struct type_hash_impl<unsigned long long int>
{
    static constexpr float value = 9;
};
template <>
struct type_hash_impl<char>
{
    static constexpr float value = 10;
};
template <>
struct type_hash_impl<float>
{
    static constexpr float value = 11;
};
template <>
struct type_hash_impl<double>
{
    static constexpr float value = 12;
};
template <intmax_t Num, intmax_t Den>
struct type_hash_impl<std::ratio<Num, Den>>
{
    static constexpr float value = static_cast<float>(Num) / static_cast<float>(Den);
};
template <intmax_t Num, intmax_t Den, class Power>
struct type_hash_impl<dim<std::ratio<Num, Den>, Power>>
{
    static constexpr float value = type_hash_impl<std::ratio<Num, Den>>::value;
};
template <class T, class Power>
struct type_hash_impl<dim<T, Power>>
{
    // Unpack.
    static constexpr float value = type_hash_impl<T>::value;
};
template <intmax_t Num, intmax_t Den, class Power>
struct type_hash_impl<pre<std::ratio<Num, Den>, Power>>
{
    static constexpr float value = type_hash_impl<std::ratio<Num, Den>>::value;
};
template <class T, class Power>
struct type_hash_impl<pre<T, Power>>
{
    // Unpack.
    static constexpr float value = type_hash_impl<T>::value;
};
template <class T>
constexpr float type_hash = type_hash_impl<T>::value;
#pragma endregion
#pragma region type ordering
template <class L, class R>
struct type_order : std::integral_constant<bool, (type_hash<L> < type_hash<R>)>
{
};
// Everything is smaller than dimensions.
template <class L, class T, class Power>
struct type_order<L, dim<T, Power>> : std::true_type
{
};
// Dimensions are ordered by their ::name.
template <class LT, class LPower, class RT, class RPower>
struct type_order<dim<LT, LPower>, dim<RT, RPower>> :
    std::integral_constant<bool, (meta::strcmp(LT::name, RT::name) < 0)>
{
};
#pragma endregion
} // namespace benri