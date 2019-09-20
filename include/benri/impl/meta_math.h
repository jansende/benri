#pragma once
#include <benri/impl/meta/array.h>
#include <benri/impl/meta/algorithm.h>
#include <benri/impl/type/traits.h>
#include <ratio>
#include <utility>

namespace benri
{
namespace impl
{
#pragma region compile time pow
//The power_impl function implements the actual power calculation for
//the power function. It handles two cases: the case of std::ratio as
//the Base type, and a Base with a static constexpr ::value for it.
template <class T, class Base, class Exponent>
constexpr auto power_impl() -> std::enable_if_t<!type::detect_if<Base, type::is_std_ratio>, T>
{
    //handle constants
    static_assert(type::detect_if<Base, type::has_value>, "power takes a value type, a std::ratio or a static constexpr ::value type, and another std::ratios, but Base is neither a std::ratio nor a static constexpr ::value type");
    static_assert(type::detect_if<Exponent, type::is_std_ratio>, "power takes a value type, a std::ratio or a static constexpr ::value type, and another std::ratios, but Exponent is not a std::ratio");
    static_assert(Exponent::den == 1, "power is only able to calculate integer powers, roots are not supported.");
    auto val = T(Base::value);
    auto exponent = Exponent::num >= 0 ? Exponent::num : -Exponent::num;
    for (; exponent > 1; --exponent)
    {
        val *= T(Base::value);
    }
    return Exponent::num >= 0 ? (val) : (1 / val);
}
template <class T, class Base, class Exponent>
constexpr auto power_impl() -> std::enable_if_t<type::detect_if<Base, type::is_std_ratio>, T>
{
    //handle ratios
    static_assert(type::detect_if<Exponent, type::is_std_ratio>, "power takes a value type, a std::ratio or a static constexpr ::value type, and another std::ratios, but Exponent is not a std::ratio");
    static_assert(Exponent::den == 1, "power is only able to calculate integer powers, roots are not supported.");
    auto num = T(Base::num);
    auto den = T(Base::den);
    auto exponent = Exponent::num >= 0 ? Exponent::num : -Exponent::num;
    for (; exponent > 1; --exponent)
    {
        num *= T(Base::num);
        den *= T(Base::den);
    }
    return Exponent::num >= 0 ? (num / den) : (den / num);
}
template <class T, class Base, class Exponent>
constexpr T power = power_impl<T, Base, Exponent>();
#pragma endregion
#pragma region primes
//The is_prime function lets you check if a number is prime.
template <class T>
static constexpr auto is_prime_impl(const T &number) -> std::enable_if_t<std::is_integral<T>::value, bool>
{
    auto test = T{2};
    for (; test * test <= number && number % test != 0; ++test)
        ;
    //negative numbers are never prime.
    return number <= 1 ? false : test * test > number;
}
template <intmax_t Num>
constexpr bool is_prime = is_prime_impl(Num);
//TODO: - Put this into a unit test folder.
//basic tests
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
//The next_prime function calculates the next prime number after
//the given number. The given number does no have to be prime.
template <class T>
static constexpr auto next_prime_impl(T number) -> std::enable_if_t<std::is_integral<T>::value, T>
{
    for (++number; !is_prime_impl(number); ++number)
        ;
    return number;
}
template <intmax_t Num>
constexpr intmax_t next_prime = next_prime_impl(Num);
//TODO: - Put this into a unit test folder.
//basic tests
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
#pragma region factorization
constexpr auto number_of_factors_impl(intmax_t number)
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
constexpr size_t number_of_factors = number_of_factors_impl(Num);
//TODO
static_assert(number_of_factors<0> == 0, "");
static_assert(number_of_factors<1> == 0, "");
static_assert(number_of_factors<2> == 1, "");
static_assert(number_of_factors<3> == 1, "");
static_assert(number_of_factors<4> == 2, "");
static_assert(number_of_factors<5> == 1, "");
static_assert(number_of_factors<6> == 2, "");
static_assert(number_of_factors<7> == 1, "");
static_assert(number_of_factors<8> == 3, "");
static_assert(number_of_factors<9> == 2, "");
static_assert(number_of_factors<10> == 2, "");
static_assert(number_of_factors<11> == 1, "");
static_assert(number_of_factors<12> == 3, "");
static_assert(number_of_factors<13> == 1, "");
static_assert(number_of_factors<14> == 2, "");
static_assert(number_of_factors<15> == 2, "");

template <size_t N>
constexpr auto factorization_factors(intmax_t number)
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
static_assert(meta::equal(factorization_factors<0>(0), meta::array<intmax_t, 0>{}), "");
static_assert(meta::equal(factorization_factors<0>(1), meta::array<intmax_t, 0>{}), "");
static_assert(meta::equal(factorization_factors<1>(2), meta::array<intmax_t, 1>{2}), "");
static_assert(meta::equal(factorization_factors<1>(3), meta::array<intmax_t, 1>{3}), "");
static_assert(meta::equal(factorization_factors<2>(4), meta::array<intmax_t, 2>{2, 2}), "");
static_assert(meta::equal(factorization_factors<1>(5), meta::array<intmax_t, 1>{5}), "");
static_assert(meta::equal(factorization_factors<2>(6), meta::array<intmax_t, 2>{2, 3}), "");
static_assert(meta::equal(factorization_factors<1>(7), meta::array<intmax_t, 1>{7}), "");
static_assert(meta::equal(factorization_factors<3>(8), meta::array<intmax_t, 3>{2, 2, 2}), "");
static_assert(meta::equal(factorization_factors<2>(9), meta::array<intmax_t, 2>{3, 3}), "");
static_assert(meta::equal(factorization_factors<2>(10), meta::array<intmax_t, 2>{2, 5}), "");
static_assert(meta::equal(factorization_factors<1>(11), meta::array<intmax_t, 1>{11}), "");
static_assert(meta::equal(factorization_factors<3>(12), meta::array<intmax_t, 3>{2, 2, 3}), "");
static_assert(meta::equal(factorization_factors<1>(13), meta::array<intmax_t, 1>{13}), "");
static_assert(meta::equal(factorization_factors<2>(14), meta::array<intmax_t, 2>{2, 7}), "");
static_assert(meta::equal(factorization_factors<2>(15), meta::array<intmax_t, 2>{3, 5}), "");

//The factorization function computes the prime factors of a given
//number, and returns them as an integer_sequence.
template <intmax_t number, size_t... Index>
constexpr auto factorization_impl(std::integer_sequence<size_t, Index...>)
{
    return std::integer_sequence<intmax_t, factorization_factors<sizeof...(Index)>(number)[Index]...>{};
};
template <intmax_t number>
using factorization = decltype(factorization_impl<number>(std::make_index_sequence<number_of_factors_impl(number)>{}));

//TODO: - Put this into a unit test folder.
//basic tests
static_assert(std::is_same<factorization<1>, std::integer_sequence<intmax_t>>::value, "factorization<1> should be <>.");
static_assert(std::is_same<factorization<2>, std::integer_sequence<intmax_t, 2>>::value, "factorization<2> should be <2>.");
static_assert(std::is_same<factorization<17>, std::integer_sequence<intmax_t, 17>>::value, "factorization<17> should be <17>.");
static_assert(std::is_same<factorization<6>, std::integer_sequence<intmax_t, 2, 3>>::value, "factorization<6> should be <2, 3>.");
static_assert(std::is_same<factorization<4>, std::integer_sequence<intmax_t, 2, 2>>::value, "factorization<4> should be <2, 2>.");
static_assert(std::is_same<factorization<8>, std::integer_sequence<intmax_t, 2, 2, 2>>::value, "factorization<8> should be <2, 2, 2>.");
static_assert(std::is_same<factorization<30>, std::integer_sequence<intmax_t, 2, 3, 5>>::value, "factorization<30> should be <2, 3, 5>.");
#pragma endregion
} // namespace impl
} // namespace benri