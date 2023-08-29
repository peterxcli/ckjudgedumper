#include <stdio.h>
#include <math.h>

int main(void){
    float res = 0, x;
 	scanf("%f", &x);
    res = 7 * pow(x, 4) - 8 * pow(x, 3) - pow(x, 2) + 6 * x - 22;
    printf("%.1f", res );
}
