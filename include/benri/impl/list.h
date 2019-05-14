#pragma once
#include <benri/impl/algorithm.h>
#include <benri/impl/array.h>
#include <benri/impl/atom.h>
#include <benri/impl/meta_math.h>
#include <benri/impl/sorting.h>
#include <benri/impl/type_traits.h>
#include <cmath>

namespace benri
{
namespace impl
{
#pragma region list type
//The list type saves arbitrary numbers of atoms, and handles mathematical
//functions on them.
template <class... Elements>
struct list
{
    static_assert(all_true_v<is_atom_v<Elements>...>, "all elements of a list need to be atoms.");
};
template <class>
struct is_list : std::false_type
{
};
template <class... Elements>
struct is_list<list<Elements...>> : std::true_type
{
};
template <class List>
constexpr bool is_list_v = is_list<List>::value;
#pragma endregion
#pragma region list functions
#pragma region concat
//The concat function lets you concatenate two or more lists.
template <class... lhsElements, class... rhsElements>
constexpr auto concat_impl(list<lhsElements...>, list<rhsElements...>) {
    return list<lhsElements..., rhsElements...>{};
}
template <class lhs, class rhs>
using concat = decltype(concat_impl(lhs{}, rhs{}));
//TODO: - Put this into a unit test folder.
//basic tests
static_assert(std::is_same<concat<list<atom<int>>, list<>>, list<atom<int>>>::value, "");
static_assert(std::is_same<concat<list<atom<int>, atom<float>, atom<bool>>, list<atom<int>, atom<float>>>, list<atom<int>, atom<float>, atom<bool>, atom<int>, atom<float>>>::value, "");
#pragma endregion
#pragma region multiplication
//The add_to_first_atom function searches the first matching
//atom in a list, and updating it. If it does not exist, the
//entry is added to the end of the list.
template <class List, class Atom>
struct add_to_first_atom_impl
{
    static_assert(is_list_v<List>, "the lhs of add_to_first_atom needs to be a list.");
    static_assert(is_atom_v<Atom>, "the rhs of add_to_first_atom needs to be an atom.");
    using type = void;
};
template <class Atom>
struct add_to_first_atom_impl<list<>, Atom>
{
    static_assert(is_atom_v<Atom>, "the rhs of add_to_first_atom needs to be an atom.");
    using type = list<Atom>;
};
template <template <class, class> class lhsAtom, template <class, class> class rhsAtom, class T, class lhsPower, class rhsPower, class... RestElements>
struct add_to_first_atom_impl<list<lhsAtom<T, lhsPower>, RestElements...>, rhsAtom<T, rhsPower>>
{
    static_assert(is_atom_v<rhsAtom<T, rhsPower>>, "the rhs of add_to_first_atom needs to be an atom.");
    using type = std::conditional_t<
    std::is_same<std::ratio_add<lhsPower, rhsPower>, std::ratio<0>>::value, 
    list<RestElements...>,
     list<lhsAtom<T, std::ratio_add<lhsPower, rhsPower>>, RestElements...>
     >;
};
template <class FirstElement, class... RestElements, template <class, class> class Atom, class T, class Power>
struct add_to_first_atom_impl<list<FirstElement, RestElements...>, Atom<T, Power>>
{
    static_assert(is_atom_v<Atom<T, Power>>, "the rhs of add_to_first_atom needs to be an atom.");
    using type = concat<list<FirstElement>, typename add_to_first_atom_impl<list<RestElements...>, Atom<T, Power>>::type>;
};
template <class List, class Atom>
using add_to_first_atom = typename add_to_first_atom_impl<List, Atom>::type;
//TODO: - Put this into a unit test folder.
//basic tests
static_assert(std::is_same<add_to_first_atom<list<>, atom<int>>, list<atom<int>>>::value, "");
static_assert(std::is_same<add_to_first_atom<list<atom<bool>>, atom<int>>, list<atom<bool>, atom<int>>>::value, "");
static_assert(std::is_same<add_to_first_atom<list<atom<int>>, atom<int>>, list<atom<int, std::ratio<2>>>>::value, "");
static_assert(std::is_same<add_to_first_atom<list<atom<int>, atom<bool>>, atom<int>>, list<atom<int, std::ratio<2>>, atom<bool>>>::value, "");
static_assert(std::is_same<add_to_first_atom<list<atom<bool>, atom<int>>, atom<int>>, list<atom<bool>, atom<int, std::ratio<2>>>>::value, "");
//The multiply_lists function combines the atoms in two lists,
//by adding the power of atoms with the same type.
template <class...Lists>
struct multiply_lists_impl
{
    static_assert(all_true_v<is_list_v<Lists>...>, "all arguments of multiply_lists need to be lists.");
    using type = void;
};
template <class lhsList>
struct multiply_lists_impl<lhsList, list<>>
{
    static_assert(is_list_v<lhsList>, "all arguments of multiply_lists need to be lists.");
    using type = lhsList;
};
template <class lhsList, class rhsElement>
struct multiply_lists_impl<lhsList, list<rhsElement>>
{
    static_assert(is_list_v<lhsList>, "all arguments of multiply_lists need to be lists.");
    using type = add_to_first_atom<lhsList, rhsElement>;
};
template <class lhsList, class rhsFirstElement, class... rhsRestElements>
struct multiply_lists_impl<lhsList, list<rhsFirstElement, rhsRestElements...>>
{
    static_assert(is_list_v<lhsList>, "all arguments of multiply_lists need to be lists.");
    using type = typename multiply_lists_impl<add_to_first_atom<lhsList, rhsFirstElement>, list<rhsRestElements...>>::type;
};
template <class lhsList, class rhsList, class... RestLists>
struct multiply_lists_impl<lhsList, rhsList, RestLists...>
{
    static_assert(is_list_v<lhsList> && is_list_v<rhsList> && all_true_v<is_list_v<RestLists>...>, "all arguments of multiply_lists need to be lists.");
    using type = typename multiply_lists_impl<typename multiply_lists_impl<lhsList, rhsList>::type, RestLists...>::type;
};
template <class...Lists>
using multiply_lists = sort_list<typename multiply_lists_impl<Lists...>::type>;
//TODO: - Put this into a unit test folder.
//basic tests
static_assert(std::is_same<multiply_lists<list<>, list<atom<int>>>, list<atom<int>>>::value, "");
static_assert(std::is_same<multiply_lists<list<atom<int>>, list<>>, list<atom<int>>>::value, "");
static_assert(std::is_same<multiply_lists<list<atom<int>>, list<atom<bool>>>, list<atom<bool>, atom<int>>>::value, "");
static_assert(std::is_same<multiply_lists<list<atom<int>>, list<atom<int>>>, list<atom<int, std::ratio<2>>>>::value, "");
static_assert(std::is_same<multiply_lists<list<atom<int>>, list<atom<int, std::ratio<-1>>>>, list<>>::value, "");
static_assert(std::is_same<multiply_lists<list<atom<int>>, list<atom<int>, atom<bool>>>, list<atom<bool>, atom<int, std::ratio<2>>>>::value, "");
static_assert(std::is_same<multiply_lists<list<atom<int>>, list<atom<bool>, atom<int>>>, list<atom<bool>, atom<int, std::ratio<2>>>>::value, "");
static_assert(std::is_same<multiply_lists<list<atom<int>, atom<bool>>, list<atom<int>>>, list<atom<bool>, atom<int, std::ratio<2>>>>::value, "");
#pragma endregion
#pragma region power
//The pow_list function adds a given power to every atom in a
//list.
template <class T, class Power, intmax_t num, intmax_t den>
constexpr auto pow_atom_impl(atom<T, Power>, std::ratio<num, den>) {
    return atom<T, std::ratio_multiply<Power, std::ratio<num, den>>>{};
}
template <class Atom, class Power>
using pow_atom = decltype(pow_atom_impl(Atom{}, Power{}));

template <class...Elements, intmax_t num, intmax_t den>
constexpr auto pow_list_func(list<Elements...>, std::ratio<num, den>) {
    return list<pow_atom<Elements, std::ratio<num, den>>...>{};
}
template <class List, class Power>
struct pow_list_impl {
    using type = decltype(pow_list_func(List{}, Power{}));
};
template <class List>
struct pow_list_impl<List, std::ratio<0>> {
    using type = list<>;
};
template <class List, class Power>
using pow_list = typename pow_list_impl<List, Power>::type;
//TODO: - Put this into a unit test folder.
//basic tests
static_assert(std::is_same<pow_list<list<>, std::ratio<2>>, list<>>::value, "");
static_assert(std::is_same<pow_list<list<>, std::ratio<-2>>, list<>>::value, "");
static_assert(std::is_same<pow_list<list<>, std::ratio<1, 3>>, list<>>::value, "");
static_assert(std::is_same<pow_list<list<>, std::ratio<-1, 3>>, list<>>::value, "");
static_assert(std::is_same<pow_list<list<atom<std::ratio<5>>>, std::ratio<1>>, list<atom<std::ratio<5>>>>::value, "");
static_assert(std::is_same<pow_list<list<atom<std::ratio<5>>>, std::ratio<2>>, list<atom<std::ratio<5>, std::ratio<2>>>>::value, "");
static_assert(std::is_same<pow_list<list<atom<std::ratio<5>>>, std::ratio<-2>>, list<atom<std::ratio<5>, std::ratio<-2>>>>::value, "");
static_assert(std::is_same<pow_list<list<atom<std::ratio<5>>>, std::ratio<1, 3>>, list<atom<std::ratio<5>, std::ratio<1, 3>>>>::value, "");
static_assert(std::is_same<pow_list<list<atom<std::ratio<5>>>, std::ratio<-1, 3>>, list<atom<std::ratio<5>, std::ratio<-1, 3>>>>::value, "");
static_assert(std::is_same<pow_list<list<atom<std::ratio<3>>, atom<std::ratio<5>>>, std::ratio<1>>, list<atom<std::ratio<3>>, atom<std::ratio<5>>>>::value, "");
static_assert(std::is_same<pow_list<list<atom<std::ratio<3>>, atom<std::ratio<5>>>, std::ratio<2>>, list<atom<std::ratio<3>, std::ratio<2>>, atom<std::ratio<5>, std::ratio<2>>>>::value, "");
static_assert(std::is_same<pow_list<list<atom<std::ratio<3>>, atom<std::ratio<5>>>, std::ratio<-2>>, list<atom<std::ratio<3>, std::ratio<-2>>, atom<std::ratio<5>, std::ratio<-2>>>>::value, "");
static_assert(std::is_same<pow_list<list<atom<std::ratio<3>>, atom<std::ratio<5>>>, std::ratio<1, 3>>, list<atom<std::ratio<3>, std::ratio<1, 3>>, atom<std::ratio<5>, std::ratio<1, 3>>>>::value, "");
static_assert(std::is_same<pow_list<list<atom<std::ratio<3>>, atom<std::ratio<5>>>, std::ratio<-1, 3>>, list<atom<std::ratio<3>, std::ratio<-1, 3>>, atom<std::ratio<5>, std::ratio<-1, 3>>>>::value, "");
#pragma endregion
#pragma region division
//The divide_lists function combines the atoms in two lists,
//by multiplying the left side with the inverse of the right
//side.
template <class lhsList, class rhsList>
using divide_lists = multiply_lists<lhsList, pow_list<rhsList, std::ratio<-1>>>;
//TODO: - Put this into a unit test folder.
//basic tests
static_assert(std::is_same<divide_lists<list<>, list<atom<int>>>, list<atom<int, std::ratio<-1>>>>::value, "");
static_assert(std::is_same<divide_lists<list<atom<int>>, list<>>, list<atom<int>>>::value, "");
static_assert(std::is_same<divide_lists<list<atom<int>>, list<atom<bool>>>, list<atom<bool, std::ratio<-1>>, atom<int>>>::value, "");
static_assert(std::is_same<divide_lists<list<atom<int>>, list<atom<int>>>, list<>>::value, "");
static_assert(std::is_same<divide_lists<list<atom<int>>, list<atom<int>, atom<bool>>>, list<atom<bool, std::ratio<-1>>>>::value, "");
static_assert(std::is_same<divide_lists<list<atom<int>>, list<atom<bool>, atom<int>>>, list<atom<bool, std::ratio<-1>>>>::value, "");
static_assert(std::is_same<divide_lists<list<atom<int>, atom<bool>>, list<atom<int>>>, list<atom<bool>>>::value, "");
static_assert(std::is_same<divide_lists<list<>, list<atom<std::ratio<3>>>>, list<atom<std::ratio<3>, std::ratio<-1>>>>::value, "");
static_assert(std::is_same<divide_lists<list<atom<std::ratio<3>>>, list<>>, list<atom<std::ratio<3>>>>::value, "");
static_assert(std::is_same<divide_lists<list<atom<std::ratio<3>>>, list<atom<std::ratio<7>>>>, list<atom<std::ratio<3>>, atom<std::ratio<7>, std::ratio<-1>>>>::value, "");
static_assert(std::is_same<divide_lists<list<atom<std::ratio<3>>>, list<atom<std::ratio<3>>>>, list<>>::value, "");
static_assert(std::is_same<divide_lists<list<atom<std::ratio<3>>>, list<atom<std::ratio<3>>, atom<std::ratio<7>>>>, list<atom<std::ratio<7>, std::ratio<-1>>>>::value, "");
static_assert(std::is_same<divide_lists<list<atom<std::ratio<3>>>, list<atom<std::ratio<7>>, atom<std::ratio<3>>>>, list<atom<std::ratio<7>, std::ratio<-1>>>>::value, "");
static_assert(std::is_same<divide_lists<list<atom<std::ratio<3>>, atom<std::ratio<7>>>, list<atom<std::ratio<3>>>>, list<atom<std::ratio<7>>>>::value, "");
static_assert(std::is_same<divide_lists<list<>, list<atom<std::ratio<3>, std::ratio<2>>>>, list<atom<std::ratio<3>, std::ratio<-2>>>>::value, "");
static_assert(std::is_same<divide_lists<list<atom<std::ratio<3>>>, list<atom<std::ratio<3>, std::ratio<2>>>>, list<atom<std::ratio<3>, std::ratio<-1>>>>::value, "");
#pragma endregion
#pragma endregion
#pragma region list generators
//The make_list function generates a list of atoms from an integer_sequence.
template <class ValueType, ValueType... Integers>
constexpr auto make_list_impl(std::integer_sequence<ValueType, Integers...>)
{
    //we multiply with an empty list, to accumulate all the factors together
    return multiply_lists<list<>, list<atom<std::ratio<Integers>>...>>{};
};
template <class Sequence>
using make_list = decltype(make_list_impl(Sequence{}));
//The make_factorial_list function generates a list by
//factorizing a given number.
template <intmax_t Value>
using make_factorial_list = make_list<factorization<Value>>;
//The make_fraction_list function generates a list by
//factorizing a given numerator and denominater.
template <intmax_t num = 1, intmax_t den = 1>
using make_fraction_list = divide_lists<make_factorial_list<num>, make_factorial_list<den>>;
//TODO: - Put this into a unit test folder.
//basic tests
static_assert(std::is_same<make_list<factorization<9>>, list<atom<std::ratio<3>, std::ratio<2>>>>::value, "");
static_assert(std::is_same<multiply_lists<list<>, make_list<factorization<9>>>, list<atom<std::ratio<3>, std::ratio<2>>>>::value, "");
static_assert(std::is_same<make_factorial_list<8>, list<atom<std::ratio<2>, std::ratio<3>>>>::value, "");
static_assert(std::is_same<make_fraction_list<1, 8>, list<atom<std::ratio<2>, std::ratio<-3>>>>::value, "");
static_assert(std::is_same<make_fraction_list<4, 8>, list<atom<std::ratio<2>, std::ratio<-1>>>>::value, "");
static_assert(std::is_same<make_fraction_list<5, 3>, list<atom<std::ratio<3>, std::ratio<-1>>, atom<std::ratio<5>>>>::value, "");
//The make_power_list function generates a list which
//represents 10^Power.
template <intmax_t Power>
using make_power_list = pow_list<make_fraction_list<10>, std::ratio<Power>>;
//TODO: - Put this into a unit test folder.
//basic tests
static_assert(std::is_same<make_power_list<2>, make_fraction_list<100>>::value, "");
static_assert(std::is_same<make_power_list<0>, make_fraction_list<1>>::value, "");
static_assert(std::is_same<make_power_list<-2>, make_fraction_list<1, 100>>::value, "");
static_assert(std::is_same<make_power_list<1>, make_fraction_list<10>>::value, "");
#pragma endregion
#pragma region expansion
//The multiply_elements function calculates the factor given by expanding
//and multiplying all atoms in the list.
template <class ValueType, class... Elements>
constexpr auto multiply_elements_impl(list<Elements...>) {
    static_assert(all_true_v<!is_root_v<Elements>...>, "multiply_elements cannot handle roots in the atoms at the moment. use runtime_multiply_elements instead.");
    return product(impl::array<ValueType, sizeof...(Elements)>{expand_atom_v<ValueType, Elements>...});
}
template <class ValueType, class List>
constexpr ValueType multiply_elements = multiply_elements_impl<ValueType>(List{});
//TODO: - Put this into a unit test folder.
//basic tests
static_assert(multiply_elements<intmax_t, make_fraction_list<8>> == 8, "");
static_assert(multiply_elements<double, make_fraction_list<1, 8>> == 1. / 8., "");
//The runtime_multiply_elements function calculates the factor given by expan-
//ding and multiplying all atoms in the list. However, this is done at
//runtime rather than compile time. The reason being, that std::pow is
//not constexpr. Still, the whole function is marked constexpr to be for-
//ward compatible with a constexpr std::pow implementation.
template <class ValueType, class... Elements>
constexpr auto runtime_multiply_elements(list<Elements...>)
{
    return product(impl::array<ValueType, sizeof...(Elements)>{runtime_expand_atom<ValueType, Elements>()...});
};
#pragma endregion
} // namespace impl
//Pull the list type and its generators into the benri namespace,
//because we need it for constructing units.
using impl::multiply_lists;
using impl::divide_lists;
using impl::pow_list;
using impl::list;
using impl::make_fraction_list;
using impl::make_power_list;
} // namespace benri