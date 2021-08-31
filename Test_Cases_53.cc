#include "MyTestCases.h"

void test_problem_53_maxSubArray::test_case_53_common_vector()
{
    vector<int> in_vec = {-2,1,-3,4,-1,2,1,-5,4};

    int res = 6;

    CPPUNIT_ASSERT( res == s->maxSubArray(in_vec) );

}

void test_problem_53_maxSubArray::test_case_53_one_element()
{
    vector<int> in_vec = {1};

    int res = 1;

    CPPUNIT_ASSERT( res == s->maxSubArray(in_vec) );

}

void test_problem_53_maxSubArray::test_case_53_all_elements()
{
    vector<int> in_vec = {5,4,-1,7,8};

    int res = 23;

    CPPUNIT_ASSERT( res == s->maxSubArray(in_vec) );

}