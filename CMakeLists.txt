cmake_minimum_required(VERSION 3.10)

project(BrazzGUI)

set(BRAZZGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BRAZZGUI_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${BRAZZGUI_DIR}/bin/debug)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BRAZZGUI_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${BRAZZGUI_DIR}/lib/debug)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
	add_subdirectory(tests)
	add_subdirectory(examples)
	add_subdirectory(docs)
endif()