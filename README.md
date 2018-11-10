<h1>OpenMP - Pearson Correlation Coefficient</h1>

<h1>Running Code</h1>

<h2>Loading the modules</h2>
Ensure that the intel module has been loaded so that you are able to compile the serial files.

`module load intel`

<h2>Compiling The Code</h2>
<h3>Serial Code</h3>
in order to compile the code run the following command:

`icc -openmp -0O ./serialCode.c -o ./serialCode.exe`

to run the code enter:

`./serialCode.exe <length-of-desired-array>`

<h3>Parallel Code</h3>
To compile the parallel code run the following:

`icc -openmp -O0 ./parallelCode.c -o ./parallelCode.exe`

To run the parallel code a shell script has been created which allows a user to enter the number of threads that they would like to use, the number of times the would like to run the parallelCode and the length of the array that they would like to use within the code. [See here](../blob/master/parallel/runParallel.sh)

to run the code using the shell script then enter the following command:
`qrsh -l h_rt=00:05:00 -cwd -V -pe smp 16 -l exclusive=true ./runParallel.sh 4 10 200000`
 <b>The last 3 arguments in the command are customisable in this example the script will run on 4 threads, 10 times with an array length of 2 million.</b>

<u>Argument breakdown</u>
- $1: The number of threads that you would like the program to run on. 
- $2: The number of times that you would like the code to run.
- $3: The length of the array that you would like the code to use.
 