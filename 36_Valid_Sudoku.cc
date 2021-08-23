/*
 * Link: https://leetcode.com/problems/valid-sudoku/
 */
#include <unordered_set>

#include "Solutions.h"

using namespace std;
 
bool Solution::isValidSudoku(vector<vector<char>>& board) 
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