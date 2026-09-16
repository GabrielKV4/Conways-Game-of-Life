cmake_minimum_required(VERSION 4.3)
project(Conway_s_Game_of_Life)

set(CMAKE_CXX_STANDARD 26)

add_executable(Conway_s_Game_of_Life main.cpp
        Window.cpp
        Window.h
        Grid.cpp
        Grid.h)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

target_link_libraries(Conway_s_Game_of_Life PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)
