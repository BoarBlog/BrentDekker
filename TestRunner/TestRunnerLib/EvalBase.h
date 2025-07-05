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
	class EvalBase
	{
	public:
		EvalBase() {}
		virtual double Evaluate(double value) = 0;
		virtual double Gradient(double value) = 0;
	};
}
