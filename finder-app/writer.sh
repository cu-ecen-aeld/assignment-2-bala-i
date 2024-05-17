#!/bin/bash

#script that accepts full path to a file "writefile" and text to be written "writestr", and writes to writefile
# creates new file if writefile does not exist, or overwrites its content

if [ $# -ne 2 ]; then
    echo "Error: invalid number of arguments. Two arguments required - writefile and writestr"
    exit 1
fi

writefile="$1"
writestr="$2"

dir=$(dirname "$writefile")

mkdir -p "$dir"

# create file with content, and check if operation successful
if [ $? -ne 0 ]; then
    echo "Error: Could not create file '$writefile'."
    exit 1
fi

echo "$writestr" > "$writefile"

if [ $? -ne 0 ]; then
    echo  "Error: Could not write to file $writefile."
	exit 1
fi

echo "Successfully wrote to $writefile"
exit 0
