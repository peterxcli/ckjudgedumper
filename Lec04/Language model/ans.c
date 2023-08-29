#include<stdio.h>

int main () {
    double ans = 1;
    for (int i = 0; i < 5; i++) {
        double tmp;
        scanf("%lf", &tmp);
    	ans *= tmp;
    }
    printf("%.15lf\n", ans);
    return 0;
}
