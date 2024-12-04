## COMP 412, Lab3 autograder

import os, time, calendar, datetime, sys
from datetime import date, timedelta, datetime
from changeto_testlocation import change_to_test_location, locate_exe
from lab_grade import lab_grade, lab_missing_file_check, lab_help_message_check
from get_id import get_id
import operator

#
# Configuration directions
#
# 1. Set the base_name to point to the directory above the current directory
#    -- that is, teh director that contains the file "Grader".
#
# 2.  Set the "normal_deadline", if necessary.
#     -- check early_day_limit and late_day_limit
#


## CONFIGURATION SETTINGS

# base name must end with a slash ("/")
base_name = "/storage-home/s/sb121/comp412lab3/autograder/"

# The on-time due date for the assignment
normal_deadline = date(2023,10,1)  # set annually

#
# Stuff after this point should be set when the lab handout changes or
# the software changes
#

## GRADING RUBRIC
CORR_SCORE = 40
EFF_SCORE  = 30

#
early_day_limit = timedelta(days=2)  # determined by the grading rubric
late_day_limit  = timedelta(days=5)  # determined by the grading rubric
archive_date    = date(2100,1,1)     # impossibly far in the future

# If the submission fails to conform (e.g., README issues), it loses
# a striaght 10% of total points.
# If it conforms, that adds zero points (conformance should be given,
# not rewarded).

def check_file_type(type):
    for cdir, dirs, files in os.walk('./'):
        for file in files:
            if type in file:
                return True
    return False

def run_test(submission,name,netid,conform_points,sub_date):
    global ref_results
    global test_dir
    global sorted_tests

    sim = '/clear/courses/comp412/students/lab3/sim'

    print("File\t\tLab\tRef\tDifference")
    print("------------------------------------------")
    result = {}

    result_file.write(netid+'\t'+name)
    
    for test in sorted_tests:
        if not '.i' in test:
            continue

        result[test] = lab_grade(test_dir+test, sim)
        diff = str(int(result[test]) - int(ref_results[test]))
        if len(test) < 8:
            print(test+"\t\t"+result[test]+"\t"+ref_results[test]+"\t"+diff)
        else:
            print(test+"\t"+result[test]+"\t"+ref_results[test]+"\t"+diff)

        result_file.write('\t'+result[test])
        
    print("")
    result_file.write('\n')

    # and write the points to the summary file
    corr_points = check_correctness(result)
    corr_points = round(corr_points * CORR_SCORE,2)
    eff_points = sum_result(result,ref_results) 
    eff_points = min(eff_points,1.0)   # cap at 1.0
    eff_points = round(eff_points * EFF_SCORE,2)
            
        
    print("\n\tCorrectness points:   "+str(corr_points)+' / '+str(CORR_SCORE)+'\t')
    print("\tEffectiveness points: "+str(eff_points)+' / '+str(EFF_SCORE))

    # check for help message and missing file message, cuz it angers me
    mf = lab_missing_file_check()
    hm = lab_help_message_check()
    
    if conform_points != 0 or mf != 1 or hm != 1:
        c_pts = "\t-10"
        print("\tLab loses 10 points for conformance problems")
    else:
        c_pts = "\t0"
    points_file.write(netid+'\t'+name+'\t'+str(corr_points)+'\t'+str(eff_points)+c_pts)

    # days late calculation
    diff = sub_date - normal_deadline
    if diff < -early_day_limit:
        diff = -early_day_limit
    elif diff > late_day_limit:
        diff = late_day_limit
    points_file.write('\t'+str(diff.days)+'\n')

    print("")
        
    return result

def get_input(file):
    f = open(file, 'r')
    input = ""
    while True:
        line = f.readline()
        if line == "":
            break
        if 'SIM INPUT' in line:
            input = line.split(':')[1]
            break
    return input.strip()

def get_ref_cycles():
    global test_dir
    global sorted_tests
    
    lab3_ref = '/clear/courses/comp412/students/lab3/lab3_ref'
    lab3_sim = '/clear/courses/comp412/students/lab3/sim'

    results = {}
    for test in sorted_tests:
        test_file = test_dir+test
        input = get_input(test_file)
        cmd = lab3_ref + ' ' + test_file + ' | ' + lab3_sim + ' -s 1 ' + input + ' | grep cycles > out'
        #print(cmd)
        os.system(lab3_ref + ' ' + test_file + ' | ' + lab3_sim + ' -s 1 ' + input + ' | grep cycles > out')
        f = open('out', 'r')
        line = f.readline()
        f.close()
        results[test] = line.rsplit(' ', 2)[1]
    os.system('rm -rf out')
    return results

# This version computes the sum of the reference implementation's cycle counts,
# the sum of the student lab's adjusted cycle counts ( > 2x ref becomes ref ),
# and computes a % distance from 100% of lab3_ref's counts.
def sum_result(result,ref_result):
    global sorted_tests
    
    sum = 0
    ref_sum = 0

    for test in sorted_tests:
        ref_cycles = int(ref_result[test])
        ref_sum = ref_sum + ref_cycles
        upper_bound = 2 * ref_cycles
        student_cycles = int(result[test])
        if student_cycles > upper_bound:
            student_cycles = upper_bound
        if student_cycles == 0:
            student_cycles = upper_bound
        sum = sum + student_cycles

    return 1.0 - float(sum - ref_sum) / float(ref_sum)
    
def check_correctness(result):
    global sorted_tests
    
    total_test = 0

    for item in sorted_tests:
        total_test = total_test + 1

    correct_count = total_test
    for test in result.keys():
        if result[test] == '100000':
            correct_count = correct_count - 1

    return 1.0 * correct_count / total_test

def main():
    global root
    global tests
    global ref_results
    global test_dir
    global sorted_tests

    global result_file
    global points_file

    root = os.getcwd()

    test_dir = base_name + "auto_grade/blocks/"
    sorted_tests = sorted(os.listdir(test_dir))
    
    #for each submission:
    #1. make a tmp dir
    #2. cp the tar ball to the dir
    #3. extract and the tar ball
    #4. locate the makefile or the executable
    #5. ready to run with the executable

    failed = []

    print("COMP 412, Lab3, Autograder")
    print("--------------------------")
    print("\nThe Lab 3 autograder does not measure running time.")
    print("Use the autotimer instead.\n")
    print("Correcness and Effectiveness points are based on the")
    print("standard that 90% of the reference implementation receives")
    print("full credit.\n")

    if not os.path.isdir(base_name):
        print('\nNeed to set "base_name" in auto_grade/auto_grade.py\n\n')
        exit(-1)

    print('... Gathering cycle counts from lab3_ref ...')
    ref_results = get_ref_cycles()
    print(" ")

    # open the various results files
    # files are written, incrementally, as the tests occur
    # (to preserve results of partial runs)
    #

    result_dir = base_name + "results/"
    
    result_file = open(result_dir + 'grader-cycles.txt', 'w')

    # write the file header
    result_file.write('Shows cycle counts for student lab by each test file\n')
    result_file.write("Import into Excel with tab separators\n\n")    
    result_file.write('NetID\tName')
    for test in sorted_tests:
        result_file.write('\t' + test) 
    result_file.write('\n')    
    
    points_file = open(result_dir + "grader-points.txt", "w")

    # write the file header
    points_file.write("Total points for correctness, efficiency, and conformance\n")
    points_file.write("Import into Excel with tab separators\n\n")
    points_file.write("NetID\tName\tCorrectness\tEffectiveness\tConformance\tDays Late\n")

    failed_file = open(result_dir+'grader-failed'+ '.txt', 'w')

    # write the file header
    failed_file.write('Shows NetIDs of labs that failed to get any correctness points\n\n')
    failed_file.write('NetID\n')
     
    print("================================================================")

    for submission in sorted(os.listdir('./')):
        result_temp = {}
        if os.path.isdir(submission):
            continue

        sub_date = change_to_test_location(submission)
        print('Testing submission: '+submission)
        current_name, current_id, readme_points, keep_processing = get_id()

        if current_id == "":
            current_id = submission.split('_',1)[0]+" (*)"
        if current_name == "":
            current_name = "missing"


        if keep_processing:
            print('Name: '+current_name+', NetId: '+current_id,end="")
            print(', Date from files: ',sub_date)
            
            if not locate_exe(submission) == -1:
                result = run_test(submission,current_name,current_id,readme_points,sub_date)
            else:
                failed.append(current_id)
                print('\nSubmission failed <---\n')

        else:
            failed.append(current_id)
            print("\nSubmission failed\n")
        
        print("================================================================")

        #clean up everything that was created during testing
        os.chdir(root)
        fixed_submission = submission.replace(" ", "\ ").replace("(", "\(").replace(")", "\)").replace("'", "\\'")
        folder = submission.split('.', 1)[0]
        fixed_folder = fixed_submission.split('.', 1)[0]
        os.system('rm ' + fixed_folder + ' -rf')

    result_file.close()
    points_file.close()
    
    # write out the list of ids that failed
    for id in failed:
        failed_file.write(id+ '\n')
    failed_file.close()

    print("\nGrading run complete")

if __name__ == "__main__":
    main()
