#include <stdio.h>

int main(void){
    char s[100];
    scanf("%s", s+1);
    int a = 0, b = 0, x = 0, y = 0, z = 0;
    for (int i = 2; i <= 12; i+=2) a += s[i] - '0';
    for (int i = 1; i <= 11; i+=2) b += s[i] - '0';
    x = 3 * a + b;
    y = x - 1;
    z = y % 10;
    printf("%d\n", 9 - z);
    return 0;
}
