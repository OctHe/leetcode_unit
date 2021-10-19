#include "739_Daily_Temperatures.h"

void test_problem_739::test_case_739()
{
    vector<int> output = {1, 1, 4, 2, 1, 1, 0, 0};
    CPPUNIT_ASSERT(s->dailyTemperatures({73, 74, 75, 71, 69, 72, 76, 73}) == output);

    output = {1, 1, 1, 0};
    CPPUNIT_ASSERT(s->dailyTemperatures({30, 40, 50, 60}) == output);


    output = {1, 1, 0};
    CPPUNIT_ASSERT(s->dailyTemperatures({30, 60, 90}) == output);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_739);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
