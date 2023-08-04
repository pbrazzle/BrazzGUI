set(LIB_SOURCES
	Win32MenuHandler.cpp)

add_library(Handlers ${LIB_SOURCES})
target_include_directories(Handlers PUBLIC ${BRAZZGUI_DIR}/include PRIVATE ${BRAZZGUI_DIR}/src)