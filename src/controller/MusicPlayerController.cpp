#include "MusicPlayerController.h"
#include <iostream>

void MusicPlayerController::loadFile(const std::string& filePath) {
    if (fileManager.isFileValid(filePath)) {
        currentFile = filePath;
        consoleView.displayMessage("Loaded file: " + currentFile);
    } else {
        consoleView.displayError("Invalid file: " + filePath);
    }
}

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

void MusicPlayerController::stop() {
    if (isPlaying) {
        audioOutput.stop();
        isPlaying = false;
        consoleView.displayMessage("Stopped.");
    }
}
