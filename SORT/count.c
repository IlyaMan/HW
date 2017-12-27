#include <stdio.h>
#include <limits.h>
#include <time.h>



unsigned long int * count(long int  *arr, long int  n){
        long int  *array = (long int *)malloc(INT_MAX * sizeof(long int ));
        long int  i;
        printf("%u ", n);
        long int  j;
        for (i = 0; i < n; i++) {
                array[arr[i]] += 1;
        }

}



int  main() {

        long int  n = 1000000;
        long int  arr[n];
        for (unsigned long int  i = 0; i < n; i++) {
                arr[i] = n - i;
        }
        clock_t start;
        clock_t stop;
        double tim;
        start = clock();
        count(arr, n);
        stop = clock();
        tim = ((double)(stop - start)) / CLOCKS_PER_SEC;
        printf("%f", tim);


        return 0;
}
