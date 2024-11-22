/**
 * @file ConsoleView.cpp
 * @brief Implementation of the ConsoleView class for displaying messages and errors in the console.
 * @version 0.1
 * @date 2024-11-22
 * 
 * @details This file implements the methods of the ConsoleView class, which provide
 * functionality to display messages and errors to the console.
 * 
 * @contact hch.bkhn@gmail.com
 * 
 * @author HungHC
 * @copyright Copyright (c) 2024
 */

#include "ConsoleView.h"
#include <iostream>

/**
 * @brief Displays a message to the console.
 * 
 * This method outputs a standard message to the console using `std::cout`.
 * 
 * @param message The message to be displayed.
 */
void ConsoleView::displayMessage(const std::string& message) {
    std::cout << message << std::endl;
}

/**
 * @brief Displays an error message to the console.
 * 
 * This method outputs an error message to the console using `std::cerr`.
 * 
 * @param error The error message to be displayed.
 */
void ConsoleView::displayError(const std::string& error) {
    std::cerr << error << std::endl;
}
