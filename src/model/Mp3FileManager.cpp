#include "Mp3FileManager.h"

bool Mp3FileManager::isFileValid(const std::string& filePath) const {
    return filePath.find(".mp3") != std::string::npos;
}

std::vector<std::string> Mp3FileManager::getSupportedFormats() const {
    return {"mp3"};
}
