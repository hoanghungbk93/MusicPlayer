1. Cài đặt Google Test
Cách 1: Clone Google Test từ GitHub
Mở terminal và chạy: 

$git clone https://github.com/google/googletest.git
$cd googletest
$mkdir build
$cd build
$cmake ..
$make
$sudo make install
2. Tạo cấu trúc thư mục dự án
Cấu trúc thư mục sẽ như sau:
MusicPlayer/
├── src/
│   ├── MusicPlayer.cpp
│   ├── MusicPlayer.h
├── tests/
│   ├── MusicPlayerTest.cpp
├── CMakeLists.txt

4. Biên dịch và chạy chương trình
Bước 1: Tạo thư mục build
$cd MusicPlayer
$mkdir build
$cd build
Bước 2: Chạy CMake
$cmake ..
Bước 3: Biên dịch
$make
Sau khi biên dịch xong, bạn sẽ thấy hai tệp thực thi:

MusicPlayer: Chương trình chính.
MusicPlayerTest: Chương trình chạy bài kiểm tra.
5. Chạy các tệp thực thi
Chạy chương trình chính
./MusicPlayer
Chạy unit tests
./MusicPlayerTest
6. Kết quả
Khi chạy MusicPlayerTest, bạn sẽ thấy đầu ra tương tự:

plaintext
Copy code
[==========] Running 5 tests from 3 test cases.
[----------] Global test environment set-up.
[----------] 1 test from FileManagerTest
[ RUN      ] FileManagerTest.ValidateFileFormat
[       OK ] FileManagerTest.ValidateFileFormat (0 ms)
...
[==========] 5 tests from 3 test cases ran. (5 ms total)
[  PASSED  ] 5 tests.

#report
pip install gcovr

ctest

gcovr -r . --filter src/ --html --html-details -o reports/coverage.html
