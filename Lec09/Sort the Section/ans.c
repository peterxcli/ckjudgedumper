void sort_section(int *ptr, int *qtr) {
    if (ptr > qtr) {int *_ = ptr; ptr = qtr; qtr = _;}
    for (int *i = ptr; i < qtr; i++) {
        for (int *j = ptr; j < qtr; j++) {
            if (*j > *(j+1)) {
                int temp = *(j+1);
                *(j+1) = *j;
                *j = temp;
            }
        }
        for (int *j = ptr; j <= qtr; j++) printf("%d ", *j);
        printf("\n");
    }
}
