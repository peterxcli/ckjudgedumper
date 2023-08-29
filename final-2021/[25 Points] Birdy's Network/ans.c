int cmp(const void *a,const void *b) {
    return *(int *)a - *(int *)b;
}

int cmp1(const void *a,const void *b) {
    return ((struct node*)a)->id - ((struct node*)b)->id;
}

struct node *read_data(int *size){
    struct node *head = malloc(sizeof(struct node)*10005);
    *size = 0;
    int a;
    while (scanf("%d", &a) != EOF) {
        char _[100005];
        scanf("%s", _);
        int n = 0, b;
        int nums[10005];
        while (scanf("%d", &b) && b != 0) {
            nums[n++] = b;
        }
        qsort(nums, n, sizeof(int), cmp);
        // for (int i = 0; i < n; i++) printf("%d ", nums[i]);
        // puts("");
        struct node *cur = &(head[(*size)++]);
        cur->id = a;
        cur->next = NULL;
        for (int i = 0; i < n; i++) {
            struct node *new_node = malloc(sizeof(struct node));
            new_node->id = nums[i];
            new_node->next = NULL;
            cur->next = new_node;
            cur = new_node;
        }
    }
    qsort(head, *size, sizeof(struct node), cmp1);
    return head;
}
