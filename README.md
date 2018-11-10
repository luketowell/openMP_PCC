<h1>OpenMP - Pearson Correlation Coefficient</h1>

<h1>Running Code</h1>

<h2>Loading the modules</h2>
Ensure that the intel module has been loaded so that you are able to compile the serial files.

`module load intel`

<h2>Compiling The Code</h2>

in order to compile the code run the following command:

`icc -openmp -0O ./serialCode.c -o ./serialCode.exe`

to run the code enter:

`./serialCode.exe <length-of-desired-array>`


