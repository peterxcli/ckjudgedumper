void solve(int *A, int *B, int *op_cnt){
    int ans = 0;
	for (int i = 0; i < N; i++) {
    	if (A[i] < B[i]) {int _ = A[i]; A[i] = B[i]; B[i] = _; ans++;}
    }
    *op_cnt = ans;
}