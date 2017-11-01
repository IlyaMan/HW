#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {

        char first[256];
        char second[256];
        int i;

        scanf("%s", first);
        scanf(" %s", second);

        if (strlen(first) > strlen(second)) {
                printf("Первое!\n");
                return 0;
        }
        if (strlen(first) < strlen(second)) {
                printf("Второе!\n");
                return 0;
        }

        i =  strlen(first) - 1;

        while ((first[i]) | (second[i])) {
                if ((i == 0) & (first[i]) == (second[i])) {
                        printf("Равны!");
                        return 0;
                }
                if ((first[i]) & (second[i])) {
                        if ((first[i]) > (second[i])) {
                                printf("Первое!\n");
                                break;
                        }
                        if ((first[i]) < (second[i])) {
                                printf("Второе!\n" );
                                break;
                        }
                }
                if (((first[i]) & (!(second[i])))) {
                        printf("Первое!\n");
                        break;
                }
                if ((!(first[i]) & ((second[i])))) {
                        printf("Второе!\n");
                        break;
                }
                i--;
        }

        return 0;
}
