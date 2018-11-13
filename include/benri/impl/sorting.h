#pragma once
#include <benri/impl/algorithm.h>
#include <benri/impl/array.h>
#include <benri/impl/atom.h>
#include <benri/impl/list.h>
#include <cstdlib>

namespace benri
{
namespace impl
{
template <class... Elements>
struct list;
}
#pragma region hash function
template <class T>
struct hash
{
};
template <>
struct hash<bool>
{
    static constexpr float value = 1;
};
template <>
struct hash<short int>
{
    static constexpr float value = 2;
};
template <>
struct hash<unsigned short int>
{
    static constexpr float value = 3;
};
template <>
struct hash<int>
{
    static constexpr float value = 4;
};
template <>
struct hash<unsigned int>
{
    static constexpr float value = 5;
};
template <>
struct hash<long int>
{
    static constexpr float value = 6;
};
template <>
struct hash<unsigned long int>
{
    static constexpr float value = 7;
};
template <>
struct hash<long long int>
{
    static constexpr float value = 8;
};
template <>
struct hash<unsigned long long int>
{
    static constexpr float value = 9;
};
template <>
struct hash<char>
{
    static constexpr float value = 10;
};
template <>
struct hash<float>
{
    static constexpr float value = 11;
};
template <>
struct hash<double>
{
    static constexpr float value = 12;
};
template <class Atom, bool hasValue>
struct atom_hash_value
{
    //TODO
};
template <template <class, class> class Atom, intmax_t num, intmax_t den, class Power>
struct atom_hash_value<Atom<std::ratio<num, den>, Power>, false>
{
    static constexpr float value = static_cast<float>(num) / static_cast<float>(den);
};
template <template <class, class> class Atom, class T, class Power>
struct atom_hash_value<Atom<T, Power>, false>
{
    static constexpr float value = hash<T>::value;
};
template <template <class, class> class Atom, class T, class Power>
struct atom_hash_value<Atom<T, Power>, true>
{
    static constexpr float value = static_cast<float>(T::value);
};
template <class Atom>
struct atom_hash
{
    //TODO
};
template <template <class, class> class Atom, class T, class Power>
struct atom_hash<Atom<T, Power>>
{
    static constexpr float value = atom_hash_value<Atom<T, Power>, impl::has_static_constexpr_value_v<T>>::value;
};

template <template <class, class> class Atom, class T, class Power>
struct hash<Atom<T, Power>>
{
    static constexpr float value = atom_hash<Atom<T, Power>>::value;
};
template <class T>
constexpr float hash_v = hash<T>::value;
#pragma endregion
namespace impl
{
#pragma region hash array
template <class List>
struct make_hash_array_impl
{
    //TODO
};
template <class... Elements>
struct make_hash_array_impl<list<Elements...>>
{
    static constexpr auto value = impl::array<float, sizeof...(Elements)>{hash_v<Elements>...};
};

template <class List>
constexpr auto make_hash_array = make_hash_array_impl<List>::value;
#pragma endregion

#pragma region get element
//TODO: make better
template <class List, size_t Index>
struct get_element_impl
{
    // static_assert
    using type = void;
};
template <class First, class... Rest, size_t Index>
struct get_element_impl<list<First, Rest...>, Index>
{
    using type = typename get_element_impl<list<Rest...>, Index - 1>::type;
};
template <class First, class... Rest>
struct get_element_impl<list<First, Rest...>, 0>
{
    using type = First;
};
template <size_t Index>
struct get_element_impl<list<>, Index>
{
    static_assert(Index == 0, "exceeded list");
    using type = void;
};
template <class List, size_t Index>
using get_element = typename get_element_impl<List, Index>::type;
#pragma endregion
#pragma region permutations
template <class List, size_t... Index>
constexpr auto permutate_list_impl(List, std::integer_sequence<size_t, Index...>)
{
    return list<get_element<List, Index>...>{};
}
template <class List, class Index>
using permutate_list = decltype(permutate_list_impl(List{}, Index{}));
#pragma endregion
#pragma region sorting function
template <class List, size_t... Index>
constexpr auto sort_list_func(List, std::integer_sequence<size_t, Index...>) {
    return permutate_list<List, std::integer_sequence<size_t, bubble_sort(make_hash_array<List>, make_index_array<size_t, sizeof...(Index)>)[Index]...>>{};
}
template <class...Elements>
constexpr auto sort_list_impl(list<Elements...>) {
    return sort_list_func(list<Elements...>{}, std::make_index_sequence<sizeof...(Elements)>{});
}
template <class List>
using sort_list = decltype(sort_list_impl(List{}));
#pragma endregion
// //basic tests
// static_assert(std::is_same_v<list<>, sort_list<list<>>>, "");
// static_assert(std::is_same_v<list<int>, sort_list<list<int>>>, "");
// static_assert(std::is_same_v<list<int, double>, sort_list<list<int, double>>>, "");
// static_assert(std::is_same_v<list<int, double>, sort_list<list<double, int>>>, "");
// static_assert(std::is_same_v<list<int, int, double>, sort_list<list<int, double, int>>>, "");
// static_assert(std::is_same_v<list<int, float, double>, sort_list<list<double, float, int>>>, "");
// static_assert(std::is_same_v<list<atom<int>, atom<float, std::ratio<2>>, atom<double>>, sort_list<list<atom<double>, atom<float, std::ratio<2>>, atom<int>>>>, "");
} // namespace impl
using impl::sort_list;
} // namespace benri