#!/bin/bash
MOD=2345
i=10000
FILENAME="input.txt";
echo "$i" > $FILENAME
for ((j=1; j<=$i; j++)); do
    echo "$(( RANDOM % $MOD + 1))" >> $FILENAME
done
