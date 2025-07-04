//--------------------------------------------------
// The details of a problem
//
// @author: Wild Boar
//
// @date: 2025-07-04
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include <opencv2/opencv.hpp>
using namespace cv;

namespace NVL_App
{
	class Problem
	{
	private:
		vector<double> _coefficient;
		Vec2d _bracket;
		double _root;
	public:
		Problem(vector<double>& coefficient, Vec2d& bracket, double root) :
			_coefficient(coefficient), _bracket(bracket), _root(root) {}

		inline vector<double>& GetCoefficient() { return _coefficient; }
		inline Vec2d& GetBracket() { return _bracket; }
		inline double& GetRoot() { return _root; }
	};
}
