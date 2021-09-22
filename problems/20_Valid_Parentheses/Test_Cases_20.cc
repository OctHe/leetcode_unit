#include "20_Valid_Parentheses.h"

void test_problem_20::test_case_20()
{
    CPPUNIT_ASSERT(s->isValid("()") == true);
    CPPUNIT_ASSERT(s->isValid("()[]{}") == true);
    CPPUNIT_ASSERT(s->isValid("(]") == false);
    CPPUNIT_ASSERT(s->isValid("([)]") == false);
    CPPUNIT_ASSERT(s->isValid("{[]}") == true);

}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_20);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
