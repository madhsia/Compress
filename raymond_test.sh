#!/bin/bash

COM="./compress"
UNC="./uncompress"
DIR="./input_files"

COM_F="./raymond_is_handsome_compressed"
UNC_F="./raymond_is_handsome_uncompressed"

if [ ! -x $COM ] || [ ! -x $UNC ]
then
    echo "No compress file or uncompress file in the current directory!"
    exit 1
fi

if [ ! -d $DIR ]
then
    echo "No input files for test"
    exit 2
fi

FAILED_TEST=0

for input in `ls $DIR`
do
    echo "########################################"
    echo "Starting test for $input..."

    $COM $DIR/$input $COM_F &> /dev/null
    $UNC $COM_F $UNC_F &> /dev/null

    result=$(diff $DIR/$input $UNC_F)

    if [ $? -eq 0 ]
    then
        echo $input passed.
    else
        echo $input failed.
        FAILED_TEST=`expr $FAILED_TEST + 1`       
    fi

    rm -rf $COM_F
    rm -rf $UNC_F
done

if [ $FAILED_TEST -eq 0 ]
then
    echo "########################################"
    echo "ACCURACY TESTS on files in input_files have PASSED."
    echo "Please do more self tests on more extensions."
    echo "For example, JPEG, mp3, and etc."
    echo "Hope you guys all get an A!!!"
    echo "^v^"
    echo "Best,"
    echo "Raymond"
fi

exit
