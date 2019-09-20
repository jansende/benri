#pragma once
#include <benri/impl/type/list.h>
#include <benri/impl/meta/math.h>

namespace benri
{
namespace type
{
//In the following we have functions which act on prefixes and dimensions exactly the same.
//However, we will have to specialize on the types to reduce the number of template para-
//meters. Whenever we can either have a prefix or a dimension, we will call this entity a
//atom.


#pragma region functions
//The add_to_first_atom function searches the first matching
//atom in a list, and updating it. If it does not exist, the
//entry is added to the end of the list.
template <class List, class Atom>
struct add_to_first_atom_impl
{
    static_assert(detect_if<List, is_list>, "List needs to be type::list.");
    static_assert(detect_if<Atom, is_dimension> || detect_if<Atom, is_prefix>, "Atom needs to be dim or pre.");
    using type = void;
};
template <class Atom>
struct add_to_first_atom_impl<sorted_list<>, Atom>
{
    static_assert(detect_if<Atom, is_dimension> || detect_if<Atom, is_prefix>, "Atom needs to be dim or pre.");
    using type = sorted_list<Atom>;
};
template <class Atom>
struct add_to_first_atom_impl<list<>, Atom>
{
    static_assert(detect_if<Atom, is_dimension> || detect_if<Atom, is_prefix>, "Atom needs to be dim or pre.");
    using type = list<Atom>;
};
template <class T, class lhsPower, class rhsPower, class... RestElements>
struct add_to_first_atom_impl<sorted_list<dim<T, lhsPower>, RestElements...>, dim<T, rhsPower>>
{
    using type = sorted_list<dim<T, std::ratio_add<lhsPower, rhsPower>>, RestElements...>;
};
template <class T, class lhsPower, class rhsPower, class... RestElements>
struct add_to_first_atom_impl<sorted_list<pre<T, lhsPower>, RestElements...>, pre<T, rhsPower>>
{
    using type = sorted_list<pre<T, std::ratio_add<lhsPower, rhsPower>>, RestElements...>;
};
template <class T, class lhsPower, class rhsPower, class... RestElements>
struct add_to_first_atom_impl<list<dim<T, lhsPower>, RestElements...>, dim<T, rhsPower>>
{
    using type = list<dim<T, std::ratio_add<lhsPower, rhsPower>>, RestElements...>;
};
template <class T, class lhsPower, class rhsPower, class... RestElements>
struct add_to_first_atom_impl<list<pre<T, lhsPower>, RestElements...>, pre<T, rhsPower>>
{
    using type = list<pre<T, std::ratio_add<lhsPower, rhsPower>>, RestElements...>;
};
template <class FirstElement, class... RestElements, class Atom>
struct add_to_first_atom_impl<sorted_list<FirstElement, RestElements...>, Atom>
{
    static_assert(detect_if<Atom, is_dimension> || detect_if<Atom, is_prefix>, "Atom needs to be dim or pre.");
    using type = concat<sorted_list<FirstElement>, typename add_to_first_atom_impl<sorted_list<RestElements...>, Atom>::type>;
};
template <class FirstElement, class... RestElements, class Atom>
struct add_to_first_atom_impl<list<FirstElement, RestElements...>, Atom>
{
    static_assert(detect_if<Atom, is_dimension> || detect_if<Atom, is_prefix>, "Atom needs to be dim or pre.");
    using type = concat<list<FirstElement>, typename add_to_first_atom_impl<list<RestElements...>, Atom>::type>;
};
template <class List, class Atom>
using add_to_first_atom = typename add_to_first_atom_impl<List, Atom>::type;
//TODO: - Put this into a unit test folder.
//Basic tests
static_assert(std::is_same<add_to_first_atom<list<>, dim<int>>, list<dim<int>>>::value, "");
static_assert(std::is_same<add_to_first_atom<list<dim<bool>>, dim<int>>, list<dim<bool>, dim<int>>>::value, "");
static_assert(std::is_same<add_to_first_atom<list<dim<int>>, dim<int>>, list<dim<int, std::ratio<2>>>>::value, "");
static_assert(std::is_same<add_to_first_atom<list<dim<int>, dim<bool>>, dim<int>>, list<dim<int, std::ratio<2>>, dim<bool>>>::value, "");
static_assert(std::is_same<add_to_first_atom<list<dim<bool>, dim<int>>, dim<int>>, list<dim<bool>, dim<int, std::ratio<2>>>>::value, "");
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
struct remove_zero_powers_impl<list<NewTs...>, list<dim<T, std::ratio<0>>, OldTs...>> : remove_zero_powers_impl<list<NewTs...>, list<OldTs...>>
{
};
template <class... NewTs, class T, class... OldTs>
struct remove_zero_powers_impl<list<NewTs...>, list<pre<T, std::ratio<0>>, OldTs...>> : remove_zero_powers_impl<list<NewTs...>, list<OldTs...>>
{
};
template <class... NewTs, class T, class... OldTs>
struct remove_zero_powers_impl<sorted_list<NewTs...>, sorted_list<dim<T, std::ratio<0>>, OldTs...>> : remove_zero_powers_impl<sorted_list<NewTs...>, sorted_list<OldTs...>>
{
};
template <class... NewTs, class T, class... OldTs>
struct remove_zero_powers_impl<sorted_list<NewTs...>, sorted_list<pre<T, std::ratio<0>>, OldTs...>> : remove_zero_powers_impl<sorted_list<NewTs...>, sorted_list<OldTs...>>
{
};

template <class List>
using remove_zero_powers = typename remove_zero_powers_impl<std::conditional_t<detect_if<List, is_sorted_list>, sorted_list<>, list<>>, List>::type;
//TODO: - Put this into a unit test folder.
//Basic tests
static_assert(std::is_same<remove_zero_powers<list<>>, list<>>::value, "");
static_assert(std::is_same<remove_zero_powers<sorted_list<>>, sorted_list<>>::value, "");
static_assert(std::is_same<remove_zero_powers<list<dim<bool>>>, list<dim<bool>>>::value, "");
static_assert(std::is_same<remove_zero_powers<sorted_list<dim<bool>>>, sorted_list<dim<bool>>>::value, "");
static_assert(std::is_same<remove_zero_powers<list<dim<bool>, dim<int>>>, list<dim<bool>, dim<int>>>::value, "");
static_assert(std::is_same<remove_zero_powers<sorted_list<dim<bool>, dim<int>>>, sorted_list<dim<bool>, dim<int>>>::value, "");
static_assert(std::is_same<remove_zero_powers<list<dim<bool, std::ratio<0>>>>, list<>>::value, "");
static_assert(std::is_same<remove_zero_powers<sorted_list<dim<bool, std::ratio<0>>>>, sorted_list<>>::value, "");
static_assert(std::is_same<remove_zero_powers<list<dim<bool>, dim<int, std::ratio<0>>>>, list<dim<bool>>>::value, "");
static_assert(std::is_same<remove_zero_powers<sorted_list<dim<bool>, dim<int, std::ratio<0>>>>, sorted_list<dim<bool>>>::value, "");
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
static_assert(std::is_same<multiply_lists<list<>, list<dim<int>>>, sorted_list<dim<int>>>::value, "");
static_assert(std::is_same<multiply_lists<list<dim<int>>, list<>>, sorted_list<dim<int>>>::value, "");
static_assert(std::is_same<multiply_lists<list<dim<int>>, list<dim<bool>>>, sorted_list<dim<bool>, dim<int>>>::value, "");
static_assert(std::is_same<multiply_lists<list<dim<int>>, list<dim<int>>>, sorted_list<dim<int, std::ratio<2>>>>::value, "");
static_assert(std::is_same<multiply_lists<list<dim<int>>, list<dim<int, std::ratio<-1>>>>, sorted_list<>>::value, "");
static_assert(std::is_same<multiply_lists<list<dim<int>>, list<dim<int>, dim<bool>>>, sorted_list<dim<bool>, dim<int, std::ratio<2>>>>::value, "");
static_assert(std::is_same<multiply_lists<list<dim<int>>, list<dim<bool>, dim<int>>>, sorted_list<dim<bool>, dim<int, std::ratio<2>>>>::value, "");
static_assert(std::is_same<multiply_lists<list<dim<bool>, dim<int>>, list<dim<int>>>, sorted_list<dim<bool>, dim<int, std::ratio<2>>>>::value, "");
static_assert(std::is_same<multiply_lists<list<dim<int>, dim<bool>>, list<dim<int>>>, sorted_list<dim<bool>, dim<int, std::ratio<2>>>>::value, "");
//Function for raising prefixes/dimensions by a given Power.
template <class AtomT, class AtomPower, class Power>
constexpr auto pow_atom_impl(dim<AtomT, AtomPower>, Power) -> dim<AtomT, std::ratio_multiply<AtomPower, Power>>;
template <class AtomT, class AtomPower, class Power>
constexpr auto pow_atom_impl(pre<AtomT, AtomPower>, Power) -> pre<AtomT, std::ratio_multiply<AtomPower, Power>>;
template <class Atom, class Power>
using pow_atom = decltype(pow_atom_impl(Atom{}, Power{}));
//Function for raising lists by a given Power.
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
static_assert(std::is_same<pow_list<sorted_list<dim<std::ratio<5>>>, std::ratio<1>>, sorted_list<dim<std::ratio<5>>>>::value, "");
static_assert(std::is_same<pow_list<sorted_list<dim<std::ratio<5>>>, std::ratio<2>>, sorted_list<dim<std::ratio<5>, std::ratio<2>>>>::value, "");
static_assert(std::is_same<pow_list<sorted_list<dim<std::ratio<5>>>, std::ratio<-2>>, sorted_list<dim<std::ratio<5>, std::ratio<-2>>>>::value, "");
static_assert(std::is_same<pow_list<sorted_list<dim<std::ratio<5>>>, std::ratio<1, 3>>, sorted_list<dim<std::ratio<5>, std::ratio<1, 3>>>>::value, "");
static_assert(std::is_same<pow_list<sorted_list<dim<std::ratio<5>>>, std::ratio<-1, 3>>, sorted_list<dim<std::ratio<5>, std::ratio<-1, 3>>>>::value, "");
static_assert(std::is_same<pow_list<sorted_list<dim<std::ratio<3>>, dim<std::ratio<5>>>, std::ratio<1>>, sorted_list<dim<std::ratio<3>>, dim<std::ratio<5>>>>::value, "");
static_assert(std::is_same<pow_list<sorted_list<dim<std::ratio<3>>, dim<std::ratio<5>>>, std::ratio<2>>, sorted_list<dim<std::ratio<3>, std::ratio<2>>, dim<std::ratio<5>, std::ratio<2>>>>::value, "");
static_assert(std::is_same<pow_list<sorted_list<dim<std::ratio<3>>, dim<std::ratio<5>>>, std::ratio<-2>>, sorted_list<dim<std::ratio<3>, std::ratio<-2>>, dim<std::ratio<5>, std::ratio<-2>>>>::value, "");
static_assert(std::is_same<pow_list<sorted_list<dim<std::ratio<3>>, dim<std::ratio<5>>>, std::ratio<1, 3>>, sorted_list<dim<std::ratio<3>, std::ratio<1, 3>>, dim<std::ratio<5>, std::ratio<1, 3>>>>::value, "");
static_assert(std::is_same<pow_list<sorted_list<dim<std::ratio<3>>, dim<std::ratio<5>>>, std::ratio<-1, 3>>, sorted_list<dim<std::ratio<3>, std::ratio<-1, 3>>, dim<std::ratio<5>, std::ratio<-1, 3>>>>::value, "");
//The divide_lists function combines the atoms in two lists,
//by multiplying the left side with the inverse of the right
//side.
template <class lhsList, class rhsList>
using divide_lists = multiply_lists<lhsList, pow_list<rhsList, std::ratio<-1>>>;
//TODO: - Put this into a unit test folder.
//Basic tests
static_assert(std::is_same<divide_lists<list<>, list<dim<int>>>, sorted_list<dim<int, std::ratio<-1>>>>::value, "");
static_assert(std::is_same<divide_lists<list<dim<int>>, list<>>, sorted_list<dim<int>>>::value, "");
static_assert(std::is_same<divide_lists<list<dim<int>>, list<dim<bool>>>, sorted_list<dim<bool, std::ratio<-1>>, dim<int>>>::value, "");
static_assert(std::is_same<divide_lists<list<dim<int>>, list<dim<int>>>, sorted_list<>>::value, "");
static_assert(std::is_same<divide_lists<list<dim<int>>, list<dim<int>, dim<bool>>>, sorted_list<dim<bool, std::ratio<-1>>>>::value, "");
static_assert(std::is_same<divide_lists<list<dim<int>>, list<dim<bool>, dim<int>>>, sorted_list<dim<bool, std::ratio<-1>>>>::value, "");
static_assert(std::is_same<divide_lists<list<dim<int>, dim<bool>>, list<dim<int>>>, sorted_list<dim<bool>>>::value, "");
static_assert(std::is_same<divide_lists<list<>, list<dim<std::ratio<3>>>>, sorted_list<dim<std::ratio<3>, std::ratio<-1>>>>::value, "");
static_assert(std::is_same<divide_lists<list<dim<std::ratio<3>>>, list<>>, sorted_list<dim<std::ratio<3>>>>::value, "");
static_assert(std::is_same<divide_lists<list<dim<std::ratio<3>>>, list<dim<std::ratio<7>>>>, sorted_list<dim<std::ratio<3>>, dim<std::ratio<7>, std::ratio<-1>>>>::value, "");
static_assert(std::is_same<divide_lists<list<dim<std::ratio<3>>>, list<dim<std::ratio<3>>>>, sorted_list<>>::value, "");
static_assert(std::is_same<divide_lists<list<dim<std::ratio<3>>>, list<dim<std::ratio<3>>, dim<std::ratio<7>>>>, sorted_list<dim<std::ratio<7>, std::ratio<-1>>>>::value, "");
static_assert(std::is_same<divide_lists<list<dim<std::ratio<3>>>, list<dim<std::ratio<7>>, dim<std::ratio<3>>>>, sorted_list<dim<std::ratio<7>, std::ratio<-1>>>>::value, "");
static_assert(std::is_same<divide_lists<list<dim<std::ratio<3>>, dim<std::ratio<7>>>, list<dim<std::ratio<3>>>>, sorted_list<dim<std::ratio<7>>>>::value, "");
static_assert(std::is_same<divide_lists<list<>, list<dim<std::ratio<3>, std::ratio<2>>>>, sorted_list<dim<std::ratio<3>, std::ratio<-2>>>>::value, "");
static_assert(std::is_same<divide_lists<list<dim<std::ratio<3>>>, list<dim<std::ratio<3>, std::ratio<2>>>>, sorted_list<dim<std::ratio<3>, std::ratio<-1>>>>::value, "");
#pragma endregion
#pragma region generators
//Function for generating a prefix list from a std::integer_sequence.
//(We multiply with an empty sorted_list to accumulate the prefixes together.)
template <class ValueType, ValueType... Integers>
constexpr auto make_list_impl(std::integer_sequence<ValueType, Integers...>)
    -> multiply_lists<sorted_list<>, list<pre<std::ratio<Integers>>...>>;
template <class Sequence>
using make_list = decltype(make_list_impl(Sequence{}));
//Basic tests
static_assert(std::is_same<make_list<meta::prime_factors<6>>, sorted_list<pre<std::ratio<2>>, pre<std::ratio<3>>>>::value, "make_list<prime_factor<6>> is list<pre<2>, pre<3>>.");
static_assert(std::is_same<make_list<meta::prime_factors<8>>, sorted_list<pre<std::ratio<2>, std::ratio<3>>>>::value, "make_list<prime_factor<8>> is list<pre<2, 3>>.");
static_assert(std::is_same<make_list<meta::prime_factors<9>>, sorted_list<pre<std::ratio<3>, std::ratio<2>>>>::value, "make_list<prime_factor<9>> is list<pre<3, 2>>.");
//Function for generating a prefix from a given numerator and denominater.
template <intmax_t num = 1, intmax_t den = 1>
using make_prefix = divide_lists<
    make_list<meta::prime_factors<num>>,
    make_list<meta::prime_factors<den>>>;
//Basic tests
static_assert(std::is_same<make_prefix<8>, sorted_list<pre<std::ratio<2>, std::ratio<3>>>>::value, "type::make_prefix<8> is list<pre<2, 3>>.");
static_assert(std::is_same<make_prefix<1, 8>, sorted_list<pre<std::ratio<2>, std::ratio<-3>>>>::value, "type::make_prefix<1, 8> is list<pre<2, -3>>.");
static_assert(std::is_same<make_prefix<4, 8>, sorted_list<pre<std::ratio<2>, std::ratio<-1>>>>::value, "type::make_prefix<4, 8> is list<pre<2, -1>>.");
static_assert(std::is_same<make_prefix<5, 3>, sorted_list<pre<std::ratio<3>, std::ratio<-1>>, pre<std::ratio<5>>>>::value, "type::make_prefix<5, 3> is list<pre<3, -1>, pre<5>>.");
//Shortcut for generating prefixes of 10^Power.
template <intmax_t Power>
using make_prefix_pow10 = pow_list<make_prefix<10>, std::ratio<Power>>;
//Basic tests
static_assert(std::is_same<make_prefix_pow10<2>, make_prefix<100>>::value, "type::make_prefix_pow10<2> is same as type::make_prefix<100>.");
static_assert(std::is_same<make_prefix_pow10<0>, make_prefix<1>>::value, "type::make_prefix_pow10<0> is same as type::make_prefix<1>.");
static_assert(std::is_same<make_prefix_pow10<-2>, make_prefix<1, 100>>::value, "type::make_prefix_pow10<-2> is same as type::make_prefix<1, 100>.");
static_assert(std::is_same<make_prefix_pow10<1>, make_prefix<10>>::value, "type::make_prefix_pow10<1> is same as type::make_prefix<10>.");
#pragma endregion
} // namespace type
} // namespace benri