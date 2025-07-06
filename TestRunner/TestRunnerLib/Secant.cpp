//--------------------------------------------------
// Implementation of class Secant
//
// @author: Wild Boar
//
// @date: 2025-07-06
//--------------------------------------------------

#include "Secant.h"
using namespace NVL_App;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param evaluator The evaluator that we are using to validate our candidate solutions
 */
Secant::Secant(ProblemBase * evaluator) : SolverBase(evaluator)
{
	// Initialize the base class with the evaluator
}

//--------------------------------------------------
// Solve
//--------------------------------------------------

/**
 * @brief Solve a polynomial
 * @param bracket The bracket starting point
 * @return double Returns a double
 */
double Secant::Solve(const Vec2d& bracket)
{
 	auto f = [this](double x) { return GetEvaluator()->Evaluate(x); };

	auto x0 = bracket[0];
	auto x1 = bracket[1];

	// Tolerance and maximum iterations
	double tol = GetTolerance();
	int max_iter = GetMaxIterations();

    for (int i = 0; i < max_iter; ++i) 
	{
		auto x2 = x0 - f(x0) * (x1 - x0) / (f(x1) - f(x0));

		x0 = x1; // Update x0 for the next iteration
		x1 = x2; // Update x1 to the new estimate
		IncrementCount(); // Increment the iteration count

		if (std::abs(f(x1)) < tol || std::abs(x1 - x0) < tol) 
		{
			return x1; // Return the root found
		}
	}

    std::cerr << "Warning: Secant method did not converge within the maximum number of iterations.\n";
    return x1;
}
