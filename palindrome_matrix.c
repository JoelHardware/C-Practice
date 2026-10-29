#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 1000

char grid[MAXN][MAXN + 1];

void palindrome(int *pos, int len, int fixed, int is_row) {
    for (int i = 0; i < len / 2; ++i) {
        char d1, d2, best = '0';
        int min_cost = INT_MAX;

        if (is_row) {
            d1 = grid[fixed][pos[i]];
            d2 = grid[fixed][pos[len - 1 - i]];
        } else {
            d1 = grid[pos[i]][fixed];
            d2 = grid[pos[len - 1 - i]][fixed];
        }

        for (char d = '0'; d <= '9'; ++d) {
            int cost = abs(d - d1) + abs(d - d2);
            if (cost < min_cost || (cost == min_cost && d < best)) {
                min_cost = cost;
                best = d;
            }
        }

        if (is_row) {
            grid[fixed][pos[i]] = best;
            grid[fixed][pos[len - 1 - i]] = best;
        } else {
            grid[pos[i]][fixed] = best;
            grid[pos[len - 1 - i]][fixed] = best;
        }
    }
}

int main(void) {
    int N, M;
    if (scanf("%d %d", &N, &M) != 2)
        return 1;

    for (int i = 0; i < N; ++i)
        scanf("%s", grid[i]);

    //rows
    for (int i = 0; i < N; ++i) {
        int j = 0;
        while (j < M) {

            while (j < M && grid[i][j] == '.') ++j;
            int start = j;

            while (j < M && grid[i][j] != '.') ++j;
            int end = j;
            int len = end - start;
            if (len > 1) {
                int pos[len];
                for (int k = 0; k < len; ++k)
                    pos[k] = start + k;
                palindrome(pos, len, i, 1);
            }
        }
    }

    //col
    for (int j = 0; j < M; ++j) {
        int i = 0;
        while (i < N) {

            while (i < N && grid[i][j] == '.') ++i;
            int start = i;

            while (i < N && grid[i][j] != '.') ++i;
            int end = i;
            int len = end - start;
            if (len > 1) {
                int pos[len];
                for (int k = 0; k < len; ++k)
                    pos[k] = start + k;
                palindrome(pos, len, j, 0);
            }
        }
    }

    for (int i = 0; i < N; ++i)
        printf("%s\n", grid[i]);

    return 0;
}
