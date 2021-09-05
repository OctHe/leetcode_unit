/*
 * Problem link: https://leetcode.com/problems/zigzag-conversion/
 */
#include "Solutions.h"

using namespace std;

string Solution::convert(string s, int numRows)
{
    if(s.size() <= 1 || numRows == 1) return s;

    vector<string> rows(numRows, "");
    string ret = "";

    for(unsigned i = 0; i < s.size(); i++)
        if(i % (2 * numRows -2) < numRows)
            rows[i % (2 * numRows -2)] += s[i];
        else
            rows[(2 * numRows -2) - i % (2 * numRows -2)] += s[i];

    for(unsigned i = 0; i < rows.size(); i++)
        ret += rows[i];

    return ret;
}
