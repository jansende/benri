#include "helpers.h"

#include <benri/si/temperature.h>
#include <gtest/gtest.h>
using namespace benri::si;
using namespace benri::si::temperature;

TEST(temperature, implicit_conversions)
{
    EXPECT_BENRI_EQ(decltype(1_degree_celsius), 2_degree_celsius + 5_kelvin,
                    7_degree_celsius);
    EXPECT_BENRI_EQ(decltype(1_degree_celsius), 2_degree_celsius + 5_celsius,
                    7_degree_celsius);
    EXPECT_BENRI_EQ(decltype(1_degree_celsius), 2_degree_celsius - 5_kelvin,
                    -3_degree_celsius);
    EXPECT_BENRI_EQ(decltype(1_degree_celsius), 2_degree_celsius - 5_celsius,
                    -3_degree_celsius);
    EXPECT_BENRI_EQ(decltype(1_degree_celsius), 5_kelvin + 2_degree_celsius,
                    7_degree_celsius);
    EXPECT_BENRI_EQ(decltype(1_degree_celsius), 5_celsius + 2_degree_celsius,
                    7_degree_celsius);

    EXPECT_BENRI_EQ(decltype(1_degree_fahrenheit), 2_degree_fahrenheit + 5_rankine,
                    7_degree_fahrenheit);
    EXPECT_BENRI_EQ(decltype(1_degree_fahrenheit), 2_degree_fahrenheit + 5_fahrenheit,
                    7_degree_fahrenheit);
    EXPECT_BENRI_EQ(decltype(1_degree_fahrenheit), 2_degree_fahrenheit - 5_rankine,
                    -3_degree_fahrenheit);
    EXPECT_BENRI_EQ(decltype(1_degree_fahrenheit), 2_degree_fahrenheit - 5_fahrenheit,
                    -3_degree_fahrenheit);
    EXPECT_BENRI_EQ(decltype(1_degree_fahrenheit), 5_rankine + 2_degree_fahrenheit,
                    7_degree_fahrenheit);
    EXPECT_BENRI_EQ(decltype(1_degree_fahrenheit), 5_fahrenheit + 2_degree_fahrenheit,
                    7_degree_fahrenheit);

    EXPECT_BENRI_EQ(decltype(1_degree_kelvin), 2_degree_kelvin + 5_celsius,
                    7_degree_kelvin);
    EXPECT_BENRI_EQ(decltype(1_degree_kelvin), 2_degree_kelvin + 5_kelvin,
                    7_degree_kelvin);
    EXPECT_BENRI_EQ(decltype(1_degree_kelvin), 2_degree_kelvin - 5_celsius,
                    -3_degree_kelvin);
    EXPECT_BENRI_EQ(decltype(1_degree_kelvin), 2_degree_kelvin - 5_kelvin,
                    -3_degree_kelvin);
    EXPECT_BENRI_EQ(decltype(1_degree_kelvin), 5_celsius + 2_degree_kelvin,
                    7_degree_kelvin);
    EXPECT_BENRI_EQ(decltype(1_degree_kelvin), 5_kelvin + 2_degree_kelvin,
                    7_degree_kelvin);

    EXPECT_BENRI_EQ(decltype(1_degree_rankine), 2_degree_rankine + 5_fahrenheit,
                    7_degree_rankine);
    EXPECT_BENRI_EQ(decltype(1_degree_rankine), 2_degree_rankine + 5_rankine,
                    7_degree_rankine);
    EXPECT_BENRI_EQ(decltype(1_degree_rankine), 2_degree_rankine - 5_fahrenheit,
                    -3_degree_rankine);
    EXPECT_BENRI_EQ(decltype(1_degree_rankine), 2_degree_rankine - 5_rankine,
                    -3_degree_rankine);
    EXPECT_BENRI_EQ(decltype(1_degree_rankine), 5_fahrenheit + 2_degree_rankine,
                    7_degree_rankine);
    EXPECT_BENRI_EQ(decltype(1_degree_rankine), 5_rankine + 2_degree_rankine,
                    7_degree_rankine);
}
TEST(temperature, conversion_to_kelvin)
{
    EXPECT_BENRI_NEAR(decltype(1_degree_kelvin),
                      benri::simple_cast<degree_kelvin_t>(constant::absolute_zero),
                      0_degree_kelvin, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_kelvin),
                      benri::simple_cast<degree_kelvin_t>(symbol::absolute_zero),
                      0_degree_kelvin, 1e-2);
    // absolute zero
    EXPECT_BENRI_NEAR(decltype(1_degree_kelvin),
                      benri::simple_cast<degree_kelvin_t>(0_degree_kelvin),
                      0_degree_kelvin, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_kelvin),
                      benri::simple_cast<degree_kelvin_t>(-273.15_degree_celsius),
                      0_degree_kelvin, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_kelvin),
                      benri::simple_cast<degree_kelvin_t>(0_degree_rankine),
                      0_degree_kelvin, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_kelvin),
                      benri::simple_cast<degree_kelvin_t>(-459.67_degree_fahrenheit),
                      0_degree_kelvin, 1e-2);
    // freezing point of brine
    EXPECT_BENRI_NEAR(decltype(1_degree_kelvin),
                      benri::simple_cast<degree_kelvin_t>(255.37_degree_kelvin),
                      255.37_degree_kelvin, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_kelvin),
                      benri::simple_cast<degree_kelvin_t>(-17.78_degree_celsius),
                      255.37_degree_kelvin, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_kelvin),
                      benri::simple_cast<degree_kelvin_t>(459.67_degree_rankine),
                      255.37_degree_kelvin, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_kelvin),
                      benri::simple_cast<degree_kelvin_t>(0_degree_fahrenheit),
                      255.37_degree_kelvin, 1e-2);
    // freezing point of water
    EXPECT_BENRI_NEAR(decltype(1_degree_kelvin),
                      benri::simple_cast<degree_kelvin_t>(273.15_degree_kelvin),
                      273.15_degree_kelvin, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_kelvin),
                      benri::simple_cast<degree_kelvin_t>(0_degree_celsius),
                      273.15_degree_kelvin, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_kelvin),
                      benri::simple_cast<degree_kelvin_t>(491.67_degree_rankine),
                      273.15_degree_kelvin, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_kelvin),
                      benri::simple_cast<degree_kelvin_t>(32_degree_fahrenheit),
                      273.15_degree_kelvin, 1e-2);
    // boiling point of water
    EXPECT_BENRI_NEAR(decltype(1_degree_kelvin),
                      benri::simple_cast<degree_kelvin_t>(373.1339_degree_kelvin),
                      373.1339_degree_kelvin, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_kelvin),
                      benri::simple_cast<degree_kelvin_t>(99.9839_degree_celsius),
                      373.1339_degree_kelvin, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_kelvin),
                      benri::simple_cast<degree_kelvin_t>(671.64102_degree_rankine),
                      373.1339_degree_kelvin, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_kelvin),
                      benri::simple_cast<degree_kelvin_t>(211.97102_degree_fahrenheit),
                      373.1339_degree_kelvin, 1e-2);
}
TEST(temperature, conversion_to_celsius)
{
    EXPECT_BENRI_NEAR(decltype(1_degree_celsius),
                      benri::simple_cast<degree_celsius_t>(constant::absolute_zero),
                      -273.15_degree_celsius, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_celsius),
                      benri::simple_cast<degree_celsius_t>(symbol::absolute_zero),
                      -273.15_degree_celsius, 1e-2);
    // absolute zero
    EXPECT_BENRI_NEAR(decltype(1_degree_celsius),
                      benri::simple_cast<degree_celsius_t>(0_degree_kelvin),
                      -273.15_degree_celsius, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_celsius),
                      benri::simple_cast<degree_celsius_t>(-273.15_degree_celsius),
                      -273.15_degree_celsius, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_celsius),
                      benri::simple_cast<degree_celsius_t>(0_degree_rankine),
                      -273.15_degree_celsius, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_celsius),
                      benri::simple_cast<degree_celsius_t>(-459.67_degree_fahrenheit),
                      -273.15_degree_celsius, 1e-2);
    // freezing point of brine
    EXPECT_BENRI_NEAR(decltype(1_degree_celsius),
                      benri::simple_cast<degree_celsius_t>(255.37_degree_kelvin),
                      -17.78_degree_celsius, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_celsius),
                      benri::simple_cast<degree_celsius_t>(-17.78_degree_celsius),
                      -17.78_degree_celsius, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_celsius),
                      benri::simple_cast<degree_celsius_t>(459.67_degree_rankine),
                      -17.78_degree_celsius, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_celsius),
                      benri::simple_cast<degree_celsius_t>(0_degree_fahrenheit),
                      -17.78_degree_celsius, 1e-2);
    // freezing point of water
    EXPECT_BENRI_NEAR(decltype(1_degree_celsius),
                      benri::simple_cast<degree_celsius_t>(273.15_degree_kelvin),
                      0_degree_celsius, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_celsius),
                      benri::simple_cast<degree_celsius_t>(0_degree_celsius),
                      0_degree_celsius, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_celsius),
                      benri::simple_cast<degree_celsius_t>(491.67_degree_rankine),
                      0_degree_celsius, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_celsius),
                      benri::simple_cast<degree_celsius_t>(32_degree_fahrenheit),
                      0_degree_celsius, 1e-2);
    // boiling point of water
    EXPECT_BENRI_NEAR(decltype(1_degree_celsius),
                      benri::simple_cast<degree_celsius_t>(373.1339_degree_kelvin),
                      99.9839_degree_celsius, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_celsius),
                      benri::simple_cast<degree_celsius_t>(99.9839_degree_celsius),
                      99.9839_degree_celsius, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_celsius),
                      benri::simple_cast<degree_celsius_t>(671.64102_degree_rankine),
                      99.9839_degree_celsius, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_celsius),
                      benri::simple_cast<degree_celsius_t>(211.97102_degree_fahrenheit),
                      99.9839_degree_celsius, 1e-2);
}
TEST(temperature, conversion_to_fahrenheit)
{
    EXPECT_BENRI_NEAR(decltype(1_degree_fahrenheit),
                      benri::simple_cast<degree_fahrenheit_t>(constant::absolute_zero),
                      -459.67_degree_fahrenheit, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_fahrenheit),
                      benri::simple_cast<degree_fahrenheit_t>(symbol::absolute_zero),
                      -459.67_degree_fahrenheit, 1e-2);
    // absolute zero
    EXPECT_BENRI_NEAR(decltype(1_degree_fahrenheit),
                      benri::simple_cast<degree_fahrenheit_t>(0_degree_kelvin),
                      -459.67_degree_fahrenheit, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_fahrenheit),
                      benri::simple_cast<degree_fahrenheit_t>(-273.15_degree_celsius),
                      -459.67_degree_fahrenheit, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_fahrenheit),
                      benri::simple_cast<degree_fahrenheit_t>(0_degree_rankine),
                      -459.67_degree_fahrenheit, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_fahrenheit),
                      benri::simple_cast<degree_fahrenheit_t>(-459.67_degree_fahrenheit),
                      -459.67_degree_fahrenheit, 1e-2);
    // freezing point of brine
    EXPECT_BENRI_NEAR(decltype(1_degree_fahrenheit),
                      benri::simple_cast<degree_fahrenheit_t>(255.37_degree_kelvin),
                      0_degree_fahrenheit, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_fahrenheit),
                      benri::simple_cast<degree_fahrenheit_t>(-17.78_degree_celsius),
                      0_degree_fahrenheit, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_fahrenheit),
                      benri::simple_cast<degree_fahrenheit_t>(459.67_degree_rankine),
                      0_degree_fahrenheit, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_fahrenheit),
                      benri::simple_cast<degree_fahrenheit_t>(0_degree_fahrenheit),
                      0_degree_fahrenheit, 1e-2);
    // freezing point of water
    EXPECT_BENRI_NEAR(decltype(1_degree_fahrenheit),
                      benri::simple_cast<degree_fahrenheit_t>(273.15_degree_kelvin),
                      32_degree_fahrenheit, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_fahrenheit),
                      benri::simple_cast<degree_fahrenheit_t>(0_degree_celsius),
                      32_degree_fahrenheit, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_fahrenheit),
                      benri::simple_cast<degree_fahrenheit_t>(491.67_degree_rankine),
                      32_degree_fahrenheit, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_fahrenheit),
                      benri::simple_cast<degree_fahrenheit_t>(32_degree_fahrenheit),
                      32_degree_fahrenheit, 1e-2);
    // boiling point of water
    EXPECT_BENRI_NEAR(decltype(1_degree_fahrenheit),
                      benri::simple_cast<degree_fahrenheit_t>(373.1339_degree_kelvin),
                      211.97102_degree_fahrenheit, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_fahrenheit),
                      benri::simple_cast<degree_fahrenheit_t>(99.9839_degree_celsius),
                      211.97102_degree_fahrenheit, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_fahrenheit),
                      benri::simple_cast<degree_fahrenheit_t>(671.64102_degree_rankine),
                      211.97102_degree_fahrenheit, 1e-2);
    EXPECT_BENRI_NEAR(
        decltype(1_degree_fahrenheit),
        benri::simple_cast<degree_fahrenheit_t>(211.97102_degree_fahrenheit),
        211.97102_degree_fahrenheit, 1e-2);
}
TEST(temperature, conversion_to_rankine)
{
    EXPECT_BENRI_NEAR(decltype(1_degree_rankine),
                      benri::simple_cast<degree_rankine_t>(constant::absolute_zero),
                      0_degree_rankine, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_rankine),
                      benri::simple_cast<degree_rankine_t>(symbol::absolute_zero),
                      0_degree_rankine, 1e-2);
    // absolute zero
    EXPECT_BENRI_NEAR(decltype(1_degree_rankine),
                      benri::simple_cast<degree_rankine_t>(0_degree_kelvin),
                      0_degree_rankine, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_rankine),
                      benri::simple_cast<degree_rankine_t>(-273.15_degree_celsius),
                      0_degree_rankine, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_rankine),
                      benri::simple_cast<degree_rankine_t>(0_degree_rankine),
                      0_degree_rankine, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_rankine),
                      benri::simple_cast<degree_rankine_t>(-459.67_degree_fahrenheit),
                      0_degree_rankine, 1e-2);
    // freezing point of brine
    EXPECT_BENRI_NEAR(decltype(1_degree_rankine),
                      benri::simple_cast<degree_rankine_t>(255.37_degree_kelvin),
                      459.67_degree_rankine, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_rankine),
                      benri::simple_cast<degree_rankine_t>(-17.78_degree_celsius),
                      459.67_degree_rankine, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_rankine),
                      benri::simple_cast<degree_rankine_t>(459.67_degree_rankine),
                      459.67_degree_rankine, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_rankine),
                      benri::simple_cast<degree_rankine_t>(0_degree_fahrenheit),
                      459.67_degree_rankine, 1e-2);
    // freezing point of water
    EXPECT_BENRI_NEAR(decltype(1_degree_rankine),
                      benri::simple_cast<degree_rankine_t>(273.15_degree_kelvin),
                      491.67_degree_rankine, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_rankine),
                      benri::simple_cast<degree_rankine_t>(0_degree_celsius),
                      491.67_degree_rankine, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_rankine),
                      benri::simple_cast<degree_rankine_t>(491.67_degree_rankine),
                      491.67_degree_rankine, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_rankine),
                      benri::simple_cast<degree_rankine_t>(32_degree_fahrenheit),
                      491.67_degree_rankine, 1e-2);
    // boiling point of water
    EXPECT_BENRI_NEAR(decltype(1_degree_rankine),
                      benri::simple_cast<degree_rankine_t>(373.1339_degree_kelvin),
                      671.64102_degree_rankine, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_rankine),
                      benri::simple_cast<degree_rankine_t>(99.9839_degree_celsius),
                      671.64102_degree_rankine, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_rankine),
                      benri::simple_cast<degree_rankine_t>(671.64102_degree_rankine),
                      671.64102_degree_rankine, 1e-2);
    EXPECT_BENRI_NEAR(decltype(1_degree_rankine),
                      benri::simple_cast<degree_rankine_t>(211.97102_degree_fahrenheit),
                      671.64102_degree_rankine, 1e-2);
}
