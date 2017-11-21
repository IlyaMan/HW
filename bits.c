#include <stdio.h>

int bitAnd(int x, int y) {
        int Z = ~((~x) | (~y));
        return (Z);
}

int bitXor(int x, int y) {
        int Z = (~((x) & (y))) & (~((~x) & (~y)));
        return (Z);
}

int thirdBits(void) {
        const int c = 73;
        const int c1 = 9;
        int x = ((73 << 23) | (73 << 14)) | (73 << 5) | (1 << 2);
        return x;

}

int fitsBits(int x, int n) {
        n = (n + (~0));
        x = !(((x>>n)) ^ (x>>31));
        return x;
}
int sign(int x) {
        return (!(!x)) | (x>>31);
}
int getByte(int x, int n) {
        x = (x >> (n * 8)) & 255;
        return x;
}

int logicalShift(int x, int n) {
        return (x>>n) & (~(((1<<31)>>n)<<1));
}

int addOK(int x, int y) {
        int signx = ((x>>31)&1);
        int signy = ((y>>31)&1);
        int sum = (((x + y)>>31)&1);
        x = x ^ (2<<31);
        y = y ^ (2<<31);
        return !signy & !signx & !sum | (signx & signy & sum) | !(signx == signy);
}

int bang(int x){
        int ones = (((~x) + 1) | x) >> 31;
        return (~ones + 1) ^ 1;
}

int conditional(int x, int y, int z) {
        return (~(~(!x) + 1) & y) | ((~(!x) + 1)&z);
}

int isPower2(int x) {
        return !((x + (~0)) & x) & !(x>>31) & !(!x);


}

int main(void) {
        printf("%d", addOK(0, 0));
        return 0;
}
