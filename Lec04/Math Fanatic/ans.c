#include<stdio.h>
#define int long long
int s[100005], sum;
signed main () {
    int N;
    scanf("%lld", &N);
    for (int i = 0; i < N; i++) scanf("%lld", &s[i]);
    for (int i = 0; i < N; i++) {
    	sum += s[i];
        if (sum % s[i] == 0) printf("%lld %lld\n", sum, s[i]);
    }
    return 0;
}
