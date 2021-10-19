#include "647_Palindromic_Substrings.h"

void test_problem_647::test_case_647()
{
    CPPUNIT_ASSERT(s->countSubstrings("abc") == 3);
    CPPUNIT_ASSERT(s->countSubstrings("aaa") == 6);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_647);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
