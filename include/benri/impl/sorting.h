#pragma once
#include <benri/impl/algorithm.h>
#include <benri/impl/array.h>
#include <benri/impl/atom.h>
#include <benri/impl/list.h>
#include <benri/impl/detector.h>
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
template <template <class, class> class Atom, intmax_t num, intmax_t den, class Power>
struct atom_hash_value<Atom<std::ratio<num, den>, Power>, false>
{
    static constexpr float value = static_cast<float>(num) / static_cast<float>(den);
};
template <template <class, class> class Atom, class T, class Power>
struct atom_hash_value<Atom<T, Power>, false>
{
    static constexpr float value = hash_impl<T>::value;
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
    static constexpr float value = atom_hash_value<Atom<T, Power>, detect_if<T, impl::has_static_constexpr_value>>::value;
};

template <template <class, class> class Atom, class T, class Power>
struct hash_impl<Atom<T, Power>>
{
    static constexpr float value = atom_hash<Atom<T, Power>>::value;
};
template <class T>
constexpr float hash = hash_impl<T>::value;
#pragma endregion
namespace impl
{
#pragma region sorting function
//hash_order is our standard ordering function
template <class L, class R>
using hash_order = std::integral_constant<bool, hash<L> < hash<R>>;
//We use insertion sort for sorting type lists. It might not be the fastest
//sorting algorithm for types, but it works and is reasonably quick for the
//lists we are usually using.
//
//The algorithm works as follows:
//def insertion_sort(new, comp, old)
//    if (new.empty) %No new elements. We are at the start. Add the first element from old to new and start sorting.
//        ret insertion_sort(new.append(old.first), comp, old.rest)
//    else if (!old.empty) %We have old elements left. Add the first element of the old list to new and sort it.
//        ret insertion_sort(insert_sort_swap(list(), comp, new.prepend(old.first)), comp, old.rest)
//    else %if (old.empty) %We have no old elements left. We are done.
//        ret new
//%we expect the unsorted element to be at the star of old
//def insert_sort_swap(new = list(), comp, old)
//    if (old.empty) %we are done
//        ret new
//    else if (old.size == 1) %only one element left, we are done
//        ret new.append(old)
//    else if (old.size ==2)
//        if (comp(old.first, old.second)) %everything is sorted
//           ret new.append(old.first,old.second)
//        else                             %unsorted but fixable
//           ret new.append(old.second,old.first)
//    else %if (old.size > 2)
//       if (comp(old.first, old.second)) %the elements are sorted. add them to new.
//           ret new.append(old)
//       else                             %unsorted but fixable. swap and continus
//           ret insert_sort_swap(new.append(old.second), comp, list().append(old.first).append(old.rest)
template <class New, template <class, class> class Comp, class Old>
struct insert_sort_swap_impl;
//No element to sort left. We are done.
template <class...NewTs, template <class, class> class Comp>
struct insert_sort_swap_impl<list<NewTs...>,Comp,list<>>
{
    using type = list<NewTs...>;
};
//One element to sort left. We are done.
template <class...NewTs, template <class, class> class Comp, class OldT>
struct insert_sort_swap_impl<list<NewTs...>,Comp,list<OldT>>
{
    using type = list<NewTs..., OldT>;
};
//Two elements to sort left. If they are in the wrong order, swap them. We are done.
template <class...NewTs, template <class, class> class Comp, class FirstOldT, class SecondOldT>
struct insert_sort_swap_impl<list<NewTs...>,Comp,list<FirstOldT,SecondOldT>>
{
    using type = std::conditional_t<Comp<FirstOldT,SecondOldT>::value, list<NewTs..., FirstOldT,SecondOldT>,list<NewTs..., SecondOldT, FirstOldT>>;
};
//More than two elements left to sort. If they are in the wrong order, swap them. Continue.
template <class...NewTs, template <class, class> class Comp, class FirstOldT, class SecondOldT, class...OldTs>
struct insert_sort_swap_impl<list<NewTs...>,Comp,list<FirstOldT,SecondOldT,OldTs...>> : std::conditional_t<Comp<FirstOldT,SecondOldT>::value, insert_sort_swap_impl<list<NewTs..., FirstOldT,SecondOldT,OldTs...>,Comp,list<>>,
insert_sort_swap_impl<list<NewTs...,SecondOldT>,Comp,list<FirstOldT,OldTs...>>>
{};
//Shortcut with correct initialization
template <template <class, class> class Comp, class Old>
using insert_sort_swap = typename insert_sort_swap_impl<list<>,Comp,Old>::type;

static_assert(std::is_same_v<   insert_sort_swap<hash_order,list<int>>,                list<int>                >, "");
static_assert(std::is_same_v<   insert_sort_swap<hash_order,list<double,int,float>>,   list<int,float,double>   >, "");

template <class New, template <class, class> class Comp, class Old>
struct insertion_sort;
//No element to sort left. We are done.
template <class... NewTs, template <class, class> class Comp>
struct insertion_sort<list<NewTs...>, Comp, list<>>
{
    using type = list<NewTs...>;
};
//No element has been sorted yet. (New list is empty.) Add the first old element to the new list, and start sorting.
template <template <class, class> class Comp, class FirstOld, class... OldTs>
struct insertion_sort<list<>, Comp, list<FirstOld, OldTs...>> : insertion_sort<list<FirstOld>, Comp, list<OldTs...>>
{
};
//Old list is not empty. Swap/Merge the first old element into the new list, and keep sorting.
template <class FirstNewT, class... NewTs, template <class, class> class Comp, class FirstOldT, class... OldTs>
struct insertion_sort<list<FirstNewT, NewTs...>, Comp, list<FirstOldT, OldTs...>> : insertion_sort<insert_sort_swap<Comp, list<FirstOldT, FirstNewT, NewTs...>>, Comp, list<OldTs...>>
{
};
//Shortcut with initialization
template <class List, template <class, class> class Comp = hash_order>
using sort = typename insertion_sort<list<>,Comp,List>::type;

#pragma endregion
//basic tests
static_assert(std::is_same<list<>, sort<list<>>>::value, "");
static_assert(std::is_same<list<int>, sort<list<int>>>::value, "");
static_assert(std::is_same<list<int, double>, sort<list<int, double>>>::value, "");
static_assert(std::is_same<list<int, double>, sort<list<double, int>>>::value, "");
static_assert(std::is_same<list<int, int, double>, sort<list<int, double, int>>>::value, "");
static_assert(std::is_same<list<int, float, double>, sort<list<double, float, int>>>::value, "");
static_assert(std::is_same<list<atom<int>, atom<float, std::ratio<2>>, atom<double>>, sort<list<atom<double>, atom<float, std::ratio<2>>, atom<int>>>>::value, "");
} // namespace impl
using impl::sort;
} // namespace benri