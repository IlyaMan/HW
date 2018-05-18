#include <stdio.h>
#include <stdlib.h>

int main(void) {
        int i;
        char str[256];
        char sign[1];

        scanf("%s ", str);
        scanf("%c", sign);

        for (i = 0; str[i] != 0; i++) {
                if (str[i] != sign[0]) {
                        printf("%c", str[i]);
                }
        }

        return 0;
}
