/*
 * Problem 56: Medium
 * Description: Given an array of intervals where intervals[i] = [start_i, end_i], merge all overlapping 
 *              intervals, and return an array of the non-overlapping intervals that cover all the 
 *              intervals in the input.
 * Ideas: 
 * Algorithm: [Flow graph of the solution]
 * Link: https://leetcode.com/problems/merge-intervals/
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

    vector<vector<int>> sort_and_merge(vector<vector<int>>& intervals)
    {
        vector< vector<int> > merged_intervals;

        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){return a[0] < b[0];});

        merged_intervals.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++)
        {
            for(int j = 0; j < merged_intervals.size(); j++)
            {
                if(!(merged_intervals[j][1] < intervals[i][0]))
                {
                    merged_intervals[j][1] = max(merged_intervals[j][1], intervals[i][1]);
                    break;
                }

                if(j == merged_intervals.size() -1)
                    merged_intervals.push_back(intervals[i]);

            }
        }

        return merged_intervals;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        return sort_and_merge(intervals);
    }
    
};

class test_problem_56 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_56 );

        CPPUNIT_TEST( test_case_56 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_56();

};
