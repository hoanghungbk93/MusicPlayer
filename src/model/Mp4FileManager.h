/**
 * @file Mp4FileManager.h
 * @brief Declaration of the Mp4FileManager class for managing MP4 files.
 * @version 0.1
 * @date 2024-11-22
 * 
 * @details This file defines the Mp4FileManager class, which implements the 
 * FileManagerInterface to provide functionality for validating MP4 files 
 * and retrieving supported file formats.
 * 
 * @contact hch.bkhn@gmail.com
 * 
 * @author Hung
 * @copyright Copyright (c) 2024
 */

#ifndef MP4_FILE_MANAGER_H
#define MP4_FILE_MANAGER_H

#include "FileManagerInterface.h"

/**
 * @class Mp4FileManager
 * @brief A class for managing MP4 files.
 * 
 * The Mp4FileManager class provides methods to validate MP4 file paths and retrieve 
 * a list of supported video formats. It implements the FileManagerInterface.
 */
class Mp4FileManager : public FileManagerInterface {
public:
    /**
     * @brief Validates if a given file path corresponds to a valid MP4 file.
     * 
     * This method checks whether the file path has a `.mp4` extension.
     * 
     * @param filePath The file path to validate.
     * @return True if the file path is valid and corresponds to an MP4 file, false otherwise.
     */
    bool isFileValid(const std::string& filePath) const override;

    /**
     * @brief Retrieves the list of supported video formats.
     * 
     * This method returns a vector containing the supported video file formats.
     * For this implementation, only the `.mp4` format is supported.
     * 
     * @return A vector of strings containing the supported file formats.
     */
    std::vector<std::string> getSupportedFormats() const override;
};

#endif // MP4_FILE_MANAGER_H
