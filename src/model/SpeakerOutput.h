/**
 * @file SpeakerOutput.h
 * @brief Declaration of the SpeakerOutput class for audio playback through speakers.
 * @version 0.1
 * @date 2024-11-22
 * 
 * @details This file defines the SpeakerOutput class, which implements the 
 * AudioOutputInterface to provide methods for initializing the speaker system, 
 * playing sound, and stopping audio playback.
 * 
 * @contact hch.bkhn@gmail.com
 * 
 * @author HungHC
 * @copyright Copyright (c) 2024
 */

#ifndef SPEAKER_OUTPUT_H
#define SPEAKER_OUTPUT_H

#include "AudioOutputInterface.h"
#include <iostream>

/**
 * @class SpeakerOutput
 * @brief A concrete implementation of AudioOutputInterface for speaker output.
 * 
 * The SpeakerOutput class provides functionality to initialize the audio system,
 * play sound through speakers, and stop audio playback.
 */
class SpeakerOutput : public AudioOutputInterface {
public:
    /**
     * @brief Initializes the speaker output system.
     * 
     * This method sets up the speaker output for audio playback.
     * 
     * @return True if the initialization is successful.
     */
    bool initialize() override;

    /**
     * @brief Plays sound through the speakers.
     * 
     * This method accepts audio data in string format and plays it through the speaker output.
     * 
     * @param soundData The audio data to be played.
     * @return True if the sound is successfully played.
     */
    bool playSound(const std::string& soundData) override;

    /**
     * @brief Stops the speaker output.
     * 
     * This method stops any ongoing audio playback through the speakers.
     */
    void stop() override;
};

#endif // SPEAKER_OUTPUT_H
