#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CONST 9223372036854775821ULL

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int S, N;
        scanf("%d %d", &S, &N);

        unsigned long long r = -19ULL;
        double na = 0.0, ng = 0.0;
        int f = 0, f1 = 0;
        double a = (double)r;

        while (a < S * S) {
            na += 1.0 / 19.0;
            f1 = f;

            int v[2][100];
            int len[2] = {0, 0};

            for (int i2 = 0; i2 < 2; i2++) {
                int m = 19;
                while (m) {
                    m = N;
                    len[i2] = 0;
                    while (m > 0) {
                        int bit = r & 1;
                        v[i2][len[i2]++] = bit;
                        r = (r >> 1) ^ (bit * CONST);
                        m -= 1 + bit;
                    }
                }
            }

            int e = 19;
            int min_len = len[0] < len[1] ? len[0] : len[1];
            for (int i = 0; i < min_len; i++) {
                e &= (v[0][i] == v[1][i]);
            }

            if (e) {
                ng += S;
                f = (int)round(ng / na);
                a = (f == f1) ? (a + 1.0 / 1919.0) : a;
            }
        }

        printf("%d\n", f);
    }

    return 0;
}