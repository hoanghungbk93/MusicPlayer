#include <gtest/gtest.h>
#include "controller/MusicPlayerController.h"
#include "model/FileManagerProxy.h"
#include "model/AudioOutputProxy.h"
#include "model/Mp3FileManager.h"
#include "model/HeadphoneOutput.h"
#include "view/ConsoleView.h"

TEST(MusicPlayerControllerTest, TestLoadFileValid) {
    // Khởi tạo đối tượng thực
    Mp3FileManager realFileManager;
    FileManagerProxy fileManagerProxy(&realFileManager);

    // Mock hành vi của isFileValid
    fileManagerProxy.setMockIsFileValid([](const std::string& filePath) {
        return filePath == "valid.mp3";
    });

    HeadphoneOutput realAudioOutput;
    ConsoleView consoleView;

    // Tạo controller với proxy
    MusicPlayerController controller(fileManagerProxy, realAudioOutput, consoleView);

    // Kiểm tra tệp hợp lệ
    controller.loadFile("valid.mp3");
    // Không hợp lệ
    controller.loadFile("invalid.mp4");
}

TEST(MusicPlayerControllerTest, TestPlayAndStopWithMockedAudio) {
    Mp3FileManager realFileManager;
    FileManagerProxy fileManagerProxy(&realFileManager);

    // Không cần mock FileManager, dùng trực tiếp đối tượng thực

    HeadphoneOutput realAudioOutput;
    AudioOutputProxy audioProxy(&realAudioOutput);

    // Mock hành vi của AudioOutput
    audioProxy.setMockInitialize([]() {
        return true; // Giả lập khởi tạo thành công
    });

    audioProxy.setMockPlaySound([](const std::string& soundData) {
        return soundData == "song.mp3"; // Chỉ phát âm thanh với tệp "song.mp3"
    });

    audioProxy.setMockStop([]() {
        // Có thể thêm logic giả lập nếu cần
    });

    ConsoleView consoleView;

    // Tạo controller với proxy
    MusicPlayerController controller(fileManagerProxy, audioProxy, consoleView);

    // Tải tệp và phát
    controller.loadFile("song.mp3");
    controller.play();
    controller.stop();
}

TEST(MusicPlayerControllerTest, TestPlayInvalidFile) {
    Mp3FileManager realFileManager;
    FileManagerProxy fileManagerProxy(&realFileManager);

    // Không cần mock FileManager, dùng trực tiếp đối tượng thực

    HeadphoneOutput realAudioOutput;
    AudioOutputProxy audioProxy(&realAudioOutput);

    // Mock AudioOutput cho trường hợp tệp không hợp lệ
    audioProxy.setMockInitialize([]() {
        return true; // Giả lập khởi tạo thành công
    });

    audioProxy.setMockPlaySound([](const std::string& soundData) {
        return false; // Không thể phát tệp không hợp lệ
    });

    ConsoleView consoleView;

    // Tạo controller với proxy
    MusicPlayerController controller(fileManagerProxy, audioProxy, consoleView);

    // Tải tệp không hợp lệ và thử phát
    controller.loadFile("invalid.mp4");
    controller.play();
}
