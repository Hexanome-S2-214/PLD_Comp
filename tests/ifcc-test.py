#!/usr/bin/env python3

# This scripts runs GCC as well as IFCC on each test-case provided and compares the results.
#
# input: the test-cases are specified either as individual
#         command-line arguments, or as part of a directory tree
#
# output: 
#
# The script is divided in three distinct steps:
# - in the ARGPARSE step, we understand the command-line arguments
# - in the PREPARE step, we copy all our test-cases into a single directory tree
# - in the TEST step, we actually run GCC and IFCC on each test-case
#
#

import argparse
import glob
import os
import shutil
import sys
import subprocess
from colorama import Fore, Style
def command(string, logfile=None):
    """execute `string` as a shell command, optionnaly logging stdout+stderr to a file. return exit status.)"""
    if args.verbose:
        print("ifcc-test.py: "+string)
    try:
        output=subprocess.check_output(string,stderr=subprocess.STDOUT,shell=True)
        ret= 0
    except subprocess.CalledProcessError as e:
        ret=e.returncode
        output = e.output

    if logfile:
        f=open(logfile,'w')
        print(output.decode(sys.stdout.encoding)+'\n'+'exit status: '+str(ret),file=f)
        f.close()

    return ret

def dumpfile(name):
    print(open(name).read(),end='')

######################################################################################
## ARGPARSE step: make sense of our command-line arguments

argparser   = argparse.ArgumentParser(
description = "Compile multiple programs with both GCC and IFCC, run them, and compare the results.",
epilog      = ""
)

argparser.add_argument('input',metavar='PATH',nargs='+',help='For each path given:'
                       +' if it\'s a file, use this file;'
                       +' if it\'s a directory, use all *.c files in this subtree')

argparser.add_argument('-rm_fail_ok',default=0)
        
argparser.add_argument('-osd','--output-subdirectory', metavar='PATH',
                        help="Name of the subdir to save the output. Only available if the input is a file.")

argparser.add_argument('-d','--debug',action="count",default=0,
                       help='Increase quantity of debugging messages (only useful to debug the test script itself)')
argparser.add_argument('-v','--verbose',action="count",default=0,
                       help='Increase verbosity level. You can use this option multiple times.')
argparser.add_argument('-w','--wrapper',metavar='PATH',
                       help='Invoke your compiler through the shell script at PATH. (default: `ifcc-wrapper.sh`)')

args=argparser.parse_args()

if args.debug >=2:
    print('debug: command-line arguments '+str(args))

orig_cwd=os.getcwd()
if "ifcc-test-output" in orig_cwd:
    print('error: cannot run from within the output directory')
    exit(1)

if (len(args.input) > 1 or os.path.isdir(args.input[0])) and args.output_subdirectory:
    print('error: cannot use -osd option when the input is a directory')
    exit(1)
    
if not os.path.exists('ifcc-test-output'):
    os.mkdir('ifcc-test-output')

# Liste des tests qui fail, mais c'est normal : message d'erreur différent entre gcc et nous, fonctionnalités qu'on
# n'implémente pas dans tous les détails (affectations enchaînées avec parenthèses par exemple)
# ATTENTION A PAS METTRE DE TEST QUI DEVRAIT MARCHER
flag_remove_tests_fail_but_ok = args.rm_fail_ok
fail_but_ok = ['inv_mult_plus.c', 'inv_div_plus.c', 'inv_affect_enchainee.c', 'affect_enchainee_parentheses.c']
    
## Then we process the inputs arguments i.e. filenames or subtrees
inputfilenames=[]
for path in args.input:
    path=os.path.normpath(path) # collapse redundant slashes etc.
    if os.path.isfile(path):
        if path[-2:] == '.c':
            # exclusion de certains tests choisis
            if flag_remove_tests_fail_but_ok:
                for file_fail_but_ok in fail_but_ok:
                    if path.find(file_fail_but_ok) != -1:
                        continue
            inputfilenames.append(path)
        else:
            print("error: incorrect filename suffix (should be '.c'): "+path)
            exit(1)
    elif os.path.isdir(path):
        for dirpath,dirnames,filenames in os.walk(path):
            for name in filenames:
                flag = 0
                if flag_remove_tests_fail_but_ok:
                    for file_fail_but_ok in fail_but_ok:
                        if name.find(file_fail_but_ok) != -1:
                            flag = 1
                            continue
                if name[-2:]=='.c' and flag == 0:
                    inputfilenames+=[dirpath+'/'+name]
    else:
        print("error: cannot read input path `"+path+"'")
        sys.exit(1)

## debug: after treewalk
if args.debug:
    print("debug: list of files after tree walk:"," ".join(inputfilenames))

## sanity check
if len(inputfilenames) == 0:
    print("error: found no test-case in: "+" ".join(args.input))
    sys.exit(1)

## Here we check that  we can actually read the files.  Our goal is to
## fail as early as possible when the CLI arguments are wrong.
for inputfilename in inputfilenames:
    try:
        f=open(inputfilename,"r")
        f.close()
    except Exception as e:
        print("error: "+e.args[1]+": "+inputfilename)
        sys.exit(1)

## Last but not least: we now locate the "wrapper script" that we will
## use to invoke ifcc
if args.wrapper:
    wrapper=os.path.realpath(os.getcwd()+"/"+ args.wrapper)
else:
    wrapper=os.path.dirname(os.path.realpath(__file__))+"/ifcc-wrapper.sh"

if not os.path.isfile(wrapper):
    print("error: cannot find "+os.path.basename(wrapper)+" in directory: "+os.path.dirname(wrapper))
    exit(1)

if args.debug:
    print("debug: wrapper path: "+wrapper)
        
######################################################################################
## PREPARE step: copy all test-cases under ifcc-test-output

jobs=[]
cpt = 1
for inputfilename in inputfilenames:
    if args.debug>=2:
        print("debug: PREPARING "+inputfilename)

    if 'ifcc-test-output' in os.path.realpath(inputfilename):
        print('error: input filename is within output directory: '+inputfilename)
        exit(1)

    # pas de test créé pour certains tests particuliers, cf ci-dessus
    if inputfilename in fail_but_ok:
        print("test fail_ok")
        continue
    
    ## each test-case gets copied and processed in its own subdirectory:
    ## ../somedir/subdir/file.c becomes ./ifcc-test-output/somedir-subdir-file/input.c
    subdir = 'ifcc-test-output/' + (args.output_subdirectory if args.output_subdirectory else (str(cpt)+'-'+inputfilename.strip("./")[:-2].replace('/','-')))

    if os.path.exists(subdir):
        shutil.rmtree(subdir)

    print(subdir)

    os.mkdir(subdir)
    shutil.copyfile(inputfilename, subdir+'/input.c')
    jobs.append(subdir)
    cpt+=1

## eliminate duplicate paths from the 'jobs' list
unique_jobs=[]
for j in jobs:
    for d in unique_jobs:
        if os.path.samefile(j,d):
            break # and skip the 'else' branch
    else:
        unique_jobs.append(j)
jobs=sorted(unique_jobs)
# debug: after deduplication
if args.debug:
    print("debug: list of test-cases after deduplication:"," ".join(jobs))


######################################################################################
## TEST step: actually compile all test-cases with both compilers

cpt = 0
cpt_test_ok = 0
failed_tests = []

for jobname in jobs:
    os.chdir(orig_cwd)
    
    cpt += 1

    print('--------------------------')
    print('TEST-CASE : '+jobname)
    os.chdir(jobname)
    
    ## Reference compiler = GCC
    gccstatus=command("gcc -S -o asm-gcc.s input.c", "gcc-compile.txt")
    if gccstatus == 0:
        # test-case is a valid program. we should run it
        gccstatus=command("gcc -o exe-gcc asm-gcc.s", "gcc-link.txt")
    if gccstatus == 0: # then both compile and link stage went well
        exegccstatus=command("./exe-gcc", "gcc-execute.txt")
        if args.verbose >=2:
            dumpfile("gcc-execute.txt")
            
    ## IFCC compiler
    ifccstatus=command(wrapper+" asm-ifcc.s input.c", "ifcc-compile.txt")
    
    if gccstatus != 0 and ifccstatus != 0:
        ## ifcc correctly rejects invalid program -> test-case ok
        print(Fore.GREEN +"TEST OK")
        print(Style.RESET_ALL)
        cpt_test_ok += 1
        continue
    elif gccstatus != 0 and ifccstatus == 0:
        ## ifcc wrongly accepts invalid program -> error
        print(Fore.RED + "TEST FAIL (your compiler accepts an invalid program)")
        print(Style.RESET_ALL)
        failed_tests.append(jobname)
        continue
    elif gccstatus == 0 and ifccstatus != 0:
        ## ifcc wrongly rejects valid program -> error
        print(Fore.RED +"TEST FAIL (your compiler rejects a valid program)")
        print(Style.RESET_ALL)
        if args.verbose:
            dumpfile("ifcc-compile.txt")
        failed_tests.append(jobname)
        continue
    else:
        ## ifcc accepts to compile valid program -> let's link it
        ldstatus=command("gcc -o exe-ifcc asm-ifcc.s", "ifcc-link.txt")
        if ldstatus:
            print(Fore.RED +"TEST FAIL (your compiler produces incorrect assembly)")
            print(Style.RESET_ALL)
            if args.verbose:
                dumpfile("ifcc-link.txt")
            failed_tests.append(jobname)
            continue

    ## both compilers  did produce an  executable, so now we  run both
    ## these executables and compare the results.
        
    command("./exe-ifcc","ifcc-execute.txt")
    if open("gcc-execute.txt").read() != open("ifcc-execute.txt").read() :
        print(Fore.RED +"TEST FAIL (different results at execution)")
        print(Style.RESET_ALL)
        if args.verbose:
            print("GCC:")
            dumpfile("gcc-execute.txt")
            print("you:")
            dumpfile("ifcc-execute.txt")
        failed_tests.append(jobname)
        continue

    ## last but not least
    print(Fore.GREEN+ "TEST OK")
    print(Style.RESET_ALL)
    cpt_test_ok += 1

## Affichage du taux d'erreur
taux_erreur = (1-cpt_test_ok/cpt)*100
print('\nTaux d\'erreur : ' + str(round(taux_erreur, 2)) + "%")

if taux_erreur > 0:
    print("\nListe des tests non validés :\n")
    for test in failed_tests:
        print(test.removeprefix("ifcc-test-output/"))

    exit(1)