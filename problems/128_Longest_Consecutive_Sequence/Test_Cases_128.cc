#include "128_Longest_Consecutive_Sequence.h"

void test_problem_128::test_case_128()
{
    vector<int> input = {100, 4, 200, 1, 3, 2};
    CPPUNIT_ASSERT(s->longestConsecutive(input) == 4);

    input = {0,3,7,2,5,8,4,6,0,1};
    CPPUNIT_ASSERT(s->longestConsecutive(input) == 9);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_128);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
