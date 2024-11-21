#ifndef FILE_MANAGER_PROXY_H
#define FILE_MANAGER_PROXY_H

#include <functional>
#include <string>
#include <vector>
#include "MusicPlayer.h" // Tệp khách hàng gốc

class FileManagerProxy {
public:
    explicit FileManagerProxy(FileManager* realManager) : realManager(realManager) {}

    // Proxy cho `isFileValid`
    bool isFileValid(const std::string& filePath) {
        if (mockIsFileValid) {
            return mockIsFileValid(filePath);
        }
        return realManager->isFileValid(filePath);
    }

    // Proxy cho `getSupportedFormats`
    std::vector<std::string> getSupportedFormats() {
        if (mockGetSupportedFormats) {
            return mockGetSupportedFormats();
        }
        return realManager->getSupportedFormats();
    }

    // Setter cho mock behavior
    void setMockIsFileValid(std::function<bool(const std::string&)> func) {
        mockIsFileValid = func;
    }

    void setMockGetSupportedFormats(std::function<std::vector<std::string>()> func) {
        mockGetSupportedFormats = func;
    }

private:
    FileManager* realManager; // Lớp thật từ khách hàng
    std::function<bool(const std::string&)> mockIsFileValid = nullptr;
    std::function<std::vector<std::string>()> mockGetSupportedFormats = nullptr;
};

#endif // FILE_MANAGER_PROXY_H
