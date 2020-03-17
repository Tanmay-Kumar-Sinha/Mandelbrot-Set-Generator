#!/bin/bash


`g++ buddhabrot.cpp`
echo "Generating matrix(may take upto a minute, depending on the resolution)"
`./a.out > data.dat`
echo "Creating the image"
`python3 imager.py`
`rm data.dat`
`rm a.out`
