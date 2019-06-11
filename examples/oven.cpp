#include <benri/si/temperature.h>
#include <iostream>

void set_oven(benri::quantity_point<benri::si::temperature::celsius_t> temperature)
{
    std::wcout << "Oven was set to " << temperature.value() << L"°C.\n";
};
auto temperature_update()
{
    using namespace benri::si::temperature;

    //Increase temperature by 10°C.
    return 10_celsius;
}
auto new_temperature()
{
    using namespace benri::si::temperature;

    //Set temperature to 210°C.
    return 210_degree_celsius;
}
int main()
{
    using namespace benri::si::temperature;

    //we can do the following:
    set_oven(200_degree_celsius); //Sets the temperature to 200°C.
    //set_oven(250_celsius);        //Will not compile because we have no zero point.
    set_oven(zero_point(celsius) + 250_celsius); //Works fine.

    //we can be safe from the following:
    //set_oven(temperature_update()); //Will not compile. (Otherwise the oven would now be at 10°C.)
    set_oven(new_temperature());    //Will compile, and set the temperature to 210°C.
}