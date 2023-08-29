#include <stdio.h>

#define int long long

signed main () {
    int N, temp = 0, d1, d2, d3, d4;
    scanf("%lld", &N);
    scanf("%lld %lld %lld %lld", &d1, &d2, &d3, &d4);
    int mask[5];
    mask[1] = ((int)1 << 32) - 1 - ((1 << 24)-1);
    mask[2] = (1 << 24) - 1 - ((1 << 16)-1);
    mask[3] = (1 << 16) - 1 - ((1 << 8 )-1);
    mask[4] = (1 << 8 ) - 1;
    temp += (((N & mask[d1]) >> ((4-d1)*8)) ^ ((N & mask[d2]) >> ((4-d2)*8))) << 24;
    //printf("%x\n", temp);
    temp += (((N & mask[d2]) >> ((4-d2)*8)) & ((N & mask[d3]) >> ((4-d3)*8))) << 16;
    //printf("%x\n", temp);
    temp += (((N & mask[d3]) >> ((4-d3)*8)) | ((N & mask[d1]) >> ((4-d1)*8))) << 8;
    //printf("%x\n", temp);
    temp += (~(((N & mask[d4]) >> ((4-d4)*8)))) & mask[4];
    //printf("%x\n", temp);
    temp = (((1<<(d1+d2+d3+d4))-1 & temp) << 32-(d1+d2+d3+d4)) | (temp >> (d1+d2+d3+d4));
    //printf("%x\n", temp);
    printf("%lld\n", (((mask[1]+mask[2]) & temp) >> 16) ^ ((mask[3]+mask[4]) & temp));
    return 0;
}
