add_executable(main WIN32 main.cpp)

set(TEST_SOURCES
	Window.test.cpp
	Button.test.cpp
	Checkbox.test.cpp
	RadioButton.test.cpp
	Textbox.test.cpp
	Label.test.cpp)

add_catch_tests(TARGETS ${TEST_SOURCES})