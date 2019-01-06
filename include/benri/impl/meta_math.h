#pragma once
#include <benri/impl/array.h>
#include <benri/impl/algorithm.h>
#include <benri/impl/type_traits.h>
#include <ratio>
#include <utility>

namespace benri
{
namespace impl
{
#pragma region ::value helper
//The has_static_constexpr_value function checks if a type has a
//static constexpr ::value attribute using SFINAE.
template <class T>
struct has_static_constexpr_value
{
    template <class U>
    static constexpr auto test(decltype(U::value) *) { return true; }
    template <class U>
    static constexpr auto test(...) { return false; }

    static constexpr auto value = test<T>(nullptr);
};
template <class T>
constexpr bool has_static_constexpr_value_v = has_static_constexpr_value<T>::value;
#pragma endregion
#pragma region ratio helper
//The is_ratio checks if a given type is an integer_sequence.
template <class T>
struct is_ratio : std::false_type
{
};
template <intmax_t num, intmax_t den>
struct is_ratio<std::ratio<num, den>> : std::true_type
{
};
template <class T>
constexpr bool is_ratio_v = is_ratio<T>::value;
#pragma endregion
#pragma region compile time pow
//The power_impl function implements the actual power calculation for
//the power function. It handles two cases: the case of std::ratio as
//the Base type, and a Base with a static constexpr ::value for it.
template <class T, class Base, class Exponent>
constexpr auto power_impl() -> std::enable_if_t<!is_ratio_v<Base>, T>
{
    //handle constants
    static_assert(has_static_constexpr_value_v<Base>, "power takes a value type, a std::ratio or a static constexpr ::value type, and another std::ratios, but Base is neither a std::ratio nor a static constexpr ::value type");
    static_assert(is_ratio_v<Exponent>, "power takes a value type, a std::ratio or a static constexpr ::value type, and another std::ratios, but Exponent is not a std::ratio");
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
constexpr auto power_impl() -> std::enable_if_t<is_ratio_v<Base>, T>
{
    //handle ratios
    static_assert(is_ratio_v<Exponent>, "power takes a value type, a std::ratio or a static constexpr ::value type, and another std::ratios, but Exponent is not a std::ratio");
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
constexpr T power_v = power_impl<T, Base, Exponent>();
#pragma endregion
#pragma region integer_sequence helpers
//The is_integer_sequence checks if a given type is an integer_sequence.
template <class T>
struct is_integer_sequence : std::false_type
{
};
template <class T, T... Ints>
struct is_integer_sequence<std::integer_sequence<T, Ints...>> : std::true_type
{
};
template <class T>
constexpr bool is_integer_sequence_v = is_integer_sequence<T>::value;
//TODO: - Put this into a unit test folder.
//basic tests
static_assert(is_integer_sequence_v<std::integer_sequence<intmax_t, 1, 2>>, "std::integer_sequence<intmax_t, 1, 2> should be a integer_sequence.");
static_assert(is_integer_sequence_v<std::integer_sequence<intmax_t, 1>>, "std::integer_sequence<intmax_t, 1> should be a integer_sequence.");
static_assert(is_integer_sequence_v<std::integer_sequence<intmax_t>>, "std::integer_sequence<intmax_t> should be a integer_sequence.");
static_assert(!is_integer_sequence_v<int>, "int should not be a integer_sequence.");
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
struct is_prime : std::integral_constant<bool, is_prime_impl(Num)>
{
};
template <intmax_t Num>
constexpr bool is_prime_v = is_prime<Num>::value;
//TODO: - Put this into a unit test folder.
//basic tests
static_assert(is_prime_v< 0> == false, "0 is not prime.");
static_assert(is_prime_v< 1> == false, "1 is not prime.");
static_assert(is_prime_v< 2> == true, "2 is prime.");
static_assert(is_prime_v< 3> == true, "3 is prime.");
static_assert(is_prime_v< 4> == false, "4 is not prime.");
static_assert(is_prime_v< 5> == true, "5 is prime.");
static_assert(is_prime_v< 6> == false, "6 is not prime.");
static_assert(is_prime_v< 7> == true, "7 is prime.");
static_assert(is_prime_v< 8> == false, "8 is not prime.");
static_assert(is_prime_v< 9> == false, "9 is not prime.");
static_assert(is_prime_v<10> == false, "10 is not prime.");
static_assert(is_prime_v<11> == true, "11 is prime.");
static_assert(is_prime_v<12> == false, "12 is not prime.");
static_assert(is_prime_v<13> == true, "13 is prime.");
static_assert(is_prime_v<14> == false, "14 is not prime.");
static_assert(is_prime_v<15> == false, "15 is not prime.");
static_assert(is_prime_v<19> == true, "19 is prime.");
static_assert(is_prime_v<100> == false, "100 is not prime.");
static_assert(is_prime_v<293339> == true, "293339 is prime.");
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
struct next_prime : std::integral_constant<intmax_t, next_prime_impl(Num)>
{
};
template <intmax_t Num>
constexpr intmax_t next_prime_v = next_prime<Num>::value;
//TODO: - Put this into a unit test folder.
//basic tests
static_assert(next_prime_v< 0> == 2, "2 is the next prime after 0.");
static_assert(next_prime_v< 1> == 2, "2 is the next prime after 1.");
static_assert(next_prime_v< 2> == 3, "3 is the next prime after 2.");
static_assert(next_prime_v< 3> == 5, "5 is the next prime after 3.");
static_assert(next_prime_v< 4> == 5, "5 is the next prime after 4.");
static_assert(next_prime_v< 5> == 7, "7 is the next prime after 5.");
static_assert(next_prime_v< 6> == 7, "7 is the next prime after 6.");
static_assert(next_prime_v< 7> == 11, "11 is the next prime after 7.");
static_assert(next_prime_v< 8> == 11, "11 is the next prime after 8.");
static_assert(next_prime_v< 9> == 11, "11 is the next prime after 9.");
static_assert(next_prime_v<10> == 11, "11 is the next prime after 10.");
static_assert(next_prime_v<11> == 13, "13 is the next prime after 11.");
static_assert(next_prime_v<12> == 13, "13 is the next prime after 12.");
static_assert(next_prime_v<13> == 17, "17 is the next prime after 13.");
static_assert(next_prime_v<14> == 17, "17 is the next prime after 14.");
static_assert(next_prime_v<15> == 17, "17 is the next prime after 15.");
static_assert(next_prime_v<17> == 19, "19 is the next prime after 17.");
#pragma endregion
#pragma region factorization
constexpr auto number_of_factors_impl(intmax_t number) {
    auto counter = size_t{0};
    for (auto test = intmax_t{2}; number > 1; ) {
        if (number % test == 0) {
            ++counter;
            number /= test;
        } else {
            test = next_prime_impl(test);
        }
    }
    return counter;
}
template <intmax_t Num>
struct number_of_factors : std::integral_constant<size_t, number_of_factors_impl(Num)>
{
};
template <intmax_t Num>
constexpr size_t number_of_factors_v = number_of_factors<Num>::value;
//TODO
static_assert(number_of_factors_v< 0> == 0, "");
static_assert(number_of_factors_v< 1> == 0, "");
static_assert(number_of_factors_v< 2> == 1, "");
static_assert(number_of_factors_v< 3> == 1, "");
static_assert(number_of_factors_v< 4> == 2, "");
static_assert(number_of_factors_v< 5> == 1, "");
static_assert(number_of_factors_v< 6> == 2, "");
static_assert(number_of_factors_v< 7> == 1, "");
static_assert(number_of_factors_v< 8> == 3, "");
static_assert(number_of_factors_v< 9> == 2, "");
static_assert(number_of_factors_v<10> == 2, "");
static_assert(number_of_factors_v<11> == 1, "");
static_assert(number_of_factors_v<12> == 3, "");
static_assert(number_of_factors_v<13> == 1, "");
static_assert(number_of_factors_v<14> == 2, "");
static_assert(number_of_factors_v<15> == 2, "");

template <size_t N>
constexpr auto factorization_factors(intmax_t number) {
    auto factors = impl::array<intmax_t,N>{};
    auto counter = size_t{0};
    for (auto test = intmax_t{2}; number > 1; ) {
        if (number % test == 0) {
            factors[counter] = test;
            ++counter;
            number /= test;
        } else {
            test = next_prime_impl(test);
        }
    }
    return factors;
}
static_assert(impl::equal(factorization_factors<0>( 0), impl::array<intmax_t, 0>{}), "");
static_assert(impl::equal(factorization_factors<0>( 1), impl::array<intmax_t, 0>{}), "");
static_assert(impl::equal(factorization_factors<1>( 2), impl::array<intmax_t, 1>{2}), "");
static_assert(impl::equal(factorization_factors<1>( 3), impl::array<intmax_t, 1>{3}), "");
static_assert(impl::equal(factorization_factors<2>( 4), impl::array<intmax_t, 2>{2, 2}), "");
static_assert(impl::equal(factorization_factors<1>( 5), impl::array<intmax_t, 1>{5}), "");
static_assert(impl::equal(factorization_factors<2>( 6), impl::array<intmax_t, 2>{2,3}), "");
static_assert(impl::equal(factorization_factors<1>( 7), impl::array<intmax_t, 1>{7}), "");
static_assert(impl::equal(factorization_factors<3>( 8), impl::array<intmax_t, 3>{2, 2, 2}), "");
static_assert(impl::equal(factorization_factors<2>( 9), impl::array<intmax_t, 2>{3, 3}), "");
static_assert(impl::equal(factorization_factors<2>(10), impl::array<intmax_t, 2>{2, 5}), "");
static_assert(impl::equal(factorization_factors<1>(11), impl::array<intmax_t, 1>{11}), "");
static_assert(impl::equal(factorization_factors<3>(12), impl::array<intmax_t, 3>{2, 2, 3}), "");
static_assert(impl::equal(factorization_factors<1>(13), impl::array<intmax_t, 1>{13}), "");
static_assert(impl::equal(factorization_factors<2>(14), impl::array<intmax_t, 2>{2, 7}), "");
static_assert(impl::equal(factorization_factors<2>(15), impl::array<intmax_t, 2>{3, 5}), "");


//The factorization function computes the prime factors of a given
//number, and returns them as an integer_sequence.
template <intmax_t number, size_t...Index>
constexpr auto factorization_impl(std::integer_sequence<size_t, Index...>) {
    return std::integer_sequence<intmax_t, factorization_factors<sizeof...(Index)>(number)[Index]...>{};
};
template <intmax_t number>
using factorization = decltype(factorization_impl<number>(std::make_index_sequence<number_of_factors_impl(number)>{}));

//TODO: - Put this into a unit test folder.
//basic tests
static_assert(std::is_same_v<factorization<1>, std::integer_sequence<intmax_t>>, "factorization<1> should be <>.");
static_assert(std::is_same_v<factorization<2>, std::integer_sequence<intmax_t, 2>>, "factorization<2> should be <2>.");
static_assert(std::is_same_v<factorization<17>, std::integer_sequence<intmax_t, 17>>, "factorization<17> should be <17>.");
static_assert(std::is_same_v<factorization<6>, std::integer_sequence<intmax_t, 2, 3>>, "factorization<6> should be <2, 3>.");
static_assert(std::is_same_v<factorization<4>, std::integer_sequence<intmax_t, 2, 2>>, "factorization<4> should be <2, 2>.");
static_assert(std::is_same_v<factorization<8>, std::integer_sequence<intmax_t, 2, 2, 2>>, "factorization<8> should be <2, 2, 2>.");
static_assert(std::is_same_v<factorization<30>, std::integer_sequence<intmax_t, 2, 3, 5>>, "factorization<30> should be <2, 3, 5>.");
#pragma endregion
} // namespace impl
} // namespace benri