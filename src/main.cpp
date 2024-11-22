/**
 * @file main.cpp
 * @brief Entry point of the Music Player application.
 * @version 0.1
 * @date 2024-11-22
 * 
 * @mainpage MusicPlayer Application
 *
 * @section intro_sec Introduction
 *
 * The MusicPlayer application demonstrates file management, audio output, and unit testing using Google Test and Google Mock.
 * It showcases how various components, such as `MusicPlayerController`, `Mp3FileManager`, and `SpeakerOutput`, work together.
 *
 * @section build_sec How to Build
 *
 * 1. Clone the repository.
 * 2. Create a `build` directory: `mkdir build && cd build`.
 * 3. Run CMake: `cmake ..`.
 * 4. Build the project: `make`.
 *
 * @section usage_sec How to Use
 *
 * - Run the main program: `./MusicPlayer`
 * - Run the unit tests: `./MusicPlayerTest`
 *
 * @section doc_sec Documentation
 *
 * The generated documentation provides an overview of the classes, methods, and tests in the MusicPlayer application.
 * 
 * @details This file contains the main function for the Music Player application.
 * It demonstrates how to use the `MusicPlayerController` with various components 
 * like `Mp3FileManager`, `SpeakerOutput`, and `ConsoleView`.
 * 
 * @author HungHC
 * @contact hch.bkhn@gmail.com
 * @copyright Copyright (c) 2024
 */


#include "model/Mp3FileManager.h"
#include "model/Mp4FileManager.h"
#include "model/HeadphoneOutput.h"
#include "model/SpeakerOutput.h"
#include "controller/MusicPlayerController.h"
#include "view/ConsoleView.h"
#include <iostream>
#include <memory>

int main() {
    // Choose a FileManager: Mp3FileManager for handling MP3 files
    std::unique_ptr<FileManagerInterface> fileManager = std::make_unique<Mp3FileManager>();

    // Choose an AudioOutput: SpeakerOutput for playback through speakers
    std::unique_ptr<AudioOutputInterface> audioOutput = std::make_unique<SpeakerOutput>();

    // Create the console interface for user messages
    ConsoleView consoleView;

    // Create the MusicPlayerController with the selected components
    MusicPlayerController controller(*fileManager, *audioOutput, consoleView);

    // Specify the file path to load
    std::string filePath = "song.mp3";

    // Load the file
    std::cout << "Loading file: " << filePath << std::endl;
    controller.loadFile(filePath);

    // Play the loaded file
    std::cout << "Playing file..." << std::endl;
    controller.play();

    // Stop playback
    std::cout << "Stopping playback..." << std::endl;
    controller.stop();

    return 0;
}
