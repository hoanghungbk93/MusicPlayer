#include "model/Mp3FileManager.h"
#include "model/Mp4FileManager.h"
#include "model/HeadphoneOutput.h"
#include "model/SpeakerOutput.h"
#include "controller/MusicPlayerController.h"
#include "view/ConsoleView.h"
#include <iostream>
#include <memory>

int main() {
    // Chọn kiểu FileManager: Mp3 hoặc Mp4
    std::unique_ptr<FileManagerInterface> fileManager = std::make_unique<Mp3FileManager>();

    // Chọn kiểu AudioOutput: Headphone hoặc Speaker
    std::unique_ptr<AudioOutputInterface> audioOutput = std::make_unique<SpeakerOutput>();

    // Tạo giao diện hiển thị
    ConsoleView consoleView;

    // Tạo controller với các thành phần đã chọn
    MusicPlayerController controller(*fileManager, *audioOutput, consoleView);

    // Thực hiện các hành động
    std::string filePath = "song.mp3";

    std::cout << "Loading file: " << filePath << std::endl;
    controller.loadFile(filePath);

    std::cout << "Playing file..." << std::endl;
    controller.play();

    std::cout << "Stopping playback..." << std::endl;
    controller.stop();

    return 0;
}
