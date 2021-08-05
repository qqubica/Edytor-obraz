cmake_minimum_required(VERSION 3.19)
project(edytorZdjec)

set(CMAKE_CXX_STANDARD 14)
set(OpenCV_DIR "C:/Biblioteki/C++/opencv-4.5.3/build/")

find_package(OpenCV REQUIRED COMPONENTS core imgproc highgui imgcodecs)
find_package(SFML 2.5 COMPONENTS system window graphics)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(edytorZdjec main.cpp)

target_link_libraries(edytorZdjec ${OpenCV_LIBS})
target_link_libraries(edytorZdjec sfml-system sfml-graphics)