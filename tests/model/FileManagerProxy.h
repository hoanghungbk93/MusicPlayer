#ifndef FILE_MANAGER_PROXY_H
#define FILE_MANAGER_PROXY_H

#include "../../src/model/FileManagerInterface.h"
#include <functional>

class FileManagerProxy : public FileManagerInterface {
public:
    /**
     * Constructor nhận vào một đối tượng FileManagerInterface thực.
     * @param realManager Đối tượng FileManagerInterface thực sự.
     */
    explicit FileManagerProxy(FileManagerInterface* realManager) 
        : realManager(realManager) {}

    /**
     * Kiểm tra tính hợp lệ của tệp bằng cách sử dụng mock hoặc gọi đối tượng thực.
     * @param filePath Đường dẫn tệp.
     * @return true nếu tệp hợp lệ, false nếu không.
     */
    bool isFileValid(const std::string& filePath) const override {
        if (mockIsFileValid) {
            return mockIsFileValid(filePath);
        }
        return realManager->isFileValid(filePath);
    }

    /**
     * Lấy danh sách các định dạng tệp được hỗ trợ bằng cách sử dụng mock hoặc gọi đối tượng thực.
     * @return Danh sách các định dạng dưới dạng vector string.
     */
    std::vector<std::string> getSupportedFormats() const override {
        if (mockGetSupportedFormats) {
            return mockGetSupportedFormats();
        }
        return realManager->getSupportedFormats();
    }

    /**
     * Cấu hình hành vi mock cho phương thức isFileValid.
     * @param func Hàm mock.
     */
    void setMockIsFileValid(std::function<bool(const std::string&)> func) {
        mockIsFileValid = func;
    }

    /**
     * Cấu hình hành vi mock cho phương thức getSupportedFormats.
     * @param func Hàm mock.
     */
    void setMockGetSupportedFormats(std::function<std::vector<std::string>()> func) {
        mockGetSupportedFormats = func;
    }

private:
    FileManagerInterface* realManager; ///< Đối tượng FileManager thực.
    std::function<bool(const std::string&)> mockIsFileValid = nullptr; ///< Hàm mock cho isFileValid.
    std::function<std::vector<std::string>()> mockGetSupportedFormats = nullptr; ///< Hàm mock cho getSupportedFormats.
};

#endif // FILE_MANAGER_PROXY_H
