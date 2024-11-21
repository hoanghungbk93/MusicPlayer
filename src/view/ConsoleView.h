#ifndef CONSOLE_VIEW_H
#define CONSOLE_VIEW_H

#include <string>
#include <iostream>

class ConsoleView {
public:
    void displayMessage(const std::string& message);
    void displayError(const std::string& error);
};

#endif // CONSOLE_VIEW_H
