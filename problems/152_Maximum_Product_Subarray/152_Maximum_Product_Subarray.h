/*
 * Problem 152: Medium
 * Key words: Dynamic programming; Two pointers
 * Link: https://leetcode.com/problems/maximum-product-subarray/
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

    // Time limit exceeded
    // Time complexity is O(n^2)
    int max_product_dp(vector<int>& nums) 
    {
        if(nums.size() == 0) return 0;

        vector<int> dp(nums.size(), INT_MIN);
        vector<int> product(nums.size(), 1);

        int max_product = INT_MIN;
        dp[0] = nums[0];
        product[0] = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            
            for(int j = i; j > 0; j--)
                product[j] = product[j-1] * nums[i];
            product[0] = nums[i];

            for(int j = 0; j <= i; j++)
                dp[j] = max(product[i-j], dp[j]);

        }

        for(int i = 0; i < nums.size(); i++)
            max_product = max(max_product, dp[i]);

        return max_product;
    }

    int max_prodcut_two_pointers(vector<int> &nums)
    {
        int imax = nums[0], imin = nums[0];
        int res = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {

            if(nums[i] < 0)
                swap(imax, imin);

            imax = max(imax * nums[i], nums[i]);
            imin = min(imin * nums[i], nums[i]);
            
            res = max(res, imax);
        }

        return res;
    }

    int maxProduct(vector<int>& nums) 
    {
        return max_prodcut_two_pointers(nums);
        // return max_product_dp(nums);
    }
    
};

class test_problem_152 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_152 );

        CPPUNIT_TEST( test_case_152 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_152();

};
