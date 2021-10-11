/*
 * Problem 91: Medium
 * Key words: Dynamic programming
 * Link: https://leetcode.com/problems/decode-ways/
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

    int numDecodings_v1(string s) 
    {
        vector<int> dp(s.size() +1, 0);
        dp[0] = 1; dp[1] = s[0] == '0' ? 0 : 1;

        // s.size() > 2  
        for(int i = 1; i < s.size(); i++)
            /*
             * 1. Case 1: dp[i-1] is the cases with single s[i]
             * 2. Case 2: dp[i-2] is the cases with single s[i-1], 
             *      s[i-1] can combined with s[i]
             * 3. Case 3: "00"
             */
            // 11-19, 21-26
            if(s[i-1] == '1' && s[i] > '0' || s[i-1] == '2' && s[i] <= '6' && s[i] > '0')
                dp[i+1] = dp[i] + dp[i-1];      // Case 1 and Case 2
            // 10, 20
            else if((s[i-1] == '1' || s[i-1] == '2') && s[i] == '0')
                dp[i+1] = dp[i-1];                // Case 2
            // 00, 30, 40, 50, 60, 70, 80, 90
            else if((s[i-1] == '0' || s[i-1] > '2') && s[i] == '0')
                dp[i+1] = 0;
            // 01-09, 27-29, 31-39, 41-49, 51-59, 61-69, 71-79, 81-89, 91-99
            else
                dp[i+1] = dp[i];                // Case 1

        return dp[s.size()];
    }

    // Version 2 is the same logic as version 1, but the code is simpler
    int numDecodings_v2(string s)
    {
        vector<int> dp(s.size() +1, 0);
        dp[0] = 1; dp[1] = s[0] == '0' ? 0 : 1;
 
        for(int i = 1; i < s.size(); i++)
        {
            /*
             * 1. Case 1: dp[i] is the cases with single s[i] (i.e., "s[i]")
             * 2. Case 2: dp[i-1] is the cases with single s[i-1], 
             *      s[i-1] can combined with s[i] (i.e., "s[i-1] s[i]")
             */
            // 10-26
            if(s[i-1] == '1' || s[i-1] == '2' && s[i] <= '6')
                dp[i+1] += dp[i-1];                // Case 2
            // 01-09, 11-19, 21-29, 31-39, 41-49, 51-59, 61-69, 71-79, 81-89, 91-99
            if(s[i] != '0')
                dp[i+1] += dp[i];                // Case 1

        }

        return dp[s.size()];
    }

    int numDecodings(string s)
    {
        return numDecodings_v1(s);
        // return numDecodings_v2(s);
    }
    
};

class test_problem_91 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_91 );

        CPPUNIT_TEST( test_case_91 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_91();

};
