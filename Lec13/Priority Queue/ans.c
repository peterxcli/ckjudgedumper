void enqueue(prio_queue_t * const queue, int value, int weight) {
    struct node_s* tmp_node = malloc(sizeof(struct node_s));
    tmp_node->next = NULL;
    tmp_node->value = value;
    tmp_node->weight = weight;
    if (queue->head == NULL) {
        queue->head = tmp_node;
        return;
    }
    struct node_s *prev = NULL, *end = NULL;
    for (struct node_s *it = queue->head; it != NULL; it = it->next) {
        if (it->weight > weight) {
            if (prev == NULL) queue->head = tmp_node;
            else prev->next = tmp_node;
            tmp_node->next = it;
            return;
        }
        if (it->next == NULL) end = it;
        prev = it;
    }
    end->next = tmp_node;
}

node_t *dequeue(prio_queue_t * const queue) {
    if (queue->head == NULL) return NULL;
    struct node_s *tmp = queue->head;
    queue->head = tmp->next;
    return tmp;
}