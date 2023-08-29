double c[MAX_SIZE][MAX_SIZE], m[MAX_SIZE][MAX_SIZE], y[MAX_SIZE][MAX_SIZE], k[MAX_SIZE][MAX_SIZE];

void print_C(unsigned int mask[][MAX_SIZE]) {
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) c[i][j] = mask[i][j]; 
}

void print_M(unsigned int mask[][MAX_SIZE]) {
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) m[i][j] = mask[i][j];
}

void print_Y(unsigned int mask[][MAX_SIZE]) {
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) y[i][j] = mask[i][j];
}

void print_K(unsigned int mask[][MAX_SIZE]) {
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) k[i][j] = mask[i][j];
}

void CMYK_to_RGB() {
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            int R = lround(255.0 * (100.0-c[i][j]) / 100.0 * (100.0-k[i][j]) / 100.0);
            int G = lround(255.0 * (100.0-m[i][j]) / 100.0 * (100.0-k[i][j]) / 100.0);
            int B = lround(255.0 * (100.0-y[i][j]) / 100.0 * (100.0-k[i][j]) / 100.0);
            image[i][j] += R << 16;
            image[i][j] += G << 8;
            image[i][j] += B;
        }
    }
}
