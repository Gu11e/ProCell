cmake_minimum_required(VERSION 3.31)
project(ProCell)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ../bin)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(SFML_STATIC_LIBRARIES TRUE CACHE BOOL "" FORCE)

add_subdirectory(vendor/SFML)

add_executable(ProCell
        src/main.cpp

)

target_compile_definitions(ProCell PRIVATE SFML_STATIC)

target_link_libraries(ProCell PRIVATE sfml-graphics sfml-window sfml-system)

target_include_directories(ProCell PRIVATE vendor/SFML/include)
target_include_directories(ProCell PRIVATE vendor/stb_image)