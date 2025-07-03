//--------------------------------------------------
// Implementation of class Polynomial
//
// @author: Wild Boar
//
// @date: 2025-07-02
//--------------------------------------------------

#include "Polynomial.h"
using namespace NVL_App;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param equation The equation of the polynomial as a string
 */
Polynomial::Polynomial(const string& equation)
{
	ParseEquation(equation);
}

//--------------------------------------------------
// Evaluate
//--------------------------------------------------

/**
 * @brief Evaluate the equation for the value given for x
 * @param x The value that we are assigning x
 * @return double Returns a double
 */
double Polynomial::Evaluate(double x)
{
	auto factor = 1.0; auto result = 0.0;

	for (size_t i = 0; i < _coeffs.size(); ++i)
	{
		result += _coeffs[i] * factor;
		factor *= x;
	}

	return result;
}

//--------------------------------------------------
// Parse Equation
//--------------------------------------------------

/**
 * @brief Parse the equation and extract the coefficients
 * @param equation The equation that we are parsing
 */
void Polynomial::ParseEquation(const string& equation) 
{
	auto maxPower = -1; unordered_map<int, double> terms; auto pos = size_t(0);
	
	while (pos < equation.size()) 
	{
		double coeff = ReadNumber(equation, pos);		
		int power = ReadPower(equation, pos);
		if (coeff == 0.0) continue;

		terms[power] = coeff; if (power > maxPower) maxPower = power;
	}

	_coeffs.clear(); // Clear the coefficients vector

	for (auto i=0; i <= maxPower; ++i) 
	{
		if (terms.find(i) != terms.end()) 
		{
			_coeffs.push_back(terms[i]);
		} 
		else 
		{
			_coeffs.push_back(0.0); // Coefficient for this power is zero
		}
	}
}

/**
 * @brief Read a number from the equation string
 * @param equation The equation that we are parsing
 * @param pos The current position in the string
 * @return double Returns the number that we have read
 */
double Polynomial::ReadNumber(const string& equation, size_t& pos) 
{
	// Skip whitespace
	while (pos < equation.size() && isspace(equation[pos])) 
	{
		pos++;
	}

	if (pos >= equation.size()) 
	{
		return 0.0; // No more numbers
	}

	// Read the sign
	double sign = 1.0;
	if (equation[pos] == '-') 
	{
		sign = -1.0;
		pos++;
	} 
	else if (equation[pos] == '+') 
	{
		pos++;
	}

	// Skip whitespace
	while (pos < equation.size() && isspace(equation[pos])) 
	{
		pos++;
	}

	// Read the sign
	if (equation[pos] == '-') 
	{
		sign = -1.0;
		pos++;
	} 
	else if (equation[pos] == '+') 
	{
		pos++;
	}

	// Read the number
	double number = 0.0;
	while (pos < equation.size() && isdigit(equation[pos])) 
	{
		number = number * 10 + (equation[pos] - '0');
		pos++;
	}

	// Check for decimal point
	if (pos < equation.size() && equation[pos] == '.') 
	{
		pos++;
		double decimalPlace = 0.1;
		while (pos < equation.size() && isdigit(equation[pos])) 
		{
			number += (equation[pos] - '0') * decimalPlace;
			decimalPlace *= 0.1;
			pos++;
		}
	}

	if (number == 0.0 && equation[pos] == 'x') 
	{
		// If we encounter 'x' immediately after reading a number, it means the coefficient is 1
		number = 1.0;
	}

	return sign * number;
}

/**
 * @brief Read a power from the equation string
 * @param equation The equation that we are parsing
 * @param pos The current position in the string
 * @return double Returns the power that we have read
 */
int Polynomial::ReadPower(const string& equation, size_t& pos) 
{
	// Skip whitespace
	while (pos < equation.size() && (isspace(equation[pos]) | equation[pos] == '*')) 
	{
		pos++;
	}

	if (pos > equation.size() || equation[pos] != 'x') 
	{
		return 0; // Default power is 0 if 'x' is not found
	}

	pos++; // Skip the 'x'

	while (pos < equation.size() && isspace(equation[pos])) 
	{
		pos++;
	}

	if (pos >= equation.size() || equation[pos] != '*') 
	{
		return 1; // Default power is 0 if no power is specified
	}

	pos++; // Skip the '*'

	while (pos < equation.size() && isspace(equation[pos])) 
	{
		pos++;
	}

	if (pos < equation.size() && equation[pos] == '*') {
		pos++; // Skip the second '*'
	} 
	else 
	{
		return 1; // Default power is 1 if only one '*' is present
	}

	while (pos < equation.size() && isspace(equation[pos])) 
	{
		pos++;
	}

	int power = 0;
	while (pos < equation.size() && isdigit(equation[pos])) 
	{
		power = power * 10 + (equation[pos] - '0');
		pos++;
	}

	return power;	
}