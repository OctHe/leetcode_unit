/*
 * Problem 46: Medium
 * Key words: Backtracking
 * Link: https://leetcode.com/problems/permutations/
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
private: 
    vector< vector<int> > permutations;
    vector<int> one_permute;

public:
    void permute_backtrack(vector<int>& nums, vector<bool>& nums_index)
    {
        // Return condition
        if(one_permute.size() == nums.size())
        {
            permutations.push_back(one_permute);
            return;
        }

        // Backtracking
        for(unsigned i = 0; i < nums.size(); i++)
        {
            if(nums_index[i] == false)
            {
                
                one_permute.push_back(nums[i]);
                nums_index[i] = true;

                permute_backtrack(nums, nums_index);

                one_permute.pop_back();
                nums_index[i] = false;
            }
            
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<bool> nums_index(nums.size(), false);
        
        permute_backtrack(nums, nums_index);

        return permutations;
    }
    
};

class test_problem_46 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_46 );

        CPPUNIT_TEST( test_case_46 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_46();

};
