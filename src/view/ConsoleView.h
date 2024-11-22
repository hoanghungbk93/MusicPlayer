/**
 * @file ConsoleView.h
 * @brief Declaration of the ConsoleView class for console-based message and error display.
 * @version 0.1
 * @date 2024-11-22
 * 
 * @details This file defines the ConsoleView class, which provides methods to 
 * display standard messages and error messages to the console.
 * 
 * @contact hch.bkhn@gmail.com
 * 
 * @author HungHC
 * @copyright Copyright (c) 2024
 */

#ifndef CONSOLE_VIEW_H
#define CONSOLE_VIEW_H

#include <string>
#include <iostream>

/**
 * @class ConsoleView
 * @brief A class for displaying messages and errors in the console.
 * 
 * The ConsoleView class provides methods to output standard messages and error messages
 * to the console. It uses `std::cout` for messages and `std::cerr` for errors.
 */
class ConsoleView {
public:
    /**
     * @brief Displays a message to the console.
     * 
     * This method outputs a standard message to the console.
     * 
     * @param message The message to be displayed.
     */
    void displayMessage(const std::string& message);

    /**
     * @brief Displays an error message to the console.
     * 
     * This method outputs an error message to the console.
     * 
     * @param error The error message to be displayed.
     */
    void displayError(const std::string& error);
};

#endif // CONSOLE_VIEW_H
