#include "46_Permutations.h"

void test_problem_46::test_case_46()
{
    vector<int> input = {1, 2, 3};
    vector< vector<int> > output = 
    {
        {1, 2, 3}, 
        {1, 3, 2}, 
        {2, 1, 3}, 
        {2, 3, 1}, 
        {3, 1, 2},
        {3, 2, 1}
    };
    CPPUNIT_ASSERT(s->permute(input) == output);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_46);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
