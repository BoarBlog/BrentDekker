#--------------------------------------------------------
# Top-Level: ProblemMaker
#
# @author: Wild Boar
#
# @Date Created: 2025-07-02
#--------------------------------------------------------

# Create the main application
cmake_minimum_required(VERSION 3.12.0)
project(ProblemMaker VERSION 1.0.0)

# Set the correct version of C++
set(CMAKE_CXX_STANDARD 17)

# Setup base directory
set(LIBRARY_BASE $ENV{HOME}/Libraries)

# Setup the includes for the libraries
include_directories("../" "${LIBRARY_BASE}/NVLib")

# Add the NVLib library to the folder
add_library(NVLib STATIC IMPORTED)
set_target_properties(NVLib PROPERTIES
    IMPORTED_LOCATION "${LIBRARY_BASE}/NVLib/build/NVLib/libNVLib.a"
    INTERFACE_INCLUDE_DIRECTORIES "${LIBRARY_BASE}/NVLib"
)

# Add opencv to the solution
find_package( OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

# Include OpenSSL
find_package(OpenSSL REQUIRED)

# Include SymEngine
find_package(SymEngine REQUIRED)

# Add the available subfolders
add_subdirectory(ProblemMakerLib)
add_subdirectory(ProblemMakerTests)
add_subdirectory(ProblemMaker)
