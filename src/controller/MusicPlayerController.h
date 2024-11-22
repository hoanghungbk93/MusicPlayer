/**
 * @file MusicPlayerController.h
 * @author Hung
 * @brief Header file for the MusicPlayerController class.
 * @version 0.2
 * @date 2024-11-22
 * 
 * @details This file declares the MusicPlayerController class, which is responsible
 * for managing music playback. It provides methods to load, play, stop audio files, 
 * and navigate through a playlist.
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
#include <vector>

/**
 * @class MusicPlayerController
 * @brief A class for controlling music playback and managing playlists.
 * 
 * The MusicPlayerController class handles interactions between the file manager,
 * audio output, and console view to provide functionalities such as playlist management,
 * playback control, and navigation between audio files.
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
    MusicPlayerController(FileManagerInterface& fileManager, AudioOutputInterface& audioOutput, ConsoleView& consoleView);

    /**
     * @brief Loads a playlist from a specified folder.
     * 
     * This method scans the folder for valid audio files and adds them to the playlist.
     * 
     * @param folderPath The path to the folder containing audio files.
     */
    void loadFolder(const std::string& folderPath);

    /**
     * @brief Plays the currently selected audio file in the playlist.
     * 
     * This method starts playback of the current file if the playlist is not empty
     * and the audio output is successfully initialized.
     */
    void play();

    /**
     * @brief Stops the currently playing audio.
     * 
     * This method stops the playback and resets the playback state.
     */
    void stop();

    /**
     * @brief Plays the next audio file in the playlist.
     * 
     * Advances to the next file in the playlist and starts playback. If the current file
     * is the last in the playlist, it loops back to the first file.
     */
    void next();

    /**
     * @brief Plays the previous audio file in the playlist.
     * 
     * Moves to the previous file in the playlist and starts playback. If the current file
     * is the first in the playlist, it loops back to the last file.
     */
    void back();

private:
    FileManagerInterface& fileManager;  ///< Reference to the file manager for file operations.
    AudioOutputInterface& audioOutput; ///< Reference to the audio output for playback control.
    ConsoleView& consoleView;          ///< Reference to the console view for displaying messages.

    std::vector<std::string> playlist; ///< List of audio files in the playlist.
    int currentIndex = -1;             ///< Index of the currently selected file in the playlist.
    bool isPlaying = false;            ///< Indicates if audio is currently playing.
};

#endif // MUSIC_PLAYER_CONTROLLER_H
