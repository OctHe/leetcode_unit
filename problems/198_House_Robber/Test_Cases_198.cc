#include "198_House_Robber.h"

void test_problem_198::test_case_198()
{
    vector<int> input = {1, 2, 3, 1};
    CPPUNIT_ASSERT(s->rob(input) == 4);

    input = {2,7,9,3,1};
    CPPUNIT_ASSERT(s->rob(input) == 12);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_198);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
