/*
 * Problem 78: Medium
 * Key words: Dynamic programming
 * Link: https://leetcode.com/problems/subsets/
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

    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector< vector<int> > res = {{}};

        for(int i = 0; i < nums.size(); i++)
        {
            int size_of_res_i = res.size();

            for(int j = 0; j < size_of_res_i; j++)
            {
                vector<int> temp = res[j];
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }

        return res;
    }
    
};

class test_problem_78 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_78 );

        CPPUNIT_TEST( test_case_78 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_78();

};
