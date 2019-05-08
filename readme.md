# Introduction
*benri* is a c++ library for working with physical quantities. Quantities are the combination of a value with a unit. For example: the quantity `1km` consists of the value `1` and the unit `kilometre`. The library allows the definition of arbitrary units, and provides a container type for quantities. The container handles unit conversions and dimensional checking. Furthermore, a replacement for most of the `<cmath>` functions is provided, to easily updated existing code.

# Table of Contents

- [Introduction](#introduction)
- [Quickstart](#quickstart)
    + [Install without using cmake](#install-without-using-cmake)
    + [Install using cmake](#install-using-cmake)
    + [TL;DR / Using *benri*](#tldr--using-benri)
- [Philosophy](#philosophy)
- [Using *benri*](#using-benri)
    + [Library structure](#library-structure)
    + [`<cmath>` functions](#cmath-functions)
    + [Unit conversions and casts](#unit-conversions-and-casts)
    + [Template functions](#template-functions)
    + [Learn more](#learn-more)
    + [Known bugs](#known-bugs)
- [Competition](#competition)
    + [Quick comparison](#quick-comparison)
    + [Features](#features)

# Quickstart
In the following, instructions for installing and using *benri* are provided. If you want more information, please read the later sections on specific topics, have a look at the [examples](./examples/) folder, or have a look at the api list in [tables.md](table.md).

## Install without using cmake
The easiest way to get *benri*, is to clone the git repository, add the `include/` directory to your project, and use the library by adding the following includes to your project:
```c++
#include <benri/si/si.h>
#include <benri/cmath.h>
```
In order to test if you set up *benri* correctly, try the following example for a cake recipe.
```c++
#include <benri/si/si.h>
#include <benri/cmath.h>
#include <iostream>

int main()
{
    using namespace benri::si;

    //Set size of the cake.
    auto height = 4_centi * metre;
    auto diameter = 30_centi * metre;

    //Calculate the volume.
    auto volume = height * constant::pi * square(diameter / 2.0);

    //Set the density of the batter.
    auto density = 1_gram / cubic(centi * metre);

    //Calculate the mass of the cake.
    auto mass = density * volume;

    //Print the recipe.
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
```
If it works, you are good to go!

## Install using cmake
If you are using cmake, you can use *benri* by cloning the repository, and adding the `add_subdirectory` and `target_link` library command to your `CMakeLists.txt`. A simple project file might look like this:
```cmake
cmake_minimum_required(VERSION 3.1)

#Define the project.
project(hello_benri)
add_executable(hello_benri main.cpp)

#Add the benri repository.
add_subdirectory(benri)
#Add the library to the project.
target_link_libraries(hello_benri PRIVATE benri)
```

## TL;DR / Using *benri*
The library provides several literal types, which can be used in the following way:
```c++
//Add namespace containing the literals.
using namespace benri::si;
//Compose quantities using a prefix literal and a unit constant.
auto capacity = 10_micro * farad;
//The literal can be omitted if the prefix is one.
auto resistance_a = 10_one * ohm;
auto resistance_b = 10_ohm;
//The kilogram is the only exception to the composition rule.
auto mass_a = 5_kilogram;
auto mass_b = 5_kilo * gram; //both are fine
```

In addition, a replacement for most `<cmath>` functions is provided:
<!-- TODO: Write example code. -->
```c++
talk about pow
```

Moreover, *benri* provides a range of helper functions:
<!-- TODO: Write example code. -->
```c++
show casting
talk about square and cubic
```

# Philosophy
The *benri* library tries to help writing correct and efficient c++ programs using the following principles:

- Be correct.
- Be explicit.
- Be sane.
- Be as efficient as possible.

In the following, these principles are explained in detail.

#### Be correct. (No stupid semantic errors.)
*benri* aims to help you write correct c++ programs on the first try. It especially wants to protect you from stupid semantic errors. If your program compiles, it should be correct. An infamous example of this kind of error is the [Mars Climate Orbiter](https://en.wikipedia.org/wiki/Mars_Climate_Orbiter). The probe crashed into Mars, because one of the sensors was giving data in `pound-force seconds` instead of `newton seconds`. However this discrepancy was not checked for, leading to faulty steering commands and finally to the destruction of the probe.

*benri* checks for these kind of errors and will fail to compile. For example:
```c++
void steer_mars_climate_orbiter(quantity<newton_second_t> force);

steer_mars_climate_orbiter(3_pound_force * second); //Will not compile.
```

However, *benri* cannot prevent you from doing all stupid things:
```c++
double get_thrust_in_pound_force_second();

auto get_thrust_force()
{
    return quantity<newton_second_t>(get_thrust_in_pound_force_second()); //Do not ever do that!
}
```

#### Be explicit. (No overflowing/faulty conversions.)
The libraries forces users to be as explicit with their programming as possible. The reason being that the implicit conversions are very error prone and can lead to unintended consequences. Therefore nearly all conversions between units and values need to be made explicit. For example:

```c++
//Dummy function.
auto test(quantity<metre_t>);

test(20_metre);                                                        //Works fine.
test(2000_centi * metre);                                              //Does not compile, because converting cm to m might cause an overflow in the value of the quantity.
test(simple_cast<decltype(centi * metre)>(2000_centi * metre)); //Works fine. The conversion is now explicitely visible.
```

This rule applies to math as well. For addition/subtraction implicit conversions are not allowed. Multiplication/division is fine, because we can save the value in a new type. For example:
```c++
auto d = 2_metre + 4_metre;            //Works fine.
auto e = 2_metre + 400_centi * metre;  //Does not compile, because a conversion is necessary.
auto f = 2_metre / 1_second;           //Works fine. Result is in m/s.
auto g = 200_centi * metre / 1_second; //Works fine. Result is in cm/s.
```

Furthermore, implicit conversions for comparisons are not allowed:
```c++
if (f < 3_metre / second)         //Works fine.
    ...
if (f < 3_centi * metre / second) //Does not compile, because a conversion is necessary.
    ...
if (f < g)                        //Does not compile, because a conversion is necessary.
    ...
if (f < simple_cast<decltype(f)>(3_centi * metre / second)) //Works fine.
    ...
if (f < simple_cast<decltype(f)>(g))                        //Works fine.
    ...
```

#### Be sane. (Do not do weird things.)
The *benri* library tries to behave in a resonable way and as one expects. The goal is to always behave in a non-surprising way. Thus, overloads for commonly used functions and operators, as well as for dimensionless units are implemented. In addition, unusual usage is disabled where ever possible. For example:
```c++
auto a = 1_metre;
a += 10_centi * metre; //Does not compile, because a conversion is necessary.
a += 10.0;             //Does not compile, because a no quantity is used.

auto b = 1_one;
a += 10_one;                       //Works fine.
a += 10_metre / 5_metre;           //Works fine.
a += 10_metre / 500_centi * metre; //Does not compile, because a conversion is necessary. (The result of the division is in %.)
a += 10.0;                         //Works fine.
```

#### Be as efficient as possible. (`constexpr` all the things.)
All of *benris* library types are defined using `constexpr` constructs. This should allow the compiler to completely eliminate the library overhead of *benri* at compile time. Thus, the assembly of code written with *benri* and of code written with standard c++ types should be exactly the same. For example:
```c++
constexpr auto calculate_area(quantity<metre_t> length, quantity<metre_t> width)
{
    return length * width; //You get proper unit checking in the rest of the code.
}
constexpr auto calculate_area(double length, double width)
{
    return length * width; //No one prevents you to put the value in kilometre here.
}
```

In addition to the types, all of *benris* library functions are defined using `constexpr` as well. This should allow the compile time calculation of these functions. In reality however, the support is currently limited, because only some of the c++ standard library functions used in *benri* support compile time evaluation. For example:

```c++
constexpr auto delta = benri::abs(5_second - 10_second); //Evaluates to delta = 5_second at compile time.
constexpr auto angle = benri::asin(4_metre / 1_metre);   //Does not compile, because compilers do not currently support compile time asin.
```

Moreover *benri* tries to reduce the amount of calculations done at runtime by shifting the work to the compile step. For example, the following operations can be evaluated at compile time:
```c++
constexpr auto energy = simple_cast<joule_t>(50_giga * joule); //The simple_cast function can be evaluated at compile time.
constexpr auto energy = 50000_joule;                           //These two definition therefore are EXACTLY the same.

constexpr auto energy = 4_joule + 5_joule; //Works fine.
constexpr auto ratio  = 4_joule / 5_joule; //Works fine.
```

# Using *benri*
<!-- TODO: Expand on the usage of benri. -->
## Library structure
## `<cmath>` functions
## Unit conversions and casts
## Template functions
## Learn more
## Known bugs
<!-- TODO: Can this be done better? -->
 - The unit pascal might conflict with the `pascal` macro set in some windows headers.

# Competition
The *benri* library is not the only library for working with physical quantities. The most notable competitors are [boost](https://www.boost.org/doc/libs/1_68_0/doc/html/boost_units.html), [nholthaus/units](https://github.com/nholthaus/units), [PhysUnits-CT](https://github.com/martinmoene/PhysUnits-CT-Cpp11), and [bigdavedev/units](https://github.com/bigdavedev/units). These libraries provide similar facilities to *benri*, but differ in some important areas. It is therefore recommended to check what you need in your project and select accordingly.

## Quick comparison
The following table gives a quick overview on the most important features provided by the different quantity libraries:

<!-- TODO: Extend table. -->
| Features                         | [benri](https://github.com/jansende/benri) | [boost](https://www.boost.org/doc/libs/1_68_0/doc/html/boost_units.html) | [nholthaus/units](https://github.com/nholthaus/units) | [PhysUnits-CT](https://github.com/martinmoene/PhysUnits-CT-Cpp11) | [bigdavedev/units](https://github.com/bigdavedev/units) |
|:---------------------------------|:-------------------------------------------|-------------------------------------------------------------------------:|:-----------------------------------------------------:|:-----------------------------------------------------------------:|:-------------------------------------------------------:|
| SI units                         | :heavy_check_mark:                         | :heavy_check_mark:                                                       | :heavy_check_mark:                                    |                                                                   |                                                         |
| CGS units                        | :heavy_check_mark:                         | :heavy_check_mark:                                                       | :x:                                                   |                                                                   |                                                         |
| imperial units                   | :heavy_check_mark:                         | :heavy_check_mark:                                                       | :heavy_check_mark:                                    |                                                                   |                                                         |
| astronomical units               | :heavy_check_mark:                         | :heavy_check_mark:                                                       | :x:                                                   |                                                                   |                                                         |
| Gray/Sievert support¹            | :heavy_check_mark:                         | :x:                                                                      | :x:                                                   |                                                                   |                                                         |
| temperature support²             | :heavy_check_mark:                         | :heavy_check_mark:                                                       | :heavy_check_mark:                                    |                                                                   |                                                         |
| physical/mathematical constants³ | :heavy_check_mark:                         | :heavy_check_mark:                                                       | :heavy_check_mark:⁸                                   |                                                                   |                                                         |
| affine quantities⁴               | :heavy_check_mark:                         | :heavy_check_mark:                                                       | :x:                                                   |                                                                   |                                                         |
| user defined dimensions          | :heavy_check_mark:                         | :heavy_check_mark:                                                       | :x:                                                   |                                                                   |                                                         |
| user defined prefixes            | :heavy_check_mark:                         | :heavy_check_mark:                                                       | :heavy_check_mark:                                    |                                                                   |                                                         |
| arbitrary prefix conversions⁵    | :heavy_check_mark:                         | :heavy_check_mark:                                                       | :x:                                                   |                                                                   |                                                         |
| symbolic computation⁶            | :heavy_check_mark:                         | :x:                                                                      | :x:                                                   |                                                                   |                                                         |
| `<cmath>`  functions             | :heavy_check_mark:                         | :heavy_check_mark:                                                       | :heavy_check_mark:                                    |                                                                   |                                                         |
| `<chrono>` interoperability      | :x:                                        | :x:                                                                      | :heavy_check_mark:                                    |                                                                   |                                                         |
| `<iostream>` functions           | :x:                                        | :heavy_check_mark:                                                       | :heavy_check_mark:                                    |                                                                   |                                                         |
| `<boost>` required               | :x:                                        | :heavy_check_mark:                                                       | :x:                                                   |                                                                   |                                                         |
| minimum c++ version              | `c++14`                                    | `c++98`                                                                  | `c++14`                                               | `c++11`                                                           | `c++14`                                                 |
| extensive documentation          | :x:⁷                                       | :heavy_check_mark:                                                       | :heavy_check_mark:                                    |                                                                   |                                                         |
| extensive unit tests             | :x:⁷                                       | :heavy_check_mark:                                                       | :heavy_check_mark:                                    |                                                                   |                                                         |

¹ The base units of Sievert and Gray are the same, but their meaning is different. Does the library make a distinction between them?

² Does the library provide different temperature scales and conversions between them?

³ Does the library provide physical and/or mathematical constants?

⁴ Does the library provide affine types? Meaning: Different types for vectors and points are provided?

⁵ Can the library handle arbitrary prefix conversions? For example: `1 megalightyear` to `femtometre`? (Depending on the implementation, the type handling the operation might overflow.)

⁶ Can the library do symbolic computations? For example, if we want the result of the calculation `2year × c` in lightyears, do we need to do a multiplication and division to get the result, or can the libray just remember to carry the `c`?

⁷ Improvements are planned.

⁸ [nholthaus](https://github.com/nholthaus/units) only supplies a very limited list of constants, without source.

## Features
In the following, the most important differences and features are explained in detail.

#### `<iostream>` functions
*benri* does not provide `<iostream>` functions, and it never will. The reason is, that implementing proper input and output of quantities is hard. One needs to develop a system for parsing and generating arbitrary unit strings. Yet, most users will not be satisfied with the provided functions, as every use case is different. The work is therefore left to you dear *benri* user. You best know what you want, and what units you are using. Thus, you can just write a input and a output function for your project without having to invent the general solution, which would be needed for *benri*.

For example, if your project only handles different times, you can write:
<!-- TODO: Write example code. -->
```c++
#include <benri/si/base.h>

template <class Unit, class ValueType>
auto print(benri::quantity<Unit, ValueType> value)
{
    std::cout << value.value() << "?";
}
template <class ValueType>
auto print(benri::quantity<benri::si::second_t, ValueType> value)
{
    std::cout << value.value() << "s";
}
template <class ValueType>
auto print(benri::quantity<benri::si::minute_t, ValueType> value)
{
    std::cout << value.value() << "min";
}
template <class ValueType>
auto print(benri::quantity<benri::si::hour_t, ValueType> value)
{
    std::cout << value.value() << "h";
}
```

#### User defined dimensions
*benri* allows its users to define new base dimensions and seemlessly use them together with the already existing ones:
```c++
#include <benri/impl/dimensions.h>

//We need to go into the benri namespace, otherwise the compiler complains.
namespace benri
{
//Dimensions are defined in the dim namespace.
namespace dim
{
//add a pirate (pir) dimension and a ninja (nin) dimension
struct pir;
struct nin;
} // namespace dim

//The following overload need to be provided, because benri internally sorts
//the dimensions by the value of this function.
//For the value all numbers equal or larger 100 can be used. Other values
//are reserved.
template <>
struct hash_impl<dim::pir>
{
    static constexpr float value = 100; 
};
template <>
struct hash_impl<dim::nin>
{
    static constexpr float value = 101;
};

//The dimensions can be registered in the benri namespace using macros.
//This has to be done inside the dim namespace.
namespace dim
{
create_and_register_dimension(pirate, helper<pir>);
create_and_register_dimension(ninja, helper<nin>);
//Compound dimensions can be defined this way.
create_and_register_dimension(woodleg, helper<pir>, helper<L>); //pirate*length
create_and_register_dimension(pirate_ninja, helper<pir>, helper<nin>); //pirate*ninja
} // namespace dim
} // namespace benri
```

#### Affine quantities
*benri* provides support for [affine](https://en.wikipedia.org/wiki/Affine_space) quantities. In short, these are a vector and a point type. Affine quantities often occur in physics. The following pairs are examples of affine quantities: (time point, time delta); (position, length); (temperature, temperature difference).

The types provided by *benri* allow to make a distinction between these quantities and only allow reasonable operations on them. For example:
```c++
#include <benri/si/temperature.h>

//Given the following function for setting the temperature of a baking oven...
void set_oven(benri::quantity_point<benri::si::celsius_t> temperature);

//...we can do the following:
using namespace benri::si::temperature;

set_oven(200_degree_celsius); //Sets the temperature to 200°C.
set_oven(200_celsius);        //Will not compile.
```

This seems quite simple, but is important if the temperature is derived in another function. For example, several functions might provide a new temperature, but not all results make sense. For example:
```c++
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

//...we can be safe from the following:
set_oven(temperature_update()); //Will not compile. (Otherwise the oven would now be at 10°C.)
set_oven(new_temperature());    //Will compile, and set the temperature to 210°C.
```

#### No runtime units
*benri* units can only be derived at compile time. Therefore, you can only use quantities with units which are known at compile time. If you want to make a runtime decision on which units you use, you need to either use the c++17 `std::variant`/`std::any` or another libraries equivalent. For example:

<!-- TODO: Write example code. -->
```c++
#include <iostream>
#include <string>
#include <variant>
#include <benri/si/base.h>

//Define a variant holding the quantities.
using si_unit = std::variant<
    benri::quantity<benri::si::kilogram_t>,
    benri::quantity<benri::si::metre_t>,
    benri::quantity<benri::si::second_t>
>;

//Define a runtime function.
auto parse(const std::string& input)
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
    std::visit([](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same<T, benri::quantity<benri::si::kilogram_t>>::value)
            std::cout << "kilogram\n" << std::flush;
        else if constexpr (std::is_same<T, benri::quantity<benri::si::metre_t>>::value)
            std::cout << "metre\n" << std::flush;
        else if constexpr (std::is_same<T, benri::quantity<benri::si::second_t>>::value)
            std::cout << "second\n" << std::flush;
        else
            throw;
    }, value);
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
```