/*
 * Problem 1: Easy
 * Key words:
 * Link: https://leetcode.com/problems/two-sum/
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

    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> sum;
        int result;
        for(int i = 0; i < nums.size(); i++)
        {
            result = target - nums[i];
            for(int j = i+1; j < nums.size(); j++)
            {
                if(result == nums[j])
                {
                    sum.push_back(i);
                    sum.push_back(j);
                }
            }
        }
        return sum;
    }

};

class test_problem_1 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_1 );

        CPPUNIT_TEST( test_case_1 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_1();

};
