#include <stdio.h>
#include <limits.h>

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

        bbl(arr, n);

        for (unsigned long int i = 0; i < n; i++) {
                printf("%llu ", arr[i]);
        }

        return 0;
}
