//--------------------------------------------------
// A representation of a working polynomial within the system
//
// @author: Wild Boar
//
// @date: 2025-07-02
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include <opencv2/opencv.hpp>
using namespace cv;

namespace NVL_App
{
	class Polynomial
	{
		private:
			vector<double> _coeffs;
		public:
			Polynomial(const string& equation);

			double Evaluate(double x);

			inline vector<double>& GetCoeffs() { return _coeffs; }
	};
}
