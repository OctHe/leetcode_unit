/*
 * Problem ${index}: [Easy/Medium/Hard]
 * Description: [Description of the problem]
 * Ideas: [Some words about the solution]
 * Algorithm: [Flow graph of the solution]
 * Link: [Link from Leetcode]
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

    <return_type> <function>
    {

    }
    
};

class test_problem_${index} : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_${index} );

        CPPUNIT_TEST( test_case_${index} );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_${index}();

};
