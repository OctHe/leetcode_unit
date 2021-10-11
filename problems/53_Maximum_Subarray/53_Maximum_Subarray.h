/*
 * Problem 53: Easy
 * Key words: dynamic programming
 * Link: https://leetcode.com/problems/maximum-subarray/
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

    int maxSubArray(vector<int>& nums)
    {
        int candidate = nums[0], max_value = nums[0];

        for(unsigned i = 1; i < nums.size(); i++)
        {
            // candidate saves the maximum sum from nums[i] to nums[i];
            candidate = max(candidate + nums[i], nums[i]);

            max_value = max(max_value, candidate);
        }

        return max_value;
    }
    
};

class test_problem_53 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_53 );

        CPPUNIT_TEST( test_case_53 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_53();

};
