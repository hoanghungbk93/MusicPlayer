#include "HeadphoneOutput.h"
#include <iostream>

bool HeadphoneOutput::initialize() {
    std::cout << "Initializing headphone output." << std::endl;
    return true;
}

bool HeadphoneOutput::playSound(const std::string& soundData) {
    std::cout << "Playing sound through headphones: " << soundData << std::endl;
    return true;
}

void HeadphoneOutput::stop() {
    std::cout << "Stopping headphone output." << std::endl;
}
