#include <string.h>
void check_sudoku(int (*grid_p)[NUM]){
    int grid[NUM][NUM];
    memset(grid, 0, sizeof(grid));
    for (int i = 0; i < NUM; ++i){
        for (int j = 0; j < NUM; ++j) {
            int num[10];

            memset(num, 0, sizeof(num));
            for (int k = 0; k < NUM; ++k) num[grid_p[i][k]]++;
            if (num[grid_p[i][j]] != 1) grid[i][j] = 1;

            memset(num, 0, sizeof(num));
            for (int k = 0; k < NUM; ++k) num[grid_p[k][j]]++;
            if (num[grid_p[i][j]] != 1) grid[i][j] = 1;

            memset(num, 0, sizeof(num));
            int u = (i/3) * 3, l = (j/3) * 3;
            for (int r = u; r <= u + 2; r++) for (int c = l; c <= l + 2; c++) num[grid_p[r][c]]++;
            if (num[grid_p[i][j]] != 1) grid[i][j] = 1;
        }
    }
    for (int i = 0; i < NUM; ++i) for (int j = 0; j < NUM; ++j) if (grid[i][j] == 1) printf("(%d,%d)\n", i, j);
}