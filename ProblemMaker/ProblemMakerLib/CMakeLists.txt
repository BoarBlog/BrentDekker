#--------------------------------------------------------
# CMake for generating the ProblemMakerLib
#
# @author: Wild Boar
#
# Date Created: 2025-07-02
#--------------------------------------------------------

# Setup include directories
include_directories("../" "${LIBRARY_BASE}/NVLib")

# Create Library
add_library(ProblemMakerLib STATIC
    ArgUtils.cpp
)
