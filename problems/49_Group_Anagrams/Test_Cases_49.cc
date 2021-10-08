#include "49_Group_Anagrams.h"

void test_problem_49::test_case_49()
{
    vector<string> input = {"eat","tea","tan","ate","nat","bat"};
    vector< vector<string> > output = {
        {"eat", "tea", "ate"},
        {"tan", "nat"},
        {"bat"}
    };
    
    CPPUNIT_ASSERT(s->groupAnagrams(input) == output);

}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_49);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
