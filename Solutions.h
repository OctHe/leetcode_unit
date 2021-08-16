#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // Problem 4 (Hard)
    // Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

    // Problem 26 (Easy)
    // Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
    int removeDuplicates(vector<int>& nums);

    // Problem 37 (Hard)
    // Link: https://leetcode.com/problems/sudoku-solver/
    void solveSudoku(vector<vector<char>>& board);

    // Helper functions
    // kth element: Find the kth elements in two vectors. The first index starts from 0
    int kthElement(vector<int> &nums1, vector<int> &nums2, int k);

    // The traverse helper to solve sudoku
    bool sudoku_backtrack(vector< vector<char> > &board);
    // Check whether c is a valid value
    bool sudoku_isvalid(vector< vector<char> > &board, int i, int j, char c);
};
