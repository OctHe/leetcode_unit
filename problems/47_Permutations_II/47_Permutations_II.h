/*
 * Problem 47: Medium
 * Key words:
 * Link: https://leetcode.com/problems/permutations-ii/
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
    void permute_backtrack(vector<int>& nums, vector<bool>& used)
    {

        // Return condition
        if(one_permute.size() == nums.size())
        {
            permutations.push_back(one_permute);
            return;
        }

        // Backtracking loop
        for(unsigned i = 0; i < nums.size(); i++)
            if(used[i] == false)
            {
                // Deal with the duplicate
                if(i > 0 && nums[i] == nums[i -1] && used[i -1])
                    continue;

                // Backtracking
                one_permute.push_back(nums[i]);
                used[i] = true;

                permute_backtrack(nums, used);

                one_permute.pop_back();
                used[i] = false;

            }
            
    }

    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<bool> used(nums.size(), false);
        
        // nums must be sorted for this algorithm
        sort(nums.begin(), nums.end());

        permute_backtrack(nums, used);

        return permutations;
    }
    
};

class test_problem_47 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_47 );

        CPPUNIT_TEST( test_case_47 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_47();

};
