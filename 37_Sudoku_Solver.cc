/*
 * Link: https://leetcode.com/problems/sudoku-solver/
 */

#include <iostream>
#include <vector>

#include "Solutions.h"

using namespace std;

void Solution::solveSudoku(vector<vector<char>>& board)
{
    sudoku_backtrack(board);
}

bool Solution::sudoku_backtrack(vector< vector<char> > &board)
{
    
    for(unsigned i = 0; i < board.size(); i++)
    for(unsigned j = 0; j < board[i].size(); j++)
        if(board[i][j] == '.')
        {
            for(char c = '1'; c <= '9'; c++)
                if(sudoku_isvalid(board, i, j, c))
                {
                    // Give a valid value to it and run next sudoku_helper
                    board[i][j] = c;
                    
                    if(sudoku_backtrack(board))
                        return true; // If next helper is true, than this must be true
                    
                    board[i][j] = '.';
                }
            
            return false;
        }

    // It returns true only when the helper completes all works
    return true;

}

bool Solution::sudoku_isvalid(vector< vector<char> > &board, int i, int j, char c)
{
        for (int idx = 0; idx < board.size(); idx++)
        {
            if (board[i][idx] == c) return false;
            if (board[idx][j] == c) return false;
            if (board[(i/3)*3 + (idx/3)][(j/3)*3 + (idx%3)] == c) return false;
        }
        
        return true;
}
