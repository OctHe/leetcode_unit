/*
 * Problem 66: Easy
 * Key words: Carry
 * Link: https://leetcode.com/problems/plus-one/
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

    vector<int> plusOne(vector<int>& digits)
    {

        for(int i = digits.size() -1; i >= 0; i--)
        {
            if(digits[i] == 9)
                digits[i] = 0;
            else
            {
                digits[i]++;
                break;
            }
        }

        // Deal with digits[0] is `9'
        if(digits[0] == 0)
        {
            digits[0] = 1;
            digits.push_back(0);
        }

        return digits;
    }
    
};

class test_problem_66 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_66 );

        CPPUNIT_TEST( test_case_66 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_66();

};
