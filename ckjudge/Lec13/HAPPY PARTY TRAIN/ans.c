int fire(struct Car *head) {
    int ans = 0;
    for (struct Car *it = head->next; it != NULL; it = it->next) {
        if (it->passenger >= it->flammable) break;
        ans++;
        if (it->next != NULL) it->next->passenger += it->passenger;
    }
    return ans;
}