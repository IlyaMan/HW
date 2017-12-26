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
        printf("finding root between %d AND %d\n", l, r);
        if (r == l) {
                return r;
        }
        int min = l;
        int valmin = abs(arr[l + 1].x - arr[l].x - arr[r].x);
        int tmp;
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
                if (tmp < valmin) {
                        min = i;
                        valmin = tmp;
                }
        }
        printf("root is %d = %d\n", min, arr[min].val);
        if (min > l){
          printf("%d GOING LEFT\n", arr[min].val);
          arr[min].l = findRoot(arr, l, min - 1);
          printf("%d L> %d\n", arr[min].val, arr[arr[min].l].val );
        }
        if (min < r){
          printf("%d GOING RIGHT\n", arr[min].val);
          arr[min].r = findRoot(arr, min + 1, r);
          printf("%d R> %d\n", arr[min].val, arr[arr[min].r].val );

        }
        return min;

}



void graviz(struct node arr[], int n){
        FILE *fp;
        fp = fopen("fo.txt", "w");
        if (!fp){
          printf("red alert");
          exit(111);
        }
        fprintf(fp, "%s", "digraph {\n");
        for (int i = 0; i < n; i++) {
                if ((arr[i].l < n)) {
                        fprintf(fp, "\"%d\\n%d\" -> \"%d\\n%d\";\n", arr[i].val, arr[i].freq, arr[arr[i].l].val, arr[arr[i].l].freq);
                }
                if ((arr[i].r < n)) {
                        fprintf(fp, "\"%d\\n%d\" -> \"%d\\n%d\";\n", arr[i].val, arr[i].freq, arr[arr[i].r].val, arr[arr[i].r].freq);
                }
        }
        fprintf(fp, "%s", "}");

}


int main(void){
        FILE *fp;
        fp = fopen("f.txt", "r");
        if (!fp){
          printf("red alert");
          exit(111);
        }
        int n;
        fscanf(fp, "%d", &n);
        struct node arr[n];
        for (int i = 0; i < n; i++) {
                fscanf(fp, "%d - %d", &arr[i].val, &arr[i].freq);
                arr[i].l = n + 10;
                arr[i].r = n + 10;
        }
        structNaiveSort(arr, n);
        findix(arr, n);
        printf("%d\n", arr[findRoot(arr, 0, n - 1)].val);
        graviz(arr, n);
        return 0;
}
