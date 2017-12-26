#include <stdio.h>
#include <stdlib.h>

int n = 1000000;


void mrg(int *arr, int *buffer, int left, int right ){

        if (left == right) {
                return;
        }

        int middle = (left + right) / 2;
        int width = right - left + 1;

        mrg(arr, buffer, left, middle);
        mrg(arr, buffer, middle + 1, right);

        int l = left;
        int r = middle + 1;
        int i = 0;

        while ((l <= middle) || (r <= right)) {

                if ( (l <= middle) && (r <= right) ) {
                        if (arr[r] < arr[l]) {
                                buffer[i] = arr[r];
                                i++;
                                r++;
                        }
                        else{
                                if (arr[r] >= arr[l]) {
                                        buffer[i] = arr[l];
                                        l++;
                                        i++;
                                }
                        }
                }
                else{
                        if (l <= middle) {
                                buffer[i] = arr[l];
                                l++;
                                i++;
                        }
                        else{
                                if (r <= right) {
                                        buffer[i] = arr[r];
                                        i++;
                                        r++;
                                }
                        }
                }
        }

        for (i = 0; i < width; i++) {
                arr[left + i] = buffer[i];
        }




}



int main(void) {
        int arr[n];
        int buffer[n];

        for (int i = 0; i < n; i++) {
                arr[i] = n - i;
        }

        mrg(arr, buffer, 0, n - 1);

        for (int i = 0; i < n; i++) {
                printf("%u ", arr[i]);
        }
        return 0;
}
