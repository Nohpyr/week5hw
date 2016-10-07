cmake_minimum_required(VERSION 2.8)

project(threshy)

add_executable(threshy main.cpp)

find_package(OpenCV REQUIRED)
target_link_libraries(threshy ${OpenCV_LIBS})
