/*
 * Problem 647: Medium
 * Description: Given a string s, return the number of palindromic substrings in it.
 *              A string is a palindrome when it reads the same backward as forward.
 *              A substring is a contiguous sequence of characters within the string.
 * Ideas: 1. The basic idea is to find all substrings and check whether it is a palindromic string
 *              1) O(n^2) to find all substrings. So we have n^2 substrings, including "" and the string
 *              2) Reverse all substrings (O(n^2))
 *              3) reversed_substrings == substrings ? (O(n))
 *        2. Substrings have lots of repeat operations
 *              1) sub[i, j] is palindromic == { sub[i+1, j-1] is palindromic } && { s[i] == s[j] }
 *              2) Save the intermediate results of sub[i, j] into a $n \times n$ array
 *        3. sub[0, j] records the counts of palindromic substrings (O(n^2))
 *              1) sub[0, j] includes all palindromic substrings in sub[0, j-1]
 *              2) sub[0, j] includes a palindromic substrings with a single character of s[j]
 *              3) sub[0, j] must check substrings from sub[0, j] to sub[j-1, j]
 *              4) sub[i, j] is palindromic == { sub[i+1, j-1] is palindromic } && { s[i] == s[j] }
 * Algorithm: 1. count[0, n-1] records the results. 
 *            2. is_palindromic[i] records whether sub[i, j-1] (1 <= i <= j) is palindromic strings
 *            3. for loop [0, n-1]
 *              1) Update count[j] (0 <= j <= n-1)
 *              2) Update is_palindromic[1, j-1]
 * Link: https://leetcode.com/problems/palindromic-substrings/
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

    int countSubstrings(string s)
    {
        int n = s.size();
        vector<int> count(n, 0);
        vector<bool> is_palindromic(n+1, false);

        count[0] = 1;
        is_palindromic[1] = true;

        for(int i = 1; i < n; i++)
        {
            count[i] += count[i-1]; // substrings of s[0, i-1] is also substrings of s[0, i]

            // Update is_palindromic[0, i]
            is_palindromic[i+1] = true;     // "" is always true
            for(int j = 0; j <= i; j++)
            {
                is_palindromic[j] = is_palindromic[j+1] && s[j] == s[i];
                count[i] += is_palindromic[j];
            }
        }

        return count[n-1];
    }
    
};

class test_problem_647 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_647 );

        CPPUNIT_TEST( test_case_647 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_647();

};
