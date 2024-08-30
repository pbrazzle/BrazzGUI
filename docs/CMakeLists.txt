find_package(Doxygen)

if (NOT ${DOXYGEN_FOUND})
    message("Doxygen not found!")
    return()
endif()

message("Doxygen found successfully!")

set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
doxygen_add_docs(docs ${BRAZZGUI_DIR}/src ${BRAZZGUI_DIR}/include ALL)