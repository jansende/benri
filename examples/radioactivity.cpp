#include <benri/si/si.h>
#include <iostream>

enum class radiation_type
{
    alpha,
    beta,
    protons,
};

auto weighting_factor(radiation_type radiation)
{
    using namespace benri::si;

    switch (radiation)
    {
    case radiation_type::alpha:
        return 1_sievert_per_gray;
    case radiation_type::beta:
        return 20_sievert_per_gray;
    case radiation_type::protons:
        return 2_sievert_per_gray;
    }
}

template <class T>
auto equivalent_dose(benri::quantity<benri::si::gray_t, T> absorbed_dose, radiation_type radiation)
{
    return absorbed_dose * benri::value_type_cast<T>(weighting_factor(radiation));
}

int main()
{
    using namespace benri::si;

    //calculate dose
    auto dose = equivalent_dose(10_gray, radiation_type::alpha);
    std::wcout
        << "You received " << dose.value() << "Sv of alpha radiation.\n"
        << ((dose > 20_sievert) ? "You will die." : "You are probably fine.") << '\n'
        << std::flush;
}