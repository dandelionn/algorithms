message( "Generating unit test for divide_et_impera" )
project(divide_et_impera_test)

set(
    source_files
    src/main.cpp
    src/binary-search_test.cpp
    src/mergesort_test.cpp
    src/quicksort_test.cpp
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
    divide_et_impera
    gtest gtest_main gmock gmock_main
)
