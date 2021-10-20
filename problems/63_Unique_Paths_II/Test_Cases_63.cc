#include "63_Unique_Paths_II.h"

void test_problem_63::test_case_63()
{
    vector< vector<int> > input = 
    {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    CPPUNIT_ASSERT(s->uniquePathsWithObstacles(input) == 2);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_63);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
