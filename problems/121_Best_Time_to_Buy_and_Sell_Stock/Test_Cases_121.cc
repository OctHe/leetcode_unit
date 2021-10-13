#include "121_Best_Time_to_Buy_and_Sell_Stock.h"

void test_problem_121::test_case_121()
{
    vector<int> input = {7,1,5,3,6,4};
    CPPUNIT_ASSERT(s->maxProfit(input) == 5);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_121);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
