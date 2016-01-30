#!/usr/bin/python
import datetime
from time import strftime
import argparse
import subprocess
import os
import tempfile
import timeit

def run_lmbench_test(args, logfile):
    p = subprocess.Popen(args, stderr=logfile)
    p.wait()

#run the 3 ram benchmarks once and add a line to a csv output file
def run_lmbench(outfile, binary_dir):
    test = str(binary_dir) + "/"+ "bw_mem"
    with tempfile.TemporaryFile() as read_log, tempfile.TemporaryFile() as write_log, tempfile.TemporaryFile() as copy_log:
        #run read test
        args = [test, "200M", "rd"]
        run_lmbench_test(args, read_log)
        read_log.seek(0)
        read_data = read_log.read().replace("\n", "")
        print "Read test: "+str(read_data)
        #run write test
        args = [test, "200M", "wr"]
        run_lmbench_test(args, write_log)
        write_log.seek(0)
        write_data = write_log.read().replace("\n", "")
        print "Write test: "+str(write_data)
        #run copy test
        args = [test, "100M", "cp"]
        run_lmbench_test(args, copy_log)
        copy_log.seek(0)
        copy_data = copy_log.read().replace("\n", "")
        print "Copy test: "+str(copy_data)
        #parse data and output to the csv

    
        read_tokens = read_data.split(" ")
        write_tokens = write_data.split(" ")
        copy_tokens = copy_data.split(" ")
    
        all_data = read_tokens + write_tokens + copy_tokens
        all_data_joined = str(",".join(all_data)) + "\n"
    
        out_handle = open(outfile, "a")
        out_handle.write(all_data_joined)
        out_handle.close()
    

if __name__ == "__main__":
    timestamp_str = str(strftime("%Y-%m-%d_%H:%M:%S"))
    argparser = argparse.ArgumentParser()
    argparser.add_argument("--output_file_scanner", help="Name of the output csv for the results when the memory scanner is running. Default is 'memory_scanner_running<timestamp>.csv'", default=str("memory_scanner_running" + timestamp_str + ".csv"))
    argparser.add_argument("--memory_scanner_log", help="Name of the log for the memory scanner stdout. Default is 'memory_scanner_log<timestamp>.log'", default=str("memory_scanner_log" + timestamp_str + ".log"))
    argparser.add_argument("--output_file_none", help="Name of the output csv for the results when the memory scanner is not running. Default is 'memory_scanner_none<timestamp>.csv'", default=str("memory_scanner_none" + timestamp_str + ".csv"))
    argparser.add_argument("--lmbench_dir", help="Location of the lmbench bin/ folder. Default is /home/michael/lmbench-3.0-a9/bin/armv7l-linux-gnu", default=str("/home/michael/lmbench-3.0-a9/bin/armv7l-linux-gnu"))
    argparser.add_argument("--memory_scanner", help="Location of the memory scanner binary. Default is /home/michael/xilinx_zedboard_c/output/memory_scanner.o", default=str("/home/michael/xilinx_zedboard_c/output/memory_scanner.o"))
    argparser.add_argument("--skip_scanner", help="Skips the memory scanner if greater than 0. Default is 0. If greater than zero, runs this number of iterations of the lmbench tests.", type=int, default=0)

    args = argparser.parse_args()
    tools_dir = args.lmbench_dir
    mem_scanner = args.memory_scanner
    mem_scanner_log = args.memory_scanner_log
    outfile_scanner = args.output_file_scanner
    outfile_none = args.output_file_none
    skip_scanner = args.skip_scanner

    csv_header = "read_bytes,read_throughput,write_bytes,write_throughput,copy_bytes,copy_throughput\n"

    #first, run the memory scanner and run the lmbench ram stuff while the memory scanner process
    #is running

    elapsed = 0

    if skip_scanner <= 0:
        print "Starting the memory tests with the memory scanner running"
        with open(mem_scanner_log, 'rw') as mem_log:
            start_time = timeit.default_timer()
            mem_p = subprocess.Popen([mem_scanner], stdout=mem_log)
    
            with open(outfile_scanner, 'w') as outfile:
                outfile.write(csv_header)
    
            #poll() returns None while the process is running
            #need to time this and run and save the ram benchmarks
            while mem_p.poll() is None:
                run_lmbench(outfile_scanner, tools_dir)
                
            elapsed = timeit.default_timer() - start_time
            print "Python measured that it took "+str(elapsed)+" seconds for the hardware to run"

    #now run the lmbench stuff for the time that it took the memory scanner to run, or for the number of iterations specified by the debug flag

    if skip_scanner > 0:
        print "Starting the debugging of the lmbench tools for "+str(skip_scanner)+" iterations"
        with open(outfile_none, 'w') as outfile:
            outfile.write(csv_header)
        for i in range(skip_scanner):
            run_lmbench(outfile_none, tools_dir)

    else:
        print "Starting the lmbench tools for the same amount of time that the memory scanner took"
        with open(outfile_none, 'w') as outfile:
            outfile.write(csv_header)
        start_time = timeit.default_timer()
        none_elapsed = 0
        while none_elapsed < elapsed:
            run_lmbench(outfile_none, tools_dir)
            none_elapsed = timeit.default_timer() - start_time
        print "Python ran the lmbench tools without the memory scanner running for "+str(none_elapsed)+" seconds"




































