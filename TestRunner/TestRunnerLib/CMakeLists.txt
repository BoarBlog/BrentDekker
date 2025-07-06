#--------------------------------------------------------
# CMake for generating the TestRunnerLib
#
# @author: Wild Boar
#
# Date Created: 2025-07-04
#--------------------------------------------------------

# Setup include directories
include_directories("../" "${LIBRARY_BASE}/NVLib")

# Create Library
add_library (TestRunnerLib STATIC
	ArgUtils.cpp
	LoaderUtils.cpp
	PolyProblem.cpp
	Bisection.cpp
	Secant.cpp
)
