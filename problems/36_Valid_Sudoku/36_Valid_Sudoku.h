/*
 * Problem 36 (Medium)
 * Key words: Unordered map; Array
 * Link: https://leetcode.com/problems/valid-sudoku/
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

public:

    bool isValidSudoku(vector<vector<char>>& board) 
    {

        vector< unordered_set<char> > rows(9, unordered_set<char>());
        vector< unordered_set<char> > columns(9, unordered_set<char>());
        vector< unordered_set<char> > boxes(9, unordered_set<char>());

        for(unsigned i = 0; i < board.size(); i++)
        for(unsigned j = 0; j < board[i].size(); j++)
        {
            if(board[i][j] == '.') continue;

            if( rows[i].find(board[i][j]) != rows[i].end()) return false;

            if( columns[j].find(board[i][j]) != columns[j].end() ) return false;

            if( boxes[(i/3)*3+j/3].find(board[i][j]) != boxes[(i/3)*3+j/3].end()) return false;

            rows[i].insert(board[i][j]);
            columns[j].insert(board[i][j]);
            boxes[(i/3)*3+j/3].insert(board[i][j]);

        }

        return true;
    }

    
};

class test_problem_36 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_36 );

        CPPUNIT_TEST( test_case_36 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_36();

};
