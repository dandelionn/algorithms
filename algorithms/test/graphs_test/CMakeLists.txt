message( "Generating unit test for graphs" )
project(graphs_test)

set(
    source_files
    	src/main.cpp
	src/algorithm-discovering-road-with-minimal-cost_test.cpp
	src/dijkstra-algorithm_test.cpp
	src/main.cpp
	src/minimum-cost-spanning-tree-kruskal_test.cpp
	src/minimum-cost-spanning-tree-prim_test.cpp
	src/roy-floyd_test.cpp
	src/roy-warshall-algoritm-for-discovering-road-matrix_test.cpp
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
    graphs
    gtest gtest_main gmock gmock_main
)
