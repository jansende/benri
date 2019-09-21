#include "helpers.h"

#include <benri/cmath.h>
#include <benri/si/everything.h>
#include <gtest/gtest.h>
using namespace benri::si;

TEST(everything, sakura)
{
    EXPECT_BENRI_EQ(decltype(constant::sakura), constant::sakura,
                    benri::simple_cast<decltype(constant::sakura)>(symbol::sakura));
}