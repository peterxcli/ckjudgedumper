void count(const char *name) {
    for (int i = 0; i < cand_cnt; i++) {
        if (strcmp(name, counter[i].name) == 0) {
            counter[i].count ++;
        }
    }
}

const char *winner() {
    int max_idx = 0;
    for (int i = 0; i < cand_cnt; i++) {
        if (counter[i].count > counter[max_idx].count) {
            max_idx = i;
        }
    }
    return counter[max_idx].name;
}