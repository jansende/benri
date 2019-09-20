#pragma once
#include <benri/impl/type/list.h>
#include <benri/impl/type/traits.h>
#include <benri/impl/type/comp.h>

namespace benri
{
namespace type
{
#pragma region insertion sort
//We use insertion sort for sorting type lists. It might not be the fastest
//sorting algorithm for types, but it works and is reasonably quick for the
//lists we are usually using.
//
//The algorithm works as follows:
//def insertion_sort(new, comp, old)
//    if (new.empty) %No new elements. We are at the start. Add the first element from
//                   %old to new and start sorting.
//        ret insertion_sort(new.append(old.first), comp, old.rest)
//    else if (!old.empty) %We have old elements left. Add the first element of the old
//                         %list to new and sort it.
//        ret insertion_sort(insert_sort_swap(list(), comp, new.prepend(old.first)),
//                           comp, old.rest)
//    else %if (old.empty) %We have no old elements left. We are done.
//        ret new
//%we expect the unsorted element to be at the start of old
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
//           ret insert_sort_swap(new.append(old.second), comp,
//                                list().append(old.first).append(old.rest))
template <class New, template <class, class> class Comp, class Old>
struct insert_sort_swap_impl;
//No element to sort left. We are done.
template <class... NewTs, template <class, class> class Comp>
struct insert_sort_swap_impl<sorted_list<NewTs...>, Comp, list<>>
{
    using type = sorted_list<NewTs...>;
};
//One element to sort left. We are done.
template <class... NewTs, template <class, class> class Comp, class OldT>
struct insert_sort_swap_impl<sorted_list<NewTs...>, Comp, list<OldT>>
{
    using type = sorted_list<NewTs..., OldT>;
};
//Two elements to sort left. If they are in the wrong order, swap them. We are done.
template <class... NewTs, template <class, class> class Comp,
          class FirstOldT, class SecondOldT>
struct insert_sort_swap_impl<sorted_list<NewTs...>, Comp, list<FirstOldT, SecondOldT>>
{
    using type = std::conditional_t<
        Comp<FirstOldT, SecondOldT>::value,
        sorted_list<NewTs..., FirstOldT, SecondOldT>,
        sorted_list<NewTs..., SecondOldT, FirstOldT>>;
};
//More than two elements left to sort. If they are in the wrong order, swap them. Continue.
template <class... NewTs, template <class, class> class Comp,
          class FirstOldT, class SecondOldT, class... OldTs>
struct insert_sort_swap_impl<sorted_list<NewTs...>, Comp,
                             list<FirstOldT, SecondOldT, OldTs...>>
    : std::conditional_t<
          Comp<FirstOldT, SecondOldT>::value,
          insert_sort_swap_impl<
              sorted_list<NewTs..., FirstOldT, SecondOldT, OldTs...>,
              Comp,
              list<>>,
          insert_sort_swap_impl<
              sorted_list<NewTs..., SecondOldT>,
              Comp,
              list<FirstOldT, OldTs...>>>
{
};
//Shortcut with correct initialization
template <template <class, class> class Comp, class Old>
using insert_sort_swap = typename insert_sort_swap_impl<sorted_list<>, Comp, Old>::type;
//Basics test
static_assert(std::is_same_v<insert_sort_swap<hash_order, list<int>>, sorted_list<int>>, "type::insert_sort_swap<list<int>> is list<int>.");
static_assert(std::is_same_v<insert_sort_swap<hash_order, list<double, int, float>>, sorted_list<int, float, double>>, "type::insert_sort_swap<list<double, int, float>> is list<int, float, double>.");

template <class New, template <class, class> class Comp, class Old>
struct insertion_sort_impl;
//No element to sort left. We are done.
template <class... NewTs, template <class, class> class Comp>
struct insertion_sort_impl<sorted_list<NewTs...>, Comp, list<>>
{
    using type = sorted_list<NewTs...>;
};
//We got a sorted list. We are done.
template <template <class, class> class Comp, class... OldTs>
struct insertion_sort_impl<sorted_list<>, Comp, sorted_list<OldTs...>>
{
    using type = sorted_list<OldTs...>;
};
//No element has been sorted yet. (New list is empty.) Add the first old element to the
//new list, and start sorting.
template <template <class, class> class Comp, class FirstOld, class... OldTs>
struct insertion_sort_impl<sorted_list<>, Comp, list<FirstOld, OldTs...>>
    : insertion_sort_impl<sorted_list<FirstOld>, Comp, list<OldTs...>>
{
};
//Old list is not empty. Swap/Merge the first old element into the new list, and keep sorting.
template <class FirstNewT, class... NewTs, template <class, class> class Comp,
          class FirstOldT, class... OldTs>
struct insertion_sort_impl<sorted_list<FirstNewT, NewTs...>, Comp,
                           list<FirstOldT, OldTs...>>
    : insertion_sort_impl<
          insert_sort_swap<Comp, list<FirstOldT, FirstNewT, NewTs...>>, Comp,
          list<OldTs...>>
{
};
template <class List, template <class, class> class Comp = hash_order>
using insertion_sort = typename insertion_sort_impl<sorted_list<>, Comp, List>::type;
//Basic tests
static_assert(std::is_same<sorted_list<>, insertion_sort<list<>>>::value, "type::insertion_sort<list<>> is list<>.");
static_assert(std::is_same<sorted_list<int>, insertion_sort<list<int>>>::value, "type::insertion_sort<list<int>> is list<int>.");
static_assert(std::is_same<sorted_list<int, double>, insertion_sort<list<int, double>>>::value, "type::insertion_sort<list<int, double>> is list<int, double>.");
static_assert(std::is_same<sorted_list<int, double>, insertion_sort<list<double, int>>>::value, "type::insertion_sort<list<double, int>> is list<int, double>.");
static_assert(std::is_same<sorted_list<int, int, double>, insertion_sort<list<int, double, int>>>::value, "type::insertion_sort<list<int, double, int>> is list<int, int, double>.");
static_assert(std::is_same<sorted_list<int, float, double>, insertion_sort<list<double, float, int>>>::value, "type::insertion_sort<list<double, float, int>> is list<int, float, double>.");
#pragma endregion
#pragma region global settings
//We use insertion sort with hash_ordering right now.
template <class List, template <class, class> class Comp = hash_order>
using sort = insertion_sort<List, Comp>;
//Basic tests
static_assert(std::is_same<sorted_list<>, sort<list<>>>::value, "type::sort<list<>> is list<>.");
static_assert(std::is_same<sorted_list<int>, sort<list<int>>>::value, "type::sort<list<int>> is list<int>.");
static_assert(std::is_same<sorted_list<int, double>, sort<list<int, double>>>::value, "type::sort<list<int, double>> is list<int, double>.");
static_assert(std::is_same<sorted_list<int, double>, sort<list<double, int>>>::value, "type::sort<list<double, int>> is list<int, double>.");
static_assert(std::is_same<sorted_list<int, int, double>, sort<list<int, double, int>>>::value, "type::sort<list<int, double, int>> is list<int, int, double>.");
static_assert(std::is_same<sorted_list<int, float, double>, sort<list<double, float, int>>>::value, "type::sort<list<double, float, int>> is list<int, float, double>.");
#pragma endregion
} // namespace type
} // namespace benri