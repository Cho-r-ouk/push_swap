#!/bin/bash

max=0
echo "checker | moves | max_moves"
while true
do
    ARG=$(seq 1 100 | sort -R | tr '\n' ' ')
    num=$(./push_swap $ARG | wc -l)
    echo "      $num    $max"
    ./push_swap $ARG | ./checker_Mac $ARG
    if [ "$num" -gt "$max" ]; then
        max=$num
    fi
    sleep 0.05
done
