#!/bin/bash

g++ -DLOCAL -g -o main main.cpp
success=$?
if [ $success -eq 0 ]; then
    echo "Start of Program"
    echo
    ./main < input.txt > output.txt
    echo
    echo "End of Program"
fi

# rm -rf main