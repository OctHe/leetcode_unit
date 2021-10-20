/*
 * Problem 64: Medium
 * Description: Given a m x n grid filled with non-negative numbers, find a path from top left to bottom
 *              right, which minimizes the sum of all numbers along its path.
 * Ideas: 1. Dynamic programming
 *          1) dp[m][n] saves all intermediate values that represent the minimum path sum
 *          2) dp[0][0] = grid[0][0]
 *          3) dp[0][j] = dp[0][j-1] + grid[0][j]
 *          4) dp[i][0] = dp[i-1][0] + grid[i][0]
 *          5) dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
 * Algorithm: [1, 3, 1]     [1,  4, 5]
 *            [1, 5, 1] ->  [2,  7, 6]
 *            [4, 2, 1]     [6, 10, 7]
 * Link: https://leetcode.com/problems/minimum-path-sum/ 
 */

#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestResult.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>

using namespace std;

class Solution 
{

public:

    int minPathSum(vector<vector<int>>& grid)
    {
        int M = grid.size(), N = grid[0].size();
        vector< vector<int> > path_sum(M, vector<int>(N, 0));

        for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
        {
            if(i == 0 && j == 0)
                path_sum[i][j] = grid[i][j];
            else if(i == 0)
                path_sum[i][j] = path_sum[i][j-1] + grid[i][j];
            else if(j == 0)
                path_sum[i][j] = path_sum[i-1][j] + grid[i][j];
            else
                path_sum[i][j] = min(path_sum[i-1][j], path_sum[i][j-1]) + grid[i][j];
        }

        return path_sum[M-1][N-1];
    }
    
};

class test_problem_64 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_64 );

        CPPUNIT_TEST( test_case_64 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_64();

};
