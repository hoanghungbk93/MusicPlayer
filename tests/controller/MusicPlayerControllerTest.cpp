#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "controller/MusicPlayerController.h"
#include "model/FileManagerInterface.h"
#include "model/AudioOutputInterface.h"
#include "view/ConsoleView.h"

/**
 * @class MockFileManager
 * @brief Mock implementation of FileManagerInterface for testing.
 */
class MockFileManager : public FileManagerInterface {
public:
    MOCK_METHOD(bool, isFileValid, (const std::string& filePath), (const, override));
    MOCK_METHOD(std::vector<std::string>, getSupportedFormats, (), (const, override));
};

/**
 * @class MockAudioOutput
 * @brief Mock implementation of AudioOutputInterface for testing.
 */
class MockAudioOutput : public AudioOutputInterface {
public:
    MOCK_METHOD(bool, initialize, (), (override));
    MOCK_METHOD(bool, playSound, (const std::string& soundData), (override));
    MOCK_METHOD(void, stop, (), (override));
};

/**
 * @class MockConsoleView
 * @brief Mock implementation of ConsoleView for testing.
 */
class MockConsoleView : public ConsoleView {
public:
    // MOCK_METHOD(void, displayMessage, (const std::string& message), (override));
    // MOCK_METHOD(void, displayError, (const std::string& error), (override));
};

/**
 * @test Tests the loading of a playlist from a folder.
 */
TEST(MusicPlayerControllerTest, LoadFolder) {
    MockFileManager mockFileManager;
    MockAudioOutput mockAudioOutput;
    MockConsoleView mockConsoleView;

    EXPECT_CALL(mockFileManager, isFileValid(testing::_))
        .WillRepeatedly(testing::Return(true));

    MusicPlayerController controller(mockFileManager, mockAudioOutput, mockConsoleView);

    // EXPECT_CALL(mockConsoleView, displayMessage(testing::Contains("Playlist loaded")));
    controller.loadFolder("test_folder");
}

/**
 * @test Tests the "next" function to play the next track.
 */
TEST(MusicPlayerControllerTest, NextTrack) {
    MockFileManager mockFileManager;
    MockAudioOutput mockAudioOutput;
    MockConsoleView mockConsoleView;

    EXPECT_CALL(mockFileManager, isFileValid(testing::_))
        .WillRepeatedly(testing::Return(true));
    EXPECT_CALL(mockAudioOutput, initialize())
        .WillRepeatedly(testing::Return(true));
    EXPECT_CALL(mockAudioOutput, playSound(testing::_))
        .WillRepeatedly(testing::Return(true));

    MusicPlayerController controller(mockFileManager, mockAudioOutput, mockConsoleView);

    controller.loadFolder("test_folder");
    controller.play();

    controller.next(); // Expect next track
}

/**
 * @test Tests the "back" function to play the previous track.
 */
TEST(MusicPlayerControllerTest, PreviousTrack) {
    MockFileManager mockFileManager;
    MockAudioOutput mockAudioOutput;
    MockConsoleView mockConsoleView;

    EXPECT_CALL(mockFileManager, isFileValid(testing::_))
        .WillRepeatedly(testing::Return(true));
    EXPECT_CALL(mockAudioOutput, initialize())
        .WillRepeatedly(testing::Return(true));
    EXPECT_CALL(mockAudioOutput, playSound(testing::_))
        .WillRepeatedly(testing::Return(true));

    MusicPlayerController controller(mockFileManager, mockAudioOutput, mockConsoleView);

    controller.loadFolder("test_folder");
    controller.play();

    controller.back(); // Expect previous track
}
