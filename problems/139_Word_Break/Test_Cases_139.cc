#include "139_Word_Break.h"

void test_problem_139::test_case_139()
{
    vector<string> dict = {"leet", "code"};
    CPPUNIT_ASSERT(s->wordBreak("leetcode", dict) == true);

    dict = {"cats", "dog", "sand", "and", "cat"};
    CPPUNIT_ASSERT(s->wordBreak("catsandog", dict) == false);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_139);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
