# Introduction
*benri* is a c++ library for working with physical quantities. Quantities are the combination of a value with a unit. For example: the quantity `1km` consists of the value `1` and the unit `kilometre`. The library allows the definition of arbitrary units, and provides a container type for quantities. The container handles unit conversions and dimensional checking. Furthermore, a replacement for most of the `<cmath>` functions is provided, to easily updated existing code.

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
```
If it works, you are good to go!

## Install using cmake
If you are using cmake, you can use *benri* by cloning the repository, and adding the `add_subdirectory` and `target_link` library command to your `CMakeLists.txt`. A simple project file might look like this:
```cmake
cmake_minimum_required(VERSION 3.1)

#define the project
project(hello_benri)
add_executable(hello_benri main.cpp)

#add the benri repository
add_subdirectory(benri)
#add the library to the project
target_link_libraries(hello_benri PRIVATE benri)
```

## TLDR; Using *benri*
The library provides several literal types, which can be used in the following way:
```c++
//add namespace containing the literals
using namespace benri::si;
//compose quantities using a prefix literal and a unit constant
auto capacity = 10_micro * farad;
//the literal can be omitted if the prefix is one
auto resistance_a = 10_one * ohm;
auto resistance_b = 10_ohm;
//the kilogram is the only exception to the composition rule
auto mass_a = 5_kilogram;
auto mass_b = 5_kilo * gram; //both are fine
```

In addition, a replacement for most `<cmath>` functions is provided:
<!-- TODO: Write example code. -->
```c++
talk about pow
```

Moreover, *benrr* provides a range of helper functions:
<!-- TODO: Write example code. -->
```c++
show casting
talk about square and cubic
```

# Philosophy
<!-- TODO: Expand on the philosophy behind benri. -->
The functions and types provided in *benri* are a compromise of generality, usability, and compile time. All of the libraries functions and types are defined using `constexpr` constructs and should therefore support compile time evaluation. In reality however, the support is currently limited, because only some of the c++ standard library functions, which are used in *benri*, support this behaviour.

The *benri* library tries to help writing correct c++ programs using the following principles:
- No weird conversions.
- No surprises.
## Design Decisions

# Using *benri*
<!-- TODO: Expand on the usage of benri. --
>
# Known Bugs
<!-- TODO: Can this be done better? -->
 - The unit pascal might conflict with the `pascal` macro set in some windows headers.

# Competition
The *benri* library is not the only library for working with physical quantities. The most notable competitors are [nholthaus]() and [boost](). These libraries provide similar facilities to *benri*, but differ in some important areas. It is therefore recommended to check what you need in your project and select accordingly.

## Quick Comparison
The following table gives a quick overview on the most important features provided by the different quantity libraries:

<!-- TODO: Extend table. -->
| Features                         | benri              | nholthaus | boost |
|:---------------------------------|:-------------------|:----------|:------|
| SI units                         | :heavy_check_mark: |           |       |
| CGS units                        | :heavy_check_mark: |           |       |
| imperial units                   | :heavy_check_mark: |           |       |
| astronomical units               | :heavy_check_mark: |           |       |
| Gray/Sievert support¹            | :heavy_check_mark: |           |       |
| temperature support²             | :heavy_check_mark: |           |       |
| physical/mathematical constants³ | :heavy_check_mark: |           |       |
| affine quantities⁴               | :heavy_check_mark: |           |       |
| user defined dimensions          | :heavy_check_mark: |           |       |
| user defined prefixes            | :heavy_check_mark: |           |       |
| arbitrary prefix conversions⁵    | :heavy_check_mark: |           |       |
| symbolic computation⁶            | :heavy_check_mark: |           |       |
| `<cmath>`  functions             | :heavy_check_mark: |           |       |
| `<chrono>` interoperability      | :x:                |           |       |
| `<iostream>` functions           | :x:                |           |       |
| `<boost>` required               | :x:                |           |       |
| minimum c++ version              | `c++14`            |           |       |
| extensive documentation          | :x:⁷               |           |       |
| extensive unit tests             | :x:⁷               |           |       |

¹ The base units of Sievert and Gray are the same, but their meaning is different. Does the library make a distinction between them?

² Does the library provide different temperature scales and conversions between them?

³ Does the library provide physical and/or mathematical constants?

⁴ Does the library provide affine types? Meaning: Different types for vectors and points are provided?

⁵ Can the library handle arbitrary prefix conversions? For example: `1 megalightyear` to `femtometre`? (Depending on the implementation, the type handling the operation might overflow.)

⁶ Can the library do symbolic computations? For example, if we want the result of the calculation `2year × c` in lightyears, do we need to do a multiplication and division to get the result, or can the libray just remember to carry the `c`?

⁷ Improvements are planned.

## Important features
In the following, the most important differences and features are explained in detail.

#### `<iostream>` functions
*benri* does not provide `<iostream>` functions, and it never will. The reason is, that implementing proper input and output of quantities is hard. One needs to develop a system for parsing and generating arbitrary unit strings. Yet, most users will not be satisfied with the provided functions, as every use case is different. The work is therefore left to you dear *benri* user. You best know what you want, and what units you are using. Thus, you can just write a input and a output function for your project without having to invent the general solution, which would be needed for *benri*.

For example, if your project only handles different times, you can write:
<!-- TODO: Write example code. -->
```c++
template <class >
auto print(benri::quantity<)
```

#### User defined dimensions
*benri* allows its users to define new base dimensions and seemlessly use them together with the already existing ones.
<!-- TODO: Write example code. -->
```c++
```

At the moment *benri* is the only library providing this functionality. In all other libraries, the whole code needs to be expanded, when adding a new dimensions. The reason is, that they store their dimensional information in a fixed (compile time) data structure, whereas *benri* uses a type list.

#### Affine quantities
*benri* provides support for [affine](https://en.wikipedia.org/wiki/Affine_space) quantities. In short, these are a vector and a point type. Affine quantities often occur in physics. The following pairs are examples of affine quantities: (time point, time delta); (position, length); (temperature, temperature difference).

The types provided by *benri* allow to make a distinction between these quantities and only allow reasonable operations on them. For example:
<!-- TODO: Write example code. -->
```c++
```

#### No runtime units
*benri* units can only be derived at compile time.