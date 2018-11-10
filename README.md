<h1>OpenMP - Pearson Correlation Coefficient</h1>

<h1>Running Code</h1>

<h2>Loading the modules</h2>
Ensure that the intel module has been loaded so that you are able to compile the serial files.

`module load intel`
_____
<h2>Executing The Code</h2>
<h3>Serial Code</h3>
in order to compile the code run the following command:

`icc -openmp -0O ./serialCode.c -o ./serialCode.exe`

to run the code enter:

`./serialCode.exe <length-of-desired-array>`

<h3>Serial Code Shell Script</h3>

In order to run the coode in exactly the same environment as the parallel code a shell script has been created - [see here](../master/serial/runSerial.sh)

the script takes two arguments which are described below:

<u>Argument breakdown</u>

<b>The last 2 arguments in the command are customisable in the example below the script will run on 10 times with an array length of 2 million.</b>
  
- $1: The number of times that you would like the code to run.
- $2: The length of the array that you would like the code to use.

<h4><u>Running the serial script</u></h4>
The command to run the script is: 

`qrsh -l h_rt=00:05:00 -cwd -V -pe smp 16 -l exclusive=true ./runSerial.sh 10 200000`
_______
<h3>Parallel Code</h3>
To compile the parallel code run the following:

`icc -openmp -O0 ./parallelCode.c -o ./parallelCode.exe`

To run the parallel code 2 shell scripts have been created which allows a user to enter the number of threads that they would like to use, the number of times the would like to run the parallelCode and the length of the array that they would like to use within the code. Once the shell scripts have been run and the parallel code has been executed then the results are output to a text file.

The reason that two scripts have been created is to allow the user to see the results of running the code with and without thread binding enabled.

<u>Argument breakdown</u>

<b>The last 3 arguments in the command are customisable in the examples below the script will run on 4 threads, 10 times with an array length of 2 million.</b>
 
- $1: The number of threads that you would like the program to run on. 
- $2: The number of times that you would like the code to run.
- $3: The length of the array that you would like the code to use.

<h4><u>Run Parallel Code No Binding</u></h4>
Direct link to the shell script - [See here](../master/parallel/runParallel.sh)

to run the code using the shell script then enter the following command:

`qrsh -l h_rt=00:05:00 -cwd -V -pe smp 16 -l exclusive=true ./runParallel.sh 4 10 200000`

<h4><u>Run Parallel Code with Binding,/u></h4>
Direct link to the shell script - [See here](../master/parallel/runParallel-binding.sh)

to run the code using the shell script then enter the following command:

`qrsh -l h_rt=00:05:00 -cwd -V -pe smp 16 -l exclusive=true ./runParallel-binding.sh 4 10 200000`
