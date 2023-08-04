set(LIB_SOURCES
	DialogHandling.cpp)

add_library(DialogHandling ${LIB_SOURCES})
target_include_directories(DialogHandling PUBLIC ${BRAZZGUI_DIR}/include PRIVATE ${BRAZZGUI_DIR}/src)