#include "41_First_Missing_Positive.h"

void test_problem_41::test_case_41()
{
    vector<int> input = {1, 2, 0};
    CPPUNIT_ASSERT(s->firstMissingPositive(input) == 3);

    input = {1, 2, 3};
    CPPUNIT_ASSERT(s->firstMissingPositive(input) == 4);

    input = {1, 1};
    CPPUNIT_ASSERT(s->firstMissingPositive(input) == 2);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_41);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
