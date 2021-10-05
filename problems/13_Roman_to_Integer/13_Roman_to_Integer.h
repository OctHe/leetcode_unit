/*
 * Problem 13: Easy
 * Key words:
 * Link: https://leetcode.com/problems/roman-to-integer/
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <map>

#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestResult.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>

using namespace std;

class Solution 
{

public:
    // I -> 1
    // V -> 5
    // X -> 10
    // L -> 50
    // C -> 100
    // D -> 500
    // M -> 1000
    int romanToInt(string s)
    {
        int num = 0;
        map<char, int> roman_to_int_table = {
            {'M', 1000},
            {'D', 500},
            {'C', 100},
            {'L', 50},
            {'X', 10},
            {'V', 5},
            {'I', 1}
        };

        for(unsigned i = 0; i < s.size() -1; i++)
        {
            if(roman_to_int_table[s[i]] < roman_to_int_table[s[i+1]])
                num -= roman_to_int_table[s[i]];
            else
                num += roman_to_int_table[s[i]];
        }

        // The last number will always be added.
        return num + roman_to_int_table[s[s.size() -1]];
    }
    
};

class test_problem_13 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_13 );

        CPPUNIT_TEST( test_case_13 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_13();

};
