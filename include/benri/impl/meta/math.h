#pragma once
#include <benri/impl/type/traits.h>
#include <ratio>
#include <type_traits>

namespace benri
{
namespace meta
{
#pragma region powers
// Function for calculating powers of a given base value at compile time. Powers
// are std::ratio types. Base values can be integral or floating point values,
// std::ratios or struct with a ::value attribute. Currently only integer powers
// are supported.
template <class T, class Base, intmax_t ExponentNum>
constexpr auto power_impl(Base value, std::ratio<ExponentNum, 1>) -> std::enable_if_t<
    std::is_integral<Base>::value || std::is_floating_point<Base>::value, T>
{
    auto val      = static_cast<T>(value);
    auto exponent = ExponentNum >= 0 ? ExponentNum : -ExponentNum;
    for (; exponent > 1; --exponent)
    {
        val *= static_cast<T>(value);
    }
    return ExponentNum >= 0 ? (val) : (T{1} / val);
}
template <class T, class Base, intmax_t ExponentNum>
constexpr auto power_impl(Base, std::ratio<ExponentNum, 1>)
    -> std::enable_if_t<type::detect_if<Base, type::has_value>, T>
{
    return power_impl<T>(Base::value, std::ratio<ExponentNum, 1>{});
}

template <class T, intmax_t BaseNum, intmax_t BaseDen, intmax_t ExponentNum>
constexpr auto power_impl(std::ratio<BaseNum, BaseDen>, std::ratio<ExponentNum, 1>) -> T
{
    auto num      = static_cast<T>(BaseNum);
    auto den      = static_cast<T>(BaseDen);
    auto exponent = ExponentNum >= 0 ? ExponentNum : -ExponentNum;
    for (; exponent > 1; --exponent)
    {
        num *= static_cast<T>(BaseNum);
        den *= static_cast<T>(BaseDen);
    }
    return ExponentNum >= 0 ? (num / den) : (den / num);
}
template <class T, class Base, class Exponent>
constexpr T pow = power_impl<T>(Base{}, Exponent{});
// Basic tests
static_assert(pow<float, std::ratio<1, 2>, std::ratio<2>> == 0.25f,
              "pow<1/2, 2> is 1/4.");
static_assert(pow<float, std::ratio<3>, std::ratio<5>> == 243.f, "pow<3, 5> is 243.");
#pragma endregion
#pragma region prime numbers
// Function for checking if a number is prime.
template <class T>
static constexpr auto is_prime_impl(const T& number)
    -> std::enable_if_t<std::is_integral<T>::value, bool>
{
    auto test = T{2};
    for (; test * test <= number && number % test != 0; ++test)
        ;
    // Negative numbers are never prime.
    return number <= 1 ? false : test * test > number;
}
template <intmax_t Num>
constexpr bool is_prime = is_prime_impl(Num);
// Basic tests
static_assert(is_prime<0> == false, "0 is not prime.");
static_assert(is_prime<1> == false, "1 is not prime.");
static_assert(is_prime<2> == true, "2 is prime.");
static_assert(is_prime<3> == true, "3 is prime.");
static_assert(is_prime<4> == false, "4 is not prime.");
static_assert(is_prime<5> == true, "5 is prime.");
static_assert(is_prime<6> == false, "6 is not prime.");
static_assert(is_prime<7> == true, "7 is prime.");
static_assert(is_prime<8> == false, "8 is not prime.");
static_assert(is_prime<9> == false, "9 is not prime.");
static_assert(is_prime<10> == false, "10 is not prime.");
static_assert(is_prime<11> == true, "11 is prime.");
static_assert(is_prime<12> == false, "12 is not prime.");
static_assert(is_prime<13> == true, "13 is prime.");
static_assert(is_prime<14> == false, "14 is not prime.");
static_assert(is_prime<15> == false, "15 is not prime.");
static_assert(is_prime<19> == true, "19 is prime.");
static_assert(is_prime<100> == false, "100 is not prime.");
static_assert(is_prime<293339> == true, "293339 is prime.");
// Function for calculating the next prime after a given number. (The given
// number does not have to be prime.)
template <class T>
constexpr auto next_prime_impl(T number)
    -> std::enable_if_t<std::is_integral<T>::value, T>
{
    for (++number; !is_prime_impl(number); ++number)
        ;
    return number;
}
template <intmax_t Num>
constexpr intmax_t next_prime = next_prime_impl(Num);
// Basic tests
static_assert(next_prime<0> == 2, "2 is the next prime after 0.");
static_assert(next_prime<1> == 2, "2 is the next prime after 1.");
static_assert(next_prime<2> == 3, "3 is the next prime after 2.");
static_assert(next_prime<3> == 5, "5 is the next prime after 3.");
static_assert(next_prime<4> == 5, "5 is the next prime after 4.");
static_assert(next_prime<5> == 7, "7 is the next prime after 5.");
static_assert(next_prime<6> == 7, "7 is the next prime after 6.");
static_assert(next_prime<7> == 11, "11 is the next prime after 7.");
static_assert(next_prime<8> == 11, "11 is the next prime after 8.");
static_assert(next_prime<9> == 11, "11 is the next prime after 9.");
static_assert(next_prime<10> == 11, "11 is the next prime after 10.");
static_assert(next_prime<11> == 13, "13 is the next prime after 11.");
static_assert(next_prime<12> == 13, "13 is the next prime after 12.");
static_assert(next_prime<13> == 17, "17 is the next prime after 13.");
static_assert(next_prime<14> == 17, "17 is the next prime after 14.");
static_assert(next_prime<15> == 17, "17 is the next prime after 15.");
static_assert(next_prime<17> == 19, "19 is the next prime after 17.");
#pragma endregion
#pragma region prime prime_factors
// Function for calculating the number of prime factors for a given number.
constexpr auto number_of_prime_factors_impl(intmax_t number) -> size_t
{
    auto counter = size_t{0};
    for (auto test = intmax_t{2}; number > 1;)
    {
        if (number % test == 0)
        {
            ++counter;
            number /= test;
        }
        else
        {
            test = next_prime_impl(test);
        }
    }
    return counter;
}
template <intmax_t Num>
constexpr size_t number_of_prime_factors = number_of_prime_factors_impl(Num);
// Basic tests
static_assert(number_of_prime_factors<0> == 0, "0 has no prime factors.");
static_assert(number_of_prime_factors<1> == 0, "1 has no prime factors.");
static_assert(number_of_prime_factors<2> == 1, "2 has one prime factor.");
static_assert(number_of_prime_factors<3> == 1, "3 has one prime factor.");
static_assert(number_of_prime_factors<4> == 2, "4 has two prime factors.");
static_assert(number_of_prime_factors<5> == 1, "5 has one prime factor.");
static_assert(number_of_prime_factors<6> == 2, "6 has two prime factors.");
static_assert(number_of_prime_factors<7> == 1, "7 has one prime factor.");
static_assert(number_of_prime_factors<8> == 3, "8 has three prime factors.");
static_assert(number_of_prime_factors<9> == 2, "9 has two prime factors");
static_assert(number_of_prime_factors<10> == 2, "10 has two prime factors");
static_assert(number_of_prime_factors<11> == 1, "11 has one prime factor.");
static_assert(number_of_prime_factors<12> == 3, "12 has three prime factors");
static_assert(number_of_prime_factors<13> == 1, "13 has one prime factor.");
static_assert(number_of_prime_factors<14> == 2, "14 has two prime factors");
static_assert(number_of_prime_factors<15> == 2, "15 has two prime factors.");
static_assert(number_of_prime_factors<64> == 6, "64 has six prime factors.");
static_assert(number_of_prime_factors<100> == 4, "100 has four prime factors.");
// Function for calculating the prime factors of a given number. Due to compile
// time constraints the number of prime factors has to be given in advance.
template <size_t N>
constexpr auto prime_factors_impl(intmax_t number) -> meta::array<intmax_t, N>
{
    auto factors = meta::array<intmax_t, N>{};
    auto counter = size_t{0};
    for (auto test = intmax_t{2}; number > 1;)
    {
        if (number % test == 0)
        {
            factors[counter] = test;
            ++counter;
            number /= test;
        }
        else
        {
            test = next_prime_impl(test);
        }
    }
    return factors;
}
// Basic tests
static_assert(meta::equal(prime_factors_impl<0>(0), meta::array<intmax_t, 0>{}),
              "0 has no prime factors.");
static_assert(meta::equal(prime_factors_impl<0>(1), meta::array<intmax_t, 0>{}),
              "1 has no prime factors.");
static_assert(meta::equal(prime_factors_impl<1>(2), meta::array<intmax_t, 1>{2}),
              "2 has prime factor {2}.");
static_assert(meta::equal(prime_factors_impl<1>(3), meta::array<intmax_t, 1>{3}),
              "3 has prime factor {3}.");
static_assert(meta::equal(prime_factors_impl<2>(4), meta::array<intmax_t, 2>{2, 2}),
              "4 has prime factors {2, 2}.");
static_assert(meta::equal(prime_factors_impl<1>(5), meta::array<intmax_t, 1>{5}),
              "5 has prime factor {5}.");
static_assert(meta::equal(prime_factors_impl<2>(6), meta::array<intmax_t, 2>{2, 3}),
              "6 has prime factors {2, 3}.");
static_assert(meta::equal(prime_factors_impl<1>(7), meta::array<intmax_t, 1>{7}),
              "7 has prime factor {7}.");
static_assert(meta::equal(prime_factors_impl<3>(8), meta::array<intmax_t, 3>{2, 2, 2}),
              "8 has prime factors {2, 2, 2}.");
static_assert(meta::equal(prime_factors_impl<2>(9), meta::array<intmax_t, 2>{3, 3}),
              "9 has prime factors {3, 3}.");
static_assert(meta::equal(prime_factors_impl<2>(10), meta::array<intmax_t, 2>{2, 5}),
              "10 has prime factors {2, 5}.");
static_assert(meta::equal(prime_factors_impl<1>(11), meta::array<intmax_t, 1>{11}),
              "11 has prime factor {11}.");
static_assert(meta::equal(prime_factors_impl<3>(12), meta::array<intmax_t, 3>{2, 2, 3}),
              "12 has prime factors {2, 2, 3}.");
static_assert(meta::equal(prime_factors_impl<1>(13), meta::array<intmax_t, 1>{13}),
              "13 has prime factor {13}.");
static_assert(meta::equal(prime_factors_impl<2>(14), meta::array<intmax_t, 2>{2, 7}),
              "14 has prime factors {2, 7}.");
static_assert(meta::equal(prime_factors_impl<2>(15), meta::array<intmax_t, 2>{3, 5}),
              "15 has prime factors {3, 5}.");
static_assert(meta::equal(prime_factors_impl<6>(64),
                          meta::array<intmax_t, 6>{2, 2, 2, 2, 2, 2}),
              "64 has prime factors {2, 2, 2, 2, 2, 2}.");
static_assert(meta::equal(prime_factors_impl<4>(100),
                          meta::array<intmax_t, 4>{2, 2, 5, 5}),
              "100 has prime factors {2, 2, 5, 5}.");
// Helper function for putting the calculate prime factors into a
// std::integer_sequence.
template <intmax_t number, size_t... Index>
constexpr auto prime_factors_to_integer_sequence(std::integer_sequence<size_t, Index...>)
{
    return std::integer_sequence<intmax_t, prime_factors_impl<sizeof...(Index)>(
                                               number)[Index]...>{};
}
template <intmax_t number>
using prime_factors = decltype(prime_factors_to_integer_sequence<number>(
    std::make_index_sequence<number_of_prime_factors<number>>{}));
// Basic tests
static_assert(std::is_same<prime_factors<1>, std::integer_sequence<intmax_t>>::value,
              "prime_factors<1> is <>.");
static_assert(std::is_same<prime_factors<2>, std::integer_sequence<intmax_t, 2>>::value,
              "prime_factors<2> is <2>.");
static_assert(
    std::is_same<prime_factors<4>, std::integer_sequence<intmax_t, 2, 2>>::value,
    "prime_factors<4> is <2, 2>.");
static_assert(
    std::is_same<prime_factors<6>, std::integer_sequence<intmax_t, 2, 3>>::value,
    "prime_factors<6> is <2, 3>.");
static_assert(
    std::is_same<prime_factors<8>, std::integer_sequence<intmax_t, 2, 2, 2>>::value,
    "prime_factors<8> is <2, 2, 2>.");
static_assert(std::is_same<prime_factors<17>, std::integer_sequence<intmax_t, 17>>::value,
              "prime_factors<17> is <17>.");
static_assert(
    std::is_same<prime_factors<30>, std::integer_sequence<intmax_t, 2, 3, 5>>::value,
    "prime_factors<30> is <2, 3, 5>.");
#pragma endregion
} // namespace meta
} // namespace benri