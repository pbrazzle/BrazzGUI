set(LIB_SOURCES
	ControlCreation.cpp
	ControlStyling.cpp
	FontHandler.cpp)

add_library(ControlHandling ${LIB_SOURCES})
target_include_directories(ControlHandling PUBLIC ${BRAZZGUI_DIR}/include PRIVATE ${BRAZZGUI_DIR}/src)