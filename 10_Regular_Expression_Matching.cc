/*
 * Problem link: https://leetcode.com/problems/regular-expression-matching/
 * 
 * How to start: Dynamic programing. 
 *  1. An important process for dynamic programing is to define an array dp
 *      to save the results. In this problem, dp is a s.size()+1 by p.size()+1 
 *      matrix because we have 2 strings. This definition can simplify the 
 *      algorithm.
 *  2. If string p does not contain '*', the problem is simple.
 *      s[0: N] and p[0: M] are matched when s[0: N-1] and p[0: M-1] are matched.
 *  3. '*' cannot be the first char because it requires a preceding element.
 * 
 */
#include "Solutions.h"

using namespace std;

bool Solution::isMatch(string s, string p)
{
    // we use s.size()+1 and p.size()+1 to deal with the empty case of s and p.
    vector< vector<bool> > dp(s.size()+1, vector<bool>(p.size()+1, false));

   // Initialization 1: An empty pattern matches an empty string
    dp[0][0] = true;
    
    // Initialization 2: p is empty (The 1st row is always false because p is empty)
    // Initialization 2 can be omitted.
    // Initialization 3: s is empty (The 1st column)
    //  Complicate case of '*' (Other char can not be true):
    //      1. dp[0][j+1] may be true when p[j] == '*' 
    //          and '*' represents 0 times of the previous char
    //      2. '*' cannot be the first char of p
    for(unsigned j = 0; j < p.size(); j++)
        if(p[j] == '*' && (j != 0)) dp[0][j+1] = dp[0][j-1];

    // Dynamic programming for dp table
    for(unsigned i = 0; i < s.size(); i++)
    for(unsigned j = 0; j < p.size(); j++)
        if(p[j] == '*' && j != 0)   // '*' cannot be the first char of p
        {
            // when p[j] == '*', we must handle 3 cases as following,
            // any of case impacts dp[i+1][j+1], so we use || for the cases.
            // case 1: '*' represents 0 time of p[j-1] (dp[i+1][j+1] = dp[i+1][j-1]).
            // case 2: '*' represents 1 time of p[j-1] (dp[i+1][j+1] = dp[i+1][j]),
            //          so '*' can be ignored in this case.
            dp[i+1][j+1] = dp[i+1][j-1] || dp[i+1][j];
            
            // case 3: '*' represents multiple times of p[j-1].
            // In case 3, we need to deal with '.' and other chars.
             // ".*" can match any string, so we do not need to consider s[i-1] and [j-1]
            if(p[j-1] == '.')
                dp[i+1][j+1] = dp[i+1][j+1] || dp[i][j+1];
            else
                if(i != 0)  // if i == 0, case 3 can be ignored
                    dp[i+1][j+1] =  dp[i+1][j+1] || (dp[i][j+1] && (s[i] == s[i-1]) && (s[i] == p[j-1]));
        }
        else if(p[j] == '.')
            dp[i+1][j+1] = dp[i][j];
        else
            dp[i+1][j+1] = dp[i][j] && ((s[i] == p[j]) ? true : false);

    return dp[s.size()][p.size()];
}

