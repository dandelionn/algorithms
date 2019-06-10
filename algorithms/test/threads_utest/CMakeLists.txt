message( "Generating unit test for threads" )
project(threads_utest)

set(
    source_files
    src/main.cpp
    src/algotest.cpp
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
    threads
    gtest gtest_main gmock gmock_main
)
