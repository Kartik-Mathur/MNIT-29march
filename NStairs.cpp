#include <iostream>
using namespace std;

int nstairs(int n) {
	// base case
	if (n == 0) return 1;
	if (n < 0) return 0;
	// recursive case
	return nstairs(n - 1) + nstairs(n - 2) + nstairs(n - 3);
}

int topDown(int n, int *dp) {
	// base case
	if (n == 0) return dp[n] = 1;
	if (n < 0) return dp[n] = 0;
	if (dp[n] != -1) return dp[n];
	// recursive case
	return dp[n] = topDown(n - 1, dp) + topDown(n - 2, dp) + topDown(n - 3, dp);
}

int bottomUp(int n) {
	int dp[10000];
	dp[0] = 1;

	for (int i = 1; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + ((i - 2) >= 0 ? dp[i - 2] : 0) + ((i - 3) >= 0 ? dp[i - 3] : 0);
	}

	return dp[n];
}

int main() {
	int dp[10000];
	for (int i = 0; i < 10000; ++i)
	{
		dp[i] = -1;
	}
	cout << topDown(100, dp) << endl;
	cout << bottomUp(100) << endl;
	cout << nstairs(100) << endl;

	return 0;
}
















