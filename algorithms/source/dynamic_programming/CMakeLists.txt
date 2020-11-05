set(libname dynamic_programming)

message("Generating ${libname} library")

# Project name
project(${libname})

set(header_files
	include/knapsack.h                        
	include/pipe_problem.h
	include/longest_increasing_subsequence.h  
	include/s_as_sum_of_n_given_numbers.h
	include/maximum_sum_in_triangle.h
)

set(source_files
	src/knapsack.cpp                        
	src/pipe_problem.cpp
	src/longest_increasing_subsequence.cpp  
	src/s_as_sum_of_n_given_numbers.cpp
	src/maximum_sum_in_triangle.cpp
)

# Generate static library
add_library(${libname} STATIC ${source_files} ${header_files})

if(MSVC)
    set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "lib")
endif()


# Export include folder
target_include_directories(${libname} PUBLIC include/)