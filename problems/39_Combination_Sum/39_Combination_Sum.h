/*
 * Problem 39: Medium
 * Key words: backtrack
 * Link: https://leetcode.com/problems/combination-sum/
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestResult.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>

using namespace std;

class Solution 
{

private:
    vector<int> res;
    vector< vector<int> > ret;

public:

    void backtrack_sum(vector<int>& candidates, 
                        int target, 
                        int candidates_start)
    {
        int sum = 0;
        for(unsigned i = 0; i < res.size(); i++)
            sum += res[i];

        if(sum == target)
        {
            ret.push_back(res);
            return;
        }
        else if(sum > target)
            return;

        for(unsigned i = candidates_start; i < candidates.size(); i++)
        {
            res.push_back(candidates[i]);
            backtrack_sum(candidates, target, i);
            res.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {

        backtrack_sum(candidates, target, 0);

        return ret;
    }

};

class test_problem_39 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_39 );

        CPPUNIT_TEST( test_case_39 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_39();

};
