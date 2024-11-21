#ifndef SPEAKER_OUTPUT_H
#define SPEAKER_OUTPUT_H

#include "AudioOutputInterface.h"
#include <iostream>

class SpeakerOutput : public AudioOutputInterface {
public:
    bool initialize() override;
    bool playSound(const std::string& soundData) override;
    void stop() override;
};

#endif // SPEAKER_OUTPUT_H
