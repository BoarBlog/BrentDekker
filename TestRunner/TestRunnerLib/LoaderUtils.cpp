//--------------------------------------------------
// Implementation of class LoaderUtils
//
// @author: Wild Boar
//
// @date: 2025-07-04
//--------------------------------------------------

#include "LoaderUtils.h"
using namespace NVL_App;

//--------------------------------------------------
// ProblemSet
//--------------------------------------------------

/**
 * @brief Load the problem set from disk
 * @param path The path that we are loading from
 * @return vector<unique_ptr<Problem>> Returns a vector<unique_ptr<Problem>>
 */
vector<shared_ptr<Problem>> LoaderUtils::LoadProblemSet(const string& path)
{
 	auto reader = FileStorage(path, FileStorage::READ | FileStorage::FORMAT_XML);
    vector<shared_ptr<Problem>> problems;

    if (!reader.isOpened()) throw runtime_error("Failed to open XML File: " + path);

    // Iterate through all top-level nodes
    for (auto it = reader.root().begin(); it != reader.root().end(); ++it) 
	{
		auto node = *it;

        if (node.name() == std::string("problem")) 
		{
            auto problem = ReadProblem(*it);
            problems.push_back(problem);
        }
    }

    reader.release();

	return problems;
}

/**
 * Read a problem
 * @brief node That we are dealing with
 */
shared_ptr<Problem> LoaderUtils::ReadProblem(const cv::FileNode& node) 
{
    auto coeffs = vector<double>();
	auto bracket = Vec2d();
	auto root = 0.0;
    
	// Read coefficients
    cv::FileNode coeffsNode = node["coeffs"];
    if (!coeffsNode.empty()) {
        for (auto it = coeffsNode.begin(); it != coeffsNode.end(); ++it) {
            coeffs.push_back((double)*it);
        }
    }

    // Read bracket
    cv::FileNode bracketNode = node["bracket"];
    if (!bracketNode.empty() && bracketNode.size() == 2) 
	{
        bracket[0] = (double)bracketNode[0];
        bracket[1] = (double)bracketNode[1];
    }

    // Read root (optional)
    if (!node["root"].empty()) root = (double)node["root"];
    else root = std::numeric_limits<double>::quiet_NaN();  // use NaN if missing
    
	// Return the value
	return make_shared<Problem>(coeffs, bracket, root);
}