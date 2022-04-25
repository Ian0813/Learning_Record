#! /bin/bash 

for i in $(find ./ -type f -name "*.c" && find ./ -type f -name "*.h" );
do 
    echo $i >> file_list.txt;
done

