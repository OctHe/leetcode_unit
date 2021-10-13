/*
 * Problem 221: Medium
 * Key words: Dynamic programming
 * Link: https://leetcode.com/problems/maximal-square/
 */
#include <iostream>
#include <climits>
#include <vector>
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

    int maximalSquare(vector<vector<char>>& matrix)
    {
        int side = 0;
        // dp[i][j] represents the maximum side length until matrix[i][j]
        vector< vector<int> > dp(matrix.size(), vector<int>(matrix[0].size(), 0));

        for(int i = 0; i < matrix.size(); i++)
            if(matrix[i][0] == '1') dp[i][0] = 1;
        for(int j = 0; j < matrix[0].size(); j++)
            if(matrix[0][j] == '1') dp[0][j] = 1;

        for(int i = 1; i < matrix.size(); i++)
        for(int j = 1; j < matrix[0].size(); j++)
            if(matrix[i][j] == '1')
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        
        for(int i = 0; i < matrix.size(); i++)
        for(int j = 0; j < matrix[0].size(); j++)
                side = max(dp[i][j], side);
                
        return side * side;
    }
    
};

class test_problem_221 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_221 );

        CPPUNIT_TEST( test_case_221 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_221();

};
