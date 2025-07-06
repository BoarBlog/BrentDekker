//--------------------------------------------------
// Add an implementation of the bisection method for problem solving
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
	class Bisection : public SolverBase
	{
	public:
		Bisection(ProblemBase * evaluator);
		virtual double Solve(const Vec2d& bracket) override;
	};
}