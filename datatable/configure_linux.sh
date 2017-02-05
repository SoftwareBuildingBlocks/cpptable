#!/bin/bash

build_type="$1"
if [ -z $build_type ]; then
	build_type="Release"
elif [ "${build_type^^}" = "DEBUG" ]; then
	build_type="Debug"
elif [ "${build_type^^}" = "RELEASE" ]; then
	build_type="Release"
else
	echo "$1 is not a valid parameter..."
	echo "configure_linux [Release|Debug]"
	echo
	exit 1
fi

cmake -DCMAKE_C_COMPILER=/usr/bin/clang -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DCMAKE_CXX_FLAGS=-std=c++1y -DCMAKE_BUILD_TYPE="$build_type"

