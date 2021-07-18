#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestResult.h>

#include "MyUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(MySolutionTest);

int main( int argc, char **argv)
{

    // Running all test cases for all problems
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();
    
    // Add unique codes to run specified test cases for one problem

    return 0;
}


