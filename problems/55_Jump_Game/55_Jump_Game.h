/*
 * Problem 55: Medium
 * Key words: Greedy
 * Link: https://leetcode.com/problems/jump-game/
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

    // Find the maximum distance can jump
    bool canJump(vector<int>& nums)
    {
        int next_reachable = nums[0], current_reachable = 0;
        int jump = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            next_reachable = max(next_reachable, i + nums[i]);

            if(i == current_reachable)
            {
                current_reachable = next_reachable;
                jump++;
            }

            if(i == next_reachable && i < nums.size() -1)
                return false;
        }

        return true;
    }
    
};

class test_problem_55 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_55 );

        CPPUNIT_TEST( test_case_55 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_55();

};
