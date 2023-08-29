#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>

int min(int x, int y) {return (x > y ? y : x);}
int max(int x, int y) {return (x > y ? x : y);}

int main () {
    int mp[26];
    mp['A' - 'A'] = 0;
    mp['B' - 'A'] = 1;
    mp['C' - 'A'] = 2;
    mp['D' - 'A'] = 3;
    mp['E' - 'A'] = 4;
    mp['F' - 'A'] = 4;
    mp['H' - 'A'] = 6;

    mp['I' - 'A'] = 7;
    mp['J' - 'A'] = 8;
    mp['K' - 'A'] = 9;
    mp['L' - 'A'] = 0;
    mp['N' - 'A'] = 2;
    mp['P' - 'A'] = 3;
    mp['Q' - 'A'] = 4;

    mp['R' - 'A'] = 5;
    mp['S' - 'A'] = 6;
    mp['T' - 'A'] = 7;
    mp['U' - 'A'] = 8;
    mp['V' - 'A'] = 9;
    mp['Z' - 'A'] = 2;
    char a[105];
    while (scanf("%s", a) != EOF) {
        int n = strlen(a);
        int ttl = 0;
        for (int i = 0; i < n; i++) {
            if ((a[i] >= 'A' && a[i] <= 'Z')) {
                ttl += mp[( a[i] - 'A')] * (9-i);
                // printf("%d x %d\n", mp[( a[i] - 'A')], 9 - i);
            }
            else if (a[i] >= 'a' && a[i] <= 'z') {
                ttl += mp[( a[i] - 'a')] * (9-i);
                // printf("%d x %d\n", mp[( a[i] - 'a')], 9 - i);
            }
            else {
                ttl += (a[i] - '0') * (9-i);
                // printf("%d x %d\n", ( a[i] - '0'), 9 - i);
            }
            // printf("%d\n", ttl);
        }
        // printf("%d\n", ttl);
        if (ttl % 10 != 0) {
            printf("%s is the imposter!!!\n", a);
        }
    }
}
