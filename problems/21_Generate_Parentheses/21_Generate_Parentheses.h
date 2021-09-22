/*
 * Problem 21 Medium
 * Key words: Recursion
 * Link: https://leetcode.com/problems/generate-parentheses/
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

    vector<string> generateParenthesis(int n)
    {
        vector<string> ret;
        string str = "";
        parenthesis_recursion(n, str, 0, 0, ret);

        return ret;
    }

    void parenthesis_recursion(int n, string str, int left, int right, vector<string> &ret)
    {
        if(left < n)
        {
            parenthesis_recursion(n, str+'(', left+1, right, ret);

            if(right < left)
                parenthesis_recursion(n, str+')', left, right+1, ret);
        }
        else
        {
            for(unsigned i = right; i < n; i++)
                str += ')';
            right = n;
        }

        if(left == n && right == n)
            ret.push_back(str);

    }

    
};

class test_problem_21 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_21 );

        CPPUNIT_TEST( test_case_21 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_21();

};
