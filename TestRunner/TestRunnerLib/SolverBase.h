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
		ProblemBase* _evaluator;
	public:
		SolverBase(ProblemBase * evaluator) : _iterationCount(0), _evaluator(evaluator) {}

		virtual double Solve(const Vec2d& bracket) = 0;

		inline int& GetIterationCount() { return _iterationCount; }
	protected:
		inline ProblemBase* GetEvaluator() { return _evaluator; }
		inline void IncrementCount() { _iterationCount++; }
	};
}
