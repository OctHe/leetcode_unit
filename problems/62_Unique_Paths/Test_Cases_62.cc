#include "62_Unique_Paths.h"

void test_problem_62::test_case_62()
{
    CPPUNIT_ASSERT(s->uniquePaths(3, 7) == 28);
    CPPUNIT_ASSERT(s->uniquePaths(3, 1) == 1);
    CPPUNIT_ASSERT(s->uniquePaths(2, 2) == 2);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_62);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
