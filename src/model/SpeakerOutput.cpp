#include "SpeakerOutput.h"

bool SpeakerOutput::initialize() {
    std::cout << "Initializing speaker output." << std::endl;
    return true;
}

bool SpeakerOutput::playSound(const std::string& soundData) {
    std::cout << "Playing sound through speakers: " << soundData << std::endl;
    return true;
}

void SpeakerOutput::stop() {
    std::cout << "Stopping speaker output." << std::endl;
}
