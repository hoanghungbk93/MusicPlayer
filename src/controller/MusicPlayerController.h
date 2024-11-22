/**
 * @file MusicPlayerController.h
 * @author Hung
 * @brief Header file for the MusicPlayerController class.
 * @version 0.1
 * @date 2024-11-22
 * 
 * @details This file declares the MusicPlayerController class, which is responsible
 * for managing music playback. It provides methods to load, play, and stop audio files.
 * 
 * @contact hch.bkhn@gmail.com
 * 
 * @copyright Copyright (c) 2024
 */

#ifndef MUSIC_PLAYER_CONTROLLER_H
#define MUSIC_PLAYER_CONTROLLER_H

#include "../model/FileManagerInterface.h"
#include "../model/AudioOutputInterface.h"
#include "../view/ConsoleView.h"
#include <string>

/**
 * @class MusicPlayerController
 * @brief A class for controlling music playback.
 * 
 * The MusicPlayerController class manages interactions between the file manager,
 * audio output, and console view to handle music playback functionalities.
 */
class MusicPlayerController {
public:
    /**
     * @brief Constructs a new MusicPlayerController object.
     * 
     * @param fileManager Reference to the file manager interface for file operations.
     * @param audioOutput Reference to the audio output interface for playback operations.
     * @param consoleView Reference to the console view interface for user messages.
     */
    MusicPlayerController(FileManagerInterface& fileManager, AudioOutputInterface& audioOutput, ConsoleView& consoleView)
        : fileManager(fileManager), audioOutput(audioOutput), consoleView(consoleView) {}

    /**
     * @brief Loads an audio file.
     * 
     * This method validates and sets the specified file as the current file for playback.
     * 
     * @param filePath The path to the audio file to be loaded.
     */
    void loadFile(const std::string& filePath);

    /**
     * @brief Plays the currently loaded audio file.
     * 
     * This method starts audio playback if a valid file is loaded and audio output is initialized.
     */
    void play();

    /**
     * @brief Stops the currently playing audio.
     * 
     * This method stops the playback and resets the playback state.
     */
    void stop();

private:
    FileManagerInterface& fileManager;  ///< Reference to the file manager for file operations.
    AudioOutputInterface& audioOutput; ///< Reference to the audio output for playback control.
    ConsoleView& consoleView;          ///< Reference to the console view for displaying messages.

    std::string currentFile;           ///< Path of the currently loaded file.
    bool isPlaying = false;            ///< Indicates if audio is currently playing.
};

#endif // MUSIC_PLAYER_CONTROLLER_H
