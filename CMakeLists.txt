cmake_minimum_required(VERSION 3.2)

project(BrazzGUI)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/BrazzGUI/lib)

set(HEADERS
	include/BrazzCore.hpp
	include/Component.hpp 
	include/Window.hpp
	include/Menu.hpp
	include/Event.hpp)

set(SOURCES
	source/BrazzCore.cpp
	source/Component.cpp 
	source/Window.cpp
	source/Menu.cpp
	source/Event.cpp)

add_library(BrazzGUI STATIC ${SOURCES} ${HEADERS})
target_include_directories(BrazzGUI PUBLIC include)
target_link_libraries(BrazzGUI gdiplus.lib)

add_subdirectory(test)