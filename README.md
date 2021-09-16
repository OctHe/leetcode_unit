# leetcode_unit

This is a terminal tool for effeciently practice the problems in [Leetcode](https://leetcode.com/) with C/C++.
The goal of leetcode_unit is to integrate all solutions and all problems in Leetcode into one program (i.e., leetcode_unit).

leetcode_unit is lightweight so that it does not require extra libraries except cppunit.
It also can works locally without network connection.
On the other hand, if you are interested in algorithm and unit test, new solutions and tests for any problem in Leetcode can be added by yourself with the help of the example.

## Support Platform

It has been tested on Ubuntu 20.04 and Windows Subsystem for Linux (WSL) v2.

On Ubuntu 20.04 system, you need to install
1. make (>=4.2.1) and g++(>=8.3.0)
2. cppunit (>=1.14.0)

you can install them using *apt*
    
    sudo apt install make g++ libcppunit-dev

On WSL v2, you also must install Ubuntu 20.04 version.
Besides the above tools and libraries, it is better to install *vscode*.

Ideally, leetcode_unit can be easily compiled at other Linux platforms.

## Download leetcode_unit

    git clone https://github.com/OctHe/leetcode_unit
    cd leetcode_unit


## Add New Problem

The following content uses the [Problem 36](https://leetcode.com/problems/valid-sudoku/) as an example.

The program is a python program named as *leetcode_unit.py*.
To add a new problem, you can directly run the following command

    ./leetcode_unit add -i 36 -n Valid_Sudoku
where *-i* is the index of the problem and *-n* is its name.

After running the command, a new directory will be created in the *./problems/* directory like this:

.   
├── problems    
│   ├── 36_Valid_Sudoku     
│   │   ├── 36_Valid_Sudoku.h   
│   │   └── Test_Cases_36.cc    

Until now, you can add your own solution to this new problem.

## Add Solution

*36_Valid_Sudoku.h* contains the Solution class. Open it with a editor, you need to replace the following:


    <return_type> <function>
    {

    }

by your solution, such as:


    bool isValidSudoku(vector<vector<char>>& board) 
    {

        vector< unordered_set<char> > rows(9, unordered_set<char>());
        vector< unordered_set<char> > columns(9, unordered_set<char>());
        vector< unordered_set<char> > boxes(9, unordered_set<char>());

        for(unsigned i = 0; i < board.size(); i++)
        for(unsigned j = 0; j < board[i].size(); j++)
        {
            if(board[i][j] == '.') continue;

            if( rows[i].find(board[i][j]) != rows[i].end()) return false;

            if( columns[j].find(board[i][j]) != columns[j].end() ) return false;

            if( boxes[(i/3)*3+j/3].find(board[i][j]) != boxes[(i/3)*3+j/3].end()) return false;

            rows[i].insert(board[i][j]);
            columns[j].insert(board[i][j]);
            boxes[(i/3)*3+j/3].insert(board[i][j]);

        }

        return true;
    }

Now, you can compile it with *g++* complier

    cd programs/36_Valid_Sudoku
    g++ -o Test_Cases_36 Test_Cases_36.cc -l cppunit

## Add Test Cases

Test cases for [Problem 36](https://leetcode.com/problems/valid-sudoku/) can be saved in file *Test_Cases_10.cc*.
The following code can be added in *test_problem_36*function

    vector< vector<char> > true_input_board = 
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

    vector< vector<char> > false_input_board = 
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

    CPPUNIT_ASSERT( s->isValidSudoku(true_input_board) == true );
    CPPUNIT_ASSERT( s->isValidSudoku(false_input_board) == false );

Compile and run it with

    g++ -o Test_Cases_36 Test_Cases_36.cc -l cppunit
    ./Test_Cases.36

If your solution is correct, you can see the output


    OK (1 tests)
