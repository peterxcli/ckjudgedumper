#include<stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int que[1005], head = 0, tail = 0;
    for (int i = 0; i < n; i++) que[tail++] = i+1;
    for (int i = 0; i < m; i++) {
        printf("%d ", que[head++]);
        que[tail++] = que[head++];
    }
    return 0;
}
