#include "${index}_${problem}.h"

void test_problem_${index}::test_case_${index}()
{

}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_${index});

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
