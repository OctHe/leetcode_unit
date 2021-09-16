#! /usr/bin/python3
#
#   leetcode_unit is a program to generate problems and unit tests for Leetcode
#

import sys, os
from string import Template
import argparse

default_templates_path = './templates/'
default_problems_path = './problems/'

default_problem_temp = 'temp_problem.h'
default_test_temp = 'temp_unit_test.cc'

problem_dir_temp = Template('${index}_${problem}/')
header_file_temp = Template('${index}_${problem}.h')
source_file_temp = Template('Test_Cases_${index}.cc')

def lcu_add(args):
    # Read template files
    with open(default_templates_path + default_problem_temp, 'r') as f:
        problem_template = Template(f.read())
        f.close()

    with open(default_templates_path + default_test_temp, 'r') as f:
        test_template = Template(f.read())
        f.close()

    problem_string = problem_template.substitute(index=args.index, problem=args.name)
    test_string = test_template.substitute(index=args.index, problem=args.name)

    # Write new files
    problem_path = default_problems_path + problem_dir_temp.substitute(index=args.index, problem=args.name)
    header_file = problem_path + header_file_temp.substitute(index=args.index, problem=args.name)
    source_file = problem_path + source_file_temp.substitute(index=args.index, problem=args.name)

    if not os.path.exists(problem_path):
        os.makedirs(problem_path)

    if os.path.isfile(header_file):
        print('File ' + header_file + ' already exists!')
    else:
        with open(header_file, 'w') as f:
            f.write(problem_string)
            f.close()

    if os.path.isfile(source_file):
        print('File ' + source_file + ' already exists!')
    else:
        with open(source_file, 'w') as f:
            f.write(test_string)
            f.close()

def lcu_list(args):
    print(os.listdir(default_problems_path))

def lcu_run(args):
    pass

def lcu_delete(args):
    pass

if __name__ == '__main__':
   
    # CMD options
    parser = argparse.ArgumentParser(description='A cmd tool to create the solution of leetcode problems.')

    subparsers = parser.add_subparsers(help='sub-command help')

    parser_add = subparsers.add_parser('add', help='add a new problem.')
    parser_add.add_argument('-i', '--index', type=int, required=True, help='Index of the problem.')
    parser_add.add_argument('-n', '--name', type=str, required=True, help='Name of the problem.')
    parser_add.set_defaults(func=lcu_add)

    parser_ls = subparsers.add_parser('list', help='list problems')
    parser_ls.add_argument('-a', '--all', action='store_true', help='List all problems.')
    parser_ls.set_defaults(func=lcu_list)

    args = parser.parse_args(sys.argv[1:])
    args.func(args)



    
