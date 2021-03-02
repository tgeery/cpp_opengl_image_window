cmake_minimum_required(VERSION 3.16)

add_subdirectory(dlib)

project(CImgWindow)

add_executable(CImgWindow main.cpp)

target_link_libraries(CImgWindow PUBLIC dlib)
target_link_libraries(CImgWindow PUBLIC glut)
target_include_directories(CImgWindow PUBLIC CImg)
target_include_directories(CImgWindow PUBLIC dlib/dlib/external/libpng)
