int dp[1005];
int maxm(int x, int y) { return x > y ? x : y; }
int maxChandy(int size) {
    dp[0] = array[0];
    dp[1] = array[1];
    dp[2] = maxm(dp[0], dp[2]) + array[2];
    for (int i = 3; i < size; i++) dp[i] = maxm(dp[i-2], dp[i-3]) + array[i];
   	return maxm(dp[size-1], dp[size-2]);
}
