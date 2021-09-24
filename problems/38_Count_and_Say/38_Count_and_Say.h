/*
 * Problem 38: Easy/Medium/Hard
 * Key words:
 * Link: 
 */
#include <iostream>
#include <vector>
#include <unordered_set>
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

    string countAndSay(int n)
    {
        if(n == 1) return "1";

        string last_say = countAndSay(n -1), say;
        int count = 0;
        char c = last_say[0];

        for(unsigned i = 0; i < last_say.size(); i++)
        {

            if(c == last_say[i])
                count++;
            else
            {
                say.push_back(count + '0');
                say.push_back(c);

                count = 1;
                c = last_say[i];
            }
        }

        say.push_back(count + '0');
        say.push_back(c);

        return say;
    }

    
};

class test_problem_38 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_38 );

        CPPUNIT_TEST( test_case_38 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_38();

};
