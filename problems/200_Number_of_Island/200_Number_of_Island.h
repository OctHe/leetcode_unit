/*
 * Problem 200: Medium
 * Key words: Backtrack
 * Link: https://leetcode.com/problems/number-of-islands/
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

    void find_land(vector<vector<char>>& grid, int x, int y)
    {
        if(grid[x][y] == '1')
            grid[x][y] == '2';
        else
            return;

        // Up
        if(x > 0) find_land(grid, x-1, y);
        // Down
        if(x < grid.size() -1) find_land(grid, x+1, y);
        // Left
        if(y > 0) find_land(grid, x, y-1);
        // Right
        if(y < grid[0].size() -1) find_land(grid, x, y+1);
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int num_island = 0;
        for(int i = 0; i < grid.size(); i++)
        for(int j = 0; j < grid[0].size(); j++)
        {
            if(grid[i][j] == '1')
            {
                num_island++;
                find_land(grid, i, j);
            }
        }

        return num_island;
    }
    
};

class test_problem_200 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_200 );

        CPPUNIT_TEST( test_case_200 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_200();

};
