/*
 * Problem 416: Medium
 * Description: Given a non-empty array nums containing only positive integers, find if the array can 
 *              be partitioned into two subsets such that the sum of elements in both subsets is equal.
 * Ideas: Binary tree; Depth-first search (DFS); Dynamic programming
 * Visualization: [Something easy to understand]
 * Link: https://leetcode.com/problems/partition-equal-subset-sum/
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
    bool partition(vector<int> &nums, int left, int right)
    {

        if(nums.empty())
        {
            if(left == right)
                return true;
            else 
                return false;
        }

        int val = nums.back();
        nums.pop_back();

        if(partition(nums, left + val, right))
            return true;
        
        if(partition(nums, left, right + val))
            return true;

        nums.push_back(val);

        return false;

    }

    bool partition_and_sum(vector<int> &nums)
    {
        
        // Calculate sum of nums
        int sum = 0;
        for(unsigned i = 0; i < nums.size(); i++)
            sum += nums[i];

        // If sum is odd, return false
        if(sum % 2) return false;

        /*
         * Dynamic programming to find a subset that 
         * the sum of the subset is equal to sum/2.
         * This is because if the sum of this subset is
         * sum/2, then the sum of the rest is also sum/2.
         */
        vector< vector<bool> > dp(sum/2+1, vector<bool>(nums.size()+1, false));
        for(int i = 0; i <= sum/2; i++)
        for(int j = 0; j <= nums.size(); j++)
        {
            if(i == 0)              // sum == 0
                dp[i][j] = true;
            else if(j == 0)         // Zero numbers
                dp[i][j] = false;
            else if(i >= nums[j-1])   // i can be added by j nums when it can be added by j-1 nums
                                    // or it can be added by j-1 nums pluses nums[i]
                dp[i][j] = dp[i][j-1] || dp[i-nums[j-1]][j-1];
            else                    // If i < nums[i], i only can be added by j-1 nums
                dp[i][j] = dp[i][j-1];

        }

        return dp[sum/2][nums.size()];
    }

    bool canPartition(vector<int> nums)
    {
        // return partition(nums, 0, 0);
        return partition_and_sum(nums);
    }
    
};

class test_problem_416 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_416 );

        CPPUNIT_TEST( test_case_416 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_416();

};
