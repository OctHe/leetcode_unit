#include "47_Permutations_II.h"

void test_problem_47::test_case_47()
{
    vector<int> input = {1, 1, 3};
    vector< vector<int> > output = 
    {
        {1, 1, 3}, 
        {1, 3, 1}, 
        {3, 1, 1}
    };
    //113 131 113 131 311 311
    CPPUNIT_ASSERT(s->permuteUnique(input) == output);

}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_47);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
