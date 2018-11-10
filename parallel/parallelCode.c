#include <stdio.h>
#include <math.h>
#include <omp.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
        //declare all int values
        int length_of_array = strtol(argv[1], NULL, 10);
        int i;

        //declaration of clocks
        double init_start, init_end, sum_start, sum_end, coef_start, coef_end, start, end;

        //declare all doubles
        double *a, *b;
        double sum_of_a, sum_of_b, mean_of_a, mean_of_b, sum_of_sqrd_a_a_bar, sum_of_sqrd_b_b_bar , sum_of_a_times_b, correlationCoefficient, time_to_run;

        //allocate memory to the arrays
        a = (double *) malloc(length_of_array * sizeof(a));
        b = (double *) malloc(length_of_array * sizeof(b));
        start =omp_get_wtime();
        init_start= omp_get_wtime();
        #pragma omp parallel for default(none) private(i) shared(length_of_array, a, b)
        //initialisation of the value arrays
        for (i = 0; i < length_of_array; i++){
                a[i] = sin(i);
                b[i] = sin(i+5);
        }
        init_end = omp_get_wtime();

        sum_start = omp_get_wtime();
        #pragma omp parallel for default(none) private(i) shared(length_of_array, a, b) reduction(+:sum_of_a, sum_of_b) 
        for (i = 0; i < length_of_array; i++){
                sum_of_a += a[i];
                sum_of_b += b[i];
        }
        sum_end = omp_get_wtime();

        //work out the mean
        mean_of_a = sum_of_a / length_of_array;
        mean_of_b = sum_of_b / length_of_array;

        printf("print the mean of a = %.10f \n",mean_of_a);
        printf("print the mean of b = %.10f \n",mean_of_b);

        //perform work out coefficients
        coef_start = omp_get_wtime();
        #pragma omp parallel for default(none) shared(length_of_array, a, mean_of_a, b, mean_of_b) private(i) reduction(+:sum_of_sqrd_a_a_bar, sum_of_sqrd_b_b_bar, sum_of_a_times_b)
        for (i = 0; i < length_of_array; i++){
                sum_of_sqrd_a_a_bar += (a[i] - mean_of_a) * (a[i] - mean_of_a); //Why square them myself instead of using a function like pow
                sum_of_sqrd_b_b_bar += (b[i] - mean_of_b) * (b[i] - mean_of_b);
                sum_of_a_times_b += (a[i] - mean_of_a) * (b[i] - mean_of_b);
        }
        coef_end = omp_get_wtime();

        correlationCoefficient = sum_of_a_times_b / sqrt((sum_of_sqrd_a_a_bar * sum_of_sqrd_b_b_bar));

        end = omp_get_wtime();

        time_to_run = (end - start);
        printf("The time to initialise arrays was %.5f ms \n", ((init_end-init_start) *1000));
        printf("The time to work out the sum is: %.5f ms \n", ((sum_end-sum_start) *1000));
        printf("The time to work out coefficient was %.5f ms \n", ((coef_end-coef_start)*1000));
        printf("The time taken to execute the whole program = %.5f ms \n", (time_to_run*1000));
        printf("The Pearson correlation coefficient is: %.4f \n", correlationCoefficient);

        return 0;
}