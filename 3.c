#include <stdio.h>
#include <stdlib.h>

int main () {

        int flag = 0;
        int fflag = 0;
        FILE *f;
        int c;

        f = fopen("f.txt","r");

        while (1) {
                c = fgetc(f);

                if ( feof(f) ) break;

                if (flag) {
                        printf("%c", c);
                }
                if ((fflag == 1) & (c !='/')) {
                        fflag = 0;
                }

                if ((c == '/') & (fflag == 0)) {
                        fflag = 1;
                }
                else {
                        if ((c == '/') & (fflag == 1))  {
                                fflag = 0;
                                flag = 1;
                        }
                }

                if (c == '\n') {
                        flag = 0;
                }
        }

        fclose(f);
        return 0;
}
