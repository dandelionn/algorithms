set(libname infoarena)

message("Generating ${libname} library")

# Project name
project(${libname})

set(header_files
	include/algo.h
)

set(source_files
	src/algo.cpp
)

# Generate static library
add_library(${libname} STATIC ${source_files} ${header_files})

if(MSVC)
    set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "lib")
endif()


# Export include folder
target_include_directories(${libname} PUBLIC include/)