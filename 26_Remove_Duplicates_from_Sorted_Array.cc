/*
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

#include <iostream>
#include <vector>

#include "Solutions.h"

using namespace std;

int Solution::removeDuplicates(vector<int>& nums) 
{

    if(nums.empty())
        return 0;

    int next = 1;
    for(unsigned i = 0; i < nums.size(); i++)
    {
        if (nums[i] > nums[next -1])
        {
            nums[next] = nums[i];
            next ++;
        }
    }
    
    return next;
}
