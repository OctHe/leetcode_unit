#include "39_Combination_Sum.h"

void test_problem_39::test_case_39()
{
    // A simple assert: CPPUNIT_ASSERT
    vector<int> candicates = {2, 3, 6, 7};
    int target = 7;
    vector< vector<int> > ret = {{2, 2, 3}, {7}};
    CPPUNIT_ASSERT(s->combinationSum(candicates, target) == ret);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_39);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
