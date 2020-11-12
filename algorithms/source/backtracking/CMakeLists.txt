set(libname backtracking)

message("Generating ${libname} library")

# Project name
project(${libname})

set(header_files
	include/backtracking-iterative.h
	include/efficient-next-permutation.h
	include/backtracking-recursive.h
	include/subsets-using-bits.h
)

set(source_files
	src/backtracking-iterative.cpp
	src/efficient-next-permutation.cpp
	src/backtracking-recursive.cpp
	src/subsets-using-bits.cpp
)

# Generate static library
add_library(${libname} STATIC ${source_files} ${header_files})

if(MSVC)
    set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "lib")
endif()


# Export include folder
target_include_directories(${libname} PUBLIC include/)