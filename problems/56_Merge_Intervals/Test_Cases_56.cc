#include "56_Merge_Intervals.h"

void test_problem_56::test_case_56()
{
    vector< vector<int> > input = 
    {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };
    vector< vector<int> > output = 
    {
        {1, 6},
        {8, 10},
        {15, 18}
    };

    CPPUNIT_ASSERT(s->merge(input) == output);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_56);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
