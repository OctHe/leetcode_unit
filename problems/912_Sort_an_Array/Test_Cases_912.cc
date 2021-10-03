#include "912_Sort_an_Array.h"

void test_problem_912::test_case_912()
{
    vector<int> nums = {5, 2, 3, 1};
    vector<int> res = {1, 2, 3, 5};
    CPPUNIT_ASSERT(s->sortArray(nums) == res);

    nums = {5, 1, 1, 2, 0, 0};
    res = {0, 0, 1, 1, 2, 5};
    CPPUNIT_ASSERT(s->sortArray(nums) == res);

}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_912);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
