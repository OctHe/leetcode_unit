/*
 * Problem 210: Medium
 * Description: There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
 *              You are given an array prerequisites where prerequisites[i] = [a_i, b_i] indicates that you 
 *              must take course b_i first if you want to take course a_i.
 *              Return the ordering of courses you should take to finish all courses. If there are many 
 *              valid answers, return any of them. If it is impossible to finish all courses, return an 
 *              empty array.
 * Ideas: Cycle detection; Degree; Adjacent matrix
 * Visualization: [Something easy to understand]
 * Link: https://leetcode.com/problems/course-schedule-ii/
 */
#include <iostream>
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

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> digraph(numCourses, vector<int>()); // From the first courses to the last
        vector<int> indegree(numCourses, 0);
        
        queue<int> q;
        vector<int> courses_scheduler;

        for(auto c : prerequisites)
        {
            // c[1] must be taken first
            digraph[c[1]].push_back(c[0]);
            indegree[c[0]]++;
        }

        // Save the courses that do not need prerequisites
        for(int i = 0; i < numCourses; i++)
            if(indegree[i] == 0) 
                q.push(i);


        int cnt = numCourses;
        while(q.size())
        {
            int c = q.front();
            q.pop();
            cnt--;

            courses_scheduler.push_back(c);
            for(auto post : digraph[c])
            {
                indegree[post]--;
                
                if(indegree[post] == 0)
                    q.push(post);
            }
        }

        return cnt == 0 ? courses_scheduler : vector<int>{};
    }
    
};

class test_problem_210 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_210 );

        CPPUNIT_TEST( test_case_210 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_210();

};
