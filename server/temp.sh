#!/bin/sh -f

g++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) vcd_core.cpp -o vcd_cpp$(python3-config --extension-suffix)
