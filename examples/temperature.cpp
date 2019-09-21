#include <benri/si/temperature.h>
#include <iostream>

//sensor functions
inline auto get_outdoor_temperature()
{
    using namespace benri::si::temperature;
    //return fake data
    return 10_degree_celsius;
}
inline auto get_indoor_temperature()
{
    using namespace benri::si::temperature;
    //return fake data
    return 18_degree_celsius;
}

int main()
{
    using namespace benri::si;
    using namespace benri::si::temperature;
    using namespace benri::casts;

    //get sensor data
    auto indoor = get_indoor_temperature();
    auto outdoor = get_outdoor_temperature();

    //calculate difference
    auto difference = outdoor - indoor;

    //print data in celsius
    std::wcout
        << "-------------------------\n"
        << "outside: " << outdoor.value()    << L"°C\n"
        << "inside:  " << indoor.value()     << L"°C\n"
        << "delta:   " << difference.value() <<   "C\n"
        << std::flush;
    //print data in kelvin
    std::wcout
        << "-------------------------\n"
        << "outside: " << simple_cast<degree_kelvin_t>(outdoor).value() << L"°K\n"
        << "inside:  " << simple_cast<degree_kelvin_t>(indoor).value()  << L"°K\n"
        << "delta:   " << simple_cast<kelvin_t>(difference).value()     <<   "K\n"
        << std::flush;
    //print data in fahrenheit
    std::wcout
        << "-------------------------\n"
        << "outside: " << simple_cast<degree_fahrenheit_t>(outdoor).value() << L"°F\n"
        << "inside:  " << simple_cast<degree_fahrenheit_t>(indoor).value()  << L"°F\n"
        << "delta:   " << simple_cast<fahrenheit_t>(difference).value()     <<   "F\n"
        << std::flush;
}