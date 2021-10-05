#include "12_Integer_to_Roman.h"

void test_problem_12::test_case_12()
{
    CPPUNIT_ASSERT(s->intToRoman(3) == "III");
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_12);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
