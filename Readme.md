# Install Google Test
git clone https://github.com/google/googletest.git

cd googletest

mkdir build

cd build

cmake ..

make

sudo make install

# Combine and run program

cd MusicPlayer

mkdir build

cd build

cmake ..

make

# Run executable files
./MusicPlayerTest

# Results

[==========] Running 5 tests from 3 test cases.

[----------] Global test environment set-up.

[----------] 1 test from FileManagerTest

[ RUN      ] FileManagerTest.ValidateFileFormat

[       OK ] FileManagerTest.ValidateFileFormat (0 ms)

...

[==========] 5 tests from 3 test cases ran. (5 ms total)

[  PASSED  ] 5 tests.

# report
pip install gcovr

ctest

gcovr -r . --filter src/ --html --html-details -o reports/coverage.html

# generate document

brew install doxygen

doxygen -g

doxygen DoxyFile
