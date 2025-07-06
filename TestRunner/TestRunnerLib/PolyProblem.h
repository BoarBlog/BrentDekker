//--------------------------------------------------
// Utilities for finding the model update for a linear model during training
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

namespace NVL_App
{
	class PolyProblem : public ProblemBase
	{
	private:
		vector<double> _coeffs;
	public:
		PolyProblem(const vector<double> coeffs);

		virtual double Evaluate(double value) override;
		virtual double Gradient(double value) override;

		inline vector<double>& GetCoeffs() { return _coeffs; }
	};
}
