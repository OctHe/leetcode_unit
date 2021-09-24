/*
 * Problem 11: Medium
 * Key words:
 * Link: https://leetcode.com/problems/container-with-most-water/
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

    int maxArea(vector<int>& height)
    {
        int i = 0, j = height.size() -1;
        int max_water = (j - i) * min(height[i], height[j]);

        int left_water = 0, right_water = 0;

        while(i < j)
        {
            max_water = max(max_water, (j - i) * min(height[i], height[j]));
            if(height[i] > height[j])
                j--;
            else
                i++;
        }
        
        return max_water;
    }

    
};

class test_problem_11 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_11 );

        CPPUNIT_TEST( test_case_11 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_11();

};
