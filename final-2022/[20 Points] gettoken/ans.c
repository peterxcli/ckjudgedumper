#include <string.h>
char *exist(const char *str, char *substr) {
    for (char *iter = (char *)str; *iter != '\0'; iter++)
        if (*iter == *substr)
            return iter;
    return NULL;
}
char *start;
char *gettoken(char *str, const char *sep) {
    if (str != NULL) {
        start = NULL;
        // for (char *iter = str; *iter != '\0'; iter++) {
        //     if (*iter == '\n') *iter = '\0';
        // }
        for (char *iter = str; *iter != '\0'; iter++) {
            if (exist(sep, iter) == NULL) {
                start = iter;
                break;
            }
        }
        if (start == NULL)
            return NULL;
    }
    // else {
    //     char* prev = start;
    //     for (char *iter = start; *iter != '\0'; iter++) {
    //         if (exist(sep, iter) == NULL) {
    //             start = iter;
    //             break;
    //         }
    //     }
    //     // if (prev != start) return NULL;
    // }
    char *ret = NULL;
    for (char *iter = start; *iter != '\0'; iter++) {
        if (exist(sep, iter) != NULL) {
            // puts(iter);
            *iter = '\0';
            ret = strdup(start);
            start = iter + 1;
            break;
        }
    }
    for (char *iter = start; *iter != '\0'; iter++) {
        if (exist(sep, iter) == NULL) {
            start = iter;
            break;
        }
    }
    if (ret != NULL && *ret == '\0') return NULL;
    return ret;
}