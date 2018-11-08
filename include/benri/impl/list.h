#pragma once
#include <cmath>
#include <benri/impl/atom.h>
#include <benri/impl/type_traits.h>
#include <benri/impl/meta_math.h>
#include <benri/impl/array.h>
#include <benri/impl/algorithm.h>

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
//The concat_lists function lets you concatenate two or more lists.
template <class... Lists>
struct concat_lists
{
    static_assert(all_true_v<is_list_v<Lists>...>, "all arguments of concat_lists need to be lists.");
    using type = void;
};
template <class... lhsElements, class... rhsElements>
struct concat_lists<list<lhsElements...>, list<rhsElements...>>
{
    using type = list<lhsElements..., rhsElements...>;
};
template <class lhsList, class rhsList, class... RestLists>
struct concat_lists<lhsList, rhsList, RestLists...>
{
    static_assert(is_list_v<lhsList> && is_list_v<rhsList> && all_true_v<is_list_v<RestLists>...>, "all arguments of concat_lists need to be lists.");
    using type = typename concat_lists<typename concat_lists<lhsList, rhsList>::type, RestLists...>::type;
};
template <class... Lists>
using concat_lists_t = typename concat_lists<Lists...>::type;
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
//The drop_first_match removes the first appearance of the atom Atom
//in a list. If the Atom is not in the list, nothing is changed.
template <class List, class Atom>
struct drop_first_match
{
    static_assert(is_list_v<List>, "the lhs of drop_first_match needs to be a list.");
    static_assert(is_atom_v<Atom>, "the rhs of drop_first_match needs to be an atom.");
    using type = void;
};
template <class Atom>
struct drop_first_match<list<>, Atom>
{
    static_assert(is_atom_v<Atom>, "the rhs of drop_first_match needs to be an atom.");
    using type = list<>;
};
template <class Atom, class... RestElements>
struct drop_first_match<list<Atom, RestElements...>, Atom>
{
    static_assert(is_atom_v<Atom>, "the rhs of drop_first_match needs to be an atom.");
    using type = list<RestElements...>;
};
template <class Atom, class FirstElement, class... RestElements>
struct drop_first_match<list<FirstElement, RestElements...>, Atom>
{
    static_assert(is_atom_v<Atom>, "the rhs of drop_first_match needs to be an atom.");
    using type = concat_lists_t<list<FirstElement>, typename drop_first_match<list<RestElements...>, Atom>::type>;
};
template <class List, class Atom>
using drop_first_match_t = typename drop_first_match<List, Atom>::type;
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
template <class lhsList, class rhsList>
struct is_equivalent_list_impl
{
    static_assert(is_list_v<lhsList> && is_list_v<rhsList>, "lhs and rhs of is_equivalent need to be lists.");
    static constexpr auto value = false;
};
template <>
struct is_equivalent_list_impl<list<>, list<>>
{
    static constexpr auto value = true;
};
template <class lhsElement, class... rhsElements>
struct is_equivalent_list_impl<list<lhsElement>, list<rhsElements...>>
{
    static constexpr auto value = std::is_same_v<drop_first_match_t<list<rhsElements...>, lhsElement>, list<>> && (sizeof...(rhsElements) == 1);
};
template <class lhsFirstElement, class... lhsRestElements, class... rhsElements>
struct is_equivalent_list_impl<list<lhsFirstElement, lhsRestElements...>, list<rhsElements...>>
{
    static constexpr auto value = is_equivalent_list_impl<list<lhsRestElements...>, drop_first_match_t<list<rhsElements...>, lhsFirstElement>>::value && (sizeof...(lhsRestElements) + 1 == sizeof...(rhsElements));
};
template <class lhsList, class rhsList>
struct is_equivalent_list : std::integral_constant<bool, is_equivalent_list_impl<lhsList, rhsList>::value>
{
};
template <class lhsList, class rhsList>
constexpr bool is_equivalent_list_v = is_equivalent_list<lhsList, rhsList>::value;
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
template <class List>
struct drop_zero_atoms
{
    static_assert(is_list_v<List>, "the argument of drop_zero_atoms needs to be a list.");
    using type = void;
};
template <>
struct drop_zero_atoms<list<>>
{
    using type = list<>;
};
template <template <class, class> class Atom, class T, class... RestElements>
struct drop_zero_atoms<list<Atom<T, std::ratio<0>>, RestElements...>>
{
    using type = typename drop_zero_atoms<list<RestElements...>>::type;
};
template <class FirstElement, class... RestElements>
struct drop_zero_atoms<list<FirstElement, RestElements...>>
{
    using type = concat_lists_t<list<FirstElement>, typename drop_zero_atoms<list<RestElements...>>::type>;
};
template <class List>
using drop_zero_atoms_t = typename drop_zero_atoms<List>::type;
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
template <class List, class Atom>
struct add_to_first_atom
{
    static_assert(is_list_v<List>, "the lhs of add_to_first_atom needs to be a list.");
    static_assert(is_atom_v<Atom>, "the rhs of add_to_first_atom needs to be an atom.");
    using type = void;
};
template <class Atom>
struct add_to_first_atom<list<>, Atom>
{
    static_assert(is_atom_v<Atom>, "the rhs of add_to_first_atom needs to be an atom.");
    using type = list<Atom>;
};
template <template <class, class> class lhsAtom, template <class, class> class rhsAtom, class T, class lhsPower, class rhsPower, class... RestElements>
struct add_to_first_atom<list<lhsAtom<T, lhsPower>, RestElements...>, rhsAtom<T, rhsPower>>
{
    static_assert(is_atom_v<rhsAtom<T, rhsPower>>, "the rhs of add_to_first_atom needs to be an atom.");
    using type = list<lhsAtom<T, std::ratio_add<lhsPower, rhsPower>>, RestElements...>;
};
template <class FirstElement, class... RestElements, template <class, class> class Atom, class T, class Power>
struct add_to_first_atom<list<FirstElement, RestElements...>, Atom<T, Power>>
{
    static_assert(is_atom_v<Atom<T, Power>>, "the rhs of add_to_first_atom needs to be an atom.");
    using type = concat_lists_t<list<FirstElement>, typename add_to_first_atom<list<RestElements...>, Atom<T, Power>>::type>;
};
template <class List, class Atom>
using add_to_first_atom_t = typename add_to_first_atom<List, Atom>::type;
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
template <class lhsList, class rhsList>
struct multiply_lists_impl
{
    static_assert(is_list_v<lhsList> && is_list_v<rhsList>, "lhs and rhs of multiply_lists need to be lists.");
    using type = void;
};
template <class lhsList>
struct multiply_lists_impl<lhsList, list<>>
{
    static_assert(is_list_v<lhsList>, "lhs and rhs of multiply_lists need to be lists.");
    using type = lhsList;
};
template <class lhsList, class rhsElement>
struct multiply_lists_impl<lhsList, list<rhsElement>>
{
    static_assert(is_list_v<lhsList>, "lhs and rhs of multiply_lists need to be lists.");
    using type = add_to_first_atom_t<lhsList, rhsElement>;
};
template <class lhsList, class rhsFirstElement, class... rhsRestElements>
struct multiply_lists_impl<lhsList, list<rhsFirstElement, rhsRestElements...>>
{
    static_assert(is_list_v<lhsList>, "lhs and rhs of multiply_lists need to be lists.");
    using type = typename multiply_lists_impl<add_to_first_atom_t<lhsList, rhsFirstElement>, list<rhsRestElements...>>::type;
};
template <class lhsList, class rhsList>
struct multiply_lists
{
    static_assert(is_list_v<lhsList> && is_list_v<rhsList>, "lhs and rhs of multiply_lists need to be lists.");
    using type = drop_zero_atoms_t<typename multiply_lists_impl<lhsList, rhsList>::type>;
};
template <class lhsList, class rhsList>
using multiply_lists_t = typename multiply_lists<lhsList, rhsList>::type;
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
template <class List, class Atom>
struct subtract_from_first_atom
{
    static_assert(is_list_v<List>, "the lhs of subtract_from_first_atom needs to be a list.");
    static_assert(is_atom_v<Atom>, "the rhs of subtract_from_first_atom needs to be an atom.");
    using type = void;
};
template <template <class, class> class Atom, class T, class Power>
struct subtract_from_first_atom<list<>, Atom<T, Power>>
{
    static_assert(is_atom_v<Atom<T, Power>>, "the rhs of subtract_from_first_atom needs to be an atom.");
    using type = list<atom<T, std::ratio_subtract<std::ratio<0>, Power>>>;
};
template <template <class, class> class lhsAtom, template <class, class> class rhsAtom, class T, class lhsPower, class rhsPower, class... RestElements>
struct subtract_from_first_atom<list<lhsAtom<T, lhsPower>, RestElements...>, rhsAtom<T, rhsPower>>
{
    static_assert(is_atom_v<rhsAtom<T, rhsPower>>, "the rhs of subtract_from_first_atom needs to be an atom.");
    using type = list<lhsAtom<T, std::ratio_subtract<lhsPower, rhsPower>>, RestElements...>;
};
template <class FirstElement, class... RestElements, template <class, class> class Atom, class T, class Power>
struct subtract_from_first_atom<list<FirstElement, RestElements...>, Atom<T, Power>>
{
    static_assert(is_atom_v<Atom<T, Power>>, "the rhs of subtract_from_first_atom needs to be an atom.");
    using type = concat_lists_t<list<FirstElement>, typename subtract_from_first_atom<list<RestElements...>, Atom<T, Power>>::type>;
};
template <class List, class Atom>
using subtract_from_first_atom_t = typename subtract_from_first_atom<List, Atom>::type;
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
template <class lhsList, class rhsList>
struct divide_lists_impl
{
    static_assert(is_list_v<lhsList> && is_list_v<rhsList>, "lhs and rhs of divide_lists need to be lists.");
    using type = void;
};
template <class lhsList>
struct divide_lists_impl<lhsList, list<>>
{
    static_assert(is_list_v<lhsList>, "lhs and rhs of divide_lists need to be lists.");
    using type = lhsList;
};
template <class lhsList, class rhsElement>
struct divide_lists_impl<lhsList, list<rhsElement>>
{
    static_assert(is_list_v<lhsList>, "lhs and rhs of divide_lists need to be lists.");
    using type = subtract_from_first_atom_t<lhsList, rhsElement>;
};
template <class lhsList, class rhsFirstElement, class... rhsRestElements>
struct divide_lists_impl<lhsList, list<rhsFirstElement, rhsRestElements...>>
{
    static_assert(is_list_v<lhsList>, "lhs and rhs of divide_lists need to be lists.");
    using type = typename divide_lists_impl<subtract_from_first_atom_t<lhsList, rhsFirstElement>, list<rhsRestElements...>>::type;
};
template <class lhsList, class rhsList>
struct divide_lists
{
    static_assert(is_list_v<lhsList> && is_list_v<rhsList>, "lhs and rhs of divide_lists need to be lists.");
    using type = drop_zero_atoms_t<typename divide_lists_impl<lhsList, rhsList>::type>;
};
template <class lhsList, class rhsList>
using divide_lists_t = typename divide_lists<lhsList, rhsList>::type;
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

    static_assert(std::is_same_v<divide_lists_t<list<>, list<atom<std::ratio<3>>>>, list<atom<std::ratio<3>, std::ratio<-1>>>>, "");
    static_assert(std::is_same_v<divide_lists_t<list<atom<std::ratio<3>>>, list<>>, list<atom<std::ratio<3>>>>, "");
    static_assert(std::is_same_v<divide_lists_t<list<atom<std::ratio<3>>>, list<atom<std::ratio<7>>>>, list<atom<std::ratio<3>>, atom<std::ratio<7>, std::ratio<-1>>>>, "");
    static_assert(std::is_same_v<divide_lists_t<list<atom<std::ratio<3>>>, list<atom<std::ratio<3>>>>, list<>>, "");
    static_assert(std::is_same_v<divide_lists_t<list<atom<std::ratio<3>>>, list<atom<std::ratio<3>>, atom<std::ratio<7>>>>, list<atom<std::ratio<7>, std::ratio<-1>>>>, "");
    static_assert(std::is_same_v<divide_lists_t<list<atom<std::ratio<3>>>, list<atom<std::ratio<7>>, atom<std::ratio<3>>>>, list<atom<std::ratio<7>, std::ratio<-1>>>>, "");
    static_assert(std::is_same_v<divide_lists_t<list<atom<std::ratio<3>>, atom<std::ratio<7>>>, list<atom<std::ratio<3>>>>, list<atom<std::ratio<7>>>>, "");

    static_assert(std::is_same_v<divide_lists_t<list<>, list<atom<std::ratio<3>, std::ratio<2>>>>, list<atom<std::ratio<3>, std::ratio<-2>>>>, "");
    static_assert(std::is_same_v<divide_lists_t<list<atom<std::ratio<3>>>, list<atom<std::ratio<3>, std::ratio<2>>>>, list<atom<std::ratio<3>, std::ratio<-1>>>>, "");
}
#pragma endregion
#pragma region power
//The pow_list function adds a given power to every atom in a
//list.
template <class List, class Power>
struct pow_list
{
    static_assert(is_list_v<List>, "the lhs of pow_list needs to be a list.");
    static_assert(is_ratio_v<Power>, "the rhs of pow_list needs to be a std::ratio.");
    using type = void;
};
template <class Power>
struct pow_list<list<>, Power>
{
    static_assert(is_ratio_v<Power>, "the rhs of pow_list needs to be a std::ratio.");
    using type = list<>;
};
template <template <class, class> class Atom, class T, class AtomPower, class... RestElements, class Power>
struct pow_list<list<Atom<T, AtomPower>, RestElements...>, Power>
{
    static_assert(is_ratio_v<Power>, "the rhs of pow_list needs to be a std::ratio.");
    using type = concat_lists_t<list<Atom<T, std::ratio_multiply<AtomPower, Power>>>, typename pow_list<list<RestElements...>, Power>::type>;
};
template <class List, class Power>
using pow_list_t = typename pow_list<List, Power>::type;
//TODO: - Put this into a unit test folder.
auto test_pow_list()
{
    static_assert(std::is_same_v<pow_list_t<list<>, std::ratio<2>>, list<>>, "");
    static_assert(std::is_same_v<pow_list_t<list<>, std::ratio<-2>>, list<>>, "");
    static_assert(std::is_same_v<pow_list_t<list<>, std::ratio<1, 3>>, list<>>, "");
    static_assert(std::is_same_v<pow_list_t<list<>, std::ratio<-1, 3>>, list<>>, "");

    static_assert(std::is_same_v<pow_list_t<list<atom<std::ratio<5>>>, std::ratio<1>>, list<atom<std::ratio<5>>>>, "");
    static_assert(std::is_same_v<pow_list_t<list<atom<std::ratio<5>>>, std::ratio<2>>, list<atom<std::ratio<5>, std::ratio<2>>>>, "");
    static_assert(std::is_same_v<pow_list_t<list<atom<std::ratio<5>>>, std::ratio<-2>>, list<atom<std::ratio<5>, std::ratio<-2>>>>, "");
    static_assert(std::is_same_v<pow_list_t<list<atom<std::ratio<5>>>, std::ratio<1, 3>>, list<atom<std::ratio<5>, std::ratio<1, 3>>>>, "");
    static_assert(std::is_same_v<pow_list_t<list<atom<std::ratio<5>>>, std::ratio<-1, 3>>, list<atom<std::ratio<5>, std::ratio<-1, 3>>>>, "");

    static_assert(std::is_same_v<pow_list_t<list<atom<std::ratio<5>>, atom<std::ratio<3>>>, std::ratio<1>>, list<atom<std::ratio<5>>, atom<std::ratio<3>>>>, "");
    static_assert(std::is_same_v<pow_list_t<list<atom<std::ratio<5>>, atom<std::ratio<3>>>, std::ratio<2>>, list<atom<std::ratio<5>, std::ratio<2>>, atom<std::ratio<3>, std::ratio<2>>>>, "");
    static_assert(std::is_same_v<pow_list_t<list<atom<std::ratio<5>>, atom<std::ratio<3>>>, std::ratio<-2>>, list<atom<std::ratio<5>, std::ratio<-2>>, atom<std::ratio<3>, std::ratio<-2>>>>, "");
    static_assert(std::is_same_v<pow_list_t<list<atom<std::ratio<5>>, atom<std::ratio<3>>>, std::ratio<1, 3>>, list<atom<std::ratio<5>, std::ratio<1, 3>>, atom<std::ratio<3>, std::ratio<1, 3>>>>, "");
    static_assert(std::is_same_v<pow_list_t<list<atom<std::ratio<5>>, atom<std::ratio<3>>>, std::ratio<-1, 3>>, list<atom<std::ratio<5>, std::ratio<-1, 3>>, atom<std::ratio<3>, std::ratio<-1, 3>>>>, "");
}
#pragma endregion
#pragma endregion
#pragma region list generators
//The make_list function generates a list of atoms from an integer_sequence.
template <class Sequence>
struct make_list_impl
{
    static_assert(is_integer_sequence_v<Sequence>, "the argument of make_list needs to be a std::integer_sequence.");
    using type = void;
};
template <class ValueType, ValueType... Integers>
struct make_list_impl<std::integer_sequence<ValueType, Integers...>>
{
    using type = list<atom<std::ratio<Integers>>...>;
};
template <class Sequence>
using make_list = typename make_list_impl<Sequence>::type;
//The make_factorial_list function generates a list by
//factorizing a given number.
template <intmax_t Value>
struct make_factorial_list_impl
{
    using type = multiply_lists_t<list<>, make_list<factorization_t<intmax_t, Value>>>;
};
template <intmax_t Value>
using make_factorial_list = typename make_factorial_list_impl<Value>::type;
//The make_fraction_list function generates a list by
//factorizing a given numerator and denominater.
template <intmax_t num = 1, intmax_t den = 1>
struct make_fraction_list_impl
{
    using type = divide_lists_t<make_factorial_list<num>, make_factorial_list<den>>;
};
template <intmax_t num = 1, intmax_t den = 1>
using make_fraction_list = typename make_fraction_list_impl<num, den>::type;
//TODO: - Put this into a unit test folder.
auto test_make_list()
{
    static_assert(std::is_same_v<make_list<factorization_t<int, 9>>, list<atom<std::ratio<3>>, atom<std::ratio<3>>>>, "");
    static_assert(std::is_same_v<multiply_lists_t<list<>, make_list<factorization_t<int, 9>>>, list<atom<std::ratio<3>, std::ratio<2>>>>, "");
    static_assert(std::is_same_v<make_factorial_list<8>, list<atom<std::ratio<2>, std::ratio<3>>>>, "");
    static_assert(std::is_same_v<make_fraction_list<1, 8>, list<atom<std::ratio<2>, std::ratio<-3>>>>, "");
    static_assert(std::is_same_v<make_fraction_list<4, 8>, list<atom<std::ratio<2>, std::ratio<-1>>>>, "");
    static_assert(std::is_same_v<make_fraction_list<5, 3>, list<atom<std::ratio<5>>, atom<std::ratio<3>, std::ratio<-1>>>>, "");
}
//The make_power_list function generates a list which
//represents 10^Power.
template <bool Positive, intmax_t Power>
struct make_power_list_impl
{
    using type = list<>;
};
template <>
struct make_power_list_impl<true, 0>
{
    using type = make_fraction_list<1>;
};
template <>
struct make_power_list_impl<false, 0>
{
    using type = make_fraction_list<1>;
};
template <intmax_t Power>
struct make_power_list_impl<true, Power>
{
    using type = multiply_lists_t<make_fraction_list<10>, typename make_power_list_impl<true, Power - 1>::type>;
};
template <intmax_t Power>
struct make_power_list_impl<false, Power>
{
    using type = multiply_lists_t<make_fraction_list<1, 10>, typename make_power_list_impl<false, Power + 1>::type>;
};
template <intmax_t Power>
using make_power_list = typename make_power_list_impl<(Power >= 0), Power>::type;
//TODO: - Put this into a unit test folder.
auto test_make_power_list()
{
    static_assert(std::is_same_v<make_power_list<2>, make_fraction_list<100>>, "");
    static_assert(std::is_same_v<make_power_list<0>, make_fraction_list<1>>, "");
    static_assert(std::is_same_v<make_power_list<-2>, make_fraction_list<1, 100>>, "");
    static_assert(std::is_same_v<make_power_list<1>, make_fraction_list<10>>, "");
}
#pragma endregion
#pragma region expansion
//The expand_list function calculates the factor given by expanding
//and multiplying all atoms in the list.
template <class ValueType, class List>
struct multiply_elements_impl
{
    static_assert(is_list_v<List>, "the rhs of multiply_elements needs to be a list list.");
    static constexpr auto value = ValueType{1};
};
template <class ValueType, class... Elements>
struct multiply_elements_impl<ValueType, list<Elements...>>
{
    static_assert(all_true_v<!is_root_v<Elements>...>, "multiply_elements cannot handle roots in the atoms at the moment. use runtime_multiply_elements instead.");
    static constexpr auto value = product(std::initializer_list<ValueType>{expand_atom_v<ValueType, Elements>...});
};
template <class ValueType, class List>
constexpr ValueType multiply_elements = multiply_elements_impl<ValueType, List>::value;
//TODO: - Put this into a unit test folder.
auto test_multiply_elements_list()
{
    static_assert(multiply_elements<intmax_t, make_fraction_list<8>> == 8, "");
    static_assert(multiply_elements<double, make_fraction_list<1, 8>> == 1. / 8., "");
}
//The runtime_multiply_elements function calculates the factor given by expan-
//ding and multiplying all atoms in the list. However, this is done at
//runtime rather than compile time. The reason being, that std::pow is
//not constexpr. Still, the whole function is marked constexpr to be for-
//ward compatible with a constexpr std::pow implementation.
template <class ValueType, class... Atoms>
constexpr auto runtime_multiply_elements(list<Atoms...>)
{
    return product(std::initializer_list<ValueType>{runtime_expand_atom<ValueType, Atoms>()...});
};
#pragma endregion
} // namespace impl
//Pull the list type and its generators into the benri namespace,
//because we need it for constructing units.
using impl::list;
using impl::make_fraction_list;
using impl::make_power_list;
} // namespace benri