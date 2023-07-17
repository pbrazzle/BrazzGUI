set(LIB_SOURCES
	DialogHandling.cpp)

add_library(DialogHandling ${LIB_SOURCES})
target_include_directories(DialogHandling PUBLIC ${CMAKE_SOURCE_DIR}/include PRIVATE ${CMAKE_SOURCE_DIR}/src)