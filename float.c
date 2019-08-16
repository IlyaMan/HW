#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct {
        int sign;
        float fract;
        int exp;
} Decoded;

typedef Decoded (*function) (float, float);

typedef struct {
        char *text;
        function f;
} Way;


union {
        float fl;
        int i;
} flint;

union {
        float fl;
        struct {
                unsigned int fract : 23;
                unsigned int exp : 8;
                unsigned int sign : 1;
        } structure;
} frustruct;

float fractIt(int c){
        float s = 1;
        double t = 1;
        int i;
        for (i = 1; i <= 23; i++) {
                t = t/2;
                s += ((c>>(23-i))&1) * t;
        }
        return s;
}

void Krasivo(Decoded c){
  if ((c.fract == 0) && (c.exp == 0)){
    printf("0");
    return;
  }
  if ((c.fract != 0) && (c.exp == 255)){
    printf("Nan");
    return;
  }
  if ((c.fract == 0) && (c.exp == 255) && (c.sign == 0)){
    printf("+Inf");
    return;
  }
  if ((c.fract == 0) && (c.exp == 255) && (c.sign == 1)){
    printf("+Inf");
    return;
  }
        printf("(-1)^%d x %f x 2^(%d)\n", c.sign, c.fract, c.exp);
}


Decoded unionInt(float a, float b){
        flint.fl = a/b;
        Decoded c;
        c.sign = (flint.i>>31)&1;
        c.fract = fractIt(8388607 & flint.i);
        c.exp = ((255) & (flint.i>>23)) - 127;
        return c;
}

Decoded unionStruct(float a, float b){
        Decoded c;
        frustruct.fl = a/b;
        c.fract = fractIt(frustruct.structure.fract);
        c.exp = frustruct.structure.exp - 127;
        c.sign = frustruct.structure.sign;
        return c;
}

Decoded pointer(float a, float b){
        Decoded c;
        float g = a/b;
        int ptr = *(int *) (float *) &g;
        c.sign = (ptr>>31)&1;
        c.fract = fractIt(8388607 & (ptr));
        c.exp = ((255) & (ptr>>23)) - 127;
        return c;
}



int main(void){
        float a, b;
        Way A = {.text = "union с int и битовые операции", .f = unionInt};
        Way B = {.text = "union со структурой с bit fields", .f = unionInt};
        Way C = {.text = "взятие адреса и разыменование указателя, приведенного к другому типу и битовые операции", .f = *unionInt};

        Way ways[] = {A, B, C};
        printf("Give me a float\n");
        scanf("%f", &a);
        printf("Give me one more\n");
        scanf("%f", &b);

        int tmp;

        for (int i = 0; i < sizeof(ways)/sizeof(Way); i++) {
                printf("%s\n нажмите %d\n", ways[i].text, i);
        }
        scanf("%d", &tmp);

        function ptrF = ways[0].f;

        if (tmp == 0) {
                function ptrF = ways[0].f;
        }
        else{
                if (tmp == 1) {
                        function ptrF = ways[1].f;
                }
                else{
                  if (tmp == 2){
                    function ptrF = ways[2].f;
                  }
                }
        }



        Krasivo(ptrF(a, b));
        return 0;
}
