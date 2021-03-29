cmake_minimum_required(VERSION 3.2)

project(BrazzGUI)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

link_directories(${CMAKE_SOURCE_DIR}/lib)

set(HEADERS
	include/OSInterface.hpp
	include/GUIEntity.hpp
	include/DrawableGUIEntity.hpp
	include/BrazzCore.hpp
	include/Window.hpp
	include/Brush.hpp
	include/Control.hpp
	include/Button.hpp
	include/Pane.hpp
	include/TextBox.hpp
	include/Menu.hpp
	include/MenuItem.hpp
	include/Label.hpp
	include/ListViewer.hpp
	include/CheckBox.hpp
	include/RadioButton.hpp
	include/Slider.hpp
	include/ComboBox.hpp
	include/RadioGroup.hpp
	include/ControlGroup.hpp)

set(SOURCES
	source/OSInterface.cpp
	source/GUIEntity.cpp
	source/DrawableGUIEntity.cpp
	source/Window.cpp
	source/Brush.cpp
	source/Control.cpp
	source/Button.cpp
	source/Pane.cpp
	source/TextBox.cpp
	source/Menu.cpp
	source/MenuItem.cpp
	source/Label.cpp
	source/ListViewer.cpp
	source/CheckBox.cpp
	source/RadioButton.cpp
	source/Slider.cpp
	source/ComboBox.cpp
	source/RadioGroup.cpp
	source/ControlGroup.cpp)

add_library(BrazzGUI STATIC ${SOURCES} ${HEADERS})
target_include_directories(BrazzGUI PUBLIC include)
target_link_libraries(BrazzGUI gdiplus)

add_executable(test WIN32 test/test.cpp)
target_link_libraries(test debug BrazzGUI winmm)
