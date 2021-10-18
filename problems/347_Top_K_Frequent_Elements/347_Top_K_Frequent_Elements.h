/*
 * Problem 347: Medium
 * Description: Given an integer array nums and an integer k, return the k most frequent elements. 
 *              You may return the answer in any order.
 * Ideas: Unordered_map; priority_queue
 * Visualization: [Something easy to understand]
 * Link: https://leetcode.com/problems/top-k-frequent-elements/
 */
#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <map>
#include <queue>
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

    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> frequent;
        priority_queue< pair<int, int> > priority;
        
        vector<int> ret(k, 0);

        for(int i = 0; i < nums.size(); i++)
            frequent[nums[i]]++;

        for(auto it : frequent)
            priority.push({it.second, it.first});

        for(int i = 0; i < k; i++)
        {
            ret[i] = priority.top().second;
            priority.pop();
        }

        return ret;

    }
    
};

class test_problem_347 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_347 );

        CPPUNIT_TEST( test_case_347 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_347();

};
