#!/bin/bash

# Compile the C++ source file
g++ -o compute src/compute.cpp

# Check if the compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
else
    echo "Compilation succeeded."
fi
