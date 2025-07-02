//--------------------------------------------------
// Implementation of the TestUtils class
//
// @author: Wild Boar
//
// @date: 2025-07-02
//--------------------------------------------------

#include "TestUtils.h"
using namespace NVL_Test;

//--------------------------------------------------
// Vector Comparison
//--------------------------------------------------

/**
 * @brief Compare two vectors
 * @param v_1 The first vector that we are comparing
 * @param v_2 The second vector that we are comparing
 */
void TestUtils::Check(const vector<double>& v_1, const vector<double>& v_2) 
{
    ASSERT_EQ(v_1.size(), v_2.size()) << "Vectors are of different sizes";

    for (size_t i = 0; i < v_1.size(); ++i) 
    {
        ASSERT_DOUBLE_EQ(v_1[i], v_2[i]) << "Vectors differ at index " << i;
    }
}