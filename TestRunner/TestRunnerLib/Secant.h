//--------------------------------------------------
// Add an implementation of the secant method for problem solving
//
// @author: Wild Boar
//
// @date: 2025-07-06
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include <opencv2/opencv.hpp>
using namespace cv;

#include "ProblemBase.h"
#include "SolverBase.h"

namespace NVL_App
{
	class Secant : public SolverBase
	{
	public:
		Secant(ProblemBase * evaluator);
		double Solve(const Vec2d& bracket) override;
	};
}
