cmake_minimum_required(VERSION 3.12)

project(PingPongGame VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/Debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/Release")

# Add source to this project's executable.
file(GLOB SOURCES "PingPongGame/*.cpp" "PingPongGame/*.h")

# Create the executable target
add_executable(PingPongGame ${SOURCES} "PingPongGame/game.cpp")

# Set the subsystem to "windows" for GUI applications
if(WIN32)
    set_target_properties(PingPongGame PROPERTIES WIN32_EXECUTABLE TRUE)
endif()

# Add include directories if needed
# target_include_directories(PingPongGame PRIVATE "path/to/includes")

# Enable compiler warnings (you can adjust the warning flags based on your preferences)
if(MSVC)
    target_compile_options(PingPongGame PRIVATE /W4)
else()
    target_compile_options(PingPongGame PRIVATE -Wall -Wextra -pedantic)
endif()

# TODO: Add tests if needed.

# Install target
install(TARGETS PingPongGame DESTINATION "${CMAKE_BINARY_DIR}/bin")

# Configure the build types
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)