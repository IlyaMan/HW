#include <stdio.h>
#include <limits.h>



unsigned long int * count(long int  *arr, long int  n){
        long int  *array = (long int *)malloc(long int _MAX * sizeof(long int ));
        long int  i;
        prlong int f("%u ", n);
        long int  j;
        for (i = 0; i < n; i++) {
                array[arr[i]] += 1;
        }
        for (i = 0; i < long int _MAX; i++) {
                if (array[i]) {
                        prlong int f("%u ", i);
                }
        }
}



long int  main() {

        long int  n = 1000000;
        long int  arr[n];
        for (unsigned long int  i = 0; i < n; i++) {
                arr[i] = n - i;
        }

        count(arr, n);



        return 0;
}
