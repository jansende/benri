#pragma once
#include <benri/impl/type/traits.h>

namespace benri
{
namespace type
{
#pragma region list
// Type list used to store dimensions and prefixes.
template <class... Elements>
struct list
{
};
// Special name for sorted type lists.
template <class... Elements>
struct sorted_list
{
};
#pragma endregion
#pragma region functions
// Function for concatenating two lists.
template <class... lhsElements, class... rhsElements>
constexpr auto concat_impl(sorted_list<lhsElements...>, sorted_list<rhsElements...>)
    -> list<lhsElements..., rhsElements...>;
template <class... lhsElements, class... rhsElements>
constexpr auto concat_impl(list<lhsElements...>, sorted_list<rhsElements...>)
    -> list<lhsElements..., rhsElements...>;
template <class... lhsElements, class... rhsElements>
constexpr auto concat_impl(sorted_list<lhsElements...>, list<rhsElements...>)
    -> list<lhsElements..., rhsElements...>;
template <class... lhsElements, class... rhsElements>
constexpr auto concat_impl(list<lhsElements...>, list<rhsElements...>)
    -> list<lhsElements..., rhsElements...>;
template <class lhs, class rhs>
using concat = decltype(concat_impl(lhs{}, rhs{}));
// Basic tests
static_assert(std::is_same<concat<list<int>, list<>>, list<int>>::value,
              "type::concat<list<int>, list<>> is list<int>.");
static_assert(std::is_same<concat<list<int, float, bool>, list<int, float>>,
                           list<int, float, bool, int, float>>::value,
              "type::concat<list<int, float, bool>, list<int, float>> is "
              "list<int, float, bool, int, float>.");
#pragma endregion
} // namespace type
} // namespace benri