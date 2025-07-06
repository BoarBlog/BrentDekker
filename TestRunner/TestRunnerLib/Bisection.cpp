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
	throw runtime_error("Not implemented");
}