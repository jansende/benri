#pragma once
#include <benri/impl/type/list.h>
#include <benri/impl/dimension.h>
#include <benri/impl/prefix.h>

namespace benri
{
#pragma region hash function
template <class T>
struct hash_impl
{
};
template <>
struct hash_impl<bool>
{
    static constexpr float value = 1;
};
template <>
struct hash_impl<short int>
{
    static constexpr float value = 2;
};
template <>
struct hash_impl<unsigned short int>
{
    static constexpr float value = 3;
};
template <>
struct hash_impl<int>
{
    static constexpr float value = 4;
};
template <>
struct hash_impl<unsigned int>
{
    static constexpr float value = 5;
};
template <>
struct hash_impl<long int>
{
    static constexpr float value = 6;
};
template <>
struct hash_impl<unsigned long int>
{
    static constexpr float value = 7;
};
template <>
struct hash_impl<long long int>
{
    static constexpr float value = 8;
};
template <>
struct hash_impl<unsigned long long int>
{
    static constexpr float value = 9;
};
template <>
struct hash_impl<char>
{
    static constexpr float value = 10;
};
template <>
struct hash_impl<float>
{
    static constexpr float value = 11;
};
template <>
struct hash_impl<double>
{
    static constexpr float value = 12;
};
template <class Atom, bool hasValue>
struct atom_hash_value
{
    //TODO
};
template <intmax_t num, intmax_t den, class Power>
struct atom_hash_value<dim<std::ratio<num, den>, Power>, false>
{
    static constexpr float value = static_cast<float>(num) / static_cast<float>(den);
};
template <class T, class Power>
struct atom_hash_value<dim<T, Power>, false>
{
    static constexpr float value = hash_impl<T>::value;
};
template <class T, class Power>
struct atom_hash_value<dim<T, Power>, true>
{
    static constexpr float value = static_cast<float>(T::value);
};
template <intmax_t num, intmax_t den, class Power>
struct atom_hash_value<pre<std::ratio<num, den>, Power>, false>
{
    static constexpr float value = static_cast<float>(num) / static_cast<float>(den);
};
template <class T, class Power>
struct atom_hash_value<pre<T, Power>, false>
{
    static constexpr float value = hash_impl<T>::value;
};
template <class T, class Power>
struct atom_hash_value<pre<T, Power>, true>
{
    static constexpr float value = static_cast<float>(T::value);
};
template <class Atom>
struct atom_hash
{
    //TODO
};
template <class T, class Power>
struct atom_hash<dim<T, Power>>
{
    static constexpr float value = atom_hash_value<dim<T, Power>, type::detect_if<T, type::has_value>>::value;
};
template <class T, class Power>
struct atom_hash<pre<T, Power>>
{
    static constexpr float value = atom_hash_value<pre<T, Power>, type::detect_if<T, type::has_value>>::value;
};

template <class T, class Power>
struct hash_impl<dim<T, Power>>
{
    static constexpr float value = atom_hash<dim<T, Power>>::value;
};
template <class T, class Power>
struct hash_impl<pre<T, Power>>
{
    static constexpr float value = atom_hash<pre<T, Power>>::value;
};
template <class T>
constexpr float hash = hash_impl<T>::value;
//hash_order is our standard ordering function
template <class L, class R>
using hash_order = std::integral_constant<bool, hash<L> < hash<R>>;
#pragma endregion
} // namespace benri