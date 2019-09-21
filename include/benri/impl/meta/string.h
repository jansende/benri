#pragma once
#include <benri/impl/meta/algorithm.h>

namespace benri
{
namespace meta
{
#pragma region static string
// Custom constexpr version of std::string because the standard is not there
// yet.
struct static_string
{
    template <size_t N>
    constexpr static_string(const char (&str)[N]) : m_size(N - 1), data(&str[0])
    {
    }
    constexpr size_t      size() const { return m_size; }
    constexpr const char* c_str() const { return data; }
    const size_t          m_size;
    const char*           data = nullptr;
};
// Custom constexpr version of std::strcmp because the standard is not there
// yet.
constexpr auto strcmp(static_string lhs, static_string rhs) -> int
{
    return lexicographical_compare(lhs.c_str(), lhs.c_str() + lhs.size(), rhs.c_str(),
                                   rhs.c_str() + rhs.size())
               ? -1
               : (lexicographical_compare(rhs.c_str(), rhs.c_str() + rhs.size(),
                                          lhs.c_str(), lhs.c_str() + lhs.size())
                      ? 1
                      : 0);
}
// Basic tests
static_assert(strcmp(static_string("A"), static_string("A")) == 0,
              "strcmp(\"A\",\"A\") should be 0");
static_assert(strcmp(static_string("A"), static_string("B")) == -1,
              "strcmp(\"A\",\"B\") should be -1");
static_assert(strcmp(static_string("B"), static_string("A")) == 1,
              "strcmp(\"B\",\"A\") should be 1");
static_assert(strcmp(static_string("B"), static_string("B")) == 0,
              "strcmp(\"B\",\"B\") should be 0");
#pragma endregion
} // namespace meta
} // namespace benri