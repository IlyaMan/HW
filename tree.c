#include <string.h>
#include <stdio.h>
#include <stdlib.h>


struct node {
        int val;
        int freq;
        int x;
        int l;
        int r;
};

void structNaiveSort(struct node *arr, int n){
        struct node tmp;
        for (int i = 0; i < n - 1; i++) {
                for ( int j = 0; j < n - 1; j++) {
                        if (arr[j].val < arr[j+1].val) {
                                tmp = arr[j];
                                arr[j] = arr[j+1];
                                arr[j+1] = tmp;
                        }
                }
        }
}

void findix(struct node arr[], int n){
        for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = 0; j < i; j++) {
                        sum += arr[j].freq;
                }
                arr[i].x = sum;
                sum = 0;
        }
}

int findRoot(struct node arr[], int l, int r){
        if (r == l) {
                return r;
        }
        int min = l;
        int valmin = abs(arr[l + 1].x - arr[l].x - arr[r].x);
        int tmp;
        printf("SATRVAl: %d STARTMP: %d\n", arr[min].val, valmin);
        for (int i = l; i <= r; i++) {
                int left, right;
                if (i == l) {
                        left = 0;
                }
                else {
                        left = arr[i-1].x;
                }

                if (i == r) {
                        right = arr[i].x;
                }
                else {
                        right = arr[i+1].x;
                }
                tmp = abs(left + right - arr[l].x - arr[r].x);
                printf("VAl: %d TMP: %d\n", arr[i].val, tmp);
                if (tmp < valmin) {
                        min = i;
                        valmin = tmp;
                }

        }
        return min;

}


void buildTree(struct node arr[], int n){
  int root = findRoot(arr, 0, n-1);
  arr 
}

int main(void){
        FILE *fp;
        fp = fopen("f.txt", "r");
        int n;
        fscanf(fp, "%d", &n);
        struct node arr[n];
        for (int i = 0; i < n; i++) {
                fscanf(fp, "%d - %d", &arr[i].val, &arr[i].freq);
        }
        structNaiveSort(arr, n);
        findix(arr, n);
        for (int i = 0; i < n; i++) {
                printf("val: %d, freq: %d, x: %d\n", arr[i].val, arr[i].freq, arr[i].x);
        }
        printf("%d", arr[findRoot(arr, 0, 2)].val);
        return 0;
}
