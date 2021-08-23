# leetcode_unit

This is a simple example to write you own C++ solutions for Leetcode problems.
The propose of this example is for practice common algorithms with simple C++ source code -- Let's begin with Leetcode.

If you are interested in Leetcode and unit test, new solutions and tests for any problem in Leetcode can be added by yourself with the help of the example.

There are some other better tools or plugins that are designed for Leetcode, such as *leetcode.vim*, *leetcode_cli* and *leetcode for vs code*.
These tools also can help some to start to experience Leetcode.

# Pre-requisites

It has been tested on ubuntu 20.04 with make (>=4.2.1) and g++(8.3.0).
It also requires cppunit (>=1.14.0) to add the unit test.

On Ubuntu, you can install them with
    
    sudo apt install make g++ libcppunit-dev

# Download, Compile, and Run It

    git clone https://github.com/OctHe/leetcode_unit
    cd leetcode_unit
    make
    ./leetcode_test

 After running the program, you can find the results for unit tests.

# Write Solutions and Tests

The following content uses the [Problem 37](https://leetcode.com/problemset/all/?topicSlugs=array&difficulty=HARD) as an example.

## Add a Solution for a New Problem

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

## Add a Test Case for the Problem

The header file related to unit test is *MyUnitTests.h* file. The unit test framework is *cppunit*

1. First, open *MyUnitTest.h* file and add a new test case

        void test_case_37();


2. If you want to run the test case, add a *CPPUNIT_TEST* Macro between the Macros *CPPUNIT_TEST_SUITE* and *CPPUNIT_TEST_SUITE_END()*, i.e.,

        CPPUNIT_TEST( void test_case_37() );

3. Create a source file for the new test cases:

    gvim TestCases_37.cc
    
Other file name is also valid.

4. Copy the following code into the new source file

        #include <cppunit/TestFixture.h>
        #include <cppunit/extensions/HelperMacros.h>

        #include "MyUnitTests.h"

        void MySolutionTest::test_case_37()
        {

        }

Now, you can start to practice Leetcode.
