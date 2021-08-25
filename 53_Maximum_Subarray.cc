/*
 * Link: https://leetcode.com/problems/maximum-subarray/
*/
#include "Solutions.h"

using namespace std;

int Solution::maxSubArray(vector<int>& nums)
{
    // max(dp), not dp[i], represents the max sum of array nums
    // dp[i] saves the max sum of the subarray that ends at index i
    vector<int> dp(nums.size());

    dp[0] = nums[0];
    for(unsigned i = 1; i < nums.size(); i++)
        dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);

    return *max_element(dp.begin(), dp.end());
    
}
