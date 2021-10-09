#include "54_Spiral_Matrix.h"

void test_problem_54::test_case_54()
{
    vector< vector<int> > input = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> output = {1, 2, 3, 6, 9, 8, 7, 4, 5};

    CPPUNIT_ASSERT(s->spiralOrder(input) == output);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_54);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
