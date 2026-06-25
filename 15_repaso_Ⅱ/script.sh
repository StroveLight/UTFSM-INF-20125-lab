#!/bin/bash
MOD=100
RANDOM="${1:-20125}"
FILENAME="input.txt";
echo "10" > $FILENAME;
for ((i=0; i<10; i++)); do
    echo "$(( RANDOM % $MOD )) $(( RANDOM % $MOD )) $(( RANDOM % $MOD ))" >> $FILENAME
done
