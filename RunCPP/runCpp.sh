#!/bin/bash

# Compile CPP File
g++ $1 -o ./RunCPP/test.out -std=c++11
# Execute it.
./RunCPP/test.out < ./RunCPP/input.txt > ./RunCpp/output.txt
python3 ./RunCPP/checkCorrectOutput.py