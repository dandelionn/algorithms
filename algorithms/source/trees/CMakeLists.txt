set(libname trees)

message("Generating ${libname} library")

# Project name
project(${libname})

set(header_files
	include/binary_search_tree.h
	include/custom_type.h
	include/dynamic_binary_tree_parse.h
	include/dynamic_tree.h
	include/heap.h
	include/left_right_child_representation.h
	include/parent_childtype_representation.h
	include/static_binary_tree_parse.h
	include/tree_traversal.h
)

set(source_files
	src/binary_search_tree.cpp
	src/dynamic_binary_tree_parse.cpp
	src/dynamic_tree.cpp
	src/heap.cpp
	src/left_right_child_representation.cpp
	src/parent_childtype_representation.cpp
	src/static_binary_tree_parse.cpp
	src/tree_traversal.cpp
)

# Generate static library
add_library(${libname} STATIC ${source_files} ${header_files})

if(MSVC)
    set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "lib")
endif()


# Export include folder
target_include_directories(${libname} PUBLIC include/)