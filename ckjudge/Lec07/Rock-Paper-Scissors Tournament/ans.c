#include<stdio.h>
#include<string.h>
#define MAXN 1030

char p[MAXN], judge[15];
int win[MAXN];

struct Player
{
    char c;
    int idx;
};


int main () {
    int n;
    scanf("%d", &n);
    scanf("%s", p+1);
    scanf("%s", judge);
    int log_n = strlen(judge);
    for (int i = 1; i <= n; i++) win[i] = 1;
    struct Player p1, p2;
    for (int i = n*2, idx = 0;i && idx < log_n; i >>= 1, idx++) {
        p1.idx = 0;
        for (int j = 1; j <= n; j++) {
            if (!win[j]) continue;
            if (p1.idx == 0) p1.c = p[j], p1.idx = j;
            else {
                p2.c = p[j], p2.idx = j;
                if (p1.c == 'r' && p2.c == 's') win[p2.idx] = 0;
                else if (p1.c == 's' && p2.c == 'p') win[p2.idx] = 0;
                else if (p1.c == 'p' && p2.c == 'r') win[p2.idx] = 0;
                else if (p1.c == 's' && p2.c == 'r') win[p1.idx] = 0;
                else if (p1.c == 'p' && p2.c == 's') win[p1.idx] = 0;
                else if (p1.c == 'r' && p2.c == 'p') win[p1.idx] = 0;
                else {
                    if (judge[idx] == 'b') {
                        win[p1.idx] = 0;
                    }
                    else {
                        win[p2.idx] = 0;
                    }
                }
                p1.idx = 0;
            }
        }
        //for (int i = 1; i <= n; i++) if (win[i]) printf("%d ", i);
        //puts("");
    }
    for (int i = 1; i <= n; i++) if (win[i]) printf("%d\n", i);
    return 0;
}
