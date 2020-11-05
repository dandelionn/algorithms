set(libname greedy)

message("Generating ${libname} library")

# Project name
project(${libname})

set(header_files
	include/maximum_subset_sum.h
	include/minimal_waiting_time_for_patients.h
	include/mountain_trail.h
	include/optimal_number_of_stations_between_cities.h
	include/payment_with_minimal_value_of_bancnotes.h
	include/activities_scheduling.h
	include/the_most_valuable_charge.h
	include/tourists_houses_scheduling.h
	include/value_of_polygon_in_given_x.h
)

set(source_files
	src/maximum_subset_sum.cpp
	src/minimal_waiting_time_for_patients.cpp
	src/mountain_trail.cpp
	src/optimal_number_of_stations_between_cities.cpp
	src/payment_with_minimal_value_of_bancnotes.cpp
	src/activities_scheduling.cpp
	src/the_most_valuable_charge.cpp
	src/tourists_houses_scheduling.cpp
	src/value_of_polygon_in_given_x.cpp
)

# Generate static library
add_library(${libname} STATIC ${source_files} ${header_files})

if(MSVC)
    set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "lib")
endif()


# Export include folder
target_include_directories(${libname} PUBLIC include/)