#include <gtest/gtest.h>
#include "../../src/model/Mp4FileManager.h"

TEST(Mp4FileManagerTest, TestIsFileValid) {
    Mp4FileManager fileManager;

    EXPECT_TRUE(fileManager.isFileValid("video.mp4"));
    EXPECT_FALSE(fileManager.isFileValid("song.mp3"));
}

TEST(Mp4FileManagerTest, TestGetSupportedFormats) {
    Mp4FileManager fileManager;

    auto formats = fileManager.getSupportedFormats();
    EXPECT_EQ(formats.size(), 1);
    EXPECT_EQ(formats[0], "mp4");
}
