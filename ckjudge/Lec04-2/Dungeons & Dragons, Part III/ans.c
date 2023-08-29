#include<stdio.h>

#define int unsigned long long

signed main () {
    int n1 = 4099276460824344576;
    int n2 = 3074457345618258602;
    int n3 = 2049638230412172401;
    int mod = 9000000000000000000;
    n1 %= mod, n2 %= mod, n3 %= mod;
    int d1, d2, d3;
    scanf("%llu %llu %llu", &d1, &d2, &d3);
    int ans = (n1 * d1) % mod;
    ans = (ans + (n2 * d2) % mod) % mod;
    ans = (ans + (n3 * d3) % mod) % mod;
    printf("%llu\n", ans);
}