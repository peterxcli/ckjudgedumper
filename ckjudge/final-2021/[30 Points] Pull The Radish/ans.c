int pull_radish(int *l, int *r, int *pos, int x) {
    for (int *iter = l; iter <= r; iter++) *iter = 1;
    int ans = 0;
    for (int *iter = pos, i = 0; iter <= r; iter++, i++) {
        if (i == x) ans++, *iter = 0, i = 0;
        // printf("%d ", iter - l);
    }
    for (int *iter = pos, i = 0; iter >= l; iter--, i++) {
        if (i == x) ans++, *iter = 0, i = 0;
    }
    return ans;
}