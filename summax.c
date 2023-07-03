#include <stdio.h>
#include <omp.h>
//this is an example of parallel programmming.....
int main()
{
    int i, a[5] = {1, 2, 3, 4, 8};
    int sum = 0, max = 0;
    int nthreads;

    #pragma omp parallel for private(i) shared(sum, max)
    for (i = 0; i < 5; i++)
    {
        sum = sum + a[i];
        max = max > a[i] ? max : a[i];
    }

    nthreads = omp_get_num_threads();
    printf("Number of threads is: %d\n", nthreads);
    printf("sum is %d\n", sum);
    printf("Maximum in an array is %d\n", max);

    return 0;
}

