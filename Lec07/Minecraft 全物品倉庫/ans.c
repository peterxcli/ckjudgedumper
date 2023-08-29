#include<stdio.h>

#define MAXN 25

int adj[30][30], len[30], dp[30];

int dfs(int u) {
    if (len[u] == 0) {
        return 1;
    }
    int ret = 0;
    for (int v = 1; v <= MAXN; v++) {
        if (adj[u][v]) {
            ret += dfs(v);
        }
    }
    return ret;
}

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int m;
        scanf("%d", &m);
        len[i] = m;
        for (int j = 0; j < m; j++) {
            int v;
            scanf("%d", &v);
            adj[i][v] = 1;
        }
    }
    for (int i = 1; i <= n; i++) dp[i] = dfs(i);
    int ans = 0;
    for (int i = 1; i <= MAXN; i++) ans += dp[i];
    printf("%d\n", ans);
    return 0;
}
