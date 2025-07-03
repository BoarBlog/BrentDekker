//--------------------------------------------------
// A set of utilities for the generation of problems
//
// @author: Wild Boar
//
// @date: 2025-07-02
//--------------------------------------------------

#pragma once

#include <unordered_set>
#include <iostream>
using namespace std;

#include <opencv2/opencv.hpp>
using namespace cv;

#include <symengine/expression.h>
#include <symengine/add.h>
#include <symengine/basic.h>
#include <symengine/symengine_casts.h>

#include <NVLib/RandomUtils.h>

#include "Polynomial.h"

namespace NVL_App
{
	class HelperUtils
	{
	public:
		static vector<double> GetRoots(int count);
		static string GetEquation(const vector<double>& roots);
		static Vec2d GetBracket(Polynomial * polynomial, double root);
	};
}