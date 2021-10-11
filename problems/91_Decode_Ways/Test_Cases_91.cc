#include "91_Decode_Ways.h"

void test_problem_91::test_case_91()
{
    // "1", "2"; "12"
    CPPUNIT_ASSERT(s->numDecodings("12") == 2);
    
    // "2", "2", "6"; "22", "6"; "2", "26"
    CPPUNIT_ASSERT(s->numDecodings("226") == 3);

    CPPUNIT_ASSERT(s->numDecodings("2102") == 1);
    CPPUNIT_ASSERT(s->numDecodings("1201234") == 3);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_91);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
