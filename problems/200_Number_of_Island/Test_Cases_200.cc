#include "200_Number_of_Island.h"

void test_problem_200::test_case_200()
{
    vector< vector<char> > input = 
    {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
    };
    
    CPPUNIT_ASSERT(s->numIslands(input) == 1);

    input = 
    {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'},
    };
    CPPUNIT_ASSERT(s->numIslands(input) == 3);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_200);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
