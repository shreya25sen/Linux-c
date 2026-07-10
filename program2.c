#include <stdio.h>
#include <omp.h>

int main()
{
    int id;

    #pragma omp parallel private(id)
    {
        id = omp_get_thread_num();

        printf("Hello World from Thread %d\n", id);
        printf("Number of Threads: %d\n", omp_get_num_threads());
        printf("Number of Processors: %d\n", omp_get_num_procs());
        printf("Maximum Threads: %d\n\n", omp_get_max_threads());
    }

    return 0;
}
