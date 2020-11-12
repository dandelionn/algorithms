message( "Generating unit test for backtracking" )
project(backtracking_test)

set(
    source_files
    src/backtracking-iterative_test.cpp        
    src/main.cpp
    src/backtracking-recursive_test.cpp
    src/subsets-using-bits_test.cpp
    src/efficient-next-permutation_test.cpp
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
    backtracking
    gtest gtest_main gmock gmock_main
)
