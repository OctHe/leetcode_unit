#include "210_Course_Schedule_II.h"

void test_problem_210::test_case_210()
{
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> output = {0, 1, 2, 3};
    CPPUNIT_ASSERT(s->findOrder(4, prerequisites) == output);


    // prerequisites = {{1, 0}, {1, 2}, {0, 1}};
    // output = {};
    // CPPUNIT_ASSERT(s->findOrder(3, prerequisites) == output);

}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_210);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
