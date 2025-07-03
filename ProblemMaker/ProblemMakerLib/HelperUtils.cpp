//--------------------------------------------------
// Implementation of class HelperUtils
//
// @author: Wild Boar
//
// @date: 2025-07-02
//--------------------------------------------------

#include "HelperUtils.h"
using namespace NVL_App;

//--------------------------------------------------
// Roots
//--------------------------------------------------

/**
 * @brief Generate a set of random roots
 * @param count The number of roots that we are generating
 * @return vector<double> Returns a vector<double>
 */
vector<double> HelperUtils::GetRoots(int count)
{
	auto duplicates = unordered_set<int>();

	while (duplicates.size() < count)
	{
		int root = NVLib::RandomUtils::GetInteger(-100, 100);
		duplicates.insert(root);
	}

	auto result = vector<double>(duplicates.size());
	auto it = duplicates.begin();
	for (size_t i = 0; i < result.size(); ++i, ++it)
	{
		result[i] = *it;
	}
	
	sort(result.begin(), result.end());

	return result;
}

//--------------------------------------------------
// Equation
//--------------------------------------------------

/**
 * @brief Generate the equation
 * @param roots The roots that we want to from an equation
 * @return string Returns a string
 */
string HelperUtils::GetEquation(const vector<double>& roots)
{
	auto x = SymEngine::Expression("x");

	if (roots.size() < 3) throw runtime_error("At least 3 roots are required to form a polynomial equation.");

	auto baseTerm = x - roots[0];

	for (size_t i = 1; i < roots.size(); ++i)
	{
		auto nextTerm = x - roots[i];
		baseTerm = baseTerm * nextTerm;
	}

	return SymEngine::expand(baseTerm).get_basic()->__str__();
}

//--------------------------------------------------
// Bracket
//--------------------------------------------------

/**
 * @brief Generate a bracket
 * @param polynomial The polynomial that we are getting the bracket for
 * @param a The lower bound of the bracket
 * @param b The upper bound of the bracket
 * @param root The root that we want a bracket that we are dealing with
 * @return Vec2d Returns a Vec2d
 */
Vec2d HelperUtils::GetBracket(Polynomial * polynomial, double a, double b, double root)
{
	auto range = b - a; auto step = range / 100.0;

	auto min = a + step;
	auto max = b - step;

	auto evalMin = polynomial->Evaluate(min);
	auto evalMax = polynomial->Evaluate(max);

	auto sign = evalMax * evalMin < 0 ? -1 : 1;
	assert(sign == -1); // verify that the signs are different

	return Vec2d(min, max);		
}