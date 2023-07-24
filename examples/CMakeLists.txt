set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/examples)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin/debug/examples)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE BrazzGUI)
target_include_directories(main PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(layout layout.cpp)
target_link_libraries(layout PRIVATE BrazzGUI)
target_include_directories(layout PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(panel panel.cpp)
target_link_libraries(panel PRIVATE BrazzGUI)
target_include_directories(panel PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(tabs tabs.cpp)
target_link_libraries(tabs PRIVATE BrazzGUI)
target_include_directories(tabs PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(menu menu.cpp)
target_link_libraries(menu PRIVATE BrazzGUI)
target_include_directories(menu PUBLIC ${CMAKE_SOURCE_DIR}/include)