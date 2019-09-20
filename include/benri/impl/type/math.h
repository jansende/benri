#pragma once
#include <benri/impl/type/list.h>
#include <benri/impl/meta/math.h>

namespace benri
{
namespace type
{
#pragma region multiplication
//The add_to_first_atom function searches the first matching
//atom in a list, and updating it. If it does not exist, the
//entry is added to the end of the list.
template <class List, class Atom>
struct add_to_first_atom_impl
{
    static_assert(detect_if<List, is_list>, "the lhs of add_to_first_atom needs to be a list.");
    static_assert(detect_if<Atom, impl::is_atom>, "the rhs of add_to_first_atom needs to be an atom.");
    using type = void;
};
template <class Atom>
struct add_to_first_atom_impl<sorted_list<>, Atom>
{
    static_assert(detect_if<Atom, impl::is_atom>, "the rhs of add_to_first_atom needs to be an atom.");
    using type = sorted_list<Atom>;
};
template <class Atom>
struct add_to_first_atom_impl<list<>, Atom>
{
    static_assert(detect_if<Atom, impl::is_atom>, "the rhs of add_to_first_atom needs to be an atom.");
    using type = list<Atom>;
};
template <class T, class lhsPower, class rhsPower, class... RestElements>
struct add_to_first_atom_impl<sorted_list<impl::dim<T, lhsPower>, RestElements...>, impl::dim<T, rhsPower>>
{
    using type = sorted_list<impl::dim<T, std::ratio_add<lhsPower, rhsPower>>, RestElements...>;
};
template <class T, class lhsPower, class rhsPower, class... RestElements>
struct add_to_first_atom_impl<sorted_list<impl::pre<T, lhsPower>, RestElements...>, impl::pre<T, rhsPower>>
{
    using type = sorted_list<impl::pre<T, std::ratio_add<lhsPower, rhsPower>>, RestElements...>;
};
template <class T, class lhsPower, class rhsPower, class... RestElements>
struct add_to_first_atom_impl<list<impl::dim<T, lhsPower>, RestElements...>, impl::dim<T, rhsPower>>
{
    using type = list<impl::dim<T, std::ratio_add<lhsPower, rhsPower>>, RestElements...>;
};
template <class T, class lhsPower, class rhsPower, class... RestElements>
struct add_to_first_atom_impl<list<impl::pre<T, lhsPower>, RestElements...>, impl::pre<T, rhsPower>>
{
    using type = list<impl::pre<T, std::ratio_add<lhsPower, rhsPower>>, RestElements...>;
};
template <class FirstElement, class... RestElements, class Atom>
struct add_to_first_atom_impl<sorted_list<FirstElement, RestElements...>, Atom>
{
    static_assert(detect_if<Atom, impl::is_atom>, "the rhs of add_to_first_atom needs to be an atom.");
    using type = concat<sorted_list<FirstElement>, typename add_to_first_atom_impl<sorted_list<RestElements...>, Atom>::type>;
};
template <class FirstElement, class... RestElements, class Atom>
struct add_to_first_atom_impl<list<FirstElement, RestElements...>, Atom>
{
    static_assert(detect_if<Atom, impl::is_atom>, "the rhs of add_to_first_atom needs to be an atom.");
    using type = concat<list<FirstElement>, typename add_to_first_atom_impl<list<RestElements...>, Atom>::type>;
};
template <class List, class Atom>
using add_to_first_atom = typename add_to_first_atom_impl<List, Atom>::type;
//TODO: - Put this into a unit test folder.
//Basic tests
static_assert(std::is_same<add_to_first_atom<list<>, impl::dim<int>>, list<impl::dim<int>>>::value, "");
static_assert(std::is_same<add_to_first_atom<list<impl::dim<bool>>, impl::dim<int>>, list<impl::dim<bool>, impl::dim<int>>>::value, "");
static_assert(std::is_same<add_to_first_atom<list<impl::dim<int>>, impl::dim<int>>, list<impl::dim<int, std::ratio<2>>>>::value, "");
static_assert(std::is_same<add_to_first_atom<list<impl::dim<int>, impl::dim<bool>>, impl::dim<int>>, list<impl::dim<int, std::ratio<2>>, impl::dim<bool>>>::value, "");
static_assert(std::is_same<add_to_first_atom<list<impl::dim<bool>, impl::dim<int>>, impl::dim<int>>, list<impl::dim<bool>, impl::dim<int, std::ratio<2>>>>::value, "");
//The remove_zero_powers function removes all atom with a power of zero from the list.
template <class Result, class List>
struct remove_zero_powers_impl
{
};
template <class... NewTs>
struct remove_zero_powers_impl<list<NewTs...>, list<>>
{
    using type = list<NewTs...>;
};
template <class... NewTs>
struct remove_zero_powers_impl<sorted_list<NewTs...>, sorted_list<>>
{
    using type = sorted_list<NewTs...>;
};
template <class... NewTs, class OldT, class... OldTs>
struct remove_zero_powers_impl<list<NewTs...>, list<OldT, OldTs...>> : remove_zero_powers_impl<list<NewTs..., OldT>, list<OldTs...>>
{
};
template <class... NewTs, class OldT, class... OldTs>
struct remove_zero_powers_impl<sorted_list<NewTs...>, sorted_list<OldT, OldTs...>> : remove_zero_powers_impl<sorted_list<NewTs..., OldT>, sorted_list<OldTs...>>
{
};
template <class... NewTs, class T, class... OldTs>
struct remove_zero_powers_impl<list<NewTs...>, list<impl::dim<T, std::ratio<0>>, OldTs...>> : remove_zero_powers_impl<list<NewTs...>, list<OldTs...>>
{
};
template <class... NewTs, class T, class... OldTs>
struct remove_zero_powers_impl<list<NewTs...>, list<impl::pre<T, std::ratio<0>>, OldTs...>> : remove_zero_powers_impl<list<NewTs...>, list<OldTs...>>
{
};
template <class... NewTs, class T, class... OldTs>
struct remove_zero_powers_impl<sorted_list<NewTs...>, sorted_list<impl::dim<T, std::ratio<0>>, OldTs...>> : remove_zero_powers_impl<sorted_list<NewTs...>, sorted_list<OldTs...>>
{
};
template <class... NewTs, class T, class... OldTs>
struct remove_zero_powers_impl<sorted_list<NewTs...>, sorted_list<impl::pre<T, std::ratio<0>>, OldTs...>> : remove_zero_powers_impl<sorted_list<NewTs...>, sorted_list<OldTs...>>
{
};

template <class List>
using remove_zero_powers = typename remove_zero_powers_impl<std::conditional_t<detect_if<List, is_sorted_list>, sorted_list<>, list<>>, List>::type;
//TODO: - Put this into a unit test folder.
//Basic tests
static_assert(std::is_same<remove_zero_powers<list<>>, list<>>::value, "");
static_assert(std::is_same<remove_zero_powers<sorted_list<>>, sorted_list<>>::value, "");
static_assert(std::is_same<remove_zero_powers<list<impl::dim<bool>>>, list<impl::dim<bool>>>::value, "");
static_assert(std::is_same<remove_zero_powers<sorted_list<impl::dim<bool>>>, sorted_list<impl::dim<bool>>>::value, "");
static_assert(std::is_same<remove_zero_powers<list<impl::dim<bool>, impl::dim<int>>>, list<impl::dim<bool>, impl::dim<int>>>::value, "");
static_assert(std::is_same<remove_zero_powers<sorted_list<impl::dim<bool>, impl::dim<int>>>, sorted_list<impl::dim<bool>, impl::dim<int>>>::value, "");
static_assert(std::is_same<remove_zero_powers<list<impl::dim<bool, std::ratio<0>>>>, list<>>::value, "");
static_assert(std::is_same<remove_zero_powers<sorted_list<impl::dim<bool, std::ratio<0>>>>, sorted_list<>>::value, "");
static_assert(std::is_same<remove_zero_powers<list<impl::dim<bool>, impl::dim<int, std::ratio<0>>>>, list<impl::dim<bool>>>::value, "");
static_assert(std::is_same<remove_zero_powers<sorted_list<impl::dim<bool>, impl::dim<int, std::ratio<0>>>>, sorted_list<impl::dim<bool>>>::value, "");
//The multiply_lists function combines the atoms in two lists,
//by adding the power of atoms with the same type.
template <class... Lists>
struct multiply_lists_impl
{
};
template <class lhsList>
struct multiply_lists_impl<lhsList, sorted_list<>>
{
    using type = lhsList;
};
template <class lhsList>
struct multiply_lists_impl<lhsList, list<>>
{
    using type = lhsList;
};
template <class lhsList, class rhsElement>
struct multiply_lists_impl<lhsList, sorted_list<rhsElement>>
{
    using type = add_to_first_atom<lhsList, rhsElement>;
};
template <class lhsList, class rhsElement>
struct multiply_lists_impl<lhsList, list<rhsElement>>
{
    using type = add_to_first_atom<lhsList, rhsElement>;
};
template <class lhsList, class rhsFirstElement, class... rhsRestElements>
struct multiply_lists_impl<lhsList, sorted_list<rhsFirstElement, rhsRestElements...>> : multiply_lists_impl<add_to_first_atom<lhsList, rhsFirstElement>, sorted_list<rhsRestElements...>>
{
};
template <class lhsList, class rhsFirstElement, class... rhsRestElements>
struct multiply_lists_impl<lhsList, list<rhsFirstElement, rhsRestElements...>> : multiply_lists_impl<add_to_first_atom<lhsList, rhsFirstElement>, list<rhsRestElements...>>
{
};
template <class lhsList, class rhsList, class... RestLists>
struct multiply_lists_impl<lhsList, rhsList, RestLists...> : multiply_lists_impl<typename multiply_lists_impl<lhsList, rhsList>::type, RestLists...>
{
};
template <class... Lists>
using multiply_lists = sort<remove_zero_powers<typename multiply_lists_impl<Lists...>::type>>;
//TODO: - Put this into a unit test folder.
//Basic tests
static_assert(std::is_same<multiply_lists<list<>, list<impl::dim<int>>>, sorted_list<impl::dim<int>>>::value, "");
static_assert(std::is_same<multiply_lists<list<impl::dim<int>>, list<>>, sorted_list<impl::dim<int>>>::value, "");
static_assert(std::is_same<multiply_lists<list<impl::dim<int>>, list<impl::dim<bool>>>, sorted_list<impl::dim<bool>, impl::dim<int>>>::value, "");
static_assert(std::is_same<multiply_lists<list<impl::dim<int>>, list<impl::dim<int>>>, sorted_list<impl::dim<int, std::ratio<2>>>>::value, "");
static_assert(std::is_same<multiply_lists<list<impl::dim<int>>, list<impl::dim<int, std::ratio<-1>>>>, sorted_list<>>::value, "");
static_assert(std::is_same<multiply_lists<list<impl::dim<int>>, list<impl::dim<int>, impl::dim<bool>>>, sorted_list<impl::dim<bool>, impl::dim<int, std::ratio<2>>>>::value, "");
static_assert(std::is_same<multiply_lists<list<impl::dim<int>>, list<impl::dim<bool>, impl::dim<int>>>, sorted_list<impl::dim<bool>, impl::dim<int, std::ratio<2>>>>::value, "");
static_assert(std::is_same<multiply_lists<list<impl::dim<bool>, impl::dim<int>>, list<impl::dim<int>>>, sorted_list<impl::dim<bool>, impl::dim<int, std::ratio<2>>>>::value, "");
static_assert(std::is_same<multiply_lists<list<impl::dim<int>, impl::dim<bool>>, list<impl::dim<int>>>, sorted_list<impl::dim<bool>, impl::dim<int, std::ratio<2>>>>::value, "");
#pragma endregion
#pragma region power
//The pow_list function adds a given power to every atom in a
//list.
template <class AtomT, class AtomPower, class Power>
constexpr auto pow_atom_impl(impl::dim<AtomT, AtomPower>, Power) -> impl::dim<AtomT, std::ratio_multiply<AtomPower, Power>>;
template <class AtomT, class AtomPower, class Power>
constexpr auto pow_atom_impl(impl::pre<AtomT, AtomPower>, Power) -> impl::pre<AtomT, std::ratio_multiply<AtomPower, Power>>;
template <class Atom, class Power>
using pow_atom = decltype(pow_atom_impl(Atom{}, Power{}));

template <class... Elements, class Power>
constexpr auto pow_list_impl(sorted_list<Elements...>, Power) -> std::conditional_t<std::is_same<Power, std::ratio<0>>::value, sorted_list<>, sorted_list<pow_atom<Elements, Power>...>>;
template <class... Elements, class Power>
constexpr auto pow_list_impl(list<Elements...>, Power) -> std::conditional_t<std::is_same<Power, std::ratio<0>>::value, list<>, list<pow_atom<Elements, Power>...>>;
template <class List, class Power>
using pow_list = decltype(pow_list_impl(List{}, Power{}));
//TODO: - Put this into a unit test folder.
//Basic tests
static_assert(std::is_same<pow_list<sorted_list<>, std::ratio<2>>, sorted_list<>>::value, "");
static_assert(std::is_same<pow_list<sorted_list<>, std::ratio<-2>>, sorted_list<>>::value, "");
static_assert(std::is_same<pow_list<sorted_list<>, std::ratio<1, 3>>, sorted_list<>>::value, "");
static_assert(std::is_same<pow_list<sorted_list<>, std::ratio<-1, 3>>, sorted_list<>>::value, "");
static_assert(std::is_same<pow_list<sorted_list<impl::dim<std::ratio<5>>>, std::ratio<1>>, sorted_list<impl::dim<std::ratio<5>>>>::value, "");
static_assert(std::is_same<pow_list<sorted_list<impl::dim<std::ratio<5>>>, std::ratio<2>>, sorted_list<impl::dim<std::ratio<5>, std::ratio<2>>>>::value, "");
static_assert(std::is_same<pow_list<sorted_list<impl::dim<std::ratio<5>>>, std::ratio<-2>>, sorted_list<impl::dim<std::ratio<5>, std::ratio<-2>>>>::value, "");
static_assert(std::is_same<pow_list<sorted_list<impl::dim<std::ratio<5>>>, std::ratio<1, 3>>, sorted_list<impl::dim<std::ratio<5>, std::ratio<1, 3>>>>::value, "");
static_assert(std::is_same<pow_list<sorted_list<impl::dim<std::ratio<5>>>, std::ratio<-1, 3>>, sorted_list<impl::dim<std::ratio<5>, std::ratio<-1, 3>>>>::value, "");
static_assert(std::is_same<pow_list<sorted_list<impl::dim<std::ratio<3>>, impl::dim<std::ratio<5>>>, std::ratio<1>>, sorted_list<impl::dim<std::ratio<3>>, impl::dim<std::ratio<5>>>>::value, "");
static_assert(std::is_same<pow_list<sorted_list<impl::dim<std::ratio<3>>, impl::dim<std::ratio<5>>>, std::ratio<2>>, sorted_list<impl::dim<std::ratio<3>, std::ratio<2>>, impl::dim<std::ratio<5>, std::ratio<2>>>>::value, "");
static_assert(std::is_same<pow_list<sorted_list<impl::dim<std::ratio<3>>, impl::dim<std::ratio<5>>>, std::ratio<-2>>, sorted_list<impl::dim<std::ratio<3>, std::ratio<-2>>, impl::dim<std::ratio<5>, std::ratio<-2>>>>::value, "");
static_assert(std::is_same<pow_list<sorted_list<impl::dim<std::ratio<3>>, impl::dim<std::ratio<5>>>, std::ratio<1, 3>>, sorted_list<impl::dim<std::ratio<3>, std::ratio<1, 3>>, impl::dim<std::ratio<5>, std::ratio<1, 3>>>>::value, "");
static_assert(std::is_same<pow_list<sorted_list<impl::dim<std::ratio<3>>, impl::dim<std::ratio<5>>>, std::ratio<-1, 3>>, sorted_list<impl::dim<std::ratio<3>, std::ratio<-1, 3>>, impl::dim<std::ratio<5>, std::ratio<-1, 3>>>>::value, "");
#pragma endregion
#pragma region division
//The divide_lists function combines the atoms in two lists,
//by multiplying the left side with the inverse of the right
//side.
template <class lhsList, class rhsList>
using divide_lists = multiply_lists<lhsList, pow_list<rhsList, std::ratio<-1>>>;
//TODO: - Put this into a unit test folder.
//Basic tests
static_assert(std::is_same<divide_lists<list<>, list<impl::dim<int>>>, sorted_list<impl::dim<int, std::ratio<-1>>>>::value, "");
static_assert(std::is_same<divide_lists<list<impl::dim<int>>, list<>>, sorted_list<impl::dim<int>>>::value, "");
static_assert(std::is_same<divide_lists<list<impl::dim<int>>, list<impl::dim<bool>>>, sorted_list<impl::dim<bool, std::ratio<-1>>, impl::dim<int>>>::value, "");
static_assert(std::is_same<divide_lists<list<impl::dim<int>>, list<impl::dim<int>>>, sorted_list<>>::value, "");
static_assert(std::is_same<divide_lists<list<impl::dim<int>>, list<impl::dim<int>, impl::dim<bool>>>, sorted_list<impl::dim<bool, std::ratio<-1>>>>::value, "");
static_assert(std::is_same<divide_lists<list<impl::dim<int>>, list<impl::dim<bool>, impl::dim<int>>>, sorted_list<impl::dim<bool, std::ratio<-1>>>>::value, "");
static_assert(std::is_same<divide_lists<list<impl::dim<int>, impl::dim<bool>>, list<impl::dim<int>>>, sorted_list<impl::dim<bool>>>::value, "");
static_assert(std::is_same<divide_lists<list<>, list<impl::dim<std::ratio<3>>>>, sorted_list<impl::dim<std::ratio<3>, std::ratio<-1>>>>::value, "");
static_assert(std::is_same<divide_lists<list<impl::dim<std::ratio<3>>>, list<>>, sorted_list<impl::dim<std::ratio<3>>>>::value, "");
static_assert(std::is_same<divide_lists<list<impl::dim<std::ratio<3>>>, list<impl::dim<std::ratio<7>>>>, sorted_list<impl::dim<std::ratio<3>>, impl::dim<std::ratio<7>, std::ratio<-1>>>>::value, "");
static_assert(std::is_same<divide_lists<list<impl::dim<std::ratio<3>>>, list<impl::dim<std::ratio<3>>>>, sorted_list<>>::value, "");
static_assert(std::is_same<divide_lists<list<impl::dim<std::ratio<3>>>, list<impl::dim<std::ratio<3>>, impl::dim<std::ratio<7>>>>, sorted_list<impl::dim<std::ratio<7>, std::ratio<-1>>>>::value, "");
static_assert(std::is_same<divide_lists<list<impl::dim<std::ratio<3>>>, list<impl::dim<std::ratio<7>>, impl::dim<std::ratio<3>>>>, sorted_list<impl::dim<std::ratio<7>, std::ratio<-1>>>>::value, "");
static_assert(std::is_same<divide_lists<list<impl::dim<std::ratio<3>>, impl::dim<std::ratio<7>>>, list<impl::dim<std::ratio<3>>>>, sorted_list<impl::dim<std::ratio<7>>>>::value, "");
static_assert(std::is_same<divide_lists<list<>, list<impl::dim<std::ratio<3>, std::ratio<2>>>>, sorted_list<impl::dim<std::ratio<3>, std::ratio<-2>>>>::value, "");
static_assert(std::is_same<divide_lists<list<impl::dim<std::ratio<3>>>, list<impl::dim<std::ratio<3>, std::ratio<2>>>>, sorted_list<impl::dim<std::ratio<3>, std::ratio<-1>>>>::value, "");
#pragma endregion
#pragma endregion
#pragma region list generators
//The make_list function generates a list of atoms from an integer_sequence.
//we multiply with an empty list, to accumulate all the factors together
template <class ValueType, ValueType... Integers>
constexpr auto make_list_impl(std::integer_sequence<ValueType, Integers...>) -> multiply_lists<sorted_list<>, list<impl::pre<std::ratio<Integers>>...>>;
template <class Sequence>
using make_list = decltype(make_list_impl(Sequence{}));
//The make_factorial_list function generates a list by
//factorizing a given number.
template <intmax_t Value>
using make_factorial_list = make_list<meta::prime_factors<Value>>;
//The make_fraction_list function generates a list by
//factorizing a given numerator and denominater.
template <intmax_t num = 1, intmax_t den = 1>
using make_fraction_list = divide_lists<make_factorial_list<num>, make_factorial_list<den>>;
//TODO: - Put this into a unit test folder.
//Basic tests
static_assert(std::is_same<make_list<meta::prime_factors<9>>, sorted_list<impl::pre<std::ratio<3>, std::ratio<2>>>>::value, "");
static_assert(std::is_same<multiply_lists<list<>, make_list<meta::prime_factors<9>>>, sorted_list<impl::pre<std::ratio<3>, std::ratio<2>>>>::value, "");
static_assert(std::is_same<make_factorial_list<8>, sorted_list<impl::pre<std::ratio<2>, std::ratio<3>>>>::value, "");
static_assert(std::is_same<make_fraction_list<1, 8>, sorted_list<impl::pre<std::ratio<2>, std::ratio<-3>>>>::value, "");
static_assert(std::is_same<make_fraction_list<4, 8>, sorted_list<impl::pre<std::ratio<2>, std::ratio<-1>>>>::value, "");
static_assert(std::is_same<make_fraction_list<5, 3>, sorted_list<impl::pre<std::ratio<3>, std::ratio<-1>>, impl::pre<std::ratio<5>>>>::value, "");
//The make_power_list function generates a list which
//represents 10^Power.
template <intmax_t Power>
using make_power_list = pow_list<make_fraction_list<10>, std::ratio<Power>>;
//TODO: - Put this into a unit test folder.
//Basic tests
static_assert(std::is_same<make_power_list<2>, make_fraction_list<100>>::value, "");
static_assert(std::is_same<make_power_list<0>, make_fraction_list<1>>::value, "");
static_assert(std::is_same<make_power_list<-2>, make_fraction_list<1, 100>>::value, "");
static_assert(std::is_same<make_power_list<1>, make_fraction_list<10>>::value, "");
#pragma endregion
#pragma region expansion
//The multiply_elements function calculates the factor given by expanding
//and multiplying all atoms in the list.
template <class ValueType, class... Elements>
constexpr auto multiply_elements_impl(sorted_list<Elements...>)
{
    static_assert(all_true<!detect_if<Elements, impl::is_root>...>, "multiply_elements cannot handle roots in the atoms at the moment. use runtime_multiply_elements instead.");
    return meta::accumulate(meta::array<ValueType, sizeof...(Elements)>{impl::expand_prefix<ValueType, Elements>...}, ValueType{1}, std::multiplies<ValueType>());
}
template <class ValueType, class List>
constexpr ValueType multiply_elements = multiply_elements_impl<ValueType>(List{});
//TODO: - Put this into a unit test folder.
//Basic tests
static_assert(multiply_elements<intmax_t, make_fraction_list<8>> == 8, "");
static_assert(multiply_elements<double, make_fraction_list<1, 8>> == 1. / 8., "");
//The runtime_multiply_elements function calculates the factor given by expan-
//ding and multiplying all atoms in the list. However, this is done at
//runtime rather than compile time. The reason being, that std::pow is
//not constexpr. Still, the whole function is marked constexpr to be for-
//ward compatible with a constexpr std::pow implementation.
template <class ValueType, class... Elements>
constexpr auto runtime_multiply_elements(sorted_list<Elements...>)
{
    return meta::accumulate(meta::array<ValueType, sizeof...(Elements)>{impl::runtime_expand_prefix<ValueType, Elements>()...}, ValueType{1}, std::multiplies<ValueType>());
};
#pragma endregion
} // namespace type
using type::divide_lists;
using type::make_fraction_list;
using type::make_power_list;
using type::multiply_lists;
using type::pow_list;
} // namespace benri