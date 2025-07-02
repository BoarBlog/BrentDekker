//--------------------------------------------------
// Unit Tests for class Polynomial
//
// @author: Wild Boar
//
// @date: 2025-07-02
//--------------------------------------------------

#include <gtest/gtest.h>

#include <ProblemMakerLib/Polynomial.h>
using namespace NVL_App;

#include "../TestHelpers/TestUtils.h"

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Perform equation decoding tests
 */
TEST(Polynomial_Test, equation)
{
	// Setup
	auto equation_1 = "-6 - 11 * x + 7 * x ** 2 - 8 * x ** 3"; 
	auto equation_2 = "1 + 2 * x - 3 * x ** 2 + 4 * x ** 3 - 5 * x ** 4";
	auto equation_3 = "+1 + 2 * x";
	auto equation_4 = "";
	auto equation_5 = "1 + 2 * x - 3 * x ** 3 + 4 * x ** 2 - 5 * x ** 5 + 6 * x ** 4";
	auto equation_6 = "1 + 2 * x - 3 * x ** 2  - 5 * x ** 5";

	// Execute
	Polynomial polynomial_1(equation_1);
	Polynomial polynomial_2(equation_2);
	Polynomial polynomial_3(equation_3);
	Polynomial polynomial_4(equation_4);
	Polynomial polynomial_5(equation_5);
	Polynomial polynomial_6(equation_6);

	// Confirm
	NVL_Test::TestUtils::Check(polynomial_1.GetCoeffs(), vector<double>({-6, -11, 7, -8}));
	NVL_Test::TestUtils::Check(polynomial_2.GetCoeffs(), vector<double>({1, 2, -3, 4, -5}));
	NVL_Test::TestUtils::Check(polynomial_3.GetCoeffs(), vector<double>({1, 2}));
	NVL_Test::TestUtils::Check(polynomial_4.GetCoeffs(), vector<double>({}));
	NVL_Test::TestUtils::Check(polynomial_5.GetCoeffs(), vector<double>({1, 2, 4, -3, 6, -5}));
	NVL_Test::TestUtils::Check(polynomial_5.GetCoeffs(), vector<double>({1, 2, -3, 0, -5}));
}