set(TEST_SOURCES
	Window.test.cpp
	Button.test.cpp
	Checkbox.test.cpp
	RadioButton.test.cpp
	Textbox.test.cpp
	Label.test.cpp
	Menu.test.cpp
	MenuItem.test.cpp
	DrawPane.test.cpp
	RadioButtonGroup.test.cpp
	TextArea.test.cpp
	ComboBox.test.cpp)

add_catch_tests(TARGETS ${TEST_SOURCES} LIBS BrazzGUI)