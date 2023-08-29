void convert(char *arr[], int count) {
    for (int i = 0; i < count; i++) {
        int n = strlen(arr[i]), idx = 0;
        // printf("%d ", n);
        char s[BUFFER_LEN];
        memcpy(s, arr[i], sizeof s);
        for (int j = 0; j < n; j++) {
            if (s[j] == '\n') continue;
            if (s[j] == ' ') {
                arr[i][idx++] = ' ';
                continue;
            }
            int block = (s[j] - 'a') / 3 + 2;
            int resi = (s[j] - 'a') % 3 + 1;
            if (s[j] >= 'p' && s[j] <= 's') block = 7, resi=s[j]-'p' + 1;
            if (s[j] >= 't' && s[j] <= 'v') block = 8, resi=s[j]-'t' + 1;
            if (s[j] >= 'w' && s[j] <= 'z') block = 9, resi=s[j]-'w' + 1;
            arr[i][idx++] = '(';
            arr[i][idx++] = block + '0';
            arr[i][idx++] = ')';
            arr[i][idx++] = resi + '0';
        }
        arr[i][idx++] = '\n';
        arr[i][idx++] = 0;
    }
}