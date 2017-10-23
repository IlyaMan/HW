#include <stdio.h>
#include <stdlib.h>

int strlen(char *s) {
        int i = 0;
        while (s[i]) {
                i++;
        }
        return i;
}

void strcopy(char *dst, char *src) {
        dst = (char *) calloc(strlen(src), sizeof(char));
        int i = 0;
        while (src[i]) {
                dst[i] = src[i];
                i++;
        }
        printf(dst);
}

void strcat(char *dst, char *src) {
        int L = strlen(dst);
        int l = strlen(src);
        char * middle = (char*) malloc(sizeof(char) * (l + L));
        int i = 0;
        while (i <= L) {
                middle[i] = dst[i];
                i++;
        }
        i = 0;
        while (i <= l) {
                middle[L + i] = src[i];
                i++;
        }
        dst = middle;
        printf(dst);
}

int strcmp(char* s1, char* s2){
        int i = 0;
        while(s1[i] or s2[i]) {
                if (s1[i] == s2[i]) {
                        if (s1[i+1] or s2[i+1]) {
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
