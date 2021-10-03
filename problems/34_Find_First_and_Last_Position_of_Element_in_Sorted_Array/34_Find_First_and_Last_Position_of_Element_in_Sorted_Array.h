/*
 * Problem 34: Medium
 * Key words:
 * Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
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

    vector<int> searchRange(vector<int>& nums, int target)
    {
        if(nums.size() == 0) return vector<int>{-1, -1};

        int first = -1, last = -1;
        int left, mid, right;
        
        // Find first
        left = 0, right = nums.size() -1;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(nums[mid] < target)
                left = mid +1;
            if(nums[mid] > target)
                right = mid -1;
            if(nums[mid] == target)
            {
                first = mid;
                right = mid -1;
            }
            
        }

        // Find last
        left = 0, right = nums.size() -1;
        while(left <= right)
        {
            mid = (left + right) / 2;
            
            if(nums[mid] < target)
                left = mid +1;
            if(nums[mid] > target)
                right = mid -1;
            if(nums[mid] == target)
            {
                last = mid;
                left = mid +1;
            }
           
        }

        return vector<int>{first, last};
    }

    
};

class test_problem_34 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_34 );

        CPPUNIT_TEST( test_case_34 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_34();

};
