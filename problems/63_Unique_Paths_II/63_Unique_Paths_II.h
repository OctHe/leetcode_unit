/*
 * Problem 63: Medium
 * Description: A robot is located at the top-left corner of a m x n grid.
 *              The robot can only move either down or right at any point in time. The robot is 
 *              trying to reach the bottom-right corner of the grid.
 *              Now consider if some obstacles are added to the grids. How many unique paths 
 *              would there be?
 *              An obstacle and space is marked as 1 and 0 respectively in the grid.
 * Ideas: 1. The native idea is dynamic programming
 *              1) Intermediate results are saved in dp[n][n], where dp[0][0] = 1;
 *              2) dp[0][j] = dp[0][j-1] && !obstacleGrid[0][j], where 1 <= j < n;
 *              3) dp[i][j] = (dp[i-1][j] + dp[i][j-1]) && !obstacleGrid[i][j]
 * Algorithm:   [0, 0, 0]       [1, 1, 1]
 *              [0, 1, 0]   ->  [1, 0, 1]
 *              [0, 0, 0]       [1, 1, 2]
 * Link: https://leetcode.com/problems/unique-paths-ii/
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

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int M = obstacleGrid.size(), N = obstacleGrid[0].size();
        vector< vector<int> > dp(M, vector<int>(N, 0));


        for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
        {
            if(obstacleGrid[i][j] == 1)
            {
                dp[i][j] = 0;
                continue;
            }

            if(i == 0 && j == 0)
                dp[i][i] = 1;
            else if(i == 0)
                dp[i][j] = dp[i][j-1];
            else if(j == 0)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];

        }

        return dp[M-1][N-1];
    }
    
};

class test_problem_63 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_63 );

        CPPUNIT_TEST( test_case_63 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_63();

};
