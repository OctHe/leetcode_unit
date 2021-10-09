#include "66_Plus_One.h"

void test_problem_66::test_case_66()
{
    vector<int> input = {9, 9, 9};
    vector<int> output = {1, 0, 0, 0};
    CPPUNIT_ASSERT(s->plusOne(input) == output);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_66);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
