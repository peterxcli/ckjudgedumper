
void convert (char *last, char *first) {
    if (strlen(last) > 15 || strlen(first) > 15) {
        printf("illegal\n");
        return;
    }
    for (int i = 0; i < strlen(last); i++) {
        if (last[i] >= 'a' && last[i] <= 'z') last[i] = (last[i] - 'a') + 'A';
    }
    for (int i = 0; i < strlen(first); i++) {
        if (first[i] >= 'a' && first[i] <= 'z') first[i] = (first[i] - 'a') + 'A';
        if (first[i] == ' ') first[i] = '-';
    }
    printf("%s, %s", last, first);
}
