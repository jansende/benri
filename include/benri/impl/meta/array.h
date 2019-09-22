#pragma once
#include <benri/impl/meta/algorithm.h>
#include <cstdint>
#include <functional>
#include <iterator>

namespace benri
{
namespace meta
{
#pragma region array
// Custom constexpr version of std::array because the standard is not there yet.
template <class T, size_t N>
struct array
{
    using value_type = T;
    T data[N > 1 ? N : 1]; // We need to make sure to have some data, to not break
                           // for N == 0.
    constexpr array() = default;
    constexpr auto&       operator[](size_t index) { return data[index]; }
    constexpr const auto& operator[](size_t index) const { return data[index]; }
    constexpr auto        size() const { return N; }
    constexpr const auto* begin() const { return data; }
    constexpr const auto* end() const { return data + N; }
};
// Basic tests
static_assert(meta::array<int, 0>{}.size() == 0, "meta::array<int,0> has zero size.");
static_assert(meta::array<int, 4>{1, 2, 3, 4}.size() == 4,
              "meta::array<int, 4>{1, 2, 3, 4} has a size of four.");
static_assert(
    meta::array<int, 4>{1, 2, 3, 4}[0] == 1 && meta::array<int, 4>{1, 2, 3, 4}[1] == 2
        && meta::array<int, 4>{1, 2, 3, 4}[2] == 3
        && meta::array<int, 4>{1, 2, 3, 4}[3] == 4,
    "meta::array<int, 4>{1, 2, 3, 4} constructs the right values in the array.");
#pragma endregion
#pragma region algorithms
// Special overloads to use meta::aray with the meta::algorithms directly
// because using the array pointers is too cumbersome for static_asserts. Plus
// basic test for the actual meta::algorithms.

template <class T, size_t N>
constexpr auto accumulate(meta::array<T, N> vals, T init) -> T
{
    return meta::accumulate(vals.begin(), vals.end(), init);
}
template <class T, size_t N, class BinaryOperation>
constexpr auto accumulate(meta::array<T, N> vals, T init, BinaryOperation op) -> T
{
    return meta::accumulate(vals.begin(), vals.end(), init, op);
}
static_assert(meta::accumulate(array<int, 3>{1, 2, 3}, 4) == 10,
              "meta::accumulate({1,2,3},4) sums up to 10.");
static_assert(meta::accumulate(array<int, 3>{1, 2, 3}, 4, std::multiplies<int>{}) == 24,
              "meta::accumulate({1,2,3},4,*) multiplies up to 24.");

template <class T, size_t N, size_t M>
constexpr auto equal(meta::array<T, N> vals1, meta::array<T, M> vals2) -> bool
{
    return meta::equal(vals1.begin(), vals1.end(), vals2.begin(), vals2.end());
}
template <class T, size_t N, size_t M, class BinaryPredicate>
constexpr auto equal(meta::array<T, N> vals1, meta::array<T, M> vals2, BinaryPredicate p)
    -> bool
{
    return meta::equal(vals1.begin(), vals1.end(), vals2.begin(), vals2.end(), p);
}
static_assert(meta::equal(meta::array<int, 3>{1, 2, 3}, meta::array<int, 3>{1, 2, 3}),
              "meta::equal({1,2,3},{1,2,3}) is true.");
static_assert(!meta::equal(meta::array<int, 3>{1, 2, 3}, meta::array<int, 3>{3, 2, 1}),
              "meta::equal({1,2,3},{3,2,1}) is false.");
static_assert(!meta::equal(meta::array<int, 3>{1, 2, 3}, meta::array<int, 1>{1}),
              "meta::equal({1,2,3},{1}) is false.");
static_assert(meta::equal(meta::array<int, 3>{1, 2, 3}, meta::array<int, 3>{1, 2, 3},
                          std::equal_to<int>{}),
              "meta::equal({1,2,3},{1,2,3}, =) is true.");
static_assert(!meta::equal(meta::array<int, 3>{1, 2, 3}, meta::array<int, 3>{3, 2, 1},
                           std::equal_to<int>{}),
              "meta::equal({1,2,3},{3,2,1}, =) is false.");
static_assert(!meta::equal(meta::array<int, 3>{1, 2, 3}, meta::array<int, 1>{1},
                           std::equal_to<int>{}),
              "meta::equal({1,2,3},{1}, =) is false.");

template <class T, size_t N, size_t M>
constexpr auto lexicographical_compare(meta::array<T, N> vals1, meta::array<T, M> vals2)
    -> bool
{
    return meta::lexicographical_compare(vals1.begin(), vals1.end(), vals2.begin(),
                                         vals2.end());
}
template <class T, size_t N, size_t M, class Compare>
constexpr auto lexicographical_compare(meta::array<T, N> vals1, meta::array<T, M> vals2,
                                       Compare comp) -> bool
{
    return meta::lexicographical_compare(vals1.begin(), vals1.end(), vals2.begin(),
                                         vals2.end(), comp);
}
static_assert(!meta::lexicographical_compare(meta::array<int, 3>{1, 2, 3},
                                             meta::array<int, 3>{1, 2, 3}),
              "meta::lexicographical_compare({1,2,3},{1,2,3}) is false.");
static_assert(meta::lexicographical_compare(meta::array<int, 3>{1, 2, 3},
                                            meta::array<int, 3>{3, 2, 1}),
              "meta::lexicographical_compare({1,2,3},{3,2,1}) is true.");
static_assert(!meta::lexicographical_compare(meta::array<int, 3>{1, 2, 3},
                                             meta::array<int, 1>{1}),
              "meta::lexicographical_compare({1,2,3},{1}) is false.");
static_assert(meta::lexicographical_compare(meta::array<int, 3>{1, 2, 3},
                                            meta::array<int, 1>{2}),
              "meta::lexicographical_compare({1,2,3},{2}) is true.");
static_assert(meta::lexicographical_compare(meta::array<int, 1>{1},
                                            meta::array<int, 3>{1, 2, 3}),
              "meta::lexicographical_compare({1},{1,2,3}) is true.");
static_assert(!meta::lexicographical_compare(meta::array<int, 1>{2},
                                             meta::array<int, 3>{1, 2, 3}),
              "meta::lexicographical_compare({2},{1,2,3}) is false.");
static_assert(!meta::lexicographical_compare(meta::array<int, 3>{1, 2, 3},
                                             meta::array<int, 3>{1, 2, 3},
                                             std::less<int>{}),
              "meta::lexicographical_compare({1,2,3},{1,2,3},<) is false.");
static_assert(meta::lexicographical_compare(meta::array<int, 3>{1, 2, 3},
                                            meta::array<int, 3>{3, 2, 1},
                                            std::less<int>{}),
              "meta::lexicographical_compare({1,2,3},{3,2,1},<) is true.");
static_assert(!meta::lexicographical_compare(meta::array<int, 3>{1, 2, 3},
                                             meta::array<int, 1>{1}, std::less<int>{}),
              "meta::lexicographical_compare({1,2,3},{1},<) is false.");
static_assert(meta::lexicographical_compare(meta::array<int, 3>{1, 2, 3},
                                            meta::array<int, 1>{2}, std::less<int>{}),
              "meta::lexicographical_compare({1,2,3},{2},<) is true.");
static_assert(meta::lexicographical_compare(meta::array<int, 1>{1},
                                            meta::array<int, 3>{1, 2, 3},
                                            std::less<int>{}),
              "meta::lexicographical_compare({1},{1,2,3},<) is true.");
static_assert(!meta::lexicographical_compare(meta::array<int, 1>{2},
                                             meta::array<int, 3>{1, 2, 3},
                                             std::less<int>{}),
              "meta::lexicographical_compare({2},{1,2,3},<) is false.");
#pragma endregion
} // namespace meta
} // namespace benri