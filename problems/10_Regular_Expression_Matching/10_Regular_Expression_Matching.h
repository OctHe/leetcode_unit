/*
 * Problem 10 Hard
 * Key words: Dynamic programming
 * Link: https://leetcode.com/problems/regular-expression-matching/
 */
#include <iostream>
#include <vector>
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

    bool isMatch(string s, string p)
    {
        // we use s.size()+1 and p.size()+1 to deal with the empty case of s and p.
        vector< vector<bool> > dp(s.size()+1, vector<bool>(p.size()+1, false));

       // Initialization 1: An empty pattern matches an empty string
        dp[0][0] = true;
        
        // Initialization 2: p is empty (The 1st row is always false because p is empty)
        // Initialization 2 can be omitted.
        // Initialization 3: s is empty (The 1st column)
        //  Complicate case of '*' (Other char can not be true):
        //      1. dp[0][j+1] may be true when p[j] == '*' 
        //          and '*' represents 0 times of the previous char
        //      2. '*' cannot be the first char of p
        for(unsigned j = 0; j < p.size(); j++)
            if(p[j] == '*' && (j != 0)) dp[0][j+1] = dp[0][j-1];

        // Dynamic programming for dp table
        for(unsigned i = 0; i < s.size(); i++)
        for(unsigned j = 0; j < p.size(); j++)
            if(p[j] == '*' && j != 0)   // '*' cannot be the first char of p
            {
                // when p[j] == '*', we must handle 3 cases as following,
                // any of case impacts dp[i+1][j+1], so we use || for the cases.
                // case 1: '*' represents 0 time of p[j-1] (dp[i+1][j+1] = dp[i+1][j-1]).
                // case 2: '*' represents 1 time of p[j-1] (dp[i+1][j+1] = dp[i+1][j]),
                //          so '*' can be ignored in this case.
                dp[i+1][j+1] = dp[i+1][j-1] || dp[i+1][j];
                
                // case 3: '*' represents multiple times of p[j-1].
                // In case 3, we need to deal with '.' and other chars.
                 // ".*" can match any string, so we do not need to consider s[i-1] and [j-1]
                if(p[j-1] == '.')
                    dp[i+1][j+1] = dp[i+1][j+1] || dp[i][j+1];
                else
                    if(i != 0)  // if i == 0, case 3 can be ignored
                        dp[i+1][j+1] =  dp[i+1][j+1] || (dp[i][j+1] && (s[i] == s[i-1]) && (s[i] == p[j-1]));
            }
            else if(p[j] == '.')
                dp[i+1][j+1] = dp[i][j];
            else
                dp[i+1][j+1] = dp[i][j] && ((s[i] == p[j]) ? true : false);

        return dp[s.size()][p.size()];
    }

    
};

class test_problem_10 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_10 );

        CPPUNIT_TEST( test_case_10_complicate_cases );
        CPPUNIT_TEST( test_case_10_repeat_zero_time );
        CPPUNIT_TEST( test_case_10_repeat_one_time );
        CPPUNIT_TEST( test_case_10_dot_cases );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_10_complicate_cases();
        void test_case_10_repeat_zero_time();
        void test_case_10_repeat_one_time();
        void test_case_10_dot_cases();

};
