/*
 * Problem 102: Medium
 * Key words: Traversal binary tree
 * Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
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

    void level_order_recursive(TreeNode* root, int level, vector<vector<int>>& order)
    {
        if(root == nullptr) return;
        
        if(level > order.size()) order.push_back(vector<int>(1, root->val));
        else order[level-1].push_back(root->val);
        
        level_order_recursive(root->left, level +1, order);
        level_order_recursive(root->right, level +1, order);
        
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> order;
        level_order_recursive(root, 1, order);
        
        return order;
    }
    
};

class test_problem_102 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_102 );

        CPPUNIT_TEST( test_case_102 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_102();

};
