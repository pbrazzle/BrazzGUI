set(TEST_SOURCES
	Checkbox.test.cpp
	Menu.test.cpp
	MenuItem.test.cpp
	BasicControl.test.cpp)

add_catch_tests(TARGETS ${TEST_SOURCES} LIBS BrazzGUI)