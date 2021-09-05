#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestResult.h>
#include <unistd.h>

#include "MyTestCases.h"

typedef map<unsigned, CppUnit::Test *(*)(void)> test_suite_map;
static test_suite_map suites = 
{
    {4, test_problem_4_findMedianSortedArrays::suite},
    {6, test_problem_6_convert::suite},
    {10, test_problem_10_isMatch::suite},
    {26, test_problem_26_removeDuplicates::suite},
    {36, test_problem_36_isValidSudoku::suite},
    {37, test_problem_37_solveSudoku::suite},
    {53, test_problem_53_maxSubArray::suite},
    {494, test_problem_494_findTargetSumWays::suite},
};

void usage()
{
    cout << "Usage: leetcode_unit [-n problem]" << endl;
    cout << "       leetcode_unit -h" << endl;
}

int main( int argc, char **argv)
{
    int opt;
    CppUnit::TextUi::TestRunner runner;

    // Default: if no options, leetcode_unit run all unit tests.
    if (argc == 1)
    {
        // Running test cases for all problems
        for(test_suite_map::iterator ite = suites.begin(); ite != suites.end(); ite++)
            runner.addTest( suites[ite->first]() );

        cout << "Testing all problems..." << endl;
        runner.run();

        exit(EXIT_SUCCESS);
    }

    while ((opt = getopt(argc, argv, "n:h")) != EOF) 
    {
        switch (opt) 
        {
        case 'n':
            for(test_suite_map::iterator ite = suites.begin(); ite != suites.end(); ite++)
                if (ite->first == atoi(optarg))
                {
                    cout << "Add tests of Problem: " << ite->first << endl;
                    runner.addTest( suites[ite->first]() );
                }
            cout << "Testing..." << endl;
            runner.run();

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

