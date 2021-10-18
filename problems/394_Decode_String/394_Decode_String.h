/*
 * Problem 394: Medium
 * Description: Given an encoded string, return its decoded string.
 *              The encoding rule is: k[encoded_string], where the encoded_string inside the square 
 *              brackets is being repeated exactly k times. Note that k is guaranteed to be a positive 
 *              integer.
 *              You may assume that the input string is always valid; No extra white spaces, square 
 *              brackets are well-formed, etc.
 *              Furthermore, you may assume that the original data does not contain any digits and that 
 *              digits are only for those repeat numbers, k. For example, there won't be input like 3a 
 *              or 2[4].
 * Ideas: Stack
 * Visualization: [Something easy to understand]
 * Link: https://leetcode.com/problems/decode-string/
 */
#include <iostream>
#include <climits>
#include <vector>
#include <stack>
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

    string decodeString(string s)
    {
        int repeat = 0, begin = 0, end = 0;

        stack<int> decode;

        string ret;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')          // Trigger
                repeat = 10 * repeat + s[i] - '0';
            else if(s[i] == '[')                    // Push repeat and begin
            {
                decode.push(repeat);
                repeat = 0;

                decode.push(ret.size() -1);
            }
            else if(s[i] == ']')                    // Pop begin and repeat 
            {
                begin = decode.top() +1;
                decode.pop();

                repeat = decode.top() -1;
                decode.pop();

                // Output the repeated string
                end = ret.size();
                for(int m = 0; m < repeat; m++)
                for(int n = begin; n < end; n++)
                    ret.push_back(ret[n]);

                repeat = 0;
            }
            else
                ret.push_back(s[i]);
            
        }

        return ret;
    }
    
};

class test_problem_394 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_394 );

        CPPUNIT_TEST( test_case_394 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_394();

};
