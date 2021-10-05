/*
 * Problem 41: Easy/Medium/Hard
 * Key words:
 * Link: 
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <map>

#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestResult.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>

using namespace std;

class Solution 
{

public:

    int firstMissingPositive(vector<int>& nums) 
    {
        for(unsigned i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] -1])
            {
                swap(nums[i], nums[nums[i] -1]);
                i--;
            }
        }

        for(unsigned i = 0; i < nums.size(); i++)
            if(nums[i] != i +1)
                return i +1;
        
        // if all nums[i] == i +1, return nums.size() +1
        return nums.size() +1;
    }
    
};

class test_problem_41 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_41 );

        CPPUNIT_TEST( test_case_41 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_41();

};
