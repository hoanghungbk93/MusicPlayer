#include <gtest/gtest.h>
#include "../../src/model/HeadphoneOutput.h"

TEST(HeadphoneOutputTest, TestInitialize) {
    HeadphoneOutput output;

    EXPECT_TRUE(output.initialize());
}

TEST(HeadphoneOutputTest, TestPlaySound) {
    HeadphoneOutput output;

    EXPECT_TRUE(output.playSound("song.mp3"));
}

TEST(HeadphoneOutputTest, TestStop) {
    HeadphoneOutput output;

    EXPECT_NO_THROW(output.stop());
}
