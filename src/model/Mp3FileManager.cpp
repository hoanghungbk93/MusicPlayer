/**
 * @file Mp3FileManager.cpp
 * @brief Implementation of the Mp3FileManager class for handling MP3 files.
 * @version 0.1
 * @date 2024-11-22
 * 
 * @details This file implements the methods defined in the Mp3FileManager class,
 * including validation of file paths and retrieval of supported formats.
 * 
 * @contact hch.bkhn@gmail.com
 * 
 * @author HungHC
 * @copyright Copyright (c) 2024
 */

#include "Mp3FileManager.h"

/**
 * @brief Validates if the given file path corresponds to an MP3 file.
 * 
 * This method checks whether the file path ends with the `.mp3` extension to determine
 * if it is a valid MP3 file.
 * 
 * @param filePath The file path to validate.
 * @return True if the file path ends with `.mp3`, false otherwise.
 */
bool Mp3FileManager::isFileValid(const std::string& filePath) const {
    return filePath.find(".mp3") != std::string::npos;
}

/**
 * @brief Retrieves the list of supported audio formats.
 * 
 * This method returns a vector containing the supported audio file formats.
 * For this class, only the `.mp3` format is supported.
 * 
 * @return A vector of strings containing the supported file formats.
 */
std::vector<std::string> Mp3FileManager::getSupportedFormats() const {
    return {"mp3"};
}
