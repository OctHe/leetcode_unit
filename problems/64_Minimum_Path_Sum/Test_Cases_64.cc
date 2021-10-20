#include "64_Minimum_Path_Sum.h"

void test_problem_64::test_case_64()
{
    vector< vector<int> > grid = 
    {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    CPPUNIT_ASSERT(s->minPathSum(grid) == 7);

    grid = 
    {
        {1, 2, 3},
        {4, 5, 6}
    };
    CPPUNIT_ASSERT(s->minPathSum(grid) == 12);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_64);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
