#include "347_Top_K_Frequent_Elements.h"

void test_problem_347::test_case_347()
{
    vector<int> input = {1, 1, 1, 2, 2, 3};
    vector<int> output = {1, 2};

    CPPUNIT_ASSERT(s->topKFrequent(input, 2) == output);

}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_347);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
