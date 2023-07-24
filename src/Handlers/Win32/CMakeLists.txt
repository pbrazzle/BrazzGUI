set(LIB_SOURCES
	Win32MenuHandler.cpp)

add_library(Handlers ${LIB_SOURCES})
target_include_directories(Handlers PUBLIC ${CMAKE_SOURCE_DIR}/include PRIVATE ${CMAKE_SOURCE_DIR}/src)