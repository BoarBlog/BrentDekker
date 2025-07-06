//--------------------------------------------------
// Unit Tests for class PolyProblem
//
// @author: Wild Boar
//
// @date: 2025-07-06
//--------------------------------------------------

#include <gtest/gtest.h>

#include <TestRunnerLib/PolyProblem.h>
using namespace NVL_App;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Test the evaluation of a polynomial problem with a given soluion
 */
TEST(PolyProblem_Test, eval_test)
{
	// Setup
	auto coeffs = vector<double>{1.0, 2.0, 3.0, 1.0};
	auto problem = PolyProblem(coeffs);

	// Execute
	auto result = problem.Evaluate(3.0);

	// Confirm
	ASSERT_EQ(result, 61);
}

/**
 * @brief Test the gradient of a polynomial problem with a given solution
 */
TEST(PolyProblem_Test, grad_test)
{
	// Setup
	auto coeffs = vector<double>{1.0, 2.0, 3.0, 1.0};
	auto problem = PolyProblem(coeffs);

	// Set an epsilon for the gradient calculation
	const double epsilon = 1e-6;

	// Execute
	auto approx = (problem.Evaluate(3.0 + epsilon) - problem.Evaluate(3.0)) / epsilon;
	auto actual = problem.Gradient(3.0);

	// Confirm
	ASSERT_NEAR(actual, approx, 1e-4); // Allow a small margin of error for floating point comparison
}