/*
 * Problem 128: Medium
 * Key words: Set; Binary search tree
 * Link: https://leetcode.com/problems/longest-consecutive-sequence/
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

    int longestConsecutive(vector<int>& nums)
    {
        
        set<int> nums_set;

        for(int i = 0; i < nums.size(); i++)
            nums_set.insert(nums[i]);

        int longest = 0, consecutive = 1;
        int pre = *nums_set.begin();

        for(auto num : nums_set)
        {
            if(pre +1 == num)
                consecutive ++;
            else
                consecutive = 1;

            longest = max(longest, consecutive);
            pre = num;
        }

        return longest;
    }

};

class test_problem_128 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_128 );

        CPPUNIT_TEST( test_case_128 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_128();

};
