/*
 * Problem 139: Medium
 * Key words: Dynamic programming
 * Link: https://leetcode.com/problems/word-break/
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

    /*
     * The importance of dynamic programming:
     * 1. The problem can be divided into multiple sub-problems.
     * 2. Dynamic programming wants to solve the sub-problmes only once.
     * 3. It will save the results of sub-problems in a table.
     */
    bool wordBreak(string s, vector<string>& wordDict)
    {
        vector<bool> dp(s.size() +1, false);
        dp[0] = true;   // "" can be breaked by any wordDict
        
        for(int i = 0; i <= s.size(); i++)
            for(string str : wordDict)
                if(dp[i] && (i+str.size() <= s.size()) && s.substr(i, str.size()) == str)
                    dp[i+str.size()] = true;
        
        return dp[s.size()];
    }
    
};

class test_problem_139 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_139 );

        CPPUNIT_TEST( test_case_139 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_139();

};
