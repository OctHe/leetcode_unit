#include "6_ZigZag_Conversion.h"

void test_problem_6::test_case_6_convert()
{
    CPPUNIT_ASSERT( s->convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    CPPUNIT_ASSERT( s->convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
    CPPUNIT_ASSERT( s->convert("A", 1) == "A");
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_6);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();


    return 0;
}
