/**
 * @file AudioOutputInterface.h
 * @author HungHC
 * @brief Declaration of the AudioOutputInterface class.
 * @version 0.1
 * @date 2024-11-22
 * 
 * @details This file defines an abstract interface for audio output operations.
 * Implementing classes must provide methods to initialize the audio system, play sounds,
 * and stop playback.
 * 
 * @contact hch.bkhn@gmail.com
 * 
 * @copyright Copyright (c) 2024
 */

#ifndef AUDIO_OUTPUT_INTERFACE_H
#define AUDIO_OUTPUT_INTERFACE_H

#include <string>

/**
 * @class AudioOutputInterface
 * @brief An interface for managing audio output operations.
 * 
 * This abstract class defines methods for initializing the audio output, playing sound, 
 * and stopping playback. It serves as a base for different audio output implementations.
 */
class AudioOutputInterface {
public:
    /**
     * @brief Initializes the audio output system.
     * 
     * This method sets up the necessary resources for audio playback.
     * 
     * @return True if initialization is successful, false otherwise.
     */
    virtual bool initialize() = 0;

    /**
     * @brief Plays the specified sound.
     * 
     * This method takes sound data and plays it through the audio output system.
     * 
     * @param soundData The data representing the sound to be played.
     * @return True if the sound is played successfully, false otherwise.
     */
    virtual bool playSound(const std::string& soundData) = 0;

    /**
     * @brief Stops the audio playback.
     * 
     * This method stops any sound currently being played.
     */
    virtual void stop() = 0;

    /**
     * @brief Virtual destructor.
     * 
     * Ensures proper cleanup of derived classes when deleted through a pointer to this interface.
     */
    virtual ~AudioOutputInterface() = default;
};

#endif // AUDIO_OUTPUT_INTERFACE_H
