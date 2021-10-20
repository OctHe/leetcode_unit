#include "65_Valid_Number.h"

void test_problem_65::test_case_65()
{
    CPPUNIT_ASSERT(s->isNumber("2") == true);
    CPPUNIT_ASSERT(s->isNumber("0089") == true);
    CPPUNIT_ASSERT(s->isNumber("-1") == true);
    CPPUNIT_ASSERT(s->isNumber("+1") == true);
    CPPUNIT_ASSERT(s->isNumber("99e2.5") == false);
    CPPUNIT_ASSERT(s->isNumber(".1") == true);
    CPPUNIT_ASSERT(s->isNumber(".-1") == false);
    CPPUNIT_ASSERT(s->isNumber("+.8") == true);
    CPPUNIT_ASSERT(s->isNumber("+.") == false);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_65);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
