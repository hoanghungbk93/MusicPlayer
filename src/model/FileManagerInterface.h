/**
 * @file FileManagerInterface.h
 * @author HungHC
 * @brief Declaration of the FileManagerInterface class.
 * @version 0.1
 * @date 2024-11-22
 * 
 * @details This file defines an abstract interface for file management operations. 
 * It includes methods to validate files and retrieve supported formats. 
 * Classes implementing this interface should define the specific behaviors for these operations.
 * 
 * @contact hch.bkhn@gmail.com
 * 
 * @copyright Copyright (c) 2024
 */

#ifndef FILE_MANAGER_INTERFACE_H
#define FILE_MANAGER_INTERFACE_H

#include <string>
#include <vector>

/**
 * @class FileManagerInterface
 * @brief An interface for managing file-related operations.
 * 
 * This abstract class defines methods to validate file paths and retrieve a list of 
 * supported file formats. It serves as a base for implementing file management in various systems.
 */
class FileManagerInterface {
public:
    /**
     * @brief Checks if the specified file is valid.
     * 
     * This method validates the given file path to ensure it meets the required criteria.
     * 
     * @param filePath The path of the file to validate.
     * @return True if the file is valid, false otherwise.
     */
    virtual bool isFileValid(const std::string& filePath) const = 0;

    /**
     * @brief Retrieves a list of supported file formats.
     * 
     * This method returns a collection of file extensions or formats that are supported by the system.
     * 
     * @return A vector of strings containing the supported file formats.
     */
    virtual std::vector<std::string> getSupportedFormats() const = 0;

    /**
     * @brief Virtual destructor.
     * 
     * Ensures proper cleanup of derived classes when deleted through a pointer to this interface.
     */
    virtual ~FileManagerInterface() = default;
};

#endif // FILE_MANAGER_INTERFACE_H
