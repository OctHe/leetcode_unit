#include "102_Binary_Tree_Level_Order_Traversal.h"

void test_problem_102::test_case_102()
{
    // Test cases is not ready
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_102);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
