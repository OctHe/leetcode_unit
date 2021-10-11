#include "98_Validate_Binary_Search_Tree.h"

void test_problem_98::test_case_98()
{
    // Test cases for binary tree is not valid right now
    // A simple assert: CPPUNIT_ASSERT
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_98);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
