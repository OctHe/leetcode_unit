#! /usr/bin/python3
#
#   leetcode_unit is a program to generate problems and unit tests for Leetcode
#

import sys
import argparse

from pylcu import cmd

if __name__ == '__main__':
   
    # CMD options
    parser = argparse.ArgumentParser(description='A cmd tool to create the solution of leetcode problems.')

    subparsers = parser.add_subparsers(help='sub-command help')

    parser_add = subparsers.add_parser('add', help='Add a new problem.')
    parser_add.add_argument('-i', '--id', type=int, required=True, help='ID of the problem.')
    parser_add.add_argument('-n', '--name', type=str, required=True, help='Name of the problem.')
    parser_add.set_defaults(func=cmd.lcu_add)

    parser_ls = subparsers.add_parser('list', help='List problems.')
    parser_ls.add_argument('-a', '--all', action='store_true', help='List all problems.')
    parser_ls.set_defaults(func=cmd.lcu_list)

    parser_run = subparsers.add_parser('run', help='Run the solution of a target problem')
    parser_run.add_argument('-i', '--id', type=int, required=True, help='ID of the problem.')
    parser_run.set_defaults(func=cmd.lcu_run)

    parser_run = subparsers.add_parser('delete', help='Delete the problem')
    parser_run.add_argument('-i', '--id', type=int, required=True, help='ID of the problem.')
    parser_run.set_defaults(func=cmd.lcu_delete)

    args = parser.parse_args(sys.argv[1:])
    args.func(args)



    
