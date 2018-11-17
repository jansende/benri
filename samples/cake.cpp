#include <benri/si/si.h>
#include <benri/cmath.h>
#include <iostream>

int main()
{
    using namespace benri::si;

    //set size of the cake
    auto height = 4_centi * metre;
    auto diameter = 30_centi * metre;

    //calculate volume
    auto volume = height * constant::pi * square(diameter / 2.0);

    //set density of the batter
    auto density = 1_gram / cubic(centi * metre);

    //calculate the mass of the cake
    auto mass = density * volume;

    //print the recipe
    std::cout
        << "  vanille cake  \n"
        << "----------------\n"
        << benri::ceil(mass * 0.028).value()  << " gram butter\n"
        << benri::ceil(mass * 0.099).value()  << " gram sugar\n"
        << benri::ceil(mass * 0.0635).value() << " gram flour\n"
        << benri::ceil(mass / 2828.0).value() << " pack of backing soda\n"
        << benri::floor(mass * 0.002).value() << " eggs\n"
        << benri::ceil(mass * 0.1765).value()  << " gram quark cream\n"
        << benri::ceil(mass * 0.0705).value() << " gram oil\n"
        << benri::ceil(mass / 2828.0).value() << " pack of vanille aroma\n"
        << benri::ceil(mass / 2828.0).value() << "/2 litre milk\n"
        << std::flush;
}