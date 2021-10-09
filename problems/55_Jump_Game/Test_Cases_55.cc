#include "55_Jump_Game.h"

void test_problem_55::test_case_55()
{
    vector<int> input = {2, 3, 1, 1, 4};
    CPPUNIT_ASSERT(s->canJump(input) == true);

    input = {3, 2, 1, 0, 4};
    CPPUNIT_ASSERT(s->canJump(input) == false);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_55);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
