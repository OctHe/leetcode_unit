/*
 * Problem 912: Medium
 * Key words: Merge sort; Quick sort
 * Link: https://leetcode.com/problems/sort-an-array/
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

    vector<int> merge_sort(vector<int>& nums)
    {
        if(nums.size() == 1) return nums;

        int mid = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());

        left = merge_sort(left);
        right = merge_sort(right);
        
        for(unsigned i = 0, m = 0, n = 0; i < nums.size(); i++)
        {
            if(m < left.size() && n < right.size())
            {
                if(left[m] <= right[n]) nums[i] = left[m++];
                else nums[i] = right[n++];
            }
            else if(m == left.size())
            {
                nums[i] = right[n++];
            }
            else if(n == right.size())
            {
                nums[i] = left[m++];
            }
            
        }

        return nums;
    }

    void quick_sort(vector<int>& nums, int low, int high)
    {
        if(low >= high) return;

        int pivot = nums[low];
        int left = low, right = high;

        while(left < right)
        {
            // Find the number from right that is less than pivot
            while(left < right && pivot <= nums[right]) right--;
            nums[left] = nums[right];

            // Find the number from left that is larger than pivot
            while(left < right && pivot >= nums[left]) left++;
            nums[right] = nums[left];

        }

        nums[left] = pivot;

        quick_sort(nums, low, left -1);
        quick_sort(nums, left +1, high);

    }

    vector<int> sortArray(vector<int>& nums)
    {
        // Quick sort
        quick_sort(nums, 0, nums.size() -1);
        return nums;

        // Merge sort
        // return merge_sort(nums);

    }

    
};

class test_problem_912 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_912 );

        CPPUNIT_TEST( test_case_912 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_912();

};
