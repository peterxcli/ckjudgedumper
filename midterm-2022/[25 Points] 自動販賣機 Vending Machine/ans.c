#include<stdio.h>
#include<math.h>

int a[105][105];

int min(int x, int y) {return (x > y ? y : x);}
int max(int x, int y) {return (x > y ? x : y);}

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= 10; j++) {
            a[i][j] = 10;
        }
    }
    int ttl = 0;
    for (int i = 0; i < n; i++) {
        int k, q;
        scanf("%d %d", &k, &q);
        if (k <= 10) {
            int row = 0;
            ttl += min(a[row][k], q) * 10;
            a[row][k] -= min(a[row][k], q);
        }
        else if (k <= 20) {
            int row = 1;
            k -= 10;
            ttl += min(a[row][k], q) * 20;
            a[row][k] -= min(a[row][k], q);
        }
        else {
            int row = 2;
            k -= 20;
            ttl += min(a[row][k], q) * 30;
            a[row][k] -= min(a[row][k], q);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= 10; j++) {
            printf("%d ", a[i][j]);
        }
        puts("");
    }
    printf("Earned: $%d\n", ttl);
}
