/*
 * Problem 6 Medium
 * Key words: String
 * Link: ://leetcode.com/problems/zigzag-conversion/
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

	string convert(string s, int numRows)
	{
	    if(s.size() <= 1 || numRows == 1) return s;

	    vector<string> rows(numRows, "");
	    string ret = "";

	    for(unsigned i = 0; i < s.size(); i++)
		if(i % (2 * numRows -2) < numRows)
		    rows[i % (2 * numRows -2)] += s[i];
		else
		    rows[(2 * numRows -2) - i % (2 * numRows -2)] += s[i];

	    for(unsigned i = 0; i < rows.size(); i++)
		ret += rows[i];

	    return ret;
	}

    
};

class test_problem_6 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_6 );

        CPPUNIT_TEST( test_case_6_convert );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_6_convert();

};
