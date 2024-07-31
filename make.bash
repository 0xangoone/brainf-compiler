#!/usr/bin/bash
compiler=g++
cd src
echo "compiling and linking ..."
cxx_files=$(ls ./*.cpp)
g++ $cxx_files -o ../build/brainf
cd ..
if [ $# -gt 0 ]
then
	echo "running ...."
	if [ $1 == "run" ]
	then
		./build/brainf
	fi
fi
