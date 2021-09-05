#include "MyTestCases.h"

void test_problem_494_findTargetSumWays::test_case_494()
{
    vector< vector<int> > nums = {
        {1,1,1,1,1},
        {1},
    };
    
    vector<int> targets = {3, 1}, res = {5, 1};

    CPPUNIT_ASSERT( s->findTargetSumWays(nums[0], targets[0]) == res[0] );
    CPPUNIT_ASSERT( s->findTargetSumWays(nums[1], targets[1]) == res[1] );
}
