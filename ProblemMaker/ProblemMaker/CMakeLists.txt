#--------------------------------------------------------
# CMake for generating the main executable
#
# @author: Wild Boar
#
# Date Created: 2025-07-02
#--------------------------------------------------------

# Setup the includes
include_directories("../")

# Create the executable
add_executable(ProblemMaker
    Engine.cpp
    Source.cpp
)

# Add link libraries                               
target_link_libraries(ProblemMaker ProblemMakerLib  NVLib ${OpenCV_LIBS} ${SYMENGINE_LIBRARIES} OpenSSL::SSL uuid)

# Copy Resources across
add_custom_target(resource_copy ALL
	COMMAND cmake -E copy_directory ${CMAKE_SOURCE_DIR}/Resources ${CMAKE_BINARY_DIR}/ProblemMaker 
    DEPENDS ${MY_TARGET}
)
