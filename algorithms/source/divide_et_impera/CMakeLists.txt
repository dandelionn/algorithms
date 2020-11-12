set(libname divide_et_impera)

message("Generating ${libname} library")

# Project name
project(${libname})

set(header_files
	include/binary-search.h  
	include/mergesort.h  
	include/quicksort.h
)

set(source_files
	src/binary-search.cpp
	src/mergesort.cpp
	src/quicksort.cpp
)

# Generate static library
add_library(${libname} STATIC ${source_files} ${header_files})

if(MSVC)
    set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "lib")
endif()


# Export include folder
target_include_directories(${libname} PUBLIC include/)