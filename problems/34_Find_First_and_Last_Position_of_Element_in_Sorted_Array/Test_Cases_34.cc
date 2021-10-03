#include "34_Find_First_and_Last_Position_of_Element_in_Sorted_Array.h"

void test_problem_34::test_case_34()
{
    // A simple assert: CPPUNIT_ASSERT
    vector<int> nums = {5,7,7,8,8,10};
    vector<int> ret = {3, 4};
    CPPUNIT_ASSERT(s->searchRange(nums, 8) == ret);

    nums = {1, 2, 3};
    ret = {1, 1};
    CPPUNIT_ASSERT(s->searchRange(nums, 2) == ret);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_34);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
