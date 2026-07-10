#include <stdio.h>
#include <omp.h>

int x;
#pragma omp threadprivate(x)

int main()
{
    int a = 10, i;

    // Shared
    #pragma omp parallel shared(a)
    printf("Shared = %d\n", a);

    // Private
    #pragma omp parallel private(a)
    {
        a = 20;
        printf("Private = %d\n", a);
    }

    // Firstprivate
    #pragma omp parallel firstprivate(a)
    printf("Firstprivate = %d\n", a);

    // Lastprivate
    #pragma omp parallel for lastprivate(i)
    for(i = 0; i < 4; i++)
    {
    }
    printf("Lastprivate = %d\n", i);

    // Threadprivate
    #pragma omp parallel
    {
        x = omp_get_thread_num();
        printf("Threadprivate = %d\n", x);
    }

    return 0;
}
