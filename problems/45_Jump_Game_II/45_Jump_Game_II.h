/*
 * Problem 45: Medium
 * Key words: Dynamic programming; Backtracking; Two pointers
 * Link: https://leetcode.com/problems/jump-game-ii/
 */
#include <iostream>
#include <climits>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <map>

#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestResult.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>

using namespace std;

class Solution 
{

public:
    /* Example:
     *      input = {2, 3, 1, 1, 4}
     *      jump1 = 2->3->4 (2 jumps)
     *      jump2 = 2->3->1->1->4 (4 jumps)
     *      jump3 = 2->1->1->4  (3 jumps)
    */
   // Error: Time limit exceeded
   void jump_backtrack(vector<int>& nums, int index, int jump, int& ret)
   {
        if(index >= nums.size()) return;
        
        if(index == nums.size() -1)
        {   ret = (jump <= ret) ? jump : ret; return;   }

        for(unsigned i = 1; i <= nums[index]; i++)
        {   jump++; jump_backtrack(nums, index + i, jump, ret); jump--; }

   }

    /* 
     * 1. We need define a vector(i.e., vector<int> dp(nums.size(), INT_MAX)).
     *      dp[i] means the minimal jump from dp[0: i-1] to dp[i].
     * 2. We need an ``if'' to determine which element
     *      in dp[0: i-1] can reach to dp[i].
     * 3. // Time complexity: O(n^2)
     */
    int jump_dynamic_programming(vector<int>& nums)
    {
        vector<int> dp(nums.size(), INT_MAX);
        
        // Initialization
        dp[0] = 0;

        // Recursion
        // Update dp from 1 to end
        for(unsigned i = 1; i < nums.size(); i++)
        // Find the minimum dp[i] according to dp[0: i-1]
        for(unsigned j = 0; j < i; j++)
        {
            if(j + nums[j] >= i)
                dp[i] = min(dp[i], dp[j] + 1);
        }

        return dp[nums.size() -1];
    }

    /*
     * 1. Greedy is a special case of dynamic programming.
     * 2. We find the max reachable index with num_jump, and
     *      then find the max reachable index with num_jump +1.
     * 3. Time complexity: O(n)
     */
    int jump_greedy(vector<int>& nums)
    {
        // Corner case
        if(nums.size() <= 1) return 0;
        
        // num_jump: if nums.size() > 1, we need 1 jump at least.
        // current_reachable: The maximal reachable index we can get from i with num_jump
		// next_reachable: The maximal reachable index we can get from i with num_jump + 1
        int num_jump = 1; 
        int current_reachable = nums[0], next_reachable = nums[0];

    	//till we reach last index, NOTE: Not necessary to cross last index
        for(int i = 0; i < nums.size() -1; i++)
        {
            // Update max reachable nums from [0: i] nums with num_jump
            // when i + nums[i] can reach more numbers
            next_reachable = max(next_reachable, i + nums[i]);
            
             //we have to take jump because we reach the maximum index with num_jump
            if(i == current_reachable)
            {
                num_jump++;
                current_reachable = next_reachable;
            }
        }

        return num_jump;
    }

    int jump(vector<int>& nums)
    {
        int ret = nums.size();
        
        // jump_backtrack(nums, 0, 0, ret);
        // ret = jump_dynamic_programming(nums);
        ret = jump_greedy(nums);

        return ret;

    }
    
};

class test_problem_45 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_45 );

        CPPUNIT_TEST( test_case_45 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_45();

};
