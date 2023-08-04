Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.3.2)

FetchContent_MakeAvailable(Catch2)

include(CTest)
include(Catch)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

enable_testing()

function(create_test)
	add_executable(${ARGV} ${ARGV})
	add_test(NAME ${ARGV}
			 COMMAND $<TARGET_FILE:${ARGV}>)
endfunction(create_test)

function(add_catch_tests)
	cmake_parse_arguments(ADD_CATCH_TESTS "" "" "TARGETS;LIBS" ${ARGN})
	foreach(TEST ${ADD_CATCH_TESTS_TARGETS})
		get_filename_component(TEST_NAME ${TEST} NAME_WE)
		add_executable(${TEST_NAME} ${TEST})
		target_link_libraries(${TEST_NAME} PRIVATE ${ADD_CATCH_TESTS_LIBS} Catch2::Catch2WithMain)
		catch_discover_tests(${TEST_NAME})
	endforeach()
endfunction()

set(TEST_SOURCES
	Checkbox.test.cpp
	Menu.test.cpp
	MenuItem.test.cpp
	BasicControl.test.cpp)

add_catch_tests(TARGETS ${TEST_SOURCES} LIBS BrazzGUI)