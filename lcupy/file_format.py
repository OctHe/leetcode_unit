from string import Template
from . import info

problem_dir_temp = Template('${index}_${problem}/')
header_file_temp = Template('${index}_${problem}.h')
source_file_temp = Template('Test_Cases_${index}.cc')
exe_file_temp = Template('Test_Cases_${index}')


def problem_path_format(problem_id, problem_name):

    problem_path = info.get_problems_path() + problem_dir_temp.substitute(index=problem_id, problem=problem_name)

    return problem_path

def problem_file_format(problem_id, problem_name):

    problem_path = problem_path_format(problem_id, problem_name)
    problem_file = problem_path + header_file_temp.substitute(index=problem_id, problem=problem_name)

    return problem_file

def test_file_format(problem_id, problem_name):

    problem_path = problem_path_format(problem_id, problem_name)
    test_file = problem_path + source_file_temp.substitute(index=problem_id, problem=problem_name)

    return test_file

def exec_file_format(problem_id, problem_name):

    problem_path = problem_path_format(problem_id, problem_name)
    exec_file = problem_path + exe_file_temp.substitute(index=problem_id)
    
    return exec_file

def get_problem_content(problem_id, problem_name):

    with open(info.get_problem_template_file(), 'r') as f:
        problem_template = Template(f.read())

    return problem_template.substitute(index=problem_id, problem=problem_name) 

def get_test_content(problem_id, problem_name):

    with open(info.get_test_template_file(), 'r') as f:
        test_template = Template(f.read())

    return test_template.substitute(index=problem_id, problem=problem_name) 
