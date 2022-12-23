cmake_minimum_required(VERSION 3.10)

project(BrazzGUI)

add_executable(main WIN32 main.cpp)
add_executable(test WIN32 test.cpp Window.cpp Win32GUIHandle.cpp BasicEventHandler.cpp)