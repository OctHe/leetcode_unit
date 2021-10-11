#include "96_Unique_Binary_Search_Trees.h"

void test_problem_96::test_case_96()
{
    CPPUNIT_ASSERT(s->numTrees(3) == 5);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_96);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
