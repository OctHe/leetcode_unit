/*
 * Problem 279: Medium
 * Key words: Dynamic programming; Breadth-first search
 * Link: https://leetcode.com/problems/perfect-squares/
 */
#include <iostream>
#include <cmath>
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

    int num_squares_dp(int n)
    {
        vector<int> dp(n+1, n);
        
        dp[0] = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j*j <= i; j++)
                dp[i] = min(dp[i], dp[i-j*j] +1);
        
        return dp.back();
    }

    // Time limit exceeded
    int num_squares_backtrack(int n)
    {
        int res = n;

        for(int i = sqrt(n); i >= 1; i--)
        {
            if(n == i*i) 
                return 1;
            else 
                res = min(num_squares_backtrack(n - i*i) +1, res);

        }

        return res;
    }

    int numSquares(int n)
    {
        // return num_squares_backtrack(n);
        return num_squares_dp(n);
    }
    
};

class test_problem_279 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_279 );

        CPPUNIT_TEST( test_case_279 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_279();

};
