#include <gtest/gtest.h>
#include "../../src/model/Mp3FileManager.h"

TEST(Mp3FileManagerTest, TestIsFileValid) {
    Mp3FileManager fileManager;

    EXPECT_TRUE(fileManager.isFileValid("song.mp3"));
    EXPECT_FALSE(fileManager.isFileValid("video.mp4"));
}

TEST(Mp3FileManagerTest, TestGetSupportedFormats) {
    Mp3FileManager fileManager;

    auto formats = fileManager.getSupportedFormats();
    EXPECT_EQ(formats.size(), 1);
    EXPECT_EQ(formats[0], "mp3");
}
