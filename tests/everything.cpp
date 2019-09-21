#include <gtest/gtest.h>
#include "helpers.h"

#include <benri/si/everything.h>
#include <benri/cmath.h>
using namespace benri::si;

TEST(everything, sakura)
{
    EXPECT_BENRI_EQ(decltype(constant::sakura), constant::sakura, benri::simple_cast<decltype(constant::sakura)>(symbol::sakura));
}