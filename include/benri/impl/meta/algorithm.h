#pragma once
#include <memory>

namespace benri
{
namespace meta
{
//Custom constexpr version of std::accumulate because the standard is not there yet.
//Copied from: https://en.cppreference.com/w/cpp/algorithm/accumulate
template <class InputIt, class T>
constexpr auto accumulate(InputIt first, InputIt last,
                          T init) -> T
{
    for (; first != last; ++first)
        init = std::move(init) + *first;
    return init;
}
template <class InputIt, class T, class BinaryOperation>
constexpr auto accumulate(InputIt first, InputIt last,
                          T init, BinaryOperation op) -> T
{
    for (; first != last; ++first)
        init = op(std::move(init), *first);
    return init;
}
//Custom constexpr version of std::equal because the standard is not there yet.
//Copied from: https://en.cppreference.com/w/cpp/algorithm/equal
template <class InputIt1, class InputIt2>
constexpr auto equal(InputIt1 first1, InputIt1 last1,
                     InputIt2 first2, InputIt2 last2) -> bool
{
    for (; first1 != last1 && first2 != last2 && *first1 == *first2; ++first1, ++first2)
        ;
    return first1 == last1 && first2 == last2;
}
template <class InputIt1, class InputIt2, class BinaryPredicate>
constexpr auto equal(InputIt1 first1, InputIt1 last1,
                     InputIt2 first2, InputIt2 last2, BinaryPredicate p) -> bool
{
    for (; first1 != last1 && first2 != last2 && p(*first1, *first2); ++first1, ++first2)
        ;
    return first1 == last1 && first2 == last2;
}
//Custom constexpr version of std::lexicographical_compare because we only get it in c++17
//plus the standard has no constexpr version yet.
//Copied from: https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare
template <class InputIt1, class InputIt2>
constexpr auto lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                       InputIt2 first2, InputIt2 last2) -> bool
{
    for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2)
    {
        if (*first1 < *first2)
            return true;
        if (*first2 < *first1)
            return false;
    }
    return (first1 == last1) && (first2 != last2);
}
template <class InputIt1, class InputIt2, class Compare>
constexpr auto lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                       InputIt2 first2, InputIt2 last2,
                                       Compare comp) -> bool
{
    for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2)
    {
        if (comp(*first1, *first2))
            return true;
        if (comp(*first2, *first1))
            return false;
    }
    return (first1 == last1) && (first2 != last2);
}
} // namespace meta
} // namespace benri