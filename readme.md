[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://github.com/jansende/benri/blob/master/license.md)

[![Build Status](https://travis-ci.com/jansende/benri.svg?branch=ace)](https://travis-ci.com/jansende/benri)

# Introduction
*benri* is a c++ library for working with physical quantities. Quantities are the
combination of a value with a unit. For example: the quantity `1km` consists of the value
`1` and the unit `kilometre`. The library allows the definition of arbitrary units and
provides a container type for quantities. The container handles unit conversions and
dimensional checking. Furthermore, a replacement for most of the `<cmath>` functions
is provided, to easily updated existing code.

# Quickstart
In the following, instructions for installing and using *benri* are provided. If you want
more information, please read the later sections on specific topics, have a look at the
[examples](./examples/) folder or scroll through the unit and dimension list in
[tables.md](./tables.md).

## Install without using cmake
The easiest way to get *benri*, is to clone the git repository, add the `include/`
directory to your project, and use the library by adding the following includes to your
project.

```c++
#include <benri/si/si.h>
#include <benri/cmath.h>
```

In order to test if you set up *benri* correctly, try the following example for a cake
recipe.

```c++
#include <benri/si/si.h>
#include <benri/cmath.h>
#include <iostream>

int main()
{
    using namespace benri::si;    //Import si literals.
    using namespace benri::casts; //Import casts into namespace for ADL to work.

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
        << "  vanilla cake  \n"
        << "----------------\n"
        << ceil(mass * 0.028).value()  << " gram butter\n"
        << ceil(mass * 0.099).value()  << " gram sugar\n"
        << ceil(mass * 0.0635).value() << " gram flour\n"
        << ceil(mass / 2828.0).value() << " pack of backing soda\n"
        << floor(mass * 0.002).value() << " eggs\n"
        << ceil(mass * 0.1765).value()  << " gram quark cream\n"
        << ceil(mass * 0.0705).value() << " gram oil\n"
        << ceil(mass / 2828.0).value() << " pack of vanille aroma\n"
        << ceil(mass / 2828.0).value() << "/2 litre milk\n"
        << std::flush;
}
```

If it works, you are good to go!

## Install using cmake
If you are using cmake, you can use *benri* by cloning the repository and adding the
`add_subdirectory` and `target_link` library command to your `CMakeLists.txt`. A simple
project file might look like this.

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
The library provides several literal types, which can be used in the following way.

```c++
//Import si literals.
using namespace benri::si;
//Import casts into namespace for ADL to work.
using namespace benri::casts;
//Compose quantities using a prefix literal and a unit constant.
auto capacity = 10_micro * farad;
//Prefix literals can be omitted.
auto resistance_a = 10_one * ohm;
auto resistance_b = 10_ohm;
//The kilogram is the only exception to the composition rule.
auto mass_a = 5_kilogram;
auto mass_b = 5_kilo * gram; //Both are fine.
```

*benri* automatically converts units for you.

```c++
auto volume = 3_metre * 2_metre * 1.5_metre;

if (volume < 4_cubic * metre) //Works.
```

However, *benri* strictly forbids any math on quantities with mismatching units or
mismatching value types. Quantities have to be explicitly cast to have the same unit/value
type.

```c++
auto volume = 3_centi * metre * 2_metre * 1.5_metre;

if (volume < 4_cubic * metre) //Does not compile!
if (simple_cast<decltype(cubic * metre)>(volume) < 4_cubic * metre) //Works.
if (volume < simple_cast<decltype(volume)>(4_cubic * metre))        //Works.
```

*benri* provides sensible replacements for most `<cmath>` functions.

```c++
#include <benri/cmath.h>

auto x = 3_metre;
auto y = 5_metre;

auto angle = atan2(y,x);
auto sinus = sin(angle);
```

The `pow` function has a specialized overload to deal with powers of units.

```c++
//The proper way.
auto area   = pow<2>(10_metre);         //Calculates the square.
auto length = pow<1,3>(area * 20_metre) //Calculates the cubic root.

//The following does not work because benri can only handle integer powers at
//compile time. The given powers however are set at runtime (and not integer...)
auto area   = pow(10_metre, 2.0);           //Calculates the square.
auto length = pow(area * 20_metre, 1.0/3.0) //Calculates the cubic root.
```

The `log` function is overloaded as well.

```c++
auto length    = 10_metre;
//The log of a unit does not make sense.
auto logarithm = log10(length);

//The proper way.
auto logarithm = log10(length / metre);

//The shortcut.
auto logarithm = log10<decltype(metre)>(length);
```

Moreover, *benri* provides a range of helper functions for powers.

```c++
auto area    = square(10_metre);  //(10m)^2
auto volume  = cubic(10_metre);   //(10m)^3
auto special = quartic(10_metre); //(10m)^4
```

In addition to the SI units, the following headers are provides, which put their units in
a sub-namespace of the same name.

```c++
//Astronomical units -- si::astronomic
#include <benri/si/astronomic.h>
//CGS system units based on SI units -- si::cgs
#include <benri/si/cgs.h>
//Computer Science units -- si::data
#include <benri/si/data.h>
//Imperial units based on SI units -- si::imperial
#include <benri/si/imperial.h>
//Temperature scale units (includes imperial temperature) -- si::temperature
#include <benri/si/temperature.h>
//Includes all of the above
#include <benri/si/everything.h>
```

Last but not least, *benri* provides a range of constants for calculation.

```c++
auto energy = constant::planck_constant *
              constant::speed_of_light / 10e-9_metre; //Energy in Joule.
auto force  = constant::gravitational_constant *
              60_kilogram *
              80_kilogram / square(1_metre); //Force in Newton.
```

Furthermore, constants provide an overload for symbolic calculations, which is handy for
intermediate calculations.

```c++
auto energy  = constant::planck_constant *
               symbol::speed_of_light / 10e-9_metre; //Energy in c×Joule.
auto impulse = energy * symbol::speed_of_light; //Impulse in Newton second
```

This was the TL;DR. Have fun with *benri*!

# Using *benri*
## Philosophy
The *benri* library tries to help writing correct and efficient c++ programmes using the
following principles:

- Be correct.
- Be explicit.
- Be sane.
- Be as efficient as possible.

In the following, these principles are explained in detail.

### Be correct. (No stupid semantic errors.)
*benri* aims to help you write correct c++ programs on the first try. It especially wants
to protect you from stupid semantic errors. If your program compiles, it should be correct.
An infamous example of this kind of error is the
[Mars Climate Orbiter](https://en.wikipedia.org/wiki/Mars_Climate_Orbiter). The probe
crashed into Mars because one of its sensors was giving data in `pound-force seconds`
instead of `newton seconds`. However, this discrepancy was not checked for, leading to
faulty steering commands and finally to the destruction of the probe.

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
    return quantity<newton_second_t>(get_thrust_in_pound_force_second()); //Just don't!
}
```

### Be explicit. (No overflowing/faulty conversions.)
The libraries forces users to be as explicit with their programming as possible. The
reason being that the implicit conversions are very error prone and can lead to unintended
consequences. Therefore nearly all conversions between units and values need to be made
explicit. For example:

```c++
//Dummy function.
auto test(quantity<metre_t>);

//Works fine.
test(20_metre); 

//Does not compile because converting cm to m might cause an overflow in the value
//of the quantity.
test(2000_centi * metre);

//Works fine. The conversion is now explicitely visible.
test(simple_cast<decltype(centi * metre)>(2000_centi * metre)); 
```

This rule applies to math as well. For addition/subtraction implicit conversions are not
allowed. Multiplication/division is fine because we can save the value in a new type. For
example:

```c++
auto a = 2_metre + 4_metre;            //Works fine.
auto b = 2_metre + 400_centi * metre;  //Does not compile because a conversion is
                                       //necessary.
auto c = 2_metre / 1_second;           //Works fine. Result is in m/s.
auto d = 200_centi * metre / 1_second; //Works fine. Result is in cm/s.
```

Furthermore, implicit conversions for comparisons are not allowed:

```c++
auto check_a = f < 3_metre / second;         //Works fine.
auto check_b = f < 3_centi * metre / second; //Does not compile because a conversion is
                                             //necessary.
auto check_c = f < g;                        //Does not compile because a conversion is
                                             //necessary.
auto check_d = f < simple_cast<decltype(f)>(3_centi * metre / second); //Works fine.
auto check_e = f < simple_cast<decltype(f)>(g);                        //Works fine.
```

### Be sane. (Don't do weird things.)
The *benri* library tries to behave in a resonable way and as one expects. The goal is to
always behave in a non-surprising way. Thus, overloads for commonly used functions and
operators, as well as for dimensionless units are implemented. In addition, unusual usage
is disabled where ever possible. For example:

```c++
auto a = 1_metre;
a += 10_centi * metre; //Does not compile because a conversion is necessary.
a += 10.0;             //Does not compile because a dimensionless quantity is used.

auto b = 1_one;
a += 10_one;                       //Works fine.
a += 10_metre / 5_metre;           //Works fine.
a += 10_metre / 500_centi * metre; //Does not compile because a conversion is necessary.
                                   //(The result of the division is in %.)
a += 10.0;                         //Works fine.
```

### Be as efficient as possible. (`constexpr` all the things.)
All of *benris* library types are defined using `constexpr` constructs. This should allow
the compiler to completely eliminate the library overhead of *benri* at compile time. The
assembly of code written with *benri* and of code written with standard c++ types should
be exactly the same. For example:

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

In addition to the types, all of *benris* library functions are defined using `constexpr`
as well. This should allow compile time calculation of these functions. In reality however,
the support is currently limited because only some STD functions used within *benri*
support compile time evaluation. For example:

```c++
constexpr auto delta = abs(5_second - 10_second); //Evaluates to delta = 5_second at
                                                  //compile time.
constexpr auto angle = asin(4_metre / 1_metre);   //Does not compile because compilers do
                                                  //not currently support compile time
                                                  //std::asin.
```

Moreover *benri* tries to reduce the amount of calculations done at runtime by shifting
the work to the compile step. For example, the following operations can be evaluated at
compile time:

```c++
//The simple_cast function can be evaluated at compile time.
//These two definition therefore are EXACTLY the same.
constexpr auto energy = simple_cast<joule_t>(50_giga * joule);
constexpr auto energy = 50000_joule;                           

constexpr auto energy = 4_joule + 5_joule; //Works fine.
constexpr auto ratio  = 4_joule / 5_joule; //Works fine.
```

## Unit conversions and casts
*benri* provides two functions for converting units `simple_cast` and `unit_cast`. Both
can be used to convert units into another. `simple_cast` is always done at compile time
and can be used for most conversions. However, due to restrictions in compile time math,
if the conversion factor contains a root, `unit_cast` has to be used. It calculates the
correct factor at runtime. Fortunately in most cases, when optimizations are used,
`unit_cast` results in the same assembly as if a `simple_cast` were possible.

```c++
constexpr auto length = simple_cast<metre_t>(10_centi * metre); //Evaluated at compile
                                                                //time.
          auto length = simple_cast<metre_t>(10_centi * metre); //Compiler may use a
                                                                //compile time evaluation.

constexpr auto length =   unit_cast<metre_t>(10_centi * metre); //Does not compile.
          auto length =   unit_cast<metre_t>(10_centi * metre); //Evaluated at runtime.
```

*benri* provides the `value_type_cast` function for changing the `value_type` of a
quantity:

```c++
auto speed = 5_centi * metre / second; //The standard is to save values as a double
                                       //internally.
auto speed = value_type_cast<float>(5_centi * metre / second); //However, we only have
                                                               //space for a float.
```

*benri* provides the `remove_prefix` function for generating base unit quantities:

```c++
auto advanced = 42_mega * byte; //The internal type is 42 megybyte.
auto base     = remove_prefix(advanced); //The internal type is 42e6 byte.
```

**WARNING**: `remove_prefix` behaviour depends on the base unit. For complicated derived
units, it might not always be obvious what the base unit is! However, `remove_prefix`
provides the facility to reduce arbitrary units to their base when needed. For example, it
is internally used to cast arbitrary dimensionless units into the right form for the
trigonometric functions. This allows `asin(10_percent)`.

## `quantity` and `quantity_point`

*benri* provides two data types `quantity` and `quantity_point`, which both take a `unit`
and a `value_type`. The `unit` is the physical unit of the quantity, like `metre_t`,
`second_t`, ... The `value_type` is the internal representation of the value, usually
`double` or `float`. While it is possible to use integral types for the `value_type` as
well, it is not recommend because integer types are prone to overflows and sign errors.
When *benri* literals are used, both the `unit` and the `value_type` are hidden behind
aliases for your convenience.

```c++
auto angle = 1_radian; //What you usually will write.
auto angle = quantity<radian_t, double>{1.0}; //This is equivalent.
//(The unit is radian_t and the value_type is double.)

auto hotness = 20_degree_fahrenheit; //What you usually will write.
auto hotness = quantity_point<degree_fahrenheit_t, double>{20.0}; //This is equivalent.
//(The unit is degree_fahrenheit_t and the value_type is double.)
```

The standard `value_type` for *benri*  is `double`. It is used for all literals and
constants. However, you can change that by setting the `BENRI_PRECISION` macro before
including the library:

```c++
#define BENRI_PRECISION float //set the standard value_type to float
#include <benri/si/si.h>
```

**WARNING**: Setting `BENRI_PRECISION` to an integral value will produce weird behaviour
because the internal floating point constants might be rounded to zero.

The `quantity` type is the most used type because it allows the largest range of possible
operations. The `quantity_point` is a special type for affine operations which has a
purposefully restricted set of possible operations. For further explanations on affine
operations, please have a look at section: [Affine quantities](#affine-quantities) The
possible operations for both types are:

| operations                              | `quantity`          | `quantity_point`   |
|:----------------------------------------|:--------------------|:-------------------|
| multiplication with a `quantity`        | :heavy_check_mark:  | :x:                |
| multiplication with a `quantity_point`  | :x:                 | :x:                |
| multiplication with a `value_type`      | :heavy_check_mark:  | :x:                |
| division by a `quantity`                | :heavy_check_mark:  | :x:                |
| division by a `quantity_point`          | :x:                 | :x:                |
| division by a `value_type`              | :heavy_check_mark:  | :x:                |
| division of a `value_type`              | :heavy_check_mark:  | :x:                |
| addition of a `quantity`                | :heavy_check_mark:  | :heavy_check_mark: |
| addition of a `quantity_point`          | :heavy_check_mark:  | :x:                |
| addition of a `value_type`              | :heavy_check_mark:¹ | :x:                |
| subtraction of a `quantity`             | :heavy_check_mark:  | :heavy_check_mark: |
| subtraction of a `quantity_point`       | :heavy_check_mark:  | :heavy_check_mark: |
| subtraction of a `value_type`           | :heavy_check_mark:¹ | :x:                |
| comparison with a `quantity`            | :heavy_check_mark:  | :x:                |
| comparison with a `quantity_point`      | :x:                 | :heavy_check_mark: |
| comparison with `value_type`            | :heavy_check_mark:¹ | :x:                |
| implicit cast to `value_type`           | :heavy_check_mark:² | :x:                |
| implicit construction with `value_type` | :heavy_check_mark:² | :x:                |

¹ Only allowed for quantities with dimension `1`.

² Only allowed for dimensionless quantities, like `1`, `1%`, ...

## Units and Constants

*benri* provides the following headers:
- `si/astronomic.h` for astronomical units.
- `si/base.h` for base SI units (no derived units).
- `si/cgs.h` for CGS system units (based on SI).
- `si/data.h` for Computer Science units (like pixel, byte, ...).
- `si/imperial.h` for Imperial units (based on SI).
- `si/si.h` for SI units.
- `si/temperature.h` for temperature scales units (like °C, ...).
- `si/everything.h` for including all units mentioned above.

The right header for most users is `si/si.h` as all base SI units and derived SI units are
found there. All other headers (except `si/base.h`) provide more specialized units, and
include this header as well. SI units reside in the `si` namespace, and spezialized units
in the `si::name-of-header` sub-namespace.

*benri* provides an extensive [list](./tables.md) of constants which can be accessed via
the `si::constant` or `si::symbol` namespace. When using `si/si.h` all SI constants are
loaded. When using additional unit packages, more constants get added to the `si::constant`
and `si::symbol` namespace (no sub-namespacing like for units).

The difference between constants provided in the `si::constant` namespace and constants
provided in the `si::symbol` namespace is the way the value of the constant is stored:
- `si::constant` stores the constant in a quantity where the quantity has the unit and the
   value of the constant.
-  si::symbol` stores the constant in a quantity with value 1, where the unit is the unit
   of the constant with a prefix of the constant value.

For example:
- `si::constant::speed_of_light` is `quantity<metre/second>{c}`;
- `si::symbol::speed_of_light` is `quantity<c * metre/second>{1}`;

This allows symbolic calculations where one can express units in terms of a constant.

```c++
#include <benri/si/astronomic.h>

auto mass_a = 2_solar_mass;           //mass in kilogram
auto mass_b = 2 * symbol::solar_mass; //mass in Solar masses
```

Furthermore, when intermediate results suffer from overflow or rounding, `si::symbol` can
be used to mitigate these problems. For example:

```c++
#define BENRI_PRECISION float //set the standard value_type to float
#include <benri/si/si.h>

//constant
auto impulse_a = constant::planck_constant / 7e5_metre; //≈9.5×10⁻⁴⁰ Ns We lose precision here!
auto impulse_b = constant::planck_constant / 3e2_metre; //≈2.2×10⁻³⁶ Ns We are close to losing precision here!

auto relation = static_cast<float>((impulse_b - impulse_a) / impulse_b);

//symbol
auto impulse_a = symbol::planck_constant / 7e5_metre; //≈1.4×10⁻⁶ h/m Everything is fine.
auto impulse_b = symbol::planck_constant / 3e2_metre; //≈3.3×10⁻³ h/m Everything is fine.

auto relation = static_cast<float>((impulse_b - impulse_a) / impulse_b);
```

## Defining new units and dimensions
*benri* allows its users to define new base dimensions and seemlessly use them together
with the already existing ones. This is achieved through macros.

```c++
#include <iostream>
#include <benri/si/si.h>
#include <benri/si/macros.h>

//Add a pirate (pir) and a ninja (nin) bas dimension.
struct pir
{
    //The name values need to be provided because benri internally sorts the dimensions by
    //their name.
    static constexpr benri::meta::static_string name = "pir";
};
struct nin
{
    static constexpr benri::meta::static_string name = "nin";
};
//Dimensions can be generated using macros.
using benri::dimension::helper;
//Singular dimensions.
create_and_register_dimension(pirate, helper<pir>);
create_and_register_dimension(ninja, helper<nin>);
//Compound dimensions.
create_and_register_dimension(woodleg, helper<pir>, helper<benri::dimension::L>); //pirate*length
create_and_register_dimension(pirate_ninja, helper<pir>, helper<nin>); //pirate*ninja

//Units can be generated using macros as well.
implement_unit(jack_sparrow, pirate_t, benri::prefix::one_t);
implement_unit(hanzo, ninja_t, benri::prefix::one_t);
implement_unit(blackbeard, woodleg_t, benri::prefix::one_t);

//So can constants.
create_constant(kaido, benri::prefix::hecto_t, typename decltype(jack_sparrow * hanzo)::unit_type);

int main()
{
    using namespace benri::si;

    auto temp = double{};
    std::cout << "Your pirate strength in Jack Sparrow: ";
    std::cin >> temp;
    auto pirate = temp * jack_sparrow;

    std::cout << "Your ninja strength in Hanzo: ";
    std::cin >> temp;
    auto ninja = temp * hanzo;

    std::cout << "Your woodleg length in metre: ";
    std::cin >> temp;
    auto woodleg = temp * metre;

    //Calculate strength from woodleg.
    auto pirate_ninja = 2_hanzo * 3_blackbeard / woodleg;

    auto strength = pirate * ninja + pirate_ninja;
    std::cout << "You are worth: " << (strength / kaido).value() << "Kaido.";
}
```

## `<chrono>` support
Without some help, *benri* cannot interact with the `<chrono>` library because the types
provided are different. However, by including the `benri/chrono.h` header *benri* gets the
necessary conversion operators. (`benri/chrono.h` includes `<chrono>` as well.) 

With `benri/chrono.h` included:
+ `std::chrono::duration` acts like a `benri::quantity` and
+ `std::chrono::time_point` acts like a `benri::quantity_point`.
+ Within expression `<chrono>` types are converted to *benri* types automatically. (The
  result of such mixed expression is always a *benri* type.)

**WARNING**: The same caveats as for *benri* types apply to `<chrono>`! Quantities with 
different units or value types do no interact. This can get be confusing because *benri*
uses `double` as its default value type whereas `<chrono>` uses integer values. If your
code does not compile, you probably forgot to cast to the right value type.

In addition to these type conversions, `benri/chrono.h` provides:
+ Three new dimensions: `system_clock_t`, `steady_clock_t`, and `high_resolution_clock_t`.
  These dimension are named similar to the clocks provided by the `<chrono>` library.
  However, whereas `std::chrono::high_resolution_clock` might alias to one of the other
  types, within in *benri*  it is always distinct.
+ Three new constants/symbols `system_epoch`, `steady_epoch`, and `high_resolution_epoch`.
  These represent the zero point for each clock.
+ A range of `quantity_point` literals called `TIME_since_CLOCK`, where `TIME` can be
  `seconds`, `hours`, `days`, `weeks`, `months`, or `years` and `CLOCK` either
  `system_epoch`, `steady_epoch`, or `high_resolution_epoch`. For example:
  `42_seconds_since_system_epoch`.
+ The `now<Clock, Unit, ValueType>()` template function, which manages the annoying casts
  involved to construct a *benri* time point with the `<chrono>` now function. `Clock` is
  a `<chrono>` clock type, `Unit` is an optional *benri* time unit, and `ValueType` an
  optional value type. If no `Unit` is defined, the default unit of the clock is used. The
  default for the `ValueType` is the same as for all *benri* types.

A short example on how *benri* interacts with `<chrono>`.
```c++
#include <benri/chrono.h>
#include <benri/si/si.h>
#include <benri/si/temperature.h>
#include <chrono>
#include <iostream>
#include <random>

using namespace benri::si;

class tnt
{
  public:
    tnt(const benri::quantity<second_t> fuse_time);
    auto ignite(benri::quantity_point<seconds_since_system_epoch_t> now) -> void;
    auto ignited() -> bool;
    auto exploded(benri::quantity_point<seconds_since_system_epoch_t> now) -> bool;
    auto fuse_left(benri::quantity_point<seconds_since_system_epoch_t> now) -> benri::quantity<second_t>;   
};

int main()
{
    using namespace benri::si;

    auto fuse_time = double{};
    std::cout << "Enter fuse time in seconds: ";
    std::cin >> fuse_time;
    auto bomb = tnt{fuse_time * second};
    std::cout << "Bomb successfully created!\n"
              << "Ignited the fuse.\n"
              << "Starting Countdown...\n";

    auto now = benri::now<std::chrono::system_clock, seconds_since_system_epoch_t>();
    bomb.ignite(now);

    for (auto counter = static_cast<int>(bomb.fuse_left(now).value());
         !bomb.exploded(now);
         now = benri::now<std::chrono::system_clock, seconds_since_system_epoch_t>())
    {
        if (static_cast<int>(bomb.fuse_left(now).value()) < counter)
        {
            if (counter == 30 || counter == 20 || counter <= 10)
                std::cout << counter << "s\n";
            counter--;
        }
    }
    std::cout << "KABOOMM!!\n";
}
```

## Known bugs
 - The unit pascal might conflict with the `pascal` macro set in some windows headers.
 - msvc can have exorbitantly longer compile times than clang and gcc, especially for
   larger projects.
 - msvc might fail on larger compilation units with [Error C1060: compiler is out of heap space](https://docs.microsoft.com/en-us/cpp/error-messages/compiler-errors-1/fatal-error-c1060?view=vs-2019).
   This seems to be a problem with the msvc internals handling templated code. The best
   remedy is to split the compilation unit into smaller tasks.

## Library structure
If you want to have a look at the *benri* code, or you are searching for the right headers
to include, *benri* is based on the following structure:

```bash
benri/ #main git repo
    examples/ #several examples
    include/benri/ #actual library
        impl/ #collection of internal types and algorithms
              #(API MAY CHANGE AT ANY TIME)
            meta/ #compile time data structures and algorithms
                algorithm.h #compile time algorithms
                array.h     #compile time array because std::array is not there yet
                math.h      #compile time math functions, mostly on primes
                string.h    #const char* string wrapper
            type/ #template type handling functions
                comp.h      #function for comparing types, used to sort type lists
                list.h      #type list type
                sort.h      #type list sorting function
                traits.h    #collection of type traits
            config.h        #compilation helpers
            dimension.h     #dimension type
            math.h          #math functions for dimension and prefix type lists
            prefix.h        #prefix type and its functions
            unit.h          #unit type and its functions
        si/
            astronomic.h    #astronomical units and constants
            base.h          #base si units metre, second, ...
                            #plus constants, but no derived units
                            #like newton, sievert, ... 
            cgs.h           #cgs units and constants
            data.h          #computer science units like byte, bit, pixel, ...
            dimensions.h    #base dimensions and derived dimensions used to create units
            everything.h    #special header for importing all si headers at once
            imperial.h      #imperial units and constants
            macros.h        #macros for easily generating dimensions, units and constants/symbols
            prefixes.h      #si prefixes and constant values
            si.h            #all of the si units
            temperature.h   #temperature units and conversion functions
        chrono.h            #<chrono> support functions
        cmath.h             #implementation of all cmath functions
        quantity_point.h    #affine point
        quantity.h          #the standard quantity type
    tests/ #several unit tests
    changelog.md #list of versions
    readme.md    #this document
    tables.md    #table of physical units and dimensions
```

**WARNING**: The files contained within `benri/impl/` are not part of the API and subject
to change at any time!

#### `benri/impl/type/string.h`
- Provides compile time encapsulation for `const char*` strings via the
  `meta::static_string` class. Might be replaced by [P0259](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0259r0.pdf)
  in the future.
- Provides compile time version of `std::strcmp` called `meta::strcmp`.

#### `benri/impl/type/comp.h`
- Provides function for ordering types at compile time via the `type::type_order` function
  and a custom `type::type_hash`.

#### `benri/impl/type/list.h`
- Provides type list variants `type::list` and `type::sorted_list`.
- Provides type list concatenation function `type::concat`.

#### `benri/impl/type/sort.h`
- Provides `type::insertion_sort` for type lists, based on the ordering function
  `type::type_order`. Sorts `type::list`, leaves `type::sorted_list` untouched.

#### `benri/impl/type/traits.h`
- Provides range of type traits via the [Detection Idiom](https://www.youtube.com/watch?v=U3jGdnRL3KI).

#### `benri/impl/dimension.h`
- Provides container `dim` for storing based dimensions and their associated power.

#### `benri/impl/prefix.h`
- Provides container `pre` for storing prefixes and their associated power.
- Provides compile time functions for calculating the value of a prefix `expand_prefix` or
  list of prefixes `expand_prefix`_list`.
- Provides runtime time functions for calculating the value of a prefix
  `runtime_expand_prefix` or list of prefixes `runtime_expand_prefix`_list`.

#### `benri/impl/math.h`
- Provides function `type::emplace` for emplacing a new `pre`/`dim` into a `pre`/`dim`
  type list. (Updating power of `dim`/`pre` in list if found, and adding it at the end if
  not found.)
- Provides function `type::remove_zero_powers` for removing `pre`/`dim` with power of zero
  from a `pre`/`dim` type list.
- Provides function `type::multiply_lists` for multiplying two or more `pre`/`dim` lists.
  (Calling `type::emplace` on the first list with the arguments of the others.)
- Provides function `type::pow_list` for updating the powers of `pre`/`dim` in a type list.
- Provides function `type::divide_lists` for dividing two `pre`/`dim` type lists.
- Provides shortcut `type::make_prefix` for generating a `pre` type list from a given
  ratio.
- Provides shortcut `type::make_prefix_pow10` for generating a `pre` type list for a given
  power of 10.

#### `benri/impl/unit.h`
- Provides container `unit` for storing `dim` and `pre` type lists together as a unit.
- Provides shortcut `one` for the unit without prefix and dimension.
- Provides shortcuts `multiply_units`, `pow_unit` and `divide_units` which execute the
  right operations on the `dim` and `pre` type lists.

#### `benri/quantity.h`
- Provides container `quantity` for storing a value of `value_type` with its associated
  unit `unit`. Container provides possible math and comparison functionality for
  quantities of the same unit. Additional checks for possible math and comparison
  functionality between quantities of different units are provided as well.
- Provides shortcuts `square`, `cubic` and `quartic` for multiplying units.
- Provides function `value_type_cast` for changing the `value_type` of a `quantity`.
- Provides function `simple_cast` for converting a `quantity` to another unit at compile
  time.
- Provides function `unit_cast` for converting a `quantity` to another unit at runtime.
- Provides function `remove_prefix` for converting a `quantity` to its base unit.
- Provides ADL helper namespace `casts`.

#### `benri/quantity_point.h`
- Provides container `quantity_point` for storing a value of `value_type` with its
  associated unit `unit`. Container provides a restricted set of the `quantity` math and
  comparison functionality to achieve affine behaviour.
- Provides function `value_type_cast` for changing the `value_type` of a `quantity_point`.
- Provides function `simple_cast` for converting a `quantity_point` to another unit at
  compile time.
- Provides function `unit_cast` for converting a `quantity_point` to another unit at
  runtime.
- Provides function `remove_prefix` for converting a `quantity_point` to its base unit.
- Provides ADL helper namespace `casts`.

## The `unit` type
The `unit` type implements the physics concept of a unit.

A unit is the product of a prefix and a number of base dimensions with an associated power:

$$
\text{Unit}= \text{Prefix}\times\prod_i \text{Base}_i^{\text{Power}_i}\ \text{.}
$$

For example, the unit Mega Newton can be expressed in the SI base dimensions Mass,
Length, and Time as:

$$
\text{Mega Newton} = \text{Mega}\times \text{Mass}\cdot \text{Length}\cdot \text{Time}^{-2}\ \text{.}
$$

In order to store the product of base dimensions, the `unit` type uses a type list of `dim`
where `dim` stores the base dimension and their associated power. For aboves example:

```c++
unti<mega * newton>::dimension = list<dim<Mass>, dim<Length>, dim<Time, -2>>;
//This is not the actual template code, but representative of how it works.
```

Inside *benri* units are compared via their type list. This means that regardless of the
computation taking place, the same units have to have the same type list. This is achieved
by removing base dimensions with power zero and by sorting the type list according to the
`::name` attribute of the base dimension.

Prefixes are usually integers. Yet, in C++ integers have a maximum range which makes it
impossible to multiply/divide arbitrary units. *benri* solves this problem by not storing
the prefix in a single integer. Prefixes are prime factorialized and saved in a type list
similar to the dimension:

$$
\text{Prefix} = \prod_j \text{Prime}_j^{\text{Power}_j}\ \text{.}
$$

For aboves example:

```c++
unti<mega * newton>::prefix = list<pre<2, 6>, dim<5, 6>>;
//This is not the actual template code, but representative of how it works.
```

A side effect of the prefix type list, is that it is possible to store symbolic factors
for the prefix.

## The `is_convertible_into` helper
Inside *benri* quantities are compared via their unit type list. If two types do not have
the same type list, they are not the same. However, this is not always preferred. To
overcome this behaviour, *benri* additionally checks if two quantities should be
considered the same via the `is_convertible_into` function. For example, this is necessary
for temperatures, where a `quantity_point` of K can be converted to a quantity of °K
although both units do not have the same type.

Quantities can be added to `is_convertible_into` function by overloading the `convert`
object. It is used for the actual conversion as well:

```c++
template <class Prefix, class ValueType>
struct convert<quantity<unit<dimension::celsius_temperature_t, Prefix>, ValueType>,
               quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>>
{
    constexpr auto operator()(
        const quantity<unit<dimension::celsius_temperature_t, Prefix>, ValueType>& rhs)
        -> quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>{
            rhs._value};
    }
    constexpr auto operator()(
        quantity<unit<dimension::celsius_temperature_t, Prefix>, ValueType>&& rhs)
        -> quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>
    {
        return quantity<unit<dimension::thermodynamic_temperature_t, Prefix>, ValueType>{
            std::move(rhs._value)};
    }
};
```

# Competition
The *benri* library is not the only library for working with physical quantities. The most
notable competitors are [boost](https://www.boost.org/doc/libs/1_68_0/doc/html/boost_units.html),
[nholthaus/units](https://github.com/nholthaus/units), [PhysUnits-CT](https://github.com/martinmoene/PhysUnits-CT-Cpp11),
and [mpusz/units](https://github.com/mpusz/units). These libraries provide similar
facilities to *benri*, but differ in some important areas. It is therefore recommended to
check what you need in your project and select accordingly.

## Quick comparison
The following table gives a quick overview on the most important features provided by the
different quantity libraries:

| Features                         | [benri](https://github.com/jansende/benri) | [boost](https://www.boost.org/doc/libs/1_68_0/doc/html/boost_units.html) | [nholthaus/units](https://github.com/nholthaus/units) | [PhysUnits-CT](https://github.com/martinmoene/PhysUnits-CT-Cpp11) | [mpusz/units](https://github.com/mpusz/units)⁸ |
|:---------------------------------|:-------------------------------------------|-------------------------------------------------------------------------:|:-----------------------------------------------------:|:-----------------------------------------------------------------:|-----------------------------------------------:|
| SI units                         | :heavy_check_mark:                         | :heavy_check_mark:                                                       | :heavy_check_mark:                                    | :heavy_check_mark:                                                | (:heavy_check_mark:)                           |
| CGS units                        | :heavy_check_mark:                         | :heavy_check_mark:                                                       | :x:                                                   | (:heavy_check_mark:)                                              | :x:                                            |
| imperial units                   | :heavy_check_mark:                         | :heavy_check_mark:                                                       | :heavy_check_mark:                                    | :heavy_check_mark:                                                | :x:                                            |
| astronomical units               | :heavy_check_mark:                         | :heavy_check_mark:                                                       | :x:                                                   | (:heavy_check_mark:)                                              | :x:                                            |
| Gray/Sievert support¹            | :heavy_check_mark:                         | :x:                                                                      | :x:                                                   | :x:                                                               | :x:                                            |
| temperature support²             | :heavy_check_mark:                         | :heavy_check_mark:                                                       | :heavy_check_mark:                                    | :heavy_check_mark:                                                | :x:                                            |
| physical/mathematical constants³ | :heavy_check_mark:                         | :heavy_check_mark:                                                       | (:heavy_check_mark:)⁷                                 | (:heavy_check_mark:)⁷                                             | :x:                                            |
| affine quantities⁴               | :heavy_check_mark:                         | :heavy_check_mark:                                                       | :x:                                                   | :x:                                                               | :x:                                            |
| user defined dimensions          | :heavy_check_mark:                         | :heavy_check_mark:                                                       | :x:                                                   | :x:                                                               | :heavy_check_mark:                             |
| user defined prefixes            | :heavy_check_mark:                         | :heavy_check_mark:                                                       | :heavy_check_mark:                                    | :heavy_check_mark:                                                | :heavy_check_mark:                             |
| arbitrary prefix conversions⁵    | :heavy_check_mark:                         | :heavy_check_mark:                                                       | :x:                                                   | :heavy_check_mark:                                                | :x:                                            |
| symbolic computation⁶            | :heavy_check_mark:                         | :x:                                                                      | :x:                                                   | :x:                                                               | :x:                                            |
| `<cmath>`  functions             | :heavy_check_mark:                         | :heavy_check_mark:                                                       | :heavy_check_mark:                                    | :x:                                                               | :x:                                            |
| `<chrono>` interoperability      | :heavy_check_mark:                         | :x:                                                                      | :heavy_check_mark:                                    | :x:                                                               | :x:                                            |
| `<iostream>` functions           | :x:                                        | :heavy_check_mark:                                                       | (:heavy_check_mark:)                                  | (:heavy_check_mark:)                                              | :x:                                            |
| `<boost>` required               | :x:                                        | :heavy_check_mark:                                                       | :x:                                                   | :x:                                                               | :x:                                            |
| minimum c++ version              | `c++14`                                    | `c++98`                                                                  | `c++14`                                               | `c++11`                                                           | `c++20`                                        |

¹ The base units of Sievert and Gray are the same, but their meaning is different. Does
  the library make a distinction between them?

² Does the library provide different temperature scales and conversions between them?

³ Does the library provide physical and/or mathematical constants?

⁴ Does the library provide affine types? Meaning: Different types for vectors and points
  are provided?

⁵ Can the library handle arbitrary prefix conversions? For example: `1 megalightyear` to
  `femtometre`? (Depending on the implementation, the type handling the operation might
  overflow.)

⁶ Can the library do symbolic computations? For example, if we want the result of the
  calculation `2year × c` in lightyears, do we need to do a multiplication and division to
  get the result, or can the libray just remember to carry the `c`?

⁷ [nholthaus](https://github.com/nholthaus/units) and [PhysUnits-CT](https://github.com/martinmoene/PhysUnits-CT-Cpp11)
  only supply a very limited list of constants, without source.

⁸ Although the scope is very limited right now, [mpusz/units](https://github.com/mpusz/units)
  makes an effort to achieve C++ Standardization.

## Features / Design
In the following, the most important differences and features are explained in detail.

#### `<iostream>` functions
*benri* doesn't provide any `<iostream>` functions and it never will. The reason is, that
implementing proper input and output of quantities is hard. One needs to develop a system
for parsing and generating arbitrary unit strings. Yet, most users will not be satisfied
with the provided functions, as every use case is different. The work is therefore left to
each *benri* user. You yourself know best what you want, and what units you are using.

Here is an example on how a project could provide stream output for different time units.

```c++
#include <iostream>
#include <benri/si/base.h>

template <class Unit>
auto operator<<(std::ostream &os, const benri::quantity<Unit> &value) -> std::ostream&
{
    os << value.value() << "?";
    return os;
}
auto operator<<(std::ostream &os, const benri::quantity<benri::si::second_t> &value) -> std::ostream&
{
    os << value.value() << "s";
    return os;
}
auto operator<<(std::ostream &os, const benri::quantity<benri::si::minute_t> &value) -> std::ostream&
{
    os << value.value() << "min";
    return os;
}
auto operator<<(std::ostream &os, const benri::quantity<benri::si::hour_t> &value) -> std::ostream&
{
    os << value.value() << "h";
    return os;
}
```

#### User defined dimensions
*benri* allows its users to define new base dimensions and seemlessly use them together
with the already existing ones. See: [Defining new units and dimensions](#defining-new-units-and-dimensions)

#### Affine quantities
*benri* provides support for [affine](https://en.wikipedia.org/wiki/Affine_space)
quantities. In short, these are a vector and a point type. Affine quantities often occur
in physics. The following pairs are examples of affine quantities: (time point, time delta);
(position, length); (temperature, temperature difference).

The types provided by *benri* allow to make a distinction between these quantities and
only allow reasonable operations on them. For example:

```c++
#include <benri/si/temperature.h>

//Given the following function for setting the temperature of a baking oven...
void set_oven(benri::quantity_point<benri::si::celsius_t> temperature);

//...we can do the following:
using namespace benri::si::temperature;

set_oven(200_degree_celsius); //Sets the temperature to 200°C.
set_oven(250_celsius);        //Will not compile because we have no zero point.
set_oven(zero_point(celsius) + 250_celsius); //Works fine.
```

This seems quite simple, but is important if the temperature is derived in another
function. For example, several functions might provide a new temperature, but not all
results make sense. For example:

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
set_oven(temperature_update()); //Will not compile. (Otherwise the oven would now be
                                //at 10°C.)
set_oven(new_temperature());    //Will compile, and set the temperature to 210°C.
```

#### No runtime units
*benri* units can only be computed at compile time. Thus, only quantities whose units have
been generated at compile time can be used at runtime. This makes writing generic runtime
code hard. However, this is on purpose as *benri* is supposed to perform compile time
checks for zero overhead at runtime.

If you nevertheless want to make a runtime decision on which units you use, you need to
either use the c++17 `std::variant`/`std::any` or another libraries equivalent. For 
example:

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
