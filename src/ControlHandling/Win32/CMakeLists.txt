set(LIB_SOURCES
	ControlCreation.cpp
	ControlStyling.cpp)

add_library(ControlHandling ${LIB_SOURCES})
target_include_directories(ControlHandling PUBLIC ${CMAKE_SOURCE_DIR}/include PRIVATE ${CMAKE_SOURCE_DIR}/src)