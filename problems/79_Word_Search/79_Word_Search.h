/*
 * Problem 79: Medium
 * Key words: Backtrack
 * Link: https://leetcode.com/problems/word-search/
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

    bool compare_exist_backtrack(vector<vector<char>>& board, 
                            vector<vector<bool>>& used, 
                            int bd_x, int bd_y,
                            string &word, int wd_x)
    {
        if(wd_x == word.size()) return true;

        if(bd_x < 0 || bd_x >= board.size() ||
            bd_y < 0 || bd_y >= board[0].size())
            return false;

        if(used[bd_x][bd_y] || board[bd_x][bd_y] != word[wd_x]) 
            return false;
        
        used[bd_x][bd_y] = true;

        // Move up, down, left, right, and return
        if(
        compare_exist_backtrack(board, used, bd_x -1, bd_y, word, wd_x +1) ||
        compare_exist_backtrack(board, used, bd_x +1, bd_y, word, wd_x +1) ||
        compare_exist_backtrack(board, used, bd_x, bd_y -1, word, wd_x +1) ||
        compare_exist_backtrack(board, used, bd_x, bd_y +1, word, wd_x +1)
        ) 
            return true;
        else
        {
            used[bd_x][bd_y] = false;   // Release used[bd_x][bd_y]
            return false;
        }
        
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        if(board.size() == 0 && word.size() == 0) return true;
        if(board[0].size() == 0 && word.size() == 0) return true;

        vector< vector<bool> > used(board.size(), vector<bool>(board[0].size(), false));

        for(int i = 0; i < board.size(); i++)
        for(int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j] == word[0])
            {
                if(compare_exist_backtrack(board, used, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
    
};

class test_problem_79 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_79 );

        CPPUNIT_TEST( test_case_79 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_79();

};
