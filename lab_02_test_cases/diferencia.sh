#!/bin/bash
for INPUTFILEPATH in ./output/*.txt;
do
    FILENAME=$(basename $INPUTFILEPATH);
	if [ $(diff -rq "$INPUTFILEPATH" "./solution/$FILENAME" | wc -m) -ne 0 ];
    then
        echo "$FILENAME";
    fi
done
