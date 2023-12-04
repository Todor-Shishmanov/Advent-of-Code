#!/bin/bash

# Simple tool to download the input files. Please do not abuse the servers with frequent requests!
# Add your cookie to the session_cookie.txt file!

if [ "$#" -ne 2 ]; then 
	echo -e "Provide exatly two argument, the year and the day.\nExample: aocdl 2023 1 => year 2023 day 1"
	exit 1 
fi

year=$1
day=$2

# if you need the hardcore way... this finds the script's directory through simlinks/dirlinks/china's defense systems/etc...
#
#source=${BASH_source[0]}
#while [ -L "$source" ]; do # resolve $source until the file is no longer a symlink
#  DIR=$( cd -P "$( dirname "$source" )" >/dev/null 2>&1 && pwd )
#  source=$(readlink "$source")
#  [[ $source != /* ]] && source=$DIR/$source # if $source was a relative symlink, we need to resolve it relative to the path where the symlink file was located
#done
#script_directory=$( cd -P "$( dirname "$source" )" >/dev/null 2>&1 && pwd )
#
script_directory=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
directory_name="$script_directory/../$year/day_$day"
cookie_session="$(< $script_directory/session_cookie.txt)"
url_request="https://adventofcode.com/$year/day/$day/input"
#echo -e "Debug info:\n\nArguments:\n year: $year\n day: $day\nLocal vars:\n script_directory: $script_directory\n directory_name: $directory_name\n URL: $url_request \ncookie_session: $cookie_session\n " #DEBUG

curl -k -s --head "$url_request" --cookie "session=$cookie_session" | head -n 1 | grep "HTTP/1.[01] [23].." > /dev/null
if [ "$?" -ne 0 ]; then
	echo "Page $url_request cannot be reached or doesn't exist."
	exit 2
fi

mkdir -p "$directory_name" # -p creates the 2023 folder too if it doesn't exist, but never gives errors

if [ -e "$directory_name/input.txt" ]; then
	curr_date=$(date +%s)
	mv "$directory_name/input.txt" "$directory_name/input_old_$curr_date.txt"
else
	cp "$script_directory/template_solution.cpp" "$directory_name/solution.cpp"
fi

#Use instead of curl during DEBUG so that the server doesn't get spammed with http requests
#echo "Curl to $directory_name/input.txt from $url_request with cookie $cookie_session" 
curl -o "$directory_name/input.txt" -k $url_request --cookie "session=$cookie_session"

exit $?