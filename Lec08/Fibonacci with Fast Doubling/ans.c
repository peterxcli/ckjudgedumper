uint64_t dp[1005];
void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1)
{
	dp[0] = 0, dp[1] = 1, dp[2] = 1;
    for (int i = 3; i <= 2*k+1; i++) dp[i] = dp[i-1] + dp[i-2];
    *f2k = dp[2*k];
    *f2k1 = dp[2*k+1];
}