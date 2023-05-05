set(LIB_SOURCES
	EventMaker.cpp
	EventSlotting.cpp)

add_library(EventHandling ${LIB_SOURCES})
target_include_directories(EventHandling PUBLIC ${CMAKE_SOURCE_DIR}/include PRIVATE ${CMAKE_SOURCE_DIR}/src)