#include <gtest/gtest.h>
#include "helpers.h"

#include <benri/si/base.h>
using namespace benri::si;

TEST(quantity, power_helpers)
{
    EXPECT_BENRI_EQ(decltype(1_metre * metre),                  25_metre * metre,                 square(5_metre) );
    EXPECT_BENRI_EQ(decltype(1_metre * metre * metre),         125_metre * metre * metre,         cubic(5_metre)  );
    EXPECT_BENRI_EQ(decltype(1_metre * metre * metre * metre), 625_metre * metre * metre * metre, quartic(5_metre));
}

TEST(quantity, division_multiplication)
{
    EXPECT_BENRI_EQ(decltype(1_metre / second),  1_metre / second * 1_one,  2_metre / 2_second);
    EXPECT_BENRI_EQ(decltype(1_metre / second),  1_metre / second * 2_one,  2_metre / second);
    EXPECT_BENRI_EQ(decltype(1_metre * second),  2_metre * second,  2_metre * second);
    EXPECT_BENRI_EQ(decltype(1_metre * second),  2_metre * 2_second,  4_metre * second);

    EXPECT_BENRI_EQ(decltype(1_metre / second),  1_metre / second,  2_metre / 2_second);
    EXPECT_BENRI_EQ(decltype(1_metre / second),  2_metre / second,  2_metre / 1_second);
    EXPECT_BENRI_EQ(decltype(1_metre / second),  4_metre / second, 12_metre / 3_second);

    EXPECT_BENRI_EQ(decltype(1_second / metre),  1_second / metre,  2_second / 2_metre);
    EXPECT_BENRI_EQ(decltype(1_second / metre),  2_second / metre,  2_second / 1_metre);
    EXPECT_BENRI_EQ(decltype(1_second / metre),  4_second / metre, 12_second / 3_metre);
    
    EXPECT_BENRI_EQ(decltype(1_one),  1_second / second,  2_second / 2_second);
    EXPECT_BENRI_EQ(decltype(1_one),  2_second / second,  2_second / 1_second);
    EXPECT_BENRI_EQ(decltype(1_one),  4_second / second, 12_second / 3_second);

    EXPECT_BENRI_EQ(decltype(1_one),  1_metre / metre,  2_metre / 2_metre);
    EXPECT_BENRI_EQ(decltype(1_one),  2_metre / metre,  2_metre / 1_metre);
    EXPECT_BENRI_EQ(decltype(1_one),  4_metre / metre, 12_metre / 3_metre);
}

TEST(quantity, addition_subtraction)
{
    EXPECT_BENRI_EQ(decltype(1_metre),  1_metre   + 1_metre,    2_metre);
    EXPECT_BENRI_EQ(decltype(1_metre),  1.7_metre + 0.3_metre,  2_metre);

    EXPECT_BENRI_EQ(decltype(1_metre),  1_metre   - 1_metre,    0_metre  );
    EXPECT_BENRI_EQ(decltype(1_metre),  1.7_metre - 0.3_metre,  1.4_metre);
    EXPECT_BENRI_EQ(decltype(1_metre),  1.2_metre - 8.3_metre, -7.1_metre);
    EXPECT_BENRI_EQ(decltype(1_metre), -1.2_metre - 8.3_metre, -9.5_metre);

    {
        auto value = 1_metre;
        value += 1_metre;
        EXPECT_BENRI_EQ(decltype(1_metre), 2_metre, value);
    }
    {
        auto value = 1.7_metre;
        value += 0.3_metre;
        EXPECT_BENRI_EQ(decltype(1_metre), 2_metre, value);
    }
    {
        auto value = 1_metre;
        value -= 1_metre;
        EXPECT_BENRI_EQ(decltype(1_metre), 0_metre, value);
    }
    {
        auto value = 1.7_metre;
        value -= 0.3_metre;
        EXPECT_BENRI_EQ(decltype(1_metre), 1.4_metre, value);
    }
    {
        auto value = 1.2_metre;
        value -= 8.3_metre;
        EXPECT_BENRI_EQ(decltype(1_metre), -7.1_metre, value);
    }
    {
        auto value = -1.2_metre;
        value -= 8.3_metre;
        EXPECT_BENRI_EQ(decltype(1_metre), -9.5_metre, value);
    }
}

TEST(quantity, user_defined_literals)
{
    EXPECT_BENRI_EQ(decltype(1_metre),  1.0_metre,  1_metre  );
    EXPECT_BENRI_EQ(decltype(1_metre),  1.2_metre,  1.2_metre);
    EXPECT_BENRI_EQ(decltype(1_metre), -7.0_metre, -7_metre  );
    EXPECT_BENRI_EQ(decltype(1_metre), -7.1_metre, -7.1_metre);

    EXPECT_BENRI_EQ(decltype(1_metre),  benri::quantity<metre_t>{1.0},  1_metre  );
    EXPECT_BENRI_EQ(decltype(1_metre),  benri::quantity<metre_t>{1.2},  1.2_metre);
    EXPECT_BENRI_EQ(decltype(1_metre), benri::quantity<metre_t>{-7.0}, -7_metre  );
    EXPECT_BENRI_EQ(decltype(1_metre), benri::quantity<metre_t>{-7.1}, -7.1_metre);
}

TEST(quantity, comparison)
{
    EXPECT_FALSE(1.7_metre == 2.1_metre);
    EXPECT_TRUE(1.7_metre != 2.1_metre);
    EXPECT_TRUE(1.7_metre <  2.1_metre);
    EXPECT_FALSE(1.7_metre >  2.1_metre);
    EXPECT_TRUE(1.7_metre <= 2.1_metre);
    EXPECT_FALSE(1.7_metre >= 2.1_metre);

    EXPECT_TRUE(2.1_metre == 2.1_metre);
    EXPECT_FALSE(2.1_metre != 2.1_metre);
    EXPECT_FALSE(2.1_metre <  2.1_metre);
    EXPECT_FALSE(2.1_metre >  2.1_metre);
    EXPECT_TRUE(2.1_metre <= 2.1_metre);
    EXPECT_TRUE(2.1_metre >= 2.1_metre);
}