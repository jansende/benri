#pragma once

namespace benri
{
namespace impl
{
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
constexpr auto is_integer_sequence_v = is_integer_sequence<T>::value;
//TODO: - Put this into a unit test folder.
auto test_is_integer_sequence()
{
    static_assert(is_integer_sequence_v<std::integer_sequence<intmax_t, 1, 2>>, "std::integer_sequence<intmax_t, 1, 2> should be a integer_sequence.");
    static_assert(is_integer_sequence_v<std::integer_sequence<intmax_t, 1>>, "std::integer_sequence<intmax_t, 1> should be a integer_sequence.");
    static_assert(is_integer_sequence_v<std::integer_sequence<intmax_t>>, "std::integer_sequence<intmax_t> should be a integer_sequence.");
    static_assert(!is_integer_sequence_v<int>, "int should not be a integer_sequence.");
}
//The concat function lets you concatenate two or more integer_sequences.
template <class... Ts>
struct concat
{
    static_assert(all_true_v<is_integer_sequence_v<Ts>...>, "concat only works on std::integer_sequences, but one of your types is not an std::integer_sequence.");
    using type = void;
};
template <class T, T... L, class U, U... R>
struct concat<std::integer_sequence<T, L...>, std::integer_sequence<U, R...>>
{
    static_assert(std::is_same_v<U, T>, "all std::integer_sequences have to have the same value_type.");
    using type = void;
};
template <class T, T... L, T... R>
struct concat<std::integer_sequence<T, L...>, std::integer_sequence<T, R...>>
{
    using type = std::integer_sequence<T, L..., R...>;
};
template <class L, class R, class... Ts>
struct concat<L, R, Ts...>
{
    static_assert(is_integer_sequence_v<L> && is_integer_sequence_v<R> && all_true_v<is_integer_sequence_v<Ts>...>, "concat only works on std::integer_sequences, but one of your types is not an std::integer_sequence.");
    using type = typename concat<typename concat<L, R>::type, Ts...>::type;
};
template <class... Ts>
using concat_t = typename concat<Ts...>::type;
//TODO: - Put this into a unit test folder.
auto test_concat()
{
    static_assert(std::is_same_v<concat_t<std::integer_sequence<intmax_t>, std::integer_sequence<intmax_t, 2>>, std::integer_sequence<intmax_t, 2>>, "std::integer_sequence<intmax_t> and std::integer_sequence<intmax_t, 2> should concat into std::integer_sequence<intmax_t, 2>.");
    static_assert(std::is_same_v<concat_t<std::integer_sequence<intmax_t, 2>, std::integer_sequence<intmax_t>>, std::integer_sequence<intmax_t, 2>>, "std::integer_sequence<intmax_t, 2> and std::integer_sequence<intmax_t> should concat into std::integer_sequence<intmax_t, 2>.");
    static_assert(std::is_same_v<concat_t<std::integer_sequence<intmax_t, 1>, std::integer_sequence<intmax_t, 7>>, std::integer_sequence<intmax_t, 1, 7>>, "std::integer_sequence<intmax_t, 1> and std::integer_sequence<intmax_t, 7> should concat into std::integer_sequence<intmax_t, 1, 7>.");
    static_assert(std::is_same_v<concat_t<std::integer_sequence<intmax_t, 7>, std::integer_sequence<intmax_t, 1>>, std::integer_sequence<intmax_t, 7, 1>>, "std::integer_sequence<intmax_t, 7> and std::integer_sequence<intmax_t, 1> should concat into std::integer_sequence<intmax_t, 7, 1>.");
    static_assert(std::is_same_v<concat_t<std::integer_sequence<intmax_t, 1, 7>, std::integer_sequence<intmax_t, 3, 2, 9>>, std::integer_sequence<intmax_t, 1, 7, 3, 2, 9>>, "std::integer_sequence<intmax_t, 1, 7> and std::integer_sequence<intmax_t, 3, 2, 9> should concat into std::integer_sequence<intmax_t, 1, 7, 3, 2, 9>.");
}
//The drop_numbers function lets you drop all occurences of a number
//from an integer_sequence.
template <class T, T, T...>
struct drop_numbers_impl;
template <class T, T num>
struct drop_numbers_impl<T, num>
{
    using type = std::integer_sequence<T>;
};
template <class T, T num, T val>
struct drop_numbers_impl<T, num, val>
{
    using type = std::integer_sequence<T, val>;
};
template <class T, T num>
struct drop_numbers_impl<T, num, num>
{
    using type = std::integer_sequence<T>;
};
template <class T, T num, T val, T... Rest>
struct drop_numbers_impl<T, num, val, Rest...>
{
    using type = concat_t<typename drop_numbers_impl<T, num, val>::type, typename drop_numbers_impl<T, num, Rest...>::type>;
};
template <class T, class U, U num>
struct drop_numbers
{
    static_assert(is_integer_sequence_v<T>, "drop_numbers takes an std::integer_sequence and a number, but your T is not an std::integer_sequence.");
    using type = void;
};
template <class T, T... nums, class U, U num>
struct drop_numbers<std::integer_sequence<T, nums...>, U, num>
{
    static_assert(std::is_same_v<T, U>, "The value_type of your std::integer_sequence and the number you want to drop has to be the same.");
    using type = void;
};
template <class T, T... nums, T num>
struct drop_numbers<std::integer_sequence<T, nums...>, T, num>
{
    using type = typename drop_numbers_impl<T, num, nums...>::type;
};
template <class T, class U, U num>
using drop_numbers_t = typename drop_numbers<T, U, num>::type;
//The drop_ones function drops all occurences of the number one from
//an integer_sequence.
template <class T>
struct drop_ones
{
    static_assert(is_integer_sequence_v<T>, "drop_ones takes an std::integer_sequencem but your T is not an std::integer_sequence.");
    using type = void;
};
template <class T, T... nums>
struct drop_ones<std::integer_sequence<T, nums...>>
{
    using type = drop_numbers_t<std::integer_sequence<T, nums...>, T, 1>;
};
template <class T>
using drop_ones_t = typename drop_ones<T>::type;
//TODO: - Put this into a unit test folder.
auto test_drop_ones()
{
    static_assert(std::is_same<drop_ones_t<std::integer_sequence<intmax_t>>, std::integer_sequence<intmax_t>>::value, "drop_ones_t<std::integer_sequence<intmax_t>> should be transformed to std::integer_sequence<intmax_t>.");
    static_assert(std::is_same<drop_ones_t<std::integer_sequence<intmax_t, 1>>, std::integer_sequence<intmax_t>>::value, "drop_ones_t<std::integer_sequence<intmax_t, 1>> should be transformed to std::integer_sequence<intmax_t>.");
    static_assert(std::is_same<drop_ones_t<std::integer_sequence<intmax_t, 2>>, std::integer_sequence<intmax_t, 2>>::value, "drop_ones_t<std::integer_sequence<intmax_t, 2>> should be transformed to std::integer_sequence<intmax_t, 2>.");
    static_assert(std::is_same<drop_ones_t<std::integer_sequence<intmax_t, 1, 1, 1>>, std::integer_sequence<intmax_t>>::value, "drop_ones_t<std::integer_sequence<intmax_t, 1, 1, 1>> should be transformed to std::integer_sequence<intmax_t>.");
    static_assert(std::is_same<drop_ones_t<std::integer_sequence<intmax_t, 0, 1, 0, 2>>, std::integer_sequence<intmax_t, 0, 0, 2>>::value, "drop_ones_t<std::integer_sequence<intmax_t, 0, 1, 0, 2>> should be transformed to std::integer_sequence<intmax_t, 0, 0, 2>.");
}
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
constexpr auto is_prime_v = is_prime<Num>::value;
//TODO: - Put this into a unit test folder.
auto test_is_prime()
{
    static_assert(!is_prime_v<100>, "100 is not prime.");
    static_assert(is_prime_v<19>, "19 is prime.");
    static_assert(is_prime_v<5>, "5 is prime.");
    static_assert(is_prime_v<2>, "2 is prime.");
    static_assert(!is_prime_v<1>, "1 is not prime.");
    static_assert(!is_prime_v<9>, "9 is not prime.");
}
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
constexpr auto next_prime_v = next_prime<Num>::value;
//TODO: - Put this into a unit test folder.
auto test_next_prime()
{
    static_assert(next_prime_v<2> == 3, "3 is the next prime after 2.");
    static_assert(next_prime_v<3> == 5, "5 is the next prime after 3.");
    static_assert(next_prime_v<17> == 19, "19 is the next prime after 17.");
    static_assert(next_prime_v<9> == 11, "11 is the next prime after 9.");
}
#pragma endregion
#pragma region factorization
//The factorization function computes the prime factors of a given
//number, and returns them as an integer_sequence.

//Wraps the remainder check to reduce code duplication.
template <template <bool, class T, T...> class Func, class T, T One, T Value, T Prime, T... PrimeFactors>
struct factorization_advance
{
    using type = typename Func<(Value % Prime) == 0, T, One, Value, Prime, PrimeFactors...>::type;
};
//Stop searching for prime factors.
template <template <bool, class T, T...> class Func, class T, T One, T Prime, T... PrimeFactors>
struct factorization_advance<Func, T, One, One, Prime, PrimeFactors...>
{
    using type = std::integer_sequence<T, PrimeFactors...>;
};
template <bool, class T, T, T, T, T...>
struct factorization_check;
//Found that value is not dividable by the current prime.
template <class T, T One, T Value, T Prime, T... PrimeFactors>
struct factorization_check<false, T, One, Value, Prime, PrimeFactors...>
{
    //Try the next prime.
    using type = typename factorization_advance<benri::impl::factorization_check, T, One, Value, next_prime_v<Prime>, PrimeFactors...>::type;
};
//Found that value is dividable by the current prime.
template <class T, T One, T Value, T Prime, T... PrimeFactors>
struct factorization_check<true, T, One, Value, Prime, PrimeFactors...>
{
    //Add the prime to the list of prime factors and try dividing again.
    using type = typename factorization_advance<benri::impl::factorization_check, T, One, Value / Prime, Prime, Prime, PrimeFactors...>::type;
};
template <class T, T Value>
struct factorization
{
    using type = drop_ones_t<typename factorization_advance<factorization_check, T, 1, Value, 2>::type>;
};
template <class T, T Value>
using factorization_t = typename factorization<T, Value>::type;
//TODO: - Put this into a unit test folder.
auto test_factorization()
{
    static_assert(std::is_same_v<factorization_t<int, 1>, std::integer_sequence<int>>, "factorization<1> should be <>.");
    static_assert(std::is_same_v<factorization_t<int, 2>, std::integer_sequence<int, 2>>, "factorization<2> should be <2>.");
    static_assert(std::is_same_v<factorization_t<int, 17>, std::integer_sequence<int, 17>>, "factorization<17> should be <17>.");
    static_assert(std::is_same_v<factorization_t<int, 6>, std::integer_sequence<int, 3, 2>>, "factorization<6> should be <3, 2>.");
    static_assert(std::is_same_v<factorization_t<int, 4>, std::integer_sequence<int, 2, 2>>, "factorization<4> should be <2, 2>.");
    static_assert(std::is_same_v<factorization_t<int, 8>, std::integer_sequence<int, 2, 2, 2>>, "factorization<8> should be <2, 2, 2>.");
    static_assert(std::is_same_v<factorization_t<int, 30>, std::integer_sequence<int, 5, 3, 2>>, "factorization<30> should be <5, 3, 2>.");
}
} // namespace impl
} // namespace benri