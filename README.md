# leetcode_unit

Customized test cases is also important in [Leetcode](https://leetcode.com/).

*leetcode_unit* is a lightweight and offline tool to generate solutions and test cases for the problems in [Leetcode](https://leetcode.com/).

## Support Platform

It has been tested on Ubuntu 20.04 and Windows Subsystem for Linux (WSL) v2.

On Ubuntu 20.04 system, you need to install
1. python 3
1. make (>=4.2.1) and g++(>=8.3.0)
2. cppunit (>=1.14.0)

you can install them using *apt*
    
    sudo apt install make g++ libcppunit-dev

On WSL v2, you also must install Ubuntu 20.04 version.
Besides the above tools and libraries, it is better to install *vscode*.

Ideally, leetcode_unit can be used at other Linux platforms.

## Download leetcode_unit

    git clone https://github.com/OctHe/leetcode_unit
    cd leetcode_unit


## Add New Problem

The following content uses the [Problem 1](https://leetcode.com/problems/two-sum/) as an example.

The program is a python program named as *leetcode_unit.py*.
To add a new problem, you can directly run the following command

    ./leetcode_unit add -i 1 -n Two_Sum

where *-i* is the index of the problem and *-n* is its name.

After running the command, a new directory will be created in the *./problems/* directory like this:

    .   
    ├── problems    
    │   ├── 1_Two_Sum     
    │   │   ├── 1_Two_Sum.h   
    │   │   └── Test_Cases_1.cc    

Until now, you can add your own solution to this new problem.

## Add Solution

*1_Two_Sum.h* contains Solution class. Open it with a editor, you need to replace the following contents:

    <return_type> <function>
    {

    }

by your solution, such as:

    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> sum;
        int result;
        for(int i = 0; i < nums.size(); i++)
        {
            result = target - nums[i];
            for(int j = i+1; j < nums.size(); j++)
            {
                if(result == nums[j])
                {
                    sum.push_back(i);
                    sum.push_back(j);
                }
            }
        }
        return sum;
    }

## Run Solution

leetcode_unit provides a command to run the solution.

    ./leetcode_unit.py run -i 1

This command will automatically compile (for C and C++) and run the program of [Problem 1](https://leetcode.com/problems/two-sum/).


If the program has no error, you can see the output

    OK (1 tests)

Note that the results will be always OK because test cases have not been added.

## Add Test Cases

Test cases for [Problem 1](https://leetcode.com/problems/two-sum/) can be saved in file *Test_Cases_1.cc* like this

    void test_problem_1::test_case_1()
    {
        // A simple assert: CPPUNIT_ASSERT
    }

The following code can be added in the function

    void test_problem_1::test_case_1()
    {
        vector<int> input = {2, 7, 11, 15};
        int target = 9;
        
        vector<int> output = {0, 1};

        CPPUNIT_ASSERT(s->twoSum(input, target) == output);
    }

Compile and run it with

    ./leetcode_unit.py run -i 1

## TODO List

1. ``open'' sub-command (work with gvim)
2. Time and space complexity of each problem
3. python style ([Google python style](https://google.github.io/styleguide/pyguide.html))
4. problem info in template