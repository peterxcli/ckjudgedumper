#define min(a, b) (a<b?a:b)
#define max(a, b) (a>b?a:b)

void recovery(char *homework) {
    char hw[MAX_LEN];
    int idx = 0;
    int n = strlen(homework);
    if (homework[n-1] == '\n') n--;
    // printf("%d\n", n);
    char s[MAX_LEN];
    int iter = 0;
    for (int i = 0; i < n; i++) {
        // if (homework[i] == '.' || homework[i] == ',' || homework[i] == '!' || homework[i] == '?') {
        //     if ((i < n-1 && homework[i+1] == ' ' && iter != 0) || (i == n-1 && iter != 0)) s[iter++] = homework[i];
        // }
        // else 
        if (homework[i] == ' ') {
            // printf("%s\n", s);
            if (iter == 0) continue;
            int flag = 0;
            for (int j = 0; j < iter; j++) if (!((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || s[j] == '.' || s[j] == ',' || s[j] == '!' || s[j] == '?')) flag = 1;
            for (int j = 0; j < iter; j++) if ((s[j] == '.' || s[j] == ',' || s[j] == '!' || s[j] == '?') && (j != iter-1 || iter == 1)) flag = 1;
            if (flag || iter > 21) {iter = 0; continue;}
            for (int j = 0; j < iter; j++) hw[idx++] = s[j];
            hw[idx++] = ' ';
            iter = 0;
        }
        else s[iter++] = homework[i];

        if (i == n-1) {
            if (iter == 0) continue;
            // printf("%s\n", s);
            int flag = 0;
            for (int j = 0; j < iter; j++) if ((s[j] == '.' || s[j] == ',' || s[j] == '!' || s[j] == '?') && (j != iter-1 || iter == 1)) flag = 1;
            for (int j = 0; j < iter; j++) if (!((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || s[j] == '.' || s[j] == ',' || s[j] == '!' || s[j] == '?')) flag = 1;
            if (flag || iter > 21) {iter = 0; continue;}
            for (int j = 0; j < iter; j++) hw[idx++] = s[j];
            // hw[idx++] = '\0';
        }
    }
    hw[idx++] = '\0';
    memset(homework, 0, sizeof homework);
    strcpy(homework, hw);
}