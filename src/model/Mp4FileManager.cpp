#include "Mp4FileManager.h"

bool Mp4FileManager::isFileValid(const std::string& filePath) const {
    return filePath.find(".mp4") != std::string::npos;
}

std::vector<std::string> Mp4FileManager::getSupportedFormats() const {
    return {"mp4"};
}
