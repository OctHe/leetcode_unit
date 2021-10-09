/*
 * Problem 62: Medium
 * Key words: Binary tree; Dynamic programming
 * Link: https://leetcode.com/problems/unique-paths/
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
private:
    int paths;

public:

    // Time limit exceeded
    void unique_paths_binary_tree(int m, int n, int x, int y)
    {
        if(x == m-1 || y == n-1)
            paths++;
        else if(x < m-1 && y < n-1)
        {
            unique_paths_binary_tree(m, n, x +1, y);
            unique_paths_binary_tree(m, n, x, y +1);
        }

    }

    // In this version, we use dp[m][n] with O(mn) complexity
    int unique_paths_dp_v1(int m, int n)
    {
        vector< vector<int> > dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++)
            dp[i][0] = 1;
        for(int j = 1; j < n; j++)
            dp[0][j] = 1;

        for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++)
            for(int k = 0; k <= j; k++)
                dp[i][j] += dp[i-1][k];
        
        return dp[m-1][n-1];
    }

    // In this version, we use dp[m][n] with O(m) complexity, where m < n
    int unique_paths_dp_v2(int m, int n)
    {
        if(m > n) swap(m, n);

        vector<int> dp(m, 0);

        for(int i = 0; i < m; i++) dp[i] = 1;

        for(int i = 1; i < n; i++)
        {
            for(int j = m-1; j > 0; j--)
                for(int k = 0; k < j; k++)
                    dp[j] += dp[k];
            
        }
        
        return dp[m-1];
    }

    int uniquePaths(int m, int n)
    {
        /* Binary tree */
        // paths = 0;
        //
        // unique_paths_binary_tree(m, n, 0, 0);
        //
        //return paths;

        /* Dynamic programming */
        // return unique_paths_dp_v1(m, n);
        return unique_paths_dp_v2(m, n);
        
    }
    
};

class test_problem_62 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_62 );

        CPPUNIT_TEST( test_case_62 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_62();

};
