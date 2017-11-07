#include <stdio.h>
#include <limits.h>



unsigned int* count(int *arr, int n){
        int *array = (int*)malloc(INT_MAX * sizeof(int));
        int i;
        printf("%u ", n);
        int j;
        for (i = 0; i < n; i++) {
                array[arr[i]] += 1;
        }
        for (i = 0; i < INT_MAX; i++) {
                if (array[i]) {
                        printf("%u ", i);
                }
        }
}



int main() {

        int n = 1000000;
        int arr[n];
        for (unsigned int i = 0; i < n; i++) {
                arr[i] = n - i;
        }

        count(arr, n);



        return 0;
}
