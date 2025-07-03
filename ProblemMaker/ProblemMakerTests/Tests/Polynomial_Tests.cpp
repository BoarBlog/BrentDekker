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

#include <symengine/expression.h>
#include <symengine/add.h>
#include <symengine/basic.h>
#include <symengine/symengine_casts.h>

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
	auto equation_7 = "x**2 - x**3";

	// Execute
	Polynomial polynomial_1(equation_1);
	Polynomial polynomial_2(equation_2);
	Polynomial polynomial_3(equation_3);
	Polynomial polynomial_4(equation_4);
	Polynomial polynomial_5(equation_5);
	Polynomial polynomial_6(equation_6);
	Polynomial polynomial_7(equation_7);

	// Confirm
	NVL_Test::TestUtils::Check(polynomial_1.GetCoeffs(), vector<double>({-6, -11, 7, -8}));
	NVL_Test::TestUtils::Check(polynomial_2.GetCoeffs(), vector<double>({1, 2, -3, 4, -5}));
	NVL_Test::TestUtils::Check(polynomial_3.GetCoeffs(), vector<double>({1, 2}));
	NVL_Test::TestUtils::Check(polynomial_4.GetCoeffs(), vector<double>({}));
	NVL_Test::TestUtils::Check(polynomial_5.GetCoeffs(), vector<double>({1, 2, 4, -3, 6, -5}));
	NVL_Test::TestUtils::Check(polynomial_6.GetCoeffs(), vector<double>({1, 2, -3, 0, 0, -5}));
	NVL_Test::TestUtils::Check(polynomial_7.GetCoeffs(), vector<double>({0, 0, 1, -1}));
}

/**
 * @brief Perform evaluation tests
 */
TEST(Polynomial_Test, evaluate)
{
	// Setup
	auto equation_1 = "-6 - 11 * x + 7 * x ** 2 + 8 * x ** 3"; 

	// Execute
	Polynomial polynomial_1(equation_1);
	auto result_1 = polynomial_1.Evaluate(3);

	// Confirm
	ASSERT_EQ(result_1, 240);
}

TEST(Polynomial_Test, symengine_test)
{
 	auto x = SymEngine::Expression("x");
    auto term_1 = x + 2;
    auto term_2 = x + 3;
    auto term_3 = x - 1;
    auto term_4 = term_1 * term_2 * term_3;
    SymEngine::Expression term_5 = SymEngine::expand(term_4);

	auto expression = term_5.get_basic()->__str__();
	cout << "Expression: " << expression << endl;

	auto polynomial = Polynomial(expression);
	auto value_1 = polynomial.Evaluate(3);
	auto value_2 = polynomial.Evaluate(-3);

	NVL_Test::TestUtils::Check(polynomial.GetCoeffs(), vector<double>({-6, 1, 4, 1}));

	auto subsitution = SymEngine::map_basic_basic();
	subsitution[x.get_basic()] = SymEngine::integer(3);	
	auto result = term_5.subs(subsitution);

	auto value_3 = SymEngine::eval_double(result);

	ASSERT_EQ(value_1, value_3);
	ASSERT_EQ(value_2, 0);
}