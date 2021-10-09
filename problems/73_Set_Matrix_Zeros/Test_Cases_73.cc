#include "73_Set_Matrix_Zeros.h"

void test_problem_73::test_case_73()
{
    vector< vector<int> > input =
    {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    vector< vector<int> > output =
    {
        {1, 0, 1},
        {0, 0, 0},
        {1, 0, 1}
    };
    
    s->setZeroes(input);
    
    CPPUNIT_ASSERT(input == output);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_73);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
