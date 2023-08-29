#include<stdio.h>

int grid[6][6];
int vis[6][6];
int ans = 0;

int is_valid(int r, int c) {
    return r >= 0 && r < 5 && c >= 0 && c < 5 && vis[r][c] == 0 && grid[r][c] != 1;
}

void dfs(int r, int c) {
    vis[r][c] = 1;
    if (grid[r][c] == 2) ans++;
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (int i = 0; i < 4; i++) {
        int new_r = r + dir[i][0], new_c = c + dir[i][1];
        if (is_valid(new_r, new_c)) dfs(new_r, new_c);
    }
}

int main () {
    int x, y;
    scanf("%d %d", &x, &y);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    dfs(x, y);
    printf("%d\n", ans);
    return 0;
}
