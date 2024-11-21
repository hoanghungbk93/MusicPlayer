#include "ConsoleView.h"

void ConsoleView::displayMessage(const std::string& message) {
    std::cout << message << std::endl;
}

void ConsoleView::displayError(const std::string& error) {
    std::cerr << error << std::endl;
}
