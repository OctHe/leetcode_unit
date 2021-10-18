#include "416_Partition_Equal_Subset_Sum.h"

void test_problem_416::test_case_416()
{
    // vector<int> input = {};
    CPPUNIT_ASSERT(s->canPartition(vector<int>{1, 5, 11, 5}) == true);
    CPPUNIT_ASSERT(s->canPartition(vector<int>{1, 2, 3, 5}) == false);
    
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_416);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
