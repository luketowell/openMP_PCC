usage(){
        echo $0 ./parallelCode.exe numRepeats arrayLength 
}

if [[ $# -ne 2 ]]; then
        usage
        exit -1
fi

EXE=serialCode.exe
REPEATS=$1
ARRAY_LENGTH=$2
FILE=serial${ARRAY_LENGTH}x${REPEATS}.txt

echo best of $REPEATS for executable $EXE

        echo running ${EXE} with an array length of ${ARRAY_LENGTH}
        for k in `seq 1 $REPEATS`; do
                ./${EXE} ${ARRAY_LENGTH}
        done  > $FILE

echo Finished
