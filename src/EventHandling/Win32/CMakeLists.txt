set(LIB_SOURCES
	EventMaker.cpp)

add_library(EventHandling ${LIB_SOURCES})
target_include_directories(EventHandling PRIVATE ${CMAKE_SOURCE_DIR}/src)