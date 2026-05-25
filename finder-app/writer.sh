#!/bin/bash

writefile=$1
writestr=$2

if [ -z "$writefile" ] || [ -z "$writestr" ]; then
	echo "Parameters are not specified correctly"
	exit 1
fi

dir_path=$(dirname "$writefile")
if [[ ! -d "$dir_path" ]]; then
	mkdir -p "$dir_path"
fi

echo "$writestr" > "$writefile"
