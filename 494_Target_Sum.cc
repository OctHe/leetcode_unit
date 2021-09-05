/*
 * Problem link: https://leetcode.com/problems/target-sum/
 * How to start:
 *      Binary tree: left == +; right == -
 * Note: Dynamic programming is also valid and may be better
 */
#include "Solutions.h"

using namespace std;

void target_sum_binary_tree(vector<int>& nums, int target, int index, int sum, int &ret)
{
    if(index == nums.size()) 
    {
        if(target == sum)
            ret ++;
        
        return;
    }

    target_sum_binary_tree(nums, target, index +1, sum + nums[index], ret);  
    target_sum_binary_tree(nums, target, index +1, sum - nums[index], ret);

}

int Solution::findTargetSumWays(vector<int>& nums, int target)
{
    int ret = 0, sum = 0;

    target_sum_binary_tree(nums, target, 0, sum, ret);
    
    cout << "return: " << ret << endl;
    return ret;
}
