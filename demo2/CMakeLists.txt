cmake_minimum_required(VERSION 3.30)
project(demo1 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
 set(CMAKE_PREFIX_PATH "D:/app/qt/6.8.1/msvc2022_64")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(demo1
    dialog.cpp
    dialog.h
    main.cpp
    )

target_include_directories(demo1 PUBLIC ./)

target_link_libraries(demo1
        Qt6::Widgets
)

