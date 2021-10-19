#include "763_Partition_Labels.h"

void test_problem_763::test_case_763()
{
    vector<int> output = {9, 7, 8};
    CPPUNIT_ASSERT(s->partitionLabels("ababcbacadefegdehijhklij") == output);

    output = {10};
    CPPUNIT_ASSERT(s->partitionLabels("eccbbbbdec") == output);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_763);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
