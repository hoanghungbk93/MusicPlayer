#include <gtest/gtest.h>
#include "../../src/model/SpeakerOutput.h"

TEST(SpeakerOutputTest, TestInitialize) {
    SpeakerOutput output;

    EXPECT_TRUE(output.initialize());
}

TEST(SpeakerOutputTest, TestPlaySound) {
    SpeakerOutput output;

    EXPECT_TRUE(output.playSound("song.mp3"));
}

TEST(SpeakerOutputTest, TestStop) {
    SpeakerOutput output;

    EXPECT_NO_THROW(output.stop());
}
