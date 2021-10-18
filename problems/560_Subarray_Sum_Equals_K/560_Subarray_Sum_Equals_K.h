/*
 * Problem 560: Medium
 * Description: Given an array of integers nums and an integer k, return the total number of continuous 
 *              subarrays whose sum equals to k.
 * Ideas: Two pointers; Hashmap
 * Visualization: sum[m, n] = sum[0, n] - sum[0, m] 
 *                  We can check sum[0, m] whether is in the hashmap
 * Link: https://leetcode.com/problems/subarray-sum-equals-k/
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

    /* Only works for unsigned int
    * Visualization: [a_1, a_2, ...,a_k, ..., a_n]
    *                  ^             ^
    *                 slow          fast
    *                if sum[slow, fast] < k, fast++; else if sum[slow, fast] > k, slow++
    *                if(sum[slow, fast]) == k, total++
    */
    int subarray_sum_2ps(vector<int> nums. int k)
    {
        int slow = 0, fast = 1;
        int total = 0, sum = nums[slow];
        while(fast < nums.size() || slow < nums.size())
        {
            if(sum < k)
            {
                if(fast < nums.size()) 
                {
                    sum += nums[fast];
                    fast++;
                }
                else
                    slow++;
            }
            else if(sum >= k)
            {
                if(sum == k)
                    total ++;

                sum -= nums[slow];
                if(slow < nums.size()) slow++;
            }
        }

        return total;

    }

    int subarray_sum_hashmap(vector<int> nums, int k)
    {
        // freq[sum] saves the frequency of the sum from 0 to i
        unordered_map<int, int> freq = {{0, 1}};
        int total = 0;  // sum from 0 to i
        int ret = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            total += nums[i];
            ret += freq[total - k];
            freq[total]++;
            
        }

        return ret;
    }

    int subarraySum(vector<int> nums, int k)
    {
        return subarray_sum_hashmap(nums, k);
    }
    
};

class test_problem_560 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_560 );

        CPPUNIT_TEST( test_case_560 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_560();

};
