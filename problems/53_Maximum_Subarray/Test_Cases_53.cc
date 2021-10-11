#include "53_Maximum_Subarray.h"

void test_problem_53::test_case_53()
{
    vector<int> input = {-2,1,-3,4,-1,2,1,-5,4};
    CPPUNIT_ASSERT(s->maxSubArray(input) == 6);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_53);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
