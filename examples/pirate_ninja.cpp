#include <benri/si/macros.h>
#include <benri/si/si.h>
#include <iostream>

// Add a pirate (pir) and a ninja (nin) base dimension.
struct pir
{
    // The name values need to be provided because benri internally sorts the
    // dimensions by their name.
    static constexpr benri::meta::static_string name = "pir";
};
struct nin
{
    static constexpr benri::meta::static_string name = "nin";
};
// Dimensions can be generated using macros.
using benri::dimension::helper;
// Singular dimensions.
using pirate_t = benri::make_dimension<helper<pir>>;
using ninja_t  = benri::make_dimension<helper<nin>>;
// Compound dimensions.
using woodleg_t      = benri::make_dimension<helper<pir>,
                                        helper<benri::dimension::L>>; // pirate*length
using pirate_ninja_t = benri::make_dimension<helper<pir>,
                                             helper<nin>>; // pirate*ninja

// Units can be generated using macros as well.
implement_unit(jack_sparrow, pirate_t, benri::prefix::one_t);
implement_unit(hanzo, ninja_t, benri::prefix::one_t);
implement_unit(blackbeard, woodleg_t, benri::prefix::one_t);

// Constants can be generated using the make_constant helper, which takes the unit and the
// value of the constant (as a type list).
constexpr auto kaido =
    benri::make_constant<typename decltype(jack_sparrow * hanzo)::unit_type,
                         benri::prefix::hecto_t>;

int main()
{
    using namespace benri::si;

    auto temp = double{};
    std::cout << "Your pirate strength in Jack Sparrow: ";
    std::cin >> temp;
    auto pirate = temp * jack_sparrow;

    std::cout << "Your ninja strength in Hanzo: ";
    std::cin >> temp;
    auto ninja = temp * hanzo;

    std::cout << "Your woodleg length in metre: ";
    std::cin >> temp;
    auto woodleg = temp * metre;

    // Calculate strength from woodleg.
    auto pirate_ninja = 2_hanzo * 3_blackbeard / woodleg;

    auto strength = pirate * ninja + pirate_ninja;
    std::cout << "You are worth: " << (strength / kaido).value() << "Kaido.";
}