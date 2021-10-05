/*
 * Problem 12: Medium
 * Key words: Table;
 * Link: https://leetcode.com/problems/integer-to-roman/
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
    // I -> 1
    // IV -> 4
    // V -> 5
    // IX -> 9
    // X -> 10
    // L -> 50
    // C -> 100
    // D -> 500
    // M -> 1000
    string intToRoman(int num)
    {
        vector<int> int_table = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> roman_table = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string roman;
        for(unsigned i = 0; i < int_table.size(); i++)
        {
            while(num >= int_table[i])
            {
                num -= int_table[i];
                roman += roman_table[i];
            }
        }

        return roman;
        
    }
    
};

class test_problem_12 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_12 );

        CPPUNIT_TEST( test_case_12 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_12();

};
