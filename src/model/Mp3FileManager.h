/**
 * @file Mp3FileManager.h
 * @brief Declaration of the Mp3FileManager class for managing MP3 files.
 * @version 0.1
 * @date 2024-11-22
 * 
 * @details This file defines the Mp3FileManager class, which implements the 
 * FileManagerInterface to provide functionality for validating MP3 files 
 * and retrieving supported file formats.
 * 
 * @contact hch.bkhn@gmail.com
 * 
 * @author HungHC
 * @copyright Copyright (c) 2024
 */

#ifndef MP3_FILE_MANAGER_H
#define MP3_FILE_MANAGER_H

#include "FileManagerInterface.h"

/**
 * @class Mp3FileManager
 * @brief A class for managing MP3 files.
 * 
 * The Mp3FileManager class provides methods to validate MP3 file paths and retrieve 
 * a list of supported audio formats. It implements the FileManagerInterface.
 */
class Mp3FileManager : public FileManagerInterface {
public:
    /**
     * @brief Validates if a given file path corresponds to a valid MP3 file.
     * 
     * This method checks whether the file path has a `.mp3` extension.
     * 
     * @param filePath The file path to validate.
     * @return True if the file path is valid and corresponds to an MP3 file, false otherwise.
     */
    bool isFileValid(const std::string& filePath) const override;

    /**
     * @brief Retrieves the list of supported audio formats.
     * 
     * This method returns a vector containing the supported audio file formats.
     * For this implementation, only the `.mp3` format is supported.
     * 
     * @return A vector of strings containing the supported file formats.
     */
    std::vector<std::string> getSupportedFormats() const override;
};

#endif // MP3_FILE_MANAGER_H
