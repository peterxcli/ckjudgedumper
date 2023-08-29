#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #define int long long

signed greater(const void *x, const void *y);
signed less(const void *x, const void *y);
int minm(int x, int y);
int maxm(int x, int y);
int gcd(int a, int b);
bool exponent_2(int n);
void swap(int *a, int *b);
void revarr(int arr[], int n);
int mod(int a, int m);
void toLower(char *s);

signed main() {
    float a, b;
    scanf("%f %f", &a, &b);
    int *p_a = &a, *p_b = &b;
    int c = *p_a;
    printf("   ");
    for (int i = 31; i >= 0; i--) {
        if ((i+1) % 8 == 0 && i != 0  && i != 31) printf(" ");
        printf("%d", (c & (1 << i)) != 0);
    } 
    printf("\n");
    c = *p_b;
    printf("+) ");
    for (int i = 31; i >= 0; i--) {
        if ((i+1) % 8 == 0 && i != 0 && i != 31) printf(" ");
        printf("%d", (c & (1 << i)) != 0);
    } 
    printf("\n");
    printf("---------------------------------------\n");
    c = *p_a + *p_b; 
    printf("   ");
    for (int i = 31; i >= 0; i--) {
        if ((i+1) % 8 == 0 && i != 0  && i != 31) printf(" ");
        printf("%d", (c & (1 << i)) != 0);
    } 
    printf("\n");
    int ans = *p_a + *p_b;
    printf("%d + %d = %d\n", (int)a, (int)b, ans);
}

//int arr[n];
//qsort(arr, n, sizeof(int), cmp);
signed greater(const void *x, const void *y) { return (*(int *)x - *(int *)y); }
signed less(const void *x, const void *y) { return (*(int *)y - *(int *)x); }
int minm(int x, int y) { return x < y ? x : y; }
int maxm(int x, int y) { return x > y ? x : y; }
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool exponent_2(int n) {
    return (n & (n - 1)) == n;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void revarr(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        swap(&arr[i], &arr[n - i - 1]);
    }
}
int mod(int a, int m) {
    return (a % m + m) % m;
}
void toLower(char *s) {
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        s[i] = tolower(s[i]);
    }
}