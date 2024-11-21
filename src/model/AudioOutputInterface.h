#ifndef AUDIO_OUTPUT_INTERFACE_H
#define AUDIO_OUTPUT_INTERFACE_H

#include <string>

class AudioOutputInterface {
public:
    virtual bool initialize() = 0;
    virtual bool playSound(const std::string& soundData) = 0;
    virtual void stop() = 0;
    virtual ~AudioOutputInterface() = default;
};

#endif // AUDIO_OUTPUT_INTERFACE_H
