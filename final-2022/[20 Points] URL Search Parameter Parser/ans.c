search_t *get_param_by_key(char *url, char *key) {
    for (int i = 0; i < URL_MAX; i++) if (url[i] == '\n') url[i] = '\0';
    int size = 0;
    int n = strlen(url);
    search_t *ans = malloc(sizeof(search_t)*10);
    for (int i = 0; i < n; i++) if (url[i] == '#') url[i] = '\0';
    
    if (strstr(url, key) == NULL || strstr(url, "?") == NULL) return NULL;
    n = strlen(url);
    // printf("%d\n", n);
    // return NULL;
    int start = 0;
    for (int i = 0; i < n; i++) {
        if (url[i] == '?') {
            start = i;
        }
    }
    int i = start+1, j = start+1;
    while (j < n) {
        while (url[j] != '=') {
            j++;
        }
        char str[100];
        for (int k = i; k <= j-1; k++) str[k-i] = url[k];
        str[j-i] = '\0';
        ans[size++].key = strdup(str);
        // printf("%s\n", str);
        j++;
        i = j;
        while (j < n && url[j] != '&') {
            j++;
        }
        for (int k = i; k <= j-1; k++) str[k-i] = url[k];
        str[j-i] = '\0';
        // printf("%s\n", str);
        // return NULL;
        ans[size-1].value = strdup(str);
        j++;
        i = j;
        // printf("%s %s\n", ans[size].key, ans[size].value);
    }
    // printf("%d\n", size);
    for (int k = 0; k < size; k++) {
        // printf("%s\n", ans[k].key);
        if (strcmp(ans[k].key, key) == 0) return &ans[k];
    }
    return NULL;
}