Location *parse_url(char *url) {
    Location *location = malloc(sizeof(Location));
    location->hash = strdup("");
    location->pathname = strdup("");
    location->search = strdup("");
    location->port = 0;
    int n = strlen(url);
    // printf("%d\n", n);
    for (int i = 0; i < n; i++) if (url[i] == '\n') url[i] = '\0';
    strlen(url);
    for (int i = 0; i < n; i++) {
        if (url[i] == '#') {
            int flag = 0;
            for (int j = i; j < n; j++) if (url[j] == '/') flag = 1;
            if (flag) continue;;
            char buff[500];
            strcpy(buff, url+i+1);
            // location->hash = ((i < n-1) ? strdup(buff) : strdup(""));
            location->hash = strdup(buff);
            url[i] = '\0';
            break;
        }
    }
    n = strlen(url);
    for (int i = 0; i < n; i++) {
        if (url[i] == '?') {
            char buff[500];
            strcpy(buff, url+i+1);
            // location->search = ((i < n-1) ? strdup(buff) : strdup(""));
            location->search = strdup(buff);
            url[i] = '\0';
            break;
        }
    }
    n = strlen(url);
    int slash = 0;
    for (int i = 0; i < n; i++) if (url[i] == '/') slash++;
    if (slash != 2) { //have pathname
        slash = 0;
        for (int i = 0; i < n; i++) {
            if (url[i] == '/') slash++;
            if (slash == 3) {
                char buff[500];
                strcpy(buff, url+i+1);
                // location->pathname = ((i < n-1) ? strdup(buff) : strdup(""));
                location->pathname = strdup(buff);
                if (location->pathname[strlen(location->pathname)-1] == '/') 
                    location->pathname[strlen(location->pathname)-1] = '\0';
                url[i] = '\0';
                break;
            } 
        }
    }
    // printf("%s\n", url);
    n = strlen(url);
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (url[i] == ':' && !flag) flag = 1;
        else if (url[i] == ':' && flag) {
            char buff[500];
            strcpy(buff, url+i+1);
            // location->port = ((i < n-1) ? atoi(buff) : 0);
            location->port = atoi(buff);
            url[i] = '\0';
            break;
        }
    }
    n = strlen(url);
    for (int i = 0; i < n; i++) {
        if (url[i] == ':') {
            char buff[500];
            strcpy(buff, url+i+3);
            // location->host = ((i < n-1) ? strdup(buff) : strdup(""));
            location->host = strdup(buff);
            url[i] = '\0';
            break;
        }
    }
    location->protocol = strdup(url);
    // if(strcmp(location->protocol, "https") == 0 ) {
    //     if (location->port == 443) location->port = 0;
    // }
    // else if (location->port == 80) location->port = 0;

    return location;
}