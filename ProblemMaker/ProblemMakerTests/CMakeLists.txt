#--------------------------------------------------------
# CMake for generating ProblemMakerLib Testing Suite
#
# @author: Wild Boar
#
# Date Created: 2025-07-02
#--------------------------------------------------------

# Add Google Test to the test group
find_package(GTest REQUIRED)

# Setup the includes
include_directories("../")

# Create the executable
add_executable (ProblemMakerTests
	TestHelpers/TestUtils.cpp
	Tests/Example_Tests.cpp
	Tests/Polynomial_Tests.cpp
)

# Add link libraries
target_link_libraries(ProblemMakerTests ProblemMakerLib NVLib ${OpenCV_LIBS} ${SYMENGINE_LIBRARIES} OpenSSL::SSL uuid GTest::Main)

# Find the associated unit tests
gtest_discover_tests(ProblemMakerTests)