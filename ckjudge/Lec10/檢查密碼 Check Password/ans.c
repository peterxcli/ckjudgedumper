int length(char pwd1[], char pwd2[]) {
    if (strlen(pwd1) >= 6 && strlen(pwd1) <= 16 && strlen(pwd2) >= 6 && strlen(pwd2) <= 16) return 0; 
    else return 1;
}

int compare(char pwd1[], char pwd2[]) {
    if (strcmp(pwd1, pwd2) != 0) return 1;
    else return 0;
}

int content(char pwd1[]) {
    int a = 0, b = 0, c = 0;
    int len = strlen(pwd1);
    for (int i = 0; i < len; i++) {
        if (pwd1[i] >= 'A' && pwd1[i] <= 'Z') a = 1;
        if (pwd1[i] >= 'a' && pwd1[i] <= 'z') b = 1;
        if (pwd1[i] >= '0' && pwd1[i] <= '9') c = 1;
    }
    if (a && b && c) return 0;
    else return 1;
}
