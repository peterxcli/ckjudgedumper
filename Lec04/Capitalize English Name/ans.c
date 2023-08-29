#include<stdio.h>
#include<string.h>

int isUpper(char c) {
    if (c >= 'A' && c <= 'Z') return 1;
    else return 0;
}

int isLower(char c) {
    if (c >= 'a' && c <= 'z') return 1;
    else return 0;
}

char toUpper(char c) {
    if (isLower(c)) return ('A' + (c-'a'));
    return c;
}

char toLower(char c) {
    if (isUpper(c)) return ('a' + (c-'A'));
    return c;
}

char c;
int cap = 1;
int main () {
    int n;
    scanf("%d", &n);
    scanf("%c", &c);
    while (n) {
        scanf("%c", &c);
        if (c == ' ') {
            cap = 1;
            printf(" ");
        }
        else if (c == ',' || c == '.' || c == ';') {
            printf("\n");
            cap = 1;
            n--;
        }
        else if (cap) {
            printf("%c", toUpper(c));
            cap = 0;
        }
        else if (!cap) {
            printf("%c", toLower(c));
        }
    }
    return 0;
}
