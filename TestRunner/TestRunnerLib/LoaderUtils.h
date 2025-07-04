//--------------------------------------------------
// The loader utilities that we are dealing with
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

#include "Problem.h"

namespace NVL_App
{
	class LoaderUtils
	{
	public:
		static vector<unique_ptr<Problem>> LoadProblemSet(const string& path);
	};
}