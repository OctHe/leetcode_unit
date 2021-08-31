# leetcode_unit

This is a terminal tool for effeciently practice the problems in [Leetcode](https://leetcode.com/) with C/C++.
The goal of leetcode_unit is to integrate all solutions and all problems in Leetcode into one program (i.e., leetcode).

leetcode_unit is lightweight so that it does not need extra libraries except cppunit.
It also can works locally without network connection.
On the other hand, if you are interested in algorithm and unit test, new solutions and tests for any problem in Leetcode can be added by yourself with the help of the example.

## Support Platform

It has been tested on Ubuntu 20.04 and Windows subsystems for Linux (WSL) v2.

On Ubuntu 20.04 system, you need to install
1. make (>=4.2.1) and g++(8.3.0)
2. cppunit (>=1.14.0)

you can install them using *apt*
    
    sudo apt install make g++ libcppunit-dev

On WSL v2, you also must install Ubuntu 20.04 version.
Besides the above tools and libraries, it is better to install *vscode*.

Ideally, leetcode_unit can be easily compiled at other Linux platforms.

## Install and Test

    git clone https://github.com/OctHe/leetcode_unit
    cd leetcode_unit
    make
    ./leetcode_unit

 After running the program, the terminal will display the results of unit tests.

## Add New Problems and Solutions 

The following content uses the [Problem 37](https://leetcode.com/problemset/all/?topicSlugs=array&difficulty=HARD) as an example.

1. The header file that is related to a new solution is *Solution.h* file.
Please add the statement of the solution in the *Solution.h* file:
    
        void solveSudoku(vector<vector<char>>& board);

2. Add a new source code file. The name of the source file can be others if you like, but in this example, the new file is created as *37_Sudoku_Solver.cc* by using gvim:

        gvim 37_Sudoku_Solver.cc

3. Add the following content in the 37_Sudoku_Solver.cc file

        /*
         * Link: https://leetcode.com/problems/sudoku-solver/
         */

        #include <iostream>
        #include <vector>

        #include "Solutions.h"

        using namespace std;

        void Solution::solveSudoku(vector<vector<char>>& board)
        {
            // Add the solution below
        }

Until now, you can run make and a new *leetcode_unit* problem will be compiled (even if there is now solution has been added).

## Add Test Cases for the Solution

The header file related to unit test is *MyTestCases.h* file. The unit test framework is *cppunit*

1. First, open *MyTestCases.h* file and add a new test fixture

        class test_problem_37_solveSudoku : public CppUnit::TestFixture  
        {
        private:
                Solution *s;

        public:
                void setUp() { s = new Solution(); }
                void tearDown() { delete s; }

                // Test cases
                void test_case_37_single_array();

                // Test Suite
                static CppUnit::Test *suite()
                {
                CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "test_Problem_37" );
                suiteOfTests->addTest( new CppUnit::TestCaller<test_problem_37_solveSudoku>( 
                                                "test_single_array", 
                                                &test_problem_37_solveSudoku::test_case_37_single_array ) );
                return suiteOfTests;
                }
        };

2. Create a source file for the new test cases (with vim, gvim, vscode or other editors):

    vim Test_Cases_37.cc
    
Other file name is also valid.

3. Copy the following code into the new source file

        #include <cppunit/TestFixture.h>
        #include <cppunit/extensions/HelperMacros.h>

        #include "MyTestCases.h"

        void test_problem_37_solveSudoku::test_case_37_single_array()
        {
        vector< vector<char> > input_board = 
        {
                {'5','3','.','.','7','.','.','.','.'},
                {'6','.','.','1','9','5','.','.','.'},
                {'.','9','8','.','.','.','.','6','.'},
                {'8','.','.','.','6','.','.','.','3'},
                {'4','.','.','8','.','3','.','.','1'},
                {'7','.','.','.','2','.','.','.','6'},
                {'.','6','.','.','.','.','2','8','.'},
                {'.','.','.','4','1','9','.','.','5'},
                {'.','.','.','.','8','.','.','7','9'}
        };

        vector< vector<char> > output_board = 
        {
                {'5','3','4','6','7','8','9','1','2'},
                {'6','7','2','1','9','5','3','4','8'},
                {'1','9','8','3','4','2','5','6','7'},
                {'8','5','9','7','6','1','4','2','3'},
                {'4','2','6','8','5','3','7','9','1'},
                {'7','1','3','9','2','4','8','5','6'},
                {'9','6','1','5','3','7','2','8','4'},
                {'2','8','7','4','1','9','6','3','5'},
                {'3','4','5','2','8','6','1','7','9'}
        };

        s->solveSudoku(input_board);
        
        CPPUNIT_ASSERT( input_board == output_board );
        }

4. Finally, do not forget add the following code in *MyUnitTests.h* to register the new test fixture.

        CPPUNIT_TEST_SUITE_REGISTRATION( test_problem_37_solveSudoku );

Now, you can start to design your own solution for this new problem.
