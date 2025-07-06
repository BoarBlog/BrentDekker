//--------------------------------------------------
// Add an implementation of the Brent Dekker method for problem solving
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

#include "SolverBase.h"

namespace NVL_App
{
	class BrentDekker : public SolverBase
	{
	public:
		BrentDekker(ProblemBase * evaluator);
		double Solve(const Vec2d& bracket);
	};
}