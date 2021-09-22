#include "21_Generate_Parentheses.h"

void test_problem_21::test_case_21()
{
    // A simple assert: CPPUNIT_ASSERT
    vector<string> truth = {"((()))", "(()())", "(())()", "()(())", "()()()"};

    CPPUNIT_ASSERT(s->generateParenthesis(3) == truth);

    CPPUNIT_ASSERT(s->generateParenthesis(1) == vector<string>{"()"});
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_21);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
