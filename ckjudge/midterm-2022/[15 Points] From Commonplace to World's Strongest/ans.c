#include<stdio.h>
#include<math.h>
#include<string.h>

#define int long long
#define char unsigned char

int min(int x, int y) {return (x > y ? y : x);}
int max(int x, int y) {return (x > y ? x : y);}

int rec[1005], depth[1005];
char G[1005][1005];

int dfs(int u) {
    // if (rec[u]) {
    //     return rec[u];
    // }
    if (u >= 'a' && u <= 'e') {
        depth[u] = 1;
        return 1;
    }
    // rec[u] = 1;
    int len = strlen(G[u]);
    int start = 0, ttl = 0;
    int mx = 0;
    for (int i = 0; i < len; i++) if (G[u][i] == ')') start = i;
    for (int i = start+1; i < len; i++) {
        int v = G[u][i];
        ttl += dfs(v);
        mx = max(mx, depth[v]);
        depth[u] = mx+1;
    }
    return ttl;
}

signed main () {
    memset(rec, 0, sizeof rec);
    memset(depth, 0, sizeof depth);
    int n;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        char s[1005];
        memset(s, 0, sizeof s);
        scanf("%s", s);
        int u = s[0];
        memcpy(G[u], s, sizeof s);
    }
    char s[1005];
    memset(s, 0, sizeof s);
    scanf("%s", s);
    int len = strlen(s);
    int ans = 0, dep = 0;
    int start = 0;
    for (int i = 0; i < len; i++) if (s[i] == ')') start = i;
    for (int i = start+1; i < len; i++) {
        ans += dfs(s[i]);
        dep = max(dep, depth[s[i]]);
    }
    printf("%lld %lld\n", dep+1, ans);
}
