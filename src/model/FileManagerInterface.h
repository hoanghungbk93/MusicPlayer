#ifndef FILE_MANAGER_INTERFACE_H
#define FILE_MANAGER_INTERFACE_H

#include <string>
#include <vector>

class FileManagerInterface {
public:
    virtual bool isFileValid(const std::string& filePath) const = 0;
    virtual std::vector<std::string> getSupportedFormats() const = 0;
    virtual ~FileManagerInterface() = default;
};

#endif // FILE_MANAGER_INTERFACE_H
