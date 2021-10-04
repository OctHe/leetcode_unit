import os

default_templates_path = './templates/'
default_problems_path = './problems/'

default_problem_temp = 'temp_problem.h'
default_test_temp = 'temp_unit_test.cc'

def get_templates_path():

    return default_templates_path

def get_problems_path():

    return default_problems_path

def get_problem_template_file():

    return default_templates_path + default_problem_temp

def get_test_template_file():

    return default_templates_path + default_test_temp

def get_problem_dict():

    prob_dict = {}
    for problem in os.listdir(get_problems_path()):
        prob_list = problem.split('_', 1)
        prob_dict[int(prob_list[0])] = prob_list[1]

    sorted_prob_dict = {}
    for i in sorted(prob_dict):
        sorted_prob_dict[i] = prob_dict[i]

    return sorted_prob_dict
