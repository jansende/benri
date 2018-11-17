# Introduction
*benri* is a c++ library for working with physical quantities. Quantities are the combination of a value with a unit. For example: the quantity `1km` consists of the value `1` and the unit `kilometre`. The library allows the definition of arbitrary units, and provides a container type for quantities. The container handles unit conversions and dimensional checking. Furthermore, a replacement for most of the `<cmath>` functions is provided, to easily updated existing code.

## Quickstart
The easiest way to get *benri*, is to clone the git repository, add the `include/` directory to your project, and use the library by adding the following includes to your file:
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
Several literal types are provided, and can be used in the following way:
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
For more information either read the rest of this document, or have a look at the examples in the `samples/` folder.

## Installation using cmake

# Philosophy
The functions and types provided in *benri* are a compromise of generality, usability, and compile time. All of the libraries functions and types are defined using `constexpr` constructs and should therefore support compile time evaluation. In reality however, the support is currently limited, because only some of the c++ standard library functions, which are used in *benri*, support this behaviour.

The *benri* library tries to help writing correct c++ programs using the following principles:
- No weird conversions.
- No surprises.

# Known Bugs
 - The unit pascal might conflict with the `pascal` macro set in some windows headers.

# Competition

| Features                         | benri              | nholthaus | boost |
|:---------------------------------|:-------------------|:----------|:------|
| si units                         | :heavy_check_mark: |           |       |
| cgs units                        | :heavy_check_mark: |           |       |
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

¹ The base units of Sievert and Gray are the same, but their meaning is different. Does the library make a distinction between them?

² Does the library provide different temperature scales and conversions between them?

³ Does the library provide physical and/or mathematical constants?

⁴ Does the library provide affine types? Meaning: different types for vectors and points.

⁵ Can the library handle arbitrary prefix conversions? For example: `1 megalightyear` to `femtometre` 

⁶ Can the library do symbolic computations? For example, if we want the result of the calculation `2year × c` in lightyears, do we need to do a multiplication and division to get the result, or can the libray just remember carry the `c`?
