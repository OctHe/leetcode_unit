/*
 * Problem 98: Medium
 * Key words: Binary search tree from top to down
 * Link: https://leetcode.com/problems/validate-binary-search-tree/
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) 
    : val(x), left(left), right(right) {}
};

class Solution 
{

public:

    bool is_valid_bst_with_min_max(TreeNode* root, long min, long max)
    {
        bool left_is_valid = true, right_is_valid = true;
        
        if(root == nullptr) return true;
        
        // root->val must in the interval of [min, max]
        // because min or max is the value of its father 
        left_is_valid = is_valid_bst_with_min_max(root->left, min, root->val)
                && min < root->val ? true : false;      

        right_is_valid = is_valid_bst_with_min_max(root->right, root->val, max)
                && root->val < max ? true : false;     

        
        return left_is_valid && right_is_valid;
    }
    
    bool isValidBST(TreeNode* root) 
    {
        return is_valid_bst_with_min_max(root, LONG_MIN, LONG_MAX);
    }
    
};

class test_problem_98 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_98 );

        CPPUNIT_TEST( test_case_98 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_98();

};
