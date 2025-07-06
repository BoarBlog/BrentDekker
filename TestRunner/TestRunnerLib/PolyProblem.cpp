//--------------------------------------------------
// Implementation of class PolyProblem
//
// @author: Wild Boar
//
// @date: 2025-07-06
//--------------------------------------------------

#include "PolyProblem.h"
using namespace NVL_App;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param coeffs The coefficients for the polynomial
 */
PolyProblem::PolyProblem(const vector<double> coeffs) : _coeffs(coeffs)
{
	// Extra implementation goes here
}

//--------------------------------------------------
// Evaluator
//--------------------------------------------------

/**
 * @brief Evaluate the provider
 * @param value The value that we dealing with
 * @return double Returns a double
 */
double PolyProblem::Evaluate(double value)
{
	double result = 0.0; auto factor = 1.0;

	for (size_t i = 0; i < _coeffs.size(); ++i)
	{
		result += _coeffs[i] * factor;
		factor *= value; // Increment the factor for the next term
	}

	return result;

}

//--------------------------------------------------
// Gradient
//--------------------------------------------------

/**
 * @brief Get the gradient
 * @param value The value that we are dealing with
 * @return double Returns a double
 */
double PolyProblem::Gradient(double value)
{
	auto result = 0.0; auto factor = 1.0;

	for (size_t i = 1; i < _coeffs.size(); ++i)
	{
		result += i * _coeffs[i] * factor;
		factor *= value; // Increment the factor for the next term	
	}

	return result;
}
