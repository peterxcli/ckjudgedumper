#include<stdio.h>
#define max(a, b) (a>b?a:b)
#define min(a, b) (a<b?a:b)
#define MAXN 200005

#define int long long

int a[MAXN];

__int32_t main () {
    int len = 0;
    for (len = 0; len < MAXN; len++) {
        scanf("%lld", &a[len]);
        if (a[len] == -1) break;
    }
    int big = 0, small = 1e12;
    for (int i = 0; i < len; i++) big = max(big, a[i]), small = min(small, a[i]);
    printf("%lld\n", big - small);
    return 0;
}
