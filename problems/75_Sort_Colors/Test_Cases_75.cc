#include "75_Sort_Colors.h"

void test_problem_75::test_case_75()
{
    vector<int> input = {2, 0, 2, 1, 1, 0};
    vector<int> output = {0, 0, 1, 1, 2, 2};
    s->sortColors(input);
    CPPUNIT_ASSERT(input == output);

}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_75);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
