#pragma once
#include <cstdint>
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
    constexpr auto size() const { return N; }
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
#pragma warning(push)           //fix msvc warning for this line
#pragma warning(disable : 4100) //we are warned that we are not using index inside the function, but this is on purpose here
#pragma GCC diagnostic push     //apply the same fix for gcc and clang
#pragma GCC diagnostic ignored "-Wunused-parameter"
    constexpr auto &operator[](size_t index) { return data[0]; }
    constexpr const auto &operator[](size_t index) const { return data[0]; }
#pragma GCC diagnostic pop
#pragma warning(pop)
    constexpr auto size() const
    {
        return size_t{0};
    }
    constexpr const auto *begin() const { return data; }
    constexpr const auto *end() const { return data + 0; }
};
//TODO: - Put this into a unit test folder.
//basic tests
static_assert(impl::array<int, 0>{}.size() == 0, "impl::array<int,0> should have zero size.");
static_assert(impl::array<int, 4>{1, 2, 3, 4}.size() == 4, "impl::array<int, 4>{1, 2, 3, 4} should have a size of four.");
static_assert(impl::array<int, 4>{1, 2, 3, 4}[0] == 1 && impl::array<int, 4>{1, 2, 3, 4}[1] == 2 && impl::array<int, 4>{1, 2, 3, 4}[2] == 3 && impl::array<int, 4>{1, 2, 3, 4}[3] == 4, "impl::array<int, 4>{1, 2, 3, 4} should save the right numbers into the array.");
#pragma endregion
#pragma region array generator
//TODO
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
#pragma endregion
} // namespace impl
} // namespace benri