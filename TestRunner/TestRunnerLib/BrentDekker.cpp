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
	auto f = [this](double x) { return GetEvaluator()->Evaluate(x); };

	auto a = bracket[0];
	auto b = bracket[1];

	// Tolerance and maximum iterations
	double tol = GetTolerance();
	int max_iter = GetMaxIterations();

	double fa = f(a);
    double fb = f(b);

    if (fa * fb >= 0) 
	{
        throw std::invalid_argument("Function must have opposite signs at endpoints a and b.");
    }

    double c = a, fc = fa;
    bool mflag = true;
    double s = b;
    double d = 0;

    for (int iter = 0; iter < max_iter; ++iter) {
        // Swap so that f(b) is the best approximation
        if (fa != fc && fb != fc) 
		{
            // Inverse quadratic interpolation
            s = (a * fb * fc) / ((fa - fb) * (fa - fc)) +
                (b * fa * fc) / ((fb - fa) * (fb - fc)) +
                (c * fa * fb) / ((fc - fa) * (fc - fb));
        } 
		else 
		{
            // Secant method
            s = b - fb * (b - a) / (fb - fa);
        }

        double condition1 = (s < (3 * a + b) / 4 || s > b);
        double condition2 = (mflag && std::abs(s - b) >= std::abs(b - c) / 2);
        double condition3 = (!mflag && std::abs(s - b) >= std::abs(c - d) / 2);
        double condition4 = (mflag && std::abs(b - c) < tol);
        double condition5 = (!mflag && std::abs(c - d) < tol);

        if (condition1 || condition2 || condition3 || condition4 || condition5) 
		{
            // Bisection method fallback
            s = (a + b) / 2;
            mflag = true;
        } 
		else 
		{
            mflag = false;
        }

        double fs = f(s);
        d = c;
        c = b;
        fc = fb;

        if (fa * fs < 0) 
		{
            b = s;
            fb = fs;
        } else 
		{
            a = s;
            fa = fs;
        }

        if (std::abs(fa) < std::abs(fb)) 
		{
            std::swap(a, b);
            std::swap(fa, fb);
        }

        if (std::abs(fb) < tol) 
		{
            return b;
        }

		IncrementCount();
    }

    std::cerr << "Warning: Brent Dekker method did not converge within the maximum number of iterations.\n";
    return b;
}