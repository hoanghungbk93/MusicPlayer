#ifndef MP4_FILE_MANAGER_H
#define MP4_FILE_MANAGER_H

#include "FileManagerInterface.h"

class Mp4FileManager : public FileManagerInterface {
public:
    bool isFileValid(const std::string& filePath) const override;
    std::vector<std::string> getSupportedFormats() const override;
};

#endif // MP4_FILE_MANAGER_H
