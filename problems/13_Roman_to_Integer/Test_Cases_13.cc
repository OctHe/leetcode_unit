#include "13_Roman_to_Integer.h"

void test_problem_13::test_case_13()
{
    CPPUNIT_ASSERT(s->romanToInt("III") == 3);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_13);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
