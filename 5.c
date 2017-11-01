#include <stdio.h>
#include <stdlib.h>

int main () {
        char The_String[256];
        FILE *f;
        int c;
        int i = 0;

        f = fopen("z.txt", "r");

        while (1) {
                c = fgetc(f);
                if (feof(f)) break;
                if (c != '\n') {
                        The_String[i] ^= c;
                        i++;
                }
                else {
                        i = 0;
                }
        }
        fclose(f);
        printf(The_String);
        return(0);
}
