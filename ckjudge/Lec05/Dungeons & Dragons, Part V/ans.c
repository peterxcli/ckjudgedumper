#include <stdio.h>

int a[7];

int main () {
    for (int i = 0; i < 75; i++) {
        int d1, d2;
        scanf("%d %d", &d1, &d2);
        if (d2 % 2 == 0) {
            a[d1] = (a[d1] - 1 + 10) % 10;
        }
        else {
            a[d1] = (a[d1] + 1 + 10) % 10;
        }
    }
    for (int i = 1; i <= 6; i++) printf("%d%c", a[i], (i == 6 ? '\n' : ' '));
    return 0;
}
