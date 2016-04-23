#!/usr/bin/env python

import sys
import getopt
import numpy
import brownian
import random 
import datetime


class arguments:
    def __init__(self, argv):
        self.start_value = 1.12325
        self.increment = 0.00001	
        self.count = 100000
        self.offer_offset_start = 0.0001
        self.offer_offset_end = 0.0009
        self.sources = ["SRC1", "SRC2", "SRC3", "SRC4", "SRC5"]
        self.amounts = ["100000.0", "20000.0", "3000000.0", "5000000.0"]
        self.precision = 5
        try:
            options, args = getopt.getopt(argv, "c:i:n:s:a:b:e:p:")
        except getopt.GetoptError as err:
	    print str(err)
	    usage()
	    sys.exit(1)
        for o, v in options:
            if o == "-n":
	        count = int(v)	
	    if o == "-v":
	        start_value = float(v)
            if o == "-i":
	        increment = float(v)
	    if o == "-s":
	        sources = v.split(",")
	    if o == "-a":
	        amounts = v.split(",")
            if o == "-b":
                offer_offset_start = float(v)
            if o == "-e":
                offer_offset_end = float(v)
            if o == "-p":
                precision = int(v)
    def usage(self):
        print "tickgen -v <start value> -i <value increment> -n <number of ticks> -s <source 1,source 2,...> -a <amount 1, amount 2, ...>"



def generate_ticks(start_value, pip_increment, offset_start, offset_end, no_ticks):
    # The Wiener process parameter.
    delta = pip_increment 
    # Total time.
    T = 100000.0
    # Number of steps.
    N = no_ticks - 1
    # Time step size
    dt = T/N
    # Number of realizations to generate.
    m = 1
    # Create an empty array to store the realizations.
    x = numpy.empty((m, N+1))
    # Initial values of x.
    x[:, 0] = start_value
    brownian.brownian(x[:,0], N, dt, delta, out=x[:,1:])
    b = x[0]
    o = random.uniform(offset_start, offset_end) ++ b
    ms = numpy.random.randint(1, 250000, N+1)
    dt = datetime.datetime.utcnow()
    t = []
    for i in range(0, N + 1):
        t.append(dt)
        dt = dt + datetime.timedelta(microseconds=ms[i])
    return t, b, o

def main(argv):
    args = arguments(argv) 
    t, b, o = generate_ticks(args.start_value, args.increment, args.offer_offset_start, args.offer_offset_end, args.count)	
    for i in range(0, args.count):
        size = args.amounts[random.randint(0, len(args.amounts) - 1)]
        exchange = args.sources[random.randint(0, len(args.sources) - 1)]
        print t[i], "\t", exchange, "\t", round(b[i], args.precision), "\t", round(o[i], args.precision), "\t", size

if __name__== "__main__":
    main(sys.argv[1:])
