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

#include "EvalBase.h"

namespace NVL_App
{
	class SolverBase
	{
	private:
		int _iterationCount;
		EvalBase* _evaluator;
	public:
		SolverBase(EvalBase * evaluator) : _iterationCount(0), _evaluator(evaluator) {}

		virtual double Solve(const Vec2d& bracket) = 0;

		inline int& GetIterationCount() { return _iterationCount; }
	};
}
