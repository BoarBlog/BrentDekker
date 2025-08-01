//--------------------------------------------------
// Unit Tests for class Secant
//
// @author: Wild Boar
//
// @date: 2025-07-06
//--------------------------------------------------

#include <gtest/gtest.h>

#include <TestRunnerLib/Secant.h>
#include <TestRunnerLib/PolyProblem.h>
using namespace NVL_App;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Verify that the refinement process worked as expected
 */
TEST(Secant_Test, confirm_refinement)
{
	// Setup
	auto coeffs = std::vector<double>{ -244618248.0, 6613865.0, 321436.0, -5154.0, -76.0, 1.0 };
	auto bracket = Vec2d(-26.039999999999999, 48.039999999999999);

	auto problem = PolyProblem(coeffs);

	auto solver = Secant(&problem);

	// Execute
	auto solution = solver.Solve(bracket);

	// Confirm
	ASSERT_NEAR(solution, 23, 1e-5);
	ASSERT_GT(solver.GetIterationCount(), 5);

	cout << "Iterations Used: " << solver.GetIterationCount() << endl;
}
