#!/bin/bash

tick_file="./eurusd.ticks"

if [ -n "$1" ]; then
	tick_file=$1
else
	echo "no file specified.  generating $tick_file"	
	./tickgen.py > $tick_file
fi

if [ -f "$tick_file" ]; then
	echo "running tickstore..."
	#TODO: use the correct path for the tickstore binary
	../../bin/linux/x64/debug/tickstore $tick_file
else
	echo "$tick_file does not exist"
fi
