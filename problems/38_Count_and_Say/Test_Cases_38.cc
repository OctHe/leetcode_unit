#include "38_Count_and_Say.h"

void test_problem_38::test_case_38()
{
    CPPUNIT_ASSERT(s->countAndSay(1) == "1");
    CPPUNIT_ASSERT(s->countAndSay(2) == "11");
    CPPUNIT_ASSERT(s->countAndSay(3) == "21");
    CPPUNIT_ASSERT(s->countAndSay(4) == "1211");
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_38);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
