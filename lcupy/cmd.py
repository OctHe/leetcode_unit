import os

from . import file_format
from . import info

CC = 'g++'
LIB = 'cppunit'

def lcu_add(args):

    prob_dict = info.get_problem_dict()

    if args.id in prob_dict:
        print('Problem exist!')
        print('Fail to add a new problem!')

    else:
        problem_path = file_format.problem_path_format(args.id, args.name)
        problem_file = file_format.problem_file_format(args.id, args.name)
        test_file = file_format.test_file_format(args.id, args.name)

        # Create a new directory
        os.makedirs(problem_path)

        # Write new files
        with open(problem_file, 'w') as f:
            f.write(file_format.get_problem_content(args.id, args.name))
        with open(test_file, 'w') as f:
            f.write(file_format.get_test_content(args.id, args.name))

def lcu_list(args):

    print(args.all)
    prob_dict = info.get_problem_dict()

    print('ID\t', 'Name')
    for prob_id in prob_dict.keys():
        print(prob_id, '\t', prob_dict[prob_id].replace("_", " "))

def lcu_run(args):

    prob_dict = info.get_problem_dict()

    if prob_dict.get(args.id) is None:
        print('The ID is not added!')
        print('Please display the problems: ')
        print('./leetcode_unit list')

    else:
        input_file = file_format.test_file_format(args.id, prob_dict[args.id])
        output_file = file_format.exec_file_format(args.id, prob_dict[args.id])

        compile_problem = CC + ' -o ' + output_file + ' ' + input_file + ' -l ' + LIB
        run_problem = output_file
        delete_output_file = 'rm ' + output_file

        os.system(compile_problem)
        os.system(run_problem)
        os.system(delete_output_file)

def lcu_debug(args):

    prob_dict = info.get_problem_dict()

    if prob_dict.get(args.id) is None:
        print('The ID is not added!')
        print('Please display the problems: ')
        print('./leetcode_unit list')

    else:
        input_file = file_format.test_file_format(args.id, prob_dict[args.id])
        output_file = file_format.exec_file_format(args.id, prob_dict[args.id])

        compile_problem = CC + '-g -o ' + output_file + ' ' + input_file + ' -l ' + LIB
        debug_problem = 'gdb ' + output_file

        os.system(compile_problem)
        os.system(debug_problem)

def lcu_delete(args):

    prob_dict = info.get_problem_dict()

    if prob_dict.get(args.id) is None:
        print('Problem ', args.id, ' does not exist!')

    else:
        problem_path = file_format.problem_path_format(args.id, prob_dict[args.id])

        print("This sub-command will delete Problem ", args.id, " .")
        print("Input the ID of the problem to continue, or input others to stop")
        input_id = input("ID: ")

        if(input_id == str(args.id)):
            delete_problem = 'rm -rf ' + problem_path

            os.system(delete_problem)
            print("Successfully delete the problem.")
        else:
            print("Stop to delete the problem.")
