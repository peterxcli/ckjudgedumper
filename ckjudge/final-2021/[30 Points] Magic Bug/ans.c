#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define int long long

void solve(int x, int stb) {
    int res[100];
    memset(res, 0, sizeof res);
    int n = 63;
    int i = 0;
    while (x) {
        res[n-i] = (x&1) & (i >= stb) & (i < stb+8);
        i++;
        x /= 2;
    }
    for (int j = 0; j <= n; j++) {
        if (j % 8 == 0 && j != 0) printf(" ");
        printf("%lld", res[j]);
    }
    puts("");
}

__int32_t main () {
    int n;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        char _;
        scanf("%lld%c%llx", &a, &_, &b);
        // printf("%llx\n", b);
        solve(b, a);
    }
    
    return 0;
}
