usage(){
        echo $0 ./parallelCode.exe numThreads numRepeats arrayLength 
}

if [[ $# -ne 3 ]]; then
        usage
        exit -1
fi

EXE=parallelCode.exe
THREADS=$1
REPEATS=$2
ARRAY_LENGTH=$3
FILE=parallel${ARRAY_LENGTH}on${THREADS}by${REPEATS}.txt

echo best of $REPEATS for executable $EXE

        export OMP_NUM_THREADS=$THREADS
        echo running ${EXE} with an array length of ${ARRAY_LENGTH}
        echo running on $OMP_NUM_THREADS threads
        for k in `seq 1 $REPEATS`; do
                ./${EXE} ${ARRAY_LENGTH}
        done  > $FILE

echo Finished