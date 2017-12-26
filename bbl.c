#include <stdio.h>
#include <limits.h>

void bbl(unsigned int *arr, int n) {
        unsigned int i;
        unsigned int j;
        unsigned int tmp;

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


unsigned int main() {
        unsigned int n = 100000;
        unsigned int arr[n];
        for (unsigned int i = 0; i < n; i++) {
                arr[i] = n - i;
        }

        bbl(arr, n);

        for (unsigned int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
        }

        return 0;
}
