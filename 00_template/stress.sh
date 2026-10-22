#!/bin/bash
# Stress test: ./stress.sh  (necesita sol.cpp, brute.cpp, gen.cpp en la carpeta)
# gen.cpp recibe la semilla como argv[1] y escribe un caso a stdout.
set -e
g++ -std=c++17 -O2 -o sol sol.cpp
g++ -std=c++17 -O2 -o brute brute.cpp
g++ -std=c++17 -O2 -o gen gen.cpp
for ((i = 1; ; i++)); do
    ./gen $i > in.txt
    ./sol < in.txt > out_sol.txt
    ./brute < in.txt > out_brute.txt
    if ! cmp -s out_sol.txt out_brute.txt; then
        echo "DIFERENCIA en caso $i (ver in.txt)"
        exit 1
    fi
    echo "OK $i"
done
