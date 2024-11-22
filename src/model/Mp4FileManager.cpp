/**
 * @file Mp4FileManager.cpp
 * @brief Implementation of the Mp4FileManager class for handling MP4 files.
 * @version 0.1
 * @date 2024-11-22
 * 
 * @details This file implements the methods defined in the Mp4FileManager class,
 * including validation of file paths and retrieval of supported formats.
 * 
 * @contact hch.bkhn@gmail.com
 * 
 * @author HungHC
 * @copyright Copyright (c) 2024
 */

#include "Mp4FileManager.h"

/**
 * @brief Validates if the given file path corresponds to an MP4 file.
 * 
 * This method checks whether the file path ends with the `.mp4` extension to determine
 * if it is a valid MP4 file.
 * 
 * @param filePath The file path to validate.
 * @return True if the file path ends with `.mp4`, false otherwise.
 */
bool Mp4FileManager::isFileValid(const std::string& filePath) const {
    return filePath.find(".mp4") != std::string::npos;
}

/**
 * @brief Retrieves the list of supported video formats.
 * 
 * This method returns a vector containing the supported video file formats.
 * For this class, only the `.mp4` format is supported.
 * 
 * @return A vector of strings containing the supported file formats.
 */
std::vector<std::string> Mp4FileManager::getSupportedFormats() const {
    return {"mp4"};
}
