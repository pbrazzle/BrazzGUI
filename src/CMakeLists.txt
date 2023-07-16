add_subdirectory(EventHandling)
add_subdirectory(ControlHandling)

set(LIB_SOURCES
	BrazzApp.cpp
	Window.cpp
	Control.cpp
	ControlID.cpp
	Button.cpp
	Checkbox.cpp
	TextControl.cpp
	Textbox.cpp
	RadioButton.cpp
	Label.cpp
	Menu.cpp
	MenuItem.cpp
	RadioButtonGroup.cpp
	TextArea.cpp
	DrawPane.cpp
	ComboBox.cpp
	Font.cpp
	LayoutController.cpp
	ParentControl.cpp
	Panel.cpp
	FileOpenDialog.cpp
	FileSaveDialog.cpp
	OKCancelDialog.cpp)
	
add_library(BrazzGUI ${LIB_SOURCES})
target_link_libraries(BrazzGUI PRIVATE EventHandling ControlHandling)
target_include_directories(BrazzGUI PRIVATE ${CMAKE_SOURCE_DIR}/src PUBLIC ${CMAKE_SOURCE_DIR}/include)