/*
 * Problem 69: Easy
 * Key words: Binary search; int to long;
 * Link: https://leetcode.com/problems/sqrtx/
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

    int mySqrt_binary(int x)
    {
        if(x == 0 || x == 1) return x;

        long first = 1, last = x;
        long mid = (first + last) / 2;
        
        while(1)
        {
            if(mid * mid > x)
            {
                last = mid -1;
                mid = (first + last) / 2;
            }
            else if((mid +1) * (mid +1) <= x)
            {
                first = mid +1;
                mid = (first + last) / 2;
            }
            
            if(mid * mid <= x && (mid +1) * (mid +1) > x)
                return mid;
        }
    }

    int mySqrt_Newton(int x)
    {
        long r = x;
        /*
         * 1. Why do we use r*r > x?
         *      Proof: (r + x/r) / 2 >= sqrt(r * x/r) = sqrt(x)
         *  So, r will be the target when r*r <= x
         * 2. In each loop, r will decrease.
         *      Proof: r_{n+1} = (r_{n} + x/(r_{n})) / 2
         *                     = (r_{n}^2 + x) / (2 * r_{n})
         *                     < (r_{n}^2 + r_{n}^2) / (2 * r_{n})
         *                     = r_{n}
         */
        while (r*r > x)
            r = (r + x/r) / 2;
        return r;
    }

    int mySqrt(int x)
    {
        // return mySqrt_binary(x);
        return mySqrt_Newton(x);
    }
    
};

class test_problem_69 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_69 );

        CPPUNIT_TEST( test_case_69 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_69();

};
