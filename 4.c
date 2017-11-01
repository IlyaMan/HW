#include <stdio.h>
#include <stdlib.h>

int main(void) {

        int i = 0;
        unsigned first_sum = 0;
        unsigned second_sum = 0;

        for ( i = 0; i < 101; i++) {
                first_sum += i * i;
                second_sum += i;
        }
        second_sum *= second_sum;

        printf("%u", second_sum - first_sum);

        return 0;

}
