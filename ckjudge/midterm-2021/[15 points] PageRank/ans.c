#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#define int long long

#define MAXN 105
const double EPS = 1e-7;

int G[MAXN][MAXN], n, odegree[MAXN];
int ans[MAXN], len, vis[MAXN];
double val[MAXN][2];

signed main() {
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        while (1) {
            int x;
            scanf("%lld", &x);
            if (x == -1) break;
            odegree[i]++;
            G[i][x] = 1;
        }
    }
    for (int i = 0; i < n; i++) val[i][0] = (double)1.0/(double)n, val[i][1]  = 0;
    
    int idx = 1;
    while (1) {
        double diff = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!G[i][j]) continue;
                val[j][idx&1] += val[i][(idx-1)&1] / odegree[i];
            }
        }
        // for (int i = 0; i < n; i++) printf("%.2lf%%%c", val[i][(idx-1)&1], (i == n-1 ? '\n' : ' '));
        // for (int i = 0; i < n; i++) printf("%.2lf%%%c", val[i][idx&1], (i == n-1 ? '\n' : ' '));
        for (int i = 0; i < n; i++) diff += fabs(val[i][(idx-1)&1] - val[i][idx&1]), val[i][(idx-1)&1] = 0;
        if (diff / (double)n < EPS) {
            for (int i = 0; i < n; i++) printf("%.2lf%%%c", val[i][idx&1]*100, (i == n-1 ? '\n' : ' '));
            break;
        } 
        idx++;
    }
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
bool exponent_2(int n) {
    return (n & (n-1)) == n; 
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