#ifndef HEADPHONE_OUTPUT_H
#define HEADPHONE_OUTPUT_H

#include "AudioOutputInterface.h"
#include <iostream>

class HeadphoneOutput : public AudioOutputInterface {
public:
    bool initialize() override;
    bool playSound(const std::string& soundData) override;
    void stop() override;
};

#endif // HEADPHONE_OUTPUT_H
