#include <iostream>
using namespace std;

int fibo(int n) {
	// base case
	if (n == 0 || n == 1) return n;

	// recursive case
	return fibo(n - 1) + fibo(n - 2);
}

int topDown(int n, int *dp) {
	// base case
	if (n == 0 || n == 1) return dp[n] = n;
	// Calculate krne se pehle check krlo
	if (dp[n] != -1) return dp[n];
	// recursive case
	return dp[n] = topDown(n - 1, dp) + topDown(n - 2, dp);
}

int bottomUp(int n) {
	int dp[10000];
	// Initialisation
	dp[0] = 0;
	dp[1] = 1;

	// Now fill the dp array
	for (int i = 2; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
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

	cout << fibo(100) << endl;

	return 0;
}
















