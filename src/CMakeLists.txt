cmake_minimum_required(VERSION 4.1)
project(Rasterization)

# Find GLFW package
find_package(glfw3 CONFIG REQUIRED)

add_executable(Main MACOSX_BUNDLE 
                Main.cpp
                2DVector.cpp
                3DVector.cpp
                Triangle.cpp
                ProjectionMath.cpp
                Window.cpp)

# Link GLFW to your executable
target_link_libraries(Main glfw)

# Include necessary frameworks for macOS
if(APPLE)
    find_library(COCOA_LIBRARY Cocoa)
    find_library(IOKIT_LIBRARY IOKit)
    find_library(COREVIDEO_LIBRARY CoreVideo)
    find_library(COREFOUNDATION_LIBRARY CoreFoundation)
    find_library(OPENGL_FRAMEWORK OpenGL)

    target_link_libraries(Main
        ${COCOA_LIBRARY}
        ${IOKIT_LIBRARY}
        ${COREVIDEO_LIBRARY}
        ${COREFOUNDATION_LIBRARY}
        ${OPENGL_FRAMEWORK}
    )
endif()