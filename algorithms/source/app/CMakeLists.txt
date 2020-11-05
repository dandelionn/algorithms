message("Generating command line application")

# Project name
project(app)

set(source_files
    src/main.cpp
)

# Generate executable
add_executable(app ${source_files})
# target_link_libraries(app algolib)

#if(MSVC)
    # Include in solution group
#    set_property(TARGET app PROPERTY FOLDER "Modules/Applications")
#endif()