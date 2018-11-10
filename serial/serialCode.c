#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

double get_wall_time();


int main(int argc, char **argv)
{
        //declare all int values
        int length_of_array = strtol(argv[1], NULL, 10);
        int i;

        //declaration of clocks
        double start, end;

        //declare all doubles
        double *a, *b;
        double sum_of_a, sum_of_b, mean_of_a, mean_of_b, sum_of_sqrd_a_a_bar, sum_of_sqrd_b_b_bar , sum_of_a_times_b, correlationCoefficient, time_to_run;

        //allocate all memory to the arrays
        a = (double *) malloc(length_of_array * sizeof(a));
        b = (double *) malloc(length_of_array * sizeof(b));

        start = get_wall_time();
        //initialisation of the value arrays
        for (i = 0; i < length_of_array; i++){
                a[i] = sin(i);
                b[i] = sin(i+5);
        }

        //sum up arrays
        for (i = 0; i < length_of_array; i++){
                sum_of_a += a[i];
                sum_of_b += b[i];
        }

        //work out the mean
        mean_of_a = sum_of_a / length_of_array;
        mean_of_b = sum_of_b / length_of_array;

        printf("print the mean of a = %.10f \n",mean_of_a);
        printf("print the mean of b = %.10f \n",mean_of_b);

        //perform work out coefficients

        for (i = 0; i < length_of_array; i++){
                sum_of_sqrd_a_a_bar += (a[i] - mean_of_a) * (a[i] - mean_of_a); //Why square them myself instead of using a function like pow
                sum_of_sqrd_b_b_bar += (b[i] - mean_of_b) * (b[i] - mean_of_b);
                sum_of_a_times_b += (a[i] - mean_of_a) * (b[i] - mean_of_b);
        }
        correlationCoefficient = sum_of_a_times_b / sqrt((sum_of_sqrd_a_a_bar * sum_of_sqrd_b_b_bar));

        end = get_wall_time();

        time_to_run = (end - start);
        printf("The time taken to execute the whole program = %.5f ms \n", (time_to_run*1000));
        printf("The Pearson correlation coefficient is: %.4f \n", correlationCoefficient);

        return 0;
}

double get_wall_time(){
        struct timeval time;
        if(gettimeofday(&time, NULL)){
                return 0;
        }
        return (double)time.tv_sec + (double)time.tv_usec * .000001;
}