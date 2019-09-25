#include "helpers.h"

#include <benri/chrono.h>
#include <gtest/gtest.h>
using namespace benri::si;

TEST(chrono, implicit_conversions)
{
    EXPECT_BENRI_EQ(decltype(1_seconds_since_system_epoch),
                    2_seconds_since_system_epoch + 5_second,
                    7_seconds_since_system_epoch);
    EXPECT_BENRI_EQ(decltype(1_seconds_since_system_epoch),
                    2_seconds_since_system_epoch - 5_second,
                    -3_seconds_since_system_epoch);
    EXPECT_BENRI_EQ(decltype(1_seconds_since_system_epoch),
                    5_second + 2_seconds_since_system_epoch,
                    7_seconds_since_system_epoch);

    EXPECT_BENRI_EQ(decltype(1_seconds_since_steady_epoch),
                    2_seconds_since_steady_epoch + 5_second,
                    7_seconds_since_steady_epoch);
    EXPECT_BENRI_EQ(decltype(1_seconds_since_steady_epoch),
                    2_seconds_since_steady_epoch - 5_second,
                    -3_seconds_since_steady_epoch);
    EXPECT_BENRI_EQ(decltype(1_seconds_since_steady_epoch),
                    5_second + 2_seconds_since_steady_epoch,
                    7_seconds_since_steady_epoch);

    EXPECT_BENRI_EQ(decltype(1_seconds_since_high_resolution_epoch),
                    2_seconds_since_high_resolution_epoch + 5_second,
                    7_seconds_since_high_resolution_epoch);
    EXPECT_BENRI_EQ(decltype(1_seconds_since_high_resolution_epoch),
                    2_seconds_since_high_resolution_epoch - 5_second,
                    -3_seconds_since_high_resolution_epoch);
    EXPECT_BENRI_EQ(decltype(1_seconds_since_high_resolution_epoch),
                    5_second + 2_seconds_since_high_resolution_epoch,
                    7_seconds_since_high_resolution_epoch);
}
TEST(chrono, constants)
{
    EXPECT_BENRI_EQ(
        decltype(constant::system_epoch), constant::system_epoch,
        benri::simple_cast<decltype(constant::system_epoch)>(symbol::system_epoch));
    EXPECT_BENRI_EQ(
        decltype(constant::steady_epoch), constant::steady_epoch,
        benri::simple_cast<decltype(constant::steady_epoch)>(symbol::steady_epoch));
    EXPECT_BENRI_EQ(decltype(constant::high_resolution_epoch),
                    constant::high_resolution_epoch,
                    benri::simple_cast<decltype(constant::high_resolution_epoch)>(
                        symbol::high_resolution_epoch));
}
TEST(chrono, implicit_chrono_conversions)
{
    EXPECT_BENRI_EQ(decltype(1_seconds_since_system_epoch),
                    2_seconds_since_system_epoch + std::chrono::duration<double>{5},
                    7_seconds_since_system_epoch);
    EXPECT_BENRI_EQ(decltype(1_seconds_since_system_epoch),
                    2_seconds_since_system_epoch - std::chrono::duration<double>{5},
                    -3_seconds_since_system_epoch);
    EXPECT_BENRI_EQ(decltype(1_seconds_since_system_epoch),
                    std::chrono::duration<double>{5} + 2_seconds_since_system_epoch,
                    7_seconds_since_system_epoch);

    EXPECT_BENRI_EQ(decltype(1_seconds_since_steady_epoch),
                    2_seconds_since_steady_epoch + std::chrono::duration<double>{5},
                    7_seconds_since_steady_epoch);
    EXPECT_BENRI_EQ(decltype(1_seconds_since_steady_epoch),
                    2_seconds_since_steady_epoch - std::chrono::duration<double>{5},
                    -3_seconds_since_steady_epoch);
    EXPECT_BENRI_EQ(decltype(1_seconds_since_steady_epoch),
                    std::chrono::duration<double>{5} + 2_seconds_since_steady_epoch,
                    7_seconds_since_steady_epoch);

    EXPECT_BENRI_EQ(decltype(1_seconds_since_high_resolution_epoch),
                    2_seconds_since_high_resolution_epoch
                        + std::chrono::duration<double>{5},
                    7_seconds_since_high_resolution_epoch);
    EXPECT_BENRI_EQ(decltype(1_seconds_since_high_resolution_epoch),
                    2_seconds_since_high_resolution_epoch
                        - std::chrono::duration<double>{5},
                    -3_seconds_since_high_resolution_epoch);
    EXPECT_BENRI_EQ(decltype(1_seconds_since_high_resolution_epoch),
                    std::chrono::duration<double>{5}
                        + 2_seconds_since_high_resolution_epoch,
                    7_seconds_since_high_resolution_epoch);

    EXPECT_BENRI_EQ(decltype(1_seconds_since_system_epoch),
                    fix(std::chrono::time_point<std::chrono::system_clock,
                                                std::chrono::duration<double>>{
                        std::chrono::duration<double>{2}})
                        + 5_second,
                    7_seconds_since_system_epoch);
    EXPECT_BENRI_EQ(decltype(1_seconds_since_system_epoch),
                    fix(std::chrono::time_point<std::chrono::system_clock,
                                                std::chrono::duration<double>>{
                        std::chrono::duration<double>{2}})
                        - 5_second,
                    -3_seconds_since_system_epoch);
    EXPECT_BENRI_EQ(
        decltype(1_seconds_since_system_epoch),
        fix(5_second
            + std::chrono::time_point<
                std::chrono::system_clock,
                std::chrono::duration<double>>{std::chrono::duration<double>{2}}),
        7_seconds_since_system_epoch);

    EXPECT_BENRI_EQ(decltype(1_seconds_since_steady_epoch),
                    fix(std::chrono::time_point<std::chrono::steady_clock,
                                                std::chrono::duration<double>>{
                        std::chrono::duration<double>{2}})
                        + 5_second,
                    7_seconds_since_steady_epoch);
    EXPECT_BENRI_EQ(decltype(1_seconds_since_steady_epoch),
                    fix(std::chrono::time_point<std::chrono::steady_clock,
                                                std::chrono::duration<double>>{
                        std::chrono::duration<double>{2}})
                        - 5_second,
                    -3_seconds_since_steady_epoch);
    EXPECT_BENRI_EQ(
        decltype(1_seconds_since_steady_epoch),
        fix(5_second
            + std::chrono::time_point<
                std::chrono::steady_clock,
                std::chrono::duration<double>>{std::chrono::duration<double>{2}}),
        7_seconds_since_steady_epoch);

    // Test disabled because high_resolution clock might alias onto system_clock or
    // steady_clock, which are not convertible back into high_resolution_clock.
    // EXPECT_BENRI_EQ(decltype(1_seconds_since_high_resolution_epoch),
    //                 fix(std::chrono::time_point<std::chrono::high_resolution_clock,
    //                                             std::chrono::duration<double>>{
    //                     std::chrono::duration<double>{2}})
    //                     + 5_second,
    //                 7_seconds_since_high_resolution_epoch);

    // EXPECT_BENRI_EQ(decltype(1_seconds_since_high_resolution_epoch),
    //                 fix(std::chrono::time_point<std::chrono::high_resolution_clock,
    //                                             std::chrono::duration<double>>{
    //                     std::chrono::duration<double>{2}})
    //                     - 5_second,
    //                 -3_seconds_since_high_resolution_epoch);

    // EXPECT_BENRI_EQ(
    //     decltype(1_seconds_since_high_resolution_epoch),
    //     fix(5_second
    //         + std::chrono::time_point<
    //             std::chrono::high_resolution_clock,
    //             std::chrono::duration<double>>{std::chrono::duration<double>{2}}),
    //     7_seconds_since_high_resolution_epoch);
}