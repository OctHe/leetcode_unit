/*
 * Problem 20 Easy
 * Key words: Stack
 * Link: https://leetcode.com/problems/valid-parentheses/
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <stack>

#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestResult.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>

using namespace std;

class Solution 
{

public:

    bool isValid(string s)
    {
        map<char, char> parenthesis = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

        stack<char> elements;

        for(unsigned i = 0; i < s.size(); i++)
        {
            if(elements.empty()) 
                elements.push(s[i]);
            else
            {
                if(parenthesis[elements.top()] == s[i])
                    elements.pop();
                else
                    elements.push(s[i]);
            }
        }
        
        return elements.empty();
    }

    
};

class test_problem_20 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_20 );

        CPPUNIT_TEST( test_case_20 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_20();

};
