void MoveToTail() {
    if (head == tail) return;
    int m = -1;
    struct node *prev = NULL;
    for (struct node *it = head; it != NULL; it = it->next) {
        if (it->val >= m) {
            m = it->val;
        }
    }
    for (struct node *it = head; it != NULL; it = it->next) {
        if (it->val == m) {
            if (it == tail) return;
            struct node *tmp = it;
            if (it == head) head = it->next;
            else prev->next = it->next;
            tail->next = it;
            tail = it;
            it->next = NULL;
            return;
        }
        prev = it;
    }
}