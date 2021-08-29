#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestResult.h>
#include <unistd.h>

#include "MyUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION( test_problem_4_findMedianSortedArrays );
CPPUNIT_TEST_SUITE_REGISTRATION( test_problem_10_isMatch );
CPPUNIT_TEST_SUITE_REGISTRATION( test_problem_26_removeDuplicates );
CPPUNIT_TEST_SUITE_REGISTRATION( test_problem_36_isValidSudoku );
CPPUNIT_TEST_SUITE_REGISTRATION( test_problem_37_solveSudoku );
CPPUNIT_TEST_SUITE_REGISTRATION( test_problem_53_maxSubArray );

void usage()
{
    cout << "Usage: leetcode_unit [-n problem]" << endl;
}

int main( int argc, char **argv)
{
    int opt, prob_ind;  // prob_ind: problem index
    CppUnit::TextUi::TestRunner runner;

    // Default: if no options, leetcode_unit run all unit tests.
    if (argc == 1)
    {
        // Running test cases for all problems
        
        CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
        runner.addTest( registry.makeTest() );
        runner.run();

        exit(EXIT_SUCCESS);
    }


    while ((opt = getopt(argc, argv, "n:h")) != EOF) 
    {
        switch (opt) 
        {
        case 'n':
            prob_ind = atoi(optarg);

            exit(EXIT_SUCCESS);

        case 'h':
            usage();

            exit(EXIT_SUCCESS);

        default: // opt == '?'
            usage();

            exit(EXIT_FAILURE);
        }
    }

}

