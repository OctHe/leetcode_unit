#include "279_Perfect_Square.h"

void test_problem_279::test_case_279()
{
    CPPUNIT_ASSERT(s->numSquares(2) == 2);
    CPPUNIT_ASSERT(s->numSquares(3) == 3);
    CPPUNIT_ASSERT(s->numSquares(4) == 1);
    CPPUNIT_ASSERT(s->numSquares(5) == 2);
    CPPUNIT_ASSERT(s->numSquares(6) == 3);
    CPPUNIT_ASSERT(s->numSquares(7) == 4);
    CPPUNIT_ASSERT(s->numSquares(8) == 2);
    CPPUNIT_ASSERT(s->numSquares(9) == 1);

}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_279);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
