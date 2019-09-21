#include "helpers.h"

#include <benri/si/base.h>
#include <benri/si/temperature.h>
#include <gtest/gtest.h>
using namespace benri::si;
using namespace benri::si::temperature;

TEST(quantity_point, addition_subtraction)
{
    EXPECT_BENRI_EQ(decltype(1_degree_celsius), 1_degree_celsius + 1_kelvin,
                    2_degree_celsius);
    EXPECT_BENRI_EQ(decltype(1_degree_celsius), 1.7_kelvin + 0.3_degree_celsius,
                    2_degree_celsius);

    EXPECT_BENRI_EQ(decltype(1_degree_celsius), 1_degree_celsius - 1_kelvin,
                    0_degree_celsius);
    EXPECT_BENRI_EQ(decltype(1_degree_celsius), 1.7_degree_celsius - 0.3_kelvin,
                    1.4_degree_celsius);
    EXPECT_BENRI_EQ(decltype(1_degree_celsius), 1.2_degree_celsius - 8.3_kelvin,
                    -7.1_degree_celsius);
    EXPECT_BENRI_EQ(decltype(1_degree_celsius), -1.2_degree_celsius - 8.3_kelvin,
                    -9.5_degree_celsius);

    EXPECT_BENRI_EQ(decltype(1_kelvin), 1_degree_celsius - 1_degree_celsius, 0_kelvin);
    EXPECT_BENRI_EQ(decltype(1_kelvin), 1.7_degree_celsius - 0.3_degree_celsius,
                    1.4_kelvin);
    EXPECT_BENRI_EQ(decltype(1_kelvin), 1.2_degree_celsius - 8.3_degree_celsius,
                    -7.1_kelvin);
    EXPECT_BENRI_EQ(decltype(1_kelvin), -1.2_degree_celsius - 8.3_degree_celsius,
                    -9.5_kelvin);

    {
        auto value = 1_degree_celsius;
        value += 1_kelvin;
        EXPECT_BENRI_EQ(decltype(1_degree_celsius), 2_degree_celsius, value);
    }
    {
        auto value = 1.7_degree_celsius;
        value += 0.3_kelvin;
        EXPECT_BENRI_EQ(decltype(1_degree_celsius), 2_degree_celsius, value);
    }
    {
        auto value = 1_degree_celsius;
        value -= 1_kelvin;
        EXPECT_BENRI_EQ(decltype(1_degree_celsius), 0_degree_celsius, value);
    }
    {
        auto value = 1.7_degree_celsius;
        value -= 0.3_kelvin;
        EXPECT_BENRI_EQ(decltype(1_degree_celsius), 1.4_degree_celsius, value);
    }
    {
        auto value = 1.2_degree_celsius;
        value -= 8.3_kelvin;
        EXPECT_BENRI_EQ(decltype(1_degree_celsius), -7.1_degree_celsius, value);
    }
    {
        auto value = -1.2_degree_celsius;
        value -= 8.3_kelvin;
        EXPECT_BENRI_EQ(decltype(1_degree_celsius), -9.5_degree_celsius, value);
    }
}

TEST(quantity_point, user_defined_literals)
{
    EXPECT_BENRI_EQ(decltype(1_degree_celsius), 1.0_degree_celsius, 1_degree_celsius);
    EXPECT_BENRI_EQ(decltype(1_degree_celsius), 1.2_degree_celsius, 1.2_degree_celsius);
    EXPECT_BENRI_EQ(decltype(1_degree_celsius), -7.0_degree_celsius, -7_degree_celsius);
    EXPECT_BENRI_EQ(decltype(1_degree_celsius), -7.1_degree_celsius, -7.1_degree_celsius);

    EXPECT_BENRI_EQ(decltype(1_degree_celsius), benri::quantity_point<celsius_t>{1.0},
                    1_degree_celsius);
    EXPECT_BENRI_EQ(decltype(1_degree_celsius), benri::quantity_point<celsius_t>{1.2},
                    1.2_degree_celsius);
    EXPECT_BENRI_EQ(decltype(1_degree_celsius), benri::quantity_point<celsius_t>{-7.0},
                    -7_degree_celsius);
    EXPECT_BENRI_EQ(decltype(1_degree_celsius), benri::quantity_point<celsius_t>{-7.1},
                    -7.1_degree_celsius);
}

TEST(quantity_point, comparison)
{
    EXPECT_FALSE(1.7_degree_celsius == 2.1_degree_celsius);
    EXPECT_TRUE(1.7_degree_celsius != 2.1_degree_celsius);
    EXPECT_TRUE(1.7_degree_celsius < 2.1_degree_celsius);
    EXPECT_FALSE(1.7_degree_celsius > 2.1_degree_celsius);
    EXPECT_TRUE(1.7_degree_celsius <= 2.1_degree_celsius);
    EXPECT_FALSE(1.7_degree_celsius >= 2.1_degree_celsius);

    EXPECT_TRUE(2.1_degree_celsius == 2.1_degree_celsius);
    EXPECT_FALSE(2.1_degree_celsius != 2.1_degree_celsius);
    EXPECT_FALSE(2.1_degree_celsius < 2.1_degree_celsius);
    EXPECT_FALSE(2.1_degree_celsius > 2.1_degree_celsius);
    EXPECT_TRUE(2.1_degree_celsius <= 2.1_degree_celsius);
    EXPECT_TRUE(2.1_degree_celsius >= 2.1_degree_celsius);
}