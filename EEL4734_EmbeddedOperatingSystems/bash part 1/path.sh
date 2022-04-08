#!/bin/bash
# add to the PATH enviroment variable, one or two directory paths using command line arguments

if [ $# -eq 0 ]; then
    echo "No paths were detected"

elif [ $# -eq 1 ]; then
       
    if [ -d $1 ]; then
    export PATH=$PATH:$1    
    echo "Successfully added the path"

    else
        echo "No directory was added"

    fi

elif [ $# -eq 2 ]; then
    if [ -d $1 ]; then
        export PATH=$PATH:$1
        echo "Successfully added the first Path"
    else
        echo "Path 1 was not added"
    fi

    if [ -d $2 ]; then
        export PATH=$PATH:$2
        echo "Successfully added the second path"
    else
        echo "Path 2 was not added"
    fi
elif [ $# -gt 2 ]; then
    echo "Too many paths included"
else
    echo "Error: Incorrect input"
fi

echo "Updated path:"
echo $PATH


exit 0
