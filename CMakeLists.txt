cmake_minimum_required(VERSION 3.22)
project(imgui-app)
set(CMAKE_CXX_STANDARD 20)

add_executable(main main.cc)
find_package(glfw3 3.3 REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(date CONFIG REQUIRED)
find_path(UWEBSOCKETS_INCLUDE_DIRS "uwebsockets/App.h")
    target_include_directories(main PRIVATE ${UWEBSOCKETS_INCLUDE_DIRS})
# find_library(mac Appkit)

# include_directories(${mac_include_dir})

add_library(${UWEBSOCKETS_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(main PRIVATE imgui::imgui)
TARGET_LINK_LIBRARIES(main PRIVATE glfw)
TARGET_LINK_LIBRARIES(main PRIVATE OpenGL::GL)
target_link_libraries(main PRIVATE date::date date::date-tz)
# target_link_libraries(main PRIVATE uweb)


# TARGET_LINK_LIBRARIES(main PRIVATE mac)

