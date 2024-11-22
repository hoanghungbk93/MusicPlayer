/**
 * @file HeadphoneOutput.h
 * @brief Declaration of the HeadphoneOutput class for audio playback through headphones.
 * @version 0.1
 * @date 2024-11-22
 * 
 * @details This file defines the HeadphoneOutput class, which implements the 
 * AudioOutputInterface to provide methods for initializing, playing sound, 
 * and stopping audio output through headphones.
 * 
 * @author HungHC
 * @contact hch.bkhn@gmail.com
 * 
 * @copyright Copyright (c) 2024
 */

#ifndef HEADPHONE_OUTPUT_H
#define HEADPHONE_OUTPUT_H

#include "AudioOutputInterface.h"
#include <iostream>

/**
 * @class HeadphoneOutput
 * @brief A concrete implementation of AudioOutputInterface for headphone output.
 * 
 * The HeadphoneOutput class provides functionality to initialize the audio system,
 * play sound through headphones, and stop audio playback.
 */
class HeadphoneOutput : public AudioOutputInterface {
public:
    /**
     * @brief Initializes the headphone output system.
     * 
     * This method sets up the headphone output for audio playback.
     * 
     * @return True if the initialization is successful.
     */
    bool initialize() override;

    /**
     * @brief Plays sound through the headphones.
     * 
     * This method accepts audio data in string format and plays it through the headphone output.
     * 
     * @param soundData The audio data to be played.
     * @return True if the sound is successfully played.
     */
    bool playSound(const std::string& soundData) override;

    /**
     * @brief Stops the headphone output.
     * 
     * This method stops any ongoing audio playback through the headphones.
     */
    void stop() override;
};

#endif // HEADPHONE_OUTPUT_H
