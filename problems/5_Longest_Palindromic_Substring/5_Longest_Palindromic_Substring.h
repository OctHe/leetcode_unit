/*
 * Problem 5 Medium
 * Key words: Dynamic programming
 * Link: https://leetcode.com/problems/longest-palindromic-substring/
 */
#include <iostream>
#include <vector>
#include <unordered_set>
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

    string longestPalindrome(string s)
    {
        vector< vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
        string sub = "";

        if(s.size() == 0) return sub;

        // Initialization for odd case
        for(unsigned i = 0; i < s.size(); i++)
        {
            dp[i][i] = true;
            sub = s.substr(i, 1);
        }

        // Initialization for even case
        for(unsigned i = 0; i < s.size() -1; i++)
        {
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = true;
                sub = s.substr(i, 2);
            }
        }
        
        // DP
        // i: string index
        // j+1: substring length
        for(unsigned j = 2; j < s.size(); j++)
        for(unsigned i = 0; i < s.size() -j; i++)
        {
            dp[i][i+j] = (s[i] == s[i+j]) && dp[i+1][i+j-1] ? true : false;
            if(dp[i][i+j] && (j +1> sub.size()))
                sub = s.substr(i, j +1);
        }

        for(unsigned i = 0; i < s.size(); i++)
        {
            for(unsigned j =  0; j < s.size(); j++)
            {
                cout << dp[i][j] << '\t';
            }
            cout << endl;
        }

        cout << sub << endl;
        return sub;
    }

    
};

class test_problem_5 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_5 );

        CPPUNIT_TEST( test_case_5 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_5();

};
