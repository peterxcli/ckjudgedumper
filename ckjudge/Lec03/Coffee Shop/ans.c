#include <stdio.h>
#define AMERICANO  110
#define LATTE      150
#define CAPPUCCINO 135
#define MOCHA      145

int main() {
    int a[5] = {0, AMERICANO, LATTE, CAPPUCCINO, MOCHA};
	int i, j;
    scanf("%d %d", &i, &j);
    if (i <= 4 && i > 0) printf("The total price is %d dollars!\n", a[i] * j);
    else printf("Wait, what?\n");
    return 0;
}