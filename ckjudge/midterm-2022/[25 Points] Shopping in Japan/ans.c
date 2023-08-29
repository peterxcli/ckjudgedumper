#include<stdio.h>
#include<math.h>

int main () {
    double x;
    scanf("%lf", &x);
    double prev, cur;
    if (x <= 5000) {
        prev = x * (1.08);
        cur = x * (1.1);
    }
    else {
        prev = x;
        cur = x;
    }
    prev = prev * 0.2966;
    cur = cur * 0.2178;
    int ans = 0;
    if (prev - cur > 0) ans = lround(prev) - lround(cur);
    else ans = lround(cur) - lround(prev); 
    printf("%ld\n", lround(ans));
    return 0;
}
