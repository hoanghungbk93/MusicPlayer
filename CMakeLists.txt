cmake_minimum_required(VERSION 3.10)

# Project Name
project(MusicPlayer)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)

# Add Source Files for Main Program
set(MAIN_SOURCE_FILES
    src/MusicPlayer.cpp
    src/main.cpp
    src/FileManagerProxy.h
    src/AudioOutputProxy.h
)

# Add Source Files for Unit Test
set(TEST_SOURCE_FILES
    tests/MusicPlayerTest.cpp
    src/MusicPlayer.cpp
    src/FileManagerProxy.h
    src/AudioOutputProxy.h
)

# Include Directories
include_directories(src)

# Add Executable for Main Program
add_executable(MusicPlayer ${MAIN_SOURCE_FILES})

# Google Test
enable_testing()
add_subdirectory(googletest)  # Thêm thư mục chứa Google Test (nếu clone thủ công)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Add Unit Test Executable
add_executable(MusicPlayerTest ${TEST_SOURCE_FILES})
target_link_libraries(MusicPlayerTest gtest gmock gtest_main)
