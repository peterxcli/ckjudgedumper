#include<stdio.h>

double f(double x, double *h) {
    *h = 0.9 * x + 0.1 * (*h) - 51;
    return (-0.98 * (*h) + 153);
}

int main () {
    double x;
    scanf("%lf", &x);
    double h = 0;
    for (int i = 0; i < 5; i++) {
        x = f(x, &h);
        printf("%.1lf ", x);
    }
    printf("\n");
    return 0;
}
