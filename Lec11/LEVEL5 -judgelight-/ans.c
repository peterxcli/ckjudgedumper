int cmp(const void *a, const void *b) {
    return ((const struct ESPer*)a)->level - ((const struct ESPer*)b)->level;
}

void sort_level(struct ESPer *arr, int length) {
    qsort(arr, length, sizeof(struct ESPer), cmp);
}