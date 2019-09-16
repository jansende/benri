#pragma once

#define EXPECT_BENRI_EQ(benri, val1, val2)\
  EXPECT_DOUBLE_EQ((benri{val1}.value()),\
                   (benri{val2}.value()))
#define ASSERT_BENRI_EQ(benri, val1, val2)\
  ASSERT_DOUBLE_EQ((benri{val1}.value()),\
                   (benri{val2}.value()))