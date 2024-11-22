/**
 * @file HeadphoneOutput.cpp
 * @author Hung
 * @brief Implementation of the HeadphoneOutput class for audio playback through headphones.
 * @version 0.1
 * @date 2024-11-22
 * 
 * @details This file implements the methods defined in the HeadphoneOutput class,
 * including initializing the headphone output, playing sound, and stopping playback.
 * 
 * @contact hch.bkhn@gmail.com
 * 
 * @copyright Copyright (c) 2024
 */

#include "HeadphoneOutput.h"
#include <iostream>

/**
 * @brief Initializes the headphone output system.
 * 
 * This method sets up the headphone output for playback. It always returns `true` 
 * in this implementation, indicating successful initialization.
 * 
 * @return true Always returns true to indicate successful initialization.
 */
bool HeadphoneOutput::initialize() {
    std::cout << "Initializing headphone output." << std::endl;
    return true;
}

/**
 * @brief Plays sound through the headphones.
 * 
 * This method simulates audio playback by outputting a message to the console with 
 * the provided sound data.
 * 
 * @param soundData The audio data to be played through the headphones.
 * @return true Always returns true to indicate successful playback.
 */
bool HeadphoneOutput::playSound(const std::string& soundData) {
    std::cout << "Playing sound through headphones: " << soundData << std::endl;
    return true;
}

/**
 * @brief Stops the headphone output.
 * 
 * This method stops the audio playback and outputs a message indicating that the 
 * headphone output has been stopped.
 */
void HeadphoneOutput::stop() {
    std::cout << "Stopping headphone output." << std::endl;
}
