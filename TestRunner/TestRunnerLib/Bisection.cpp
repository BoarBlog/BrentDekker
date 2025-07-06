//--------------------------------------------------
// Implementation of class Bisection
//
// @author: Wild Boar
//
// @date: 2025-07-06
//--------------------------------------------------

#include "Bisection.h"
using namespace NVL_App;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param evaluator The evaluator that we are using to validate our candidate solutions
 */
Bisection::Bisection(ProblemBase * evaluator) : SolverBase(evaluator)
{
	// Extra implementation can go here if needed
}

//--------------------------------------------------
// Solve
//--------------------------------------------------

/**
 * @brief Solve a polynomial
 * @param bracket The bracket starting point
 * @return double Returns a double
 */
double Bisection::Solve(const Vec2d& bracket)
{
	auto f = [this](double x) { return GetEvaluator()->Evaluate(x); };

	double a = bracket[0];
	double b = bracket[1];
	double tol = GetTolerance(); // Tolerance for convergence
	int max_iter = GetMaxIterations(); // Maximum iterations

	// Check if the initial interval is valid
  	if (f(a) * f(b) >= 0) 
	{
        std::cerr << "Invalid interval: f(a) and f(b) must have opposite signs." << std::endl;
        return std::numeric_limits<double>::quiet_NaN();
    }

    double c;
    for (int i = 0; i < max_iter; ++i) 
	{
        c = (a + b) / 2;
        double fc = f(c);

        // Check if solution is found or interval is small enough
        if (std::abs(fc) < tol || (b - a) / 2 < tol) 
		{
            return c;
        }

        // Narrow down the interval
        if (f(a) * fc < 0)
            b = c;
        else
            a = c;
		
		IncrementCount();
	}


    std::cerr << "Maximum iterations reached without convergence." << std::endl;
    return c;
}