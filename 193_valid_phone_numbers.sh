#! /bin/bash

CURR_PATH=$(cd $(dirname $0) && pwd)
TEMP_FILE=$(mktemp)
TEMP_STR=""

grep "." ${CURR_PATH}/file.txt | while read -e DATA;
do
	HYPHEN_COUNT=$(echo $DATA | grep -o '-' | wc -l) 

	if [ $HYPHEN_COUNT -eq 1 ]; 
    then
        TEMP_STR=$(echo "$DATA" | sed -nE "s/\([0-9]{3}\) [0-9]{3}-[0-9]{4}/match/pg")
		if [  "match" = "$TEMP_STR" ];
		then 
            echo $DATA
        fi
    elif [ $HYPHEN_COUNT -eq 2 ];
    then
		TEMP_STR=$(echo "$DATA" | sed -nE "s/[0-9]{3}-[0-9]{3}-[0-9]{4}/match/pg")
		if [  "match" = "$TEMP_STR" ];
		then 
            echo $DATA
        fi
    fi
done
cat $TEMP_FILE
rm $TEMP_FILE
