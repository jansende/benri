#pragma once
#include <cstdint>
#include <initializer_list>
#include <iterator>

namespace benri
{
namespace impl
{
#pragma region array
//The custom array type provides a constepxr, because for some
//reason the std::array is not constexpr.
template <class T, size_t N>
struct array
{
    using value_type = T;
    T data[N];
    constexpr array() = default;
    constexpr auto &operator[](size_t index) { return data[index]; }
    constexpr const auto &operator[](size_t index) const { return data[index]; }
    constexpr const auto size() const { return N; }
    constexpr const auto *begin() const { return data; }
    constexpr const auto *end() const { return data + N; }
};
template <class T>
struct array<T, 0>
{
    //This is a specialization to prevent breaking the code for arrays with length of 0.
    using value_type = T;
    T data[1];
    constexpr array() = default;
    constexpr auto &operator[](size_t index) { return data[0]; }
    constexpr const auto &operator[](size_t index) const { return data[0]; }
    constexpr const auto size() const { return size_t{0}; }
    constexpr const auto *begin() const { return nullptr; }
    constexpr const auto *end() const { return nullptr; }
};
//TODO: - Put this into a unit test folder.
//basic tests
static_assert(impl::array<int, 0>{}.size() == 0, "impl::array<int,0> should have zero size.");
static_assert(impl::array<int, 4>{1, 2, 3, 4}.size() == 4, "impl::array<int, 4>{1, 2, 3, 4} should have a size of four.");
static_assert(impl::array<int, 4>{1, 2, 3, 4}[0] == 1 && impl::array<int, 4>{1, 2, 3, 4}[1] == 2 && impl::array<int, 4>{1, 2, 3, 4}[2] == 3 && impl::array<int, 4>{1, 2, 3, 4}[3] == 4, "impl::array<int, 4>{1, 2, 3, 4} should save the right numbers into the array.");
#pragma endregion
#pragma region array generator
//The make_integer_array function creates a custom array from a list
//of integers.
template <class T, T... nums>
struct make_integer_array_impl
{
    static constexpr auto value = impl::array<T, sizeof...(nums)>{nums...};
};
template <class T, T... nums>
constexpr impl::array<T, sizeof...(nums)> make_integer_array = make_integer_array_impl<T, nums...>::value;
template <class T, size_t N>
constexpr auto make_index_array_impl()
{
    auto val = impl::array<T, N>{};
    for (auto i = size_t{0}; i < N; ++i)
        val[i] = static_cast<T>(i);
    return val;
}
template <class T, size_t N>
constexpr auto make_index_array = make_index_array_impl<T, N>();
//TODO: - Put this into a unit test folder.
//basic tests
static_assert(make_integer_array<int>.size() == 0, "make_integer_array<int> should have zero size.");
static_assert(make_integer_array<int, 1, 2, 3, 4>.size() == 4, "make_integer_array<int, 1, 2, 3, 4> should have a size of four.");
static_assert(make_integer_array<int, 1, 2, 3, 4>[0] == 1 && make_integer_array<int, 1, 2, 3, 4>[1] == 2 && make_integer_array<int, 1, 2, 3, 4>[2] == 3 && make_integer_array<int, 1, 2, 3, 4>[3] == 4, "make_integer_array<int, 1, 2, 3, 4> should save the right numbers into the array.");
#pragma endregion
} // namespace impl
} // namespace benri