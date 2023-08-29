#include<stdio.h>

int main () {
    int n;
    int ips[4];
    scanf("%x", &n);
    for (int i = 3; i >= 0; i--) {
        ips[i] = n & 255;
        n >>= 8;
    }
    for (int i = 0; i < 4; i++) printf("%d%c", ips[i], (i == 3) ? '\n' : '.');
    return 0;
}
