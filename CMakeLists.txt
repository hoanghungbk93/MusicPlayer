cmake_minimum_required(VERSION 3.10)

# Project Name
project(MusicPlayer)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add coverage flags
option(CODE_COVERAGE "Enable coverage reporting" ON)
if (CODE_COVERAGE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -O0 -g")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

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
add_test(NAME MusicPlayerControllerTest COMMAND MusicPlayerControllerTest)

add_executable(Mp3FileManagerTest tests/model/Mp3FileManagerTest.cpp ${MODEL_SOURCES})
target_link_libraries(Mp3FileManagerTest gtest gmock gtest_main)
add_test(NAME Mp3FileManagerTest COMMAND Mp3FileManagerTest)

add_executable(Mp4FileManagerTest tests/model/Mp4FileManagerTest.cpp ${MODEL_SOURCES})
target_link_libraries(Mp4FileManagerTest gtest gmock gtest_main)
add_test(NAME Mp4FileManagerTest COMMAND Mp4FileManagerTest)

add_executable(HeadphoneOutputTest tests/model/HeadphoneOutputTest.cpp ${MODEL_SOURCES})
target_link_libraries(HeadphoneOutputTest gtest gmock gtest_main)
add_test(NAME HeadphoneOutputTest COMMAND HeadphoneOutputTest)

add_executable(SpeakerOutputTest tests/model/SpeakerOutputTest.cpp ${MODEL_SOURCES})
target_link_libraries(SpeakerOutputTest gtest gmock gtest_main)
add_test(NAME SpeakerOutputTest COMMAND SpeakerOutputTest)

# Generate coverage reports (optional)
if (CODE_COVERAGE)
    add_custom_target(coverage
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/../reports
        COMMAND gcovr -r ${CMAKE_SOURCE_DIR} --filter ../src/ --html --html-details -o ${CMAKE_BINARY_DIR}/../reports/coverage.html
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Generating coverage report..."
    )
endif()

