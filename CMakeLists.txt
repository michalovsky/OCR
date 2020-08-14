cmake_minimum_required(VERSION 3.13)

project(OCR)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(utils)
add_subdirectory(recognition)

add_executable(OCR Main.cpp)

target_link_libraries(OCR PUBLIC lept tesseract utils recognition)
