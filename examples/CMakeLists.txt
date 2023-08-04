set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BRAZZGUI_DIR}/bin/examples)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${BRAZZGUI_DIR}/bin/debug/examples)

set(EXAMPLE_SRCS
    main.cpp
    layout.cpp
    panel.cpp
    tabs.cpp
    menu.cpp
    draw.cpp)

foreach(EXAMPLE_SRC ${EXAMPLE_SRCS})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SRC} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SRC})
    target_link_libraries(${EXAMPLE_NAME} PRIVATE BrazzGUI)
    target_include_directories(${EXAMPLE_NAME} PUBLIC ${BRAZZGUI_DIR}/include)
endforeach()