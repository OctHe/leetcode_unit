/*
 * Problem 739: Medium
 * Description: Given an array of integers temperatures represents the daily temperatures, 
 *              return an array answer such that answer[i] is the number of days you have 
 *              to wait after the ith day to get a warmer temperature. If there is no future 
 *              day for which this is possible, keep answer[i] == 0 instead. 
 * Ideas: 1. The basic idea is to record after[i] for each temperatures[i]. This method costs O(n^2)
 *          1) after[i] = temperatures[j] > temperatures[i]
 *          2) If we find temperatures[j] is the target of temperatures[i] (j > i), then
 *          temperatures[i+1, j-1] only need to search the target until j
 *        2. We maintain an array after[n] which is the return.
 *          1) For each after[i], we only need to operate after[j] = 0, 0 <= j <= i
 *          2) We maintain a priority_queue no_future, push the temperatures that is after[j] = 0 until i
 * Algorithm: 1. after[0, n-1], highest
 *            2. after[0] = 0, highest.push(temperatures[0])
 *            3. if temperatures[i] > no_future.top() after[no_future.top().index] = i - no_future.top().index; 
 *            4. no_future.pop(); repeat
 *            5. if temperatures[i] < no_future.top(); i++
 * Link: https://leetcode.com/problems/daily-temperatures/
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

    vector<int> dailyTemperatures(vector<int> temperatures)
    {
        int N = temperatures.size();
        priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > no_future;
        vector<int> after(N, 0);

        for(int i = 0; i < N; i++)
        {
            after[i] = 0;
            no_future.push({temperatures[i], i});

            while(temperatures[i] > no_future.top().first)
            {
                after[no_future.top().second] = i - no_future.top().second;
                no_future.pop();
            }
        }

        return after;
    }
    
};

class test_problem_739 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_739 );

        CPPUNIT_TEST( test_case_739 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_739();

};
