set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/test)

add_executable(test WIN32 test.cpp)
target_link_libraries(test BrazzGUI)