#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define int long long
 
int compare(const void *x, const void *y);
int minm(int x, int y);
int maxm(int x, int y);
int gcd(int a, int b);
int lower_bound(int arr[], int l, int r, int x);
int upper_bound(int arr[], int l, int r, int x);
void merge(int arr[], int l, int m, int r);
void merge_sort(int arr[], int l, int r);
int exponent_2(int n);
void swap(int *a, int *b);
void revarr(int arr[], int n);
#define MAXN 10005

void toTime (int* _cur, char* s) {
    *_cur = (s[0]-'0') * 10 + (s[1]-'0');
    *_cur = *_cur * 60 + (s[3]-'0') * 10 + (s[4]-'0');
}

int cur;

signed main() {
    char s[MAXN];
    scanf("%s", s);
    toTime(&cur, s);
    //printf("%lld", cur);
    int n;
    scanf("%lld", &n);
    int mx = __INT32_MAX__, ans = 0;
    for (int i = 0; i < n; i++) {
        int x, y, t;
        scanf("%lld %s %lld", &x, s, &y);
        toTime(&t, s);
        if (t < cur) continue;
        if (t+y < mx) ans = x, mx = t+y;
    }
    printf("%lld\n", ans);
}

int compare(const void *x, const void *y) { return (*(int *)y - *(int *)x); }
int minm(int x, int y) { return x < y ? x : y; }
int maxm(int x, int y) { return x > y ? x : y; }
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lower_bound(int arr[], int l, int r, int x) {
    while ((l + 1) < r) {
        int mid = (l + r) / 2;
        if (x <= arr[mid]) r = mid;
        else l = mid;
    }
    return r;
}

int upper_bound(int arr[], int l, int r, int x) {
    while ((l + 1) < r) {
        int mid = (l + r) / 2;
        if (x >= arr[mid]) l = mid;
        else r = mid;
    }

    if (x > arr[l] && x <= arr[r]) return r;
    else return l;
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int exponent_2(int n) {
    if (n > 0)
    {
        if (ceil(log2(n)) == floor(log2(n)))
            ;
        return log2(n);
    }
    return -1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void revarr(int arr[], int n) {
    for (int i = 0; i < n / 2; i++)
    {
        swap(&arr[i], &arr[n - i - 1]);
    }
}