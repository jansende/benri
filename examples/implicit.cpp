#include <benri/si/si.h>
#include <benri/cmath.h>
#include <iostream>

int main() {
    using namespace benri::si;
    auto integer_value = benri::quantity<one_t, int>{4};
    //does not compile
    // sin(integer_value);
    //compiles
    std::cout << sin<true>(integer_value).value() << '\n' << std::flush;
}