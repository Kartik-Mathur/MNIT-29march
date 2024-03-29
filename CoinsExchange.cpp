#include <iostream>
using namespace std;

int coinsExchange(int amt, int *deno, int n) {
	// base case
	if (amt == 0) {
		return 0;
	}
	// recursive case
	int ans = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		if (amt >= deno[i]) {
			int chotiAmt = amt - deno[i];
			int x = coinsExchange(chotiAmt, deno, n);
			if (x != INT_MAX)
				ans = min(ans, x + 1);
		}
	}

	return ans;
}

int topDown(int amt, int *deno, int n, int *dp) {
	// base case
	if (amt == 0) {
		return dp[amt] = 0;
	}

	if (dp[amt] != -1) return dp[amt];
	// recursive case
	int ans = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		if (amt >= deno[i]) {
			int chotiAmt = amt - deno[i];
			int x = topDown(chotiAmt, deno, n, dp);
			if (x != INT_MAX)
				ans = min(ans, x + 1);
		}
	}

	return dp[amt] = ans;
}

int bottomUp(int amt, int *deno, int n) {
	int dp[10000];
	for (int i = 0; i < 10000; ++i) dp[i] = INT_MAX;

	dp[0] = 0;

	for (int rupay = 1; rupay <= amt; ++rupay)
	{
		for (int i = 0; i < n; ++i)
		{
			if (rupay >= deno[i]) {
				dp[rupay] = min(dp[rupay], dp[rupay - deno[i]] + 1);
			}
		}
	}
	return dp[amt];
}

int main() {

	int deno[] = {1, 7, 10};
	int n = sizeof(deno) / sizeof(int);
	int dp[10000];
	for (int i = 0; i < 10000; ++i)
	{
		dp[i] = -1;
	}

	int amount = 237;

	cout << topDown(amount, deno, n, dp) << endl;
	cout << bottomUp(amount, deno, n) << endl;
	cout << coinsExchange(amount, deno, n) << endl;


	return 0;
}
















