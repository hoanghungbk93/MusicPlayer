/**
 * @file MusicPlayerController.cpp
 * @author Hung
 * @brief Implementation of the MusicPlayerController class, responsible for controlling music playback and playlist management.
 * @version 0.2
 * @date 2024-11-22
 * 
 * @details This file contains the implementation of methods to load, play, stop audio files, 
 * and navigate through a playlist using `next` and `back` functionalities.
 * 
 * @contact hch.bkhn@gmail.com
 * 
 * @copyright Copyright (c) 2024
 */

#include "MusicPlayerController.h"
#include <iostream>
#include <filesystem>

/**
 * @brief Constructs a MusicPlayerController object.
 * 
 * Initializes the controller with the provided file manager, audio output, and console view.
 * 
 * @param fileManager Reference to the file manager interface for file operations.
 * @param audioOutput Reference to the audio output interface for playback operations.
 * @param consoleView Reference to the console view interface for user messages.
 */
MusicPlayerController::MusicPlayerController(FileManagerInterface& fileManager, AudioOutputInterface& audioOutput, ConsoleView& consoleView)
    : fileManager(fileManager), audioOutput(audioOutput), consoleView(consoleView) {}

/**
 * @brief Loads a playlist from a specified folder.
 * 
 * Scans the folder for valid audio files using the file manager and adds them to the playlist.
 * If no valid files are found, an error message is displayed.
 * 
 * @param folderPath The path to the folder containing audio files.
 */
void MusicPlayerController::loadFolder(const std::string& folderPath) {
    playlist.clear();
    for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
        if (fileManager.isFileValid(entry.path().string())) {
            playlist.push_back(entry.path().string());
        }
    }

    if (playlist.empty()) {
        consoleView.displayError("No valid files found in the folder: " + folderPath);
    } else {
        currentIndex = 0;
        consoleView.displayMessage("Playlist loaded. Total files: " + std::to_string(playlist.size()));
    }
}

/**
 * @brief Plays the currently selected audio file in the playlist.
 * 
 * If the playlist is not empty and audio output is initialized successfully, this method
 * plays the current file and updates the playing status. Displays messages for success
 * or errors encountered.
 */
void MusicPlayerController::play() {
    if (currentIndex >= 0 && !playlist.empty() && audioOutput.initialize()) {
        if (audioOutput.playSound(playlist[currentIndex])) {
            isPlaying = true;
            consoleView.displayMessage("Playing: " + playlist[currentIndex]);
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
 * Stops the playback and resets the playing status. Displays a confirmation message.
 */
void MusicPlayerController::stop() {
    if (isPlaying) {
        audioOutput.stop();
        isPlaying = false;
        consoleView.displayMessage("Playback stopped.");
    }
}

/**
 * @brief Plays the next audio file in the playlist.
 * 
 * Advances the current index to the next file in the playlist. If the current file
 * is the last in the playlist, the index loops back to the first file. Automatically
 * starts playback of the selected file.
 */
void MusicPlayerController::next() {
    if (!playlist.empty()) {
        currentIndex = (currentIndex + 1) % playlist.size();
        play();
    } else {
        consoleView.displayError("Playlist is empty.");
    }
}

/**
 * @brief Plays the previous audio file in the playlist.
 * 
 * Decreases the current index to the previous file in the playlist. If the current file
 * is the first in the playlist, the index loops back to the last file. Automatically
 * starts playback of the selected file.
 */
void MusicPlayerController::back() {
    if (!playlist.empty()) {
        currentIndex = (currentIndex - 1 + playlist.size()) % playlist.size();
        play();
    } else {
        consoleView.displayError("Playlist is empty.");
    }
}
