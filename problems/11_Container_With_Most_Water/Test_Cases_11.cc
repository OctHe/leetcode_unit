#include "11_Container_With_Most_Water.h"

void test_problem_11::test_case_11()
{
    // A simple assert: CPPUNIT_ASSERT
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    CPPUNIT_ASSERT(s->maxArea(height) == 49);

    height = {1, 1};
    CPPUNIT_ASSERT(s->maxArea(height) == 1);

    height = {1,3,2,5,25,24,5};
    CPPUNIT_ASSERT(s->maxArea(height) == 24);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_11);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
