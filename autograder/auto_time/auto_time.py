#!/usr/bin/python3

import os, time, calendar, datetime, sys
from datetime import datetime

from changeto_testlocation import change_to_test_location, locate_exe, get_language
from get_id import get_id
import operator

#
# Code to take timing measurements on the lab submission, using the 
# SLOCs test set

#
# Configuration parameters
#

PRODUCTION = False

# base_name contains the path to the directory where this file tree is installed
# It should be one level above the directory that holds this code.

base_name = "/storage-home/s/sb121/comp412lab3/autograder/"

# Locations for test blocks (blocks) and timing blocks (timing)
# These are relative to the directory in base_name

timing_dir = "auto_time/timing_blocks/"

timeout_val = 60.0 # Maximum number of seconds that any run should be allowed
repetitions = 5    # trials at each size

#
# and, the Grading Rubric (e.g., how many points for Scaling and Efficiency
#
SCALE_SCORE = 15
EFF_SCORE   = 15

def run_timing_block(block_name):
    global kill_switch

    path = base_name + timing_dir

    command_line = "timeout "+str(timeout_val)+"s ./schedule "+path+block_name+" >&/dev/null"
    #print("command line: ", command_line)
    
    start_tic = datetime.now()
    os.system(command_line)
    stop_tic  = datetime.now()
    elapsed = stop_tic - start_tic
    ms = (elapsed.days * 86400 + elapsed.seconds) * 1000 + elapsed.microseconds / 1000.0

    if (ms/1000) >= timeout_val:
        kill_switch = 1
    return ms
        
def run_test(submission,id,conforms):
    global scaling
    global t_names
    global t_sizes
    global kill_switch

    scaling = ""

    # have already found and built the executable
    #record name and netid in result file
    details_file.write(current_id + '\t' + current_name)

    # Scalability testing
    scales = 0
    print("Testing Scalability:\n")

    t_times =  [1000000, 1000000, 1000000, 1000000,  1000000,  1000000,  1000000,  1000000]

    kill_switch = 0

    for i in range(0,repetitions):
        n = 7
        if kill_switch > 0:
            print("\n--> Scheduler exceeded timeout value\n")
            break # stop running the iterative trials that improve accuracy
        while n > -1:
            ms = run_timing_block(t_names[n])
            if ms < t_times[n]:
                t_times[n] = ms
            n = n -1

    for i in range(0,8):
        print("\t"+t_names[i]+":  \t"+str(t_times[i]/1000)[0:6]+" seconds")
        details_file.write("\t"+str(t_times[i]/1000)[0:6])

    # analyze scaling
    linear_ct = 0
    noninc_ct = 0
    quad_ct   = 0
    for i in range(0,7):
        ratio = t_times[i+1]/t_times[i]
        if ratio < 1:
            noninc_ct +=1
        if ratio < 2.3:
            linear_ct += 1
        elif ratio > 3.6:
            quad_ct += 1
        else:
           noninc_ct += 1

    if noninc_ct == 0:
        scaling += " linear"
        scale_points = 100
    elif noninc_ct == 1:
        scaling += " linear (1 jump)"
        scale_points = 100
    elif quad_ct > 2:
        scaling = " quadratic"
        scale_points = 0
    else:
        scaling = " unusual"
        scale_points = 0

    # analyze efficiency
    time = t_times[7] / 1000
    language = get_language()

    if language.find("python") > -1:
        if time <= 10.0:
            eff_points = 100
        elif time > 20.0:
            eff_points = 0
        else:
            eff_points = 100 - (time - 10.0) / 0.1   # 0.1 is (20 - 10) /100

    elif language.find("java") > -1:
        if time <= 4.75:
            eff_points = 100
        elif time > 12.0:
            eff_points = 0
        else:
            eff_points = 100 - (time - 2.75) / 0.0725  # 0.0725 is (10 - 2.75) / 100

    elif language.find("c++") > -1:
        if time <= 2.0:
            eff_points = 100
        elif time > 4.0:
            eff_points = 0
        else:
            eff_points = 100 - (time - 2.0) / 0.02  # 0.02 is (4 - 2) / 100

    elif language.find("c") > -1:
        if time <= 1.5:
            eff_points = 100
        elif time > 3.0:
            eff_points = 0
        else:
            eff_points = 100 - (time - 1.5) / 0.015  # 0.015 is (3 - 1.5) / 100

    else:  # others are all 1 sec and 2 sec
        if time <= 1.5:
            eff_points = 100
        elif time > 3.0:
            eff_points = 0
        else:
            eff_points = 100 - (time - 1.5) / 0.15
        
    eff_pts_str = str(round(eff_points*EFF_SCORE/100.0,2))
    sca_pts_str = str(round(scale_points*SCALE_SCORE/100.0,2))
        
    print("\nScaling points: \t"+sca_pts_str+' / '+str(SCALE_SCORE))
    print("Efficiency points: \t"+eff_pts_str+' / '+str(EFF_SCORE)+"  ("+language+", "+str(round(time,3))+")")
    if conforms != 0:
        print("\nSubmission does not conform to specifications.")
        print("Submission will lose 10% of total points unless fixed.")

    # record scaling and efficiency points in results file
    if noninc_ct > 0:
        scaling += " (?)"
        print("\n\tAnomalous behavior: "+str(noninc_ct)+" inputs showed no growth")
        details_file.write("\t"+language+"\t"+scaling+"\t"+sca_pts_str+"\t"+eff_pts_str+"\t*\n")
    else:
        details_file.write("\t"+language+"\t"+scaling+"\t"+sca_pts_str+"\t"+eff_pts_str+"\n")

    points_file.write(current_id+'\t'+current_name+'\t'+eff_pts_str+'\t'+sca_pts_str+'\n')
            
    return 0


def main():
    global root
    global tests
    global base_name
    global current_name
    global current_id
    global details_file
    global failed_file
    global points_file
    global scaling
    global t_names, t_times

    root = os.getcwd()

    #for each submission:
    #1. make a tmp dir
    #2. cp the tar ball to the dir
    #3. extract and the tar ball
    #4. locate the makefile or the executable
    #5. ready to run with the executable

    print('Autotimer: using Scalability SLOCs blocks')
    print(str(repetitions)+" trials at each block size")

    # set up the output files
    if not os.path.isdir(base_name):
        print('\nNeed to set "base_name" in auto_time/auto_time.py\n\n')
        exit(-1)

    result_path = base_name + 'results/'

    details_file = open(result_path + 'timer-details.txt','w')
    failed_file = open(result_path + 'timer-failed.txt','w')
    points_file = open(result_path + 'timer-points.txt','w')

    # write file headers
    details_file.write('Import into Excel with tab separators\n\n')
    details_file.write('NetId\tName\tT1k\tT2k\tT4k\tT8k\tT16k\tT32k\tT64k\tT128k\tLang.\tScaling Pts\tEff Pts %\n')
    points_file.write('Import into Excel with tab separators\n\n')
    points_file.write("NetID\tName\tEfficiency Pts\tScalability Pts\n")    
    failed_file.write('Name\tNetId\n')

    print('=======================================================================')

    t_names =  ["T001k.i","T002k.i","T004k.i","T008k.i","T016k.i","T032k.i","T064k.i","T128k.i"]
    t_sizes =  [1, 2, 4, 8, 16, 32, 64, 128]

    for submission in sorted(os.listdir('./')):
        if os.path.isdir(submission):
            continue

        print('Testing submission: ' + submission)
        submission_date = change_to_test_location(submission)
                
        current_name, current_id, readme_points, keep_processing = get_id()
        if current_id == "":
            current_id   = submission.split('.', 1)[0]
        if current_name == "":
            current_name = "missing"

        print('NetId: ' + current_id + '\tName: ' + current_name)

        if keep_processing:
            print('Name: '+ current_name + ', NetID: ' + current_id,end="")
            print(', Date from files: ',submission_date)

            if not locate_exe(submission) == -1:
                dummy = run_test(submission,current_id,readme_points)
            else:
                print('submission failed to build correctly')
                print('likely a problem with tar file, make file, or script')
                failed_file.write(current_name + '\t' + current_id+'\n')
        else:
            failed_file.write(current_name + '\t' + current_id+'\n')
            print("\nSubmission failed\n")             

        print('\nfinished timing run on submission ' + submission)
        print('=======================================================================')

        #clean up everything that was created during testing
        os.chdir(root)
        fixed_submission = submission.replace(" ", "\ ").replace("(", "\(").replace(")", "\)").replace("'", "\\'")
        folder = submission.split('.', 1)[0]
        fixed_folder = fixed_submission.split('.', 1)[0]
        os.system('rm -rf ' + fixed_folder)

    # close the grading files
    details_file.close()
    failed_file.close()
    points_file.close()
    
    print('\nTiming run complete.')
    exit(0)
    
if __name__ == "__main__":
    main()
