
#include <stdio.h>
#include <omp.h>

int main()
{
    int a = 10, b = 20, c = 15;
    int largest, smallest;
    double t1, t2;

    // Serial
    t1 = omp_get_wtime();

    largest = a;
    if (b > largest) largest = b;
    if (c > largest) largest = c;

    smallest = a;
    if (b < smallest) smallest = b;
    if (c < smallest) smallest = c;

    t2 = omp_get_wtime();

    printf("Serial\n");
    printf("Largest = %d\n", largest);
    printf("Smallest = %d\n", smallest);
    printf("Time = %f\n\n", t2 - t1);

    // Parallel
    t1 = omp_get_wtime();

    #pragma omp parallel
    {
        #pragma omp single
        {
            largest = a;
            if (b > largest) largest = b;
            if (c > largest) largest = c;

            smallest = a;
            if (b < smallest) smallest = b;
            if (c < smallest) smallest = c;
        }
    }

    t2 = omp_get_wtime();

    printf("Parallel\n");
    printf("Largest = %d\n", largest);
    printf("Smallest = %d\n", smallest);
    printf("Time = %f\n", t2 - t1);

    return 0;
}
