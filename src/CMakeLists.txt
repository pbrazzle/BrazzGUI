add_subdirectory(EventHandling)

set(LIB_SOURCES
	BrazzApp.cpp
	Window.cpp)
	
add_library(BrazzGUI ${LIB_SOURCES})
target_link_libraries(BrazzGUI PRIVATE EventHandling)
target_include_directories(BrazzGUI PRIVATE ${CMAKE_SOURCE_DIR}/src PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE BrazzGUI)
target_include_directories(main PUBLIC ${CMAKE_SOURCE_DIR}/include)

set(TEST_SOURCES
	Window.test.cpp
	Button.test.cpp
	Checkbox.test.cpp
	RadioButton.test.cpp
	Textbox.test.cpp
	Label.test.cpp)

add_catch_tests(TARGETS ${TEST_SOURCES} LIBS BrazzGUI)