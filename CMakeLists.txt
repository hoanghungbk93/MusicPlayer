cmake_minimum_required(VERSION 3.10)

# Project Name
project(MusicPlayer)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)

# Add coverage flags for gcov
set(CMAKE_CXX_FLAGS "--coverage -O0 -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "--coverage")

# Include Directories
include_directories(src)
include_directories(tests)

# Google Test Configuration
enable_testing()
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Source Files
file(GLOB MODEL_SOURCES src/model/*.cpp)
file(GLOB CONTROLLER_SOURCES src/controller/*.cpp)
file(GLOB VIEW_SOURCES src/view/*.cpp)

# Main Executable
add_executable(MusicPlayer src/main.cpp ${MODEL_SOURCES} ${CONTROLLER_SOURCES} ${VIEW_SOURCES})

# Add Tests
add_executable(MusicPlayerControllerTest tests/controller/MusicPlayerControllerTest.cpp ${MODEL_SOURCES} ${CONTROLLER_SOURCES} ${VIEW_SOURCES})
target_link_libraries(MusicPlayerControllerTest gtest gmock gtest_main)

add_executable(Mp3FileManagerTest tests/model/Mp3FileManagerTest.cpp ${MODEL_SOURCES})
target_link_libraries(Mp3FileManagerTest gtest gmock gtest_main)

add_executable(Mp4FileManagerTest tests/model/Mp4FileManagerTest.cpp ${MODEL_SOURCES})
target_link_libraries(Mp4FileManagerTest gtest gmock gtest_main)

add_executable(HeadphoneOutputTest tests/model/HeadphoneOutputTest.cpp ${MODEL_SOURCES})
target_link_libraries(HeadphoneOutputTest gtest gmock gtest_main)

add_executable(SpeakerOutputTest tests/model/SpeakerOutputTest.cpp ${MODEL_SOURCES})
target_link_libraries(SpeakerOutputTest gtest gmock gtest_main)

# Enable Tests
add_test(NAME MusicPlayerControllerTest COMMAND MusicPlayerControllerTest)
add_test(NAME Mp3FileManagerTest COMMAND Mp3FileManagerTest)
add_test(NAME Mp4FileManagerTest COMMAND Mp4FileManagerTest)
add_test(NAME HeadphoneOutputTest COMMAND HeadphoneOutputTest)
add_test(NAME SpeakerOutputTest COMMAND SpeakerOutputTest)
