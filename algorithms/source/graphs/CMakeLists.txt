set(libname graphs)

message("Generating ${libname} library")

# Project name
project(${libname})

set(header_files
	include/minimum-cost-spanning-tree-kruskal.h  
	include/minimum-cost-spanning-tree-prim.h
	include/algorithm-discovering-road-with-minimal-cost.h
	include/dijkstra-algorithm.h
	include/minimum-cost-spanning-tree-kruskal.h
	include/minimum-cost-spanning-tree-prim.h
	include/roy-floyd.h
	include/roy-warshall-algoritm-for-discovering-road-matrix.h
)

set(source_files
	src/minimum-cost-spanning-tree-kruskal.cpp  
	src/minimum-cost-spanning-tree-prim.cpp
	src/algorithm-discovering-road-with-minimal-cost.cpp
	src/dijkstra-algorithm.cpp
	src/minimum-cost-spanning-tree-kruskal.cpp
	src/minimum-cost-spanning-tree-prim.cpp
	src/roy-floyd.cpp
	src/roy-warshall-algoritm-for-discovering-road-matrix.cpp
)

# Generate static library
add_library(${libname} STATIC ${source_files} ${header_files})

if(MSVC)
    set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "lib")
endif()


# Export include folder
target_include_directories(${libname} PUBLIC include/)