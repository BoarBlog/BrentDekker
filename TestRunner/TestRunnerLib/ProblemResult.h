//--------------------------------------------------
// Defines the result of a problem
//
// @author: Wild Boar
//
// @date: 2025-07-06
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

namespace NVL_App
{
	class ProblemResult
	{
	private:
		string _algorithms;
		int _iterations;
		bool _matchExpected;
		bool _validResult;
	public:
		ProblemResult(const string& algorithms, int iterations, bool matchExpected, bool validResult) :
			_algorithms(algorithms), _iterations(iterations), _matchExpected(matchExpected), _validResult(validResult) {}

		inline string& GetAlgorithms() { return _algorithms; }
		inline int& GetIterations() { return _iterations; }
		inline bool GetMatchExpected() { return _matchExpected; }
		inline bool GetValidResult() { return _validResult; }
	};
}