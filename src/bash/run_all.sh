#!/bin/bash

for x in `ls ./Tests/$1`; do
    if [[ $x == *".c" ]]; then
        "make" "-s" "run" "FILE=$x";
    fi
done
