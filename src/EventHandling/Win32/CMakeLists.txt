set(LIB_SOURCES
	EventMaker.cpp
	EventSlotting.cpp)

add_library(EventHandling ${LIB_SOURCES})
target_include_directories(EventHandling PUBLIC ${BRAZZGUI_DIR}/include PRIVATE ${BRAZZGUI_DIR}/src)