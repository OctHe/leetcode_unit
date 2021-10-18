#include "560_Subarray_Sum_Equals_K.h"

void test_problem_560::test_case_560()
{
    CPPUNIT_ASSERT(s->subarraySum({1, 1, 1}, 2) == 2);
    CPPUNIT_ASSERT(s->subarraySum({1, 2, 3}, 3) == 2);
    CPPUNIT_ASSERT(s->subarraySum({1}, 1) == 1);
    CPPUNIT_ASSERT(s->subarraySum({-1, -1, 1}, 0) == 1);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_560);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
