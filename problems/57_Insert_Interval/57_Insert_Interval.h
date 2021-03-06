/*
 * Problem 57: Medium
 * Description: You are given an array of non-overlapping intervals intervals where intervals[i] = 
 *              [starti, endi] represent the start and the end of the ith interval and intervals is 
 *              sorted in ascending order by starti. You are also given an interval newInterval = 
 *              [start, end] that represents the start and end of another interval.
 *              Insert newInterval into intervals such that intervals is still sorted in ascending 
 *              order by starti and intervals still does not have any overlapping intervals (merge 
 *              overlapping intervals if necessary).
 *              Return intervals after the insertion.
 * Ideas: 1. Merge and sort
 *              1) Push all non-overlapped intervals into merged
 *              2) Merge all overlapped intervals into newInterval
 *              3) sort(merged.begin(), merged.end())
 * Algorithm: [a_0, b_0], [a_1, b_1], [a_2, b_2], [a_3, b_3]
 *                          [c,          d]
 * Link: https://leetcode.com/problems/insert-interval/
 */
#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
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

    vector<vector<int>> insert_by_merge_and_sort(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        vector< vector<int> > merged;

        for(int i = 0; i < intervals.size(); i++)
        {
            if(intervals[i][1] < newInterval[0] || intervals[i][0] > newInterval[1])
                merged.push_back(intervals[i]);
            else
            {
                if(intervals[i][0] <= newInterval[0]) 
                    newInterval[0] = min(newInterval[0], intervals[i][0]);
                if(intervals[i][1] >= newInterval[1])  
                    newInterval[1]  = max(newInterval[1], intervals[i][1]);
            }
        }

        merged.push_back(newInterval);

        sort(merged.begin(), merged.end());

        return merged;

    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        return insert_by_merge_and_sort(intervals, newInterval);
    }
    
};

class test_problem_57 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_57 );

        CPPUNIT_TEST( test_case_57_merge_one );
        CPPUNIT_TEST( test_case_57_merge_multiple );
        CPPUNIT_TEST( test_case_57_insert );
        CPPUNIT_TEST( test_case_57_invariant );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_57_merge_one();
        void test_case_57_merge_multiple();
        void test_case_57_insert();
        void test_case_57_invariant();

};
