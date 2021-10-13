#include "189_Rotate_Array.h"

void test_problem_189::test_case_189()
{
    vector<int> input = {1,2,3,4,5,6,7};
    s->rotate(input, 3);
    vector<int> rotated_input = {5,6,7,1,2,3,4};
    CPPUNIT_ASSERT(input == rotated_input);

    input ={1, 2, 3, 4, 5, 6, 7, 8};
    s->rotate(input, 2);
    rotated_input = {7, 8, 1, 2, 3, 4, 5, 6};
    CPPUNIT_ASSERT(input == rotated_input);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_189);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
