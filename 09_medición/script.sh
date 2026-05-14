#!/bin/bash
n=500000
m=30
FILENAME="test.txt";
for ((i=1; i<=$n; i++)); do
    echo "$(( RANDOM % $m ))" >> $FILENAME
done
