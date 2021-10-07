#include "45_Jump_Game_II.h"

void test_problem_45::test_case_45()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    CPPUNIT_ASSERT(s->jump(nums) == 2);

}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_45);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
