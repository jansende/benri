#pragma once
#include <benri/impl/array.h>

namespace benri
{
namespace impl
{
#pragma region custom accumulate
//copied from: https://en.cppreference.com/w/cpp/algorithm/accumulate
template <class InputIt, class T>
constexpr auto accumulate(InputIt first, InputIt last, T init)
{
    for (; first != last; ++first)
        init = std::move(init) + *first;
    return init;
}
template <class InputIt, class T, class BinaryOperation>
constexpr auto accumulate(InputIt first, InputIt last, T init, BinaryOperation op)
{
    for (; first != last; ++first)
        init = op(std::move(init), *first);
    return init;
}
//custom accumulate for the custom array type
template <class T, size_t N>
constexpr auto accumulate(impl::array<T, N> vals, T init)
{
    //std::begin and std::end don't work here. thus we use .begin() and .end() instead
    return impl::accumulate(vals.begin(), vals.end(), init);
}
template <class T, size_t N, class BinaryOperation>
constexpr auto accumulate(impl::array<T, N> vals, T init, BinaryOperation op)
{
    //std::begin and std::end don't work here. thus we use .begin() and .end() instead
    return impl::accumulate(vals.begin(), vals.end(), init, op);
}
//TODO: - Put this into a unit test folder.
//basic tests
static_assert(impl::accumulate(array<int, 3>{1, 2, 3}, 4) == 10, "accumulate({1,2,3},4) should sum up to 10.");
static_assert(impl::accumulate(array<int, 3>{1, 2, 3}, 4, std::multiplies<int>()) == 24, "accumulate({1,2,3},4,*) should multiply up to 24.");
#pragma endregion
#pragma region custom swap
template <class T>
constexpr auto constexpr_swap(T &lhs, T &rhs)
{
    auto temp = lhs;
    lhs = rhs;
    rhs = temp;
}
#pragma endregion
#pragma region equal
//copied from: https://en.cppreference.com/w/cpp/algorithm/equal
template <class InputIt1, class InputIt2>
constexpr auto equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
{
    for (; first1 != last1 && first2 != last2 && *first1 == *first2; ++first1, ++first2)
        ;
    return first1 == last1 && first2 == last2;
}
//custom equal for the custom array type
template <class T, size_t N, size_t M>
constexpr auto equal(impl::array<T, N> vals1, impl::array<T, M> vals2)
{
    //std::begin and std::end don't work here. thus we use .begin() and .end() instead
    return (N == 0 || M == 0) ? (N == M) : (N == M && impl::equal(vals1.begin(), vals1.end(), vals2.begin(), vals2.end()));
}
//TODO: - Put this into a unit test folder.
//basic tests
static_assert(impl::equal(impl::array<int, 3>{1, 2, 3}, impl::array<int, 3>{1, 2, 3}), "equal({1,2,3},{1,2,3}) should be true.");
static_assert(!impl::equal(impl::array<int, 3>{1, 2, 3}, impl::array<int, 3>{3, 2, 1}), "equal({1,2,3},{3,2,1}) should be false.");
static_assert(!impl::equal(impl::array<int, 3>{1, 2, 3}, impl::array<int, 1>{1}), "equal({1,2,3},{1}) should be false.");
#pragma endregion
#pragma region product
//The product function calculates the product of all given numbers
//in a vector type.
template <class T, size_t N>
constexpr auto product(impl::array<T, N> vals)
{
    //std::begin and std::end don't work here. thus we use .begin() and .end() instead
    return impl::accumulate(vals.begin(), vals.end(), T{1}, std::multiplies<T>());
}
template <class T>
constexpr auto product(impl::array<T, 0>)
{
    return T{1};
}
#pragma endregion
} // namespace impl
} // namespace benri