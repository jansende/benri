#pragma once
#include <benri/impl/atom.h>
#include <benri/impl/type_traits.h>
#include <benri/impl/meta_math.h>

namespace benri
{
namespace impl
{
#pragma region list type
//The list type saves arbitrary numbers of atoms, and handles mathematical
//functions on them.
template <class... Ts>
struct list
{
    static_assert(all_true_v<is_atom_v<Ts>...>, "list only takes atoms as types.");
};
template <class T>
struct is_list : std::false_type
{
};
template <class... Ts>
struct is_list<list<Ts...>> : std::true_type
{
};
template <class T>
constexpr auto is_list_v = is_list<T>::value;
#pragma endregion
#pragma region list functions
#pragma region concat
//The concat_lists function lets you concatenate two or more lists.
template <class... Ts>
struct concat_lists
{
    static_assert(all_true_v<is_list_v<Ts>...>, "concat_lists only works on lists, but one of your types is not a list.");
    using type = void;
};
template <class... L, class... R>
struct concat_lists<list<L...>, list<R...>>
{
    using type = list<L..., R...>;
};
template <class L, class R, class... Ts>
struct concat_lists<L, R, Ts...>
{
    static_assert(is_list_v<L> && is_list_v<R> && all_true_v<is_list_v<Ts>...>, "concat_lists only works on lists, but one of your types is not a list.");
    using type = typename concat_lists<typename concat_lists<L, R>::type, Ts...>::type;
};
template <class... Ts>
using concat_lists_t = typename concat_lists<Ts...>::type;
//TODO: - Put this into a unit test folder.
auto test_concat_lists()
{
    static_assert(std::is_same_v<concat_lists_t<list<atom<int>>, list<>>, list<atom<int>>>, "");
    static_assert(std::is_same_v<concat_lists_t<list<atom<int>>, list<>, list<>>, list<atom<int>>>, "");
    static_assert(std::is_same_v<concat_lists_t<list<atom<int>>, list<atom<int>>, list<>>, list<atom<int>, atom<int>>>, "");
    static_assert(std::is_same_v<concat_lists_t<list<atom<bool>>, list<atom<int>>, list<>>, list<atom<bool>, atom<int>>>, "");

    static_assert(std::is_same_v<concat_lists_t<list<atom<int>, atom<float>, atom<bool>>, list<atom<int>, atom<float>>>, list<atom<int>, atom<float>, atom<bool>, atom<int>, atom<float>>>, "");
}
#pragma endregion
#pragma region equivalence
//The drop_first_match removes the first appearance of the atom T
//in a list. If the T is not in the list, nothing is changed.
template <class List, class T>
struct drop_first_match
{
    static_assert(is_list_v<List>, "drop_first_match takes a list and an atom, but your List type is not a list.");
    static_assert(is_atom_v<T>, "drop_first_match takes a list and an atom, but your T is not an atom.");
    using type = void;
};
template <class T>
struct drop_first_match<list<>, T>
{
    using type = list<>;
};
template <class T, class... Rest>
struct drop_first_match<list<T, Rest...>, T>
{
    using type = list<Rest...>;
};
template <class T, class First, class... Rest>
struct drop_first_match<list<First, Rest...>, T>
{
    static_assert(is_atom_v<T>, "drop_first_match takes a list and an atom, but your T is not an atom.");
    using type = concat_lists_t<list<First>, typename drop_first_match<list<Rest...>, T>::type>;
};
template <class List, class T>
using drop_first_match_t = typename drop_first_match<List, T>::type;
//TODO: - Put this into a unit test folder.
auto test_drop_first_match()
{
    static_assert(std::is_same_v<drop_first_match_t<list<>, atom<int>>, list<>>, "");
    static_assert(std::is_same_v<drop_first_match_t<list<atom<bool>>, atom<int>>, list<atom<bool>>>, "");
    static_assert(std::is_same_v<drop_first_match_t<list<atom<bool>, atom<int>, atom<float>, atom<int>>, atom<int>>, list<atom<bool>, atom<float>, atom<int>>>, "");
}
//The is_equivalent_list function checks if two lists are
//equivalent. Two lists are equivalent when they contain
//the same atoms, no more, no less, with an arbitrary ordering.
template <class L, class R>
struct is_equivalent_list_impl
{
    static_assert(is_list_v<L> && is_list_v<L>, "is_equivalent takes two lists, but either L or R is not a list.");
    static constexpr auto value = false;
};
template <>
struct is_equivalent_list_impl<list<>, list<>>
{
    static constexpr auto value = true;
};
template <class T, class... R>
struct is_equivalent_list_impl<list<T>, list<R...>>
{
    static constexpr auto value = std::is_same_v<drop_first_match_t<list<R...>, T>, list<>> && (sizeof...(R) == 1);
};
template <class T, class... L, class... R>
struct is_equivalent_list_impl<list<T, L...>, list<R...>>
{
    static constexpr auto value = is_equivalent_list_impl<list<L...>, drop_first_match_t<list<R...>, T>>::value && (sizeof...(L) + 1 == sizeof...(R));
};
template <class L, class R>
struct is_equivalent_list : std::integral_constant<bool, is_equivalent_list_impl<L, R>::value>
{
};
template <class L, class R>
constexpr auto is_equivalent_list_v = is_equivalent_list<L, R>::value;
//TODO: - Put this into a unit test folder.
auto test_equivalent()
{
    static_assert(is_equivalent_list_v<list<atom<int, std::ratio<2>>>, list<atom<int, std::ratio<2>>>>, "");
    static_assert(!is_equivalent_list_v<list<atom<int, std::ratio<3>>>, list<atom<int, std::ratio<2>>>>, "");
    static_assert(!is_equivalent_list_v<list<atom<int, std::ratio<-2>>>, list<atom<int, std::ratio<2>>>>, "");
    static_assert(is_equivalent_list_v<list<>, list<>>, "");
    static_assert(is_equivalent_list_v<list<atom<int>>, list<atom<int>>>, "");
    static_assert(is_equivalent_list_v<list<atom<float>>, list<atom<float>>>, "");
    static_assert(!is_equivalent_list_v<list<atom<int>>, list<atom<float>>>, "");
    static_assert(!is_equivalent_list_v<list<atom<float>>, list<atom<int>>>, "");
    static_assert(!is_equivalent_list_v<list<atom<int>, atom<int>>, list<atom<int>>>, "");
    static_assert(!is_equivalent_list_v<list<atom<int>>, list<atom<int>, atom<int>>>, "");
    static_assert(is_equivalent_list_v<list<atom<int>, atom<float>>, list<atom<float>, atom<int>>>, "");
    static_assert(is_equivalent_list_v<list<atom<int>, atom<float>>, list<atom<int>, atom<float>>>, "");
    static_assert(is_equivalent_list_v<list<atom<bool>, atom<int>, atom<float>>, list<atom<int>, atom<float>, atom<bool>>>, "");
    static_assert(!is_equivalent_list_v<list<atom<bool>, atom<int>, atom<float>, atom<float>>, list<atom<int>, atom<float>, atom<bool>>>, "");
    static_assert(!is_equivalent_list_v<list<atom<bool>, atom<int>, atom<float>, atom<float>>, list<atom<int>, atom<float>, atom<int>, atom<bool>>>, "");
}
#pragma endregion
#pragma region multiplication
//The drop_zero_atoms function removes all atoms with a power of zero.
template <class T>
struct drop_zero_atoms
{
    static_assert(is_list_v<T>, "drop_zero_atoms takes a list, but your given type is not a list.");
    using type = void;
};
template <>
struct drop_zero_atoms<list<>>
{
    using type = list<>;
};
template <template <class, class> class Atom, class T, class... Rest>
struct drop_zero_atoms<list<Atom<T, std::ratio<0>>, Rest...>>
{
    using type = typename drop_zero_atoms<list<Rest...>>::type;
};
template <class First, class... Rest>
struct drop_zero_atoms<list<First, Rest...>>
{
    using type = concat_lists_t<list<First>, typename drop_zero_atoms<list<Rest...>>::type>;
};
template <class T>
using drop_zero_atoms_t = typename drop_zero_atoms<T>::type;
//TODO: - Put this into a unit test folder.
auto test_drop_zero_atoms()
{
    static_assert(std::is_same_v<drop_zero_atoms_t<list<>>, list<>>, "");
    static_assert(std::is_same_v<drop_zero_atoms_t<list<atom<int>>>, list<atom<int>>>, "");
    static_assert(std::is_same_v<drop_zero_atoms_t<list<atom<int, std::ratio<0>>>>, list<>>, "");
    static_assert(std::is_same_v<drop_zero_atoms_t<list<atom<int, std::ratio<2>>>>, list<atom<int, std::ratio<2>>>>, "");
}
//The add_to_first_atom function searches the first matching
//atom in a list, and updating it. If it does not exist, the
//entry is added to the end of the list.
template <class L, class R>
struct add_to_first_atom
{
    static_assert(is_list_v<L>, "add_to_first_atom takes a list and an atom, but your L is not a list.");
    static_assert(is_atom_v<R>, "add_to_first_atom takes a list and an atom, but your R is not an atom.");
    using type = void;
};
template <class R>
struct add_to_first_atom<list<>, R>
{
    static_assert(is_atom_v<R>, "add_to_first_atom takes a list and an atom, but your R is not an atom.");
    using type = list<R>;
};
template <template <class, class> class LAtom, template <class, class> class RAtom, class T, class LPower, class RPower, class... Rest>
struct add_to_first_atom<list<LAtom<T, LPower>, Rest...>, RAtom<T, RPower>>
{
    static_assert(is_atom_v<RAtom<T, RPower>>, "add_to_first_atom takes a list and an atom, but your R is not an atom.");
    using type = list<LAtom<T, std::ratio_add<LPower, RPower>>, Rest...>;
};
template <class First, class... Rest, template <class, class> class Atom, class T, class Power>
struct add_to_first_atom<list<First, Rest...>, Atom<T, Power>>
{
    static_assert(is_atom_v<Atom<T, Power>>, "add_to_first_atom takes a list and an atom, but your R is not an atom.");
    using type = concat_lists_t<list<First>, typename add_to_first_atom<list<Rest...>, Atom<T, Power>>::type>;
};
template <class L, class R>
using add_to_first_atom_t = typename add_to_first_atom<L, R>::type;
//TODO: - Put this into a unit test folder.
auto test_add_to_first_atom()
{
    static_assert(std::is_same_v<add_to_first_atom_t<list<>, atom<int>>, list<atom<int>>>, "");
    static_assert(std::is_same_v<add_to_first_atom_t<list<atom<bool>>, atom<int>>, list<atom<bool>, atom<int>>>, "");
    static_assert(std::is_same_v<add_to_first_atom_t<list<atom<int>>, atom<int>>, list<atom<int, std::ratio<2>>>>, "");
    static_assert(std::is_same_v<add_to_first_atom_t<list<atom<int>, atom<bool>>, atom<int>>, list<atom<int, std::ratio<2>>, atom<bool>>>, "");
    static_assert(std::is_same_v<add_to_first_atom_t<list<atom<bool>, atom<int>>, atom<int>>, list<atom<bool>, atom<int, std::ratio<2>>>>, "");
}
//The multiply_lists function combines the atoms in two lists,
//by adding the power of atoms with the same type.
template <class L, class R>
struct multiply_lists_impl
{
    static_assert(is_list_v<L> && is_list_v<R>, "multiply_lists takes two lists, but one of your arguments is not a list.");
    using type = void;
};
template <class L>
struct multiply_lists_impl<L, list<>>
{
    static_assert(is_list_v<L>, "multiply_lists takes two lists, but one of your arguments is not a list.");
    using type = L;
};
template <class L, class R>
struct multiply_lists_impl<L, list<R>>
{
    static_assert(is_list_v<L>, "multiply_lists takes two lists, but one of your arguments is not a list.");
    using type = add_to_first_atom_t<L, R>;
};
template <class L, class T, class... R>
struct multiply_lists_impl<L, list<T, R...>>
{
    static_assert(is_list_v<L>, "multiply_lists takes two lists, but one of your arguments is not a list.");
    using type = typename multiply_lists_impl<add_to_first_atom_t<L, T>, list<R...>>::type;
};
template <class L, class R>
struct multiply_lists
{
    static_assert(is_list_v<L> && is_list_v<R>, "multiply_lists takes two lists, but one of your arguments is not a list.");
    using type = drop_zero_atoms_t<typename multiply_lists_impl<L, R>::type>;
};
template <class L, class R>
using multiply_lists_t = typename multiply_lists<L, R>::type;
//TODO: - Put this into a unit test folder.
auto test_multiply_lists()
{
    static_assert(std::is_same_v<multiply_lists_t<list<>, list<atom<int>>>, list<atom<int>>>, "");
    static_assert(std::is_same_v<multiply_lists_t<list<atom<int>>, list<>>, list<atom<int>>>, "");
    static_assert(std::is_same_v<multiply_lists_t<list<atom<int>>, list<atom<bool>>>, list<atom<int>, atom<bool>>>, "");
    static_assert(std::is_same_v<multiply_lists_t<list<atom<int>>, list<atom<int>>>, list<atom<int, std::ratio<2>>>>, "");
    static_assert(std::is_same_v<multiply_lists_t<list<atom<int>>, list<atom<int, std::ratio<-1>>>>, list<>>, "");
    static_assert(std::is_same_v<multiply_lists_t<list<atom<int>>, list<atom<int>, atom<bool>>>, list<atom<int, std::ratio<2>>, atom<bool>>>, "");
    static_assert(std::is_same_v<multiply_lists_t<list<atom<int>>, list<atom<bool>, atom<int>>>, list<atom<int, std::ratio<2>>, atom<bool>>>, "");
    static_assert(std::is_same_v<multiply_lists_t<list<atom<int>, atom<bool>>, list<atom<int>>>, list<atom<int, std::ratio<2>>, atom<bool>>>, "");
}
//The subtract_from_first_atom function searches the first match-
//ing atom in a list, and updating it. If it does not exist, the
//entry is added to the end of the list.
template <class L, class R>
struct subtract_from_first_atom
{
    static_assert(is_list_v<L>, "subtract_from_first_atom takes a list and an atom, but your L is not a list.");
    static_assert(is_atom_v<R>, "subtract_from_first_atom takes a list and an atom, but your R is not an atom.");
    using type = void;
};
template <template <class, class> class Atom, class R, class Power>
struct subtract_from_first_atom<list<>, Atom<R, Power>>
{
    static_assert(is_atom_v<Atom<R, Power>>, "subtract_from_first_atom takes a list and an atom, but your R is not an atom.");
    using type = list<atom<R, std::ratio_subtract<std::ratio<0>, Power>>>;
};
template <template <class, class> class LAtom, template <class, class> class RAtom, class T, class LPower, class RPower, class... Rest>
struct subtract_from_first_atom<list<LAtom<T, LPower>, Rest...>, RAtom<T, RPower>>
{
    static_assert(is_atom_v<RAtom<T, RPower>>, "subtract_from_first_atom takes a list and an atom, but your R is not an atom.");
    using type = list<LAtom<T, std::ratio_subtract<LPower, RPower>>, Rest...>;
};
template <class First, class... Rest, template <class, class> class Atom, class T, class Power>
struct subtract_from_first_atom<list<First, Rest...>, Atom<T, Power>>
{
    static_assert(is_atom_v<Atom<T, Power>>, "subtract_from_first_atom takes a list and an atom, but your R is not an atom.");
    using type = concat_lists_t<list<First>, typename subtract_from_first_atom<list<Rest...>, Atom<T, Power>>::type>;
};
template <class L, class R>
using subtract_from_first_atom_t = typename subtract_from_first_atom<L, R>::type;
//TODO: - Put this into a unit test folder.
auto test_subtract_from_first_atom()
{
    static_assert(std::is_same_v<subtract_from_first_atom_t<list<>, atom<int>>, list<atom<int, std::ratio<-1>>>>, "");
    static_assert(std::is_same_v<subtract_from_first_atom_t<list<atom<bool>>, atom<int>>, list<atom<bool>, atom<int, std::ratio<-1>>>>, "");
    static_assert(std::is_same_v<subtract_from_first_atom_t<list<atom<int>>, atom<int>>, list<atom<int, std::ratio<0>>>>, "");
    static_assert(std::is_same_v<subtract_from_first_atom_t<list<atom<int>, atom<bool>>, atom<int>>, list<atom<int, std::ratio<0>>, atom<bool>>>, "");
    static_assert(std::is_same_v<subtract_from_first_atom_t<list<atom<bool>, atom<int>>, atom<int>>, list<atom<bool>, atom<int, std::ratio<0>>>>, "");
}
//The divide_lists function combines the atoms in two lists,
//by subtracting the power of atoms with the same type of the
//left list from the right.
template <class L, class R>
struct divide_lists_impl
{
    static_assert(is_list_v<L> && is_list_v<R>, "divide_lists takes two lists, but one of your arguments is not a list.");
    using type = void;
};
template <class L>
struct divide_lists_impl<L, list<>>
{
    static_assert(is_list_v<L>, "divide_lists takes two lists, but one of your arguments is not a list.");
    using type = L;
};
template <class L, class R>
struct divide_lists_impl<L, list<R>>
{
    static_assert(is_list_v<L>, "divide_lists takes two lists, but one of your arguments is not a list.");
    using type = subtract_from_first_atom_t<L, R>;
};
template <class L, class T, class... R>
struct divide_lists_impl<L, list<T, R...>>
{
    static_assert(is_list_v<L>, "divide_lists takes two lists, but one of your arguments is not a list.");
    using type = typename divide_lists_impl<subtract_from_first_atom_t<L, T>, list<R...>>::type;
};
template <class L, class R>
struct divide_lists
{
    static_assert(is_list_v<L> && is_list_v<R>, "divide_lists takes two lists, but one of your arguments is not a list.");
    using type = drop_zero_atoms_t<typename divide_lists_impl<L, R>::type>;
};
template <class L, class R>
using divide_lists_t = typename divide_lists<L, R>::type;
//TODO: - Put this into a unit test folder.
auto test_divide_lists()
{
    static_assert(std::is_same_v<divide_lists_t<list<>, list<atom<int>>>, list<atom<int, std::ratio<-1>>>>, "");
    static_assert(std::is_same_v<divide_lists_t<list<atom<int>>, list<>>, list<atom<int>>>, "");
    static_assert(std::is_same_v<divide_lists_t<list<atom<int>>, list<atom<bool>>>, list<atom<int>, atom<bool, std::ratio<-1>>>>, "");
    static_assert(std::is_same_v<divide_lists_t<list<atom<int>>, list<atom<int>>>, list<>>, "");
    static_assert(std::is_same_v<divide_lists_t<list<atom<int>>, list<atom<int>, atom<bool>>>, list<atom<bool, std::ratio<-1>>>>, "");
    static_assert(std::is_same_v<divide_lists_t<list<atom<int>>, list<atom<bool>, atom<int>>>, list<atom<bool, std::ratio<-1>>>>, "");
    static_assert(std::is_same_v<divide_lists_t<list<atom<int>, atom<bool>>, list<atom<int>>>, list<atom<bool>>>, "");
}
#pragma endregion
#pragma region power
//The pow_list function adds a given power to every atom in a
//list.
template <class L, class R>
struct pow_list
{
    static_assert(is_list_v<L>, "divide_lists takes a list and a std::ratio, but your L is not a list.");
    static_assert(is_ratio_v<R>, "divide_lists takes a list and a std::ratio, but your R is not a std::ratio.");
    using type = void;
};
template <class R>
struct pow_list<list<>, R>
{
    static_assert(is_ratio_v<R>, "divide_lists takes a list and a std::ratio, but your R is not a std::ratio.");
    using type = list<>;
};
template <template <class, class> class Atom, class T, class Power, class... Rest, class R>
struct pow_list<list<Atom<T, Power>, Rest...>, R>
{
    static_assert(is_ratio_v<R>, "divide_lists takes a list and a std::ratio, but your R is not a std::ratio.");
    using type = concat_lists_t<list<Atom<T, std::ratio_multiply<Power, R>>>, typename pow_list<list<Rest...>, Power>::type>;
};
template <class L, class R>
using pow_list_t = typename pow_list<L, R>::type;
#pragma endregion
#pragma endregion
#pragma region list generators
//The make_list function generates a list from an integer_sequence.
template <class T>
struct make_list
{
    static_assert(is_integer_sequence_v<T>, "make_list takes an std::integer_sequence, but you given type is not a integer_sequence.");
    using type = void;
};
template <class T, T... Values>
struct make_list<std::integer_sequence<T, Values...>>
{
    using type = list<atom<std::ratio<Values>>...>;
};
template <class T>
using make_list_t = typename make_list<T>::type;
//The make_factorial_list function generates a list by
//factorizing a given number.
template <intmax_t Value>
struct make_factorial_list
{
    using type = multiply_lists_t<list<>, make_list_t<factorization_t<intmax_t, Value>>>;
};
template <intmax_t Value>
using make_factorial_list_t = typename make_factorial_list<Value>::type;
//The make_fraction_list function generates a list by
//factorizing a given numerator and denominater.
template <intmax_t num, intmax_t den = 1>
struct make_fraction_list
{
    using type = divide_lists_t<make_factorial_list_t<num>, make_factorial_list_t<den>>;
};
template <intmax_t num, intmax_t den = 1>
using make_fraction_list_t = typename make_fraction_list<num, den>::type;
//TODO: - Put this into a unit test folder.
auto test_make_list()
{
    static_assert(std::is_same_v<make_list_t<factorization_t<int, 9>>, list<atom<std::ratio<3>>, atom<std::ratio<3>>>>, "");
    static_assert(std::is_same_v<multiply_lists_t<list<>, make_list_t<factorization_t<int, 9>>>, list<atom<std::ratio<3>, std::ratio<2>>>>, "");
    static_assert(std::is_same_v<make_factorial_list_t<8>, list<atom<std::ratio<2>, std::ratio<3>>>>, "");
    static_assert(std::is_same_v<make_fraction_list_t<1, 8>, list<atom<std::ratio<2>, std::ratio<-3>>>>, "");
    static_assert(std::is_same_v<make_fraction_list_t<4, 8>, list<atom<std::ratio<2>, std::ratio<-1>>>>, "");
    static_assert(std::is_same_v<make_fraction_list_t<5, 3>, list<atom<std::ratio<5>>, atom<std::ratio<3>, std::ratio<-1>>>>, "");
}
#pragma endregion
} // namespace impl
//Pull the list type and its generators into the benri namespace,
//because we need it for constructing units.
using impl::list;
using impl::make_fraction_list_t;
} // namespace benri