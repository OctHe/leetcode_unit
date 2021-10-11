#include "152_Maximum_Product_Subarray.h"

void test_problem_152::test_case_152()
{

    vector<int> input = {2, 3, -2, 4};
    CPPUNIT_ASSERT(s->maxProduct(input) == 6);

    input = {-2, 0, -1};
    CPPUNIT_ASSERT(s->maxProduct(input) == 0);

    input = {-4, -3, -2};
    CPPUNIT_ASSERT(s->maxProduct(input) == 12);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_152);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
