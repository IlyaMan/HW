#include <stdio.h>
#include <stdlib.h>

int strlen(char *s) {
        int i = 0;
        while (s[i]) {
                i++;
        }
        return i;
}

void strcpy(char *dst, char *src) {
        int i = 0;
        while ((src[i])) {
                dst[i] = src[i];
                i++;
        }
        printf("\n%s", dst);
}

void strcat(char *dst, char *src) {
        int L = strlen(dst);
        int i = 0;
        while(src[i]) {
          dst[L + i] = src[i];
          i++;
        }
        dst[L + i] = 0;
        printf(dst);
}



int strcmp(char* s1, char* s2){
        int i = 0;
        while((s1[i]) || (s2[i])) {
                if (s1[i] == s2[i]) {
                        if ((s1[i+1]) || (s2[i+1])) {
                                i++;
                                continue;
                        }
                        else{
                                return 0;
                        }
                }
                if (s1[i] > s2[i]) {
                        return 1;
                }
                else{
                        return -1;
                }
        }
}


int main(void) {
        return 0;
}
