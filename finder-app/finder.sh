#!/bin/bash
# A script that accepts runtime args 'filesdir' and 'searchstr', and searches the number of files X and number of>
# subdirectories, and Y is the number of matching lines found in respective files.

if [ $# != 2 ]; then
    echo "Error: Invalid number of arguments."
    exit 1
elif [ ! -d $1 ]; then
    echo "File does not exist or is not a valid directory"
    exit 1
else
    filesdir=$1
    searchstr=$2

    num_files=$(find "$filesdir" -type f | wc -l)
    matching_lines=$(grep -r "$searchstr" "$filesdir" 2>/dev/null | wc -l)

    echo "The number of files are $num_files and the number of matching lines are $matching_lines"
    exit 0
fi

