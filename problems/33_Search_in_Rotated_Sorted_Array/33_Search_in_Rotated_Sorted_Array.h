/*
 * Problem 33 Medium
 * Key words: Sorting an array; O(logN) complexity
 * Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
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

    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        int left = 0, right = n -1;
        int middle = (left + right) / 2;

        while(left < right)
        {
            if(nums[middle] == target) return middle;

            if(nums[left] <= nums[middle] && (target < nums[left] || target > nums[middle]))
                left = middle +1;
            else if(nums[left] <= nums[middle] && target >= nums[left] && target <= nums[middle])
                right = middle;
            else if(nums[middle +1] <= nums[right] && (target < nums[middle +1] || target > nums[right]))
                right = middle;
            else if(nums[middle +1] <= nums[right] && target >= nums[middle +1] && target <= nums[right])
                left = middle +1;

            middle = (left + right) / 2;
        }
        
        if(target == nums[middle]) return middle;
        else return -1;
    }

    
};

class test_problem_33 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_33 );

        CPPUNIT_TEST( test_case_33 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_33();

};
