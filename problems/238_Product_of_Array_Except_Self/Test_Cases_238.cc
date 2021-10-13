#include "238_Product_of_Array_Except_Self.h"

void test_problem_238::test_case_238()
{
    vector<int> input = {1, 2, 3, 4};
    vector<int> output = {24, 12, 8, 6};
    CPPUNIT_ASSERT(s->productExceptSelf(input) == output);

    input = {-1, 1, 0, -3, 3};
    output = {0, 0, 9, 0, 0};
    CPPUNIT_ASSERT(s->productExceptSelf(input) == output);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_238);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
