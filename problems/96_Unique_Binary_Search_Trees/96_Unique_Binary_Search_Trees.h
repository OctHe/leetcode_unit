/*
 * Problem 96: Medium
 * Key words: Recursion; Dynamic programming
 * Link: https://leetcode.com/problems/unique-binary-search-trees/
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

    // Time limit exceeded
    int numTrees_recursive(int n)
    {
        int count = 0;

        if(n == 0 || n == 1) return 1;

        for(int i = 1; i <= n; i++)
            count += numTrees_recursive(i-1) * numTrees_recursive(n-i);

        return count;
    }

    int numTrees_dp(int n)
    {
        vector<int> dp(n+1, 0);
        dp[0] = 1;

        for(int i = 1; i <= n; i++)
        for(int j = 0; j < i; j++)
            dp[i] += dp[j] * dp[i-j-1];

        return dp[n];
    }

    int numTrees(int n)
    {
        // return numTrees_recursive(n);
        return numTrees_dp(n);
    }
    
};

class test_problem_96 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_96 );

        CPPUNIT_TEST( test_case_96 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_96();

};
