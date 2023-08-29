#include<stdio.h>

int main () {
    float h, w;
    scanf("%f %f", &h, &w);
    h /= 100;
    printf("%f", w / (h * h));
    return 0;
}
