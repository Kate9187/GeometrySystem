cmake_minimum_required(VERSION 3.16)

project(GeometrySystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(GeometrySystem
    main.cpp
    Circle.cpp
    Group.cpp
    Rectangle.cpp
    Scene.cpp
    Triangle.cpp
)

target_include_directories(GeometrySystem PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)