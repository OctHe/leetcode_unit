#include "221_Maximal_Square.h"

void test_problem_221::test_case_221()
{
    vector<vector<char>> input = 
    {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    CPPUNIT_ASSERT(s->maximalSquare(input) == 4);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_221);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
