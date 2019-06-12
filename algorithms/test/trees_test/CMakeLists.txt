message( "Generating unit test for trees" )
project(trees_test)

set(
    source_files
	src/binary_search_tree_test.cpp
	src/dynamic_binary_tree_parse_test.cpp
	src/dynamic_tree_test.cpp
	src/heap_test.cpp
	src/main.cpp
	src/static_binary_tree_parse_test.cpp
	src/tree_traversal_test.cpp
	src/left_right_child_representation_test.cpp
	src/parent_childtype_representation_test.cpp
)

link_directories(${LIBRARY_OUTPUT_PATH})
add_executable(${PROJECT_NAME} ${source_files})

# Add to Ctests
add_test(NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME}
        WORKING_DIRECTORY ${ATM_BIN_DIR})

if(MSVC)
    set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "test")
endif()

target_link_libraries(${PROJECT_NAME}
    trees
    gtest gtest_main gmock gmock_main
)
