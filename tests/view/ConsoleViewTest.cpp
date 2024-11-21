#include <gtest/gtest.h>
#include "../../src/view/ConsoleView.h"
#include <sstream>
#include <iostream>

TEST(ConsoleViewTest, TestDisplayMessage) {
    ConsoleView view;
    testing::internal::CaptureStdout();

    view.displayMessage("Hello, World!");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Hello, World!\n");
}

TEST(ConsoleViewTest, TestDisplayError) {
    ConsoleView view;
    testing::internal::CaptureStderr();

    view.displayError("An error occurred");
    std::string output = testing::internal::GetCapturedStderr();

    EXPECT_EQ(output, "An error occurred\n");
}
