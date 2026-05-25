#!/bin/bash

filesdir=$1
searchstr=$2

if [ -z "$filesdir" ] || [ -z "$searchstr" ]; then
	echo "Parameters are not set correctly"
	exit 1
fi

if [[ -d  "$filesdir" ]]; then
	echo "directory is valid"
else
	echo "directory is not valid $filesdir";
	exit 1
fi

echo "the number of files are $(find "$filesdir" -type f | wc -l) and the number of matching lines are $(grep -rl $searchstr $filesdir | wc -l)"

