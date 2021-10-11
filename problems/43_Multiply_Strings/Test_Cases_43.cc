#include "43_Multiply_Strings.h"

void test_problem_43::test_case_43()
{
    CPPUNIT_ASSERT(s->multiply("123", "456") == "56088");
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_43);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
