#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, k;
    scanf("%d %d", &N, &k);

    int *C = (int *)malloc(sizeof(int) * N);
    C[0] = 0; // Capital
    for (int i = 1; i < N; i++) {
        scanf("%d", &C[i]);
    }

    // DP for all possible sums of round trips (0->i->0)
    unsigned char reachable[10001] = {0};
    reachable[0] = 1;

    for (int i = 1; i < N; i++) {
        int cost = 2 * C[i];
        for (int j = cost; j <= k; j++) {
            if (reachable[j - cost])
                reachable[j] = 1;
        }
    }

    int Q;
    scanf("%d", &Q);

    while (Q--) {
        int A, B;
        scanf("%d %d", &A, &B);

        int base = C[A] + C[B];
        int leftover = k - base;

        if (leftover < 0) {
            printf("No\n");
        } else if (reachable[leftover]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    free(C);
    return 0;
}
