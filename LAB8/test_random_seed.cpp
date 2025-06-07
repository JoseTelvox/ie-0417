#include <gtest/gtest.h>
#include <random>

TEST(RandomTest, FixedSeedProducesExpectedValues) {
    std::mt19937 gen(12345);
    EXPECT_EQ(gen(), 3992670690);
    EXPECT_EQ(gen(), 3245001050);
    EXPECT_EQ(gen(), 3593461620);
    EXPECT_EQ(gen(), 4184046583);
    EXPECT_EQ(gen(), 3446152082);
}
