#include <benri/si/temperature.h>

//Given the following function for setting the temperature of a baking oven...
void set_oven(benri::quantity_point<benri::si::temperature::celsius_t> temperature)
{
    //Dummy function.
}

auto test_1()
{
    using namespace benri::si::temperature;

    //...we can do the following:
    set_oven(200_degree_celsius); //Sets the temperature to 200°C.
    // set_oven(200_celsius);        //Will not compile.
}

//Given the following function...
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

auto test_2()
{
    using namespace benri::si::temperature;

    //...we can be safe from the following:
    // set_oven(temperature_update()); //Will not compile. (Otherwise the oven would now be at 10°C.)
    set_oven(new_temperature());    //Will compile, and set the temperature to 210°C.
}

int main()
{
    //Call the test functions.
    test_1();
    test_2();
}