/*
 * Problem 65: Hard
 * Description: A valid number can be split up into these components in order:
 *                  1. A decimal number or an integer
 *                  2. An 'e' or 'E', followed by an integer;
 * Ideas: 1. We check 'e' or 'E' in the string,
 *          1) 'e'/'E' cannot be the first and last one
 *          2) if s does not contain 'e'/'E', we turn into before 'e'/'E' part
 *          3) If we have multiple 'e'/'E', return false
 *          4) If we have 1 'e'/'E', turn into before 'e'/'E' and after 'e'/'E'
 *        2. before 'e'/'E' part
 *          1) check for '.': if we have more than one '.', return false
 *          2) s[0] can be either '+'/'-'/'.'/digits
 *          3) If we have one '.', the rest part must all be digital
 *        3. after 'e'/'E' part (It must be a integer)
 *          1) s[0] can be either '+'/'-'/digits
 *          2) The rest must be digits
 *
 * Algorithm: [Flow graph of the solution]
 * Link: https://leetcode.com/problems/valid-number/
 */
#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
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

    bool all_digits(string s)
    {
        for(int i = 0; i < s.size(); i++)
            if(s[i] < '0' || s[i] > '9')
                return false;

        return true;
    }

    bool is_integer(string s)
    {
        // Check for '+'/'-'
        if(s[0] == '+' || s[0] == '-')
            s = s.substr(1);

        // null string must be false
        if(s.size() == 0)
            return false;

        return all_digits(s);
    }

    bool is_decimal(string s)
    {

        // Check for '+'/'-'
        if(s[0] == '+' || s[0] == '-')
            s = s.substr(1);

        int N = s.size();
        int dot = -1;

        // N == 1 cannot be a valid decimal, even it can be an integer
        if(N == 1) return false;

        // Check for '.'
        for(int i = 0; i < N; i++)
        {

            // multiple '.'s
            if(dot != -1 && s[i] == '.')
                return false;

            // '.' is detected
            if( dot == -1 && s[i] == '.' )
                dot = i;
        }

        if(dot == -1)
            return is_integer(s);

        string before_dot(s.begin(), s.begin() + dot);
        string after_dot(s.begin() + dot +1, s.end());

        if(dot == 0)
            return all_digits(after_dot);

        if(dot == N-1)
            return all_digits(before_dot);

        return all_digits(before_dot) && all_digits(after_dot);
    }

    bool isNumber(string s) 
    {
        int N = s.size();
        int e_or_E = -1;

        // Check for 'e'/'E'
        for(int i = 0; i < N; i++)
        {
            // 'e'/'E' cannot be the first or the last
            if( (i == 0 || i == N-1) && (s[i] == 'e' || s[i] == 'E') )
                return false;

            // multiple 'e'/'E's
            if( e_or_E > 0 && (s[i] == 'e' || s[i] == 'E') )
                return false;

            // 'e'/'E' is detected
            if( e_or_E == -1 && (s[i] == 'e' || s[i] == 'E') )
                e_or_E = i;

        }

        if(e_or_E == -1)
            return is_decimal(s) || is_integer(s);

        string before_e(s.begin(), s.begin() + e_or_E);
        string after_e(s.begin() + e_or_E +1, s.end());

        return (is_integer(before_e) || is_decimal(before_e)) && is_integer(after_e);
    }
    
};

class test_problem_65 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_65 );

        CPPUNIT_TEST( test_case_65 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_65();

};
