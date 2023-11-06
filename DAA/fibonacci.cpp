#include <bits/stdc++.h>
using namespace std;

//fibonacci

int fibo(int n,vector<int> &dp) {
	if (n <= 1) return 1;
    if(dp[n] != -1) return dp[n];
	return dp[n] = fibo(n - 1,dp) + fibo(n - 2,dp);
}
// TC - O(2^n)
// TC after memoization - O(n)
// SC - O(n)

void solve() {
	int n;
	cin >> n;
    vector<int> dp(n + 1, -1);
	// recursive approach
	cout << "recursive : " <<  fibo(n - 1,dp) << endl;
	// iterative approach
	int f1 = 0;
	int f2 = 1;
	int f3 = 1;
	for (int i = 3; i <= n + 1; ++i) {
		f3 = f2 + f1;
		f1 = f2;
		f2 = f3;
	}
    // TC - O(n)
    // SC - O(1)
	cout << "iterative : " << f3 << endl;

}
int main() {
	solve();
}
