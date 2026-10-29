#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 1024

void fwht(double *a);
double pw(double x, int p);

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int frequency[SIZE] = {0};
    for (int i = 0; i < N; ++i) {
        int A;
        scanf("%d", &A);
        frequency[A]++;
    }

    double F[SIZE];
    for (int i = 0; i < SIZE; ++i) F[i] = 1.0;
    double b[SIZE];

    // main loop over all possible values
    for (int v = 0; v < SIZE; ++v) {
        if (frequency[v]) {
            // build probability vector for value v
            for (int i = 0; i < SIZE; ++i) b[i] = 0.0;
            b[0] = 0.5;
            b[v] += 0.5;

            fwht(b);
            for (int i = 0; i < SIZE; ++i)
                F[i] *= pw(b[i], frequency[v]);
        }
    }

    // inverse FWHT (same operation)
    fwht(F);

    double ans = 0.0, sum = 0.0;
    for (int x = 0; x < SIZE; ++x) {
        double p = F[x] / SIZE;
        if (p < 0 && p > -1e-12) p = 0; // remove floating noise
        sum += p;
        ans += p * pow(x, K);
    }

    ans /= sum; // normalize
    printf("%.2f\n", ans);
    return 0;
}

/* Fast Walsh–Hadamard Transform for XOR convolution */
void fwht(double *a) {
    for (int length = 1; length < SIZE; length <<= 1) {
        for (int i = 0; i < SIZE; i += (length << 1)) {
            for (int j = 0; j < length; ++j) {
                double u = a[i + j];
                double v = a[i + j + length];
                a[i + j] = u + v;
                a[i + j + length] = u - v;
            }
        }
    }
}

/* Safe power function handling negative bases correctly */
double pw(double x, int p) {
    if (p == 0) return 1.0;
    double s = (x < 0 && (p & 1)) ? -1.0 : 1.0;
    return s * pow(fabs(x), p);
}
