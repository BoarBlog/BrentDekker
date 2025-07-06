//--------------------------------------------------
// Implementation of class BrentDekker
//
// @author: Wild Boar
//
// @date: 2025-07-06
//--------------------------------------------------

#include "BrentDekker.h"
using namespace NVL_App;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param evaluator The evaluator that we are using to validate our candidate solutions
 */
BrentDekker::BrentDekker(ProblemBase * evaluator) : SolverBase(evaluator)
{
	// Initialize the solver with the evaluator
}

//--------------------------------------------------
// Solve
//--------------------------------------------------

/**
 * @brief Solve a polynomial
 * @param bracket The bracket starting point
 * @return double Returns a double
 */
double BrentDekker::Solve(const Vec2d& bracket)
{
	throw runtime_error("Not implemented");
}