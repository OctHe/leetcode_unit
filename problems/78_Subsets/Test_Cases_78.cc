#include "78_Subsets.h"

void test_problem_78::test_case_78()
{
    vector<int> nums = {1, 2, 3};
    vector< vector<int> > subsets = 
    {
        {},
        {1},
        {2},
        {1, 2},
        {3},
        {1, 3},
        {2, 3},
        {1, 2, 3}
    };

    CPPUNIT_ASSERT(s->subsets(nums) == subsets);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_78);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
