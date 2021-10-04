#include "1_Two_Sum.h"

void test_problem_1::test_case_1()
{
    vector<int> input = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> output = {0, 1};

    CPPUNIT_ASSERT(s->twoSum(input, target) == output);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_1);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
