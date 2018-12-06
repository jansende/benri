#include <iostream>
#include <string>
#include <variant>
#include <benri/si/base.h>

//Define a variant holding the quantities.
using si_unit = std::variant<
    benri::quantity<benri::si::kilogram_t>,
    benri::quantity<benri::si::metre_t>,
    benri::quantity<benri::si::second_t>>;

//Define a runtime function.
auto parse(const std::string &input)
{
    if (input == "kilogram")
        return si_unit(benri::quantity<benri::si::kilogram_t>{1});
    else if (input == "metre")
        return si_unit(benri::quantity<benri::si::metre_t>{1});
    else if (input == "second")
        return si_unit(benri::quantity<benri::si::second_t>{1});
    else
        throw;
}
//Define another runtime function.
auto print(si_unit value)
{
    std::cout << "You entered: ";
    std::visit([](auto &&arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, benri::quantity<benri::si::kilogram_t>>)
            std::cout << "kilogram\n" << std::flush;
        else if constexpr (std::is_same_v<T, benri::quantity<benri::si::metre_t>>)
            std::cout << "metre\n" << std::flush;
        else if constexpr (std::is_same_v<T, benri::quantity<benri::si::second_t>>)
            std::cout << "second\n" << std::flush;
        else
            throw;
    },
               value);
}

int main()
{
    //Get runtime quantity from user input.
    std::string input;
    std::cin >> input;

    auto value = parse(input);

    //Print unit of the quantity.
    print(value);
}