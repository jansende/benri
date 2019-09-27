#include <benri/si/imperial.h>
#include <benri/si/si.h>
#include <iostream>

template <class Distance, class Time>
constexpr auto avg_speed(const Distance& distance, const Time& duration) -> std::enable_if_t<
    benri::type::detect_if<
        Distance, benri::type::has_dimension,
        benri::dimension::
            length_t> && benri::type::detect_if<Time, benri::type::has_dimension, benri::dimension::time_t>,
    decltype(distance / duration)>
{
    return distance / duration;
}

int main()
{
    using namespace benri::si;
    using namespace benri::si::imperial;

    constexpr auto kmph = avg_speed(220_kilo * metre, 2_hour);
    std::cout << kmph.value() << " kmp/h\n";

    constexpr auto mph = avg_speed(220_mile, 2_hour);
    std::cout << mph.value() << " mph\n";
}