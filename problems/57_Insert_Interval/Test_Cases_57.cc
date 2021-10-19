#include "57_Insert_Interval.h"

void test_problem_57::test_case_57_merge_one()
{
    vector< vector<int> > input = 
    {
        {1, 3},
        {6, 9},
    };
    vector<int> insert = {2, 5};
    vector< vector<int> > output = 
    {
        {1, 5},
        {6, 9},
    };
    CPPUNIT_ASSERT(s->insert(input, insert) == output);
}

void test_problem_57::test_case_57_merge_multiple()
{
    vector< vector<int> > input = 
    {
        {1, 2},
        {3, 5},
        {6, 7},
        {8, 10},
        {12, 16},
    };
    vector<int> insert = {4, 8};
    vector< vector<int> > output = 
    {
        {1, 2},
        {3, 10},
        {12, 16},
    };
    CPPUNIT_ASSERT(s->insert(input, insert) == output);

}

void test_problem_57::test_case_57_insert()
{
    vector< vector<int> > input;
    vector<int> insert = {4, 8};
    vector< vector<int> > output = 
    {
        {4, 8},
    };
    CPPUNIT_ASSERT(s->insert(input, insert) == output);

}

void test_problem_57::test_case_57_invariant()
{
    vector< vector<int> > input = 
    {
        {1, 5},
    };
    vector<int> insert = {2, 3};
    CPPUNIT_ASSERT(s->insert(input, insert) == input);

}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_57);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
