#include <benri/si/si.h>
#include <benri/cmath.h>
#include <iostream>

int main()
{
    using namespace benri::si;
    using namespace benri::casts;

    auto integer_value = benri::quantity<one_t, int>{4};
    //does not compile
    // std::cout << sin(integer_value).value() << '\n' << std::flush;
    //compiles
    std::cout << sin(value_type_cast<double>(integer_value)).value() << '\n' << std::flush;
}