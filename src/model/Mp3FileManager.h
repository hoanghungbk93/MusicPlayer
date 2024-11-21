#ifndef MP3_FILE_MANAGER_H
#define MP3_FILE_MANAGER_H

#include "FileManagerInterface.h"

class Mp3FileManager : public FileManagerInterface {
public:
    bool isFileValid(const std::string& filePath) const override;
    std::vector<std::string> getSupportedFormats() const override;
};

#endif // MP3_FILE_MANAGER_H
