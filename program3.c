#include <stdio.h>
#include <omp.h>

int main()
{
    int a = 10, b = 5;
    double start, end;

    start = omp_get_wtime();

    #pragma omp parallel sections
    {
        #pragma omp section
        printf("Addition = %d\n", a + b);

        #pragma omp section
        printf("Subtraction = %d\n", a - b);

        #pragma omp section
        printf("Multiplication = %d\n", a * b);

        #pragma omp section
        printf("Division = %d\n", a / b);
    }

    end = omp_get_wtime();

    printf("Time = %f\n", end - start);

    return 0;
}
