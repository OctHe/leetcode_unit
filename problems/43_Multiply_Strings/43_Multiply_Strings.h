/*
 * Problem 43: Medium
 * Key words: String; Carry;
 * Link: https://leetcode.com/problems/multiply-strings/
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

    string multiply(string num1, string num2) 
    {
        int m = num1.size(), n = num2.size();

        string product(m + n, '0');     // product[0] is reserved for carry

        for (int i = m - 1; i >= 0; i--) 
        for (int j = n - 1; j >= 0; j--) 
        {
            /*
             * 1. Use an integer to save the sum results
             * 2. The result of num1[i] and num2[j] is saved in prodjuct[i + j + 1]
             *      because product[0] is reserved for carry
             */
            int sum = (num1[i] - '0') * (num2[j] - '0') + (product[i + j + 1] - '0');
            product[i + j + 1] = sum % 10 + '0';    // Digits
            product[i + j] += sum / 10;     // Carry
        }

        // Ignore all zero chars at the begin
        for (int i = 0; i < m + n; i++) 
            if (product[i] != '0') 
                return product.substr(i);   // Get the substr from i to the end
            
        return "0";
    }
    
};

class test_problem_43 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_43 );

        CPPUNIT_TEST( test_case_43 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_43();

};
