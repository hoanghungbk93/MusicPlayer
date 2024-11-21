#include <gtest/gtest.h>
#include "FileManagerProxy.h"
#include "AudioOutputProxy.h"

TEST(FileManagerProxyTest, TestMockIsFileValid) {
    FileManager realManager;
    FileManagerProxy proxy(&realManager);

    // Thiết lập hành vi mock
    proxy.setMockIsFileValid([](const std::string& filePath) {
        return filePath == "test.mp3";
    });

    EXPECT_TRUE(proxy.isFileValid("test.mp3"));  // Mock behavior
    EXPECT_FALSE(proxy.isFileValid("invalid.wav"));  // Mock behavior
}

TEST(AudioOutputProxyTest, TestMockPlaySound) {
    AudioOutput realOutput;
    AudioOutputProxy proxy(&realOutput);

    // Thiết lập hành vi mock
    proxy.setMockPlaySound([](const std::string& soundData) {
        return soundData == "valid_sound";
    });

    EXPECT_TRUE(proxy.playSound("valid_sound"));  // Mock behavior
    EXPECT_FALSE(proxy.playSound("invalid_sound"));  // Mock behavior
}
