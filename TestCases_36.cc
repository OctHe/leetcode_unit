#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "MyUnitTests.h"

void MySolutionTest::test_case_36_true_case()
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

    CPPUNIT_ASSERT( s->isValidSudoku(input_board) == true );
}

void MySolutionTest::test_case_36_false_case()
{
    vector< vector<char> > input_board = 
    {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    
    CPPUNIT_ASSERT( s->isValidSudoku(input_board) == false );
}