#! /bin/bash

# Simple tool to compile a solution from anywhere given the year and day

if [ "$#" -ne 2 ]; then 
	echo -e "Provide exatly two argument, the year and the day.\nExample: aocdl 2023 1 => year 2023 day 1"
	exit 1 
fi

year=$1
day=$2
script_directory=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
compiling_directory="$script_directory/../$year/day_$day"

echo "Compiling..."
g++ -o "$compiling_directory/solution.exe" "$compiling_directory/solution.cpp"

if [ "$?" -ne 0 ]; then
	exit 1
fi

echo "Running..."
"$compiling_directory/solution.exe" "$compiling_directory/input.txt"