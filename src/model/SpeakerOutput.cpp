/**
 * @file SpeakerOutput.cpp
 * @brief Implementation of the SpeakerOutput class for audio playback through speakers.
 * @version 0.1
 * @date 2024-11-22
 * 
 * @details This file implements the methods defined in the SpeakerOutput class,
 * including initializing the speaker output, playing sound, and stopping playback.
 * 
 * @contact hch.bkhn@gmail.com
 * 
 * @author Hung
 * @copyright Copyright (c) 2024
 */

#include "SpeakerOutput.h"
#include <iostream>

/**
 * @brief Initializes the speaker output system.
 * 
 * This method sets up the speaker output for audio playback. It always returns `true` 
 * in this implementation, indicating successful initialization.
 * 
 * @return true Always returns true to indicate successful initialization.
 */
bool SpeakerOutput::initialize() {
    std::cout << "Initializing speaker output." << std::endl;
    return true;
}

/**
 * @brief Plays sound through the speakers.
 * 
 * This method simulates audio playback by outputting a message to the console with 
 * the provided sound data.
 * 
 * @param soundData The audio data to be played through the speakers.
 * @return true Always returns true to indicate successful playback.
 */
bool SpeakerOutput::playSound(const std::string& soundData) {
    std::cout << "Playing sound through speakers: " << soundData << std::endl;
    return true;
}

/**
 * @brief Stops the speaker output.
 * 
 * This method stops any sound currently being played through the speakers and 
 * outputs a message indicating that the playback has been stopped.
 */
void SpeakerOutput::stop() {
    std::cout << "Stopping speaker output." << std::endl;
}
