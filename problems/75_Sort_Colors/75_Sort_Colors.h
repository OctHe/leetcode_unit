/*
 * Problem 75: Medium
 * Key words: Two pointers
 * Link: https://leetcode.com/problems/sort-colors/
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

    void sortColors(vector<int>& nums)
    {
        int left = 0, right = nums.size() -1;

        for(int i = 0; i <= right; )
            if(i > left && nums[i] == 0)
                swap(nums[left++], nums[i]);
            else if(nums[i] == 2)
                swap(nums[right--], nums[i]);
            else if(i == left || nums[i] == 1)
                i++;

    }
    
};

class test_problem_75 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_75 );

        CPPUNIT_TEST( test_case_75 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_75();

};
