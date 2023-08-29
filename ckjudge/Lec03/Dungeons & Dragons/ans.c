#include<stdio.h>

int main () {
    int a[10];
    for (int i = 1; i <= 6; i++)  scanf("%d", &a[i]);
    if (a[1] + a[2] + a[3] <= 10) {
        if (a[4] == a[5] && a[5] == a[6]) printf("Player attacks: Critical Hit\n");
        else if (a[4] + a[5] >= a[6]) printf("Player attacks: Normal Hit\n");
        else printf("Player attacks: Miss\n");
    }
    else {
    	if (a[4] == a[5] || a[5] == a[6] || a[4] == a[6]) printf("Dragon attacks: Miss\n");
       	else if (a[4] + a[5] != a[6]) printf("Dragon attacks: Normal Hit\n");
        else printf("Dragon attacks: Critical Hit\n");
    }
    return 0;
}
