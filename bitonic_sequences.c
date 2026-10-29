#include <stdio.h>
#include <string.h>


#define MOD 1000000007
#define MAXM 300005

int dp[MAXM], bitonic[MAXM];

int main(){
    int M;
    scanf("%d", &M);
    
    dp[0] = 1;

    for (int i = 1; i <= M; i++) {
        for (int j = 1, k = 1; i >= (3 * j * j - j) / 2; j = (j > 0) ? -j : -j + 1) {
            int idx = (3 * j * j - j) / 2;
            if (j % 2 == 0) {
                dp[i] = (dp[i] - dp[i - idx] + MOD) % MOD;
            } else {
                dp[i] = (dp[i] + dp[i - idx]) % MOD;
            }
            k++;
            if (k > 100) break;
        }
    }

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    
    for (int i = 1; i <= M; i++) {
        for (int j = i; j <= M; j++) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }

    for (int n = 1; n <= M; n++) {
        long long total = 0;

        for (int m = 1; m <= n; m++) {
            int remaining = n - m;

            if (remaining >= 0) {
                total = (total + (long long)dp[remaining] * dp[remaining]) % MOD;
            }
        }
        bitonic[n] = total;
    }
    
    for (int n = 1; n <= M; n++) {
        printf("%d\n", bitonic[n]);
    }
    return 0;
}