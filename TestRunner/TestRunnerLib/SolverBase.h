//--------------------------------------------------
// Base class for a solver
//
// @author: Wild Boar
//
// @date: 2025-07-05
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include <opencv2/opencv.hpp>
using namespace cv;

#include "ProblemBase.h"

namespace NVL_App
{
	class SolverBase
	{
	private:
		int _iterationCount;
		int _maxIterations; // Default maximum iterations
		double _tolerance; // Default tolerance for convergence
		ProblemBase* _evaluator;
	public:
		SolverBase(ProblemBase * evaluator, double tolerance = 1e-8, int maxIterations = 1000000) : _iterationCount(0), _evaluator(evaluator), _tolerance(tolerance), _maxIterations(maxIterations) {}

		virtual double Solve(const Vec2d& bracket) = 0;

		inline int& GetIterationCount() { return _iterationCount; }
	protected:
		inline ProblemBase* GetEvaluator() { return _evaluator; }
		inline void IncrementCount() { _iterationCount++; }
		inline int GetMaxIterations() const { return _maxIterations; }
		inline double GetTolerance() const { return _tolerance; }
	};
}
