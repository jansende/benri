#include <iostream>
#define BENRI_PRECISION float //set the standard value_type to float
#include <benri/si/si.h>

int main()
{
    using namespace benri::si;
    // using namespace benri::si::astronomic;
    using namespace benri::casts;

    auto constant_relation = float{};
    auto symbol_relation = float{};
    //constant variant
    {
        auto impulse_a = constant::planck_constant / 7e5_metre;
        auto impulse_b = constant::planck_constant / 3e2_metre;

        constant_relation = static_cast<float>((impulse_b - impulse_a) / impulse_b);
        std::cout << "constant: " << constant_relation << "\n";
    }

    //symbol variant
    {
        auto impulse_a = symbol::planck_constant / 7e5_metre;
        auto impulse_b = symbol::planck_constant / 3e2_metre;

        symbol_relation = static_cast<float>((impulse_b - impulse_a) / impulse_b);
        std::cout << "constant: " << symbol_relation << "\n";
    }
    if (constant_relation == symbol_relation)
        std::cout << "Both results are the same.";
    else
        std::cout << "Both results are the different.";
}