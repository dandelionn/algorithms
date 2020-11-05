message( "Generating unit test for dynamic_programming" )
project(dynamic_programming_test)

set(
    source_files
    src/main.cpp
    src/knapsack_test.cpp
    src/maximum_sum_in_triangle_test.cpp
    src/longest_increasing_subsequence_test.cpp  
    src/pipe_problem_test.cpp
    src/s_as_sum_of_n_given_numbers_test.cpp
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
    dynamic_programming
    gtest gtest_main gmock gmock_main
)
