message( "Generating unit test for greedy" )
project(greedy_test)

set(
    source_files
	src/maximum_subset_sum_test.cpp
	src/minimal_waiting_time_for_patients_test.cpp
	src/mountain_trail_test.cpp
	src/optimal_number_of_stations_between_cities_test.cpp
	src/payment_with_minimal_value_of_bancnotes_test.cpp
	src/activities_scheduling_test.cpp
	src/the_most_valuable_charge_test.cpp
	src/tourists_houses_scheduling_test.cpp
	src/value_of_polygon_in_given_x_test.cpp
    src/main.cpp
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
    greedy
    gtest gtest_main gmock gmock_main
)
