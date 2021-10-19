/*
 * Problem 763: Medium
 * Description: You are given a string s. We want to partition the string into as many parts as possible 
 *              so that each letter appears in at most one part.
 *              Return a list of integers representing the size of these parts.
 * Ideas: 1. The straightforward idea is to combine different partitions when meet a duplicate char
 *        2. We observe that the output is the substring length, so we can record the length of the first
 *              partition, and turn into the next partition.
 * Algorithm: 1. unordered_set<pair<char, int>> saves the last index of a particular character
 *            2. For a new character, we extend the length into the maximum one.
 * Link: https://leetcode.com/problems/partition-labels/
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

    vector<int> partitionLabels(string s) 
    {
        unordered_map<char, int> last;

        for(int i = 0; i < s.size(); i++)
            last[s[i]] = i;

        vector<int> length;
        int begin = 0, end = last[s[0]];

        for(int i = 0; i < s.size(); i++)
        {

            if(i < end)
            {
                end = max(end, last[s[i]]);
            }
            else if(i == end)
            {
                length.push_back(end - begin +1);

                if(i +1 < s.size())
                {
                    begin = i +1;
                    end = last[s[i+1]];
                }
            }
        }

        return length;

    }
    
};

class test_problem_763 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_763 );

        CPPUNIT_TEST( test_case_763 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_763();

};
