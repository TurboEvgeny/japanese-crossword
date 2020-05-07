cmake_minimum_required(VERSION 3.13)

project(japanese-crossword LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(japanese-crossword
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/mainwindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/mainwindow.h
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/mainwindow.ui
  )
target_link_libraries(japanese-crossword PRIVATE Qt5::Widgets)
