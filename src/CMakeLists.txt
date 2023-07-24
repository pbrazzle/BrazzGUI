add_subdirectory(EventHandling)
add_subdirectory(ControlHandling)
add_subdirectory(DialogHandling)
add_subdirectory(Handlers)

set(LIB_SOURCES
	BrazzApp.cpp
	Control.cpp
	ControlID.cpp
	Checkbox.cpp
	TextControl.cpp
	Menu.cpp
	MenuItem.cpp
	RadioButtonGroup.cpp
	ComboBox.cpp
	TabGroup.cpp
	Font.cpp
	LayoutController.cpp
	ParentControl.cpp
	FileOpenDialog.cpp
	FileSaveDialog.cpp
	OKCancelDialog.cpp
	Window.cpp)
	
add_library(BrazzGUI ${LIB_SOURCES})
target_link_libraries(BrazzGUI PRIVATE EventHandling ControlHandling DialogHandling Handlers)
target_include_directories(BrazzGUI PRIVATE ${CMAKE_SOURCE_DIR}/src PUBLIC ${CMAKE_SOURCE_DIR}/include)