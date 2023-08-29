#include <stdio.h>
#include <math.h>

int main () {
    int player = 100, dragon = 100;
    int d1, d2, d3, d4, d5, d6;
    while (scanf("%d%d%d%d%d%d", &d1, &d2, &d3, &d4, &d5, &d6) != EOF) {
        if ((d1 + d2 + d3) & 1) {
            if (d4 < d5 && d5 < d6) dragon -= 25;
            else if (d4 & 1 == d5 & 1 || d5 & 1 == d6 & 1) dragon -= 5;
            if (dragon <= 0) break;
        }
        else {
            if (abs(d5-d4) > d6) player -= 15;
            else if (d4+d5 != d6) player -= 5;
            if (player <= 0) break;
        }
    }
    if (player <= 0) printf("Dragon wins\n");
    else printf("Player wins\n");
    return 0;
}
