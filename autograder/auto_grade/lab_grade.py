#!/usr/bin/python

import os

def check_output(alloc_output, correct_output):
    fa = open(alloc_output, 'r')
    fc = open(correct_output, 'r')
    line_a = ""
    line_c = ""
    is_bad = False
    while True:
        line_c = fc.readline()
        line_a = fa.readline()
	#print(line_c)
	#print(line_a)
        if 'cycle' in line_c:
            break
        if line_a == "":
            is_bad = True
            break
        if not line_a == line_c:
            is_bad = True
            break

    fa.close()
    fc.close()
    big_number = '100000'
    if is_bad == True:
        return big_number

    if not 'cycle' in line_a:
        return big_number

    return line_a.rsplit(' ', 1)[0].rsplit(' ', 1)[1]

#return number of cycles after allocation and checking the outputs
def lab_grade(test_file, sim):
    #get input for simulator
    os.system('cp ' + test_file + ' ./')
    file = test_file.rsplit('/', 1)[1]
    f = open(file, 'r')
    input = ""
    output = []

    while True:
        line = f.readline().strip()
        if line == "":
            break
        if '//SIM INPUT:' in line:
            input = line.split(':')[1]
            break

    f.close()

    # get result without scheduling
    correct_output = 'correct_output'
    os.system(sim + ' -s 3 ' + input + ' < ' + file + ' > ' + correct_output)

    # compare output with scheduling to result without scheduling
    # if same outputs, return number of cycles
    # if not same, return -1
    alloc_output = 'alloc_output'
    os.system('chmod +x schedule')
    #print('checking ' + file)
    test_string = 'timeout 120s ./schedule ' + file + ' | ' + sim + ' -s 1 ' + input + ' > ' + alloc_output
    #print(test_string)
    os.system(test_string)
    cycles = check_output(alloc_output, correct_output) # outup comparison
    #os.system('rm ' + alloc_output)

    #os.system('rm ' + correct_output)
    return cycles


#=======================================================
# Code lifted directly from l2ag

def check_missing_file_name(file_name):
    if not os.path.isfile(file_name):
        print("Check for missing file name produced no output")
        return 0

    o_file = open(file_name,'r');

    #look for "ERROR" in the file
    error_message_found = 0;
    while True:
        o_line = o_file.readline().strip(' ')

        if o_line == '':
            break;

        if o_line.find("Traceback") != -1:
            print("\nMissing file test produced a Traceback.")
            error_message_found = 0
            break

        if o_line.find("ERROR") != -1:
            error_message_found = 1

        o_line = o_line.lower()
        if error_message_found == 0 and o_line.find("error") != -1:
            print("\nProduced 'file not found' message, but ERROR was not in uppercase (1)")

    return error_message_found

def check_for_help_message(file_name):
    if not os.path.isfile(file_name):
        print("Check for missing help message check produced no output")
        return 0

    o_file = open(file_name,'r');

    #look for "-h" in the file
    found_h = 0

    while True:
        o_line = o_file.readline()  #.strip(' ')
        if o_line == '':
            break
        
        if o_line.find("-h") != -1:
            found_h = 1

    if found_h == 0:
        print("Help message does not list '-h'")

    return found_h

# Check to see if it handle a bad input file name gracefully
def lab_missing_file_check():
    
    # set stdin to /dev/null in case lab reads from terminal if open
    # fails. Use timeout as a hedge against other bad results from the open()
    fname = "./does_not_exist"
    command_line = 'timeout 20s ./schedule 5 ' + fname + '.mine >& ./'+ fname+ '.output </dev/null'
    os.system(command_line)

    result = check_missing_file_name(fname+".output")
    return result

# Check to see if it prints out a complete help message
def lab_help_message_check():
    fname = "./helpmessage.output"
    command_line = './schedule -h >& ./'+fname
    os.system(command_line)

    result = check_for_help_message(fname)
    return result


