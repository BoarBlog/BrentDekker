//--------------------------------------------------
// Base class for the evaluator
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

namespace NVL_App
{
	class ProblemBase
	{
	public:
		ProblemBase() {}
		virtual double Evaluate(double solution) = 0;
		virtual double Gradient(double solution) = 0;
	};
}
