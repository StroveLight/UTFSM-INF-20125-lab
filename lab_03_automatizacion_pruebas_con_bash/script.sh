#!/bin/bash
MOD=26
for ((i=1; i<=$1; i++)); do
    FILENAME="input/test$i.txt";
    echo "$(($i*100))" > $FILENAME
    for ((j=1; j<=$i*100; j++)); do
        echo "$(( RANDOM % $MOD )) $(( RANDOM % $MOD )) $(( RANDOM % $MOD ))" >> $FILENAME
    done
done
