#include<stdio.h>
#include<string.h>

int main () {
    int dis, h;
    scanf("%d %d", &dis, &h);
    char s[100][4][100], c;
    int i = 0, j = 0, k = 0;
    scanf("%c", &c);
    // printf("%c\n", c);
    while (1) {
        if (scanf("%c", &c) == EOF) {s[i][j][k] = '\0'; break;}
        // printf("%c\n", c);
        if (c == '\n') {s[i][j][k] = '\0'; break;}
        else if (c == ' ') j++, k = 0;
        else if (c == '.' || c == ',') {
            s[i][j][k] = '\0';
            i++, j = 0, k = 0;
        }
        else s[i][j][k++] = c;
    }
    // printf("%d\n", i);
    // for (int idx = 0; idx <= i; idx++) {
    //     printf("%s %s %s %s\n", s[idx][0], s[idx][1], s[idx][2], s[idx][3]);
    // }
    int cnt = 0;
    for (int idx = 0; idx <= i; idx++) {
        if (strcmp(s[idx][0], "PATA") == 0 && strcmp(s[idx][1], "PATA") == 0 && strcmp(s[idx][2], "PATA") == 0 && strcmp(s[idx][3], "PON") == 0) {
            cnt++;
            dis--;
        }
        else if (strcmp(s[idx][0], "PON") == 0 && strcmp(s[idx][1], "PON") == 0 && strcmp(s[idx][2], "PATA") == 0 && strcmp(s[idx][3], "PON") == 0) {
            cnt++;
            if (dis <= 3) h--;
        }
        else if (strcmp(s[idx][0], "CHAKA") == 0 && strcmp(s[idx][1], "CHAKA") == 0 && strcmp(s[idx][2], "PATA") == 0 && strcmp(s[idx][3], "PON") == 0) {
            cnt++;
            dis++;
        }
        
        if (dis <= 0) {
            printf("NO %d\n", h);
            return 0;
        }
        else if (h <= 0) {
            printf("YES %d\n", cnt);
            return 0;
        }
        else if((idx+1) % 10 == 0 && (strcmp(s[idx][0], "CHAKA") != 0 || strcmp(s[idx][1], "CHAKA") != 0 || strcmp(s[idx][2], "PATA") != 0 || strcmp(s[idx][3], "PON") != 0)) {
            printf("NO %d\n", h);
            return 0;
        }
    }
    printf("NO %d\n", h);
    return 0;
}
