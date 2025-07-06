#--------------------------------------------------------
# CMake for generating TestRunnerLib Testing Suite
#
# @author: Wild Boar
#
# Date Created: 2025-07-04
#--------------------------------------------------------

# Add Google Test to the test group
find_package(GTest REQUIRED)

# Setup the includes
include_directories("../")

# Create the executable
add_executable (TestRunnerTests
	Tests/Example_Tests.cpp
	Tests/PolyProblem_Tests.cpp
	Tests/Bisection_Tests.cpp
)

# Add link libraries
target_link_libraries(TestRunnerTests TestRunnerLib NVLib ${OpenCV_LIBS} OpenSSL::SSL uuid GTest::Main)

# Find the associated unit tests
gtest_discover_tests(TestRunnerTests)