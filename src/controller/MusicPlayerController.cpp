/**
 * @file MusicPlayerController.cpp
 * @author Hung
 * @brief Implementation of the MusicPlayerController class, responsible for controlling music playback.
 * @version 0.1
 * @date 2024-11-22
 * 
 * @details This file contains the implementation of methods to load, play, and stop audio files.
 * 
 * @contact hch.bkhn@gmail.com
 * 
 * @copyright Copyright (c) 2024
 */

#include "MusicPlayerController.h"
#include <iostream>

/**
 * @brief Loads an audio file into the player.
 * 
 * This function validates the provided file path and sets it as the current file
 * if it is valid. Displays appropriate messages on success or failure.
 * 
 * @param filePath The path to the audio file to be loaded.
 */
void MusicPlayerController::loadFile(const std::string& filePath) {
    if (fileManager.isFileValid(filePath)) {
        currentFile = filePath;
        consoleView.displayMessage("Loaded file: " + currentFile);
    } else {
        consoleView.displayError("Invalid file: " + filePath);
    }
}

/**
 * @brief Plays the currently loaded audio file.
 * 
 * This function checks if a file is loaded and initializes the audio output.
 * If successful, it plays the file and updates the player's status. Displays
 * messages for success or any errors encountered.
 */
void MusicPlayerController::play() {
    if (!currentFile.empty() && audioOutput.initialize()) {
        if (audioOutput.playSound(currentFile)) {
            isPlaying = true;
            consoleView.displayMessage("Playing...");
        } else {
            consoleView.displayError("Failed to play the file.");
        }
    } else {
        consoleView.displayError("No file loaded or failed to initialize.");
    }
}

/**
 * @brief Stops the currently playing audio file.
 * 
 * This function stops the playback and resets the player's status to indicate
 * that no audio is playing. Displays a confirmation message.
 */
void MusicPlayerController::stop() {
    if (isPlaying) {
        audioOutput.stop();
        isPlaying = false;
        consoleView.displayMessage("Stopped.");
    }
}
