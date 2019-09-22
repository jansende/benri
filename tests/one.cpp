#include "helpers.h"

#include <benri/si/base.h>
#include <gtest/gtest.h>
using namespace benri::si;

TEST(one, power_helpers)
{
    EXPECT_BENRI_EQ(decltype(1_one * one), 25_one * one, square(5_one));
    EXPECT_BENRI_EQ(decltype(1_one * one * one), 125_one * one * one, cubic(5_one));
    EXPECT_BENRI_EQ(decltype(1_one * one * one * one), 625_one * one * one * one,
                    quartic(5_one));
}

TEST(one, division_multiplication)
{
    EXPECT_BENRI_EQ(decltype(1_one), 1_one / one, 2_one / 2_one);
    EXPECT_BENRI_EQ(decltype(1_one), 2_one / one, 2_one / 1_one);
    EXPECT_BENRI_EQ(decltype(1_one), 4_one / one, 12_one / 3_one);

    EXPECT_BENRI_EQ(decltype(1_one), 1_one * 4_one, 2_one * 2_one);
    EXPECT_BENRI_EQ(decltype(1_one), 1_one * 2_one, 2_one * 1_one);
    EXPECT_BENRI_EQ(decltype(1_one), 4_one * 9_one, 12_one * 3_one);
}

TEST(one, addition_subtraction)
{
    EXPECT_BENRI_EQ(decltype(1_one), 1_one + 1_one, 2_one);
    EXPECT_BENRI_EQ(decltype(1_one), 1.7_one + 0.3_one, 2_one);

    EXPECT_BENRI_EQ(decltype(1_one), 1.0 + 1_one, 2_one);
    EXPECT_BENRI_EQ(decltype(1_one), 1.7 + 0.3_one, 2_one);

    EXPECT_BENRI_EQ(decltype(1_one), 1_one + 1.0, 2_one);
    EXPECT_BENRI_EQ(decltype(1_one), 1.7_one + 0.3, 2_one);

    EXPECT_BENRI_EQ(decltype(1_one), 1_one - 1_one, 0_one);
    EXPECT_BENRI_EQ(decltype(1_one), 1.7_one - 0.3_one, 1.4_one);
    EXPECT_BENRI_EQ(decltype(1_one), 1.2_one - 8.3_one, -7.1_one);
    EXPECT_BENRI_EQ(decltype(1_one), -1.2_one - 8.3_one, -9.5_one);

    EXPECT_BENRI_EQ(decltype(1_one), 1.0 - 1_one, 0_one);
    EXPECT_BENRI_EQ(decltype(1_one), 1.7 - 0.3_one, 1.4_one);
    EXPECT_BENRI_EQ(decltype(1_one), 1.2 - 8.3_one, -7.1_one);
    EXPECT_BENRI_EQ(decltype(1_one), -1.2 - 8.3_one, -9.5_one);

    EXPECT_BENRI_EQ(decltype(1_one), 1_one - 1.0, 0_one);
    EXPECT_BENRI_EQ(decltype(1_one), 1.7_one - 0.3, 1.4_one);
    EXPECT_BENRI_EQ(decltype(1_one), 1.2_one - 8.3, -7.1_one);
    EXPECT_BENRI_EQ(decltype(1_one), -1.2_one - 8.3, -9.5_one);

    {
        auto value = 1_one;
        value += 1_one;
        EXPECT_BENRI_EQ(decltype(1_one), 2_one, value);
    }
    {
        auto value = 1.7_one;
        value += 0.3_one;
        EXPECT_BENRI_EQ(decltype(1_one), 2_one, value);
    }
    {
        auto value = 1_one;
        value -= 1_one;
        EXPECT_BENRI_EQ(decltype(1_one), 0_one, value);
    }
    {
        auto value = 1.7_one;
        value -= 0.3_one;
        EXPECT_BENRI_EQ(decltype(1_one), 1.4_one, value);
    }
    {
        auto value = 1.2_one;
        value -= 8.3_one;
        EXPECT_BENRI_EQ(decltype(1_one), -7.1_one, value);
    }
    {
        auto value = -1.2_one;
        value -= 8.3_one;
        EXPECT_BENRI_EQ(decltype(1_one), -9.5_one, value);
    }

    {
        auto value = 1_one;
        value += 1.0;
        EXPECT_BENRI_EQ(decltype(1_one), 2_one, value);
    }
    {
        auto value = 1.7_one;
        value += 0.3;
        EXPECT_BENRI_EQ(decltype(1_one), 2_one, value);
    }
    {
        auto value = 1_one;
        value -= 1.0;
        EXPECT_BENRI_EQ(decltype(1_one), 0_one, value);
    }
    {
        auto value = 1.7_one;
        value -= 0.3;
        EXPECT_BENRI_EQ(decltype(1_one), 1.4_one, value);
    }
    {
        auto value = 1.2_one;
        value -= 8.3;
        EXPECT_BENRI_EQ(decltype(1_one), -7.1_one, value);
    }
    {
        auto value = -1.2_one;
        value -= 8.3;
        EXPECT_BENRI_EQ(decltype(1_one), -9.5_one, value);
    }
}

TEST(one, user_defined_literals)
{
    EXPECT_BENRI_EQ(decltype(1_one), 1.0, 1_one);
    EXPECT_BENRI_EQ(decltype(1_one), 1.2, 1.2_one);
    EXPECT_BENRI_EQ(decltype(1_one), -7.0, -7_one);
    EXPECT_BENRI_EQ(decltype(1_one), -7.1, -7.1_one);

    EXPECT_BENRI_EQ(decltype(1_one), 1.0_one, 1_one);
    EXPECT_BENRI_EQ(decltype(1_one), 1.2_one, 1.2_one);
    EXPECT_BENRI_EQ(decltype(1_one), -7.0_one, -7_one);
    EXPECT_BENRI_EQ(decltype(1_one), -7.1_one, -7.1_one);

    EXPECT_BENRI_EQ(decltype(1_one), benri::quantity<one_t>{1.0}, 1_one);
    EXPECT_BENRI_EQ(decltype(1_one), benri::quantity<one_t>{1.2}, 1.2_one);
    EXPECT_BENRI_EQ(decltype(1_one), benri::quantity<one_t>{-7.0}, -7_one);
    EXPECT_BENRI_EQ(decltype(1_one), benri::quantity<one_t>{-7.1}, -7.1_one);
}

TEST(one, comparison)
{
    EXPECT_FALSE(1.7_one == 2.1_one);
    EXPECT_TRUE(1.7_one != 2.1_one);
    EXPECT_TRUE(1.7_one < 2.1_one);
    EXPECT_FALSE(1.7_one > 2.1_one);
    EXPECT_TRUE(1.7_one <= 2.1_one);
    EXPECT_FALSE(1.7_one >= 2.1_one);

    EXPECT_FALSE(1.7 == 2.1_one);
    EXPECT_TRUE(1.7 != 2.1_one);
    EXPECT_TRUE(1.7 < 2.1_one);
    EXPECT_FALSE(1.7 > 2.1_one);
    EXPECT_TRUE(1.7 <= 2.1_one);
    EXPECT_FALSE(1.7 >= 2.1_one);

    EXPECT_FALSE(1.7_one == 2.1);
    EXPECT_TRUE(1.7_one != 2.1);
    EXPECT_TRUE(1.7_one < 2.1);
    EXPECT_FALSE(1.7_one > 2.1);
    EXPECT_TRUE(1.7_one <= 2.1);
    EXPECT_FALSE(1.7_one >= 2.1);

    EXPECT_TRUE(2.1_one == 2.1_one);
    EXPECT_FALSE(2.1_one != 2.1_one);
    EXPECT_FALSE(2.1_one < 2.1_one);
    EXPECT_FALSE(2.1_one > 2.1_one);
    EXPECT_TRUE(2.1_one <= 2.1_one);
    EXPECT_TRUE(2.1_one >= 2.1_one);

    EXPECT_TRUE(2.1 == 2.1_one);
    EXPECT_FALSE(2.1 != 2.1_one);
    EXPECT_FALSE(2.1 < 2.1_one);
    EXPECT_FALSE(2.1 > 2.1_one);
    EXPECT_TRUE(2.1 <= 2.1_one);
    EXPECT_TRUE(2.1 >= 2.1_one);

    EXPECT_TRUE(2.1_one == 2.1);
    EXPECT_FALSE(2.1_one != 2.1);
    EXPECT_FALSE(2.1_one < 2.1);
    EXPECT_FALSE(2.1_one > 2.1);
    EXPECT_TRUE(2.1_one <= 2.1);
    EXPECT_TRUE(2.1_one >= 2.1);
}