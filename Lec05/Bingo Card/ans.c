#include<stdio.h>

int tables[8][8], d[64], grid[8][8];

int main () {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%d", &tables[i][j]);
            grid[i][j] = 0;
        }
    }
    for (int i = 0; i < 64; i++) scanf("%d", &d[i]);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 64; k++) {
                if (tables[i][j] == d[k]) grid[i][j] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (grid[i][j] == 0) break;
            if (j == 7) ans++;
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (grid[j][i] == 0) break;
            if (j == 7) ans++;
        }
    }
    for (int i = 0; i < 8; i++) {
        if (grid[i][i] == 0) break;
        if (i == 7) ans++;
    }
    for (int i = 0; i < 8; i++) {
        if (grid[i][7-i] == 0) break;
        if (i == 7) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
