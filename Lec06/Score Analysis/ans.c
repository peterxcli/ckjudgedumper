#include<stdio.h>

int s[1005];

int main () {
    int N, T;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &s[i]);
    }
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int a, b;
        scanf("%d %d", &b, &a);
        int l = 0, m = 0, r = 0;
        for (int j = 0; j < N; j++) {
            if (s[j] < b) l++;
            if (s[j] >= b && s[j] < a) m++;
            if (s[j] >= a) r++;
        }
        printf("%d %d %d\n", l, m, r);
    }
    return 0;
}
