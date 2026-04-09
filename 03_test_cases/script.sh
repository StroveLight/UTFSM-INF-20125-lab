#!/bin/bash
for INPUTFILEPATH in ./input/*.txt;
do
    FILENAME=$(basename $INPUTFILEPATH);
    echo "running $FILENAME";
    ./main < "$INPUTFILEPATH" > "./output/$FILENAME";
done
