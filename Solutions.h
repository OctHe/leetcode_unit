#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{

public:

    // Problem 4 (Hard)
    // Key words: Sorting array
    // Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

    // Problem 26 (Easy)
    // Key words: Array
    // Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
    int removeDuplicates(vector<int>& nums);

    // Problem 36 (Medium)
    // Key words: Unordered map; Array
    // Link: https://leetcode.com/problems/valid-sudoku/
    bool isValidSudoku(vector<vector<char>>& board);

    // Problem 37 (Hard)
    // Key words: Backtrack
    // Link: https://leetcode.com/problems/sudoku-solver/
    void solveSudoku(vector<vector<char>>& board);

    // Problem 53 (Easy)
    // Key words: Dynamic programing
    // Link: https://leetcode.com/problems/maximum-subarray/
    int maxSubArray(vector<int>& nums);

    // ****************************************************************
    //                          Helper functions
    // ****************************************************************
    // kth element: Find the kth elements in two vectors. The first index starts from 0
    int kthElement(vector<int> &nums1, vector<int> &nums2, int k);

    // The traverse helper to solve sudoku
    bool sudoku_backtrack(vector< vector<char> > &board);
    // Check whether c is a valid value in a sudoku
    bool sudoku_isvalid(vector< vector<char> > &board, int i, int j, char c);
    
};
