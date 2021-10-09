#include "69_Sqrt_X.h"

void test_problem_69::test_case_69()
{
    CPPUNIT_ASSERT(s->mySqrt(4) == 2);
    CPPUNIT_ASSERT(s->mySqrt(100) == 10);
    CPPUNIT_ASSERT(s->mySqrt(99) == 9);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_69);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
