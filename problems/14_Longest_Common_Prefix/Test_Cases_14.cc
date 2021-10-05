#include "14_Longest_Common_Prefix.h"

void test_problem_14::test_case_14()
{
    vector<string> strs = {"flower","flow","flight"};
    string ret = "fl";
    
    CPPUNIT_ASSERT(s->longestCommonPrefix(strs) == ret);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_14);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
