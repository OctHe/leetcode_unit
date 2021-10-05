/*
 * Problem 14: Easy
 * Key words:
 * Link: https://leetcode.com/problems/longest-common-prefix/
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

    string longestCommonPrefix(vector<string>& strs)
    {
        string prefix = strs[0];
        bool find_prefix = false;

        while(prefix != "" && !find_prefix)
        {
            for(unsigned i = 0; i < strs.size(); i++)
            {
                if(prefix != strs[i].substr(0, prefix.size()))
                {
                    prefix.pop_back();
                    break;
                }
                
                // Traversal all strings. All strings match the prefix
                if(i == strs.size() -1)
                    find_prefix = true;
            }
        }

        return prefix;
    }
    
};

class test_problem_14 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_14 );

        CPPUNIT_TEST( test_case_14 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_14();

};
