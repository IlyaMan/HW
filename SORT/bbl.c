#include <stdio.h>
#include <limits.h>
#include <time.h>

void bbl(unsigned long int *arr, long int n) {
        unsigned long int i;
        unsigned long int j;
        unsigned long int tmp;

        for (i = 0; i < n; i++) {
                for (j = 1; j < n; j++) {
                        if (arr[j] < arr[j - 1]) {
                                tmp = arr[j];
                                arr[j] = arr[j - 1];
                                arr[j - 1] = tmp;
                        }
                }
        }
}


unsigned long int main() {
        unsigned long long int n = 1000000;
        unsigned long int arr[n];
        for (unsigned long int i = 0; i < n; i++) {
                arr[i] = n - i;
        }
        clock_t start;
        clock_t stop;
        double tim;
        start = clock();
        bbl(arr, n);
        stop = clock();
        tim = ((double)(stop - start)) / CLOCKS_PER_SEC;
        printf("%f", tim);

        return 0;
}
