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

    // Problem 6 (Medium)
    // Key words: String
    // Link: https://leetcode.com/problems/zigzag-conversion/
    string convert(string s, int numRows);

    // Problem 10 (Hard)
    // Key words: Dynamic programming
    // Link: https://leetcode.com/problems/regular-expression-matching/
    bool isMatch(string s, string p);

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

    // Problem 494 (Medium)
    // Key words: Binary tree
    // Link: https://leetcode.com/problems/target-sum/
    int findTargetSumWays(vector<int>& nums, int target);

    // ****************************************************************
    //                          Helper functions
    // ****************************************************************
    // Problem 4 (Hard)
    // kth element: Find the kth elements in two vectors. The first index starts from 0
    int kthElement(vector<int> &nums1, vector<int> &nums2, int k);

    // Problem 37 (Hard)
    // The traverse helper to solve sudoku
    bool sudoku_backtrack(vector< vector<char> > &board);
    // Check whether c is a valid value in a sudoku
    bool sudoku_isvalid(vector< vector<char> > &board, int i, int j, char c);
    

};
