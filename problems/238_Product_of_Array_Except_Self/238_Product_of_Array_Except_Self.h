/*
 * Problem 238: Medium
 * Key words: Dynamic programming
 * Link: https://leetcode.com/problems/product-of-array-except-self/
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
    // Time complexity: O(n^2): Space complexity: O(n)
    vector<int> product_except_self_v1(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> ans(nums.size(), 1);
        int nums_i = nums[0];

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j) continue;
                ans[j] *= nums[i];
            }
        }

        return ans;
    }

    // Time complexity: O(n): Space complexity: O(n)
    vector<int> product_except_self_v2(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> first_part(n, 1), last_part(n, 1);

        for(int i = 1; i < n; i++)
        {
            first_part[i] = first_part[i-1] * nums[i-1];
            last_part[n-i-1] = last_part[n-i] * nums[n-i];
        }

        for(int i = 0; i < n; i++)
            first_part[i] *= last_part[i];
            
        return first_part;
    }

    /*
     * ans[0] = nums[1] * ... * nums[n-1]
     * ans[1] = nums[0] * nums[2] * ... * nums[n-1]
     * ans[2] = nums[0] * numas[1] * nums[3] * ... * nums[n-1]
     * ...
     * ans[n-1] = nums[0] * ... * nums[n-2]
     */
    /*
     *  x 1 2 3 4
     *  0 x 2 3 4
     *  0 1 x 3 4
     *  0 1 2 x 4
     *  0 1 2 3 x
     */
    // Time complexity: O(n): Space complexity: O(1) (with division)
    vector<int> product_except_self_v3(vector<int>& nums)
    {
        int n = nums.size();

        // if nums has at least 1 zero
        for(int i = 0; i < n; i++)
            if(nums[i] == 0)
            {
                nums[i] = 1;
                for(int j = 0; j < n; j++)
                    if(j != i) 
                    {
                        nums[i] *= nums[j];
                        nums[j] = 0;
                    }

                return nums;
            }

        // Now, nums does not have any zero, so we can use division
        int first = 1, last = 1, nums_i = 1;
        
        for(int i = 0; i < n; i++) 
            last *= nums[i];
        
        for(int i = 0; i < n; i++)
        {
            nums_i = nums[i];
            
            last /= nums_i;
            nums[i] = first * last;
            first *= nums_i;
        }
  
        return nums;
    }

    vector<int> productExceptSelf(vector<int>& nums)
    {
        // return product_except_self_v1(nums);
        // return product_except_self_v2(nums);
        return product_except_self_v3(nums);
    }
    
};

class test_problem_238 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_238 );

        CPPUNIT_TEST( test_case_238 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_238();

};
