cmake_minimum_required(VERSION 3.22)
project(imgui)

add_executable(main main.cc)
find_package(glfw3 3.3 REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(main PRIVATE imgui::imgui)
target_link_libraries(main PRIVATE glfw)
TARGET_LINK_LIBRARIES(main PRIVATE OpenGL::GL)

